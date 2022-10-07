#include <iostream>


using std::cin;
using std::cout;
using std::endl;
using std::string;

string toBinary(int n)
{
    string r;
    while (n != 0){
        r += ( n % 2 == 0 ? "0" : "1" );
        n /= 2;
    }
    return r;
}

int main() {
    int number;

    cout << "Dame el numero en decimal: \n";
    cin >> number;

    cout << "decimal: " << number << endl;
    cout << "binary : " << toBinary(number) << endl;

    return EXIT_SUCCESS;
}