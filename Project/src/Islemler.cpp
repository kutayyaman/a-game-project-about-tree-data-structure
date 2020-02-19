/**
* @file Islemler.cpp
* @description AMACI BST OLUSTURMAK VE DOSYADAN OKUMA ISLEMLERINI GERCEKLESTIRMEK
* @course 1. Ogretim C grubu
* @assignment 3. ODEV
* @date 7.12.19
* @author TEK KISI YAPTI. KUTAY YAMAN kutay.yaman@ogr.sakarya.edu.tr 
*/
#include "Islemler.hpp"
#include <sstream>

Islemler::Islemler(string rakipDosyaYolu,string benimDosyaYolu):
rakipDosyaYolu(rakipDosyaYolu),benimDosyaYolu(benimDosyaYolu)
{
}
BST* Islemler::getRakipBST()const{
	return rakipBST;
}
BST* Islemler::getBenimBST()const{
	return benimBST;
}
void Islemler::dosyayiOku(){
	rakipBST=new BST();
	benimBST=new BST();
	fstream rakipDosya;
	fstream benimDosya;
	rakipDosya.open(rakipDosyaYolu,ios::in);
	if(rakipDosya.is_open())
	{
		int eleman;
		while(rakipDosya>>eleman)
		{
			rakipBST->Ekle(eleman);
		}
	}
	rakipDosya.close();
	benimDosya.open(benimDosyaYolu,ios::in);
	if(benimDosya.is_open())
	{
		int eleman;
		while(benimDosya>>eleman)
		{
			benimBST->Ekle(eleman);
		}
	}
	benimDosya.close();
}
void Islemler::soySayilariniGuncelle()
{
	rakipBST->soySayisiHesapla();
	benimBST->soySayisiHesapla();
}
Islemler::~Islemler()
{
	delete rakipBST;
	delete benimBST;
}