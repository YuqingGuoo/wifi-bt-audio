/*
********************************************************************************************
*
*  Copyright (c):  Fuzhou Rockchip Electronics Co., Ltd
*                         All rights reserved.
*
* FileName: System\Example\ModuleFormat.c
* Owner: Aaron.sun
* Date: 2014.5.16
* Time: 18:14:46
* Desc: Module Format
* History:
*    <author>    <date>       <time>     <version>     <Desc>
*    Aaron.sun     2014.5.16     18:14:46   1.0
********************************************************************************************
*/

#include "BspConfig.h"
#ifdef __SYSTEM_EXAMPLE_MODULEFORMAT_C__

/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   #include define
*
*---------------------------------------------------------------------------------------------------------------------
*/
#include "Bsp.h"



/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   #define / #typedef define
*
*---------------------------------------------------------------------------------------------------------------------
*/

#define _SYSTEM_EXAMPLE_MODULEFORMAT_READ_  __attribute__((section("system_example_moduleformat_read")))
#define _SYSTEM_EXAMPLE_MODULEFORMAT_WRITE_ __attribute__((section("system_example_moduleformat_write")))
#define _SYSTEM_EXAMPLE_MODULEFORMAT_INIT_  __attribute__((section("system_example_moduleformat_init")))
#define _SYSTEM_EXAMPLE_MODULEFORMAT_SHELL_  __attribute__((section("system_example_moduleformat_shell")))


/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   local variable define
*
*---------------------------------------------------------------------------------------------------------------------
*/



/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   global variable define
*
*---------------------------------------------------------------------------------------------------------------------
*/



/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   local function declare
*
*---------------------------------------------------------------------------------------------------------------------
*/
rk_err_t TestShellTest(HDC dev, uint8 * pstr);



/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   API(read) define
*
*---------------------------------------------------------------------------------------------------------------------
*/



/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   local function(read) define
*
*---------------------------------------------------------------------------------------------------------------------
*/



/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   API(write) define
*
*---------------------------------------------------------------------------------------------------------------------
*/



/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   local function(write) define
*
*---------------------------------------------------------------------------------------------------------------------
*/



/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   API(init) define
*
*---------------------------------------------------------------------------------------------------------------------
*/



/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   local function(init) define
*
*---------------------------------------------------------------------------------------------------------------------
*/


#ifdef _TEST_SHELL_
_SYSTEM_EXAMPLE_MODULEFORMAT_SHELL_
static SHELL_CMD ShellTestName[] =
{
    "test",NULL,"NULL","NULL",
    "help",NULL,"NULL","NULL",
    "\b",NULL,"NULL","NULL",
};

/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   API(shell) define
*
*---------------------------------------------------------------------------------------------------------------------
*/
/*******************************************************************************
** Name: Test_Shell
** Input:HDC dev, uint8 * pstr
** Return: rk_err_t
** Owner:Aaron.sun
** Date: 2014.5.16
** Time: 18:15:33
*******************************************************************************/
_SYSTEM_EXAMPLE_MODULEFORMAT_SHELL_
SHELL API rk_err_t Test_Shell(HDC dev, uint8 * pstr)
{

}



/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   local function(shell) define
*
*---------------------------------------------------------------------------------------------------------------------
*/
/*******************************************************************************
** Name: TestShellTest
** Input:HDC dev, uint8 * pstr
** Return: rk_err_t
** Owner:Aaron.sun
** Date: 2014.5.16
** Time: 18:15:33
*******************************************************************************/
_SYSTEM_EXAMPLE_MODULEFORMAT_SHELL_
SHELL FUN rk_err_t TestShellTest(HDC dev, uint8 * pstr)
{

}



#endif
#endif

