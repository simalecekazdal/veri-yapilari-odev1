/**       
* @file          DNA.cpp
* @description   DNA üzerinden yapılacak olan ekleme, çaprazlama, mutasyon, kayıtlı işlemler,
*                ekrana yazdırma işlemlerini burada tanımladım. Ayrıca yıkıcı fonksiyon da burada.
* @course        İkinci öğretin B grubu
* @assignment    Birinci ödev
* @date          04.11.2024
* @author        Şimal Ece KAZDAL 
*/ 

#include "DNA.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

DNA::DNA() : bas(nullptr) {}  // Constructor implementasyonu/Kurucu fonksiyon

void DNA::ekle(Kromozom* kromozom) 
//Kromozomları DNA ya ekleme fonksiyonu
{
    if (!bas) 
    {
        bas = kromozom;  // İlk kromozomu başa ekle
    } 
    else 
    {
        Kromozom* temp = bas;
        while (temp->sonraki) 
        {  // Son kromozomu bul
            temp = temp->sonraki;
        }
        temp->sonraki = kromozom;  // Sonuna ekle
    }
}

void DNA::caprazla(int idx1, int idx2) 
//Çaprazlama işlemi
{
    Kromozom* krom1 = bas;
    Kromozom* krom2 = bas;
    for (int i = 0; i < idx1; i++) 
    {
        if (krom1) krom1 = krom1->sonraki;
    }
    for (int i = 0; i < idx2; i++) 
    {
        if (krom2) krom2 = krom2->sonraki;
    }

    if (!krom1 || !krom2) return; // Geçersiz indeks kontrolü

    Kromozom* yeniKromozom1 = new Kromozom();
    Kromozom* yeniKromozom2 = new Kromozom();

    Gen* temp1 = krom1->bas;
    Gen* temp2 = krom2->bas;

    int genSayisi1 = 0, genSayisi2 = 0;

    while (temp1) { genSayisi1++; temp1 = temp1->sonraki; }
    while (temp2) { genSayisi2++; temp2 = temp2->sonraki; }

    int orta1 = genSayisi1 / 2;
    int orta2 = genSayisi2 / 2;

    // Kromozomların genlerini çaprazlama
    temp1 = krom1->bas;
    temp2 = krom2->bas;

    for (int i = 0; i < orta1; i++) 
    {
        yeniKromozom1->ekle(temp1->veri);
        temp1 = temp1->sonraki;
    }
    for (int i = 0; i < orta2; i++) 
    {
        temp2 = temp2->sonraki;
    }
    while (temp2) 
    {
        yeniKromozom1->ekle(temp2->veri);
        temp2 = temp2->sonraki;
    }

    temp1 = krom1->bas;
    temp2 = krom2->bas;

    for (int i = 0; i < orta1; i++) 
    {
        temp1 = temp1->sonraki;
    }
    while (temp1) 
    {
        yeniKromozom2->ekle(temp1->veri);
        temp1 = temp1->sonraki;
    }
    for (int i = 0; i < orta2; i++) 
    {
        yeniKromozom2->ekle(temp2->veri);
        temp2 = temp2->sonraki;
    }

    ekle(yeniKromozom1);
    ekle(yeniKromozom2);
}

void DNA::mutasyon(int kromIdx, int genIdx) 
{
    Kromozom* krom = bas;
    for (int i = 0; i < kromIdx && krom; i++) 
    {
        krom = krom->sonraki; // Kromozoma git
    }

    if (!krom) return; // Geçersiz indeks kontrolü

    Gen* temp = krom->bas;
    int count = 0;

    while (temp && count < genIdx) 
    {
        temp = temp->sonraki;
        count++;
    }

    if (temp) temp->veri = 'X'; // Mutasyon işlemi
}

void DNA::otomatikIslem(const string& dosyaAdi) 
{
    ifstream dosya(dosyaAdi);
    if (!dosya) return;

    string satir;
    while (getline(dosya, satir)) 
    {
        //değişkenler tanımlandı
        stringstream ss(satir);
        char islemTuru;
        int idx1, idx2;
        ss >> islemTuru >> idx1 >> idx2;

        if (islemTuru == 'C') 
        //eğer C işe işlem Çaprazlamadır bu durumda çaprazlama metoduna gider.
        {
            caprazla(idx1, idx2);
        } 
        else if (islemTuru == 'M') 
        //eğer M ise işlem mutasyondur bu durumda mutasyon metoduna gier.
        {
            mutasyon(idx1, idx2);
        }
    }
    dosya.close();
    cout << "Islem tamamlandi." << endl;
}

void DNA::ozelYazdir() const 
{
    for (Kromozom* krom = bas; krom; krom = krom->sonraki) 
    {
        Gen* temp = krom->bas;

        if (!temp) continue;  // Eğer kromozom boşsa, geç

        char referansGen = temp->veri;  // En soldaki (ilk) gen değeri referans alınır
        char yazdirGen = referansGen;   // İlk olarak yazdırılacak değer olarak belirlenir

        // Kromozomun sonuna git
        while (temp && temp->sonraki) 
        {
            temp = temp->sonraki;
        }

        // Sağdan sola doğru en soldaki değerle kıyaslayıp en soldakinden küçük değerle karşılaşılırsa ekrana o yazdırılıyor.
        while (temp) 
        {
            if (temp->veri < referansGen) 
            {
                yazdirGen = temp->veri;  // En soldaki değerden küçük bir gen bulundu
                break;  // İlk küçük değeri bulduğunda döngüden çık
            }
            temp = temp->onceki;  // Sola doğru gidildiği için önceki gene geçiliyor.
        }

        cout << yazdirGen << " ";  // Bulunan yazdırılacak gen ekrana yazdırılır
    }
    cout << endl;
}


void DNA::yazdir() const {
    //son durumu ekrana yazdırma fonksiyonu tüm kromozomları sırayla yazdırıyor.
    for (Kromozom* krom = bas; krom; krom = krom->sonraki) 
    {
        krom->yazdir();
    }
}

DNA::~DNA() 
//yıkıcı fonksiyon.
{
    Kromozom* temp;
    while (bas) 
    {
        temp = bas;
        bas = bas->sonraki; // Sonraki kromozoma geç
        delete temp; // Eski kromozomu sil
    }
}
