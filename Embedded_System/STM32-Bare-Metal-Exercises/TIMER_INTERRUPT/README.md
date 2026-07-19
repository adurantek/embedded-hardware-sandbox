# TIMER-INTERRUPT Practice

### Simulation/Testing

- Logic Analyzer results

![LOGIC ANALYZER](images/logic_analyzer_timer_interrupt.gif)

- Real footage

![REAL](images/real_view-ezgif.com-video-to-gif-converter.gif)

## Features

    • Bare-Metal Implementation : STM32 kütüphaneleri kullanmadan, doğrudan register seviyesinde (CMSIS) firmware geliştirme.
    • Timer-Interrupt Architecture : Gecikme veya sistemi bekletme olmadan zamanlama kullanımı
    • GPIO Configuration : LED davranışlarının yapılandırılması
    • Logic Analyzer Verification : Sinyal zamanlamalarının ve donanımların davranışlarının izlenmesi

## Pin Configuration

| Pin | Function | MODE |
|-----|----------|------|
| PA1 | LED | OUTPUT |

## Purpose

This study was conducted only to understand-learn-reinforce the Timer-Interrupt architecture.

### Registers Used

- RCC
- GPIOA
- NVIC
- TIM3
- DMA

## Learning Outcomes

- ✅ Timer-Interrupt architecture was grasped.

## Technical Details

### Registers Describe

With `RCC`, `TIM3` and port A were opened. Timer-Interrupt was activated using `DMA`. Frequency reduction and timing settings were made with `PSC` and `ARR`. By checking the `SR` register, the interrupt is activated when the time is up and the `led_status` variable is changed. Then the `SR` register is reset. The timer is started with `CRT`. Inside the `while` loop, it is ensured that the LED blinks 1 time per second by using `toggle` only with the `if` block.

### Components list
    
    -1 LED
    -1 330 OHM Resistor