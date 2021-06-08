#define LAL_H_


using namespace std;
class Vector;

class Matrix {

public:
   Matrix(double* , int, int);
   void print(void);
   ~Matrix(); 
   int getRows();
   int getCols();
   double* getEntries();
   void matrixRandom(void);
   Matrix operator+(const Matrix& m);
   Matrix operator-(const Matrix& m);
   Matrix operator*(const Matrix& m);
   bool operator==(const Matrix& m);
   Matrix operator*(const Vector& v);

  
protected:
   int cols;
   double *entries;
   int rows;
  
 
};

class Vector : public Matrix{
	public:
   Vector(double* , int);
   void vectorRandom(void);      
   void yazdir(void);
   ~Vector();  
    Vector operator+(const Vector& v);
    Vector operator-(const Vector& v);
    Vector operator*(const Vector& v);
    Vector operator++();
    Vector operator++(int);
    bool operator==(const Vector& v);
private:
  double l2norm;
 
    
}; 

double norm(Matrix m);




