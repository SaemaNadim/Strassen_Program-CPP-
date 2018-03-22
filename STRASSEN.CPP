#include<iostream.h>
#include<conio.h>
void Strassen(int A[10][10],int B[10][10],int n,int C[10][10])
{
 if(n==1)
 {
  C[0][0]=A[0][0]*B[0][0];
 }
 else
 {
  int A11[10][10],A12[10][10],A21[10][10],A22[10][10];
  int B11[10][10],B12[10][10],B21[10][10],B22[10][10],i,j;
  int A1[10][10],A2[10][10],A5[10][10],A6[10][10],A7[10][10];
  int B1[10][10],B3[10][10],B4[10][10],B6[10][10],B7[10][10];
  int C11[10][10],C12[10][10],C21[10][10],C22[10][10];
  int P1[10][10],P2[10][10],P3[10][10],P4[10][10],P5[10][10],P6[10][10],P7[10][10];
  for(i=0;i<n/2;i++)
  {
   for(j=0;j<n/2;j++)
   {
    A11[i][j]=A[i][j];// cout<<"a11"<<A11[i][j];
    B11[i][j]=B[i][j]; // cout<<"b11"<<B11[i][j];
    A12[i][j]=A[i][j+n/2]; // cout<<"a12"<<A12[i][j];
    B12[i][j]=B[i][j+n/2];  // cout<<"b12"<<B12[i][j];
    A21[i][j]=A[i+n/2][j];  // cout<<"a21"<<A21[i][j];
    B21[i][j]=B[i+n/2][j];  // cout<<"b21"<<B21[i][j];
    A22[i][j]=A[i+n/2][j+n/2];// cout<<"a22"<<A22[i][j];
    B22[i][j]=B[i+n/2][j+n/2]; // cout<<"b22"<<B22[i][j];
   }
  }
  for(i=0;i<n/2;i++)
  {
   for(j=0;j<n/2;j++)
   {
    A1[i][j]=A11[i][j]+A22[i][j];    // cout<<"a1 "<<A1[i][j]<<" ";
    B1[i][j]=B11[i][j]+B22[i][j];    // cout<<"b1 "<<B1[i][j]<<" ";
    A2[i][j]=A21[i][j]+A22[i][j];    // cout<<"a2 "<<A2[i][j]<<" ";
    B3[i][j]=B12[i][j]-B22[i][j];    // cout<<"b3 "<<B3[i][j]<<" ";
    B4[i][j]=B21[i][j]-B11[i][j];    // cout<<"b4 "<<B4[i][j]<<" ";
    A5[i][j]=A11[i][j]+A12[i][j];    // cout<<"a5 "<<A5[i][j]<<" ";
    A6[i][j]=A21[i][j]-A11[i][j];    // cout<<"a6 "<<A6[i][j]<<" ";
    B6[i][j]=B11[i][j]+B12[i][j];    // cout<<"b6 "<<B6[i][j]<<" ";
    A7[i][j]=A12[i][j]-A22[i][j];    // cout<<"a7 "<<A7[i][j]<<" ";
    B7[i][j]=B21[i][j]+B22[i][j];    // cout<<"b7 "<<B7[i][j]<<" ";
   }
  }
  Strassen(A1,B1,n/2,P1);
  Strassen(A2,B11,n/2,P2);
  Strassen(A11,B3,n/2,P3);
  Strassen(A22,B4,n/2,P4);
  Strassen(A5,B22,n/2,P5);
  Strassen(A6,B6,n/2,P6);
  Strassen(A7,B7,n/2,P7);
  for(i=0;i<n/2;i++)
  {
   for(j=0;j<n/2;j++)
   {
    C11[i][j]=P1[i][j]+P4[i][j]-P5[i][j]+P7[i][j];// cout<<"C11 "<<C11[i][j];
    C12[i][j]=P3[i][j]+P5[i][j];                   // cout<<"c12 "<<C12[i][j];
    C21[i][j]=P2[i][j]+P4[i][j];                    // cout<<"c21 "<<C21[i][j];
    C22[i][j]=P1[i][j]+P3[i][j]-P2[i][j]+P6[i][j];   // cout<<"c22 "<<C22[i][j];
   }
  }
  for(i=0;i<n/2;i++)
  {
   for(j=0;j<n/2;j++)
   {
    C[i][j]=C11[i][j]; // cout<<"c-11 "<<C11[i][j];
    C[i][j+n/2]=C12[i][j];  //cout<<"c-12 "<<C12[i][j];
    C[i+n/2][j]=C21[i][j];  // cout<<"c-21 "<<C21[i][j];
    C[i+n/2][j+n/2]=C22[i][j];  // cout<<"c-22 "<<C22[i][j];
   }
  }
 }
}
void main()
{
clrscr();
int i,j,n,A[10][10],B[10][10],C[10][10];
cout<<"Enter the order of the matrix 'n' where n can be written as a power of 2.\n";
cin>>n;
cout<<"Enter the first matrix of order nxn\n";
for(i=0;i<n;i++)
 for(j=0;j<n;j++)
  cin>>A[i][j];
cout<<"Enter the second matrix also of the same order.\n";
for(i=0;i<n;i++)
 for(j=0;j<n;j++)
  cin>>B[i][j];
Strassen(A,B,n,C);
cout<<"The result is :\n";
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
  {
   cout<<C[i][j]<<" ";
  }
  cout<<endl;
 }
getch();
}