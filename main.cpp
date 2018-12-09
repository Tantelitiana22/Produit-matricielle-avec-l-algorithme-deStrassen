
/************************************************
 Tae Young OH et RAKOTOARIJAONA Andrianarivo
 ***********************************************/


#include<iostream>
#include"matrice.hpp"
#include<cstdlib>

using namespace std;

/******************************************************
 On vérifie si les deux méthodes donnent bien le meme 
                    resultat.
 * *****************************************************/
int main(void){
	
	 int n=20;
	
	matrice A(n);
	matrice B(n);
	matrice C(n);
	srand(1);
  for(int i=0; i<n;i++){
	 for(int j=0;j<n;j++){
		A(i,j)=rand()%101;
		B(i,j)=rand()%101;
	 }
  }
  
  cout<<"Resultat strassen"<<endl;
  C=strassen(A,B);
     cout<<C;
     
     cout<<"Produit naif"<<endl;
     cout<<A*B; 
      
	return 0;
}
