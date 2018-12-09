
/************************************************
 Tae Young OH et RAKOTOARIJAONA Andrianarivo
 ***********************************************/



#include<iostream>
#include"matrice.hpp"
#include<cstdlib>
#include<ctime>
#include<fstream>

using namespace std;

/****************************************************
                  Pour le produit naif.
   On a fait plusieurs test avec des valeurs de n
   ainsi que des pas differents, mais ce qui est utilise
   ici n'est qu'un exemple parmis les tests qu'on a fait.
    ON A PRIS LE MEME PAS ET MEME n QUE DANS test1.cpp
 *****************************************************/
int main(void){
	
   int n=200;
	int pas=200;
	
	ofstream out("test2.dat");

	for(int i=1; i<=7;i++){
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
  
  
   /***********************************************
   Ici, on calcul l'ecart du temps entre le debut
   de l'execution et la fin et on enregistre les 
       resultats dans un fichier.dat
   ************************************************/
   
  double temps_init,temps_fi;
  temps_init=clock();
   C=A*B;
  temps_fi=clock();
  out<<n<<" "<<(temps_fi-temps_init)/CLOCKS_PER_SEC<<endl;
   n+=pas;
  }
  out.close();
  
  
  
	return 0;
}
