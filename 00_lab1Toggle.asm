; initial constants
    ldi R16, 0xFF
	ldi R17, 0xFF
; set DDRB as output
	out DDRB, R17
; code to toggle LEDs
toggler:
	subi R16, 0xFF
	out PORTB, R16
	rjmp idle_loop
; delay loop
idle_loop :
	ldi R19, 0xFF
	ldi R20, 0x0F
	ldi R21, 0x01

idle_loop_0 :
idle_loop_1 :
idle_loop_2 :
	dec R19
	brne idle_loop_2
	dec R20
	brne idle_loop_1
	dec R21
	brne idle_loop_0

rjmp toggler
