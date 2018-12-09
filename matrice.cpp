

/************************************************
 Tae Young OH et RAKOTOARIJAONA Andrianarivo
 ***********************************************/


#include<iostream>
#include"matrice.hpp"
#include<cstdlib>

/******************************************************************
 *                  Pour afficher des matrices 
 *****************************************************************/

std::ostream& operator <<(std::ostream& sortie,matrice const& A){

    for(int i=0;i<A.n;i++){
	   for(int j=0;j<A.n;j++){ 
	    sortie<<A.coeff[i*A.n+j]<<"  ";
	   }
	   sortie<<std::endl;
    }
   return sortie;
}
	/********************************************************
	             Constructeur par defaut
	**********************************************************/
	matrice::matrice(int N=4):n(N){
          
		coeff=new double[n*n];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
			   if(i==j){
				   coeff[i*n+j]=1;
			   }else{
				   coeff[i*n+j]=0;
			   }	
			}
		 }
	}


/********************************************************
	  Pour donner une valeur à la case (i,j)
**********************************************************/

double& matrice::operator ()(int i, int j){

return coeff[i*n+j];
}


/********************************************************
	  Pour recuperer la valeur dans la case (i,j)
**********************************************************/

double matrice::operator ()(int i, int j) const {
	
	return coeff[i*n+j];
	
}


/********************************************************
	  Algorithme produit Naif
**********************************************************/
matrice operator *(matrice const& A, matrice const& B){

matrice C(A.n);
int j=0;
int i=0;
int k=0;
double res;

   if(A.n!=B.n){
     std::cout<<"les matrices ne sont pas de meme taille\n";
     std::cout<<"Dans le projet, on veut faire le produit de deux matrice de meme taille!\n";
     exit(1);
   }else{
	for(i=0;i<C.n;i++){

	     
	     for( j=0;j<C.n;j++){  
		   res=0;
	       for(k=0;k<C.n;k++){
		    res=res+A.coeff[i*C.n+k]*B.coeff[k*C.n+j];   
	       }
	       C.coeff[i*C.n+j]=res;
         }
	   
    }   
  }
  
  return C;
}


/********************************************************
	Les opérateurs += , -= et *=
**********************************************************/
//operatuer *=
matrice& matrice::operator *=(matrice const& A){
	
	*this=*this*A;
	return *this;
}

matrice& matrice::operator -=(matrice const& A){
	
  *this=*this-A;
  	return *this;
}

matrice& matrice::operator +=(matrice const& A){
	
  *this=*this+A;
  	return *this;
}	

 
/********************************************************
	             Somme de deux matrice
**********************************************************/

matrice operator +(matrice const& A,matrice const& B){

matrice D(A.n);

if(A.n!=B.n){
 std::cout<<"Erreur! somme de deux matrice de taille differente\n";
  exit(1);
}

for(int i=0;i<D.n;i++){
	   for(int j=0;j<D.n;j++){
		   D(i,j)=A(i,j)+B(i,j);
	   }	      
   }
   return D;
}

//operateur -A:

matrice matrice::operator-(void){
   matrice A(n);
    for(int i=0;i<n;i++){
	   for(int j=0;j<n;j++){
		   A.coeff[i*n+j]=-coeff[i*n+j];
	   }
	
   }
   return A;
}

matrice operator -(matrice const& A, matrice const& B){
	matrice C(A);
	matrice D(B);
	return C+(-D);
	
}

/*******************************************
constructeur de copie
*********************************************/
matrice::matrice(matrice const& A){
	n=A.n;
	coeff=new double[n*n];
	 for(int i=0;i<n;i++){
	   for(int j=0;j<n;j++){
		   coeff[i*n+j]=A.coeff[i*n+j];   
	   }
	      
   }
	
}


//Destructeur
matrice::~matrice(){
delete[] coeff;
}

//Operateur d'affectation 
void matrice::operator =(matrice const& A){
   if(n!=A.n){
    n=A.n;
    delete[] coeff;
    coeff=new double[n*n];
   }
   
   for(int i=0;i<n;i++){
	   for(int j=0;j<n;j++){
		   coeff[i*n+j]=A.coeff[i*n+j];   
	   }
	      
   }
}
