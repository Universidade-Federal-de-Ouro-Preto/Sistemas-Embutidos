/*******************************************************************************
* File Name: pino_chave.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_pino_chave_H) /* Pins pino_chave_H */
#define CY_PINS_pino_chave_H

#include "cytypes.h"
#include "cyfitter.h"
#include "pino_chave_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} pino_chave_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   pino_chave_Read(void);
void    pino_chave_Write(uint8 value);
uint8   pino_chave_ReadDataReg(void);
#if defined(pino_chave__PC) || (CY_PSOC4_4200L) 
    void    pino_chave_SetDriveMode(uint8 mode);
#endif
void    pino_chave_SetInterruptMode(uint16 position, uint16 mode);
uint8   pino_chave_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void pino_chave_Sleep(void); 
void pino_chave_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(pino_chave__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define pino_chave_DRIVE_MODE_BITS        (3)
    #define pino_chave_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - pino_chave_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the pino_chave_SetDriveMode() function.
         *  @{
         */
        #define pino_chave_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define pino_chave_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define pino_chave_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define pino_chave_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define pino_chave_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define pino_chave_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define pino_chave_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define pino_chave_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define pino_chave_MASK               pino_chave__MASK
#define pino_chave_SHIFT              pino_chave__SHIFT
#define pino_chave_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in pino_chave_SetInterruptMode() function.
     *  @{
     */
        #define pino_chave_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define pino_chave_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define pino_chave_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define pino_chave_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(pino_chave__SIO)
    #define pino_chave_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(pino_chave__PC) && (CY_PSOC4_4200L)
    #define pino_chave_USBIO_ENABLE               ((uint32)0x80000000u)
    #define pino_chave_USBIO_DISABLE              ((uint32)(~pino_chave_USBIO_ENABLE))
    #define pino_chave_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define pino_chave_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define pino_chave_USBIO_ENTER_SLEEP          ((uint32)((1u << pino_chave_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << pino_chave_USBIO_SUSPEND_DEL_SHIFT)))
    #define pino_chave_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << pino_chave_USBIO_SUSPEND_SHIFT)))
    #define pino_chave_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << pino_chave_USBIO_SUSPEND_DEL_SHIFT)))
    #define pino_chave_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(pino_chave__PC)
    /* Port Configuration */
    #define pino_chave_PC                 (* (reg32 *) pino_chave__PC)
#endif
/* Pin State */
#define pino_chave_PS                     (* (reg32 *) pino_chave__PS)
/* Data Register */
#define pino_chave_DR                     (* (reg32 *) pino_chave__DR)
/* Input Buffer Disable Override */
#define pino_chave_INP_DIS                (* (reg32 *) pino_chave__PC2)

/* Interrupt configuration Registers */
#define pino_chave_INTCFG                 (* (reg32 *) pino_chave__INTCFG)
#define pino_chave_INTSTAT                (* (reg32 *) pino_chave__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define pino_chave_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(pino_chave__SIO)
    #define pino_chave_SIO_REG            (* (reg32 *) pino_chave__SIO)
#endif /* (pino_chave__SIO_CFG) */

/* USBIO registers */
#if !defined(pino_chave__PC) && (CY_PSOC4_4200L)
    #define pino_chave_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define pino_chave_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define pino_chave_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define pino_chave_DRIVE_MODE_SHIFT       (0x00u)
#define pino_chave_DRIVE_MODE_MASK        (0x07u << pino_chave_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins pino_chave_H */


/* [] END OF FILE */
