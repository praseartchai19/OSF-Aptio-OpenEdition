/** @file
  Prototype of the PeiSaPolicy library.

Copyright (c) 2017, Intel Corporation. All rights reserved.<BR>
This program and the accompanying materials are licensed and made available under
the terms and conditions of the BSD License that accompanies this distribution.
The full text of the license may be found at
http://opensource.org/licenses/bsd-license.php.

THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/
#ifndef _PEI_SA_POLICY_LIB_H_
#define _PEI_SA_POLICY_LIB_H_

#include <Ppi/SiPolicy.h>
#include <Library/ConfigBlockLib.h>

/**
  This function prints the PEI phase PreMem policy.

  @param[in] SiPolicyPreMemPpi              The RC PreMem Policy PPI instance
**/
VOID
EFIAPI
SaPrintPolicyPpiPreMem (
  IN  SI_PREMEM_POLICY_PPI *SiPolicyPreMemPpi
  );

/**
  This function prints the PEI phase policy.

  @param[in] SiPolicyPpi              The RC Policy PPI instance
**/
VOID
EFIAPI
SaPrintPolicyPpi (
  IN  SI_POLICY_PPI     *SiPolicyPpi
  );

/**
  Get SA config block table total size.

  @retval     Size of SA config block table
**/
UINT16
EFIAPI
SaGetConfigBlockTotalSize (
  VOID
  );

/**
  Get SA config block table total size.

  @retval      Size of SA config block table
**/
UINT16
EFIAPI
SaGetConfigBlockTotalSizePreMem (
  VOID
  );

/**
  SaAddConfigBlocksPreMem add all SA config blocks.

  @param[in] ConfigBlockTableAddress    The pointer to add SA config blocks

  @retval EFI_SUCCESS                   The policy default is initialized.
  @retval EFI_OUT_OF_RESOURCES          Insufficient resources to create buffer
**/
EFI_STATUS
EFIAPI
SaAddConfigBlocksPreMem (
  IN VOID           *ConfigBlockTableAddress
  );

/**
  SaAddConfigBlocks add all SA config blocks.

  @param[in] ConfigBlockTableAddress    The pointer to add SA config blocks

  @retval EFI_SUCCESS                   The policy default is initialized.
  @retval EFI_OUT_OF_RESOURCES          Insufficient resources to create buffer
**/
EFI_STATUS
EFIAPI
SaAddConfigBlocks (
  IN VOID           *ConfigBlockTableAddress
  );
#endif // _PEI_SA_POLICY_LIBRARY_H_
