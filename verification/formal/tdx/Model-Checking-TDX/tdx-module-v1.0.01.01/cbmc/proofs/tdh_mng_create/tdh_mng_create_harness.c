// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: MIT-0

/*
 * Insert copyright notice
 */

/**
 * @file tdh_mng_create_harness.c
 * @brief Implements the proof harness for tdh_mng_create function.
 */

#include "assert.h"
#include "stdio.h"
#include "tdx_vmm_api_handlers.h"
#include "tdx_basic_defs.h"
#include "auto_gen/tdx_error_codes_defs.h"
#include "x86_defs/x86_defs.h"
#include "data_structures/td_control_structures.h"
#include "memory_handlers/keyhole_manager.h"
#include "memory_handlers/pamt_manager.h"
#include "helpers/helpers.h"
#include "accessors/data_accessors.h"
#include "accessors/ia32_accessors.h"


/*
 * Insert project header files that
 *   - include the declaration of the function
 *   - include the types needed to declare function arguments
 */
api_error_type tdh_mng_create(uint64_t target_tdr_pa, hkid_api_input_t hkid_info);


/**
 * @brief Starting point for formal analysis
 * 
 */
void harness(void)
{

  /* Insert argument declarations */
  uint64_t target_tdr_pa;
  hkid_api_input_t hkid_info;
  __CPROVER_assume(target_tdr_pa != NULL);
  // __CPROVER_assume(sizeof(hkid_info.hkid)== 16);
  // __CPROVER_assume(get_global_data()->private_hkid_min != NULL);
  // __CPROVER_assume(get_global_data()->private_hkid_max != NULL);


  tdh_mng_create( target_tdr_pa, hkid_info);
  // assert(hkid_info.reserved != 0);

}
