// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: MIT-0

/*
 * Insert copyright notice
 */

/**
 * @file tdh_sys_info_harness.c
 * @brief Implements the proof harness for tdh_sys_info function.
 */
#include "tdx_api_defs.h"
#include "tdx_basic_defs.h"
#include "tdx_basic_types.h"
#include "tdx_vmm_api_handlers.h"
#include "auto_gen/tdx_error_codes_defs.h"

#include "data_structures/tdx_global_data.h"
#include "helpers/helpers.h"
#include "memory_handlers/keyhole_manager.h"
#include "accessors/data_accessors.h"
#include "auto_gen/cpuid_configurations.h"

#define MAX_TDMRS 64

api_error_type tdh_sys_info(uint64_t tdhsysinfo_output_pa,
		uint64_t num_of_bytes_in_buffer, uint64_t target_cmr_info_pa,
		uint64_t num_of_cmr_info_entries);
/*
 * Insert project header files that
 *   - include the declaration of the function
 *   - include the types needed to declare function arguments
 */

/**
 * @brief Starting point for formal analysis
 * 
 */
void harness(void)
{

  /* Insert argument declarations */
  uint64_t tdhsysinfo_output_pa;
		uint64_t num_of_bytes_in_buffer;
     uint64_t target_cmr_info_pa;
		uint64_t num_of_cmr_info_entries;

  tdh_sys_info( tdhsysinfo_output_pa,
		num_of_bytes_in_buffer, target_cmr_info_pa,
		 num_of_cmr_info_entries);
}
