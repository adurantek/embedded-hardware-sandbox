# STM32 MINIMAL VIABLE SYSTEM

## Purpose



## Learning Outcomes
- ✅ **Decopling kapasitörleri mantığı** ve mikrodenetleyicilerde, entegrelerde ve işlemcilerde **konumlandırılması**, **yakın olmasının önemi**
- ✅ Pull-up dirençlerinin mikrodenetleyicilerde, entegrelerde ve işlemcilerde yerleştirilmesi ve önemi
- ✅ Neden Minimal Viable System tasarlanması gerektiği ve tasarımı

## Technical Details

### Circuit Design

- Components list

    -1x4 Pinheader Connector
    -1 Resistor (SMD) -10k Ohm-
    -1 Tacticle Switch
    -3 Seramic Capacitors -100nF- (SMD)

- Schematic explanation

### Simulation/Testing
- Test results
- Performance metrics
- Images/graphs

## Design Decisions

-3 kapasitör, girişlerde gürültü engellemek için (**decopling**) amaçlı -pcb tasarımda yakın olması önemli-,
-direnç 10 numaralı pinde **akımı sınırlamak** amaçlı, **kısa devreyi önlemek** için,
-anahtar 10 numaralı pinde **floating** önlemek için konuldu.

## Future Improvements

- Idea 1
- Idea 2