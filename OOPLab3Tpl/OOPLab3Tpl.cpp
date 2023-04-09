#include <iostream>
#include <string>

//#define DEBUG

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

/*Задача 2.3.
Створити тип даних - клас вектор, який має вказівник на double, число елементів і
змінну стану. У класі визначити

o конструктор без параметрів( виділяє місце для одного елемента та інінціалізує
його в нуль);
o конструктор з одним параметром - розмір вектора( виділяє місце та інінціалізує
масив значенням нуль);
o конструктор із двома параметрами - розмір вектора та значення
ініціалізації(виділяє місце (значення перший аргумент) та інінціалізує
значенням другого аргументу);
o конструктор копій та операцію присвоєння; // !!!
o деструктор звільняє пам'ять;
o визначити функцію, яка присвоює елементу масиву деяке значення (параметр за
замовчуванням);
o функцію яка одержує деякий елемент масиву;
o визначити функції друку, додавання, віднімання, які здійснюють ці
арифметичні операції з даними цього класу, множення та ділення на скаляр
типу double;
o визначити функції порівняння: більше, менше або рівно, які повертають true
або false.
У змінну стани встановлювати код помилки, коли не вистачає пам'яті, виходить за межі масиву.
Передбачити можливість підрахунку числа об'єктів даного типу*/


class ClassVector
{
public:
    //default constructor
    ClassVector() {
        this->size = 1;
        this->vector = new double[this->size];
        this->vector[0] = 0;
#ifdef DEBUG
        cout << "default constructor " << this << endl;
#endif // DEBUG

    }

    //other constructors
    ClassVector(short size) {
        this->SetSize(size);
        vector = new double[size];
        for (short i = 0; i < size; i++) {
            vector[i] = 0;
        }
#ifdef DEBUG
        cout << "constructor size only " << this << endl;
#endif // DEBUG

    }

    ClassVector(short size, double inicialisated_value) {
        this->SetSize(size);
        vector = new double[size];
        for (short i = 0; i < size; i++) {
            vector[i] = inicialisated_value;
        }
#ifdef DEBUG
        cout << "constructor size n value " << this << endl;
#endif // DEBUG

    }

    //constructor of copy
    ClassVector(const ClassVector& other) {
        this->size = other.size;
        this->vector = new double[other.size];
        for (short i = 0; i < other.size; i++) {
            this->vector[i] = other.vector[i];
        }
#ifdef DEBUG
        cout << "constructor copy " << this << endl;
#endif // DEBUG

    }

    //destructor
    ~ClassVector() {
        if (state_variable) {
            delete[]vector;
#ifdef DEBUG
            cout << "destructor deleted memory" << this << endl;
#endif // DEBUG
        }
        else {
            state_variable = 1;

#ifdef DEBUG
            cout << "destructor skiped" << this << endl;
#endif // DEBUG
        }
    }

    void SetSize(short size) {
        if (size >= 0) {
            this->size = size;

        }
        else if (size < SHRT_MIN || size > SHRT_MAX) {
            error = 2; // size input error
            this->err_counter++;
            this->size = 0;
        }

        else {
            error = 2;
            this->err_counter++;
            this->size = abs(size);
        }

    }


private:
    double* vector;
    short size, error = 0, err_counter = 0;/*1 — set element
                                             2 — set size */
    bool state_variable = true;
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