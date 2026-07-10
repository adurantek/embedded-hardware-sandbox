# DİGİTAL LOGİC XOR GATE CİRCUİT

## DESCRİPTİON 

Bu devreyi XOR entegresinin iç yapısını tasarlayarak, hem sayısal sistem tasarımını kavramak hemde lojik kapıların çalışma şeklini anlamak için tasarladım. 2 NOT, 2 AND ve bir adet OR kapısı kullandım. NOT ile gelen sinyallerden biri ters çevriliyor, diğer sinyal AND girişlerinden birine gidiyor, AND entegresi gelen 2 sinyal 1 ise çalışıyor ve bu 2 AND entegresinden gelen digital veriler en son OR entegresinin 2 kapısına aktarılıyor. Bu şekilde XOR entegresi elde etmiş oluyoruz.

** Output = $(A \cdot \bar{B}) + (\bar{A} \cdot B)$ **

### Truth Table

| Input A | Input B | Output (LED) |
| :---: | :---: | :---: |
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

### Components

    2 74LS04 (NOT)
    2 74LS08 (AND)
    1 74LS32 (OR)

### Views

![Schematic Design](images/schematic-design.jpg)

![PCB Design](images/pcb-design.jpg)

![3D View](images/3d_view.jpg)