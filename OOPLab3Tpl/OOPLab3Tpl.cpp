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

    //SETERS
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
    void SetColor_OnlyIndex(short colornumber) {
        if (colornumber < 0 || colornumber > 7) {
            cout << "incorrect input" << endl;
            colornumber = -1;
        }
        color_number = colornumber;
    }

    //GETERS
    short GetHigh() {
        return high;
    }
    short GetWeigth() {
        return weight;
    }
    short GetColorNumber() {
        return color_number;
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

    //function for consol inputing parameters
    void ConsolInputingParameters()
    {
        short highValue, weightValue, colorValue;

        cout << "enter high: ";
        cin >> highValue;
        SetHigh(highValue);

        cout << "enter weight: ";
        cin >> weightValue;
        SetWeigth(weightValue);

        ColorMenu();
        cin >> colorValue;
        SetColor_OnlyIndex(colorValue);
        GetColor(color_number);
    }

private:
    short high, weight, color_number;
    short perimetr, square;
    string color;



    void ColorMenu() {
        cout << "enter number of color" << endl;
        cout << "1. white" << endl;
        cout << "2. red" << endl;
        cout << "3. yellow" << endl;
        cout << "4. green" << endl;
        cout << "5. blue" << endl;
        cout << "6. purpule" << endl;
        cout << "7. black" << endl;
    }
};

void Task1()
{
    rectangle a, b, c(5, 7, 4);
    cout << "Rectangle A:" << endl;
    a.print();
    b.ConsolInputingParameters();
    cout << "Rectangle B:" << endl;
    b.print();
    cout << "Rectangle C:" << endl;
    c.print();
    short cSquare = c.GetSquare();
    cout << "Square equal " << cSquare << '\n';
    short cPerimetr = c.GetPerimetr();
    cout << "Perimetr equal " << cPerimetr << '\n';
}



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