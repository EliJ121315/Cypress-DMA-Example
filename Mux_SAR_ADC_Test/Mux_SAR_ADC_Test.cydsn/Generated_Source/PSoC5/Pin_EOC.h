/*******************************************************************************
* File Name: Pin_EOC.h  
* Version 2.5
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

#if !defined(CY_PINS_Pin_EOC_H) /* Pins Pin_EOC_H */
#define CY_PINS_Pin_EOC_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Pin_EOC_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Pin_EOC__PORT == 15 && ((Pin_EOC__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Pin_EOC_Write(uint8 value) ;
void    Pin_EOC_SetDriveMode(uint8 mode) ;
uint8   Pin_EOC_ReadDataReg(void) ;
uint8   Pin_EOC_Read(void) ;
uint8   Pin_EOC_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Pin_EOC_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Pin_EOC_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Pin_EOC_DM_RES_UP          PIN_DM_RES_UP
#define Pin_EOC_DM_RES_DWN         PIN_DM_RES_DWN
#define Pin_EOC_DM_OD_LO           PIN_DM_OD_LO
#define Pin_EOC_DM_OD_HI           PIN_DM_OD_HI
#define Pin_EOC_DM_STRONG          PIN_DM_STRONG
#define Pin_EOC_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Pin_EOC_MASK               Pin_EOC__MASK
#define Pin_EOC_SHIFT              Pin_EOC__SHIFT
#define Pin_EOC_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pin_EOC_PS                     (* (reg8 *) Pin_EOC__PS)
/* Data Register */
#define Pin_EOC_DR                     (* (reg8 *) Pin_EOC__DR)
/* Port Number */
#define Pin_EOC_PRT_NUM                (* (reg8 *) Pin_EOC__PRT) 
/* Connect to Analog Globals */                                                  
#define Pin_EOC_AG                     (* (reg8 *) Pin_EOC__AG)                       
/* Analog MUX bux enable */
#define Pin_EOC_AMUX                   (* (reg8 *) Pin_EOC__AMUX) 
/* Bidirectional Enable */                                                        
#define Pin_EOC_BIE                    (* (reg8 *) Pin_EOC__BIE)
/* Bit-mask for Aliased Register Access */
#define Pin_EOC_BIT_MASK               (* (reg8 *) Pin_EOC__BIT_MASK)
/* Bypass Enable */
#define Pin_EOC_BYP                    (* (reg8 *) Pin_EOC__BYP)
/* Port wide control signals */                                                   
#define Pin_EOC_CTL                    (* (reg8 *) Pin_EOC__CTL)
/* Drive Modes */
#define Pin_EOC_DM0                    (* (reg8 *) Pin_EOC__DM0) 
#define Pin_EOC_DM1                    (* (reg8 *) Pin_EOC__DM1)
#define Pin_EOC_DM2                    (* (reg8 *) Pin_EOC__DM2) 
/* Input Buffer Disable Override */
#define Pin_EOC_INP_DIS                (* (reg8 *) Pin_EOC__INP_DIS)
/* LCD Common or Segment Drive */
#define Pin_EOC_LCD_COM_SEG            (* (reg8 *) Pin_EOC__LCD_COM_SEG)
/* Enable Segment LCD */
#define Pin_EOC_LCD_EN                 (* (reg8 *) Pin_EOC__LCD_EN)
/* Slew Rate Control */
#define Pin_EOC_SLW                    (* (reg8 *) Pin_EOC__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Pin_EOC_PRTDSI__CAPS_SEL       (* (reg8 *) Pin_EOC__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Pin_EOC_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Pin_EOC__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Pin_EOC_PRTDSI__OE_SEL0        (* (reg8 *) Pin_EOC__PRTDSI__OE_SEL0) 
#define Pin_EOC_PRTDSI__OE_SEL1        (* (reg8 *) Pin_EOC__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Pin_EOC_PRTDSI__OUT_SEL0       (* (reg8 *) Pin_EOC__PRTDSI__OUT_SEL0) 
#define Pin_EOC_PRTDSI__OUT_SEL1       (* (reg8 *) Pin_EOC__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Pin_EOC_PRTDSI__SYNC_OUT       (* (reg8 *) Pin_EOC__PRTDSI__SYNC_OUT) 


#if defined(Pin_EOC__INTSTAT)  /* Interrupt Registers */

    #define Pin_EOC_INTSTAT                (* (reg8 *) Pin_EOC__INTSTAT)
    #define Pin_EOC_SNAP                   (* (reg8 *) Pin_EOC__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Pin_EOC_H */


/* [] END OF FILE */
