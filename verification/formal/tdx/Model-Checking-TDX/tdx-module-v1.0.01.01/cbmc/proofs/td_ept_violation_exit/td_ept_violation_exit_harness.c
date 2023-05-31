// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: MIT-0

/*
 * Insert copyright notice
 */

/**
 * @file td_ept_violation_exit_harness.c
 * @brief Implements the proof harness for td_ept_violation_exit function.
 */
#include "td_dispatcher/tdx_td_dispatcher.h"
#include "tdx_api_defs.h"
#include "data_structures/tdx_tdvps.h"
#include "accessors/ia32_accessors.h"
#include "accessors/vt_accessors.h"
#include "accessors/data_accessors.h"
#include "x86_defs/vmcs_defs.h"
#include "data_structures/tdx_local_data.h"
#include "tdx_td_api_handlers.h"
#include "auto_gen/tdx_error_codes_defs.h"
#include "vmm_dispatcher/tdx_vmm_dispatcher.h"
#include "helpers/helpers.h"
#include "memory_handlers/sept_manager.h"
#include "td_dispatcher/vm_exits/td_vmexit.h"

void td_ept_violation_exit(vmx_exit_qualification_t exit_qualification, vm_vmexit_exit_reason_t vm_exit_reason);

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
  vmx_exit_qualification_t exit_qualification;
  vm_vmexit_exit_reason_t vm_exit_reason;

  td_ept_violation_exit(exit_qualification,  vm_exit_reason);
}
