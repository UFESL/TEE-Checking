// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: MIT-0

/*
 * Insert copyright notice
 */

/**
 * @file tdx_vmm_dispatcher_harness.c
 * @brief Implements the proof harness for tdx_vmm_dispatcher function.
 */
// #include "vmm_dispatcher/tdx_vmm_dispatcher.h"
#include "/home/hasini/Desktop/TEE/Verification/TEE/verification/formal/tdx/Model-Checking-TDX/tdx-module-v1.0.01.01/src/vmm_dispatcher/tdx_vmm_dispatcher.h"
#include "accessors/ia32_accessors.h"
#include "accessors/vt_accessors.h"
#include "accessors/data_accessors.h"
#include "x86_defs/vmcs_defs.h"
#include "auto_gen/tdx_error_codes_defs.h"
#include "data_structures/tdx_global_data.h"
#include "data_structures/tdx_local_data.h"
#include "tdx_vmm_api_handlers.h"
#include "debug/tdx_debug.h"
#include "helpers/helpers.h"

/*
 * Insert project header files that
 *   - include the declaration of the function
 *   - include the types needed to declare function arguments
 */
void tdx_vmm_dispatcher(void);

/**
 * @brief Starting point for formal analysis
 * 
 */
void harness(void)
{

  /* Insert argument declarations */

  tdx_vmm_dispatcher();
}
