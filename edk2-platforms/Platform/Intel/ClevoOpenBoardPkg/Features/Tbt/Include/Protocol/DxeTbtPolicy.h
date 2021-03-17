/** @file
TBT DXE Policy

Copyright (c) 2019, Intel Corporation. All rights reserved.<BR>
This program and the accompanying materials are licensed and made available under
the terms and conditions of the BSD License that accompanies this distribution.
The full text of the license may be found at
http://opensource.org/licenses/bsd-license.php.

THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/
#ifndef _DXE_TBT_POLICY_H_
#define _DXE_TBT_POLICY_H_

#include <TbtPolicyCommonDefinition.h>

#pragma pack(push, 1)

#define DXE_TBT_POLICY_REVISION 1

//
// TBT Common Data Structure
//
typedef struct _TBT_COMMON_CONFIG{
  /**
    TBT Security Level
    <b>0: SL0 No Security</b>, 1: SL1 User Authorization, 2: SL2 Secure Connect, 3: SL3 Display Port and USB
  **/
  UINT32   SecurityMode      : 3;
  /**
    BIOS W/A for Hot plug of 12V USB devices cause electrical noise on PCH GPIOs
    <b>0: Disabled</b>, 1: Enabled
  **/
  UINT32   Gpio5Filter       : 1;
  /**
    Send Go2SxNoWake or GoSxWake according to TbtWakeupSupport
    <b>0: Disabled</b>, 1: Enabled
  **/
  UINT32   TbtWakeupSupport  : 1;
  /**
    SMI TBT enumeration
    <b>0: Disabled</b>, 1: Enabled
  **/
  UINT32   TbtHotSMI         : 1;
  /**
    Notify PCIe RP after Hot-Plug/Hot-Unplug occurred.
    <b>0: Disabled</b>, 1: Enabled
  **/
  UINT32   TbtHotNotify      : 1;
  /**
    CLK REQ for all the PCIe device in TBT daisy chain.
    <b>0: Disabled</b>, 1: Enabled
  **/
  UINT32   TbtSetClkReq      : 1;
  /**
    ASPM setting for all the PCIe device in TBT daisy chain.
    <b>0: Disabled</b>, 1: L0s, 2: L1, 3: L0sL1
  **/
  UINT32   TbtAspm           : 2;
  /**
    LTR for for all the PCIe device in TBT daisy chain.
    <b>0: Disabled</b>, 1: Enabled
  **/
  UINT32   TbtLtr            : 1;
  /**
    TBT Dynamic AC/DC L1.
    <b>0: Disabled</b>, 1: Enabled
  **/
  UINT32   TbtAcDcSwitch     : 1;
  /**
    TBT RTD3 Support.
    <b>0: Disabled</b>, 1: Enabled
  **/
  UINT32   Rtd3Tbt           : 1;
  /**
    TBT ClkReq for RTD3 Flow.
    <b>0: Disabled</b>, 1: Enabled
  **/
  UINT32   Rtd3TbtClkReq     : 1;
  /**
    TBT Win10support for Tbt FW execution mode.
    <b>0: Disabled</b>, 1: Native, 2: Native + RTD3
  **/
  UINT32   Win10Support      : 2;
  UINT32   Rsvd0             : 17; ///< Reserved bits
  UINT16  Rtd3TbtClkReqDelay;
  UINT16  Rtd3TbtOffDelay;
} TBT_COMMON_CONFIG;

//
// dTBT Resource Data Structure
//
typedef struct _DTBT_RESOURCE_CONFIG{
  UINT8  DTbtPcieExtraBusRsvd;     ///< Preserve Bus resource for PCIe RP that connect to dTBT Host Router
  UINT16 DTbtPcieMemRsvd;          ///< Preserve MEM resource for PCIe RP that connect to dTBT Host Router
  UINT8  DTbtPcieMemAddrRngMax;    ///< Alignment of Preserve MEM resource for PCIe RP that connect to dTBT Host Router
  UINT16 DTbtPciePMemRsvd;         ///< Preserve PMEM resource for PCIe RP that connect to dTBT Host Router
  UINT8  DTbtPciePMemAddrRngMax;   ///< Alignment of Preserve PMEM resource for PCIe RP that connect to dTBT Host Router
  UINT8  Reserved[1];      ///< Reserved for DWORD alignment
} DTBT_RESOURCE_CONFIG;

/**
 TBT DXE configuration\n
  <b>Revision 1</b>:
  - Initial version.
**/
typedef struct _DXE_TBT_POLICY_PROTOCOL {
  TBT_COMMON_CONFIG      TbtCommonConfig;                                  ///< Tbt Common Information
  DTBT_RESOURCE_CONFIG   DTbtResourceConfig;   ///< dTbt Resource Configuration
} DXE_TBT_POLICY_PROTOCOL;

#pragma pack(pop)

#endif
