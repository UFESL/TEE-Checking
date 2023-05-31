// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: MIT-0

/*
 * Insert copyright notice
 */

/**
 * @file tdh_mem_page_demote_harness.c
 * @brief Implements the proof harness for tdh_mem_page_demote function.
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

/*
 * Insert project header files that
 *   - include the declaration of the function
 *   - include the types needed to declare function arguments
 */
api_error_type tdh_mem_page_demote(page_info_api_input_t gpa_page_info,
                              uint64_t target_tdr_pa, uint64_t target_sept_pa);

/**
 * @brief Starting point for formal analysis
 * 
 */
void harness(void)
{

  /* Insert argument declarations */
  page_info_api_input_t gpa_page_info;
  uint64_t target_tdr_pa;
  uint64_t target_sept_pa;

  tdh_mem_page_demote( gpa_page_info, target_tdr_pa, target_sept_pa);
}
