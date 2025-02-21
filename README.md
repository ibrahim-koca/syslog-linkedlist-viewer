# Syslog Bağlı Liste Uygulaması

Bu proje, Linux işletim sistemindeki syslog kayıtlarını bağlı liste veri yapısı kullanarak görüntüleyen ve yöneten bir C uygulamasıdır.

## Proje Hakkında

Bu uygulama, Linux sistem günlüklerini (syslog) okuyup, çift yönlü bağlı liste yapısında saklar ve yönetir. Syslog kayıtları, sistemde gerçekleşen olayları kronolojik sırayla takip etmemizi sağlar.

### Özellikler

- Syslog kayıtlarını okuma ve parse etme
- Çift yönlü bağlı liste yapısında saklama
- Kayıtları tarih/saat, öncelik ve kaynak bilgisine göre listeleme
- Yeni log kayıtları ekleme
- Var olan kayıtları silme

## Kullanılan Veri Yapısı

Projede çift yönlü bağlı liste (Doubly Linked List) kullanılmıştır. Bu veri yapısının seçilme nedenleri:

1. İleri ve geri yönde gezinme imkanı
2. Dinamik bellek kullanımı
3. Kayıtların kronolojik sırada tutulmasına uygunluk
4. Kayıt ekleme/silme işlemlerinin efektif yapılabilmesi

## Kurulum

```bash
gcc -o syslog_program main.c
./syslog_program
```

## Kullanım

Program çalıştırıldığında kullanıcıya aşağıdaki seçenekler sunulur:

1. Tüm kayıtları listele
2. Yeni kayıt ekle
3. Kayıt sil
4. Önceliğe göre filtrele
5. Çıkış

## Katkıda Bulunma

1. Bu depoyu fork edin
2. Yeni bir branch oluşturun (`git checkout -b feature/yeniOzellik`)
3. Değişikliklerinizi commit edin (`git commit -am 'Yeni özellik eklendi'`)
4. Branch'inizi push edin (`git push origin feature/yeniOzellik`)
5. Pull Request oluşturun
