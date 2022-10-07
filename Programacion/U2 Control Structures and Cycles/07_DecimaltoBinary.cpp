#include <iostream>

using namespace std;



int main (){

    int num;
    int decimal;
    string resultado;

    cout << "Dame el numero en decimal: \n";
    cin >> num, decimal;
    while (num != 0)
    {
        if (num % 2 == 0)
        {
            resultado = "0" + resultado;
        }
        else
        {
            resultado = "1" + resultado;
        }
        num /= 2;
    }
    
    cout << "binary : " << resultado << endl;

    return 0;
}