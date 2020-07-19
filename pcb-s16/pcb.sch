EESchema Schematic File Version 4
LIBS:pcb-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L power:GND #PWR0102
U 1 1 5F1305F4
P 6350 5150
F 0 "#PWR0102" H 6350 4900 50  0001 C CNN
F 1 "GND" V 6355 5022 50  0000 R CNN
F 2 "" H 6350 5150 50  0001 C CNN
F 3 "" H 6350 5150 50  0001 C CNN
	1    6350 5150
	1    0    0    -1  
$EndComp
$Comp
L Padauk:PFS154-S16 U1
U 1 1 5F10DBD3
P 4750 2750
F 0 "U1" H 4750 2250 50  0000 C CNN
F 1 "PFS154-S16" H 4750 3250 50  0000 C CNN
F 2 "Package_SO:SOIC-16_3.9x9.9mm_P1.27mm" H 4750 2750 50  0001 C CNN
F 3 "" H 4750 2750 50  0001 C CNN
	1    4750 2750
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC595 U2
U 1 1 5F114471
P 6350 4450
F 0 "U2" H 6150 3750 50  0000 C CNN
F 1 "74HC595" H 6250 4100 50  0000 C CNN
F 2 "Package_SO:SOIC-16_3.9x9.9mm_P1.27mm" H 6350 4450 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 6350 4450 50  0001 C CNN
	1    6350 4450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5F11C07F
P 5150 2800
F 0 "#PWR0101" H 5150 2550 50  0001 C CNN
F 1 "GND" V 5155 2672 50  0000 R CNN
F 2 "" H 5150 2800 50  0001 C CNN
F 3 "" H 5150 2800 50  0001 C CNN
	1    5150 2800
	0    -1   -1   0   
$EndComp
$Comp
L power:VDD #PWR0103
U 1 1 5F11C66A
P 4350 2800
F 0 "#PWR0103" H 4350 2650 50  0001 C CNN
F 1 "VDD" V 4367 2928 50  0000 L CNN
F 2 "" H 4350 2800 50  0001 C CNN
F 3 "" H 4350 2800 50  0001 C CNN
	1    4350 2800
	0    -1   -1   0   
$EndComp
$Comp
L power:VDD #PWR0104
U 1 1 5F11CB2C
P 6350 3850
F 0 "#PWR0104" H 6350 3700 50  0001 C CNN
F 1 "VDD" V 6367 3978 50  0000 L CNN
F 2 "" H 6350 3850 50  0001 C CNN
F 3 "" H 6350 3850 50  0001 C CNN
	1    6350 3850
	1    0    0    -1  
$EndComp
$Comp
L SLR0394DRC5BD:SLR0394DRC5BD U3
U 1 1 5F1267D4
P 7600 2700
F 0 "U3" H 6650 3250 50  0000 L CNN
F 1 "SLR0394DRC5BD" H 7950 3250 50  0000 L CNN
F 2 "modules:SLR039DRC5BD" H 7600 2100 50  0001 C CNN
F 3 "" H 7170 2730 50  0001 C CNN
	1    7600 2700
	1    0    0    -1  
$EndComp
Text Label 5150 2700 0    50   ~ 0
PB0
Text Label 5150 2600 0    50   ~ 0
PB1
Text Label 5150 2500 0    50   ~ 0
PB2
Text Label 5150 2400 0    50   ~ 0
PB3
Text Label 5850 2400 2    50   ~ 0
PB0
Text Label 5850 2500 2    50   ~ 0
PB1
Text Label 5850 2600 2    50   ~ 0
PB2
Text Label 5850 2700 2    50   ~ 0
PB3
Text Label 5750 3250 2    50   ~ 0
PB4
Text Label 5750 3350 2    50   ~ 0
PB5
Text Label 6150 3050 0    50   ~ 0
PB7
Text Label 4350 2400 2    50   ~ 0
PB4
Text Label 4350 2500 2    50   ~ 0
PB5
Text Label 4350 2600 2    50   ~ 0
PB6
Text Label 4350 2700 2    50   ~ 0
PB7
$Comp
L Device:Crystal_Small Y1
U 1 1 5F12EB82
P 3850 2950
F 0 "Y1" V 3850 3000 50  0000 R CNN
F 1 "32.768kHz" V 3850 2850 50  0000 R CNN
F 2 "Crystal:Crystal_DS26_D2.0mm_L6.0mm_Horizontal" H 3850 2950 50  0001 C CNN
F 3 "~" H 3850 2950 50  0001 C CNN
	1    3850 2950
	0    -1   -1   0   
$EndComp
$Comp
L Switch:SW_Push SW1
U 1 1 5F13065F
P 4400 4350
F 0 "SW1" H 4400 4250 50  0000 C CNN
F 1 "BTN" H 4400 4550 50  0000 C CNN
F 2 "modules:SMD-SW_Push_3.5x4.55_Side" H 4400 4550 50  0001 C CNN
F 3 "~" H 4400 4550 50  0001 C CNN
	1    4400 4350
	0    -1   -1   0   
$EndComp
Text Label 4350 3100 2    50   ~ 0
PA5
Text Label 4400 4100 1    50   ~ 0
PA5
Wire Wire Line
	3950 3050 4150 3050
Wire Wire Line
	4150 3050 4150 3000
Wire Wire Line
	4150 3000 4350 3000
Wire Wire Line
	4150 2900 4350 2900
Wire Wire Line
	3950 2850 4150 2850
Wire Wire Line
	4150 2850 4150 2900
$Comp
L Device:C C3
U 1 1 5F132D59
P 3650 2800
F 0 "C3" V 3800 2800 50  0000 C CNN
F 1 "20pF" V 3700 2950 50  0000 C CNN
F 2 "modules:C_0805" H 3688 2650 50  0001 C CNN
F 3 "~" H 3650 2800 50  0001 C CNN
	1    3650 2800
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C4
U 1 1 5F134555
P 3650 3100
F 0 "C4" V 3800 3100 50  0000 C CNN
F 1 "20pF" V 3700 3250 50  0000 C CNN
F 2 "modules:C_0805" H 3688 2950 50  0001 C CNN
F 3 "~" H 3650 3100 50  0001 C CNN
	1    3650 3100
	0    -1   1    0   
$EndComp
Wire Wire Line
	3800 2800 3850 2800
Wire Wire Line
	3950 2800 3950 2850
Wire Wire Line
	3950 3050 3950 3100
Wire Wire Line
	3950 3100 3850 3100
Wire Wire Line
	3500 2800 3450 2800
$Comp
L power:GND #PWR0105
U 1 1 5F13644B
P 3400 2950
F 0 "#PWR0105" H 3400 2700 50  0001 C CNN
F 1 "GND" V 3405 2822 50  0000 R CNN
F 2 "" H 3400 2950 50  0001 C CNN
F 3 "" H 3400 2950 50  0001 C CNN
	1    3400 2950
	0    1    1    0   
$EndComp
Wire Wire Line
	3850 2850 3850 2800
Connection ~ 3850 2800
Wire Wire Line
	3850 2800 3950 2800
Wire Wire Line
	3850 3050 3850 3100
Connection ~ 3850 3100
Wire Wire Line
	3850 3100 3800 3100
Wire Wire Line
	3450 2800 3450 2950
Wire Wire Line
	3450 3100 3500 3100
Wire Wire Line
	3400 2950 3450 2950
Connection ~ 3450 2950
Wire Wire Line
	3450 2950 3450 3100
$Comp
L Device:R_Pack04 RN1
U 1 1 5F13AD07
P 6050 2600
F 0 "RN1" V 5750 2600 50  0000 C CNN
F 1 "R_Pack04" V 5724 2600 50  0001 C CNN
F 2 "Resistor_SMD:R_Array_Convex_4x0603" V 6325 2600 50  0001 C CNN
F 3 "~" H 6050 2600 50  0001 C CNN
	1    6050 2600
	0    -1   1    0   
$EndComp
$Comp
L Device:R_Pack04 RN2
U 1 1 5F13C2E7
P 5950 3250
F 0 "RN2" V 6150 3250 50  0000 C CNN
F 1 "R_Pack04" V 5624 3250 50  0001 C CNN
F 2 "Resistor_SMD:R_Array_Convex_4x0603" V 6225 3250 50  0001 C CNN
F 3 "~" H 5950 3250 50  0001 C CNN
	1    5950 3250
	0    -1   1    0   
$EndComp
Text Label 7050 3300 3    50   ~ 0
DIG1
Text Label 7500 3300 3    50   ~ 0
DIG2
Text Label 7900 3300 3    50   ~ 0
DIG3
Text Label 8300 3300 3    50   ~ 0
DIG4
Text Label 6750 4450 0    50   ~ 0
DIG1
Text Label 6750 4550 0    50   ~ 0
DIG2
Text Label 6750 4650 0    50   ~ 0
DIG3
Text Label 6750 4750 0    50   ~ 0
DIG4
NoConn ~ 6750 4950
Text Label 5150 2900 0    50   ~ 0
PA0
Text Label 5950 4250 2    50   ~ 0
PA0
Text Label 5150 3000 0    50   ~ 0
PA4
Text Label 5950 4550 2    50   ~ 0
PA4
Text Label 5950 4350 2    50   ~ 0
VDD
Text Label 5950 4650 2    50   ~ 0
GND
Text Label 5150 3100 0    50   ~ 0
PA3
Text Label 5950 4050 2    50   ~ 0
PA3
$Comp
L Device:C C1
U 1 1 5F142698
P 4850 4350
F 0 "C1" V 4700 4350 50  0000 C CNN
F 1 "100nF" V 5000 4350 50  0000 C CNN
F 2 "modules:C_0805" H 4888 4200 50  0001 C CNN
F 3 "~" H 4850 4350 50  0001 C CNN
	1    4850 4350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0106
U 1 1 5F142D56
P 5100 4600
F 0 "#PWR0106" H 5100 4350 50  0001 C CNN
F 1 "GND" V 5105 4472 50  0000 R CNN
F 2 "" H 5100 4600 50  0001 C CNN
F 3 "" H 5100 4600 50  0001 C CNN
	1    5100 4600
	1    0    0    -1  
$EndComp
$Comp
L power:VDD #PWR0107
U 1 1 5F1431AE
P 5100 4100
F 0 "#PWR0107" H 5100 3950 50  0001 C CNN
F 1 "VDD" V 5117 4228 50  0000 L CNN
F 2 "" H 5100 4100 50  0001 C CNN
F 3 "" H 5100 4100 50  0001 C CNN
	1    5100 4100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0108
U 1 1 5F14775A
P 4400 4600
F 0 "#PWR0108" H 4400 4350 50  0001 C CNN
F 1 "GND" V 4405 4472 50  0000 R CNN
F 2 "" H 4400 4600 50  0001 C CNN
F 3 "" H 4400 4600 50  0001 C CNN
	1    4400 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 4500 4850 4550
Wire Wire Line
	4400 4100 4400 4150
$Comp
L Device:C C2
U 1 1 5F151096
P 5350 4350
F 0 "C2" V 5200 4350 50  0000 C CNN
F 1 "10uF" V 5500 4350 50  0000 C CNN
F 2 "modules:C_0805" H 5388 4200 50  0001 C CNN
F 3 "~" H 5350 4350 50  0001 C CNN
	1    5350 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 4550 5100 4550
Wire Wire Line
	5350 4550 5350 4500
Connection ~ 5100 4550
Wire Wire Line
	5100 4550 5350 4550
Wire Wire Line
	5100 4550 5100 4600
Wire Wire Line
	4400 4550 4400 4600
Wire Wire Line
	4850 4200 4850 4150
Wire Wire Line
	4850 4150 5100 4150
Wire Wire Line
	5350 4150 5350 4200
Connection ~ 5100 4150
Wire Wire Line
	5100 4150 5350 4150
Wire Wire Line
	5100 4100 5100 4150
$Comp
L Connector:USB_B_Micro J1
U 1 1 5F1603EF
P 3400 4400
F 0 "J1" H 3457 4867 50  0000 C CNN
F 1 "USB_B_Micro" H 3457 4776 50  0000 C CNN
F 2 "modules:USB_Micro_B_Male" H 3550 4350 50  0001 C CNN
F 3 "~" H 3550 4350 50  0001 C CNN
	1    3400 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 4800 3400 4800
Wire Wire Line
	3700 4600 3700 4800
Wire Wire Line
	3700 4800 3400 4800
Connection ~ 3400 4800
$Comp
L power:GND #PWR0109
U 1 1 5F162B7F
P 3400 4800
F 0 "#PWR0109" H 3400 4550 50  0001 C CNN
F 1 "GND" V 3405 4672 50  0000 R CNN
F 2 "" H 3400 4800 50  0001 C CNN
F 3 "" H 3400 4800 50  0001 C CNN
	1    3400 4800
	1    0    0    -1  
$EndComp
NoConn ~ 3700 4400
NoConn ~ 3700 4500
$Comp
L power:VDD #PWR0110
U 1 1 5F163A89
P 3700 4200
F 0 "#PWR0110" H 3700 4050 50  0001 C CNN
F 1 "VDD" V 3717 4328 50  0000 L CNN
F 2 "" H 3700 4200 50  0001 C CNN
F 3 "" H 3700 4200 50  0001 C CNN
	1    3700 4200
	0    1    1    0   
$EndComp
Wire Wire Line
	6250 2400 6500 2400
Wire Wire Line
	6500 2500 6250 2500
Wire Wire Line
	6250 2600 6500 2600
Wire Wire Line
	6500 2700 6250 2700
Text Label 5750 3150 2    50   ~ 0
R7
Text Label 6150 3250 0    50   ~ 0
R3
Text Label 6150 3350 0    50   ~ 0
R4
Text Label 6500 2800 2    50   ~ 0
R3
Text Label 6500 2900 2    50   ~ 0
R4
Text Label 6500 3000 2    50   ~ 0
R7
Text Label 6500 3100 2    50   ~ 0
R8
Text Label 5750 3050 2    50   ~ 0
R8
Text Label 6150 3150 0    50   ~ 0
PB6
Wire Wire Line
	7050 3300 7050 4050
Wire Wire Line
	7050 4050 6750 4050
Wire Wire Line
	6750 4150 7500 4150
Wire Wire Line
	7500 4150 7500 3300
Wire Wire Line
	6750 4250 7900 4250
Wire Wire Line
	7900 4250 7900 3300
Wire Wire Line
	6750 4350 8300 4350
Wire Wire Line
	8300 4350 8300 3300
$EndSCHEMATC