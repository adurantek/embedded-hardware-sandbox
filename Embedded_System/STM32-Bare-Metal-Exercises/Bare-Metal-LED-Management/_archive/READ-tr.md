# LED Management

### Simulation/Testing

- Logic Analyzer results

![LOGIC ANALYZER](images/logic_analyzer.gif)

- Real footage

![REAL](images/real_view.gif)

## Features

    • Bare-Metal Programming
    • External Interrupts
    • Timer Delay
    • GPIO Configuration
    • Logic Analyzer Verification

## Pin Configuration

| Pin | Function | MODE |
|-----|----------|------|
| PA1 | LED1 | INPUT |
| PA2 | LED2 | INPUT |
| PA3 | LED3 | INPUT |
| PA4 | LED4 | INPUT |
| PA5 | LED5 | INPUT |
| PA6 | Button 1 (EXTI) | OUTPUT |
| PA7 | Button 2 (EXTI) | OUTPUT |

## Purpose
Bu çalışmamda sadece Bare-Metal kullanarak, 2 buton ile 6 ledin durumlarını değiştirme üzerine çalıştım. Amacım bu çalışmada GPIO, RCC, INTERRUPT ve TIMER konularını tekrar etmek, pekiştirmek ve pratiğe dökerek kalıcı öğrenme sağlamaktı. Logic Analyzer kullanarak hem pinlerin davranışını hemde bu cihazın nasıl kullanılacağını öğrenmek istedim. Bu çalışma, fiziksel olarak ilk defa STM32 kodladığım ve çalıştırdığım çalışmamdır.

### Registers Used

- RCC
- GPIOA
- EXTI
- SYSCFG
- NVIC
- TIM3


## Learning Outcomes

- ✅ Logic Analyzer ile **pin-register-dijital davranışları** ve PulseView ile okuma yapma öğrenildi.
- ✅ **TIMER** ile **mikrodenetleyici frekansı ayarlama** ve kendi delay() fonksiyonu yazma öğrenildi.
- ✅ 2 farklı buton kullanılarak **INTERRUPT** yapıları daha net öğrenildi ve pekiştirildi.
- ✅ STM32 CubeIDE ve STM32 CubeMX kullanımı öğrenildi.
- ✅ Board üzerinde pin ayarlamaları ve bağlantılarını yapma öğrenildi.

## Technical Details

### Registers Describe

Anahtarlar ve ledlerin hepsi A portuna bağlandı, GPIO ile A portu açıldı. Ledler için PA12345, anahtarlar için PA6 ve PA7 kullanıldı (başa dönmek için board üzerindeki reset butonu kullanılıyor). Her butona basıldığında leds_status degiskeni if blokları ile degistirilerek ledlerin yanma hızı ve yanma sıraları değiştiriliyor. MODER ile gerekli input-output atamaları yapıldı, PUPDR ile butonlara pull-up dirençleri atanıyor, EXTICR ile PA6 ve PA7 için interrupt atanıyor, FTSR1 ile falling anahtarı tanımlanıyor, IMR ile mask enable ve NVICEnableIRQ() fonksiyonu ile board içinde önlem amaçlı yazılan fonksiyon açılıyor. TIMER kısmında kendi delay() fonksiyonumu yazdım, CNT ile sayaç sıfırlanıyor, PSC ile board frekansı düşürülüyor, ARR ile hedef süre tanımlanıyor, SR önce sıfırlanıyor, CR1 ile clock başlatılıp while fonksiyonu hedef süreye ulaşılmasını bekledikten sonra SR board içinden enable oluyor ve tekrar kullanılmak üzere SR sıfırlıyoruz. EXTI4_15_IRQHandler(void) içine FPR1 ile anahtarların tetiklenme durumlarını kontrol ederek leds_status değişkenine gerekli tanımlamalar yapılıyor. int main(void) içine ise Ledlerin yanma hızları ve sıraları tanımlanıyor. Interrupt ile olacak değişimler if blokları ile sağlanmıştır. (Her kod bloğunun açıklaması yanına yorum satırları ile açıklanmıştır).

### Components list

    - Each 2 Same color (red, yellow, green) with LEDs.
    - 2 Tactile Switch
    - Jumpers
    - Logic Analyzer (24Mhz 8 Channels)
    - 330 Ohm 6 Resistors

## Future Improvements

- Bu TIMER kullanımı sistemi bekletiyor ve verimsizleştiriyor, INTERRUPT TIMERS kullanılmalı
- Başlangıç durumuna dönmek için board üzerindeki button kullanılmakta, yeni bir buton eklenmeli
- Butonlara basıldığı anda LEDler tepki vermiyor, durumun tamamen bitmesi bekleniyor, anında değişim için yapı değiştirilebilir

## Project Structure

    ├── Core
    │   ├── Inc
    │   └── Src
    ├── images
    ├── README.md