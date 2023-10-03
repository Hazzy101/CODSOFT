#include <iostream>
using namespace std;

class calculator
{
private:
    float number1, number2 ;
    float answer;
    char sign;


    int menu()
    {
        int opt;
        while (1)
        {
            
            cout << "1. Continue This Calcultion" << endl;
            cout << "2. Start New Calculation" << endl;
            cout << "3. Exit" << endl;

            cin >> opt;
            if (opt == 1 || opt == 2 || opt == 3)
                break;
            else
                cout << "Invalid Input" << endl;
        }
        return opt;
    }
    void calculation()
    {
        operation_input();

        switch (sign)
        {
        case '+':
        {
            answer = number1 + number2;
        }
        break;
        case '-':
        {
            answer = number1 - number2;
        }
        break;
        case '*':
        {
            answer = number1 * number2;
        }
        break;
        case '/':
        {
            answer = number1 / number2;
        }
        break;
        }
    }
    void operation_input()
    {
        while (1)
        {
            cout << "Enter The The Operation (+,-,*,/) : "; cin >> sign;
            if (sign == '+' || sign == '-' || sign == '*' || sign == '/')
                break;

            cout << "Enter A Valid Operation " << endl;
        }
    }
    void display()
    {
        system("cls");
        cout << "Your Answer is : " << endl;
        cout << number1 << " " << sign << " " << number2 << " = " << answer << endl;
    }
public:

    void start()
    {
        bool cont = false;  // to check to continue the calculaton with old answer
        while(1)
        {
            cout << "******** Calculator ********\n";
            if (cont == false)
            {
                cout << "Input First Number : "; cin >> number1;
            }
            cout << "Input Second Number : "; cin >> number2;
            calculation();
            display();
    
            switch (menu())
            {
               case 1:
               {
                cont = true;
                number1 = answer;
               }
                break;
                case 2:
               {
                cont = false;
               }
                break;
                case 3:
                {
                    return;
                }
                break;
            }
        }
    }
};
int main()
{
    calculator sum;
    sum.start();
    return 0;
}
