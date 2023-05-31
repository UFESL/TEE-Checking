// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: MIT-0

/*
 * Insert copyright notice
 */

/**
 * @file is_private_hkid_harness.c
 * @brief Implements the proof harness for is_private_hkid function.
 */
// #ifndef SRC_COMMON_HELPERS_HELPERS_H_
// #define SRC_COMMON_HELPERS_HELPERS_H_

#include "tdx_basic_defs.h"
#include "tdx_basic_types.h"
#include "auto_gen/tdx_error_codes_defs.h"
#include "tdx_api_defs.h"
#include "/home/hasini/Desktop/TEE/Verification/TEE/verification/formal/tdx/Model-Checking-TDX/tdx-module-v1.0.01.01/src/common/x86_defs/x86_defs.h"
#include "/home/hasini/Desktop/TEE/Verification/TEE/verification/formal/tdx/Model-Checking-TDX/tdx-module-v1.0.01.01/src/common/accessors/data_accessors.h"
#include "/home/hasini/Desktop/TEE/Verification/TEE/verification/formal/tdx/Model-Checking-TDX/tdx-module-v1.0.01.01/src/common/accessors/vt_accessors.h"
#include "/home/hasini/Desktop/TEE/Verification/TEE/verification/formal/tdx/Model-Checking-TDX/tdx-module-v1.0.01.01/src/common/memory_handlers/keyhole_manager.h"
#include "/home/hasini/Desktop/TEE/Verification/TEE/verification/formal/tdx/Model-Checking-TDX/tdx-module-v1.0.01.01/src/common/memory_handlers/pamt_manager.h"
#include "/home/hasini/Desktop/TEE/Verification/TEE/verification/formal/tdx/Model-Checking-TDX/tdx-module-v1.0.01.01/src/common/data_structures/td_vmcs_init.h"
// #include "error_reporting.h"
/*
 * Insert project header files that
 *   - include the declaration of the function
 *   - include the types needed to declare function arguments
 */

bool_t is_private_hkid(uint16_t hkid);

/**
 * @brief Starting point for formal analysis
 * 
 */
void harness(void)
{
  uint16_t hkid;

  /* Insert argument declarations */

  is_private_hkid(hkid);
}
