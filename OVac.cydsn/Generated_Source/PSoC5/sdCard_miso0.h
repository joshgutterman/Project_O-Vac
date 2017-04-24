/*******************************************************************************
* File Name: sdCard_miso0.h  
* Version 2.0
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_sdCard_miso0_H) /* Pins sdCard_miso0_H */
#define CY_PINS_sdCard_miso0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "sdCard_miso0_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_0 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 sdCard_miso0__PORT == 15 && ((sdCard_miso0__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    sdCard_miso0_Write(uint8 value) ;
void    sdCard_miso0_SetDriveMode(uint8 mode) ;
uint8   sdCard_miso0_ReadDataReg(void) ;
uint8   sdCard_miso0_Read(void) ;
uint8   sdCard_miso0_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define sdCard_miso0_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define sdCard_miso0_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define sdCard_miso0_DM_RES_UP          PIN_DM_RES_UP
#define sdCard_miso0_DM_RES_DWN         PIN_DM_RES_DWN
#define sdCard_miso0_DM_OD_LO           PIN_DM_OD_LO
#define sdCard_miso0_DM_OD_HI           PIN_DM_OD_HI
#define sdCard_miso0_DM_STRONG          PIN_DM_STRONG
#define sdCard_miso0_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define sdCard_miso0_MASK               sdCard_miso0__MASK
#define sdCard_miso0_SHIFT              sdCard_miso0__SHIFT
#define sdCard_miso0_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define sdCard_miso0_PS                     (* (reg8 *) sdCard_miso0__PS)
/* Data Register */
#define sdCard_miso0_DR                     (* (reg8 *) sdCard_miso0__DR)
/* Port Number */
#define sdCard_miso0_PRT_NUM                (* (reg8 *) sdCard_miso0__PRT) 
/* Connect to Analog Globals */                                                  
#define sdCard_miso0_AG                     (* (reg8 *) sdCard_miso0__AG)                       
/* Analog MUX bux enable */
#define sdCard_miso0_AMUX                   (* (reg8 *) sdCard_miso0__AMUX) 
/* Bidirectional Enable */                                                        
#define sdCard_miso0_BIE                    (* (reg8 *) sdCard_miso0__BIE)
/* Bit-mask for Aliased Register Access */
#define sdCard_miso0_BIT_MASK               (* (reg8 *) sdCard_miso0__BIT_MASK)
/* Bypass Enable */
#define sdCard_miso0_BYP                    (* (reg8 *) sdCard_miso0__BYP)
/* Port wide control signals */                                                   
#define sdCard_miso0_CTL                    (* (reg8 *) sdCard_miso0__CTL)
/* Drive Modes */
#define sdCard_miso0_DM0                    (* (reg8 *) sdCard_miso0__DM0) 
#define sdCard_miso0_DM1                    (* (reg8 *) sdCard_miso0__DM1)
#define sdCard_miso0_DM2                    (* (reg8 *) sdCard_miso0__DM2) 
/* Input Buffer Disable Override */
#define sdCard_miso0_INP_DIS                (* (reg8 *) sdCard_miso0__INP_DIS)
/* LCD Common or Segment Drive */
#define sdCard_miso0_LCD_COM_SEG            (* (reg8 *) sdCard_miso0__LCD_COM_SEG)
/* Enable Segment LCD */
#define sdCard_miso0_LCD_EN                 (* (reg8 *) sdCard_miso0__LCD_EN)
/* Slew Rate Control */
#define sdCard_miso0_SLW                    (* (reg8 *) sdCard_miso0__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define sdCard_miso0_PRTDSI__CAPS_SEL       (* (reg8 *) sdCard_miso0__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define sdCard_miso0_PRTDSI__DBL_SYNC_IN    (* (reg8 *) sdCard_miso0__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define sdCard_miso0_PRTDSI__OE_SEL0        (* (reg8 *) sdCard_miso0__PRTDSI__OE_SEL0) 
#define sdCard_miso0_PRTDSI__OE_SEL1        (* (reg8 *) sdCard_miso0__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define sdCard_miso0_PRTDSI__OUT_SEL0       (* (reg8 *) sdCard_miso0__PRTDSI__OUT_SEL0) 
#define sdCard_miso0_PRTDSI__OUT_SEL1       (* (reg8 *) sdCard_miso0__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define sdCard_miso0_PRTDSI__SYNC_OUT       (* (reg8 *) sdCard_miso0__PRTDSI__SYNC_OUT) 


#if defined(sdCard_miso0__INTSTAT)  /* Interrupt Registers */

    #define sdCard_miso0_INTSTAT                (* (reg8 *) sdCard_miso0__INTSTAT)
    #define sdCard_miso0_SNAP                   (* (reg8 *) sdCard_miso0__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_sdCard_miso0_H */


/* [] END OF FILE */
