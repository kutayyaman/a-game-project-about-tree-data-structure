/**
* @file Oyun.hpp
* @description Amaci oyunu yonetmek, oyunu kuralina gore oynatmak.
* @course 1. Ogretim C grubu
* @assignment 3. ODEV
* @date 7.12.19
* @author TEK KISI YAPTI. KUTAY YAMAN kutay.yaman@ogr.sakarya.edu.tr 
*/
#ifndef OYUN_HPP
#define OYUN_HPP

#include "Islemler.hpp"

class Oyun{
	private:
		Islemler* islemler;
		string rakipDosyaYolu;
		string benimDosyaYolu;
		int benimSkor;
		int rakipSkor;
		int turSayisi;
	public:
		Oyun(string,string);
		void oyunuBaslat();
		void sonDurumuEkranaBas();
		void oyunuOynat();
		~Oyun();
};


#endif