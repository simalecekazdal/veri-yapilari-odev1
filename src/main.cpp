/**       
* @file          Main.cpp
* @description   Tüm işlemlerin birleşiği ve bütün olarak çalışmasını sağlayan kısım burası.
*                Diğer dosyalarda tanımladığım fonksiyonları burada çalıştırıyorum.
*                Dosya okumayla başlayıp menüyü oluşturduğum ve kullanıcı ile asıl bağlantı kurulan kısım burası.
* @course        İkinci öğretin B grubu
* @assignment    Birinci ödev
* @date          04.11.2024
* @author        Şimal Ece KAZDAL 
*/

#include "DNA.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <locale>
#include <limits>

using namespace std;

void dosyadanOku(DNA &dna, const string &dosyaAdi) 
//burada dosya açılıp okunur gen ve kromozomlar oluşturulur. işlem tamamlandığında ise dosya kapatılır.
{
    ifstream dosya(dosyaAdi);
    string satir;

    while (getline(dosya, satir)) 
    {
        stringstream ss(satir);
        char gen;
        Kromozom* kromozom = new Kromozom();
        
        while (ss >> gen) 
        {
            kromozom->ekle(gen);
        }
        dna.ekle(kromozom);
    }
    dosya.close();
}

int main() 
{
    setlocale(LC_ALL, "Turkish"); // ekrana Türkçe karakter yazımını sağlamak için

    DNA dna;
    dosyadanOku(dna, "Dna.txt");

    int secim;
    do 
    {
        cout << "1- Caprazlama\n2- Mutasyon\n3- Otomatik Islemler\n4- Ekrana Yaz\n5- Cikis\nSecim: "; // menü
        cin >> secim;

        // Eğer cin başarısız olursa (örneğin sayı dışında bir karakter girilmişse)
        if (cin.fail()) {
            cin.clear(); // Hata bayrağını temizle
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Geçersiz girdiyi temizle
            cout << "Gecersiz bir deger girdiniz, lutfen 1-5 arasi bir sayi giriniz." << endl;
            continue; // Döngünün başına dön
        }

        switch (secim) 
        {
            case 1: 
            {
                int idx1, idx2;
                cout << "Caprazlanacak kromozom indekslerini girin: ";
                cin >> idx1 >> idx2;
                dna.caprazla(idx1, idx2);
                cout << "Islem tamamlandi." << endl;
                
                // Alt menü
                char altSecim;
                do {
                    cout << "a) Son durumu ekrana yazdir\nb) Ana menuye don\nSecim: ";
                    cin >> altSecim;
                    if (altSecim == 'a') {
                        dna.yazdir();
                    } else if (altSecim == 'b') {
                        break;
                    } else {
                        cout << "Gecersiz secim, lutfen a veya b giriniz." << endl;
                    }
                } while (altSecim != 'b');
                break;
            }
            case 2: 
            {
                int kromIdx, genIdx;
                cout << "Mutasyon icin kromozom ve gen indeksini girin: ";
                cin >> kromIdx >> genIdx;
                dna.mutasyon(kromIdx, genIdx);
                cout << "Islem tamamlandi." << endl;

                // Alt menü
                char altSecim;
                do {
                    cout << "a) Son durumu ekrana yazdir\nb) Ana menuye don\nSecim: ";
                    cin >> altSecim;
                    if (altSecim == 'a') {
                        dna.yazdir();
                    } else if (altSecim == 'b') {
                        break;
                    } else {
                        cout << "Gecersiz secim, lutfen a veya b giriniz." << endl;
                    }
                } while (altSecim != 'b');
                break;
            }
            case 3: 
            {
                dna.otomatikIslem("Islemler.txt");
                cout << "Islem tamamlandi." << endl;

                // Alt menü
                char altSecim;
                do {
                    cout << "a) Son durumu ekrana yazdir\nb) Ana menuye don\nSecim: ";
                    cin >> altSecim;
                    if (altSecim == 'a') {
                        dna.yazdir();
                    } else if (altSecim == 'b') {
                        break;
                    } else {
                        cout << "Gecersiz secim, lutfen a veya b giriniz." << endl;
                    }
                } while (altSecim != 'b');
                break;
            }
            case 4: 
            {
                dna.ozelYazdir();
                break;
            }
            case 5:
                cout << "Cikis yapiliyor...\n";
                break;
            default:
                cout << "Gecersiz bir deger girdiniz, lutfen 1-5 arasi bir deger giriniz." << endl;
                break;
        }

    } 
    while (secim != 5);

    return 0;
}
