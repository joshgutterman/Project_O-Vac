/*******************************************************************************
* File Name: adjust_timer_PM.c
* Version 2.70
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "adjust_timer.h"

static adjust_timer_backupStruct adjust_timer_backup;


/*******************************************************************************
* Function Name: adjust_timer_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  adjust_timer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void adjust_timer_SaveConfig(void) 
{
    #if (!adjust_timer_UsingFixedFunction)
        adjust_timer_backup.TimerUdb = adjust_timer_ReadCounter();
        adjust_timer_backup.InterruptMaskValue = adjust_timer_STATUS_MASK;
        #if (adjust_timer_UsingHWCaptureCounter)
            adjust_timer_backup.TimerCaptureCounter = adjust_timer_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!adjust_timer_UDB_CONTROL_REG_REMOVED)
            adjust_timer_backup.TimerControlRegister = adjust_timer_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: adjust_timer_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  adjust_timer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void adjust_timer_RestoreConfig(void) 
{   
    #if (!adjust_timer_UsingFixedFunction)

        adjust_timer_WriteCounter(adjust_timer_backup.TimerUdb);
        adjust_timer_STATUS_MASK =adjust_timer_backup.InterruptMaskValue;
        #if (adjust_timer_UsingHWCaptureCounter)
            adjust_timer_SetCaptureCount(adjust_timer_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!adjust_timer_UDB_CONTROL_REG_REMOVED)
            adjust_timer_WriteControlRegister(adjust_timer_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: adjust_timer_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  adjust_timer_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void adjust_timer_Sleep(void) 
{
    #if(!adjust_timer_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(adjust_timer_CTRL_ENABLE == (adjust_timer_CONTROL & adjust_timer_CTRL_ENABLE))
        {
            /* Timer is enabled */
            adjust_timer_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            adjust_timer_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    adjust_timer_Stop();
    adjust_timer_SaveConfig();
}


/*******************************************************************************
* Function Name: adjust_timer_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  adjust_timer_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void adjust_timer_Wakeup(void) 
{
    adjust_timer_RestoreConfig();
    #if(!adjust_timer_UDB_CONTROL_REG_REMOVED)
        if(adjust_timer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                adjust_timer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
