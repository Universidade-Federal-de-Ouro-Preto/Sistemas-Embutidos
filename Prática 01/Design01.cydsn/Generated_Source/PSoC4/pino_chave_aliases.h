/*******************************************************************************
* File Name: pino_chave.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_pino_chave_ALIASES_H) /* Pins pino_chave_ALIASES_H */
#define CY_PINS_pino_chave_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define pino_chave_0			(pino_chave__0__PC)
#define pino_chave_0_PS		(pino_chave__0__PS)
#define pino_chave_0_PC		(pino_chave__0__PC)
#define pino_chave_0_DR		(pino_chave__0__DR)
#define pino_chave_0_SHIFT	(pino_chave__0__SHIFT)
#define pino_chave_0_INTR	((uint16)((uint16)0x0003u << (pino_chave__0__SHIFT*2u)))

#define pino_chave_INTR_ALL	 ((uint16)(pino_chave_0_INTR))


#endif /* End Pins pino_chave_ALIASES_H */


/* [] END OF FILE */
