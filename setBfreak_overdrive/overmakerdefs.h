/* setBfree - DSP tonewheel organ
 *
 * Copyright (C) 2003-2004 Fredrik Kilander <fk@dsv.su.se>
 * Copyright (C) 2008-2012 Robin Gareus <robin@gareus.org>
 * Copyright (C) 2012 Will Panther <pantherb@setbfree.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/* overmakerdefs.h */
//#include "eqcomp.h"		/* Filter type symbols */

/*
 * List of strings for system include-files in the output souce code.
 */

#define SYSTEM_INCLUDES {NULL}

/*
 * List of strings for local include-files in the output source code.
 */

#define LOCAL_INCLUDES {"overdrive.h", NULL}

/* The nof points in the interpolation filter. */

#define IPOL_LEN 33

#define IPOL_FIR00 { \
  0.000000000000000000000000000000000069107852418382210791849936, /* [0] */  \
 -0.000029195141905802302062511444091796875000000000000000000000, /* [1] */  \
 -0.000240361885516904294490814208984375000000000000000000000000, /* [2] */  \
 -0.000806394324172288179397583007812500000000000000000000000000, /* [3] */  \
 -0.001801325590349733829498291015625000000000000000000000000000, /* [4] */  \
 -0.003049216698855161666870117187500000000000000000000000000000, /* [5] */  \
 -0.003958590794354677200317382812500000000000000000000000000000, /* [6] */  \
 -0.003437968436628580093383789062500000000000000000000000000000, /* [7] */  \
  0.000000000000000001693113499430822435897489933176451870622259, /* [8] */  \
  0.007889833301305770874023437500000000000000000000000000000000, /* [9] */  \
  0.021269135177135467529296875000000000000000000000000000000000, /* [10] */ \
  0.040103543549776077270507812500000000000000000000000000000000, /* [11] */ \
  0.062911629676818847656250000000000000000000000000000000000000, /* [12] */ \
  0.086793623864650726318359375000000000000000000000000000000000, /* [13] */ \
  0.107942819595336914062500000000000000000000000000000000000000, /* [14] */ \
  0.122537523508071899414062500000000000000000000000000000000000, /* [15] */ \
  0.127749890089035034179687500000000000000000000000000000000000, /* [16] */ \
  0.122537523508071899414062500000000000000000000000000000000000, /* [17] */ \
  0.107942819595336914062500000000000000000000000000000000000000, /* [18] */ \
  0.086793623864650726318359375000000000000000000000000000000000, /* [19] */ \
  0.062911629676818847656250000000000000000000000000000000000000, /* [20] */ \
  0.040103543549776077270507812500000000000000000000000000000000, /* [21] */ \
  0.021269135177135467529296875000000000000000000000000000000000, /* [22] */ \
  0.007889833301305770874023437500000000000000000000000000000000, /* [23] */ \
  0.000000000000000001693113499430822435897489933176451870622259, /* [24] */ \
 -0.003437968436628580093383789062500000000000000000000000000000, /* [25] */ \
 -0.003958590794354677200317382812500000000000000000000000000000, /* [26] */ \
 -0.003049216698855161666870117187500000000000000000000000000000, /* [27] */ \
 -0.001801325590349733829498291015625000000000000000000000000000, /* [28] */ \
 -0.000806394324172288179397583007812500000000000000000000000000, /* [29] */ \
 -0.000240361885516904294490814208984375000000000000000000000000, /* [30] */ \
 -0.000029195141905802302062511444091796875000000000000000000000, /* [31] */ \
  0.000000000000000000000000000000000069107852418382210791849936  /* [32] */ \
}

/* fdes -o 4 -kn 33  */

#define IPOL_FIR01 { \
 -0.000000000000000000388245104566976935245921787737133357154562, /* [0] */ \
 -0.000718555646017193794250488281250000000000000000000000000000, /* [1] */ \
 -0.001841715304180979728698730468750000000000000000000000000000, /* [2] */ \
 -0.003549180924892425537109375000000000000000000000000000000000, /* [3] */ \
 -0.005673130042850971221923828125000000000000000000000000000000, /* [4] */ \
 -0.007573895156383514404296875000000000000000000000000000000000, /* [5] */ \
 -0.008159336633980274200439453125000000000000000000000000000000, /* [6] */ \
 -0.006069717928767204284667968750000000000000000000000000000000, /* [7] */ \
  0.000000000000000002620654384741260421634156257963965686030861, /* [8] */ \
  0.010914741083979606628417968750000000000000000000000000000000, /* [9] */ \
  0.026753284037113189697265625000000000000000000000000000000000, /* [10] */ \
  0.046604625880718231201171875000000000000000000000000000000000, /* [11] */ \
  0.068580508232116699218750000000000000000000000000000000000000, /* [12] */ \
  0.090065538883209228515625000000000000000000000000000000000000, /* [13] */ \
  0.108164526522159576416015625000000000000000000000000000000000, /* [14] */ \
  0.120252311229705810546875000000000000000000000000000000000000, /* [15] */ \
  0.124499998986721038818359375000000000000000000000000000000000, /* [16] */ \
  0.120252311229705810546875000000000000000000000000000000000000, /* [17] */ \
  0.108164526522159576416015625000000000000000000000000000000000, /* [18] */ \
  0.090065538883209228515625000000000000000000000000000000000000, /* [19] */ \
  0.068580508232116699218750000000000000000000000000000000000000, /* [20] */ \
  0.046604625880718231201171875000000000000000000000000000000000, /* [21] */ \
  0.026753284037113189697265625000000000000000000000000000000000, /* [22] */ \
  0.010914741083979606628417968750000000000000000000000000000000, /* [23] */ \
  0.000000000000000002620654384741260421634156257963965686030861, /* [24] */ \
 -0.006069717928767204284667968750000000000000000000000000000000, /* [25] */ \
 -0.008159336633980274200439453125000000000000000000000000000000, /* [26] */ \
 -0.007573895156383514404296875000000000000000000000000000000000, /* [27] */ \
 -0.005673130042850971221923828125000000000000000000000000000000, /* [28] */ \
 -0.003549180924892425537109375000000000000000000000000000000000, /* [29] */ \
 -0.001841715304180979728698730468750000000000000000000000000000, /* [30] */ \
 -0.000718555646017193794250488281250000000000000000000000000000, /* [31] */ \
 -0.000000000000000000388245104566976935245921787737133357154562  /* [32] */ \
}

/* fdes -c 0.1 -kn 33 */

#define IPOL_FIR02 { \
 -0.000935046351514756679534912109375000000000000000000000000000, /* [0] */ \
  0.000000000000000000692266834260169446329125780836832859677088, /* [1] */ \
  0.001536353491246700286865234375000000000000000000000000000000, /* [2] */ \
  0.003666520351544022560119628906250000000000000000000000000000, /* [3] */ \
  0.005414571147412061691284179687500000000000000000000000000000, /* [4] */ \
  0.004835680592805147171020507812500000000000000000000000000000, /* [5] */ \
 -0.000000000000000002836163885632763486906778721552413458084629, /* [6] */ \
 -0.009355833753943443298339843750000000000000000000000000000000, /* [7] */ \
 -0.020424647256731986999511718750000000000000000000000000000000, /* [8] */ \
 -0.027221690863370895385742187500000000000000000000000000000000, /* [9] */ \
 -0.022317511960864067077636718750000000000000000000000000000000, /* [10] */ \
  0.000000000000000006199335706461330371347742684839943194674561, /* [11] */ \
  0.040453337132930755615234375000000000000000000000000000000000, /* [12] */ \
  0.093043193221092224121093750000000000000000000000000000000000, /* [13] */ \
  0.145996063947677612304687500000000000000000000000000000000000, /* [14] */ \
  0.185356348752975463867187500000000000000000000000000000000000, /* [15] */ \
  0.199905306100845336914062500000000000000000000000000000000000, /* [16] */ \
  0.185356348752975463867187500000000000000000000000000000000000, /* [17] */ \
  0.145996063947677612304687500000000000000000000000000000000000, /* [18] */ \
  0.093043193221092224121093750000000000000000000000000000000000, /* [19] */ \
  0.040453337132930755615234375000000000000000000000000000000000, /* [20] */ \
  0.000000000000000006199335706461330371347742684839943194674561, /* [21] */ \
 -0.022317511960864067077636718750000000000000000000000000000000, /* [22] */ \
 -0.027221690863370895385742187500000000000000000000000000000000, /* [23] */ \
 -0.020424647256731986999511718750000000000000000000000000000000, /* [24] */ \
 -0.009355833753943443298339843750000000000000000000000000000000, /* [25] */ \
 -0.000000000000000002836163885632763486906778721552413458084629, /* [26] */ \
  0.004835680592805147171020507812500000000000000000000000000000, /* [27] */ \
  0.005414571147412061691284179687500000000000000000000000000000, /* [28] */ \
  0.003666520351544022560119628906250000000000000000000000000000, /* [29] */ \
  0.001536353491246700286865234375000000000000000000000000000000, /* [30] */ \
  0.000000000000000000692266834260169446329125780836832859677088, /* [31] */ \
 -0.000935046351514756679534912109375000000000000000000000000000  /* [32] */ \
}

/* fdes -c 0.15 -kn 33 */

#define IPOL_FIR03 { \
  0.000932948023546487092971801757812500000000000000000000000000, /* [0] */ \
  0.001880096038803458213806152343750000000000000000000000000000, /* [1] */ \
  0.001532905735075473785400390625000000000000000000000000000000, /* [2] */ \
 -0.001188651192933320999145507812500000000000000000000000000000, /* [3] */ \
 -0.005402419716119766235351562500000000000000000000000000000000, /* [4] */ \
 -0.006640806794166564941406250000000000000000000000000000000000, /* [5] */ \
  0.000000000000000004244698820011787892322180359983008202107158, /* [6] */ \
  0.012848302721977233886718750000000000000000000000000000000000, /* [7] */ \
  0.020378811284899711608886718750000000000000000000000000000000, /* [8] */ \
  0.008825014345347881317138671875000000000000000000000000000000, /* [9] */ \
 -0.022267427295446395874023437500000000000000000000000000000000, /* [10] */ \
 -0.050509486347436904907226562500000000000000000000000000000000, /* [11] */ \
 -0.040362555533647537231445312500000000000000000000000000000000, /* [12] */ \
  0.030163722112774848937988281250000000000000000000000000000000, /* [13] */ \
  0.145668432116508483886718750000000000000000000000000000000000, /* [14] */ \
  0.254548579454421997070312500000000000000000000000000000000000, /* [15] */ \
  0.299185037612915039062500000000000000000000000000000000000000, /* [16] */ \
  0.254548579454421997070312500000000000000000000000000000000000, /* [17] */ \
  0.145668432116508483886718750000000000000000000000000000000000, /* [18] */ \
  0.030163722112774848937988281250000000000000000000000000000000, /* [19] */ \
 -0.040362555533647537231445312500000000000000000000000000000000, /* [20] */ \
 -0.050509486347436904907226562500000000000000000000000000000000, /* [21] */ \
 -0.022267427295446395874023437500000000000000000000000000000000, /* [22] */ \
  0.008825014345347881317138671875000000000000000000000000000000, /* [23] */ \
  0.020378811284899711608886718750000000000000000000000000000000, /* [24] */ \
  0.012848302721977233886718750000000000000000000000000000000000, /* [25] */ \
  0.000000000000000004244698820011787892322180359983008202107158, /* [26] */ \
 -0.006640806794166564941406250000000000000000000000000000000000, /* [27] */ \
 -0.005402419716119766235351562500000000000000000000000000000000, /* [28] */ \
 -0.001188651192933320999145507812500000000000000000000000000000, /* [29] */ \
  0.001532905735075473785400390625000000000000000000000000000000, /* [30] */ \
  0.001880096038803458213806152343750000000000000000000000000000, /* [31] */ \
  0.000932948023546487092971801757812500000000000000000000000000  /* [32] */ \
}

/* Static initializer for the interpolation filter, picked from above. */

#define IPOL_FIR IPOL_FIR00

/*
 * When the symbol IPOC_FC is defined, it holds the digital cutoff frequency
 * of the interpolation filter. The filter coefficients will be computed by
 * the overmaker program.
 *
 * The symbol IPOL_WDW refers to the window function used to smooth the
 * ends of the impulse response. See filterTools.h for the available options.
 */

#define IPOL_FC 0.25

#ifdef IPOL_FC
#define IPOL_WDW 0
#endif /* IPOL_FC */

/* XOVER_RATE: Oversampling rate */

#define XOVER_RATE 4

/* XZB_SIZE: Input history buffer (interpolation filter) */

#define XZB_SIZE 64

/* YZB_SIZE: Output history buffer (decimation filter) */

#define YZB_SIZE 128

/* AAL_LEN: The nof points in the decimation filter */

#define AAL_LEN 33

/* Static initialization of decimation filter, selected from above.
 * This is not used when AAL_FC is defined.
 */

#define AAL_FIR IPOL_FIR03

/*
 * When the symbol AAL_FC is defined, it holds the digital cutoff frequency
 * of the decimation filter. The filter coefficients will then be computed
 * by the overmaker program.
 *
 * The symbol AAL_WDW refers to the window function used to smooth the
 * ends of the impulse response. See filterTools.h for the available options.
 */

#define AAL_FC IPOL_FC

#ifdef AAL_FC
#define AAL_WDW 0
#endif /* AAL_FC */

/* Mix clean sound with overdriven */
/* #define CLEAN_MIX */

#define TR_BIASED

#ifdef TR_BIASED
#define SAG_EMULATION

#define BIAS      0.5347
#define BIAS_LO   0.0
#define BIAS_HI   0.7

#define ADWS_PRE_DIFF
#ifdef ADWS_PRE_DIFF
#define ADWS_FB        0.5821
#define ADWS_FB_MAX    0.999
#endif /* ADWS_PRE_DIFF */

#ifdef SAG_EMULATION

#define SAG_FB     0.991

#define SAG_ZGB    0.0094
#define SAG_ZGB_LO 0.0
#define SAG_ZGB_HI 0.05
#endif /* SAG_EMULATION */

#define ADWS_NO_LINEAR		/* Use curve with no linear segment */
#ifdef ADWS_NO_LINEAR
#define ADWS_V_LO  0.0
#define ADWS_V_HI  1.0
#endif /* ADWS_NO_LINEAR */

#define ADWS_POST_DIFF
#ifdef ADWS_POST_DIFF
#define ADWS_FB2     0.999
#define ADWS_FB2_MAX 0.999
#endif /* ADWS_POST_DIFF */

#define ADWS_GFB		/* Global feedback */
#ifdef ADWS_GFB
#define ADWS_GFB_MAX -0.999
#endif /* ADWS_GFB */

#define ADWS_FAT_CTRL

#ifndef HAS_CALLBACKS
#define HAS_CALLBACKS
#endif /* HAS_CALLBACKS */

#endif /* TR_BIASED */

/* ================================================================ */

/* Prefilter type (undefine for no filter) */
/* #define PRE_FILTER_TYPE EQC_PEQ */
#define PRE_FILTER_HERTZ     800.0 /* Initial cutoff */
#define PRE_FILTER_HERTZ_LO   32.0 /* Minimum cutoff */
#define PRE_FILTER_HERTZ_HI 8000.0 /* Maximum cutoff */
#define PRE_FILTER_Q    1.0
#define PRE_FILTER_Q_LO 0.01
#define PRE_FILTER_Q_HI 6.0
#define PRE_FILTER_G    0.0
#define PRE_FILTER_G_LO -12.0
#define PRE_FILTER_G_HI  12.0

/* Postfilter type (undefine for no filter) */
/* #define POST_FILTER_TYPE EQC_PEQ */
/* #define POST_FILTER_TYPE EQC_BPF1 */
#define POST_FILTER_HERTZ      800.0
#define POST_FILTER_HERTZ_LO    32.0
#define POST_FILTER_HERTZ_HI 10000.0
#define POST_FILTER_Q      1.0
#define POST_FILTER_Q_LO   0.01
#define POST_FILTER_Q_HI   6.0
#define POST_FILTER_G      0.0
#define POST_FILTER_G_LO -12.0
#define POST_FILTER_G_HI  12.0

/* If defined, gain is applied to the input signal */
#define INPUT_GAIN      3.5675
#define INPUT_GAIN_LO   0.001
#define INPUT_GAIN_HI  10.0

/* If defined, gain is applied to output signal */
#define OUTPUT_GAIN     0.8795
#define OUTPUT_GAIN_LO  0.1
#define OUTPUT_GAIN_HI 10.0

/* #define PRE_DC_OFFSET */
/* #define BASS_SIDECHAIN */
/* #define INPUT_COMPRESS */
#ifdef INPUT_COMPRESS

#define IPC_THRESHOLD    1.0
#define IPC_THR_LO       0.001	/* Must not be zero */
#define IPC_THR_HI       2.0

#define IPC_GAIN_REDUCE  0.98
#define IPC_ATK_LO       0.97
#define IPC_ATK_HI       1.00

#define IPC_GAIN_RECOVER 1.002
#define IPC_RLS_LO       1.00
#define IPC_RLS_HI       1.1

#define IPC_GAIN_IDLE    1.0
#endif /* INPUT_COMPRESS */