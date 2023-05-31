// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: MIT-0

/*
 * Insert copyright notice
 */

/**
 * @file tdh_phymem_cache_wb_harness.c
 * @brief Implements the proof harness for tdh_phymem_cache_wb function.
 */
#include "tdx_vmm_api_handlers.h"
#include "tdx_basic_defs.h"
#include "auto_gen/tdx_error_codes_defs.h"
#include "x86_defs/x86_defs.h"
#include "data_structures/tdx_global_data.h"
#include "data_structures/tdx_local_data.h"
#include "memory_handlers/keyhole_manager.h"
#include "helpers/helpers.h"
#include "accessors/data_accessors.h"


api_error_type tdh_phymem_cache_wb(uint64_t cachewb_cmd);

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
  uint64_t cachewb_cmd;

  tdh_phymem_cache_wb(cachewb_cmd);
}
