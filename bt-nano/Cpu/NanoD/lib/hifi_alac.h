/*
********************************************************************************************
*
*                  Copyright (c):  Fuzhou Rockchip Electronics Co., Ltd
*                               All rights reserved.
*
* FileName: Cpu\NanoC\lib\hifi_alac.h
* Owner: WJR
* Date: 2014.11.28
* Time: 16:22:12
* Desc:
* History:
*    <author>     <date>       <time>     <version>       <Desc>
*    WJR     2014.11.28     16:22:12   1.0
********************************************************************************************
*/

#ifndef __CPU_NANOC_LIB_HIFI_ALAC_H__
#define __CPU_NANOC_LIB_HIFI_ALAC_H__

/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   #include define
*
*---------------------------------------------------------------------------------------------------------------------
*/

#include "typedef.h"

/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   #define / #typedef define
*
*---------------------------------------------------------------------------------------------------------------------
*/
#define ALAC_BPS                  (uint32)(0xFF << 24)
#define ALAC_LPC_ORDER            (uint32)(0xFF << 16)
#define ALAC_LPC_QUANT            (uint32)(0xFF << 8)

#define ALAC_INPUT_END_FLAG       (uint32)(0x1 << 5)

/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   global variable declare
*
*---------------------------------------------------------------------------------------------------------------------
*/



/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   API Declare
*
*---------------------------------------------------------------------------------------------------------------------
*/
extern rk_err_t hifi_alac_shell(void);
extern rk_err_t Alac_Set_CFG(UINT32 HifiId,int lpc_order, int lpc_quant,int bps);



#endif

