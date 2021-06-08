#include <iostream>
#include "lal.h"
#include <cstdlib>
 Matrix vectorArray2Matrix(Vector* vectorArray, int p, int m ){
      Matrix *matrix=(Matrix*)malloc(sizeof(Matrix)*(m*p));
  	int i,j;
  	for(i=0; i<p; ++i){
  		for(j=0; j<m; ++j){
  		matrix[p*i+j]=vectorArray[p*i+j];
	  }
	  	cout<<endl;
}
	  return *matrix;

}

int main(void){
	

cout<<"----------------------------------"<<endl;
  Matrix m1((double*)3,3,3);
  m1.matrixRandom();
  cout<<"-----matris1-----\n"<<endl;
  Matrix m2((double*)3,3,3);
  m2.matrixRandom();
  cout<<"-----matris2-----\n"<<endl;
  cout<<"\n";
  m1==m2;
  cout<<"\n";
  m1==m1;
  
  cout<<"\n";
 (m1+m2).print();
 cout<<"toplam \n";
 (m1-m2).print();
 cout<<"cikarma \n";
 (m1*m2).print();
 cout<<"carpma \n";
 
  
 
 cout<<"-----------Vektor-------------\n"<<endl;
 Vector v1((double*)4,4);
    v1.vectorRandom();
    cout<<"v1"<<endl;
     m2=m1*v1;  
     m2.print();
    cout<<"matrix vektor carpim \n"<<endl;;
    cout<<"\n";
   
    Vector v2((double*)4,4);
    v2.vectorRandom();
     cout<<"v2"<<endl;
   
    cout<<"\n";
    (v1+v2).yazdir();
    cout<<"toplam \n";
    (v1-v2).yazdir();
    cout<<"cikarma \n";
    (v1*v2).yazdir();
     cout<<"carpma \n";
     
    v1==v2;
    v1==v1;
    ++v1;
    v1.yazdir();
    cout<<"\n";
    v2++; 
    v2.yazdir();
    cout<<"\n";
   


cout<<"---------------------VectorArrayDizi--------------------"<<endl;	


    int m=2;
    int p=2;
  int i;
   Vector *vectorArray[m];
  
   for(i=0; i<m; i++){
   	vectorArray[i]=new Vector((double *)1,p);
		vectorArray[i]->vectorRandom();
	
       cout<<"\n";
}
 cout<<"---------------------VectorArray2Matrix---------------------"<<endl;
 
        vectorArray2Matrix(*vectorArray,p,m ).print();
    
 
  
  cout<<"\n";
  cout<<"---------------------MatrixVectorArrayDizi---------------------"<<endl;
  
Matrix **matrix=(Matrix **) malloc(sizeof(Matrix)*10);


 Matrix *mtr1=new Matrix((double*)9,3,3);
 Matrix *mtr2=new Matrix((double*)9,3,3);
 Vector *vect1=new Vector((double*)1,4);
 Vector *vect2=new Vector((double*)1,4);
 
 //matrix ve vector nesneleri oluþturup daha sonra diziye atadým
 
 matrix[0]=mtr1;
 matrix[1]=mtr2;
 matrix[2]=vect1;
 matrix[3]=vect2;
 
 for(int i=0; i<4; i++){
 	matrix[i]->matrixRandom();
 	cout<<"\n\t";
    
   
 }
 
 cout<<"-----------------------"<<endl;
 cout<<"matrix m1 norm-->"<<norm(m1)<<endl;
 cout<<"vector v1 norm-->"<<norm(v1)<<endl;
 
 
}

