/**       
* @file          Kromozom.cpp
* @description   Kromozom üzerinden ekleme, yazdırma ve yapıcı yıkıcı fonksiyonları burada tanımladım.
* @course        İkinci öğretin B grubu
* @assignment    Birinci ödev
* @date          04.11.2024
* @author        Şimal Ece KAZDAL 
*/ 

#include "Kromozom.hpp"
#include <iostream>

using namespace std;

Kromozom::Kromozom() : bas(nullptr), sonraki(nullptr) {} // Constructor

void Kromozom::ekle(char veri) 
{
    Gen* yeniGen = new Gen(veri); // Yeni Gen nesnesi oluşturuluyor
    if (!bas) 
    {
        bas = yeniGen; // İlk gen olarak ekleniyor
    } 
    else 
    {
        Gen* temp = bas;
        while (temp->sonraki) 
        {
            temp = temp->sonraki; // Son gene git
        }
        temp->sonraki = yeniGen; // Sonuna ekle
        yeniGen->onceki = temp; // Yeni genin önceki bağlantısını ayarla
    }
}

void Kromozom::yazdir() const 
{
    Gen* temp = bas;
    while (temp) 
    {
        cout << temp->veri << " "; // Genleri aralarında boşluk bırakarak yazdırmamızı sağlar
        temp = temp->sonraki; // Sonraki gene geçme işlemi
    }
    cout << endl;
}

Kromozom::~Kromozom() 
//yıkıcı fonksiyon
{
    Gen* temp;
    while (bas) 
    {
        temp = bas;
        bas = bas->sonraki; // Sonraki gene geç
        delete temp; // Eski geni sil
    }
}