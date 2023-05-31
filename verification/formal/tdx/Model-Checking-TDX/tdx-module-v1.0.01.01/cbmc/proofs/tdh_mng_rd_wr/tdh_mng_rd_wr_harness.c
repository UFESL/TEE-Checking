// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: MIT-0

/*
 * Insert copyright notice
 */

/**
 * @file tdh_mng_rd_wr_harness.c
 * @brief Implements the proof harness for tdh_mng_rd_wr function.
 */
#include "tdx_vmm_api_handlers.h"
#include "tdx_basic_defs.h"
#include "auto_gen/tdx_error_codes_defs.h"
#include "x86_defs/x86_defs.h"
#include "x86_defs/vmcs_defs.h"
#include "data_structures/tdx_local_data.h"
#include "data_structures/td_control_structures.h"
#include "memory_handlers/keyhole_manager.h"
#include "memory_handlers/pamt_manager.h"
#include "helpers/helpers.h"
#include "accessors/data_accessors.h"
#include "accessors/vt_accessors.h"
#include "auto_gen/tdvps_fields_lookup.h"

/*
 * Insert project header files that
 *   - include the declaration of the function
 *   - include the types needed to declare function arguments
 */
api_error_type tdh_mng_rd_wr(uint64_t target_tdr_pa, uint64_t requested_field_code,
        bool_t write, uint64_t wr_value, uint64_t wr_request_mask);

/**
 * @brief Starting point for formal analysis
 * 
 */
void harness(void)
{

  /* Insert argument declarations */
  uint64_t target_tdr_pa;
  uint64_t requested_field_code;

  bool_t write;
  uint64_t wr_value;
  uint64_t wr_request_mask;

  tdh_mng_rd_wr(target_tdr_pa, requested_field_code, write, wr_value, wr_request_mask);
}
