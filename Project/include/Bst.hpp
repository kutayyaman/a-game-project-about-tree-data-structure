/**
* @file Bst.hpp
* @description Oyunda kullanilmasi gereken Binary Search Tree Veri Yapisini Olusturmak.
* @course 1. Ogretim C grubu
* @assignment 3. ODEV
* @date 7.12.19
* @author TEK KISI YAPTI. KUTAY YAMAN kutay.yaman@ogr.sakarya.edu.tr 
*/
#ifndef BST_HPP
#define BST_HPP

#include "Dugum.hpp"

class BST{
	private:
		Dugum* root;
		
		void AraveEkle(Dugum*&,const int&);
		bool AraveSil(Dugum*&,const int&);
		bool DugumSil(Dugum*&);
		void SeviyeyiYazdir(Dugum*,int);
		void inorder(Dugum*);
		void preorder(Dugum*);
		void postorder(Dugum*);
		int Yukseklik(Dugum*);
		bool Ara(Dugum*,const int&);
		int soySayisiHesapla(Dugum*);
		int toplamSoySayisiBul(Dugum* hesaplanacakDugum);
	public:
		BST():root(NULL){
		}
		bool BosMu()const;
		void Ekle(const int&);
		void Sil(const int&);
		bool Ara(const int&);
		void inorder();
		void preorder();
		void postorder();
		void levelorder();
		int Yukseklik();
		void Temizle();
		void soySayisiHesapla();
		int toplamSoySayisiBul();
		int rootDegerGetir();
		void rootSil();
		int enBuyuguSil();
		~BST();
};

#endif