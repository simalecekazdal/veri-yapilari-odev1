/**       
* @file          DNA.hpp
* @description   DNA.cpp iiçn gerekli olan başlık dosyasıdır.
* @course        İkinci öğretin B grubu
* @assignment    Birinci ödev
* @date          04.11.2024
* @author        Şimal Ece KAZDAL 
*/ 

#ifndef DNA_HPP
#define DNA_HPP

#include "Kromozom.hpp"
#include <string>

class DNA 
{
public:
    Kromozom* bas;  // Kromozomların başı

    DNA();  // Constructor
    void ekle(Kromozom* kromozom); //Kromozom ekleme
    void caprazla(int idx1, int idx2); //Çaprazlama İşlemi
    void mutasyon(int kromIdx, int genIdx); //Mutasyon işlemi

    // Islemler.txt dosyasından otomatik işlemleri gerçekleştir
    void otomatikIslem(const std::string& dosyaAdi);

    // Kromozomları özel bir yazdırma yöntemiyle ekrana yazdır
    void ozelYazdir() const;

    void yazdir() const; //Mevcut son durumu ekrana yazdırır
    ~DNA(); //Yıkıcı fonksiyon
};

#endif 
