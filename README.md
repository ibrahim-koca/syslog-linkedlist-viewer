# Log Sistemi Projesi

Bu proje, syslog mesajlarını yönetmek ve görüntülemek için basit bir C programı içerir. Program, farklı öncelik seviyelerine sahip log mesajlarını bir bağlı liste yapısında saklar ve bu mesajları kullanıcıya gösterir.

## İçindekiler

1. [Proje Açıklaması](#proje-açıklaması)
2. [Gereksinimler](#gereksinimler)
3. [Kurulum](#kurulum)
4. [Kullanım](#kullanım)
5. [Fonksiyonlar](#fonksiyonlar)
6. [Örnekler](#örnekler)
7. [Katkıda Bulunma](#katkıda-bulunma)

## Proje Açıklaması

Bu proje, syslog mesajlarını yönetmek için bir C programı içerir. Program, farklı öncelik seviyelerine sahip log mesajlarını bir bağlı liste yapısında saklar ve bu mesajları kullanıcıya gösterir. Program, aşağıdaki özellikleri içerir:

- Log mesajlarını farklı öncelik seviyelerinde saklama
- Log mesajlarını ekranda görüntüleme
- Bellek yönetimi ve temizleme

## Gereksinimler 
- C derleyicisi (GCC veya Dev-C++ gibi GCC tabanlı derleyiciler)
- Standart C kütüphaneleri

## Kurulum

Projeyi yerel makinenizde çalıştırmak için aşağıdaki adımları izleyin:

1. Bu depoyu klonlayın:
   ```bash
   git clone https://github.com/kullanici_adiniz/log-sistemi.git
   ```
2. Proje dizinine gidin:
   ```bash
   cd log-sistemi
   ```
3. Programı derleyin:
   ```bash
   gcc log_sistemi.c -o log_sistemi
   ```

## Kullanım

Programı çalıştırmak için aşağıdaki komutu kullanın:

```bash
./log_sistemi
```

Program, örnek log mesajlarını ekleyecek ve bu mesajları ekranda gösterecektir.

## Fonksiyonlar

- `dugumOlustur`: Yeni bir log düğümü oluşturur.
- `mesajEkle`: Log mesajını listeye ekler.
- `oncelikMetni`: Öncelik seviyesini metin olarak döndürür.
- `mesajlariGoster`: Tüm log mesajlarını ekranda gösterir.
- `listeyiTemizle`: Log listesini temizler ve belleği serbest bırakır.

## Örnekler

Program, aşağıdaki örnek log mesajlarını içerir:

- Acil durum mesajı: "System crash detected! Immediate action required."
- Hata mesajı: "Failed to establish database connection."
- Uyarı mesajı: "Disk space usage exceeds 90%."
- Bilgi mesajı: "System startup completed successfully."
- Hata ayıklama mesajı: "Function call trace: initSystem()"

## Katkıda Bulunma

Katkıda bulunmak için lütfen bir "Pull Request" açın. Büyük değişiklikler için önce bir konu açarak neyi değiştirmek istediğinizi tartışın.
