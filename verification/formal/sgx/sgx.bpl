//********************* Memory *********************
type physical_address = int;
const abort_page : physical_address;
const dummy_physical_address : physical_address;
axiom dummy_physical_address == 0; //arbitrary value //FIXME: just added this
axiom abort_page == 0;

type linear_address = int;
const dummy_linear_address : physical_address;
axiom dummy_linear_address == 0; //arbitrary value

type data; //uninterpreted data denoting memory contents
const abort_data : data;

//linear range register: lbase * lsize
//Why doesn't Boogie have record types???
type lr_register; // an array of registers
const dummy_lsrr : lr_register;
// constructor for lr_register
function Lr_register(lbase: linear_address, lsize: int) : lr_register;
// getter methods for lbase and lsize
function Lr_register_lbase (lr : lr_register) : linear_address;
function Lr_register_lsize (lr : lr_register) : int;
// tells us what the above 2 functions do
// for each getter method, when we call it on an instance of Lr_register, we return the value of lbase or lsize
axiom (forall lbase: linear_address, lsize: int :: {Lr_register(lbase,lsize)}
       Lr_register_lbase(Lr_register(lbase, lsize)) == lbase);
axiom (forall lbase: linear_address, lsize: int :: {Lr_register(lbase,lsize)}
       Lr_register_lsize(Lr_register(lbase, lsize)) == lsize);
// constructor definition
axiom (forall lr: lr_register :: {Lr_register_lbase(lr)} {Lr_register_lsize(lr)}
       Lr_register(Lr_register_lbase(lr), Lr_register_lsize(lr)) == lr);
// checks if a linear address is between lbase and lbase + lsize
function in_register_range (linear_address, lr_register) : bool;
axiom (forall la : linear_address, lr : lr_register :: {in_register_range(la,lr)}
       in_register_range(la,lr) <==> Lr_register_lbase(lr) <= la && la < (Lr_register_lbase(lr) + Lr_register_lsize(lr)));
// for interrupts and exceptions, we need to make sure the area is secure
// TCS = thread control structure
// SECS = security enclave
// SSA = state save area
// OSSA = offset of the SSA, location of first SSA
// NSSA = number of SSAs within the enclave
// checks if it's within the SSA
function in_ssa_range(linear_address, tcs_ty, secs_ty): bool;
axiom (forall la: linear_address, tcs: tcs_ty, secs: secs_ty :: {in_ssa_range(la, tcs, secs)}
       in_ssa_range(la,tcs, secs) <==> (la >= (Secs_baseaddr(secs) + Tcs_ossa(tcs))) && (la < (Secs_baseaddr(secs) + Tcs_ossa(tcs) + Tcs_nssa(tcs))));

//Page Table
type page_table_ty = [linear_address] physical_address;
var page_table : page_table_ty;

//Enclave related memory: all physical memory is partitioned into EPC memory and non-EPC memory
function is_epc_address (physical_address) : bool;
axiom is_epc_address(dummy_physical_address) == false;
axiom is_epc_address(abort_page) == false;
const EPC_LOW  : physical_address; axiom EPC_LOW == 2000; //arbitrary value
const EPC_HIGH : physical_address; axiom EPC_HIGH == 3000; //arbitrary value
//axiom (forall i : physical_address :: ((EPC_LOW <= i && i < EPC_HIGH) ==> is_epc_address(i)) &&
//                                      ((!(EPC_LOW <= i && i < EPC_HIGH)) ==> !is_epc_address(i)));
axiom (forall i: physical_address :: {is_epc_address(i)}
    is_epc_address(i) <==> (EPC_LOW <= i && i < EPC_HIGH));

//********************* Processor *********************
//CPU id
type lp_id = int;
var curr_lp : lp_id;

type xstate_ty;
const unique dummy_xstate : xstate_ty;

//processor state is type-cast to data when storing to memory
function xstate_to_data (xstate_ty) : data;
function data_to_xstate (data) : xstate_ty;
axiom (forall d: data :: {data_to_xstate(d)} xstate_to_data(data_to_xstate(d)) == d); 
axiom (forall x: xstate_ty :: {xstate_to_data(x)} data_to_xstate(xstate_to_data(x)) == x);

//size of xstate area in pages
function xstate_size(xstate_ty) : int;

var xstate : [lp_id] xstate_ty;

type lp_state_ty;
function Lp_state(cr_enclave_mode: bool,
                  cr_tcs_pa: physical_address,
                  cr_active_secs: physical_address,
                  cr_elrange: lr_register,
                  ssa_pa: physical_address)
                  : lp_state_ty;
function Lp_state_cr_enclave_mode (lps : lp_state_ty) : bool;
function Lp_state_cr_tcs_pa (lps : lp_state_ty) : physical_address;
function Lp_state_cr_active_secs (lps : lp_state_ty) : physical_address;
function Lp_state_cr_elrange (lps : lp_state_ty) : lr_register;
function Lp_state_ssa_pa (lps : lp_state_ty) : physical_address;
axiom (forall cr_enclave_mode: bool,
              cr_tcs_pa: physical_address,
              cr_active_secs: physical_address,
              cr_elrange: lr_register,
              ssa_pa: physical_address ::
              {Lp_state(cr_enclave_mode, cr_tcs_pa, cr_active_secs, cr_elrange, ssa_pa)}
       Lp_state_cr_enclave_mode(Lp_state(cr_enclave_mode, cr_tcs_pa, cr_active_secs, cr_elrange, ssa_pa)) == cr_enclave_mode);
axiom (forall cr_enclave_mode: bool,
              cr_tcs_pa: physical_address,
              cr_active_secs: physical_address,
              cr_elrange: lr_register,
              ssa_pa: physical_address ::
              {Lp_state(cr_enclave_mode, cr_tcs_pa, cr_active_secs, cr_elrange, ssa_pa)}
       Lp_state_cr_tcs_pa(Lp_state(cr_enclave_mode, cr_tcs_pa, cr_active_secs, cr_elrange, ssa_pa)) == cr_tcs_pa);
axiom (forall cr_enclave_mode: bool,
              cr_tcs_pa: physical_address,
              cr_active_secs: physical_address,
              cr_elrange: lr_register,
              ssa_pa: physical_address ::
              {Lp_state(cr_enclave_mode, cr_tcs_pa, cr_active_secs, cr_elrange, ssa_pa)}
       Lp_state_cr_active_secs(Lp_state(cr_enclave_mode, cr_tcs_pa, cr_active_secs, cr_elrange, ssa_pa)) == cr_active_secs);
axiom (forall cr_enclave_mode: bool,
              cr_tcs_pa: physical_address,
              cr_active_secs: physical_address,
              cr_elrange: lr_register,
              ssa_pa: physical_address ::
              {Lp_state(cr_enclave_mode, cr_tcs_pa, cr_active_secs, cr_elrange, ssa_pa)}
       Lp_state_cr_elrange(Lp_state(cr_enclave_mode, cr_tcs_pa, cr_active_secs, cr_elrange, ssa_pa)) == cr_elrange);
axiom (forall cr_enclave_mode: bool,
              cr_tcs_pa: physical_address,
              cr_active_secs: physical_address,
              cr_elrange: lr_register,
              ssa_pa: physical_address ::
              {Lp_state(cr_enclave_mode, cr_tcs_pa, cr_active_secs, cr_elrange, ssa_pa)}
       Lp_state_ssa_pa(Lp_state(cr_enclave_mode, cr_tcs_pa, cr_active_secs, cr_elrange, ssa_pa)) == ssa_pa);

axiom (forall lps: lp_state_ty ::
              {Lp_state_cr_enclave_mode(lps)}
              {Lp_state_cr_tcs_pa(lps)}
              {Lp_state_cr_active_secs(lps)}
              {Lp_state_cr_elrange(lps)}
              {Lp_state_ssa_pa(lps)}
        Lp_state( Lp_state_cr_enclave_mode(lps),
                  Lp_state_cr_tcs_pa(lps),
                  Lp_state_cr_active_secs(lps),
                  Lp_state_cr_elrange(lps),
                  Lp_state_ssa_pa(lps) ) == lps);

var lp_state : [lp_id] lp_state_ty;

//********************* SGX structs *********************
type page_ty;
const unique pt_secs : page_ty;
const unique pt_tcs : page_ty;
const unique pt_reg : page_ty;
axiom (forall pt: page_ty :: (pt == pt_secs) || (pt == pt_reg) || (pt == pt_tcs));

type key_ty = int;
const dummy_signing_key : key_ty;

type measurement_ty = int;
type hashtext_ty a; //unary type constructor
type ciphertext_ty a;
type mactext_ty a;

type attributes_ty;
function Attributes(einittokenkey: bool): attributes_ty;
function Attributes_einittokenkey(attributes: attributes_ty): bool;
axiom (forall einittokenkey: bool :: 
  {Attributes(einittokenkey)}
  Attributes_einittokenkey(Attributes(einittokenkey)) == einittokenkey);
axiom (forall attributes: attributes_ty ::
  {Attributes_einittokenkey(attributes)}
  Attributes(Attributes_einittokenkey(attributes)) == attributes);

type targetinfo_ty;
function Targetinfo(attributes: attributes_ty, measurement: measurement_ty): targetinfo_ty;
function Targetinfo_attributes(targetinfo: targetinfo_ty): attributes_ty;
function Targetinfo_measurement(targetinfo: targetinfo_ty): measurement_ty;
axiom (forall attributes: attributes_ty, measurement: measurement_ty ::
  {Targetinfo(attributes, measurement)}
  Targetinfo_attributes(Targetinfo(attributes, measurement)) == attributes);
axiom (forall attributes: attributes_ty, measurement: measurement_ty ::
  {Targetinfo(attributes, measurement)}
  Targetinfo_measurement(Targetinfo(attributes, measurement)) == measurement);
axiom (forall targetinfo: targetinfo_ty ::
  {Targetinfo_attributes(targetinfo)}
  {Targetinfo_measurement(targetinfo)}
  Targetinfo(Targetinfo_attributes(targetinfo), Targetinfo_measurement(targetinfo)) == targetinfo);

type report_ty;
function Report(isvprodid: int, isvsvn: int, attributes: attributes_ty,
                reportdata: data, mrenclave: measurement_ty, mrsigner: hashtext_ty key_ty) : report_ty;
function Report_isvprodid(report: report_ty): int;
function Report_isvsvn(report: report_ty): int;
function Report_attributes(report: report_ty): attributes_ty;
function Report_reportdata(report: report_ty): data;
function Report_mrenclave(report: report_ty): measurement_ty;
function Report_mrsigner(report: report_ty): hashtext_ty key_ty;
axiom (forall isvprodid: int, isvsvn: int, attributes: attributes_ty,
              reportdata: data, mrenclave: measurement_ty, mrsigner: hashtext_ty key_ty ::
  {Report(isvprodid, isvsvn, attributes, reportdata, mrenclave, mrsigner)}
  Report_isvprodid(Report(isvprodid, isvsvn, attributes, reportdata, mrenclave, mrsigner)) == isvprodid);
axiom (forall isvprodid: int, isvsvn: int, attributes: attributes_ty,
              reportdata: data, mrenclave: measurement_ty, mrsigner: hashtext_ty key_ty ::
  {Report(isvprodid, isvsvn, attributes, reportdata, mrenclave, mrsigner)}
  Report_isvsvn(Report(isvprodid, isvsvn, attributes, reportdata, mrenclave, mrsigner)) == isvsvn);
axiom (forall isvprodid: int, isvsvn: int, attributes: attributes_ty,
              reportdata: data, mrenclave: measurement_ty, mrsigner: hashtext_ty key_ty ::
  {Report(isvprodid, isvsvn, attributes, reportdata, mrenclave, mrsigner)}
  Report_attributes(Report(isvprodid, isvsvn, attributes, reportdata, mrenclave, mrsigner)) == attributes);
axiom (forall isvprodid: int, isvsvn: int, attributes: attributes_ty,
              reportdata: data, mrenclave: measurement_ty, mrsigner: hashtext_ty key_ty ::
  {Report(isvprodid, isvsvn, attributes, reportdata, mrenclave, mrsigner)}
  Report_reportdata(Report(isvprodid, isvsvn, attributes, reportdata, mrenclave, mrsigner)) == reportdata);
axiom (forall isvprodid: int, isvsvn: int, attributes: attributes_ty,
              reportdata: data, mrenclave: measurement_ty, mrsigner: hashtext_ty key_ty ::
  {Report(isvprodid, isvsvn, attributes, reportdata, mrenclave, mrsigner)}
  Report_mrenclave(Report(isvprodid, isvsvn, attributes, reportdata, mrenclave, mrsigner)) == mrenclave);
axiom (forall isvprodid: int, isvsvn: int, attributes: attributes_ty,
              reportdata: data, mrenclave: measurement_ty, mrsigner: hashtext_ty key_ty ::
  {Report(isvprodid, isvsvn, attributes, reportdata, mrenclave, mrsigner)}
  Report_mrsigner(Report(isvprodid, isvsvn, attributes, reportdata, mrenclave, mrsigner)) == mrsigner);
axiom (forall report: report_ty ::
  {Report_isvprodid(report)}
  {Report_isvsvn(report)}
  {Report_attributes(report)}
  {Report_reportdata(report)}
  {Report_mrenclave(report)}
  {Report_mrsigner(report)}
  Report(Report_isvprodid(report),
         Report_isvsvn(report),
         Report_attributes(report),
         Report_reportdata(report),
         Report_mrenclave(report),
         Report_mrsigner(report)) == report);


type report_maced_ty;
function Report_maced(report: report_ty, mac: mactext_ty report_ty): report_maced_ty;
function Report_maced_report(report_maced: report_maced_ty): report_ty;
function Report_maced_mac(report_maced: report_maced_ty): mactext_ty report_ty;
axiom (forall report: report_ty, mac: mactext_ty report_ty ::
  {Report_maced(report, mac)}
  Report_maced_report(Report_maced(report, mac)) == report);
axiom (forall report: report_ty, mac: mactext_ty report_ty ::
  {Report_maced(report, mac)}
  Report_maced_mac(Report_maced(report, mac)) == mac);
axiom (forall report_maced: report_maced_ty ::
  {Report_maced_report(report_maced)}
  {Report_maced_mac(report_maced)}
  Report_maced(Report_maced_report(report_maced), 
               Report_maced_mac(report_maced)) == report_maced);

type keyname_ty;
const unique launch_key : keyname_ty;
const unique provision_key : keyname_ty;
const unique provision_seal_key : keyname_ty;
const unique report_key : keyname_ty;
const unique seal_key : keyname_ty;

type keyrequest_ty;
function Keyrequest(keyname: keyname_ty, isvsvn: int, 
                    keypolicy_mrenclave: bool, keypolicy_mrsigner: bool): keyrequest_ty; 
function Keyrequest_keyname(keyrequest: keyrequest_ty) : keyname_ty;
function Keyrequest_isvsvn(keyrequest: keyrequest_ty) : int;
function Keyrequest_keypolicy_mrenclave(keyrequest: keyrequest_ty) : bool;
function Keyrequest_keypolicy_mrsigner(keyrequest: keyrequest_ty) : bool;
axiom (forall keyname: keyname_ty, isvsvn: int, 
              keypolicy_mrenclave: bool, keypolicy_mrsigner: bool :: 
  {Keyrequest(keyname, isvsvn, keypolicy_mrenclave, keypolicy_mrsigner)}
  Keyrequest_keyname(Keyrequest(keyname, isvsvn, keypolicy_mrenclave, keypolicy_mrsigner)) == keyname);
axiom (forall keyname: keyname_ty, isvsvn: int, 
              keypolicy_mrenclave: bool, keypolicy_mrsigner: bool :: 
  {Keyrequest(keyname, isvsvn, keypolicy_mrenclave, keypolicy_mrsigner)}
  Keyrequest_isvsvn(Keyrequest(keyname, isvsvn, keypolicy_mrenclave, keypolicy_mrsigner)) == isvsvn);
axiom (forall keyname: keyname_ty, isvsvn: int, 
              keypolicy_mrenclave: bool, keypolicy_mrsigner: bool :: 
  {Keyrequest(keyname, isvsvn, keypolicy_mrenclave, keypolicy_mrsigner)}
  Keyrequest_keypolicy_mrenclave(Keyrequest(keyname, isvsvn, keypolicy_mrenclave, keypolicy_mrsigner)) == keypolicy_mrenclave);
axiom (forall keyname: keyname_ty, isvsvn: int, 
              keypolicy_mrenclave: bool, keypolicy_mrsigner: bool :: 
  {Keyrequest(keyname, isvsvn, keypolicy_mrenclave, keypolicy_mrsigner)}
  Keyrequest_keypolicy_mrsigner(Keyrequest(keyname, isvsvn, keypolicy_mrenclave, keypolicy_mrsigner)) == keypolicy_mrsigner);
axiom (forall keyrequest: keyrequest_ty ::
  {Keyrequest_keyname(keyrequest)}
  {Keyrequest_isvsvn(keyrequest)}
  {Keyrequest_keypolicy_mrenclave(keyrequest)}
  {Keyrequest_keypolicy_mrsigner(keyrequest)}
  Keyrequest(Keyrequest_keyname(keyrequest),
             Keyrequest_isvsvn(keyrequest),
             Keyrequest_keypolicy_mrenclave(keyrequest),
             Keyrequest_keypolicy_mrsigner(keyrequest)) == keyrequest);

type einittoken_ty;
function Einittoken(valid: bool, attributes: attributes_ty, 
                    mrenclave: measurement_ty, mrsigner: hashtext_ty key_ty) : einittoken_ty;
function Einittoken_valid(einittoken: einittoken_ty): bool;
function Einittoken_attributes(einittoken: einittoken_ty): attributes_ty;
function Einittoken_mrenclave(einittoken: einittoken_ty): measurement_ty;
function Einittoken_mrsigner(einittoken: einittoken_ty): hashtext_ty key_ty;
axiom (forall valid: bool, attributes: attributes_ty, mrenclave: measurement_ty, mrsigner: hashtext_ty key_ty ::
  {Einittoken(valid, attributes, mrenclave, mrsigner)}
  Einittoken_valid(Einittoken(valid, attributes, mrenclave, mrsigner)) == valid);
axiom (forall valid: bool, attributes: attributes_ty, mrenclave: measurement_ty, mrsigner: hashtext_ty key_ty ::
  {Einittoken(valid, attributes, mrenclave, mrsigner)}
  Einittoken_attributes(Einittoken(valid, attributes, mrenclave, mrsigner)) == attributes);
axiom (forall valid: bool, attributes: attributes_ty, mrenclave: measurement_ty, mrsigner: hashtext_ty key_ty ::
  {Einittoken(valid, attributes, mrenclave, mrsigner)}
  Einittoken_mrenclave(Einittoken(valid, attributes, mrenclave, mrsigner)) == mrenclave);
axiom (forall valid: bool, attributes: attributes_ty, mrenclave: measurement_ty, mrsigner: hashtext_ty key_ty ::
  {Einittoken(valid, attributes, mrenclave, mrsigner)}
  Einittoken_mrsigner(Einittoken(valid, attributes, mrenclave, mrsigner)) == mrsigner);
axiom (forall einittoken: einittoken_ty ::
  {Einittoken_valid(einittoken)}
  {Einittoken_attributes(einittoken)}
  {Einittoken_mrenclave(einittoken)}
  {Einittoken_mrsigner(einittoken)}
  Einittoken(Einittoken_valid(einittoken),
             Einittoken_attributes(einittoken),
             Einittoken_mrenclave(einittoken),
             Einittoken_mrsigner(einittoken)) == einittoken);

type sigstruct_ty;
function Sigstruct(modulus: key_ty, enclavehash: measurement_ty,
                   attributes: attributes_ty, isvprodid: int, isvsvn: int) : sigstruct_ty; 
function Sigstruct_modulus(sigstruct_ty) : key_ty;
function Sigstruct_enclavehash(sigstruct_ty): measurement_ty;
function Sigstruct_attributes(sigstruct_ty): attributes_ty;
function Sigstruct_isvprodid(sigstruct_ty): int;
function Sigstruct_isvsvn(sigstruct_ty): int;
axiom (forall modulus: key_ty, enclavehash: measurement_ty,
              attributes: attributes_ty, isvprodid: int, isvsvn: int ::
  {Sigstruct(modulus, enclavehash, attributes, isvprodid, isvsvn)}
  Sigstruct_modulus(Sigstruct(modulus, enclavehash, attributes, isvprodid, isvsvn)) == modulus);
axiom (forall modulus: key_ty, enclavehash: measurement_ty,
              attributes: attributes_ty, isvprodid: int, isvsvn: int ::
  {Sigstruct(modulus, enclavehash, attributes, isvprodid, isvsvn)}
  Sigstruct_enclavehash(Sigstruct(modulus, enclavehash, attributes, isvprodid, isvsvn)) == enclavehash);
axiom (forall modulus: key_ty, enclavehash: measurement_ty,
              attributes: attributes_ty, isvprodid: int, isvsvn: int ::
  {Sigstruct(modulus, enclavehash, attributes, isvprodid, isvsvn)}
  Sigstruct_attributes(Sigstruct(modulus, enclavehash, attributes, isvprodid, isvsvn)) == attributes);
axiom (forall modulus: key_ty, enclavehash: measurement_ty,
              attributes: attributes_ty, isvprodid: int, isvsvn: int ::
  {Sigstruct(modulus, enclavehash, attributes, isvprodid, isvsvn)}
  Sigstruct_isvprodid(Sigstruct(modulus, enclavehash, attributes, isvprodid, isvsvn)) == isvprodid);
axiom (forall modulus: key_ty, enclavehash: measurement_ty,
              attributes: attributes_ty, isvprodid: int, isvsvn: int ::
  {Sigstruct(modulus, enclavehash, attributes, isvprodid, isvsvn)}
  Sigstruct_isvsvn(Sigstruct(modulus, enclavehash, attributes, isvprodid, isvsvn)) == isvsvn);
axiom (forall sigstruct: sigstruct_ty ::
  {Sigstruct_modulus(sigstruct)}
  {Sigstruct_enclavehash(sigstruct)}
  {Sigstruct_attributes(sigstruct)}
  {Sigstruct_isvprodid(sigstruct)}
  {Sigstruct_isvsvn(sigstruct)}
  Sigstruct(Sigstruct_modulus(sigstruct),
            Sigstruct_enclavehash(sigstruct),
            Sigstruct_attributes(sigstruct),
            Sigstruct_isvprodid(sigstruct),
            Sigstruct_isvsvn(sigstruct)) == sigstruct);

type sigstruct_signature_ty = ciphertext_ty (hashtext_ty sigstruct_ty);
type sigstruct_signed_ty;
function Sigstruct_signed(signature: sigstruct_signature_ty, sigstruct: sigstruct_ty) : sigstruct_signed_ty;
function Sigstruct_signed_signature(sigstruct_signed_ty): sigstruct_signature_ty;
function Sigstruct_signed_sigstruct(sigstruct_signed_ty): sigstruct_ty;
axiom (forall signature: sigstruct_signature_ty, sigstruct: sigstruct_ty ::
  {Sigstruct_signed(signature, sigstruct)}
  Sigstruct_signed_signature(Sigstruct_signed(signature, sigstruct)) == signature);
axiom (forall signature: sigstruct_signature_ty, sigstruct: sigstruct_ty ::
  {Sigstruct_signed(signature, sigstruct)}
  Sigstruct_signed_sigstruct(Sigstruct_signed(signature, sigstruct)) == sigstruct);
axiom (forall sigstruct_signed: sigstruct_signed_ty ::
  {Sigstruct_signed_signature(sigstruct_signed)}
  {Sigstruct_signed_sigstruct(sigstruct_signed)}
  Sigstruct_signed(Sigstruct_signed_signature(sigstruct_signed),
                   Sigstruct_signed_sigstruct(sigstruct_signed)) == sigstruct_signed);

type secinfo_ty;
function Secinfo(flags_r: bool, flags_w: bool, flags_x: bool, flags_pt: page_ty): secinfo_ty;
function Secinfo_flags_r(secinfo: secinfo_ty): bool;
function Secinfo_flags_w(secinfo: secinfo_ty): bool;
function Secinfo_flags_x(secinfo: secinfo_ty): bool;
function Secinfo_flags_pt(secinfo: secinfo_ty) : page_ty;
axiom (forall flags_r: bool, flags_w: bool, flags_x: bool, flags_pt: page_ty ::
      {Secinfo(flags_r, flags_w, flags_x, flags_pt)}
      Secinfo_flags_r(Secinfo(flags_r, flags_w, flags_x, flags_pt)) == flags_r);
axiom (forall flags_r: bool, flags_w: bool, flags_x: bool, flags_pt: page_ty ::
      {Secinfo(flags_r, flags_w, flags_x, flags_pt)}
      Secinfo_flags_w(Secinfo(flags_r, flags_w, flags_x, flags_pt)) == flags_w);
axiom (forall flags_r: bool, flags_w: bool, flags_x: bool, flags_pt: page_ty ::
      {Secinfo(flags_r, flags_w, flags_x, flags_pt)}
      Secinfo_flags_x(Secinfo(flags_r, flags_w, flags_x, flags_pt)) == flags_x);
axiom (forall flags_r: bool, flags_w: bool, flags_x: bool, flags_pt: page_ty ::
      {Secinfo(flags_r, flags_w, flags_x, flags_pt)}
      Secinfo_flags_pt(Secinfo(flags_r, flags_w, flags_x, flags_pt)) == flags_pt);
axiom (forall secinfo: secinfo_ty ::
       {Secinfo_flags_r(secinfo)}
       {Secinfo_flags_w(secinfo)}
       {Secinfo_flags_x(secinfo)}
       {Secinfo_flags_pt(secinfo)}
       Secinfo(Secinfo_flags_r(secinfo),
               Secinfo_flags_w(secinfo),
               Secinfo_flags_x(secinfo),
               Secinfo_flags_pt(secinfo)) == secinfo);

type pcmd_ty;
type pageinfo_ty;
function Pageinfo(linaddr: linear_address, srcpge: linear_address, 
                  secinfo: secinfo_ty, pcmd: pcmd_ty, secs: linear_address): pageinfo_ty;
function Pageinfo_linaddr(pageinfo: pageinfo_ty) : linear_address;
function Pageinfo_srcpge(pageinfo: pageinfo_ty) : linear_address;
function Pageinfo_secinfo(pageinfo: pageinfo_ty) : secinfo_ty;
function Pageinfo_pcmd(pageinfo: pageinfo_ty) : pcmd_ty;
function Pageinfo_secs(pageinfo: pageinfo_ty) : linear_address;
axiom (forall linaddr: linear_address, srcpge: linear_address, 
              secinfo: secinfo_ty, pcmd: pcmd_ty, secs: linear_address ::
       {Pageinfo(linaddr, srcpge, secinfo, pcmd, secs)}
       Pageinfo_linaddr(Pageinfo(linaddr, srcpge, secinfo, pcmd, secs)) == linaddr);
axiom (forall linaddr: linear_address, srcpge: linear_address, 
              secinfo: secinfo_ty, pcmd: pcmd_ty, secs: linear_address ::
       {Pageinfo(linaddr, srcpge, secinfo, pcmd, secs)}
       Pageinfo_srcpge(Pageinfo(linaddr, srcpge, secinfo, pcmd, secs)) == srcpge);
axiom (forall linaddr: linear_address, srcpge: linear_address, 
              secinfo: secinfo_ty, pcmd: pcmd_ty, secs: linear_address ::
       {Pageinfo(linaddr, srcpge, secinfo, pcmd, secs)}
       Pageinfo_secinfo(Pageinfo(linaddr, srcpge, secinfo, pcmd, secs)) == secinfo);
axiom (forall linaddr: linear_address, srcpge: linear_address, 
              secinfo: secinfo_ty, pcmd: pcmd_ty, secs: linear_address ::
       {Pageinfo(linaddr, srcpge, secinfo, pcmd, secs)}
       Pageinfo_pcmd(Pageinfo(linaddr, srcpge, secinfo, pcmd, secs)) == pcmd);
axiom (forall linaddr: linear_address, srcpge: linear_address, 
              secinfo: secinfo_ty, pcmd: pcmd_ty, secs: linear_address ::
       {Pageinfo(linaddr, srcpge, secinfo, pcmd, secs)}
       Pageinfo_secs(Pageinfo(linaddr, srcpge, secinfo, pcmd, secs)) == secs);
axiom (forall pageinfo: pageinfo_ty ::
       {Pageinfo_linaddr(pageinfo)}
       {Pageinfo_srcpge(pageinfo)}
       {Pageinfo_secinfo(pageinfo)}
       {Pageinfo_pcmd(pageinfo)}
       {Pageinfo_secs(pageinfo)}
       Pageinfo(Pageinfo_linaddr(pageinfo),
                Pageinfo_srcpge(pageinfo),
                Pageinfo_secinfo(pageinfo),
                Pageinfo_pcmd(pageinfo),
                Pageinfo_secs(pageinfo)) == pageinfo);

type secs_ty;
function Secs(baseaddr: linear_address, size: int, initialized: bool, 
              mrenclave: measurement_ty, mrsigner: hashtext_ty key_ty, 
              isvprodid: int, isvsvn: int,
              attributes: attributes_ty) : secs_ty;
function Secs_baseaddr (secs : secs_ty) : linear_address;
function Secs_size (secs: secs_ty) : int;
function Secs_initialized (secs: secs_ty) : bool;
function Secs_mrenclave (secs: secs_ty) : measurement_ty;
function Secs_mrsigner (secs: secs_ty) : hashtext_ty key_ty;
function Secs_isvprodid (secs: secs_ty) : int;
function Secs_isvsvn (secs: secs_ty) : int;
function Secs_attributes (secs: secs_ty) : attributes_ty;
axiom (forall baseaddr: linear_address, size: int, initialized: bool, 
              mrenclave: measurement_ty, mrsigner: hashtext_ty key_ty, 
              isvprodid: int, isvsvn: int, attributes: attributes_ty ::
       {Secs(baseaddr, size, initialized, mrenclave, mrsigner, isvprodid, isvsvn, attributes)}
       Secs_baseaddr(Secs(baseaddr, size, initialized, mrenclave, mrsigner, isvprodid, isvsvn, attributes)) == baseaddr);
axiom (forall baseaddr: linear_address, size: int, initialized: bool, 
              mrenclave: measurement_ty, mrsigner: hashtext_ty key_ty, 
              isvprodid: int, isvsvn: int, attributes: attributes_ty ::
       {Secs(baseaddr, size, initialized, mrenclave, mrsigner, isvprodid, isvsvn, attributes)}
       Secs_size(Secs(baseaddr, size, initialized, mrenclave, mrsigner, isvprodid, isvsvn, attributes)) == size);
axiom (forall baseaddr: linear_address, size: int, initialized: bool, 
              mrenclave: measurement_ty, mrsigner: hashtext_ty key_ty, 
              isvprodid: int, isvsvn: int, attributes: attributes_ty ::
       {Secs(baseaddr, size, initialized, mrenclave, mrsigner, isvprodid, isvsvn, attributes)}
       Secs_initialized(Secs(baseaddr, size, initialized, mrenclave, mrsigner, isvprodid, isvsvn, attributes)) == initialized);
axiom (forall baseaddr: linear_address, size: int, initialized: bool, 
              mrenclave: measurement_ty, mrsigner: hashtext_ty key_ty, 
              isvprodid: int, isvsvn: int, attributes: attributes_ty ::
       {Secs(baseaddr, size, initialized, mrenclave, mrsigner, isvprodid, isvsvn, attributes)}
       Secs_mrenclave(Secs(baseaddr, size, initialized, mrenclave, mrsigner, isvprodid, isvsvn, attributes)) == mrenclave);
axiom (forall baseaddr: linear_address, size: int, initialized: bool, 
              mrenclave: measurement_ty, mrsigner: hashtext_ty key_ty, 
              isvprodid: int, isvsvn: int, attributes: attributes_ty ::
       {Secs(baseaddr, size, initialized, mrenclave, mrsigner, isvprodid, isvsvn, attributes)}
       Secs_mrsigner(Secs(baseaddr, size, initialized, mrenclave, mrsigner, isvprodid, isvsvn, attributes)) == mrsigner);
axiom (forall baseaddr: linear_address, size: int, initialized: bool, 
              mrenclave: measurement_ty, mrsigner: hashtext_ty key_ty, 
              isvprodid: int, isvsvn: int, attributes: attributes_ty ::
       {Secs(baseaddr, size, initialized, mrenclave, mrsigner, isvprodid, isvsvn, attributes)}
       Secs_isvprodid(Secs(baseaddr, size, initialized, mrenclave, mrsigner, isvprodid, isvsvn, attributes)) == isvprodid);
axiom (forall baseaddr: linear_address, size: int, initialized: bool, 
              mrenclave: measurement_ty, mrsigner: hashtext_ty key_ty, 
              isvprodid: int, isvsvn: int, attributes: attributes_ty ::
       {Secs(baseaddr, size, initialized, mrenclave, mrsigner, isvprodid, isvsvn, attributes)}
       Secs_isvsvn(Secs(baseaddr, size, initialized, mrenclave, mrsigner, isvprodid, isvsvn, attributes)) == isvsvn);
axiom (forall baseaddr: linear_address, size: int, initialized: bool, 
              mrenclave: measurement_ty, mrsigner: hashtext_ty key_ty, 
              isvprodid: int, isvsvn: int, attributes: attributes_ty ::
       {Secs(baseaddr, size, initialized, mrenclave, mrsigner, isvprodid, isvsvn, attributes)}
       Secs_attributes(Secs(baseaddr, size, initialized, mrenclave, mrsigner, isvprodid, isvsvn, attributes)) == attributes);
axiom (forall secs: secs_ty ::
       {Secs_baseaddr(secs)}
       {Secs_size(secs)}
       {Secs_initialized(secs)}
       {Secs_mrenclave(secs)}
       {Secs_mrsigner(secs)}
       {Secs_isvprodid(secs)}
       {Secs_isvsvn(secs)}
       {Secs_attributes(secs)}
       Secs(Secs_baseaddr(secs), Secs_size(secs), Secs_initialized(secs), 
            Secs_mrenclave(secs), Secs_mrsigner(secs), 
            Secs_isvprodid(secs), Secs_isvsvn(secs), Secs_attributes(secs)) == secs);

type tcs_ty;
function Tcs(active: bool, interrupted: bool, ossa: int, nssa: int, cssa: int) : tcs_ty;
function Tcs_active (tcs : tcs_ty) : bool;
function Tcs_interrupted (tcs : tcs_ty) : bool;
function Tcs_ossa (tcs : tcs_ty) : int;
function Tcs_nssa (tcs : tcs_ty) : int;
function Tcs_cssa (tcs : tcs_ty) : int;
axiom (forall active: bool, interrupted: bool, ossa: int, nssa: int, cssa: int ::
       {Tcs(active, interrupted, ossa, nssa, cssa)}
       Tcs_active(Tcs(active, interrupted, ossa, nssa, cssa)) == active);
axiom (forall active: bool, interrupted: bool, ossa: int, nssa: int, cssa: int ::
       {Tcs(active, interrupted, ossa, nssa, cssa)}
       Tcs_interrupted(Tcs(active, interrupted, ossa, nssa, cssa)) == interrupted);
axiom (forall active: bool, interrupted: bool, ossa: int, nssa: int, cssa: int ::
       {Tcs(active, interrupted, ossa, nssa, cssa)}
       Tcs_ossa(Tcs(active, interrupted, ossa, nssa, cssa)) == ossa);
axiom (forall active: bool, interrupted: bool, ossa: int, nssa: int, cssa: int ::
       {Tcs(active, interrupted, ossa, nssa, cssa)}
       Tcs_nssa(Tcs(active, interrupted, ossa, nssa, cssa)) == nssa);
axiom (forall active: bool, interrupted: bool, ossa: int, nssa: int, cssa: int ::
       {Tcs(active, interrupted, ossa, nssa, cssa)}
       Tcs_cssa(Tcs(active, interrupted, ossa, nssa, cssa)) == cssa);
axiom (forall tcs: tcs_ty ::
       {Tcs_active(tcs)}
       {Tcs_interrupted(tcs)}
       {Tcs_ossa(tcs)}
       {Tcs_nssa(tcs)}
       {Tcs_cssa(tcs)}
       Tcs(Tcs_active(tcs), Tcs_interrupted(tcs), Tcs_ossa(tcs), Tcs_nssa(tcs), Tcs_cssa(tcs)) == tcs);

var mem_secs : [physical_address] secs_ty;
var mem_tcs : [physical_address] tcs_ty;
var mem_reg : [physical_address] data;

//this is meant to be used for writes made by hardware within an SGX instruction. They don't need access permission checks.
var arbitrary_write_count: int;
function arbitrary_secs_val(int): secs_ty;
function arbitrary_tcs_val(int): tcs_ty;
function arbitrary_reg_val(int): data;

procedure {:inline 1} unchecked_write_secs(pa: physical_address, val: secs_ty)
modifies arbitrary_write_count, mem_reg, mem_secs, mem_tcs; 
{
  mem_secs[pa] := val;
  mem_reg[pa]  := arbitrary_reg_val(arbitrary_write_count);
  mem_tcs[pa]  := arbitrary_tcs_val(arbitrary_write_count);
  arbitrary_write_count := arbitrary_write_count + 1;
}

procedure {:inline 1} unchecked_write_tcs(pa: physical_address, val: tcs_ty)
modifies arbitrary_write_count, mem_reg, mem_secs, mem_tcs; 
{
  mem_tcs[pa] := val;
  mem_reg[pa]  := arbitrary_reg_val(arbitrary_write_count);
  mem_secs[pa]  := arbitrary_secs_val(arbitrary_write_count);
  arbitrary_write_count := arbitrary_write_count + 1;
}

procedure {:inline 1} unchecked_write_reg(pa: physical_address, val: data)
modifies arbitrary_write_count, mem_reg, mem_secs, mem_tcs; 
{
  mem_reg[pa] := val;
  mem_secs[pa]  := arbitrary_secs_val(arbitrary_write_count);
  mem_tcs[pa]  := arbitrary_tcs_val(arbitrary_write_count);
  arbitrary_write_count := arbitrary_write_count + 1;
}

type epcm_entry_ty;
function Epcm(valid: bool, pt: page_ty, enclavesecs: physical_address, enclaveaddress: linear_address) : epcm_entry_ty;
function Epcm_valid (epcm_entry : epcm_entry_ty) : bool;
function Epcm_pt (epcm_entry : epcm_entry_ty) : page_ty;
function Epcm_enclavesecs (epcm_entry : epcm_entry_ty) : physical_address;
function Epcm_enclaveaddress (epcm_entry : epcm_entry_ty) : linear_address;
axiom (forall valid: bool, pt: page_ty, enclavesecs: physical_address, enclaveaddress: linear_address ::
       {Epcm(valid, pt, enclavesecs, enclaveaddress)}
       Epcm_valid(Epcm(valid, pt, enclavesecs, enclaveaddress)) == valid);
axiom (forall valid: bool, pt: page_ty, enclavesecs: physical_address, enclaveaddress: linear_address ::
       {Epcm(valid, pt, enclavesecs, enclaveaddress)}
       Epcm_pt(Epcm(valid, pt, enclavesecs, enclaveaddress)) == pt);
axiom (forall valid: bool, pt: page_ty, enclavesecs: physical_address, enclaveaddress: linear_address ::
       {Epcm(valid, pt, enclavesecs, enclaveaddress)}
       Epcm_enclavesecs(Epcm(valid, pt, enclavesecs, enclaveaddress)) == enclavesecs);
axiom (forall valid: bool, pt: page_ty, enclavesecs: physical_address, enclaveaddress: linear_address ::
       {Epcm(valid, pt, enclavesecs, enclaveaddress)}
       Epcm_enclaveaddress(Epcm(valid, pt, enclavesecs, enclaveaddress)) == enclaveaddress);
axiom (forall epcm_entry: epcm_entry_ty ::
       {Epcm_valid(epcm_entry)}
       {Epcm_pt(epcm_entry)}
       {Epcm_enclavesecs(epcm_entry)}
       {Epcm_enclaveaddress(epcm_entry)}
       Epcm(Epcm_valid(epcm_entry), Epcm_pt(epcm_entry), Epcm_enclavesecs(epcm_entry), Epcm_enclaveaddress(epcm_entry)) == epcm_entry);

const dummy_epcm : epcm_entry_ty;
axiom (Epcm_valid(dummy_epcm) == false &&
       Epcm_pt(dummy_epcm) == pt_reg &&
       Epcm_enclavesecs(dummy_epcm) == dummy_physical_address &&
       Epcm_enclaveaddress(dummy_epcm) == dummy_linear_address);

var epcm : [physical_address] epcm_entry_ty;

/* FIXME: access control requirements from the PRM
   - All memory accesses must obey the segmentation and paging policies set by the OS / VMM
   - Code fetches from inside and enclave to linear address outside that enclave results in #GP(0)
   - Non-enclave accesses to EPC memory results in abort page semantics
   - Direct access to EPC page must conform to the security attributes which were established when those pages were added to EPC
     - Target must belong to the same enclave
     - RWX of the requested access conforms with the RWX of target page
     - Target page must not have restricted page type pt_secs, pt_tcs, pt_va
     - Target EPC page must not be blocked
*/
procedure {:inline 1} is_accessible(lp: lp_id, la: linear_address) returns (result: bool)
{
  var pa : physical_address; //pagetable[la]
  var ea : bool; //is this access to enclave memory?
  var mapped_la : bool; //does pagetable map this to an address != dummy_physical_address
  //FIXED: Nov 8, 2014, Reverted Nov 9,2014
  //ea := Lp_state_cr_enclave_mode(lp_state[lp]) && is_epc_address(la);
  ea := Lp_state_cr_enclave_mode(lp_state[lp]) && in_register_range(la, Lp_state_cr_elrange(lp_state[lp]));
  pa := page_table[la];
  mapped_la := (pa != dummy_physical_address);
  result := mapped_la && (ea ==> (Epcm_valid(epcm[pa]) && is_epc_address(pa)) &&
                                 Epcm_pt(epcm[pa]) == pt_reg &&
                                 Epcm_enclavesecs(epcm[pa]) == Lp_state_cr_active_secs(lp_state[lp]) &&
                                 Epcm_enclaveaddress(epcm[pa]) == la);
}

procedure {:inline 1} translate(la: linear_address) returns (result: physical_address)
{
  var ea : bool;
  var pa : physical_address;
  var accessible : bool;
  call accessible := is_accessible(curr_lp, la);
  assume accessible;
  ea := Lp_state_cr_enclave_mode(lp_state[curr_lp]) && in_register_range(la, Lp_state_cr_elrange(lp_state[curr_lp]));
  pa := page_table[la];
  if (ea) { result := pa; }
  else {
    if (is_epc_address(pa)) { result := abort_page; }
    else { result := pa; }
  }
}

//********************* Helper predicates *********************
//Is cpu represented by lps running an enclave thread whose secs is pa?
function thread_in_enclave(lp_state_ty, physical_address) : bool;
axiom (forall lps: lp_state_ty, pa: physical_address ::
  {thread_in_enclave(lps, pa)}
  thread_in_enclave(lps,pa) <==> (Lp_state_cr_enclave_mode(lps) && (Lp_state_cr_active_secs(lps) == pa)));

function no_threads_in_enclave([lp_id] lp_state_ty, physical_address) : bool;
axiom (forall lp_state : [lp_id] lp_state_ty, pa: physical_address ::
  {no_threads_in_enclave(lp_state, pa)}
  no_threads_in_enclave(lp_state, pa) <==> (forall lp: lp_id :: !thread_in_enclave(lp_state[lp], pa))); 

function page_in_enclave(epcm_entry_ty, physical_address, physical_address) : bool;
axiom (forall epcm_entry : epcm_entry_ty, pa: physical_address, ps: physical_address ::
  {page_in_enclave(epcm_entry, pa, ps)}
  page_in_enclave(epcm_entry, pa, ps) <==> is_epc_address(pa) && 
                                           Epcm_valid(epcm_entry) && 
                                           Epcm_enclavesecs(epcm_entry) == ps && 
                                           pa != ps);

function no_pages_in_enclave([physical_address] epcm_entry_ty, physical_address) : bool;
axiom (forall epcm: [physical_address] epcm_entry_ty, ps: physical_address ::
  {no_pages_in_enclave(epcm, ps)}
  no_pages_in_enclave(epcm, ps) <==> (forall pa: physical_address :: !page_in_enclave(epcm[pa], pa, ps)));

function cssa_addr(secs_ty, tcs_ty) : linear_address;
axiom (forall secs: secs_ty, tcs: tcs_ty ::
  {cssa_addr(secs,tcs)}
  cssa_addr(secs,tcs) == Secs_baseaddr(secs) + Tcs_ossa(tcs) + Tcs_cssa(tcs));

function pssa_addr(secs_ty, tcs_ty) : linear_address;
axiom (forall secs: secs_ty, tcs: tcs_ty ::
  {pssa_addr(secs,tcs)}
  pssa_addr(secs,tcs) == cssa_addr(secs,tcs) - 1); 

//axiom constraining sha256 to be injective
function sha256(val: int) : measurement_ty;
axiom (forall val1: int, val2: int ::
  {sha256(val1), sha256(val2)}
  (val1 != val2 ==> sha256(val1) != sha256(val2)));

function cmac<a>(k: key_ty, x: a) : mactext_ty a;
axiom (forall <a> k: key_ty, x1: a, x2: a :: 
  {cmac(k,x1), cmac(k,x2)}
  (x1 != x2 ==> cmac(k,x1) != cmac(k,x2)));

axiom (forall val1: int, val2: int ::
  {sha256(val1), sha256(val2)}
  (val1 != val2 ==> sha256(val1) != sha256(val2)));

//axiom constraining chained sha256 to be injective
function sha256update(prev: measurement_ty, update: int) : measurement_ty;
axiom (forall prev1: measurement_ty, update1: int, prev2: measurement_ty, update2: int ::
  {sha256update(prev1,update1), sha256update(prev2,update2)}
  (prev1 != prev2 || update1 != update2) ==> (sha256update(prev1,update1) != sha256update(prev2,update2)));

//injective axiom for hash (we use hash only when its unclear which hash algorithm Intel is using)
function hash<a>(x: a) : hashtext_ty a;
axiom (forall <a> x1: a, x2: a :: {hash(x1), hash(x2)}
       (x1 != x2 ==> hash(x1) != hash(x2)));

function derive_key_ereport(attributes: attributes_ty, measurement: measurement_ty): key_ty;
function derive_key_egetkey(keyname: keyname_ty, 
                            isvprodid: int, isvsvn: int, attributes: attributes_ty, 
                            mrenclave: measurement_ty, mrsigner: hashtext_ty key_ty): key_ty;
axiom (forall attr1: attributes_ty, meas1: measurement_ty,
              keyname: keyname_ty, isvprodid: int, isvsvn: int,
              attr2: attributes_ty, mrenclave: measurement_ty, mrsigner: hashtext_ty key_ty ::
              {derive_key_ereport(attr1, meas1), derive_key_egetkey(keyname, isvprodid, isvsvn, attr2, mrenclave, mrsigner)}
              (attr1 == attr2 && meas1 == mrenclave && keyname == report_key) ==>
              (derive_key_ereport(attr1, meas1) == derive_key_egetkey(keyname, isvprodid, isvsvn, attr2, mrenclave, mrsigner)));


function decrypt<a>(key: key_ty, ciphertext: ciphertext_ty a): a;
function encrypt<a>(key: key_ty, p: a): ciphertext_ty a;
axiom (forall <a> k: key_ty, c: ciphertext_ty a :: {decrypt(k, c)} encrypt(k, decrypt(k, c)) == c);
axiom (forall <a> k: key_ty, p: a :: {encrypt(k,p)} decrypt(k, encrypt(k, p)) == p);

//concatenation must be injective
function concat_two_int_to_one(fst: int, snd: int) : int;
axiom (forall fst1: int, fst2: int, snd1: int, snd2: int ::
  {concat_two_int_to_one(fst1, snd1), concat_two_int_to_one(fst2, snd2)}
  (fst1 != fst2 || snd1 != snd2) ==> (concat_two_int_to_one(fst1,snd1) != concat_two_int_to_one(fst2,snd2)));

//cast a regular page to an int
function reg_to_int(val: data) : int;
//would like the cast to be one-to-one
axiom (forall val1: data, val2: data ::
  {reg_to_int(val1), reg_to_int(val2)}
  (val1 != val2 ==> reg_to_int(val1) != reg_to_int(val2)));

//cast a regular page to an int
function tcs_to_int(val: tcs_ty) : int;
//would like the cast to be one-to-one
axiom (forall val1: tcs_ty, val2: tcs_ty ::
  {tcs_to_int(val1), tcs_to_int(val2)}
  (val1 != val2 ==> tcs_to_int(val1) != tcs_to_int(val2)));

//********************* SGX Instructions *********************

procedure {:inline 1} ecreate(la: linear_address, secs: secs_ty) 
modifies epcm, mem_secs, mem_reg, mem_tcs, arbitrary_write_count;
requires (page_table[la] != dummy_physical_address); //la is mapped
requires (is_epc_address(page_table[la]) && !Epcm_valid(epcm[page_table[la]])); //must be a free epc address
requires (!Lp_state_cr_enclave_mode(lp_state[curr_lp])); //enclave cannot call ecreate
requires (Secs_size(secs) > 0); //positive sized enclave
{
  var pa: physical_address;
  var measurement : measurement_ty; //computing value for mrenclave
  var ssaframesize : int;

  ssaframesize := 1; //FIXME: This is a field within SECS, and not a constant

  pa := page_table[la];
  measurement := Secs_mrenclave(secs);
  measurement := sha256update(measurement, concat_two_int_to_one(ssaframesize, Secs_size(secs)));

  //valid epcm of type secs and enclave address of 0, enclavesecs undefined thus set to 0
  epcm[pa] := Epcm(true, pt_secs, 0, 0); 

  //set baseaddr and size from the input secs struct, initialized must be false, mrsigner is not yet set
  call unchecked_write_secs(pa, Secs(Secs_baseaddr(secs), 
                                     Secs_size(secs), false, measurement, 
                                     hash(dummy_signing_key), 0, 0, Secs_attributes(secs)
                                    ));
}

procedure {:inline 1} ecreate_with_assumptions(la: linear_address, secs: secs_ty) 
modifies epcm, mem_secs, mem_reg, mem_tcs, arbitrary_write_count;
{
  assume (page_table[la] != dummy_physical_address); //la is mapped
  assume (is_epc_address(page_table[la]) && !Epcm_valid(epcm[page_table[la]])); //must be a free epc address
  assume (!Lp_state_cr_enclave_mode(lp_state[curr_lp])); //enclave cannot call ecreate
  assume (Secs_size(secs) > 0); //positive sized enclave
  call ecreate(la, secs);
}

procedure {:inline 1} eadd_reg(la: linear_address, ls: linear_address, d: data)
modifies epcm, mem_secs, mem_reg, mem_tcs, arbitrary_write_count;
requires (page_table[la] != dummy_physical_address);
requires (page_table[ls] != dummy_physical_address);
requires (is_epc_address(page_table[ls]) && 
          Epcm_valid(epcm[page_table[ls]]) && 
          Epcm_pt(epcm[page_table[ls]]) == pt_secs &&
          !Secs_initialized(mem_secs[page_table[ls]]));
requires (la >= Secs_baseaddr(mem_secs[page_table[ls]]) &&
          la < (Secs_baseaddr(mem_secs[page_table[ls]]) + Secs_size(mem_secs[page_table[ls]])));
requires (is_epc_address(page_table[la]) && (!Epcm_valid(epcm[page_table[la]]))); //must be a free epc address
requires (!Lp_state_cr_enclave_mode(lp_state[curr_lp])); //enclave cannot call eadd
{
  var pa : physical_address;
  var ps : physical_address;
  pa := page_table[la];
  ps := page_table[ls];
  epcm[pa] := Epcm(true, pt_reg, ps, la);
  call unchecked_write_reg(pa, d);
}


procedure {:inline 1} eadd_reg_with_assumptions(la: linear_address, ls: linear_address, d: data)
modifies epcm, mem_secs, mem_reg, mem_tcs, arbitrary_write_count;
{
  assume (page_table[la] != dummy_physical_address);
  assume (page_table[ls] != dummy_physical_address);
  assume (is_epc_address(page_table[ls]) && 
          Epcm_valid(epcm[page_table[ls]]) && 
          Epcm_pt(epcm[page_table[ls]]) == pt_secs &&
          !Secs_initialized(mem_secs[page_table[ls]]));
  assume (la >= Secs_baseaddr(mem_secs[page_table[ls]]) &&
          la < (Secs_baseaddr(mem_secs[page_table[ls]]) + Secs_size(mem_secs[page_table[ls]])));
  assume (is_epc_address(page_table[la]) && (!Epcm_valid(epcm[page_table[la]]))); //must be a free epc address
  assume (!Lp_state_cr_enclave_mode(lp_state[curr_lp])); //enclave cannot call eadd
  call eadd_reg(la, ls, d);
}


procedure {:inline 1} eadd_tcs(la: linear_address, ls: linear_address, tcs: tcs_ty)
modifies epcm, mem_secs, mem_reg, mem_tcs, arbitrary_write_count;
requires (page_table[la] != dummy_physical_address);
requires (page_table[ls] != dummy_physical_address);
requires (is_epc_address(page_table[ls]) && 
          Epcm_valid(epcm[page_table[ls]]) && 
          Epcm_pt(epcm[page_table[ls]]) == pt_secs &&
          !Secs_initialized(mem_secs[page_table[ls]]));
requires (la >= Secs_baseaddr(mem_secs[page_table[ls]]) &&
          la < (Secs_baseaddr(mem_secs[page_table[ls]]) + Secs_size(mem_secs[page_table[ls]])));
requires is_epc_address(page_table[la]);
requires !Epcm_valid(epcm[page_table[la]]); //must be a free epc address
requires (!Lp_state_cr_enclave_mode(lp_state[curr_lp])); //enclave cannot call eadd
requires (Tcs_ossa(tcs) >= 0);
requires (Tcs_nssa(tcs) >= 0);
{
  var pa : physical_address;
  var ps : physical_address;
  pa := page_table[la];
  ps := page_table[ls];
  epcm[pa] := Epcm(true, pt_tcs, ps, la);
  //active = false, interrupted = false, and cssa must be 0
  call unchecked_write_tcs(pa, Tcs(false, false, Tcs_ossa(tcs), Tcs_nssa(tcs), 0));
}

procedure {:inline 1} eadd_tcs_with_assumptions(la: linear_address, ls: linear_address, tcs: tcs_ty)
modifies epcm, mem_secs, mem_reg, mem_tcs, arbitrary_write_count;
{
  assume (page_table[la] != dummy_physical_address);
  assume (page_table[ls] != dummy_physical_address);
  assume (is_epc_address(page_table[ls]) && 
          Epcm_valid(epcm[page_table[ls]]) && 
          Epcm_pt(epcm[page_table[ls]]) == pt_secs &&
          !Secs_initialized(mem_secs[page_table[ls]]));
  assume (la >= Secs_baseaddr(mem_secs[page_table[ls]]) &&
          la < (Secs_baseaddr(mem_secs[page_table[ls]]) + Secs_size(mem_secs[page_table[ls]])));
  assume is_epc_address(page_table[la]);
  assume !Epcm_valid(epcm[page_table[la]]); //must be a free epc address
  assume (!Lp_state_cr_enclave_mode(lp_state[curr_lp])); //enclave cannot call eadd
  assume (Tcs_ossa(tcs) >= 0);
  assume (Tcs_nssa(tcs) >= 0);
  call eadd_tcs(la, ls, tcs);
}


// remove EPC page at EPC address la
procedure {:inline 1} eremove(la: linear_address)
modifies epcm;
requires (page_table[la] != dummy_physical_address);
requires (is_epc_address(page_table[la]));
requires ((Epcm_valid(epcm[page_table[la]]) &&
           Epcm_pt(epcm[page_table[la]]) == pt_secs) ==>
          no_pages_in_enclave(epcm, page_table[la]));
requires ((Epcm_valid(epcm[page_table[la]]) &&
           Epcm_pt(epcm[page_table[la]]) != pt_secs) ==>
          no_threads_in_enclave(lp_state, Epcm_enclavesecs(epcm[page_table[la]])));
requires (!Lp_state_cr_enclave_mode(lp_state[curr_lp])); 
{
  var pa: physical_address;
  pa := page_table[la];
  //set valid bit to false
  epcm[pa] := Epcm(false, Epcm_pt(epcm[pa]), Epcm_enclavesecs(epcm[pa]), Epcm_enclaveaddress(epcm[pa]));
}

procedure {:inline 1} eremove_with_assumptions(la: linear_address)
modifies epcm;
{
  assume (page_table[la] != dummy_physical_address);
  assume (is_epc_address(page_table[la]));
  assume ((Epcm_valid(epcm[page_table[la]]) &&
           Epcm_pt(epcm[page_table[la]]) == pt_secs) ==>
           no_pages_in_enclave(epcm, page_table[la]));
  assume ((Epcm_valid(epcm[page_table[la]]) &&
           Epcm_pt(epcm[page_table[la]]) != pt_secs) ==>
           no_threads_in_enclave(lp_state, Epcm_enclavesecs(epcm[page_table[la]])));
  assume (!Lp_state_cr_enclave_mode(lp_state[curr_lp])); 
  call eremove(la);
}

// take measurement of a 256 byte region, must be invokes 16 times to measure a page
// However, this model takes the entire measurement of the page at once
procedure {:inline 1} eextend(la: linear_address)
modifies arbitrary_write_count, mem_reg, mem_secs, mem_tcs; 
requires is_epc_address(page_table[la]); 
requires (Epcm_valid(epcm[page_table[la]]) &&
         (Epcm_pt(epcm[page_table[la]]) == pt_reg ||
          Epcm_pt(epcm[page_table[la]]) == pt_tcs));
requires !(Secs_initialized(mem_secs[Epcm_enclavesecs(epcm[page_table[la]])]));
requires (!Lp_state_cr_enclave_mode(lp_state[curr_lp])); 
{
  var secs : secs_ty;
  var tmp_enclaveoffset : linear_address;
  var tmp_mrenclave : measurement_ty;

  secs := mem_secs[Epcm_enclavesecs(epcm[page_table[la]])];

  tmp_enclaveoffset := Epcm_enclaveaddress(epcm[page_table[la]]) - Secs_baseaddr(secs);
  //We are modeling at the page level
  //tmp_enclaveoffset := tmp_enclaveoffset + (linear_address - linear_address / 4096 * 4096);
  
  tmp_mrenclave := Secs_mrenclave(secs);
  tmp_mrenclave := sha256update(tmp_mrenclave, tmp_enclaveoffset);
  if (Epcm_pt(epcm[page_table[la]]) == pt_reg) {
    tmp_mrenclave := sha256update(tmp_mrenclave, reg_to_int(mem_reg[page_table[la]])); 
  } else {
    tmp_mrenclave := sha256update(tmp_mrenclave, tcs_to_int(mem_tcs[page_table[la]])); 
  }

  call unchecked_write_secs(Epcm_enclavesecs(epcm[page_table[la]]),
                            Secs(Secs_baseaddr(secs), Secs_size(secs), Secs_initialized(secs), 
                                 tmp_mrenclave, Secs_mrsigner(secs), 
                                 Secs_isvprodid(secs), Secs_isvsvn(secs), Secs_attributes(secs)));
}

procedure {:inline 1} eextend_with_assumptions(la: linear_address)
modifies arbitrary_write_count, mem_reg, mem_secs, mem_tcs; 
{
  assume is_epc_address(page_table[la]); 
  assume (Epcm_valid(epcm[page_table[la]]) &&
         (Epcm_pt(epcm[page_table[la]]) == pt_reg ||
          Epcm_pt(epcm[page_table[la]]) == pt_tcs));
  assume !(Secs_initialized(mem_secs[Epcm_enclavesecs(epcm[page_table[la]])]));
  assume (!Lp_state_cr_enclave_mode(lp_state[curr_lp])); 
  call eextend(la);
}

//rbx: targetinfo struct, rcx: reportdata struct, rdx: addr containing output report struct
procedure {:inline 1} ereport(targetinfo: targetinfo_ty, reportdata: data) returns (report_maced: report_maced_ty)
requires (Lp_state_cr_enclave_mode(lp_state[curr_lp])); 
{
  var tmp_reportkey : key_ty; 
  var tmp_currentsecs : secs_ty;
  var report : report_ty;
  var tmp_report_mac : mactext_ty report_ty;

  tmp_reportkey := derive_key_ereport(Targetinfo_attributes(targetinfo),
                                      Targetinfo_measurement(targetinfo));
  tmp_currentsecs := mem_secs[Lp_state_cr_active_secs(lp_state[curr_lp])];
  report := Report(Secs_isvprodid(tmp_currentsecs),
                   Secs_isvsvn(tmp_currentsecs),
                   Secs_attributes(tmp_currentsecs),
                   reportdata,
                   Secs_mrenclave(tmp_currentsecs),
                   Secs_mrsigner(tmp_currentsecs));
                   
  tmp_report_mac := cmac(tmp_reportkey, report);
  report_maced := Report_maced(report, tmp_report_mac); 
}

procedure {:inline 1} ereport_with_assumptions(targetinfo: targetinfo_ty, reportdata: data) returns (report_maced: report_maced_ty)
{
  assume (Lp_state_cr_enclave_mode(lp_state[curr_lp])); 
  call report_maced := ereport(targetinfo, reportdata);
}

const CSR_INTELPUBKEYHASH : hashtext_ty key_ty; 

// initialize enclave whose SECS page is located at EPC address ls
//rbx -> sigstruct, rcx -> secs, rdx -> einittoken
procedure {:inline 1} einit(sigstruct_signed: sigstruct_signed_ty, ls: linear_address, einittoken: einittoken_ty)
modifies arbitrary_write_count, mem_reg, mem_secs, mem_tcs; 
requires (page_table[ls] != dummy_physical_address);
requires (is_epc_address(page_table[ls]) && 
          !Secs_initialized(mem_secs[page_table[ls]]));
requires (!Lp_state_cr_enclave_mode(lp_state[curr_lp])); //enclave cannot call einit
requires decrypt(Sigstruct_modulus(Sigstruct_signed_sigstruct(sigstruct_signed)), 
                 Sigstruct_signed_signature(sigstruct_signed)) == 
         hash(Sigstruct_signed_sigstruct(sigstruct_signed)); 
requires (Epcm_valid(epcm[page_table[ls]]) && 
          Epcm_pt(epcm[page_table[ls]]) == pt_secs);
requires Sigstruct_enclavehash(Sigstruct_signed_sigstruct(sigstruct_signed)) == 
         Secs_mrenclave(mem_secs[page_table[ls]]);
//if INTEL_ONLY attributes are set, SIGSTRUCT must be signed using the Intel Key
//The INTEL_ONLY_MASK checks whether EINITTOKENKEY bit is set within the attributes struct
requires Attributes_einittokenkey(Secs_attributes(mem_secs[page_table[ls]])) ==> 
         (hash(Sigstruct_modulus(Sigstruct_signed_sigstruct(sigstruct_signed))) == CSR_INTELPUBKEYHASH);
//verify SIGSTRUCT.ATTRIBUTE requirements are met
//processor actually checks equality after ANDing with ATTRIBUTEMASK
requires Secs_attributes(mem_secs[page_table[ls]]) == Sigstruct_attributes(Sigstruct_signed_sigstruct(sigstruct_signed));
//if EINITTOKEN.VALID[0] is 0, verify the enclave is signed by Intel
requires (!Einittoken_valid(einittoken)) ==> 
         (hash(Sigstruct_modulus(Sigstruct_signed_sigstruct(sigstruct_signed))) == CSR_INTELPUBKEYHASH);
//TODO: check MAC in einittoken --- no clear need to model this check for now
requires (Einittoken_valid(einittoken)) ==>
         (Einittoken_mrenclave(einittoken) == Secs_mrenclave(mem_secs[page_table[ls]]) &&
          Einittoken_mrsigner(einittoken) == hash(Sigstruct_modulus(Sigstruct_signed_sigstruct(sigstruct_signed))));
requires (Einittoken_valid(einittoken)) ==>
         (Secs_attributes(mem_secs[page_table[ls]]) == Einittoken_attributes(einittoken));
{
  var secs : secs_ty;
  var tmp_mrsigner : hashtext_ty key_ty;
  var sigstruct : sigstruct_ty;

  sigstruct := Sigstruct_signed_sigstruct(sigstruct_signed);
  tmp_mrsigner := hash(Sigstruct_modulus(sigstruct)); 
  
  secs := mem_secs[page_table[ls]];

  call unchecked_write_secs(page_table[ls],
                            Secs(Secs_baseaddr(secs), Secs_size(secs), true, 
                                 Secs_mrenclave(secs), tmp_mrsigner, 
                                 Sigstruct_isvprodid(sigstruct), Sigstruct_isvsvn(sigstruct),
                                 Secs_attributes(secs)));
}

procedure {:inline 1} einit_with_assumptions(sigstruct_signed: sigstruct_signed_ty, ls: linear_address, einittoken: einittoken_ty)
modifies arbitrary_write_count, mem_reg, mem_secs, mem_tcs; 
{
  assume (page_table[ls] != dummy_physical_address);
  assume (is_epc_address(page_table[ls]) && 
          !Secs_initialized(mem_secs[page_table[ls]]));
  assume (!Lp_state_cr_enclave_mode(lp_state[curr_lp])); //enclave cannot call einit
  assume decrypt(Sigstruct_modulus(Sigstruct_signed_sigstruct(sigstruct_signed)), 
                 Sigstruct_signed_signature(sigstruct_signed)) == 
         hash(Sigstruct_signed_sigstruct(sigstruct_signed)); 
  assume (Epcm_valid(epcm[page_table[ls]]) && 
          Epcm_pt(epcm[page_table[ls]]) == pt_secs);
  assume Sigstruct_enclavehash(Sigstruct_signed_sigstruct(sigstruct_signed)) == 
         Secs_mrenclave(mem_secs[page_table[ls]]);
  assume Attributes_einittokenkey(Secs_attributes(mem_secs[page_table[ls]])) ==> 
         (hash(Sigstruct_modulus(Sigstruct_signed_sigstruct(sigstruct_signed))) == CSR_INTELPUBKEYHASH);
  assume Secs_attributes(mem_secs[page_table[ls]]) == Sigstruct_attributes(Sigstruct_signed_sigstruct(sigstruct_signed));
  assume (!Einittoken_valid(einittoken)) ==> 
         (hash(Sigstruct_modulus(Sigstruct_signed_sigstruct(sigstruct_signed))) == CSR_INTELPUBKEYHASH);
  assume (Einittoken_valid(einittoken)) ==>
         (Einittoken_mrenclave(einittoken) == Secs_mrenclave(mem_secs[page_table[ls]]) &&
          Einittoken_mrsigner(einittoken) == hash(Sigstruct_modulus(Sigstruct_signed_sigstruct(sigstruct_signed))));
  assume (Einittoken_valid(einittoken)) ==>
         (Secs_attributes(mem_secs[page_table[ls]]) == Einittoken_attributes(einittoken));
  call einit(sigstruct_signed, ls, einittoken);
}


//Enter an enclave via a thread whose TCS lives at EPC address la
procedure {:inline 1} eenter(la: linear_address)
modifies arbitrary_write_count, mem_reg, mem_secs, mem_tcs, lp_state; 
requires (page_table[la] != dummy_physical_address);
requires (!Tcs_active(mem_tcs[page_table[la]]) && 
          !Tcs_interrupted(mem_tcs[page_table[la]]));
requires (Epcm_enclaveaddress(epcm[page_table[la]]) == la &&
          Epcm_pt(epcm[page_table[la]]) == pt_tcs &&
          Epcm_valid(epcm[page_table[la]]));
requires (Tcs_cssa(mem_tcs[page_table[la]]) < Tcs_nssa(mem_tcs[page_table[la]]) &&
          is_epc_address(page_table[cssa_addr(mem_secs[Epcm_enclavesecs(epcm[page_table[la]])], mem_tcs[page_table[la]])]) && 
          Epcm_valid(epcm[page_table[cssa_addr(mem_secs[Epcm_enclavesecs(epcm[page_table[la]])], mem_tcs[page_table[la]])]]) && 
          Epcm_pt(epcm[page_table[cssa_addr(mem_secs[Epcm_enclavesecs(epcm[page_table[la]])], mem_tcs[page_table[la]])]]) == pt_reg &&
          Epcm_enclaveaddress(epcm[page_table[cssa_addr(mem_secs[Epcm_enclavesecs(epcm[page_table[la]])], mem_tcs[page_table[la]])]]) == 
                                              cssa_addr(mem_secs[Epcm_enclavesecs(epcm[page_table[la]])], mem_tcs[page_table[la]]) &&
          Epcm_enclavesecs(epcm[page_table[cssa_addr(mem_secs[Epcm_enclavesecs(epcm[page_table[la]])], mem_tcs[page_table[la]])]]) == 
                                         Epcm_enclavesecs(epcm[page_table[la]]) && 
          Secs_initialized(mem_secs[Epcm_enclavesecs(epcm[page_table[la]])]));
requires (!Lp_state_cr_enclave_mode(lp_state[curr_lp])); //enclave cannot call eenter
{
  var pa: physical_address;
  var psecs: physical_address;
  var pcssa: physical_address;

  pa := page_table[la];
  psecs := Epcm_enclavesecs(epcm[page_table[la]]);
  pcssa := page_table[cssa_addr(mem_secs[Epcm_enclavesecs(epcm[page_table[la]])], mem_tcs[page_table[la]])]; 

  call unchecked_write_tcs(pa, Tcs(true,
                                   Tcs_interrupted(mem_tcs[pa]),
                                   Tcs_ossa(mem_tcs[pa]),
                                   Tcs_nssa(mem_tcs[pa]),
                                   Tcs_cssa(mem_tcs[pa])
                                  ));

  lp_state[curr_lp] := Lp_state(true, 
                                pa, 
                                psecs, 
                                Lr_register(Secs_baseaddr(mem_secs[psecs]), Secs_size(mem_secs[psecs])),
                                pcssa
                               ); 
}

procedure {:inline 1} eenter_with_assumptions(la: linear_address)
modifies arbitrary_write_count, mem_reg, mem_secs, mem_tcs, lp_state; 
{
  assume (page_table[la] != dummy_physical_address);
  assume (!Tcs_active(mem_tcs[page_table[la]]) && 
          !Tcs_interrupted(mem_tcs[page_table[la]]));
  assume (Epcm_enclaveaddress(epcm[page_table[la]]) == la &&
          Epcm_pt(epcm[page_table[la]]) == pt_tcs &&
          Epcm_valid(epcm[page_table[la]]));
  assume (Tcs_cssa(mem_tcs[page_table[la]]) < Tcs_nssa(mem_tcs[page_table[la]]) &&
          is_epc_address(page_table[cssa_addr(mem_secs[Epcm_enclavesecs(epcm[page_table[la]])], mem_tcs[page_table[la]])]) && 
          Epcm_valid(epcm[page_table[cssa_addr(mem_secs[Epcm_enclavesecs(epcm[page_table[la]])], mem_tcs[page_table[la]])]]) && 
          Epcm_pt(epcm[page_table[cssa_addr(mem_secs[Epcm_enclavesecs(epcm[page_table[la]])], mem_tcs[page_table[la]])]]) == pt_reg &&
          Epcm_enclaveaddress(epcm[page_table[cssa_addr(mem_secs[Epcm_enclavesecs(epcm[page_table[la]])], mem_tcs[page_table[la]])]]) == 
                                              cssa_addr(mem_secs[Epcm_enclavesecs(epcm[page_table[la]])], mem_tcs[page_table[la]]) &&
          Epcm_enclavesecs(epcm[page_table[cssa_addr(mem_secs[Epcm_enclavesecs(epcm[page_table[la]])], mem_tcs[page_table[la]])]]) == 
                                         Epcm_enclavesecs(epcm[page_table[la]]) && 
          Secs_initialized(mem_secs[Epcm_enclavesecs(epcm[page_table[la]])]));
  assume (!Lp_state_cr_enclave_mode(lp_state[curr_lp])); //enclave cannot call eenter
  call eenter(la);
}

//Resume an enclave via a thread whose TCS lives at la
procedure {:inline 1} eresume(la: linear_address)
modifies arbitrary_write_count, mem_reg, mem_secs, mem_tcs, lp_state, xstate; 
requires (page_table[la] != dummy_physical_address);
requires (!Tcs_active(mem_tcs[page_table[la]])); 
requires (is_epc_address(page_table[la])); 
requires (Epcm_valid(epcm[page_table[la]]));
requires (Epcm_enclaveaddress(epcm[page_table[la]]) == la) && (Epcm_pt(epcm[page_table[la]]) == pt_tcs);
requires (Tcs_cssa(mem_tcs[page_table[la]]) > 0);
requires (is_epc_address(page_table[pssa_addr(mem_secs[Epcm_enclavesecs(epcm[page_table[la]])], mem_tcs[page_table[la]])]) && 
          Epcm_valid(epcm[page_table[pssa_addr(mem_secs[Epcm_enclavesecs(epcm[page_table[la]])], mem_tcs[page_table[la]])]]) && 
          Epcm_pt(epcm[page_table[pssa_addr(mem_secs[Epcm_enclavesecs(epcm[page_table[la]])], mem_tcs[page_table[la]])]]) == pt_reg);
requires (Epcm_enclaveaddress(epcm[page_table[pssa_addr(mem_secs[Epcm_enclavesecs(epcm[page_table[la]])], mem_tcs[page_table[la]])]]) == 
                                              pssa_addr(mem_secs[Epcm_enclavesecs(epcm[page_table[la]])], mem_tcs[page_table[la]]));
requires (Epcm_enclavesecs(epcm[page_table[pssa_addr(mem_secs[Epcm_enclavesecs(epcm[page_table[la]])], mem_tcs[page_table[la]])]]) == 
          Epcm_enclavesecs(epcm[page_table[la]])); 
requires (Secs_initialized(mem_secs[Epcm_enclavesecs(epcm[page_table[la]])]));
requires (!Lp_state_cr_enclave_mode(lp_state[curr_lp])); //enclave cannot call eresume
{
  var pa: physical_address;
  var psecs: physical_address;
  var ppssa: physical_address;

  pa := page_table[la];
  psecs := Epcm_enclavesecs(epcm[page_table[la]]);
  ppssa := page_table[pssa_addr(mem_secs[Epcm_enclavesecs(epcm[page_table[la]])], mem_tcs[page_table[la]])]; 

  call unchecked_write_tcs(pa, Tcs(true,  //active
                                   false, //interrupted
                                   Tcs_ossa(mem_tcs[pa]),
                                   Tcs_nssa(mem_tcs[pa]),
                                   Tcs_cssa(mem_tcs[pa]) - 1
                               ));

  lp_state[curr_lp] := Lp_state(true, 
                                pa, 
                                psecs, 
                                Lr_register(Secs_baseaddr(mem_secs[psecs]), Secs_size(mem_secs[psecs])),
                                ppssa
                               ); 
  xstate[curr_lp] := data_to_xstate(mem_reg[ppssa]); 
}

procedure {:inline 1} eresume_with_assumptions(la: linear_address)
modifies arbitrary_write_count, mem_reg, mem_secs, mem_tcs, lp_state, xstate; 
{  
  assume (page_table[la] != dummy_physical_address);
  assume (!Tcs_active(mem_tcs[page_table[la]])); 
  assume (is_epc_address(page_table[la]));
  assume (Epcm_valid(epcm[page_table[la]]));
  assume (Epcm_enclaveaddress(epcm[page_table[la]]) == la) && (Epcm_pt(epcm[page_table[la]]) == pt_tcs);
  assume (Tcs_cssa(mem_tcs[page_table[la]]) > 0);
  assume (is_epc_address(page_table[pssa_addr(mem_secs[Epcm_enclavesecs(epcm[page_table[la]])], mem_tcs[page_table[la]])]) && 
          Epcm_valid(epcm[page_table[pssa_addr(mem_secs[Epcm_enclavesecs(epcm[page_table[la]])], mem_tcs[page_table[la]])]]) && 
          Epcm_pt(epcm[page_table[pssa_addr(mem_secs[Epcm_enclavesecs(epcm[page_table[la]])], mem_tcs[page_table[la]])]]) == pt_reg);
  assume (Epcm_enclaveaddress(epcm[page_table[pssa_addr(mem_secs[Epcm_enclavesecs(epcm[page_table[la]])], mem_tcs[page_table[la]])]]) == 
                                              pssa_addr(mem_secs[Epcm_enclavesecs(epcm[page_table[la]])], mem_tcs[page_table[la]]));
  assume (Epcm_enclavesecs(epcm[page_table[pssa_addr(mem_secs[Epcm_enclavesecs(epcm[page_table[la]])], mem_tcs[page_table[la]])]]) == 
          Epcm_enclavesecs(epcm[page_table[la]])); 
  assume (Secs_initialized(mem_secs[Epcm_enclavesecs(epcm[page_table[la]])]));
  assume (!Lp_state_cr_enclave_mode(lp_state[curr_lp])); //enclave cannot call eresume
  call eresume(la);
}

function AES_GCM_ENC_reg(plaintext: data) : data;
function AES_GCM_DEC_reg(ciphertext: data) : data;
axiom (forall ptxt: data, ctxt: data :: {AES_GCM_ENC_reg(ptxt), AES_GCM_DEC_reg(ctxt)}
              AES_GCM_ENC_reg(ptxt) == ctxt ==> AES_GCM_DEC_reg(ctxt) == ptxt); 
axiom (forall ptxt: data, ctxt: data :: {AES_GCM_ENC_reg(ptxt), AES_GCM_DEC_reg(ctxt)}
              AES_GCM_DEC_reg(ctxt) == ptxt ==> AES_GCM_ENC_reg(ptxt) == ctxt); 

function AES_GCM_ENC_tcs(plaintext: tcs_ty) : data;
function AES_GCM_DEC_tcs(ciphertext: data) : tcs_ty;
axiom (forall ptxt: tcs_ty, ctxt: data :: {AES_GCM_ENC_tcs(ptxt), AES_GCM_DEC_tcs(ctxt)}
              AES_GCM_ENC_tcs(ptxt) == ctxt ==> AES_GCM_DEC_tcs(ctxt) == ptxt); 
axiom (forall ptxt: tcs_ty, ctxt: data :: {AES_GCM_ENC_tcs(ptxt), AES_GCM_DEC_tcs(ctxt)}
              AES_GCM_DEC_tcs(ctxt) == ptxt ==> AES_GCM_ENC_tcs(ptxt) == ctxt); 

function AES_GCM_ENC_secs(plaintext: secs_ty) : data;
function AES_GCM_DEC_secs(ciphertext: data) : secs_ty;
axiom (forall ptxt: secs_ty, ctxt: data :: {AES_GCM_ENC_secs(ptxt), AES_GCM_DEC_secs(ctxt)}
              AES_GCM_ENC_secs(ptxt) == ctxt ==> AES_GCM_DEC_secs(ctxt) == ptxt); 
axiom (forall ptxt: secs_ty, ctxt: data :: {AES_GCM_ENC_secs(ptxt), AES_GCM_DEC_secs(ctxt)}
              AES_GCM_DEC_secs(ctxt) == ptxt ==> AES_GCM_ENC_secs(ptxt) == ctxt); 


//copy a page from EPC page la to dst_la in unprotected memory
procedure {:inline 1} ewb(la: linear_address, pageinfo: pageinfo_ty)
modifies arbitrary_write_count, mem_reg, mem_secs, mem_tcs, epcm; 
requires (!Lp_state_cr_enclave_mode(lp_state[curr_lp])); //only OS/VMM allowed to call ewb
requires (is_epc_address(page_table[la]) && Epcm_valid(epcm[page_table[la]]));
//FIXME: This is too strict, but PRM is unclear on the requirements
requires ((Epcm_pt(epcm[page_table[la]]) == pt_reg) || 
          (Epcm_pt(epcm[page_table[la]]) == pt_tcs)) ==>
          no_threads_in_enclave(lp_state, Epcm_enclavesecs(epcm[page_table[la]]));
//FIXME: This is too strict, but PRM is unclear on the requirements
requires (Epcm_pt(epcm[page_table[la]]) == pt_secs) ==> 
         (no_threads_in_enclave(lp_state, page_table[la]) &&
          no_pages_in_enclave(epcm, page_table[la]));
requires (!is_epc_address(page_table[Pageinfo_srcpge(pageinfo)]));
{
  var pa: physical_address;
  var tmp_srcpge : linear_address;

  pa := page_table[la];
  tmp_srcpge := Pageinfo_srcpge(pageinfo);

  epcm[pa] := Epcm(false, Epcm_pt(epcm[pa]), Epcm_enclavesecs(epcm[pa]), Epcm_enclaveaddress(epcm[pa])); 

  if (Epcm_pt(epcm[pa]) == pt_reg) {
    call unchecked_write_reg(page_table[tmp_srcpge], AES_GCM_ENC_reg(mem_reg[pa]));
  } else if (Epcm_pt(epcm[pa]) == pt_tcs) {
    call unchecked_write_reg(page_table[tmp_srcpge], AES_GCM_ENC_tcs(mem_tcs[pa]));
  } else if (Epcm_pt(epcm[pa]) == pt_secs) {
    call unchecked_write_reg(page_table[tmp_srcpge], AES_GCM_ENC_secs(mem_secs[pa]));
  }
  //write out pcmd
}

//copy a page from src_la to EPC page la
procedure {:inline 1} eldu(la: linear_address, pageinfo: pageinfo_ty)
modifies mem_reg, mem_tcs, mem_secs, epcm, arbitrary_write_count;
requires (is_epc_address(page_table[la]) && !Epcm_valid(epcm[page_table[la]]));
requires ((Secinfo_flags_pt(Pageinfo_secinfo(pageinfo)) == pt_reg) || 
          (Secinfo_flags_pt(Pageinfo_secinfo(pageinfo)) == pt_tcs)) ==>
          (is_epc_address(page_table[Pageinfo_secs(pageinfo)]) &&
           Epcm_valid(epcm[page_table[Pageinfo_secs(pageinfo)]]) &&
           Epcm_pt(epcm[page_table[Pageinfo_secs(pageinfo)]]) == pt_secs);
requires (Secinfo_flags_pt(Pageinfo_secinfo(pageinfo)) == pt_secs) ==> 
         (Pageinfo_secs(pageinfo) == 0);
{
  var tmp_srcpge : linear_address;
  var tmp_secs : linear_address;
  var tmp_secinfo : secinfo_ty; 
  var pa: physical_address;
  var tmp_header_secinfo_flags_pt : page_ty; 

  pa := page_table[la];
  tmp_srcpge := Pageinfo_srcpge(pageinfo);
  tmp_secs := Pageinfo_secs(pageinfo);
  tmp_secinfo := Pageinfo_secinfo(pageinfo);

  tmp_header_secinfo_flags_pt := Secinfo_flags_pt(tmp_secinfo); 
  if (tmp_header_secinfo_flags_pt == pt_reg) {
    call unchecked_write_reg(pa, AES_GCM_DEC_reg(mem_reg[page_table[tmp_srcpge]]));
  } else if (tmp_header_secinfo_flags_pt == pt_tcs) {
    call unchecked_write_tcs(pa, AES_GCM_DEC_tcs(mem_reg[page_table[tmp_srcpge]]));
  } else if (tmp_header_secinfo_flags_pt == pt_secs) {
    call unchecked_write_secs(pa, AES_GCM_DEC_secs(mem_reg[page_table[tmp_srcpge]]));
  }

  epcm[pa] := Epcm(true, 
                   tmp_header_secinfo_flags_pt, 
                   Pageinfo_secs(pageinfo), 
                   Pageinfo_linaddr(pageinfo)); 
}

procedure {:inline 1} eexit()
modifies mem_reg, xstate, lp_state, mem_tcs, mem_secs, arbitrary_write_count;
requires (Lp_state_cr_enclave_mode(lp_state[curr_lp])); //enclave must call eexit
{
  var ptcs  : physical_address;
  ptcs := Lp_state_cr_tcs_pa(lp_state[curr_lp]);

  //NOTE: the registers are not cleared. It is the enclave's responsibility to do so.

  lp_state[curr_lp] := Lp_state(false,
                                Lp_state_cr_tcs_pa(lp_state[curr_lp]),
                                Lp_state_cr_active_secs(lp_state[curr_lp]),
                                Lp_state_cr_elrange(lp_state[curr_lp]),
                                Lp_state_ssa_pa(lp_state[curr_lp])
                               ); 
  call unchecked_write_tcs(ptcs, Tcs(false,
                                     Tcs_interrupted(mem_tcs[ptcs]),
                                     Tcs_ossa(mem_tcs[ptcs]),
                                     Tcs_nssa(mem_tcs[ptcs]),
                                     Tcs_cssa(mem_tcs[ptcs])
                                 ));
}

procedure {:inline 1} aexit(interrupt: bool)
modifies mem_reg, xstate, lp_state, mem_tcs, mem_secs, arbitrary_write_count;
requires (Lp_state_cr_enclave_mode(lp_state[curr_lp])); //can only exit from enclave mode
{
  var pt : physical_address;
  var pc : physical_address;
  pt := Lp_state_cr_tcs_pa(lp_state[curr_lp]);
  pc := Lp_state_ssa_pa(lp_state[curr_lp]);

  call unchecked_write_reg(pc, xstate_to_data(xstate[curr_lp]));
  xstate[curr_lp] := dummy_xstate;
  lp_state[curr_lp] := Lp_state(false,
                                Lp_state_cr_tcs_pa(lp_state[curr_lp]),
                                Lp_state_cr_active_secs(lp_state[curr_lp]),
                                Lp_state_cr_elrange(lp_state[curr_lp]),
                                Lp_state_ssa_pa(lp_state[curr_lp])
                               ); 
  call unchecked_write_tcs(pt, Tcs(false,
                                   interrupt,
                                   Tcs_ossa(mem_tcs[pt]),
                                   Tcs_nssa(mem_tcs[pt]),
                                   Tcs_cssa(mem_tcs[pt]) + 1
                                  ));
}

procedure {:inline 1} interrupt()
modifies mem_reg, xstate, lp_state, mem_tcs, mem_secs, arbitrary_write_count;
{
  if (Lp_state_cr_enclave_mode(lp_state[curr_lp])) {
    call aexit(true);  
  }
}

procedure {:inline 1} exception()
modifies mem_reg, xstate, lp_state, mem_tcs, mem_secs, arbitrary_write_count;
{
  if (Lp_state_cr_enclave_mode(lp_state[curr_lp])) {
    call aexit(false);  
  }
}

//rbx: input keyrequest struct, rcx: output outputdata struct
//return sealing and attestation keys
procedure {:inline 1} egetkey(keyrequest: keyrequest_ty) returns (result: key_ty)
requires (Lp_state_cr_enclave_mode(lp_state[curr_lp])); 
requires (Keyrequest_keyname(keyrequest) == seal_key) ==>
         (Keyrequest_isvsvn(keyrequest) > Secs_isvsvn(mem_secs[Lp_state_cr_active_secs(lp_state[curr_lp])]));
requires Keyrequest_keyname(keyrequest) == seal_key ||
         Keyrequest_keyname(keyrequest) == report_key;
{
  var tmp_currentsecs : secs_ty;
  var keyname : keyname_ty;
  var tmp_mrenclave : measurement_ty;
  var tmp_mrsigner : hashtext_ty key_ty;
  tmp_currentsecs := mem_secs[Lp_state_cr_active_secs(lp_state[curr_lp])];
  keyname := Keyrequest_keyname(keyrequest);

  if (keyname == seal_key) {
    tmp_mrenclave := 0;
    //include enclave identity?
    if (Keyrequest_keypolicy_mrenclave(keyrequest)) {
      tmp_mrenclave := Secs_mrenclave(tmp_currentsecs);
    }
    tmp_mrsigner := hash(dummy_signing_key);
    //include enclave author?
    if (Keyrequest_keypolicy_mrsigner(keyrequest)) {
      tmp_mrsigner := Secs_mrsigner(tmp_currentsecs);
    }
    result := derive_key_egetkey(seal_key, 
                                 Secs_isvprodid(tmp_currentsecs),
                                 Keyrequest_isvsvn(keyrequest),
                                 Secs_attributes(tmp_currentsecs),
                                 tmp_mrenclave, 
                                 tmp_mrsigner);
  }
  else if(keyname == report_key) {
    result := derive_key_egetkey(report_key, 
                                0,
                                0,
                                Secs_attributes(tmp_currentsecs),
                                Secs_mrenclave(tmp_currentsecs), 
                                hash(dummy_signing_key));
  }
}


procedure {:inline 1} egetkey_with_assumptions(keyrequest: keyrequest_ty) returns (result: key_ty)
{
  assume (Lp_state_cr_enclave_mode(lp_state[curr_lp])); 
  assume (Keyrequest_keyname(keyrequest) == seal_key) ==>
         (Keyrequest_isvsvn(keyrequest) > Secs_isvsvn(mem_secs[Lp_state_cr_active_secs(lp_state[curr_lp])]));
  assume Keyrequest_keyname(keyrequest) == seal_key ||
         Keyrequest_keyname(keyrequest) == report_key;
  call result := egetkey(keyrequest);
}

