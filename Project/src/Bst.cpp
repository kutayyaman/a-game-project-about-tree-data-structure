/**
* @file Bst.cpp
* @description Oyunda kullanilmasi gereken Binary Search Tree Veri Yapisini Olusturmak.
* @course 1. Ogretim C grubu
* @assignment 3. ODEV
* @date 7.12.19
* @author TEK KISI YAPTI. KUTAY YAMAN kutay.yaman@ogr.sakarya.edu.tr 
*/
#include "Bst.hpp"
#include <algorithm>

void BST::AraveEkle(Dugum*& altDugum,const int& yeni)
{
	if(altDugum==NULL) altDugum=new Dugum(yeni);
	else if(yeni<altDugum->getVeri())
		return AraveEkle(altDugum->sol,yeni);
	else if(yeni>altDugum->getVeri())
		return AraveEkle(altDugum->sag,yeni);
	else
		return AraveEkle(altDugum->sol,yeni); //eşitse sola yerleştiriyor
}
bool BST::AraveSil(Dugum*& altDugum,const int& eleman)
{
	if(altDugum==NULL)
		return false;
	if(altDugum->getVeri()==eleman)
		return DugumSil(altDugum);
	else if(eleman<altDugum->getVeri())
		return AraveSil(altDugum->sol,eleman);
	else
		return AraveSil(altDugum->sag,eleman);
}
bool BST::DugumSil(Dugum*& altDugum)
{
	Dugum* silinecekDugum=altDugum;
	if(altDugum->sag==NULL)
		altDugum=altDugum->sol;
	else if(altDugum->sol==NULL)
		altDugum=altDugum->sag;
	else
	{
		silinecekDugum=altDugum->sol;
		Dugum* ebeveynDugum=altDugum;
		while(silinecekDugum->sag!=NULL){
			ebeveynDugum=silinecekDugum;
			silinecekDugum=silinecekDugum->sag;
		}
		altDugum->setVeri(silinecekDugum->getVeri());
		if(ebeveynDugum==altDugum)
			altDugum->sol=silinecekDugum->sol;
		else{
			ebeveynDugum->sag=silinecekDugum->sol;
		}
	}
	delete silinecekDugum;
	return true;
}

void BST::inorder(Dugum* altDugum)
{
	if(altDugum!=NULL){
		inorder(altDugum->sol);
		cout<<"<"<<altDugum->getVeri()<<","<<altDugum->getSoySayisi()<<"> ";
		inorder(altDugum->sag);
	}
}
void BST::preorder(Dugum* altDugum)
{
	if(altDugum!=NULL){
		cout<<"<"<<altDugum->getVeri()<<","<<altDugum->getSoySayisi()<<"> ";		preorder(altDugum->sol);
		preorder(altDugum->sag);
	}
}
void BST::postorder(Dugum* altDugum)
{
	if(altDugum!=NULL){
		postorder(altDugum->sol);
		postorder(altDugum->sag);
		cout<<"<"<<altDugum->getVeri()<<","<<altDugum->getSoySayisi()<<"> ";
	}
}
int BST::Yukseklik(Dugum* altDugum){
	if(altDugum==NULL)
		return -1;
	return 1+max(Yukseklik(altDugum->sol),Yukseklik(altDugum->sag));
}
bool BST::Ara(Dugum* altDugum,const int& aranan){
	if(altDugum==NULL) return false;
	else if(altDugum->getVeri()==aranan) return true;
	else if(aranan<altDugum->getVeri())
		return Ara(altDugum->sol,aranan);
	else
		return Ara(altDugum->sag,aranan);
}
bool BST::BosMu()const
{
	return root==NULL;
}
void BST::Ekle(const int& yeni)
{
	AraveEkle(root,yeni);
}
void BST::Sil(const int& eleman)
{
	if(AraveSil(root,eleman)==false) throw "HATA";
}
bool BST::Ara(const int& aranan)
{
	return Ara(root,aranan);
}
void BST::inorder()
{
	inorder(root);
}
void BST::preorder()
{
	preorder(root);
}
void BST::postorder()
{
	postorder(root);
}
void BST::SeviyeyiYazdir(Dugum* altDugum,int seviye)
{
	if(altDugum==NULL) return;
	if(seviye==0)
		cout<<altDugum->getVeri()<<" ";
	else{
		SeviyeyiYazdir(altDugum->sol,seviye-1);
		SeviyeyiYazdir(altDugum->sag,seviye-1);
	}
}
void BST::levelorder()
{
	int h=Yukseklik();
	for(int seviye=0;seviye<=h;seviye++)
	{
		SeviyeyiYazdir(root,seviye);
	}
}
int BST::Yukseklik()
{
	return Yukseklik(root);
}
void BST::Temizle()
{
	while(!BosMu())
		DugumSil(root);
}
int BST::soySayisiHesapla(Dugum* hesaplanacakDugum)
{
	if(hesaplanacakDugum->sag==NULL && hesaplanacakDugum->sol==NULL)
	{
		hesaplanacakDugum->setSoySayisi(0);
		return 0;
	}
	else if(hesaplanacakDugum->sag==NULL)
	{
		hesaplanacakDugum->setSoySayisi(1 + soySayisiHesapla(hesaplanacakDugum->sol));
		//return 1+soySayisiHesapla(hesaplanacakDugum->sol);
		return hesaplanacakDugum->getSoySayisi();
	}
	else if(hesaplanacakDugum->sol==NULL)
	{
		hesaplanacakDugum->setSoySayisi(1 + soySayisiHesapla(hesaplanacakDugum->sag));
		//return 1+soySayisiHesapla(hesaplanacakDugum->sag);
		return hesaplanacakDugum->getSoySayisi();

	}
	else{
		hesaplanacakDugum->setSoySayisi(2 + soySayisiHesapla(hesaplanacakDugum->sag) + soySayisiHesapla(hesaplanacakDugum->sol));
		//return 2+soySayisiHesapla(hesaplanacakDugum->sag)+soySayisiHesapla(hesaplanacakDugum->sol);
		return hesaplanacakDugum->getSoySayisi();
	}
}
void BST::soySayisiHesapla()
{
	soySayisiHesapla(root);
}
int BST::toplamSoySayisiBul(Dugum* hesaplanacakDugum) //skor karsılastırılması yapmak icin
{
	if(hesaplanacakDugum==NULL)
		return 0;
	else if(hesaplanacakDugum->sag==NULL && hesaplanacakDugum->sol==NULL)
	{
		return hesaplanacakDugum->getSoySayisi();
	}
	else if(hesaplanacakDugum->sag==NULL)
	{
		return hesaplanacakDugum->getSoySayisi()+toplamSoySayisiBul(hesaplanacakDugum->sol);
	}
	else if(hesaplanacakDugum->sol==NULL)
	{
		return hesaplanacakDugum->getSoySayisi()+toplamSoySayisiBul(hesaplanacakDugum->sag);
	}
	else{
		return hesaplanacakDugum->getSoySayisi()+toplamSoySayisiBul(hesaplanacakDugum->sag)+toplamSoySayisiBul(hesaplanacakDugum->sol);
	}
}
int BST::toplamSoySayisiBul()
{
	return toplamSoySayisiBul(root);
}
void BST::rootSil()
{
	DugumSil(root);
}
int BST::enBuyuguSil()
{
	Dugum* dugum=root;
	while(dugum->sag!=NULL)
		dugum=dugum->sag;
	int deger=dugum->getVeri();
	AraveSil(root,deger);
	return deger;
}
int BST::rootDegerGetir()
{
	return root->getVeri();
}
BST::~BST(){
	Temizle();
}

