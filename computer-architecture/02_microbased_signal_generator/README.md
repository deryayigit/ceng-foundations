# Microprocessor Based Signal Generator

In this experiment, the generation of different types of periodic signals using a microcomputer is investigated. Microprocessors are not only capable of processing digital data but can also generate waveform-like outputs by sending values to output ports at specific time intervals. These signals are inherently discrete, and therefore the smoothness and quality of the waveform depend directly on the processing speed of the microprocessor.  

The fundamental approach is to send a sequence of numerical values, representing the signal, to an output port in a controlled manner. These values can either be generated using counters or retrieved from a predefined lookup table stored in memory. A delay routine is used between successive outputs to control the frequency of the signal.  

---

## Purpose of the Experiment  

The purpose of this experiment is to generate periodic signals composed of linear segments using a microcomputer. The formation of fundamental waveform types such as square wave, triangle wave, and sawtooth wave is examined, along with how their frequencies can be controlled using delay subroutines.  

---

## Working Principle  

Periodic signal generation is achieved by sequentially sending discrete sample values to an output port. A counter is used to track the current sample index, and this index is incremented at each step. Once the maximum value is reached, the counter is reset, ensuring the periodic nature of the signal.  

Simple signals such as square waves can be generated easily even at low speeds because they consist of only two levels. However, more complex signals require finer resolution and faster updates, making the processor speed a critical factor in signal quality.  

For nonlinear signals, a lookup table is typically used. This table contains precomputed values corresponding to each point of the waveform. These values are then read sequentially and sent to the output port. The digital output can be converted into an analog signal using a Digital-to-Analog Converter (DAC).  

---

## Algorithm (Pseudo Code)  

```text
START

Configure input/output ports
Prepare signal sample values
I = 0

LOOP:
    I = I + 1

    Send the I-th value to the output port

    Call delay subroutine

    If I reaches maximum value:
        I = 0

    Go back to LOOP

END
```

### Square Wave Generation

In square wave generation, two amplitude levels (high and low) are alternately sent to the output port for a fixed duration. The BL register acts as a counter to determine how long each level is maintained.

The waitport subroutine ensures that the output port is ready before sending new data, providing proper timing control.

This approach results in a waveform that closely resembles an ideal square wave.

👉 [suquare_wave](suquare_wave.asm)

### Triangle Wave Generation

In triangle wave generation, the output value increases linearly up to a maximum and then decreases back to the starting value. The AL register is incremented step by step until it reaches its maximum value and then decremented.

This creates a waveform composed of linear rising and falling segments. With sufficient processor speed, the generated waveform closely approximates a continuous triangle wave.

👉 [triangle_wave](triangle_wave.asm)

# Code Structure

The programs follow a simple structure. The microprocessor initializes registers and enters a loop where it continuously sends values to the output port. After each output operation, a delay subroutine is executed to control timing.

The instruction OUT 160, AL is used to send the generated value to the output port. The waitport subroutine checks whether the port is ready, preventing data loss and ensuring synchronization.

## Observations

The experiment demonstrates that periodic signal generation is feasible using a microprocessor. However, the quality of the generated signal is highly dependent on the processor speed. At lower speeds, the waveform appears more discrete and stepped rather than smooth.

Simple signals such as square waves can be generated accurately even at low speeds, whereas more complex signals like triangle or sinusoidal waves require higher processing speeds and more precise timing control.

Additionally, it is observed that the delay subroutine plays a crucial role in determining the frequency of the generated signal.
