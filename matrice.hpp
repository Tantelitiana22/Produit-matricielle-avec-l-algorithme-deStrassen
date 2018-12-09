#ifndef MATRICE_HPP
#define MATRICE_HPP	


/************************************************
 Tae Young OH et RAKOTOARIJAONA Andrianarivo
 ***********************************************/

#include<iostream>


class matrice{

public:

double& operator()(int i, int j);
double operator ()(int i, int j) const;

friend matrice operator *(matrice const& A, matrice const& B);
friend matrice operator +(matrice const& A, matrice const& B);
friend matrice operator -(matrice const& A, matrice const& B);
friend std::ostream& operator<<(std::ostream& sortie, matrice const& A);

matrice(int N);
matrice& operator *=(matrice const& A);
matrice& operator -=(matrice const& A);
matrice& operator +=(matrice const& A);
matrice operator-(void);
matrice(matrice const& A);
~matrice();

void operator=(matrice const& A);


int get_n(void){
	return n;
}

private:
int n;
double *coeff;

};


/*******************************************************************
Prototype de strassen qui ne se trouve pas dans la classe matrice.
**********************************************************************/

matrice strassen(matrice A, matrice B);



#endif
