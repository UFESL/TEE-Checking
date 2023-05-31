// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: MIT-0

/*
 * Insert copyright notice
 */

/**
 * @file tdh_mem_page_relocate_harness.c
 * @brief Implements the proof harness for tdh_mem_page_relocate function.
 */
#include "tdx_vmm_api_handlers.h"
#include "tdx_basic_defs.h"
#include "auto_gen/tdx_error_codes_defs.h"
#include "x86_defs/x86_defs.h"
#include "helpers/helpers.h"

/*
 * Insert project header files that
 *   - include the declaration of the function
 *   - include the types needed to declare function arguments
 */
api_error_type tdh_mem_page_relocate(uint64_t source_page_pa,
                                    uint64_t target_tdr_pa,
                                    uint64_t target_page_pa);

/**
 * @brief Starting point for formal analysis
 * 
 */
void harness(void)
{

  /* Insert argument declarations */
  uint64_t source_page_pa;
  uint64_t target_tdr_pa;
  uint64_t target_page_pa;

  tdh_mem_page_relocate(source_page_pa, target_tdr_pa, target_page_pa);
}
