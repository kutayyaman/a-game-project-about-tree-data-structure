/**
* @file Islemler.hpp
* @description AMACI BST OLUSTURMAK VE DOSYADAN OKUMA ISLEMLERINI GERCEKLESTIRMEK
* @course 1. Ogretim C grubu
* @assignment 3. ODEV
* @date 7.12.19
* @author TEK KISI YAPTI. KUTAY YAMAN kutay.yaman@ogr.sakarya.edu.tr 
*/
#ifndef ISLEMLER_HPP
#define ISLEMLER_HPP

#include "Bst.hpp"
#include<fstream>
#include<string>

class Islemler
{
	private:
		string rakipDosyaYolu;
		string benimDosyaYolu;
		BST* rakipBST;
		BST* benimBST;
	public:
		Islemler(string,string);
		BST* getRakipBST()const;
		BST* getBenimBST()const;
		void dosyayiOku();
		void soySayilariniGuncelle();
		~Islemler();
};

#endif