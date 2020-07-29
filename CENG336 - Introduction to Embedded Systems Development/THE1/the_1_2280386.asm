LIST P = 18F8722
#INCLUDE <p18f8722.inc>
    
CONFIG OSC=HSPLL, FCMEN=OFF, IESO=OFF,PWRT=OFF,BOREN=OFF, WDT=OFF, MCLRE=ON, LPT1OSC=OFF, LVP=OFF, XINST=OFF, DEBUG=OFF
    
i1 udata 0x20
i1

j1 udata 0x21
j1

k1 udata 0x22
k1
 
p1 udata 0x23
p1
 
bpart udata 0x24
bpart
 
cpart udata 0x25
cpart

dpart udata 0x26
dpart
 
ORG	0x00
goto	MAIN
     
INITIAL
    ; CONFIGURE DIGITAL I/O
    MOVLW   b'00010000' ; configure RA4	as digital input
    MOVWF   TRISA	
    MOVLW   b'00011000'	; configure RE3, RE4 as digital input
    MOVWF   TRISE
    MOVLW   b'11110000'	; configure RB[0-3], RC[0-3] as digital output
    MOVWF   TRISB   
    MOVWF   TRISC
    MOVLW   b'00000000'	; configure RD[0-7] as digital output	 
    MOVWF   TRISD	
    
    ; TURN ON LIGHTS
    MOVLW   b'00001111'	; turn on leds	RB[0-3] and RC[0-3]
    MOVWF   LATB
    MOVWF   LATC
    MOVLW   b'11111111' ; turn on leds	RD[0-7]
    MOVWF   LATD   
    
    ; DELAY 1sc
    call DELAY
		    
    ; TURN OFF LEDS
    MOVLW   b'00000000'
    MOVWF   LATB
    MOVWF   LATC
    MOVWF   LATD
    return
        
; DELAY
DELAY
    MOVLW   h'F0'
    MOVWF   k1
    kloop:
	MOVLW   h'50'
	MOVWF   j1
	jloop:
	    MOVLW   h'AC'
	    MOVWF   i1
	    iloop:
		decfsz	i1, F
		GOTO	iloop
		decfsz	j1, F
		GOTO	jloop
		decfsz	k1, F
		GOTO	kloop   
    return
    
MAIN
    MOVLW H'0F'
    MOVWF ADCON1
    call INITIAL 

loop:
    clrf    bpart    
    clrf    cpart
    clrf    dpart
    
    CLRF    LATB
    CLRF    LATC
    CLRF    LATD
    
    CLRF    p1
        
    press_RA4_for_starting_program:
	btfss	PORTA,	4   
	goto	press_RA4_for_starting_program
    releaseRA4:
	btfsc	PORTA,	4
	goto	releaseRA4

    INCF p1 
    
    press_RE3_or_RA4_for_PARTB_or_PARTA:
	btfsc	PORTA,	4
	goto	releaseRA4
	btfss	PORTE,	3
	goto	press_RE3_or_RA4_for_PARTB_or_PARTA
    releaseRE3_B_ucun_kecid:
	btfsc	PORTE,	3
	goto	releaseRE3_B_ucun_kecid  
		    
    press_RE4_or_RE3_for_PARTB_or_PARTC:
	btfsc	PORTE,	3
	goto	release_RE3_for_PARTC
	btfss	PORTE,	4
	goto	press_RE4_or_RE3_for_PARTB_or_PARTC
    release_RE4_for_PARTB:
	btfsc	PORTE,	4
	goto	release_RE4_for_PARTB
   	
    INCF    bpart
    
    movf    bpart, W
	xorlw   1
	bz	bcase1
    movf    bpart, W
	xorlw   2
	bz	bcase2
    movf    bpart, W
	xorlw   3
	bz	bcase3
    movf    bpart, W
	xorlw   4
	bz	bcase4
    movf    bpart, W
	xorlw   5
	bz	bcase0

    bcase0:
	MOVLW	d'0'
	MOVWF	bpart
	MOVLW	b'00000000'
	MOVWF	LATB
	goto	press_RE4_or_RE3_for_PARTB_or_PARTC1
    bcase1:
	MOVLW	b'00000001'
	MOVWF	LATB
	goto	press_RE4_or_RE3_for_PARTB_or_PARTC1
    bcase2:
	MOVLW	b'00000011'
	MOVWF	LATB
	goto	press_RE4_or_RE3_for_PARTB_or_PARTC1
    bcase3:
	MOVLW	b'00000111'
	MOVWF	LATB
	goto	press_RE4_or_RE3_for_PARTB_or_PARTC1
    bcase4:
	MOVLW	b'00001111'
	MOVWF	LATB
	goto	press_RE4_or_RE3_for_PARTB_or_PARTC1

    release_RE3_for_PARTC:
	btfsc	PORTE,	3
	goto	release_RE3_for_PARTC
    	
    press_RE4_or_RE3_for_PARTC_or_PARTD:
	btfsc	PORTE,	3
	goto	release_RE3_for_PARTD
	btfss	PORTE,	4
	goto	press_RE4_or_RE3_for_PARTC_or_PARTD
    release_RE4_for_PARTC:
	btfsc	PORTE,	4
	goto	release_RE4_for_PARTC
	
	
    INCF cpart
    movf    cpart, W
	xorlw   1
	bz	ccase1
    movf    cpart, W
	xorlw   2
	bz	ccase2
    movf    cpart, W
	xorlw   3
	bz	ccase3
    movf    cpart, W
	xorlw   4
	bz	ccase4
    movf    cpart, W
	xorlw   5
	bz	ccase0
	
    ccase0:
	MOVLW	d'0'
	MOVWF	cpart
	MOVLW	b'00000000'
	MOVWF	LATC
	goto	press_RE4_or_RE3_for_PARTC_or_PARTD1
    ccase1:
	MOVLW	b'00000001'
	MOVWF	LATC
	goto	press_RE4_or_RE3_for_PARTC_or_PARTD1
    ccase2:
	MOVLW	b'00000011'
	MOVWF	LATC
	goto	press_RE4_or_RE3_for_PARTC_or_PARTD1
    ccase3:
	MOVLW	b'00000111'
	MOVWF	LATC
	goto	press_RE4_or_RE3_for_PARTC_or_PARTD1
    ccase4:
	MOVLW	b'00001111'
	MOVWF	LATC
	goto	press_RE4_or_RE3_for_PARTC_or_PARTD1

    release_RE3_for_PARTD:
	btfsc	PORTE,	3	
	goto	release_RE3_for_PARTD
	
    btfss   p1, 0
    goto    subtraction
    goto    addition
    
addition:
    MOVF    bpart, 0, 1
    ADDWF   cpart,  0,	1
    MOVWF   p1
    
    movf    p1, W
	xorlw   0
	bz	TON0
    movf    p1, W
	xorlw   1
	bz	TON1
    movf    p1, W
	xorlw   2
	bz	TON2
    movf    p1, W
	xorlw   3
	bz	TON3
    movf    p1, W
	xorlw   4
	bz	TON4
    movf    p1, W
	xorlw   5
	bz	TON5
    movf    p1, W
	xorlw   6
	bz	TON6
    movf    p1, W
	xorlw   7
	bz	TON7
    movf    p1, W
	xorlw   8
	bz	TON8
	
    TON0:
	MOVLW	b'00000000'
	MOVWF	LATD
	goto	burda_sizin_reklaminiz_olabiler
    TON1:
	MOVLW	b'00000001'
	MOVWF	LATD
	goto	burda_sizin_reklaminiz_olabiler
    TON2:
	MOVLW	b'00000011'
	MOVWF	LATD
	goto	burda_sizin_reklaminiz_olabiler
    TON3:
	MOVLW	b'00000111'
	MOVWF	LATD
	goto	burda_sizin_reklaminiz_olabiler
    TON4:
	MOVLW	b'00001111'
	MOVWF	LATD
	goto	burda_sizin_reklaminiz_olabiler
    TON5:
	MOVLW	b'00011111'
	MOVWF	LATD
	goto	burda_sizin_reklaminiz_olabiler
    TON6:
	MOVLW	b'00111111'
	MOVWF	LATD
	goto	burda_sizin_reklaminiz_olabiler
    TON7:
	MOVLW	b'01111111'
	MOVWF	LATD
	goto	burda_sizin_reklaminiz_olabiler
    TON8:
	MOVLW	b'11111111'
	MOVWF	LATD
	goto	burda_sizin_reklaminiz_olabiler
       
subtraction:
    movf    bpart,  0,	1
    subwf   cpart,  0,	1
    bn	    negative
    MOVWF   p1
    goto    LEDS
    
negative:
    MOVWF   p1
    NEGF    p1
    
LEDS:
    movf    p1, W
	xorlw   0
	bz	TONE0
    movf    p1, W
	xorlw   1
	bz	TONE1
    movf    p1, W
	xorlw   2
	bz	TONE2
    movf    p1, W
	xorlw   3
	bz	TONE3
    movf    p1, W
	xorlw   4
	bz	TONE4
	
    TONE0:
	MOVLW	b'00000000'
	MOVWF	LATD
	goto	burda_sizin_reklaminiz_olabiler
    TONE1:
	MOVLW	b'00000001'
	MOVWF	LATD
	goto	burda_sizin_reklaminiz_olabiler
    TONE2:
	MOVLW	b'00000011'
	MOVWF	LATD
	goto	burda_sizin_reklaminiz_olabiler
    TONE3:
	MOVLW	b'00000111'
	MOVWF	LATD
	goto	burda_sizin_reklaminiz_olabiler
    TONE4:
	MOVLW	b'00001111'
	MOVWF	LATD
	goto	burda_sizin_reklaminiz_olabiler
 
burda_sizin_reklaminiz_olabiler:
    call DELAY

goto loop
END
    