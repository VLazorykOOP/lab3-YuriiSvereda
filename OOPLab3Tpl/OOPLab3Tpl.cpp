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


    //SETERS
    void SetElement(short element_number, double value = 6.66) {
        if (element_number < 0 || element_number > size) {
            cout << "set element error" << endl;
            this->error = 1; // set element error
            this->err_counter++;
        }
        else if (value < DBL_MIN || value > DBL_MAX) {
            value = 6.66;
            this->error = 1;
            this->err_counter++;
            this->vector[element_number] = value;
        }
        else
            this->vector[element_number] = value;
    }

    void SetStateVirable(bool state_variable) {
        this->state_variable = state_variable;
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

    //GETERS
    short GetSize() {
        return this->size;
    }
    double GetElement(short element_number) {
        return this->vector[element_number];
    }
    short GetErrorIndex() {
        return this->error;
    }
    short GetErrorCouter() {
        return this->err_counter;
    }

    void print() {
        for (short i = 0; i < size; i++) {
            cout << "vector[" << i << "] = " << vector[i] << endl;
        }
        cout << endl;
    }


    void DeleteMemoryManualy() {
        delete[]vector;
    }
    void ConsolInputVector() {
        double value;
        cout << "input size: ";
        cin >> this->size;
        this->vector = new double[size];
        for (short i = 0; i < size; i++) {
            cout << "vector[" << i << "] = ";
            cin >> value;
            this->SetElement(i, value);
        }
    }


    //functions of arithmetic operations
    ClassVector Addition(ClassVector other_vector) {

        double value;
        short resultsize;
        //check which size bigger becouse bigger one will be size of the result`s vector
        if (this->GetSize() < other_vector.GetSize()) {
            resultsize = this->size;
        }
        else
            resultsize = other_vector.GetSize();

        ClassVector result(resultsize);
        for (short i = 0; i < resultsize; i++) {
            value = this->vector[i] + other_vector.GetElement(i);
            result.SetElement(i, value);
        }
        result.SetStateVirable(0);
        return result;
    }

    ClassVector Subtraсtion(ClassVector other_vector) {
        double value;
        short resultsize;
        if (this->GetSize() < other_vector.GetSize()) {
            resultsize = this->size;
        }
        else {
            resultsize = other_vector.GetSize();
        }
        ClassVector result(resultsize);
        for (short i = 0; i < resultsize; i++) {
            value = this->vector[i] - other_vector.GetElement(i);
            result.SetElement(i, value);
        }
        result.SetStateVirable(0);
        return result;
    }

    //functions of multiplication and division by a scalar
    void MultiplicationByScalar(double scalar) {
        double value;
        for (short i = 0; i < size; i++) {
            value = vector[i] * scalar;
            this->SetElement(i, value);
        }

    }

    void DvisionByScalar(double scalar) {
        double value;
        for (short i = 0; i < size; i++) {
            value = vector[i] / scalar;
            this->SetElement(i, value);
        }

    }



    //functions of comparison by elements
    bool IfBiggerByElements(ClassVector other_vector) {
        short other_size;
        other_size = other_vector.GetSize();

        if (this->size > other_size)
            return true;
        else {
            for (short i = 0; i < this->size; i++) {
                if (this->vector[i] <= other_vector.GetElement(i))
                    return false;

            }
            return true;
        }
    }

    bool IfSmallerByElements(ClassVector other_vector) {
        short other_size;
        other_size = other_vector.GetSize();

        if (this->size > other_size)
            return true;
        else {
            for (short i = 0; i < this->size; i++) {
                if (this->vector[i] >= other_vector.GetElement(i))
                    return false;

            }
            return true;
        }
    }

    bool IfEqualByElements(ClassVector other_vector) {
        short other_size;
        other_size = other_vector.GetSize();

        if (this->size > other_size)
            return true;
        else {
            for (short i = 0; i < this->size; i++) {
                if (this->vector[i] != other_vector.GetElement(i))
                    return false;

            }
            return true;
        }
    }


    //functions of comparison by modul
    bool IfBiggerByModul(ClassVector other_vector) {
        double this_modul = 1, other_modul = 1;
        for (short i = 0; i < this->size; i++) {
            this_modul += this->vector[i] * this->vector[i];
        }
        this_modul = sqrt(this_modul);

        short other_size = other_vector.GetSize();
        for (short i = 0; i < other_size; i++) {
            other_modul += other_vector.GetElement(i) * other_vector.GetElement(i);
        }
        other_modul = sqrt(other_modul);

        if (this_modul > other_modul) {
            return true;
        }
        return false;
    }

    bool IfSmallerByModul(ClassVector other_vector) {
        double this_modul = 1, other_modul = 1;
        for (short i = 0; i < this->size; i++) {
            this_modul += this->vector[i] * this->vector[i];
        }
        this_modul = sqrt(this_modul);

        short other_size = other_vector.GetSize();
        for (short i = 0; i < other_size; i++) {
            other_modul += other_vector.GetElement(i) * other_vector.GetElement(i);
        }
        other_modul = sqrt(other_modul);

        if (this_modul < other_modul) {
            return true;
        }
        return false;
    }

    bool IfEqualByModul(ClassVector other_vector) {
        double this_modul = 1, other_modul = 1;
        for (short i = 0; i < this->size; i++) {
            this_modul += this->vector[i] * this->vector[i];
        }
        this_modul = sqrt(this_modul);

        short other_size = other_vector.GetSize();
        for (short i = 0; i < other_size; i++) {
            other_modul += other_vector.GetElement(i) * other_vector.GetElement(i);
        }
        other_modul = sqrt(other_modul);

        if (this_modul == other_modul) {
            return true;
        }
        return false;
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

void Task2()
{
    ClassVector defult, defult_1(5), defult_2(5, 8);
    cout << "DEF:" << endl;
    defult.print();
    if (defult_1.IfSmallerByElements(defult_2)) {
        cout << "DEF1:" << endl;
        defult_1.print();
        cout << "DEF2:" << endl;
        defult_2.print();
    }

    ClassVector a(6, 8), b(8, 6), summ_vector, difference_vector, multiplicated_vector, divided_vector;

    summ_vector = a.Addition(b);
    cout << "Addition of vectors a & b =" << endl;
    summ_vector.print();

    difference_vector = a.Subtraсtion(b);
    cout << "Substruction of vectors a & b =" << endl;
    difference_vector.print();

    multiplicated_vector.ConsolInputVector();
    cout << endl;
    multiplicated_vector.MultiplicationByScalar(3);
    cout << "Vector of multiplications by 3:" << endl;
    multiplicated_vector.print();

    divided_vector.ConsolInputVector();
    cout << endl;
    divided_vector.DvisionByScalar(4);
    cout << "Vector of divisions by 4:" << endl;
    divided_vector.print();

    /*delete memory manualy because in function of arithmetic operations
    wasn`t able to use destructor and delete it automatically
    (allocated memory had deleted before the outputing of array)*/
    summ_vector.DeleteMemoryManualy();
    difference_vector.DeleteMemoryManualy();
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