/**
* @file Oyun.cpp
* @description Amaci oyunu yonetmek, oyunu kuralina gore oynatmak.
* @course 1. Ogretim C grubu
* @assignment 3. ODEV
* @date 7.12.19
* @author TEK KISI YAPTI. KUTAY YAMAN kutay.yaman@ogr.sakarya.edu.tr 
*/
#include "Oyun.hpp"

Oyun::Oyun(string rakipDosyaYolu,string benimDosyaYolu):
rakipDosyaYolu(rakipDosyaYolu),benimDosyaYolu(benimDosyaYolu)
{
	benimSkor=0;
	rakipSkor=0;
	turSayisi=0;
}
void Oyun::oyunuBaslat()
{
	islemler=new Islemler(rakipDosyaYolu,benimDosyaYolu);
	islemler->dosyayiOku();
	islemler->soySayilariniGuncelle();
}
void Oyun::sonDurumuEkranaBas()
{
	islemler->soySayilariniGuncelle();
	cout<<"Benim Agac Postorder :"<<endl;
	islemler->getBenimBST()->postorder();
	cout<<endl;
	cout<<"Benim Agac Toplam Soy Sayisi : "<<islemler->getBenimBST()->toplamSoySayisiBul()<<endl;
	cout<<"---------------------------------------"<<endl<<endl;
	
	cout<<"Rakip Agac Postorder :"<<endl;
	islemler->getRakipBST()->postorder();
	cout<<endl;
	cout<<"Rakip Agac Toplam Soy Sayisi : "<<islemler->getRakipBST()->toplamSoySayisiBul()<<endl<<endl<<endl;
}
void Oyun::oyunuOynat()
{
	while(turSayisi<20) //skorları while icinde kontrol ettim.
	{
		turSayisi++;
		cout<<"------------Suanda "<<turSayisi<<". Turdayiz------------"<<endl<<endl;
		sonDurumuEkranaBas();
		BST* benimBST=islemler->getBenimBST();
		BST* rakipBST=islemler->getRakipBST();
		benimBST->soySayisiHesapla();
		rakipBST->soySayisiHesapla();
		int benimAgacToplamSoySayisi=benimBST->toplamSoySayisiBul();
		int rakipAgacToplamSoySayisi=rakipBST->toplamSoySayisiBul();
		if(benimAgacToplamSoySayisi<rakipAgacToplamSoySayisi){
			benimSkor++;
			benimBST->Ekle(rakipBST->enBuyuguSil());
			rakipBST->Ekle(benimBST->rootDegerGetir());
			benimBST->rootSil();
			cout<<"-- TEBRIKLER TURU KAZANDINIZ --"<<endl;
			cout<<"SKOR"<<endl;
			cout<<"Benim : "<<benimSkor<<endl;
			cout<<"Rakip : "<<rakipSkor<<endl;
		}
		else if(rakipAgacToplamSoySayisi<benimAgacToplamSoySayisi){
			rakipSkor++;
			rakipBST->Ekle(benimBST->enBuyuguSil());
			benimBST->Ekle(rakipBST->rootDegerGetir());
			rakipBST->rootSil();
			cout<<"-- TURU RAKIP KAZANDI UZGUNUM --"<<endl;
			cout<<"SKOR"<<endl;
			cout<<"Benim : "<<benimSkor<<endl;
			cout<<"Rakip : "<<rakipSkor<<endl<<endl<<endl<<endl;
		}
		else{
			benimBST->Ekle(rakipBST->rootDegerGetir());
			rakipBST->Ekle(benimBST->rootDegerGetir());
			benimBST->rootSil();
			rakipBST->rootSil();
			cout<<"-- TUR BERABERE BITTI --"<<endl;
			cout<<"SKOR"<<endl;
			cout<<"Benim : "<<benimSkor<<endl;
			cout<<"Rakip : "<<rakipSkor<<endl;
		}
		if(rakipSkor>=5 || benimSkor>=5)
			break;
		cout<<"Diger Tura Gecmek Icin Bir Tusa Basip Entera Basiniz..."<<endl;
		getchar();
		cin.ignore();
	}
	cout<<endl<<endl<<endl;
	cout<<"*****************-------------*****************"<<endl;
	cout<<"OYUN SONUCU"<<endl;
	cout<<"Benim : "<<benimSkor<<endl;
	cout<<"Rakip : "<<rakipSkor<<endl;
	cin.get();
}
Oyun::~Oyun()
{
	if(islemler!=NULL)
		delete islemler;
}