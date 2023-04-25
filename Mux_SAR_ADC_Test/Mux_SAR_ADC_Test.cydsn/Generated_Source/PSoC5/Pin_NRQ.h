/*******************************************************************************
* File Name: Pin_NRQ.h  
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

#if !defined(CY_PINS_Pin_NRQ_H) /* Pins Pin_NRQ_H */
#define CY_PINS_Pin_NRQ_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Pin_NRQ_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Pin_NRQ__PORT == 15 && ((Pin_NRQ__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Pin_NRQ_Write(uint8 value) ;
void    Pin_NRQ_SetDriveMode(uint8 mode) ;
uint8   Pin_NRQ_ReadDataReg(void) ;
uint8   Pin_NRQ_Read(void) ;
uint8   Pin_NRQ_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Pin_NRQ_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Pin_NRQ_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Pin_NRQ_DM_RES_UP          PIN_DM_RES_UP
#define Pin_NRQ_DM_RES_DWN         PIN_DM_RES_DWN
#define Pin_NRQ_DM_OD_LO           PIN_DM_OD_LO
#define Pin_NRQ_DM_OD_HI           PIN_DM_OD_HI
#define Pin_NRQ_DM_STRONG          PIN_DM_STRONG
#define Pin_NRQ_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Pin_NRQ_MASK               Pin_NRQ__MASK
#define Pin_NRQ_SHIFT              Pin_NRQ__SHIFT
#define Pin_NRQ_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pin_NRQ_PS                     (* (reg8 *) Pin_NRQ__PS)
/* Data Register */
#define Pin_NRQ_DR                     (* (reg8 *) Pin_NRQ__DR)
/* Port Number */
#define Pin_NRQ_PRT_NUM                (* (reg8 *) Pin_NRQ__PRT) 
/* Connect to Analog Globals */                                                  
#define Pin_NRQ_AG                     (* (reg8 *) Pin_NRQ__AG)                       
/* Analog MUX bux enable */
#define Pin_NRQ_AMUX                   (* (reg8 *) Pin_NRQ__AMUX) 
/* Bidirectional Enable */                                                        
#define Pin_NRQ_BIE                    (* (reg8 *) Pin_NRQ__BIE)
/* Bit-mask for Aliased Register Access */
#define Pin_NRQ_BIT_MASK               (* (reg8 *) Pin_NRQ__BIT_MASK)
/* Bypass Enable */
#define Pin_NRQ_BYP                    (* (reg8 *) Pin_NRQ__BYP)
/* Port wide control signals */                                                   
#define Pin_NRQ_CTL                    (* (reg8 *) Pin_NRQ__CTL)
/* Drive Modes */
#define Pin_NRQ_DM0                    (* (reg8 *) Pin_NRQ__DM0) 
#define Pin_NRQ_DM1                    (* (reg8 *) Pin_NRQ__DM1)
#define Pin_NRQ_DM2                    (* (reg8 *) Pin_NRQ__DM2) 
/* Input Buffer Disable Override */
#define Pin_NRQ_INP_DIS                (* (reg8 *) Pin_NRQ__INP_DIS)
/* LCD Common or Segment Drive */
#define Pin_NRQ_LCD_COM_SEG            (* (reg8 *) Pin_NRQ__LCD_COM_SEG)
/* Enable Segment LCD */
#define Pin_NRQ_LCD_EN                 (* (reg8 *) Pin_NRQ__LCD_EN)
/* Slew Rate Control */
#define Pin_NRQ_SLW                    (* (reg8 *) Pin_NRQ__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Pin_NRQ_PRTDSI__CAPS_SEL       (* (reg8 *) Pin_NRQ__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Pin_NRQ_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Pin_NRQ__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Pin_NRQ_PRTDSI__OE_SEL0        (* (reg8 *) Pin_NRQ__PRTDSI__OE_SEL0) 
#define Pin_NRQ_PRTDSI__OE_SEL1        (* (reg8 *) Pin_NRQ__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Pin_NRQ_PRTDSI__OUT_SEL0       (* (reg8 *) Pin_NRQ__PRTDSI__OUT_SEL0) 
#define Pin_NRQ_PRTDSI__OUT_SEL1       (* (reg8 *) Pin_NRQ__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Pin_NRQ_PRTDSI__SYNC_OUT       (* (reg8 *) Pin_NRQ__PRTDSI__SYNC_OUT) 


#if defined(Pin_NRQ__INTSTAT)  /* Interrupt Registers */

    #define Pin_NRQ_INTSTAT                (* (reg8 *) Pin_NRQ__INTSTAT)
    #define Pin_NRQ_SNAP                   (* (reg8 *) Pin_NRQ__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Pin_NRQ_H */


/* [] END OF FILE */
