//Library for handling screen inputs and outputs
#include <iostream>

//Use of the namespace to avoid the std::
using namespace std;

int main (){
    int conjunto[5][5];

    for (int row = 0; row < 5; row ++)
    {
        for (int col = 0; col < 5; col++)
        {
            cout << "Dame el valor para la columna " << row << "," << col<< endl;
            cin >> conjunto[row][col]; 
        }
    }

    for (int row = 0; row < 5; row ++)
    {
        for (int j = 0; j <= 80; j++)
            {
                cout << "-";
            }
        cout<<endl;
        for (int col = 0; col < 5; col++)
        {
            cout <<"|\t"<<conjunto[row][col]<<"\t|";
        }
        cout<<endl;
    }
    for (int p = 0; p <=80; p++)
    {
        cout << "-";
    }
    cout<<endl;
}