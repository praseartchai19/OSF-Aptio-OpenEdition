## @file
# Silicon build option configuration file.
#
# Copyright (c) 2017, Intel Corporation. All rights reserved.<BR>
#
# This program and the accompanying materials are licensed and made available under
# the terms and conditions of the BSD License which accompanies this distribution.
# The full text of the license may be found at
# http://opensource.org/licenses/bsd-license.php
#
# THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
# WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
#
##

[BuildOptions]
# Define Build Options both for EDK and EDKII drivers.



# SA
  DEFINE PTT_BUILD_OPTION =


  DEFINE SIMICS_BUILD_OPTIONS =

!if gSiPkgTokenSpaceGuid.PcdSgEnable == TRUE
  DEFINE DSC_SG_BUILD_OPTIONS = -DSG_SUPPORT=1
!else
  DEFINE DSC_SG_BUILD_OPTIONS =
!endif

!if gSiPkgTokenSpaceGuid.PcdBdatEnable == TRUE
  DEFINE BDAT_BUILD_OPTION = -DBDAT_SUPPORT=1
!else
  DEFINE BDAT_BUILD_OPTION =
!endif

!if gSiPkgTokenSpaceGuid.PcdSsaFlagEnable == TRUE
  DEFINE DSC_SSA_BUILD_OPTIONS = -DSSA_FLAG=1 -DSSA_CLIENT_FLAG=1
  DEFINE BDAT_BUILD_OPTION = -DBDAT_SUPPORT=1
!else
  DEFINE DSC_SSA_BUILD_OPTIONS =
!endif

  DEFINE DSC_AMT_BUILD_OPTIONS =

  DEFINE SLE_BUILD_OPTIONS =
!if $(TARGET) == RELEASE
!if gSiPkgTokenSpaceGuid.PcdSiCatalogDebugEnable == TRUE
  DEFINE DEBUG_BUILD_OPTIONS =
!else
  # MDEPKG_NDEBUG is introduced for the intention
  # of size reduction when compiler optimization is disabled. If MDEPKG_NDEBUG is
  # defined, then debug and assert related macros wrapped by it are the NULL implementations.
  DEFINE DEBUG_BUILD_OPTIONS = -DMDEPKG_NDEBUG
!endif
!else
  DEFINE DEBUG_BUILD_OPTIONS =
!endif

!if gSiPkgTokenSpaceGuid.PcdOptimizeCompilerEnable == FALSE
  DEFINE OPTIMIZE_DISABLE_OPTIONS = -Od -GL-
!else
  DEFINE OPTIMIZE_DISABLE_OPTIONS =
!endif

DEFINE DSC_SIPKG_FEATURE_BUILD_OPTIONS = $(BDAT_BUILD_OPTION) $(PTT_BUILD_OPTION) $(DEBUG_BUILD_OPTIONS) $(DSC_SSA_BUILD_OPTIONS) $(DSC_AMT_BUILD_OPTIONS)
DEFINE DSC_SIPKG_FEATURE_BUILD_OPTIONS = $(DSC_SIPKG_FEATURE_BUILD_OPTIONS) $(DSC_SG_BUILD_OPTIONS) $(SIMICS_BUILD_OPTIONS)


[BuildOptions.Common.EDKII]

#
# For IA32 Global Build Flag
#
       *_*_IA32_CC_FLAGS      = $(DSC_SIPKG_FEATURE_BUILD_OPTIONS) -D PI_SPECIFICATION_VERSION=0x00010015 -DASF_PEI
       *_*_IA32_VFRPP_FLAGS   = $(DSC_SIPKG_FEATURE_BUILD_OPTIONS)
       *_*_IA32_APP_FLAGS     = $(DSC_SIPKG_FEATURE_BUILD_OPTIONS)
       *_*_IA32_ASLPP_FLAGS   = $(DSC_SIPKG_FEATURE_BUILD_OPTIONS)
       *_*_IA32_ASLCC_FLAGS   = $(DSC_SIPKG_FEATURE_BUILD_OPTIONS)

#
# For IA32 Specific Build Flag
#
GCC:   *_*_IA32_PP_FLAGS      = $(DSC_SIPKG_FEATURE_BUILD_OPTIONS)
MSFT:  *_*_IA32_ASM_FLAGS     = $(DSC_SIPKG_FEATURE_BUILD_OPTIONS)
MSFT:  *_*_IA32_CC_FLAGS      = $(DSC_SIPKG_FEATURE_BUILD_OPTIONS) $(OPTIMIZE_DISABLE_OPTIONS) -D PI_SPECIFICATION_VERSION=0x00010015 -DASF_PEI
MSFT:  *_*_IA32_VFRPP_FLAGS   = $(DSC_SIPKG_FEATURE_BUILD_OPTIONS) $(OPTIMIZE_DISABLE_OPTIONS)
MSFT:  *_*_IA32_APP_FLAGS     = $(DSC_SIPKG_FEATURE_BUILD_OPTIONS) $(OPTIMIZE_DISABLE_OPTIONS)
MSFT:  *_*_IA32_ASLPP_FLAGS   = $(DSC_SIPKG_FEATURE_BUILD_OPTIONS) $(OPTIMIZE_DISABLE_OPTIONS)
MSFT:  *_*_IA32_ASLCC_FLAGS   = $(DSC_SIPKG_FEATURE_BUILD_OPTIONS) $(OPTIMIZE_DISABLE_OPTIONS)

#
# For X64 Global Build Flag
#
       *_*_X64_CC_FLAGS       = $(DSC_SIPKG_FEATURE_BUILD_OPTIONS) -D PI_SPECIFICATION_VERSION=0x00010015
       *_*_X64_VFRPP_FLAGS    = $(DSC_SIPKG_FEATURE_BUILD_OPTIONS)
       *_*_X64_APP_FLAGS      = $(DSC_SIPKG_FEATURE_BUILD_OPTIONS)
       *_*_X64_ASLPP_FLAGS    = $(DSC_SIPKG_FEATURE_BUILD_OPTIONS)
       *_*_X64_ASLCC_FLAGS    = $(DSC_SIPKG_FEATURE_BUILD_OPTIONS)

#
# For X64 Specific Build Flag
#
GCC:   *_*_X64_PP_FLAGS       = $(DSC_SIPKG_FEATURE_BUILD_OPTIONS)
MSFT:  *_*_X64_ASM_FLAGS      = $(DSC_SIPKG_FEATURE_BUILD_OPTIONS)
MSFT:  *_*_X64_CC_FLAGS       = $(DSC_SIPKG_FEATURE_BUILD_OPTIONS) $(OPTIMIZE_DISABLE_OPTIONS) -D PI_SPECIFICATION_VERSION=0x00010015
MSFT:  *_*_X64_VFRPP_FLAGS    = $(DSC_SIPKG_FEATURE_BUILD_OPTIONS) $(OPTIMIZE_DISABLE_OPTIONS)
MSFT:  *_*_X64_APP_FLAGS      = $(DSC_SIPKG_FEATURE_BUILD_OPTIONS) $(OPTIMIZE_DISABLE_OPTIONS)
MSFT:  *_*_X64_ASLPP_FLAGS    = $(DSC_SIPKG_FEATURE_BUILD_OPTIONS)
MSFT:  *_*_X64_ASLCC_FLAGS    = $(DSC_SIPKG_FEATURE_BUILD_OPTIONS)


[BuildOptions.common.EDKII.DXE_RUNTIME_DRIVER]
GCC:   *_*_*_DLINK_FLAGS      = -z common-page-size=0x1000
MSFT:  *_*_*_DLINK_FLAGS      = /ALIGN:4096
XCODE: *_*_*_DLINK_FLAGS      = -segalign 0x1000

