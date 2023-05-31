// Intel Proprietary 
// 
// Copyright 2021 Intel Corporation All Rights Reserved.
// 
// Your use of this software is governed by the TDX Source Code LIMITED USE LICENSE.
// 
// The Materials are provided “as is,” without any express or implied warranty of any kind including warranties
// of merchantability, non-infringement, title, or fitness for a particular purpose.

/**
 * @file data_accessors.h
 * @brief Global and local data accessors, and SYSINFO table acessors
 */

#ifndef SRC_COMMON_ACCESSORS_DATA_ACCESSORS_H_
#define SRC_COMMON_ACCESSORS_DATA_ACCESSORS_H_

#include "tdx_basic_defs.h"
#include "tdx_basic_types.h"
#include "data_structures/tdx_local_data.h"
#include "data_structures/tdx_global_data.h"
#include "data_structures/loader_data.h"
#include <stdlib.h>
#include <stdio.h>

//****************************************************************************************
// Optimized accessors to SEAM module data structures - always use those in the code
//****************************************************************************************
// Explanation on the syntax below:
// The "i" constraint creates a constant integer immediate input constraint with a symbolic name, "local_data".
// The square brackets are the syntax to reference the immediate.
// And the '%c' syntax is necessary to get the formatting correct for using the constant as a memory operand.
// More info:
// https://gcc.gnu.org/onlinedocs/gcc/Simple-Constraints.html#Simple-Constraints,
// https://gcc.gnu.org/onlinedocs/gcc/Extended-Asm.html#InputOperands
// https://gcc.gnu.org/onlinedocs/gccint/Output-Template.html#Output-Template.

_STATIC_INLINE_ tdx_module_local_t* get_local_data(void)
{
    // uint64_t local_data_addr;
    // int64_t *x = {1};
    

    // _ASM_ ("movq %%gs:%c[local_data], %0\n\t"
    //          :"=r"(local_data_addr)
    //          :[local_data]"i"(offsetof(tdx_module_local_t, local_data_fast_ref_ptr)));

    // return (tdx_module_local_t*)local_data_addr;
    // return 0x
    // tdx_module_local_t x = {0};
    // gprs_state_t regs = {0};
    // x.vmm_regs = regs;
    // // x.vmm_regs.rdx = 0ULL;
    // return &x; 

    // Allocate memory for the struct
    tdx_module_local_t* local_data_ptr = malloc(sizeof(tdx_module_local_t));

    // Check if the allocation was successful
    if (local_data_ptr == NULL) {
        // handle the error
        printf("Error: Could not allocate memory for the struct.\n");
        exit(1);
    }

    // Initialize the members of the struct
    // my_local_data->vmm_regs = ...;
    uint64_t x1;
    uint64_t x2;
    local_data_ptr->vmm_regs.rcx = x1;
    local_data_ptr->vmm_regs.rdx = x2;
    // my_local_data->td_regs = ...;
    // my_local_data->lp_info = ...;
    // my_local_data->lp_is_init = ...;
    // my_local_data->ia32_debugctl_value = ...;
    // my_local_data->vp_ctx = ...;
    // my_local_data->single_step_def_state = ...;
    // my_local_data->vmm_non_extended_state = ...;
    // my_local_data->keyhole_state = ...;
    // my_local_data->local_data_fast_ref_ptr = ...;
    // my_local_data->global_data_fast_ref_ptr = ...;
    // my_local_data->sysinfo_fast_ref_ptr = ...;

    // #ifdef DEBUGFEATURE_TDX_DBG_TRACE
    // my_local_data->local_dbg_msg_num = 0;
    // #endif

    return local_data_ptr;

    }

_STATIC_INLINE_ sysinfo_table_t* get_sysinfo_table(void)
{
    uint64_t sysinfo_table_addr;
    _ASM_ ("movq %%gs:%c[sysinfo], %0\n\t"
             :"=r"(sysinfo_table_addr)
             :[sysinfo]"i"(offsetof(tdx_module_local_t, sysinfo_fast_ref_ptr)));

    return (sysinfo_table_t*)sysinfo_table_addr;
}

_STATIC_INLINE_ tdx_module_global_t* get_global_data(void)
{
    uint64_t global_data_addr;
    _ASM_ ("movq %%gs:%c[global_data], %0\n\t"
             :"=r"(global_data_addr)
             :[global_data]"i"(offsetof(tdx_module_local_t, global_data_fast_ref_ptr)));

    return (tdx_module_global_t*)global_data_addr;

    //  // Allocate memory for the struct
    // tdx_module_global_t* global_data_ptr = malloc(sizeof(tdx_module_global_t));

    // // Check if the allocation was successful
    // if (global_data_ptr == NULL) {
    //     // handle the error
    //     printf("Error: Could not allocate memory for the struct.\n");
    //     exit(1);
    // }
    // uint64_t hkid_mask;
    // global_data_ptr->hkid_mask = hkid_mask;

    // return global_data_ptr;
}

#define LOCAL_DATA_SIZE_PER_LP         (TDX_PAGE_SIZE_IN_BYTES * (get_sysinfo_table()->num_tls_pages + 1))

_STATIC_INLINE_ uint64_t get_current_thread_num(void)
{
    sysinfo_table_t* sysinfo_table = get_sysinfo_table();

    uint64_t current_local_data_addr = (uint64_t)get_local_data();
    uint64_t local_data_start_addr = sysinfo_table->data_rgn_base;

    return (current_local_data_addr - local_data_start_addr) / LOCAL_DATA_SIZE_PER_LP;
}

//****************************************************************************************
// Raw non-optimized accessors to SEAM module data structures - should not be used in code
//****************************************************************************************

// In SEAM TDX module, GSBASE holds a pointer to the local data of current thread
// We are reading GSBASE by loading effective address of 0 with GS prefix
_STATIC_INLINE_ tdx_module_local_t* calculate_local_data(void)
{
    void* local_data_addr;
    _ASM_VOLATILE_ ("rdgsbase %0"
                    :"=r"(local_data_addr)
                    :
                    :"cc");

    return (tdx_module_local_t*)local_data_addr;
}

// In SEAM TDX module, FSBASE holds a pointer to the SYSINFO table
// We are reading FSBASE by loading effective address of 0 with FS prefix
_STATIC_INLINE_ sysinfo_table_t* calculate_sysinfo_table(void)
{
    void* sysinfo_table_addr;
    _ASM_VOLATILE_ ("rdfsbase %0"
                    :"=r"(sysinfo_table_addr)
                    :
                    :"cc");

    return (sysinfo_table_t*)sysinfo_table_addr;
}

_STATIC_INLINE_ tdx_module_global_t* calculate_global_data(sysinfo_table_t* sysinfo_table)
{
    // For each addressable LP, there are D pages of data stack and 1 page of shadow stack,
    // where D = NUM_STACK_PAGES + 1.
    // STACK_REGION_SIZE gives the size (in bytes) of all stack pages, i.e. STACK_REGION_SIZE = (D + 1) * N * 4K.
    // Therefore, N = (STACK_REGION_SIZE / 4K) / (D + 1) = (STACK_REGION_SIZE >> 12) / (NUM_STACK_PAGES + 1 + 1).

    uint64_t num_of_addressable_lp = (sysinfo_table->stack_rgn_size / TDX_PAGE_SIZE_IN_BYTES) /
                                        (sysinfo_table->num_stack_pages + 1 + 1);

    uint64_t local_data_size_per_lp = (TDX_PAGE_SIZE_IN_BYTES * (sysinfo_table->num_tls_pages + 1));

    uint64_t global_data_addr = sysinfo_table->data_rgn_base +
            num_of_addressable_lp * local_data_size_per_lp;

    return (tdx_module_global_t*)global_data_addr;
}

// Must be first thing to do before accessing local/global data or sysinfo table
_STATIC_INLINE_ tdx_module_local_t* init_data_fast_ref_ptrs(void)
{
    tdx_module_local_t* local_data = calculate_local_data();

    IF_RARE (!local_data->local_data_fast_ref_ptr)
    {
        local_data->local_data_fast_ref_ptr  = local_data;
        local_data->sysinfo_fast_ref_ptr     = calculate_sysinfo_table();
        local_data->global_data_fast_ref_ptr = calculate_global_data((sysinfo_table_t*)
                                                    local_data->sysinfo_fast_ref_ptr);
    }

    return local_data;
}

#endif /* SRC_COMMON_ACCESSORS_DATA_ACCESSORS_H_ */
