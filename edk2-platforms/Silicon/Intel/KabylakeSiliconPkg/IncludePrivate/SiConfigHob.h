/** @file
  Silicon Config HOB is used for gathering platform
  related Intel silicon information and config setting.

Copyright (c) 2017, Intel Corporation. All rights reserved.<BR>
This program and the accompanying materials are licensed and made available under
the terms and conditions of the BSD License that accompanies this distribution.
The full text of the license may be found at
http://opensource.org/licenses/bsd-license.php.

THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef _SI_CONFIG_HOB_H_
#define _SI_CONFIG_HOB_H_

#include <SiPolicyStruct.h>

extern EFI_GUID gSiConfigHobGuid;

typedef CONST SI_CONFIG SI_CONFIG_HOB;
#endif
