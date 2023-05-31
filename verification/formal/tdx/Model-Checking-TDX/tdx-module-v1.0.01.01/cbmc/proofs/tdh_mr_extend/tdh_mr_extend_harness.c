// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: MIT-0

/*
 * Insert copyright notice
 */

/**
 * @file tdh_mr_extend_harness.c
 * @brief Implements the proof harness for tdh_mr_extend function.
 */
#include "tdx_vmm_api_handlers.h"
#include "tdx_basic_defs.h"
#include "auto_gen/tdx_error_codes_defs.h"
#include "x86_defs/x86_defs.h"
#include "data_structures/td_control_structures.h"
#include "memory_handlers/keyhole_manager.h"
#include "memory_handlers/pamt_manager.h"
#include "memory_handlers/sept_manager.h"
#include "helpers/helpers.h"
#include "accessors/ia32_accessors.h"
#include "accessors/data_accessors.h"
#include "crypto/sha384.h"


api_error_type tdh_mr_extend(uint64_t target_page_gpa, uint64_t target_tdr_pa);

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
  uint64_t target_page_gpa;
  uint64_t target_tdr_pa;

  tdh_mr_extend(target_page_gpa, target_tdr_pa);
}
