# PROJE-6
README: TM4C123GH6PM Clock Initialization (APIsiz)

Proje Açıklaması
Bu proje, TM4C123GH6PM mikrodenetleyicisi için API kullanmadan saat (clock) ayarlarını gerçekleştiren bir program içerir. Program, sistem saatini PLL (Phase-Locked Loop) kullanarak 50 MHz'e ayarlamak için doğrudan donanım kayıtlarına (registers) erişir.

Kullanılan Donanım
Mikrodenetleyici: TM4C123GH6PM
Kristal Frekansı: 16 MHz (Harici Osilatör)

Kod Açıklaması
Kod, clockinit() fonksiyonunu kullanarak sistem saatini yapılandırır. Bu yapılandırma aşağıdaki adımları içerir:
PLL Kullanımı Devre Dışı Bırakılır: Bypass ve sistem bölücü kapatılır.
Kristal ve Osilatör Kaynağı Seçilir: 16 MHz harici osilatör kullanılır.
PLL Etkinleştirilir: PLL açılır, ancak henüz devreye alınmaz.
Sistem Bölücü Ayarlanır: 4'e bölerek sistem saatini 50 MHz'e ayarlar.
PLL Kilitlenmesi Beklenir: PLL'nin kilitlendiğinden emin olmak için bekleme döngüsü kullanılır.
PLL Devreye Alınır: Bypass kaldırılır ve yeni saat frekansı kullanıma girer.
Kod, TivaWare API'leri olmadan yazılmıştır ve donanım seviyesinde register manipülasyonu ile çalışmaktadır.

Derleme ve Çalıştırma
Bu kod, Keil uVision, Code Composer Studio (CCS) veya ARM GCC gibi derleyiciler ile çalıştırılabilir.
