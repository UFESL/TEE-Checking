// This is a copy of the memory section of sgx.bpl
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

axiom (forall lbase: linear_address, lsize: int :: {Lr_register(lbase,lsize)}
       Lr_register_lbase(Lr_register(lbase, lsize)) == lbase);
axiom (forall lbase: linear_address, lsize: int :: {Lr_register(lbase,lsize)}
       Lr_register_lsize(Lr_register(lbase, lsize)) == lsize);
axiom (forall lr: lr_register :: {Lr_register_lbase(lr)} {Lr_register_lsize(lr)}
       Lr_register(Lr_register_lbase(lr), Lr_register_lsize(lr)) == lr);
function in_register_range (linear_address, lr_register) : bool;
axiom (forall la : linear_address, lr : lr_register :: {in_register_range(la,lr)}
       in_register_range(la,lr) <==> Lr_register_lbase(lr) <= la && la < (Lr_register_lbase(lr) + Lr_register_lsize(lr)));
//function in_ssa_range(linear_address, tcs_ty, secs_ty): bool;
//axiom (forall la: linear_address, tcs: tcs_ty, secs: secs_ty :: {in_ssa_range(la, tcs, secs)}
//       in_ssa_range(la,tcs, secs) <==> (la >= (Secs_baseaddr(secs) + Tcs_ossa(tcs))) && (la < (Secs_baseaddr(secs) + Tcs_ossa(tcs) + Tcs_nssa(tcs))));

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

