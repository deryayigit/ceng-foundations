#start=original.exe

name "stepper"

#make_bin#

steps_before_direction_change = 8h   ; total steps (32)

jmp start

datcw   db 0000_0110b
        db 0000_0100b
        db 0000_0011b
        db 0000_0010b    ; stepper phase sequence

start:
    mov bx, offset datcw ; sequence base address
    mov si, 0            ; step index
    mov cx, 0            ; step counter
    mov dx, 0            ; delay (speed control)

next_step:
wait:
    in  al, 7
    test al, 80h         ; wait for ready signal
    jz  wait

    mov di, 0
delay2:
    add di, 2
    cmp di, dx           ; delay loop
    jb  delay2

    cmp cx, 4
    jb  increase_delay   ; slow down phase
    jmp decrease_delay   ; speed up phase

increase_delay:
    add dx, 2            ; increase delay → slower
    jmp output

decrease_delay:
    sub dx, 2            ; decrease delay → faster
    jmp output

output:
    mov al, [bx+si]
    out 7, al            ; send phase to motor

    inc si
    cmp si, 4
    jb  next_step
    mov si, 0            ; restart sequence

    inc cx
    cmp cx, steps_before_direction_change
    jb  next_step

    mov ah, 4Ch
    int 21h              ; exit

end
