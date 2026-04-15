#start=original.exe

name "stepper_speed_up_down"

#make_bin#

steps_total = 20h          ; 32 steps
initial_delay = 20h        ; starting delay
ramp_limit = 4h            ; first 4 steps: speed up

jmp start

datcw   db 0000_0110b
        db 0000_0100b
        db 0000_0011b
        db 0000_0010b      ; stepper phase sequence

start:
    mov bx, offset datcw   ; base address of phase table
    mov si, 0              ; current phase index
    mov cx, 0              ; step counter
    mov dx, initial_delay  ; delay value

next_step:
wait:
    in  al, 7
    test al, 80h           ; wait until ready bit becomes 1
    jz  wait

    mov di, dx
delay_loop:
    sub di, 2
    nop
    jnz delay_loop         ; software delay

    cmp cx, ramp_limit
    jb  decrease_delay     ; first phase: speed up
    jmp increase_delay     ; second phase: slow down

decrease_delay:
    cmp dx, 2
    jbe output_step
    sub dx, 2              ; smaller delay -> higher speed
    jmp output_step

increase_delay:
    add dx, 2              ; larger delay -> lower speed

output_step:
    mov al, [bx+si]
    out 7, al              ; send phase value to motor

    inc si
    cmp si, 4
    jb  continue_steps
    mov si, 0              ; restart phase sequence

continue_steps:
    inc cx
    cmp cx, steps_total
    jb  next_step

    mov ah, 4Ch
    int 21h                ; terminate program

end
