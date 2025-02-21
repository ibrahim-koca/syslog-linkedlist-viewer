#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef enum {
    NORMAL,
    UYARI,
    HATA
} OncelikTipi;

typedef struct LogKayit {
    char mesaj[256];
    OncelikTipi oncelik;
    struct LogKayit* sonraki;
} LogKayit;

typedef struct {
    LogKayit* bas;
    int sayac;
} KayitListesi;

void listeBaslat(KayitListesi* liste) {
    liste->bas = NULL;
    liste->sayac = 0;
}

void kayitEkle(KayitListesi* liste, OncelikTipi oncelik, const char* mesaj) {
    LogKayit* yeniKayit = (LogKayit*)malloc(sizeof(LogKayit));
    if (yeniKayit == NULL) {
        printf("Bellek hatasi!\n");
        return;
    }
    
    yeniKayit->oncelik = oncelik;
    strncpy(yeniKayit->mesaj, mesaj, sizeof(yeniKayit->mesaj) - 1);
    yeniKayit->sonraki = liste->bas;
    liste->bas = yeniKayit;
    liste->sayac++;
}

void kayitlariGoster(KayitListesi* liste) {
    LogKayit* simdiki = liste->bas;
    if (simdiki == NULL) {
        printf("Kayit yok.\n");
        return;
    }
    
    printf("\n--- Kayitlar ---\n");
    while (simdiki != NULL) {
        printf("Oncelik: %s\n", 
            simdiki->oncelik == NORMAL ? "Normal" :
            simdiki->oncelik == UYARI ? "Uyari" : "Hata");
        printf("Mesaj: %s\n", simdiki->mesaj);
        printf("-------------\n");
        simdiki = simdiki->sonraki;
    }
}

void listeyiTemizle(KayitListesi* liste) {
    LogKayit* simdiki = liste->bas;
    while (simdiki != NULL) {
        LogKayit* gecici = simdiki;
        simdiki = simdiki->sonraki;
        free(gecici);
    }
    liste->bas = NULL;
    liste->sayac = 0;
}

int main() {
    KayitListesi liste;
    listeBaslat(&liste);
    int secim;
    
    while (1) {
        printf("\nLog Sistemi\n");
        printf("1. Kayitlari goster\n");
        printf("2. Yeni kayit ekle\n");
        printf("3. Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &secim);
        getchar();
        
        if (secim == 1) {
            kayitlariGoster(&liste);
        }
        else if (secim == 2) {
            char mesaj[256];
            int oncelik;
            
            printf("Mesaj: ");
            fgets(mesaj, sizeof(mesaj), stdin);
            mesaj[strcspn(mesaj, "\n")] = 0;
            
            printf("Oncelik (0:Normal, 1:Uyari, 2:Hata): ");
            scanf("%d", &oncelik);
            getchar();
            
            if (oncelik >= 0 && oncelik <= 2) {
                kayitEkle(&liste, (OncelikTipi)oncelik, mesaj);
                printf("Kayit eklendi.\n");
            } else {
                printf("Gecersiz oncelik!\n");
            }
        }
        else if (secim == 3) {
            listeyiTemizle(&liste);
            printf("Program sonlandi.\n");
            break;
        }
    }
    
    return 0;
}
