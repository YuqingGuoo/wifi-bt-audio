/*
********************************************************************************************
*
*                Copyright (c):  Fuzhou Rockchip Electronic Co., Ltd
*                             All rights reserved.
*
* FileName: ..\Gui\GUIMsgBox.h
* Owner: Benjo.lei
* Date: 2015.10.14
* Time: 15:07:35
* Desc:
* History:
*   <author>    <date>       <time>     <version>     <Desc>
* Benjo.lei      2015.10.14     15:07:35   1.0
********************************************************************************************
*/

#ifndef __GUI_GUICHAIN_H__
#define __GUI_GUICHAIN_H__

/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   #include define
*
*---------------------------------------------------------------------------------------------------------------------
*/



/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   #define / #typedef define
*
*---------------------------------------------------------------------------------------------------------------------
*/
typedef struct _GUI_CHAIN_CLASS
{
    GUI_CONTROL_CLASS pfControl;
    uint32 ResourceId;
    uint32 Current;
    int num;
    int delay;
    int speed;
    int blurry;
}GUI_CHAIN_CLASS;

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
extern rk_err_t GUI_ChainDisplay(HGC hGc);
extern GUI_CONTROL_CLASS * GUI_ChainCreate(void *arg);
extern rk_err_t GUI_ChainDelete(HGC hGc);

#endif

