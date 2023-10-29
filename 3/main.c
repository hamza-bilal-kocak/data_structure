#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Öğrenci bilgilerini saklamak için bir yapı tanımlanıyor.
struct Ogrenci {
    int numara;
    char isim[50];
    int yas;
    struct Ogrenci* sonraki; // Bağlı liste için bir sonraki öğrenci işareti.
};

// Bağlı listeyi dolaşarak öğrenci bilgilerini ekrana yazan ve sayan fonksiyon.
void ogrenciBilgileriniYaz(struct Ogrenci* baslangic) {
    int sayac = 1;

    // Bağlı listeyi dolaşma döngüsü.
    while (baslangic != NULL) {
        printf("%d - %s %d %d\n", sayac, baslangic->isim, baslangic->yas, baslangic->numara);
        baslangic = baslangic->sonraki;
        sayac++;
    }
}

int main() {
    // Öğrenci bilgilerini içeren bağlı liste oluşturuluyor.
    struct Ogrenci* ilkOgrenci = NULL;
    struct Ogrenci* yeniOgrenci;

    // Örnek öğrenciler ekleniyor.
    yeniOgrenci = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    yeniOgrenci->numara = 101;
    strcpy(yeniOgrenci->isim, "Ali");
    yeniOgrenci->yas = 20;
    yeniOgrenci->sonraki = NULL;
    ilkOgrenci = yeniOgrenci;

    yeniOgrenci = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    yeniOgrenci->numara = 102;
    strcpy(yeniOgrenci->isim, "Ayşe");
    yeniOgrenci->yas = 22;
    yeniOgrenci->sonraki = NULL;
    ilkOgrenci->sonraki = yeniOgrenci;

    yeniOgrenci = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    yeniOgrenci->numara = 103;
    strcpy(yeniOgrenci->isim, "Mehmet");
    yeniOgrenci->yas = 21;
    yeniOgrenci->sonraki = NULL;
    ilkOgrenci->sonraki->sonraki = yeniOgrenci;

    // Öğrenci bilgilerini yazdıran fonksiyon çağrılıyor.
    ogrenciBilgileriniYaz(ilkOgrenci);

    return 0;
}
