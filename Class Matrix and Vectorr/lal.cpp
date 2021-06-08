#include <iostream>
#include "lal.h"
#include <cmath>
#include <time.h>
#include <cstdlib>
#include <typeinfo>
#include <stdio.h>
#include <string.h> 

using namespace std;

Matrix::Matrix(double* entries, int rows, int cols){

    this->rows=rows;
    this->cols=cols;
    this->entries=new double[rows*cols];
   
 
}
void Matrix::matrixRandom(void){
	
		for (int i = 0; i <this-> rows; ++i) {
				 cout<<"\n\t";
          for (int j = 0; j < this->cols; ++j) {
   	  entries[i* cols + j] =(rand() % 10) / 1.0; 
         	cout<<entries[i* cols + j];
        			 cout<<"\t";
}
}    
}

  void Matrix::print(void) {
  	int i,j;
  	
  	for (int i = 0; i <this-> rows; ++i) {
				 cout<<"\n\t";
          for (int j = 0; j < this->cols; ++j) {
          		cout<<entries[i* cols + j];
        			 cout<<"\t";
}
}    
     
}
    Matrix::~Matrix() {
 
	}


	 bool Matrix::operator==(const Matrix& m){
	 bool statement=true;
	 		for (int i = 0; i < rows * cols; ++i) {
	 		if(this->entries[i]==m.entries[i]){
	 	cout<<"esit";
	
	 	   return statement=true;
		 }else{
			cout<<"esit degil";
		return statement=false;

		 }
			 }
			 return statement;
		
      }  
	    
	 Matrix Matrix::operator+(const Matrix& m){
	 
	 	Matrix sum(entries, rows, cols);
	 	 if(this->rows!=m.rows || this->cols!=m.cols){
	 	 	cout<<"gecersiz boyut"<<endl;
	 	 return *this;
	 	  } 
		
	for (int i = 0; i < rows * cols; ++i) {
    sum.entries[i] =this->entries[i] + m.entries[i];
      } 
        return sum;
}
 Matrix Matrix::operator-(const Matrix& m){
	 	Matrix eksi(entries, rows, cols);
	 	if(this->rows!=m.rows || this->cols!=m.cols){
	 	 	cout<<"gecersiz boyut"<<endl;
	 	 return *this;
	 }
      for (int i = 0; i < rows * cols; ++i) {
    eksi.entries[i] = entries[i] - m.entries[i];
         
       }
      return eksi;
}

Matrix Matrix::operator*(const Matrix& m){
	
	 Matrix carp(entries,rows,cols);
       carp.rows=rows;
        carp.cols=m.cols;
      for(int i=0;i<carp.rows;i++)
    for(int j=0;j<carp.cols;j++)
                  {
           carp.entries[i* cols + j]=0;
           for(int k=0;k<cols;k++)
        carp.entries[cols*i+j]+=entries[cols*i+k]*m.entries[cols*k+j];
    } 
     return carp;
         
    
}

Matrix Matrix::operator*(const Vector& v){
    Matrix carp2(entries,rows,cols);
    int i,j;
    for(i=0; i<this->rows*this->cols; i++){
    	  for(j=0; j < v.rows; j++){
    	  	carp2.entries[i]+=this->entries[i]*v.entries[j];	
	}
    }
    return carp2;	
}

 
Vector::Vector(double* entries, int rows):Matrix(entries, rows, 1){
	 this->entries=new double[rows];

	 this->rows=rows;
		
		int i;
    double vec[rows];
    for(i=0; i<rows; i++){
	this->entries[i]=(rand() % 10) / 1.0; 
	
		
	}
	double deger=0;	
	for(i=0; i<rows; i++){
		deger+=vec[i]*vec[i];
	}
	double norm=sqrt(deger); 
 this->l2norm=norm; 
  
}
void Vector::vectorRandom(void){
	entries[rows];
  
    for (int i = 0; i < rows; ++i) {
        entries[i] = (rand() % 10) / 1.0; 
      cout<<entries[i];
        cout<<"\t ";
    }
   
}
     
  void Vector::yazdir(void){
  for (int i = 0; i < rows; ++i) {
       cout<<entries[i];
       cout<<"\t";
    }
   
}
 Vector Vector::operator+(const Vector& v){
	 	Vector sum(entries, rows);
	
   for (int i = 0; i < rows; ++i) {
    sum.entries[i] = entries[i] + v.entries[i];
    
	 }
     return sum; 
	
}
Vector Vector::operator-(const Vector& v){
	 	Vector eksi(entries, rows);
	 
   for (int i = 0; i < rows; ++i) {
    eksi.entries[i] = entries[i] - v.entries[i];
    
	 }
     return eksi; 
	
}

 Vector Vector::operator*(const Vector& v){
	 	Vector carp(entries, rows);
	 
   for (int i = 0; i < rows; ++i) {
    carp.entries[i] = entries[i] * v.entries[i];
    
	 }
     return carp; 
	
} 
 bool Vector::operator==(const Vector& v){
	 	bool statement=true;
	 	for (int i = 0; i < rows; ++i) {
	
	   if(this->entries[i]== v.entries[i]){
	   
	   	cout<<"esit"<<endl;
	   	return statement=true;
	   } else{
	   	cout<<"esit degil"<<endl;
	   	return statement=false;
	   }
	 	 }  
	 	 return statement;
      }  
      
      Vector Vector::operator++(){
      
      	for (int i = 0; i < rows; ++i) {
      		entries[i]++;
      
	 }
   
      	
	  }
	   Vector Vector::operator++(int){
      
      	for (int i = 0; i < rows; ++i) {
      		++entries[i];
      
	 }
   
      	
	  }

 Vector::~Vector() { }
 
 
 int Matrix::getRows()
{
	return this->rows;
}
   int Matrix::getCols()
{
	return this->cols;
}

  double* Matrix::getEntries()
{
 return this->entries;
}


    double norm(Matrix m){
	if(strcmp(typeid(m).name(),"6Matrix")==0){
		
		double norm=0;
		for(int i=0;i<m.getRows();i++){
			for(int j=0;j<m.getCols();j++){
				norm+=m.getEntries()[m.getCols()*i+j]*m.getEntries()[m.getCols()*i+j];
			}
		} 
		return sqrt(norm);
	}
	else{
		double norm=0;
		for(int i=0;i<m.getRows();i++){
			norm+=m.getEntries()[i]*m.getEntries()[i];
		}
		return sqrt(norm);
	}
}

 





