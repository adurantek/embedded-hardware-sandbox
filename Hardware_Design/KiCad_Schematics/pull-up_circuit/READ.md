# PULL-UP CIRCUIT

## Purpose

I designed this circuit to understand the logic of pull-up resistors and why we use them.

## Learning Outcomes

- ✅ Pull-up design rules were learned
- ✅ It was understood that pull-up resistors must be used in designs to prevent **floating** at microcontroller pin inputs or similar situations.

## Technical Details

### Circuit Design

- Components list

    **2 1x1 Connector**
    
    **2 330R Each Resistors**

    **1 LED Diod**

    **Push Button**


- Design calculations

Taking the VCC voltage as 5V reference.

**R4 value selected for the safe operation of the LED:** $$I_{LED} = \frac{V_{CC} - V_f}{R_4} = \frac{5\text{V} - 2\text{V}}{330\,\Omega} \approx 9.09\text{ mA}$$

**Power dissipation value on the R3 resistor:**

$$P = \frac{V_{CC}^2}{R_3} = \frac{5^2}{330} \approx (75\text{ mW})$$

- Schematic explanation

    If we consider the J3 connector in the circuit as the pin where the digital value comes from, and the J2 connector as a microcontroller, the digital value coming from J3 is directly connected to the J2 connector, ensuring a continuous digital 1 value, there is no noise, and the **pin does not float (floating)**. The SW2 switch is connected directly to the ground, so when the switch is activated, the circuit becomes digital value 0. In this way, **floating** is prevented.

### Simulation/Testing

- Test results

    Case 1: BUTTON RELEASED -> Logic value 1, J2 connector sees VCC.
    
    Case 2: BUTTON PRESSED -> Logic value 0, J2 connector is connected to ground.


- Images

![Schematic](images/schematic_design.jpg)

![Schematic](images/pcb_design.jpg)

## Design Decisions

R3 and R2 resistors were placed in relevant places to prevent short circuits, the push button to simulate pull-up, and the LED for control purposes.

## Future Improvements

- Adding a capacitor ($C$) in parallel with the button to prevent mechanical arcs (signal bouncing) in hardware.

- Adding an NPN Transistor to prevent voltage drop, meaning if we assume VCC is 5V, the J2 pin, which is approximately 3.3V due to R4, will become 5V if we add it.