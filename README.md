# Syslog Linked List Viewer

Basit bir log kayıt sistemi uygulaması. Bu program, log kayıtlarını öncelik seviyelerine göre saklamak ve görüntülemek için bağlı liste veri yapısını kullanır.

## İçindekiler
- [Özellikler](#özellikler)
- [Kullanılan Veri Yapısı](#kullanılan-veri-yapısı)
- [Gereksinimler](#gereksinimler)
- [Kurulum](#kurulum)
- [Kullanım](#kullanım)
- [Katkıda Bulunma](#katkıda-bulunma)

## Özellikler
- Log kayıtlarını öncelik seviyesine göre saklama
- Yeni log kayıtları ekleme
- Tüm kayıtları listeleme
- Üç farklı öncelik seviyesi (Normal, Uyari, Hata)

## Kullanılan Veri Yapısı
Projede tek yönlü bağlı liste (Singly Linked List) kullanılmıştır. Bu veri yapısının seçilme nedenleri:
- Dinamik bellek kullanımı
- Yeni kayıtların hızlı eklenmesi
- Basit ve etkili implementasyon
- Bellek kullanımında verimlilik

## Gereksinimler
- C derleyicisi (GCC önerilir)
- Standart C kütüphaneleri

## Kurulum
1. Projeyi klonlayın:
```bash
git clone https://github.com/ibrahim-koca/syslog-linkedlist-viewer.git
cd syslog-linkedlist-viewer
```

2. Programı derleyin:
```bash
gcc -o syslog_program main.c
```

3. Programı çalıştırın:
```bash
./syslog_program
```

## Kullanım
Program çalıştırıldığında aşağıdaki menü seçenekleri sunulur:

1. **Kayitlari goster**
   - Tüm log kayıtlarını öncelik seviyeleriyle birlikte görüntüler

2. **Yeni kayit ekle**
   - Yeni bir log kaydı oluşturur
   - Öncelik seviyeleri:
     - 0: Normal
     - 1: Uyari
     - 2: Hata

3. **Cikis**
   - Programdan çıkış yapar ve belleği temizler

## Katkıda Bulunma
1. Bu projeyi fork edin
2. Yeni bir branch oluşturun:
```bash
git checkout -b feature/yeniOzellik
```
3. Değişikliklerinizi commit edin:
```bash
git commit -am 'Yeni özellik: <özellik adı>'
```
4. Branch'inizi push edin:
```bash
git push origin feature/yeniOzellik
```
5. Bir Pull Request oluşturun
