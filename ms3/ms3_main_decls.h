/* $Id: ms3_main_decls.h,v 1.117.4.1 2015/01/23 15:44:31 jsmcortina Exp $
 * Copyright 2007, 2008, 2009, 2010, 2011, 2012 James Murray and Kenneth Culver
 *
 * This file is a part of Megasquirt-3.
 *
 *
    Origin: Al Grippo
    Major: James Murray / Kenneth Culver
    Majority: Al Grippo / James Murray / Kenneth Culver
 *
 * You should have received a copy of the code LICENSE along with this source, please
 * ask on the www.msextra.com forum if you did not.
 *
*/

#ifndef _MS3_MAIN_DECLS
#define _MS3_MAIN_DEClS
// this gives warnings in gcc which is annoying, but using it does make some things easier
// now used by CAN and SCI routines that reference tables
// has a slightly different usage to MS2 2.8+
// It is important to note that although the tables are defined here, there are hardcoded refs to
// the tables within the code. Specifically in isr_sci.c and ms2_extra_can_isr.c

//Caution! cp_flash_ram uses hardcoded EPAGE and RPAGE for a few special pages
// {*addrRam, addrFlash, n_bytes, rpg, adhi }
const tableDescriptor tables[NO_TBLES] TEXT_ATTR = {
    {(unsigned int *) &ram_window, 0x4000, sizeof(cltfactor_table), 0xf1, 0x10},
    {(unsigned int *) &ram_window, 0x4800, sizeof(matfactor_table), 0xf1, 0x10},
    {(unsigned int *) &ram_window, 0x5000, sizeof(egofactor_table), 0xf1, 0x10},
    {(unsigned int *) &ram_window, 0x5400, sizeof(maffactor_table), 0xf1, 0x10},
    {(unsigned int *) &ram_window.pg4, 0x3000, 1024, 0xfe, 0x10},
    {(unsigned int *) &ram_window.pg5, 0x3400, 1024, 0xfe, 0x14},
    {(unsigned int *) &canbuf, NULL, sizeof(canbuf), 0, 0},
    {(unsigned int *) &outpc, NULL, sizeof(outpc), 0, 0},
    {(unsigned int *) &ram_window.pg8, 0x0000, 1024, 0xfc, 0x10},
    {(unsigned int *) &ram_window.pg9, 0x0400, 1024, 0xfc, 0x14},
    {(unsigned int *) &ram_window.pg10, 0x0800, 1024, 0xfc, 0x18},
    {(unsigned int *) &ram_window.pg11, 0x0c00, 1024, 0xfc, 0x1c},
    {(unsigned int *) &ram_window.pg12, 0x1000, 1024, 0xfa, 0x10},
    {(unsigned int *) &ram_window.pg13, 0x1400, 1024, 0xfa, 0x14},
    {(unsigned int *) &Signature, NULL, 60, 0, 0},
    {(unsigned int *) &RevNum, NULL, 20, 0, 0},
    {(unsigned int *) &buf2, NULL, sizeof(buf2), 0, 0},        // Table 0x10
    {(unsigned int *) SDSECT1, NULL, 1024, 0xfe, 0x10},      //SD sector 0x11, RPAGE irrelevant
    {(unsigned int *) &ram_window.pg18, 0x1800, 1024, 0xfa, 0x18},
    {(unsigned int *) &ram_window.pg19, 0x1c00, 1024, 0xfa, 0x1c},
    {(unsigned int *) 0x1000, NULL, 2056, 0xfc, 0x10},  //SD file readback 0x14
    {(unsigned int *) &ram_window.pg21, 0x2000, 1024, 0xfb, 0x10},
    {(unsigned int *) &ram_window.pg22, 0x2400, 1024, 0xfb, 0x14},
    {(unsigned int *) &ram_window.pg23, 0x2800, 1024, 0xfb, 0x18},
    {(unsigned int *) &ram_window.pg24, 0x2c00, 1024, 0xfb, 0x1c},
    {(unsigned int *) &ram_window.pg25, 0x3800, 1024, 0xf0, 0x14},
    {(unsigned int *) &ram_window.trimpage, 0x6400, 1024, 0xf0, 0x18}, // special flash handling 0x1a
    {(unsigned int *) &ram_window.pg27, 0x3c00, 1024, 0xfd, 0x14},
    {(unsigned int *) &ram_window.pg28, 0x6800, 1024, 0xfd, 0x18},
    {(unsigned int *) &ram_window.pg29, 0x6c00, 1024, 0xfd, 0x1c},
    {NULL, NULL, 0, 0, 0},
    {NULL, NULL, 0, 0, 0}
};

/* whether this table should be automatically copied from FLASH to RAM or not */
const unsigned char cpf2r[NO_TBLES] TEXT_ATTR = {
//  0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31
//  0 1 2 3 4 5 6 7 8 9 a  b  c  d  e  f  10 11 12 13 14 15 16 17 18 19 1a 1b 1c 1d 1e 1f
    0,0,0,0,1,1,0,0,1,1,1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0
    };

// IAC stepper motor sequence
const unsigned char IACCoilA[8] TEXT_ATTR = { 0, 0, 1, 1, 0, 0, 1, 1 };
const unsigned char IACCoilB[8] TEXT_ATTR = { 1, 0, 0, 1, 1, 0, 0, 1 };

// Spare port sequence
//        enabledPorts = psEnabled, "PM3 - Injection LED D14", "PM4 - Accel LED D16", "PM5 - Warmup LED D15", "PJ0 - IAC2", "PJ1 - IAC1", "PJ7 - JS11", "PP2 - Idle", "PP3 - Boost", "PP4 - Nitrous 1", "PP5 - Nitrous 2", "PP6 - VVT", "PP7 - Fidle", "PT1 - inj1", "PT3 - inj2", "PT5 - JS10", "PK0 - Tacho", "PA0 - Inj A", "PA1 - Inj B", "PA2 - Inj C", "PA3 - Inj D", "PA4 - Inj E", "PA5 - Inj F", "PA6 - Inj G", "PA7 - Inj H", "PB0 - Spk A", "PB1 - Spk B", "PB2 - Spk C", "PB3 - Spk D", "PB4 - Spk E", "PB5 - Spk F", "PB6 - Spk G", "PB7 - Spk H"
const unsigned char spr_port_hw[3][NPORT] TEXT_ATTR =      // mapping of spare software ports to physical ports and bits
{ { 0, 0, 0,
    1, 1, 1,
    2, 2, 2, 2, 2, 2,
    3, 3, 3,
    6,
    4, 4, 4, 4, 4, 4, 4, 4,
    5, 5, 5, 5, 5, 5, 5, 5,
    7, 7, 7, 7, 7, 7, 7, 7,
    8, 8, 8, 8, 8, 8, 8, 8,
    9, 9, 9},     // ports 0 = PM, 1 = PJ, 2 = PP, 3 = PT, 4 = PA, 5 = PB, 6 = PK, 7 = CANout1-8, 8 = CANout9-16, 9 = loop
{   3, 4, 5,
    0, 1, 7,
    2, 3, 4, 5, 6, 7,
    1, 3, 5,
    0,
    0, 1, 2, 3, 4, 5, 6, 7,
    0, 1, 2, 3, 4, 5, 6, 7,
    0, 1, 2, 3, 4, 5, 6, 7,
    0, 1, 2, 3, 4, 5, 6, 7,
    0, 1, 2 },       // pin no. 0-7
{   0x08, 0x10, 0x20,
    0x01, 0x02, 0x80,
    0x04, 0x08, 0x10, 0x20, 0x40, 0x80,
    0x02, 0x08, 0x20,
    0x01,
    0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80,
    0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80,
    0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80,
    0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80,
    0x01, 0x02, 0x04}
};                              // pin mask 0x01-0x80

volatile unsigned char *const spr_port_addr[NPORT] TEXT_ATTR =     // mapping of spare software ports to physical ports
{   &PTM, &PTM, &PTM,
    &PTJ, &PTJ, &PTJ,
    &PTP, &PTP, &PTP, &PTP, &PTP, &PTP,
    &PTT, &PTT, &PTT,
    &PORTK,
    &PORTA, &PORTA, &PORTA, &PORTA, &PORTA, &PORTA, &PORTA, &PORTA,
    &PORTB, &PORTB, &PORTB, &PORTB, &PORTB, &PORTB, &PORTB, &PORTB,
    &outpc.canout1_8, &outpc.canout1_8, &outpc.canout1_8, &outpc.canout1_8, &outpc.canout1_8, &outpc.canout1_8, &outpc.canout1_8, &outpc.canout1_8,
    &outpc.canout9_16, &outpc.canout9_16, &outpc.canout9_16, &outpc.canout9_16, &outpc.canout9_16, &outpc.canout9_16, &outpc.canout9_16, &outpc.canout9_16,
    &outpc.loop, &outpc.loop, &outpc.loop
};

const unsigned char default_port_inits[40] TEXT_ATTR =
    { 0xff, 0xff, 0xff, 0x10, 0x08, 0x43, 0x01, 0x00, 0x00, 0x3c, 0xff,
    0x00, 0x7a, 0x80, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

const unsigned int setcoil_array_norm[16][16] TEXT_ATTR = // mapping of [num spk][coil num] / spkbit - normal (not all combinations make sense)
    {{ 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001 }, //  num_spk = 1
     { 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x0001, 0x0002, 0x0001, 0x0002, 0x0001, 0x0002, 0x0001, 0x0002 }, //  2
     { 0x01, 0x02, 0x04, 0x01, 0x02, 0x04, 0x01, 0x02, 0x0004, 0x0001, 0x0002, 0x0004, 0x0001, 0x0002, 0x0004, 0x0000 }, //  3
     { 0x01, 0x02, 0x04, 0x08, 0x01, 0x02, 0x04, 0x08, 0x0001, 0x0002, 0x0004, 0x0008, 0x0001, 0x0002, 0x0004, 0x0008 }, //  4
     { 0x01, 0x02, 0x04, 0x08, 0x10, 0x01, 0x02, 0x04, 0x0008, 0x0010, 0x0001, 0x0002, 0x0004, 0x0008, 0x0010, 0x0000 }, //  5
     { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x01, 0x02, 0x0004, 0x0008, 0x0010, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000 }, //  6
     { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x01, 0x0002, 0x0004, 0x0008, 0x0010, 0x0020, 0x0040, 0x0000, 0x0000 }, //  7
     { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x0001, 0x0002, 0x0004, 0x0008, 0x0010, 0x0020, 0x0040, 0x0080 }, //  8
     { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x0100, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 }, //  9
     { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x0100, 0x0200, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 }, // 10
     { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x0100, 0x0200, 0x0400, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 }, // 11
     { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x0100, 0x0200, 0x0400, 0x0800, 0x0000, 0x0000, 0x0000, 0x0000 }, // 12
     { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x0100, 0x0200, 0x0400, 0x0800, 0x1000, 0x0000, 0x0000, 0x0000 }, // 13
     { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x0100, 0x0200, 0x0400, 0x0800, 0x1000, 0x2000, 0x0000, 0x0000 }, // 14
     { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x0100, 0x0200, 0x0400, 0x0800, 0x1000, 0x2000, 0x4000, 0x0000 }, // 15
     { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x0100, 0x0200, 0x0400, 0x0800, 0x1000, 0x2000, 0x4000, 0x8000 }};// 16

const unsigned int setcoil_array_fcfd[4] TEXT_ATTR = {0x1, 0x1, 0x4, 0x8};

const unsigned int twopow[16] = {1,2,4,8,0x10,0x20,0x40,0x80,0x100,0x200,0x400,0x800,0x1000,0x2000,0x4000,0x8000};
const unsigned char slow_boost_intervals[8] = {91,13,26,39,52,65,77,91};
const unsigned char fast_boost_intervals[16] = {10,10,10,10,10,10,10,
	                                     10,11,14,20,21,34,50,67,84};


const unsigned char pwmopts[16] = {3,4,5,6,8,10,15,20,31,41,61,64,101,150,200,255};
const unsigned int pwmfreq[16] = {111,111,2500,2250,2000,1750,1500,1250,1000,780,390,260,195,156,130,111};
const unsigned int can_outpc_int[8] = {7812,7812,3906,1562,781,391,156,78};

/* moved to xgate.s
const unsigned char random_no[256] TEXTf9_ATTR =
    {0xb2, 0x8a, 0x29, 0x54, 0x48, 0x9a, 0x0a, 0xbc, 0xd5, 0x0e, 0x18, 0xa8, 0x44, 0xac, 0x5b, 0xf3, 
    0x8e, 0x4c, 0xd7, 0x2d, 0x9b, 0x09, 0x42, 0xe5, 0x06, 0xc4, 0x33, 0xaf, 0xcd, 0xa3, 0x84, 0x7f, 
    0x2d, 0xad, 0xd4, 0x76, 0x47, 0xde, 0x32, 0x1c, 0xec, 0x4a, 0xc4, 0x30, 0xf6, 0x20, 0x23, 0x85, 
    0x6c, 0xfb, 0xb2, 0x07, 0x04, 0xf4, 0xec, 0x0b, 0xb9, 0x20, 0xba, 0x86, 0xc3, 0x3e, 0x05, 0xf1, 
    0xec, 0xd9, 0x67, 0x33, 0xb7, 0x99, 0x50, 0xa3, 0xe3, 0x14, 0xd3, 0xd9, 0x34, 0xf7, 0x5e, 0xa0, 
    0xf2, 0x10, 0xa8, 0xf6, 0x05, 0x94, 0x01, 0xbe, 0xb4, 0xbc, 0x44, 0x78, 0xfa, 0x49, 0x69, 0xe6, 
    0x23, 0xd0, 0x1a, 0xda, 0x69, 0x6a, 0x7e, 0x4c, 0x7e, 0x51, 0x25, 0xb3, 0x48, 0x84, 0x53, 0x3a, 
    0x94, 0xfb, 0x31, 0x99, 0x90, 0x32, 0x57, 0x44, 0xee, 0x9b, 0xbc, 0xe9, 0xe5, 0x25, 0xcf, 0x08, 
    0xf5, 0xe9, 0xe2, 0x5e, 0x53, 0x60, 0xaa, 0xd2, 0xb2, 0xd0, 0x85, 0xfa, 0x54, 0xd8, 0x35, 0xe8, 
    0xd4, 0x66, 0x82, 0x64, 0x98, 0xd9, 0xa8, 0x87, 0x75, 0x65, 0x70, 0x5a, 0x8a, 0x3f, 0x62, 0x80, 
    0x29, 0x44, 0xde, 0x7c, 0xa5, 0x89, 0x4e, 0x57, 0x59, 0xd3, 0x51, 0xad, 0xac, 0x86, 0x95, 0x80, 
    0xec, 0x17, 0xe4, 0x85, 0xf1, 0x8c, 0x0c, 0x66, 0xf1, 0x7c, 0xc0, 0x7c, 0xbb, 0x22, 0xfc, 0xe4, 
    0x66, 0xda, 0x61, 0x0b, 0x63, 0xaf, 0x62, 0xbc, 0x83, 0xb4, 0x69, 0x2f, 0x3a, 0xff, 0xaf, 0x27, 
    0x16, 0x93, 0xac, 0x07, 0x1f, 0xb8, 0x6d, 0x11, 0x34, 0x2d, 0x8d, 0xef, 0x4f, 0x89, 0xd4, 0xb6, 
    0x63, 0x35, 0xc1, 0xc7, 0xe4, 0x24, 0x83, 0x67, 0xd8, 0xed, 0x96, 0x12, 0xec, 0x45, 0x39, 0x02, 
    0xd8, 0xe5, 0x0a, 0xf8, 0x9d, 0x77, 0x09, 0xd1, 0xa5, 0x96, 0xc1, 0xf4, 0x1f, 0x95, 0xaa, 0x82};
*/

const unsigned int fuelcut_array[16][16] TEXT_ATTR = // mapping of injs to cut vs. [num inj][cut num]
    {{ 0x01, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 }, //  num_inj = 1
     { 0x01, 0x0002, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 }, //  2
     { 0x01, 0x0002, 0x0004, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 }, //  3
     { 0x01, 0x0004, 0x0002, 0x0008, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 }, //  4
     { 0x01, 0x0004, 0x0002, 0x0008, 0x0010, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 }, //  5
     { 0x01, 0x0008, 0x0002, 0x0010, 0x0004, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 }, //  6
     { 0x01, 0x0010, 0x0002, 0x0020, 0x0004, 0x0040, 0x0008, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 }, //  7
     { 0x01, 0x0010, 0x0004, 0x0040, 0x0002, 0x0020, 0x0008, 0x0080, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 }, //  8
     { 0x01, 0x0020, 0x0004, 0x0080, 0x0002, 0x0040, 0x0008, 0x0100, 0x0010, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 }, //  9
     { 0x01, 0x0020, 0x0008, 0x0100, 0x0002, 0x0040, 0x0010, 0x0200, 0x0004, 0x0080, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 }, // 10
     { 0x01, 0x0040, 0x0008, 0x0200, 0x0002, 0x0080, 0x0020, 0x0800, 0x0004, 0x0100, 0x0010, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 }, // 11
     { 0x01, 0x0040, 0x0008, 0x0200, 0x0002, 0x0080, 0x0020, 0x0800, 0x0004, 0x0100, 0x0010, 0x0400, 0x0000, 0x0000, 0x0000, 0x0000 }, // 12
     { 0x01, 0x0080, 0x0010, 0x0800, 0x0004, 0x0200, 0x0040, 0x0008, 0x0400, 0x0002, 0x0100, 0x0020, 0x1000, 0x0000, 0x0000, 0x0000 }, // 13
     { 0x01, 0x0080, 0x0010, 0x0800, 0x0004, 0x0200, 0x0040, 0x2000, 0x0008, 0x0400, 0x0002, 0x0100, 0x0020, 0x1000, 0x0000, 0x0000 }, // 14
     { 0x01, 0x0100, 0x0010, 0x1000, 0x0004, 0x0400, 0x0040, 0x4000, 0x0020, 0x2000, 0x0080, 0x0008, 0x0800, 0x0002, 0x0200, 0x0000 }, // 15
     { 0x01, 0x0100, 0x0010, 0x1000, 0x0004, 0x0400, 0x0040, 0x4000, 0x0020, 0x2000, 0x0080, 0x8000, 0x0008, 0x0800, 0x0002, 0x0200 }};// 16

#include "ms3_main_vars.h"

#endif