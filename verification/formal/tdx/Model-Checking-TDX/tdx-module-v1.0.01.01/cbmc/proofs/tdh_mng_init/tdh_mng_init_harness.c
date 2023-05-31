// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: MIT-0

/*
 * Insert copyright notice
 */
#include "tdx_vmm_api_handlers.h"
#include "tdx_basic_defs.h"
#include "auto_gen/tdx_error_codes_defs.h"
#include "x86_defs/x86_defs.h"
#include "data_structures/td_control_structures.h"
#include "x86_defs/vmcs_defs.h"
#include "memory_handlers/keyhole_manager.h"
#include "memory_handlers/pamt_manager.h"
#include "memory_handlers/sept_manager.h"
#include "helpers/helpers.h"
#include "accessors/ia32_accessors.h"
#include "accessors/data_accessors.h"
#include "crypto/sha384.h"
#include "auto_gen/msr_config_lookup.h"
#include "auto_gen/cpuid_configurations.h"

/**
 * @file tdh_mng_init_harness.c
 * @brief Implements the proof harness for tdh_mng_init function.
 */

/*
 * Insert project header files that
 *   - include the declaration of the function
 *   - include the types needed to declare function arguments
 */
api_error_type tdh_mng_init(uint64_t target_tdr_pa, uint64_t target_td_params_pa)
;
/**
 * @brief Starting point for formal analysis
 * 
 */
void harness(void)
{

  /* Insert argument declarations */
  uint64_t target_tdr_pa;
  uint64_t target_td_params_pa;

  tdh_mng_init(target_tdr_pa, target_td_params_pa);
}
