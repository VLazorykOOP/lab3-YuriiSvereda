#include <iostream>

using namespace std;

int main()
{
    int choise;
    cout << "Select a task:" << endl;
    cout << "1. Rectangle;" << endl;
    cout << "2. Class Vector;" << endl;
    cout << "3. Matrix;" << endl;
    cin >> choise;

    if (choise == 1) {
        Task1();
    }
    else if (choise == 2) {
        Task2();
    }
    else if (choise == 3) {
        Task3();
    }
    else
        cout << "error: incorrect input" << endl;


    return 0;
}