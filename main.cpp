#include <iostream>

using namespace std;
struct matrix{
    int* data;
    int row,col;
};
void createMatrix (int row, int col, int num[], matrix& mat);
istream& operator>> (istream& in, matrix& mat);
ostream& operator<< (ostream& out, matrix& mat);
matrix operator+  (matrix mat1, matrix mat2); // Add if same dimensions
matrix operator-  (matrix mat1, matrix mat2); // Sub if same dimensions
matrix operator*  (matrix mat1, matrix mat2); // Multi if col1 == row2
matrix operator+  (matrix mat1, int scalar);  // Add a scalar
matrix operator-  (matrix mat1, int scalar);  // Subtract a scalar
matrix operator*  (matrix mat1, int scalar);  // Multiple by scalar
matrix operator+= (matrix& mat1, matrix mat2); // mat1 changes & return
					    // new matrix with the sum
matrix operator-= (matrix& mat1, matrix mat2); // mat1 changes + return new
					     // matrix with difference
matrix operator+= (matrix& mat, int scalar);   // change mat & return new matrix
matrix operator-= (matrix& mat, int scalar);   // change mat & return new matrix
void   operator++ (matrix& mat);   	// Add 1 to each element ++mat
void   operator-- (matrix& mat);    	// Sub 1 from each element --mat


int main()
{
    matrix mat1,mat2,mat;
    cin>>mat1;//>>mat2;
    mat1+=mat1;
    cout << mat1 ;
    return 0;
}
istream& operator>> (istream& in, matrix& mat){
    cout<<"Enter the number of rows : ";
    in>>mat.row;
    cout<<"Enter the number of cols : ";
    in>>mat.col;
    mat.data= new int [mat.row*mat.col];
    for(int i=0;i<mat.row;i++){
        cout<<"Enter the data of row no."<<i+1<<" : ";
        for(int j=0;j<mat.col;j++){
            in>>mat.data[i*mat.row+j];
        }
    }
    return in;
}
ostream& operator<< (ostream& out, matrix& mat){
out<<"the data of matrix is : \n";
    for(int i=0;i<mat.row;i++){
        for(int j=0;j<mat.col;j++){
            out<<mat.data[i*mat.row+j]<<" ";
        }
        out<<endl;
    }
    return out;
}
matrix operator+  (matrix mat1, matrix mat2){
    matrix newMat;
    newMat.row=mat1.row;
    newMat.col=mat1.col;
    newMat.data= new int [newMat.col*newMat.row];
    for(int i=0;i<newMat.row;i++){
        for(int j=0;j<newMat.col;j++){
            newMat.data[i*newMat.row+j]=mat1.data[i*newMat.row+j]+mat2.data[i*newMat.row+j];
        }
    }
    return newMat;
}
matrix operator-  (matrix mat1, matrix mat2){
    matrix newMat;
    newMat.row=mat1.row;
    newMat.col=mat1.col;
    newMat.data= new int [newMat.col*newMat.row];
    for(int i=0;i<newMat.row;i++){
        for(int j=0;j<newMat.col;j++){
            newMat.data[i*newMat.row+j]=mat1.data[i*newMat.row+j]-mat2.data[i*newMat.row+j];
        }
    }
    return newMat;
}
matrix operator*  (matrix mat1, matrix mat2){
    matrix newMat;
    newMat.row=mat2.row;
    newMat.col=mat1.col;
    newMat.data= new int [newMat.col*newMat.row];
    for(int i=0,a=0;i<newMat.row;i++,a+=2){
        for(int j=0;j<newMat.col;j++){
            newMat.data[i*newMat.row+j]=mat1.data[a]*mat2.data[j]+mat1.data[a+1]*mat2.data[j+mat2.col];
        }
    }
    return newMat;
}
matrix operator+  (matrix mat1, int scalar){
    matrix newMat;
    newMat.row=mat1.row;
    newMat.col=mat1.col;
    newMat.data= new int [newMat.col*newMat.row];
    for(int i=0;i<newMat.row;i++){
        for(int j=0;j<newMat.col;j++){
            newMat.data[i*newMat.row+j]=mat1.data[i*newMat.row+j]+scalar;
        }
    }
    return newMat;
}
matrix operator-  (matrix mat1, int scalar){
    matrix newMat;
    newMat.row=mat1.row;
    newMat.col=mat1.col;
    newMat.data= new int [newMat.col*newMat.row];
    for(int i=0;i<newMat.row;i++){
        for(int j=0;j<newMat.col;j++){
            newMat.data[i*newMat.row+j]=mat1.data[i*newMat.row+j]-scalar;
        }
    }
    return newMat;
}
matrix operator*  (matrix mat1, int scalar){
    matrix newMat;
    newMat.row=mat1.row;
    newMat.col=mat1.col;
    newMat.data= new int [newMat.col*newMat.row];
    for(int i=0;i<newMat.row;i++){
        for(int j=0;j<newMat.col;j++){
            newMat.data[i*newMat.row+j]=mat1.data[i*newMat.row+j]*scalar;
        }
    }
    return newMat;

}
matrix operator+= (matrix& mat1, matrix mat2){
    for(int i=0;i<mat1.row;i++){
        for(int j=0;j<mat1.col;j++){
            mat1.data[i*mat1.row+j]+=mat2.data[i*mat1.row+j];
        }
    }
}
matrix operator-= (matrix& mat1, matrix mat2){
    for(int i=0;i<mat1.row;i++){
        for(int j=0;j<mat1.col;j++){
            mat1.data[i*mat1.row+j]-=mat2.data[i*mat1.row+j];
        }
    }
}
matrix operator+= (matrix& mat1, int scalar){
    for(int i=0;i<mat1.row;i++){
        for(int j=0;j<mat1.col;j++){
            mat1.data[i*mat1.row+j]+=scalar;
        }
    }
}
matrix operator-= (matrix& mat1, int scalar){
    for(int i=0;i<mat1.row;i++){
        for(int j=0;j<mat1.col;j++){
            mat1.data[i*mat1.row+j]-=scalar;
        }
    }
}
void   operator++ (matrix& mat1){
    for(int i=0;i<mat1.row;i++){
        for(int j=0;j<mat1.col;j++){
            mat1.data[i*mat1.row+j]+=1;
        }
    }
}
void   operator-- (matrix& mat1){
    for(int i=0;i<mat1.row;i++){
        for(int j=0;j<mat1.col;j++){
            mat1.data[i*mat1.row+j]-=1;
        }
    }
}
