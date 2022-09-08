 .include "/home/ganga/m328Pdef.inc"

ldi r16,high(RAMEND)
OUT SPH,r16
ldi r16,low(RAMEND)
OUT SPL,r16


ldi r16, 0b00111100          ;OUTPUTS
out DDRD,r16
ldi r17, 0b11110000         ;INPUTS
out DDRB,r17         
;ldi r17,0b11110011   
;out PortB,r17
;in r17,PINB

;ldi r16, high(RAMEND) ;for clock 
;out SPH, r16
;ldi r16, low(RAMEND)
;out SPL, r16
ldi r16, 0b00000101 ;clk
out TCCR0B, r16

loopw:
in r17,PINB
ldi r18,0b00000001
ldi r19,0b00000001
ldi r20,0b00000001
ldi r21,0b00000001


AND r19,r17          ;r19=c
LSR  r17
AND r20,r17           ;r20=b
LSR r17
AND r21,r17           ;r21=a
LSR r17
AND r18,r17           ;r18=x

ldi r22,0b00000001
eor r22,r19           ;r22=c'

ldi r23,0b00000001
eor r23,r20           ;r23=b'

ldi r24,0b00000001
eor r24,r21           ;r24=a'

ldi r25,0b00000001
eor r25,r18           ;r25=x'

mov r0,r25            ;r0=x'        
mov r1,r23            ;r1=b'
AND r1,r0             ;r1=b'x'

mov r2,r19           ;r2=c
AND r2,r0            ;r2=cx'
OR r2,r1             ;r2=cx'+b'x'     (p)

mov r3,r19            ;r3=c
AND r3,r18            ;r3=cx
mov r4,r20            ;r4=b
AND r4,r22            ;r4=bc'
OR  r4,r3             ;r4=bc'+cx      (Q)      

mov r5,r22            ;r5=C'
AND r5,r25            ;r5=C'X'
mov r6,r22            ;r6=c'
AND r6,r23            ;r6=b'c'
OR  r6,r5             ;r6=b'c'+c'x'
OR r6,r1              ;r6=b'c'+c'x'+b'x'   (R)


AND r25,r20            ;r0=bx'
AND r25,r19            ;r0=bx'c         (y)



ldi  r16,0b00000000          ;
mov r16,r25               ;0b0000000y
lsl r16
or r16,r6                ;0b000000YR
lsl r16
or r16,r4                ;0b00000YRQ
lsl r16
or r1,r2                 ; 0b0000YRQP
lsl r16
lsl r16

out PORTD,r16



sbi PORTB,5; set pin 13  as output pin clock
rcall  WAIT
cbi PORTB,5
rcall  WAIT

rjmp loopw

 WAIT:
ldi r26, 0x50 
 
WAIT_loop:
in r16, TIFR0
andi r16, 0x01  ; Check if timer overflow (given 0x02 which mask for compare)
breq wait_loop 
ldi r16, 0x01   ; Clear flag to check again
out TIFR0, r16
dec r26
brne  WAIT_loop
ret


start:
rjmp start

