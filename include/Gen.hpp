/**       
* @file          Gen.hpp
* @description   Gen.cpp iiçn gerekli olan başlık dosyasıdır.
* @course        İkinci öğretin B grubu
* @assignment    Birinci ödev
* @date          04.11.2024
* @author        Şimal Ece KAZDAL 
*/ 

#ifndef GEN_HPP
#define GEN_HPP

class Gen 
{
public:
    char veri;         // Gen verisi
    Gen* sonraki;      // Sonraki gen
    Gen* onceki;       // Önceki gen (iki yönlü bağlantı)

    // Constructor
    Gen(char v) : veri(v), sonraki(nullptr), onceki(nullptr) {}
};

#endif 
