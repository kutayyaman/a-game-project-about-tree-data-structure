/**
* @file Dugum.cpp
* @description Binary Search Tree'de kullanilacak olan dugum.
* @course 1. Ogretim C grubu
* @assignment 3. ODEV
* @date 7.12.19
* @author TEK KISI YAPTI. KUTAY YAMAN kutay.yaman@ogr.sakarya.edu.tr 
*/
#include "Dugum.hpp"

int Dugum::getVeri()const
{
	return this->veri;
}
void Dugum::setVeri(const int& veri)
{
	this->veri=veri;
}
int Dugum::getSoySayisi(){
	return soySayisi;
}
void Dugum::setSoySayisi(const int& soySayisi)
{
	this->soySayisi=soySayisi;
}
