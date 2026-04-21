#start=Grafik.exe#

#make_bin#

name "square"


    MOV CX,3
SQUARE:	
    MOV BL, 00H
	  MOV AX, 01H
HIGH:
    PUSH AX	
    call waitport
    
    POP AX
    OUT 160, AL
    
    INC BL
    CMP BL,0FH
	  JNZ HIGH
	
	  MOV BL, 00H
	  MOV AX, 0FAH  
LOW:  
    PUSH AX	
    call waitport
    
    POP AX
    OUT 160, AL

    INC BL
    CMP BL,0FH

	  JNZ LOW
	
	  LOOP SQUARE

hlt

waitport:
    wait3:           ; loop to ensure the printer
    in al, 160d     ; is ready, it clears
    or al, 0        ; the port when this is true.
    jnz wait3
    ret
