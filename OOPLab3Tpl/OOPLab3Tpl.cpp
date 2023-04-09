#include <iostream>

using namespace std;

/*Задача 1.3.
Створити клас типу – прямокутник ( поля : висота, ширина, колір). У класі визначити
o конструктори ( не менше двох);
o функції-члени обчислення площі, периметру;
o функції-члени встановлення висоти, ширини, кольору, функції встановлення
полів класу повинні перевіряти коректність параметрів, що задаються;
o функції-члени що повертають значення полів;
o функцію друку.*/

class rectangle 
{
public:
    //default constructor
    rectangle()
    {
        this->high = 1;
        this->weight = 1;
        this->color_number = 0;
        GetColor(color_number);
    }

    //constructor for manualy input values
    rectangle(short high, short weight, short colornumber)
    {
        SetHigh(high);
        SetWeigth(weight);
        SetColor(colornumber);
    }

    //function for counting parameters
    short GetPerimetr()
    {
        perimetr = (high + weight) * 2;
        return perimetr;
    }

    //function for counting square
    short GetSquare()
    {
        square = high * weight;
        return square;
    }

    //function for output all parameters
    void print()
    {
        cout << "High: " << this->high << '\t';
        cout << "Weigth: " << this->weight << '\t';
        cout << "Color Index: " << this->color_number << '\t';
        cout << "Color: " << this->color << '\n';
        cout << endl << endl;

    }

    void SetHigh(short high) {
        if (high < 0) {
            this->high = abs(high);
        }
        else
            this->high = high;

    }
    void SetWeigth(short weight) {
        if (weight < 0) {
            this->weight = abs(weight);
        }
        else
            this->weight = weight;
    }
    void SetColor(short colornumber) {
        if (colornumber < 0 || colornumber > 7) {
            colornumber = -1;
            color = "grey";
        }
        else {
            color_number = colornumber;
            color = GetColor(color_number);
        }

    }       

    string GetColor(short colornumber) {


        switch (colornumber)
        {
        case 1:
            color = "white";
            break;
        case 2:
            color = "rad";
            break;
        case 3:
            color = "yellow";
            break;
        case 4:
            color = "green";
            break;
        case 5:
            color = "blue";
            break;
        case 6:
            color = "purpule";
            break;
        case 7:
            color = "black";
            break;
        default:
            color = "grey";
            cout << "input error";
            break;
        }
        return color;


    }

private:
    short high, weight, color_number;
    short perimetr, square;
    string color;
};

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