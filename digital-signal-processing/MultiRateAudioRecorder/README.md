# Audio Recorder Using Arduino and Multi-Rate Processing

## Project Description

Within the scope of the Digital Signal Processing (DSP) Applications course, the **Audio Recorder Using Arduino and Multi-Rate Processing** project aims to digitize an analog audio signal using a microcontroller with limited hardware resources, process the signal using multi-rate digital signal processing techniques, and store the resulting data on an SD card.


## Objective of the Project

The objective of this project is to transfer an analog audio signal into the digital domain using an ATmega328P-based microcontroller such as Arduino Uno or Nano and to demonstrate the multi-rate signal processing approach in a practical manner. In the project, the audio signal is sampled at a frequency higher than the target recording frequency, followed by digital low-pass filtering and a decimation process to reduce the sampling rate. This approach reduces the need for an analog anti-aliasing filter and enables more controlled filtering in the digital domain. In addition, oversampling is used to improve the signal-to-noise ratio.

## Required Hardware

The hardware components used in the project are listed below:

- Arduino Uno or Arduino Nano (ATmega328P-based)
- Electret microphone with amplifier module (MAX4466 or MAX9814)
- SPI interface SD card module
- Micro SD card formatted as FAT16 or FAT32
- Push button for starting and stopping recording
- LED for indicating system status
- Breadboard and connection wires

## Theoretical Background (Multi-Rate Processing)

Under normal conditions, an audio signal can be sampled directly at the target sampling frequency, such as 8 kHz. However, in this project, a multi-rate approach based on oversampling and decimation is adopted. The audio signal is sampled at a higher frequency that is a multiple of the target frequency, for example 32 kHz. The samples obtained at this higher frequency are then passed through a digital low-pass filter, and only one out of a certain number of samples is retained, reducing the sampling frequency to 8 kHz. This approach reduces aliasing effects and increases the effectiveness of digital filtering.

## Project Stages and Implementation

In the hardware setup, the analog output of the microphone module is connected to the A0 pin of the Arduino. The SD card module is connected to the Arduino using the SPI communication protocol, utilizing the MOSI, MISO, SCK, and CS pins. A push button is added for recording control, and an LED is used to indicate the operational status of the system.

On the software side, due to the insufficient sampling speed of Arduino’s standard `analogRead()` function, the ADC configuration is performed directly at the register level. The ADC prescaler settings are adjusted to increase the sampling rate. The sampling process is not performed within the main loop; instead, a timer interrupt mechanism is used to ensure precise timing. Timer1 or Timer2 is configured to generate interrupts at a fixed sampling frequency, and ADC readings are performed within the interrupt service routine.

Within the interrupt routine, the acquired samples are accumulated, basic digital filtering or averaging is applied, and the samples are decimated according to the specified decimation factor. The resulting lower-rate samples are transferred to a buffer to be written to the SD card.

Since writing to the SD card is a time-consuming operation, a double buffering mechanism is employed to prevent data loss. While one buffer is being filled, the other buffer is written to the SD card, and the roles of the buffers are swapped when a buffer becomes full.


## File Format and Recording

The audio data obtained in the project are stored either in raw (RAW) format or in WAV format by adding a standard 44-byte WAV header. When the WAV format is used, the recorded files can be played directly on a computer without requiring any additional conversion.


## Evaluation

The project is evaluated based on the correctness of the hardware setup, the performance of the ADC and timer interrupt configuration, the correct implementation of the multi-rate algorithm, buffer management and uninterrupted writing to the SD card, as well as the quality of the technical report and the analyses performed.

---

## Algorithm Flowchart
