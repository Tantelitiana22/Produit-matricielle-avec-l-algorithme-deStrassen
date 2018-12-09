
/************************************************
 Tae Young OH et RAKOTOARIJAONA Andrianarivo
 ***********************************************/


#include<iostream>
#include"matrice.hpp"
#include<cstdlib>
#include<ctime>
#include<fstream>

using namespace std;

/**************************************************
       L'algorithme de Strassen.
   On a fait plusieurs test avec des valeurs de n
   ainsi que des pas differents, mais ce qui est utilise
   ici n'est qu'un exemple parmis les tests qu'on a fait
   
 *****************************************************/
 
int main(void){
		
	int n=200;
	int pas=200;
	ofstream out("test1.dat");

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
   Pour chaque n correspond a un temps d'execution t.
   ************************************************/
  double temps_init,temps_fi;
 
  temps_init=clock();
  C=strassen(A,B);
  temps_fi=clock();
  out<<n<<" "<<(temps_fi-temps_init)/CLOCKS_PER_SEC<<endl;

   n+=pas;
 
  }

	return 0;
}

