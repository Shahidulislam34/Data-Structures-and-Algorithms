#include <iostream>
using namespace std;
void counter() {
    static int coun = 0; // one time initialization
    coun++;
    cout << "Coun = " << coun << endl;
}
int main() {
    counter(); // Coun = 1
    counter(); // Coun = 2
    counter(); // Coun = 3
}

