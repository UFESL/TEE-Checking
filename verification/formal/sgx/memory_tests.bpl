// test procedures for memory.bpl

// tests whether an EPC address is between 2000 and 3000
procedure check_epc_addr() {
       var epc_addr: int;
       assume epc_addr == 2500;
       assert is_epc_address(epc_addr);
}

procedure check_not_epc_addr() {
       var not_epc_addr: int;
       assume not_epc_addr == 1000;
       assert !is_epc_address(not_epc_addr);
}
