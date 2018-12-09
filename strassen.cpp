
/************************************************
 Tae Young OH et RAKOTOARIJAONA Andrianarivo
 ***********************************************/


#include<iostream>
#include"matrice.hpp"
#include<cstdlib>

using namespace std;

/*****************************************************************
 Dans cette partie, on a l'algorithme de Strassen, et pour le realiser 
               nous avons utilises la recursivite,
 ********************************************************************/
matrice strassen(matrice A, matrice B){



if(A.get_n()!=B.get_n()){
	
	
  cout<<"les deux matrices ne sont pas de meme taille\n";
  cout<<"Dans le projet, on veut faire le produit de deux matrice de meme taille!\n";

 exit(1);
}

int n=A.get_n();

   if(n%2==1 && n<17){
     return A*B;
   }

int m=n/2;

     matrice A11(m);
     matrice A12(m);
     matrice A21(m);
     matrice A22(m);
     
     matrice B11(m);
     matrice B12(m);
     matrice B21(m);
     matrice B22(m);
     
     matrice P1(m);
     matrice P2(m);
     matrice P3(m);
     matrice P4(m);
     matrice P5(m);
     matrice P6(m);
     matrice P7(m);
     
     matrice res(n);
     
     /********************************************
      On divise les matrices A et B en 4 bloques.
      * ******************************************/
	for(int i=0;i<m;i++){
	   for(int j=0;j<m;j++){
		   
		     A11(i,j)=A(i,j);
		     A12(i,j)=A(i,j+m);
		     A21(i,j)=A(i+m,j);
		     A22(i,j)=A(i+m,j+m);
		     
		     B11(i,j)=B(i,j);
		     B12(i,j)=B(i,j+m);
		     B21(i,j)=B(i+m,j);
		     B22(i,j)=B(i+m,j+m);
      }
    }
    
     /****************************************************
      On re applique par recursivite Strassen afin 
       d'eviter de faire le produit naif
      ***************************************************/   
               
    P1=strassen(A11+A22,B11+B22);
    P2=strassen(A21+A22,B11);
    P3=strassen(A11,B12-B22);
    P4=strassen(A22,B21-B11);
    P5=strassen(A11+A12,B22);
    P6=strassen(A21-A11,B11+B12);
    P7=strassen(A12-A22,B21+B22);
    
    
    /**********************************
     Ici res va etre le resultat du 
            produit matriciel
     **********************************/
    for (int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			res(i,j)=P1(i,j)+P4(i,j)-P5(i,j)+P7(i,j);
			res(i,j+m)=P3(i,j)+P5(i,j);
			res(i+m,j)=P2(i,j)+P4(i,j);
			res(i+m,j+m)=P1(i,j)-P2(i,j)+P3(i,j)+P6(i,j);
		}
   }
    
 return res;   
}
