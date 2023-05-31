// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: MIT-0

/*
 * Insert copyright notice
 */

/**
 * @file tdh_sys_config_harness.c
 * @brief Implements the proof harness for tdh_sys_config function.
 */
#include "tdx_api_defs.h"
#include "tdx_basic_defs.h"
#include "tdx_basic_types.h"
#include "tdx_vmm_api_handlers.h"
#include "auto_gen/tdx_error_codes_defs.h"
#include "data_structures/tdx_global_data.h"
#include "memory_handlers/pamt_manager.h"
#include "data_structures/loader_data.h"
#include "accessors/data_accessors.h"
#include "helpers/helpers.h"
#include "memory_handlers/keyhole_manager.h"
#include "auto_gen/cpuid_configurations.h"


/*
 * Insert project header files that
 *   - include the declaration of the function
 *   - include the types needed to declare function arguments
 */
api_error_type tdh_sys_config(uint64_t tdmr_info_array_pa,
                             uint64_t num_of_tdmr_entries,
                             hkid_api_input_t global_private_hkid);

/**
 * @brief Starting point for formal analysis
 * 
 */
void harness(void)
{

  /* Insert argument declarations */
  uint64_t tdmr_info_array_pa;
  uint64_t num_of_tdmr_entries;
  hkid_api_input_t global_private_hkid;

  tdh_sys_config( tdmr_info_array_pa, num_of_tdmr_entries, global_private_hkid );
}
