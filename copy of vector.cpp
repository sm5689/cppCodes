// C++ code to demonstrate copy of vector
// by iterative method.
#include<iostream>
#include<vector>
using namespace std;
  
int main()
{
    // Initializing vector with values
    vector<int> vect1{1, 2, 3, 4};
  
    // Declaring new vector
    vector<int> vect2;
  
    // A loop to copy elements of
    // old vector into new vector
    // by Iterative method
    for (int i=0; i<vect1.size(); i++)
        vect2.push_back(vect1[i]);
  
    cout << "Old vector elements are : ";
    for (int i=0; i<vect1.size(); i++)
        cout << vect1[i] << " ";
    cout << endl;
  
    cout << "New vector elements are : ";
    for (int i=0; i<vect2.size(); i++)
        cout << vect2[i] << " ";
    cout<< endl;
  
    // Changing value of vector to show that a new
    // copy is created.
    vect1[0] = 2;
  
    cout << "The first element of old vector is :";
    cout << vect1[0] << endl;
    cout << "The first element of new vector is :";
    cout << vect2[0] <<endl;
  
    return 0;
}