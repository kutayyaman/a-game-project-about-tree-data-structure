/**
* @file Dugum.hpp
* @description Binary Search Tree'de kullanilacak olan dugum.
* @course 1. Ogretim C grubu
* @assignment 3. ODEV
* @date 7.12.19
* @author TEK KISI YAPTI. KUTAY YAMAN kutay.yaman@ogr.sakarya.edu.tr 
*/
#ifndef DUGUM_HPP
#define DUGUM_HPP

#include<iostream>
#include<cmath>
using namespace std;

class Dugum{
	private:
		int veri;
		int soySayisi;
	public:
		Dugum* sol;
		Dugum* sag;
		Dugum(const int& veri, const int& soySayisi =0, Dugum* sol = NULL, Dugum* sag = NULL) :
		veri(veri), soySayisi(soySayisi), sol(sol), sag(sag)
		{
		}
		int getVeri()const;
		void   setVeri(const int&); 
		int getSoySayisi();
		void setSoySayisi(const int&);
};


#endif