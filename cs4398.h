/*
 * ALSA SoC CS4398 codec driver
 *
 * Copyright 2016 Dennis Fleming
 *
 * Derived from ALSA SoC CS4349
 * by Tim Howe <Tim.Howe@cirrus.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 */

#ifndef __CS4398_H__
#define __CS4398_H__

/* CS4398 registers addresses */
#define CS4398_CHIPID		0x01	/* Device and Rev ID, Read Only */
#define CS4398_MODE		0x02	/* Mode Control */
#define CS4398_VMI		0x03	/* Volume, Mixing, Inversion Control */
#define CS4398_MUTE		0x04	/* Mute Control */
#define CS4398_VOLA		0x05	/* DAC Channel A Volume Control */
#define CS4398_VOLB		0x06	/* DAC Channel B Volume Control */
#define CS4398_RMPFLT		0x07	/* Ramp and Filter Control */
#define CS4398_MISC		0x08	/* Power Down,Freeze Control,Pop Stop*/
#define CS4398_MISC2            0x09    /* Static/Invalid DSD Detect, Phase mode*/

#define CS4398_I2C_INCR		0x80

/* Device and Revision ID */
#define CS4398_REVA		0x70	/* Rev A */
#define CS4398_REVB		0x71	/* Rev B */


/* PDN_DONE Poll Maximum
 * If soft ramp is set it will take much longer to power down
 * the system.
 */
#define PDN_POLL_MAX		900


/* Bitfield Definitions */

/* CS4398_MODE */
/* (Digital Interface Format, De-Emphasis Control, Functional Mode */
#define DSD_SRC                 (1 << 7)
#define DIF2			(1 << 6)
#define DIF1			(1 << 5)
#define DIF0			(1 << 4)
#define DEM1			(1 << 3)
#define DEM0			(1 << 2)
#define FM1			(1 << 1)
#define FM0                     (1 << 0)
#define DIF_LEFT_JST		0x00
#define DIF_I2S			0x01
#define DIF_RGHT_JST16		0x02
#define DIF_RGHT_JST24		0x03
#define DIF_RGHT_JST20		0x04
#define DIF_RGHT_JST18		0x05
#define DIF_RESERVE1		0x06
#define DIF_RESERVE2		0x07
#define DIF_MASK		0x70
#define MODE_FORMAT(x)		(((x)&7)<<4)

/* Values checked in place
#define DEM_MASK		0x0C
#define NO_DEM			0x00
#define DEM_441			0x04
#define DEM_48K			0x08
#define DEM_32K			0x0C
#define FM_AUTO			0x00
#define FM_SNGL			0x01
#define FM_DBL			0x02
#define FM_QUAD			0x03
#define FM_SNGL_MIN		30000
#define FM_SNGL_MAX		54000
#define FM_DBL_MAX		108000
#define FM_QUAD_MAX		216000
#define FM_MASK			0x03

/* CS4398_VMI (VMI = Volume, Mixing and Inversion Controls) */
#define VOLBISA			(1 << 7)
#define VOLAISB			(1 << 7)
#define INVERT_A		(1 << 6)
#define INVERT_B		(1 << 5)
#define ATAPI4                  (1 << 4)
#define ATAPI3			(1 << 3)
#define ATAPI2			(1 << 2)
#define ATAPI1			(1 << 1)
#define ATAPI0			(1 << 0)
#define MUTEAB			0x00
#define MUTEA_RIGHTB		0x01
#define MUTEA_LEFTB		0x02
#define MUTEA_SUMLRDIV2B	0x03
#define RIGHTA_MUTEB		0x04
#define RIGHTA_RIGHTB		0x05
#define RIGHTA_LEFTB		0x06
#define RIGHTA_SUMLRDIV2B	0x07
#define LEFTA_MUTEB		0x08
#define LEFTA_RIGHTB		0x09	/* Default */
#define LEFTA_LEFTB		0x0A
#define LEFTA_SUMLRDIV2B	0x0B
#define SUMLRDIV2A_MUTEB	0x0C
#define SUMLRDIV2A_RIGHTB	0x0D
#define SUMLRDIV2A_LEFTB	0x0E
#define SUMLRDIV2_AB		0x0F
 /* Tease out the rest of teh CS4398 mixing modes */
#define CHMIX_MASK		0x0F

/* CS4398_MUTE */
#define PAMUTE	 	        (1 << 7)
#define DAMUTE	 	        (1 << 7)
#define MUTEC_AB		(1 << 5)
#define MUTE_A			(1 << 4)
#define MUTE_B			(1 << 3)
#define MUTE_AB_MASK		0x18
#define MUTEP_AUTO              0x00
#define MUTEP_RESRV             0x01
#define MUTEP_ACTLOW            0x02
#define MUTEP_ACTHI             0x03
#define MUTEP_MASK              0x03

/* CS4398_RMPFLT (Ramp and Filter Control) */
#define SCZ1			(1 << 7)  /* Immediate (0) vs Soft (1)
#define SCZ0			(1 << 6)  /* Immediate (0) vs zero crossing (1)
#define RMP_UP			(1 << 5)
#define RMP_DN			(1 << 4)
#define FILT_SEL		(1 << 2)
#define IMMDT_CHNG		0x31
#define ZEROCRSS		0x71
#define SOFT_RMP		0xB1
#define SFTRMP_ZEROCRSS		0xF1
#define SR_ZC_MASK		0xC0

/* CS4398_MISC */
#define PWR_DWN			(1 << 7)
#define CPEN                    (1 << 6)
#define FREEZE			(1 << 5)
#define MCLKDIV2                (1 << 4)
#define MCLKDIV3                (1 << 3)

/* CS4398_MISC2 */
#define STATIC_DSD              (1 << 3)
#define INVALID_DSD             (1 << 2)
#define DSD_PM_MODE_MASK        0x03
#define DSD_PM_MODE1            (1 << 1)
#define DSD_PM_MODE0            (1 << 0)

#endif	/* __CS4398_H__ */
