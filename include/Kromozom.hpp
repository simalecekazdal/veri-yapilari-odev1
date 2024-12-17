/**       
* @file          Kromozom.hpp
* @description   Kromozom.cpp iiçn gerekli olan başlık dosyasıdır.
* @course        İkinci öğretin B grubu
* @assignment    Birinci ödev
* @date          04.11.2024
* @author        Şimal Ece KAZDAL 
*/ 

#ifndef KROMOZOM_HPP
#define KROMOZOM_HPP

#include "Gen.hpp"

class Kromozom 
{
public:
    Gen* bas;           // Genlerin başı
    Kromozom* sonraki;  // Kromozomların bağlı liste yapısındaki sonraki eleman


    Kromozom();         // Constructor
    void ekle(char veri); // Gen ekleme fonksiyonu
    void yazdir() const;   // Genleri yazdırma fonksiyonu
    ~Kromozom();         // Destructor
};

#endif 
