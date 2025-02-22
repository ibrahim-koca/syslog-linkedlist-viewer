#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Syslog mesaj oncelik seviyeleri
// Bu enum, syslog mesajlarinin oncelik seviyelerini tanimlar.
typedef enum {
    ACIL = 0,       // Acil durum mesajlari
    HATA = 3,       // Hata mesajlari
    UYARI = 4,      // Uyari mesajlari
    BILGI = 6,      // Bilgi mesajlari
    HATA_AYIKLAMA = 7  // Hata ayiklama mesajlari
} MesajOnceligi;

// Syslog mesaji icin dugum yapisi
// Bu struct, her bir log mesajini temsil eder.
typedef struct LogDugum {
    MesajOnceligi oncelik;  // Mesajin oncelik seviyesi
    char zamanDamgasi[26];  // Mesajin zaman damgasi
    char mesaj[256];        // Mesaj icerigi
    struct LogDugum* sonraki; // Sonraki log mesajina isaretci
} LogDugum;

// Yeni log dugumu olusturma fonksiyonu
// Bu fonksiyon, yeni bir log dugumu olusturur ve baslatir.
LogDugum* dugumOlustur(MesajOnceligi oncelik, const char* zaman, const char* mesaj) {
    LogDugum* yeniDugum = (LogDugum*)malloc(sizeof(LogDugum));
    if (!yeniDugum) {
        printf("Bellek ayirma hatasi!\n");
        exit(1);
    }

    yeniDugum->oncelik = oncelik;
    strncpy(yeniDugum->zamanDamgasi, zaman, sizeof(yeniDugum->zamanDamgasi) - 1);
    yeniDugum->zamanDamgasi[sizeof(yeniDugum->zamanDamgasi) - 1] = '\0';
    strncpy(yeniDugum->mesaj, mesaj, sizeof(yeniDugum->mesaj) - 1);
    yeniDugum->mesaj[sizeof(yeniDugum->mesaj) - 1] = '\0';
    yeniDugum->sonraki = NULL;

    return yeniDugum;
}

// Log mesajini listeye ekleme fonksiyonu
// Bu fonksiyon, yeni bir log mesajini listeye ekler.
void mesajEkle(LogDugum** bas, MesajOnceligi oncelik, const char* zaman, const char* mesaj) {
    LogDugum* yeni = dugumOlustur(oncelik, zaman, mesaj);

    if (*bas == NULL) {
        *bas = yeni;
        return;
    }

    LogDugum* simdiki = *bas;
    while (simdiki->sonraki)
        simdiki = simdiki->sonraki;
    
    simdiki->sonraki = yeni;
}

// Oncelik seviyesini metin olarak donduren fonksiyon
// Bu fonksiyon, oncelik seviyesini metin olarak dondurur.
const char* oncelikMetni(MesajOnceligi oncelik) {
    switch (oncelik) {
        case ACIL:          return "EMERGENCY";
        case HATA:          return "ERROR";
        case UYARI:         return "WARNING";
        case BILGI:         return "INFO";
        case HATA_AYIKLAMA: return "DEBUG";
        default:            return "UNKNOWN";
    }
}

// Tum log mesajlarini goruntuleme fonksiyonu
// Bu fonksiyon, tum log mesajlarini ekranda gosterir.
void mesajlariGoster(LogDugum* bas) {
    LogDugum* simdiki = bas;
    printf("\n=== SYSTEM LOG MESSAGES ===\n\n");

    while (simdiki) {
        printf("[%s] %s - %s\n", 
            oncelikMetni(simdiki->oncelik), 
            simdiki->zamanDamgasi, 
            simdiki->mesaj);
        simdiki = simdiki->sonraki;
    }
    printf("\n");
}

// Bellegi temizleme fonksiyonu
// Bu fonksiyon, log listesini temizler ve bellegi serbest birakir.
void listeyiTemizle(LogDugum** bas) {
    LogDugum* simdiki = *bas;
    while (simdiki) {
        LogDugum* gecici = simdiki;
        simdiki = simdiki->sonraki;
        free(gecici);
    }
    *bas = NULL;
}

int main() {
    LogDugum* mesajListesi = NULL;

    // Ornek log mesajlari
    mesajEkle(&mesajListesi, ACIL, "2025-02-12 14:30:00", "System crash detected! Immediate action required.");
    mesajEkle(&mesajListesi, HATA, "2025-02-12 14:31:10", "Failed to establish database connection.");
    mesajEkle(&mesajListesi, UYARI, "2025-02-12 14:32:20", "Disk space usage exceeds 90%.");
    mesajEkle(&mesajListesi, BILGI, "2025-02-12 14:33:30", "System startup completed successfully.");
    mesajEkle(&mesajListesi, HATA_AYIKLAMA, "2025-02-12 14:34:40", "Function call trace: initSystem()");

    // Log mesajlarini goster
    mesajlariGoster(mesajListesi);

    // Bellegi temizle
    listeyiTemizle(&mesajListesi);

    return 0;
}

