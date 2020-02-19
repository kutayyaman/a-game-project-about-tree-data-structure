/**
* @file Main.cpp
* @description Oyun isimli classımdan nesne olusturarak oyunu baslatıyor.
* @course 1. Ogretim C grubu
* @assignment 3. ODEV
* @date 7.12.19
* @author TEK KISI YAPTI. KUTAY YAMAN kutay.yaman@ogr.sakarya.edu.tr 
*/
#include "Oyun.hpp"
int main()
{
	Oyun* oyun=new Oyun("rakip.txt","benim.txt");
	oyun->oyunuBaslat();
	oyun->oyunuOynat();
	delete oyun;
	
	
	cin.get();
	return 0;
}