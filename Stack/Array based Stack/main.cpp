#include <iostream>

using namespace std;

template<class T >
class stack
{
    int top;
    int Max_size;
    int* arr;

public :

    stack(int size)
    {
        top = 0;
        Max_size = size;
        arr = new int[size];
    }

    bool isEmpty()
    {
        return top == 0;
    }
    
    bool isFull()
    {
        return top == Max_size - 1;
    }

    void push(T& element)
    {
        if (isFull())
        {
            cout << "The Stack Is Full" << endl;
        }
        else
        {
            arr[top] = element;
            top++;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "The Stack Is Empty " << endl;
        }
        else
        {
            top--;
        }
    }

    int TopElement()
    {
        if (isEmpty())
        {
            cout << "The Stack Is Empty " << endl;
        }
        else
        {
            return arr[top - 1];
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "The Stack Is Empty " << endl;
        }
        else
        {
            cout << "[ ";
            for (int i = top - 1; i >= 0; i--)
            {
                cout << arr[i];
                if (i != 0)
                {
                    cout << " , ";
                }
            }
            cout << "]" << endl;
        }
    }

};

int main()
{
    int size;
    cout << "Hi, Please Enter The Size Of The Stack to Start :- ";
    cin >> size;
    system("cls");
    cout << "choose the choice :" << endl;
    cout << "----------------------main table ------------------------------" << endl << endl;
    cout << "\t 1 - Add to stack " << endl;
    cout << "\t 2 - delete the top element " << endl;
    cout << "\t 3 - print the top of stack " << endl;
    cout << "\t 4 - print the Stack " << endl;
    cout << "\t 5 - Exit " << endl;

    int choice;
    cin >> choice;
    stack<int> s(size);
    while (choice <= 5)
    {
        switch (choice)
        {
        case(1):
        {
            int val;
            cin >> val;
            s.push(val);
            cout << "the value is saved" << endl;
            break;
        }
        
        case(2):
        {
            s.pop();
            cout << "the value is deleted" << endl;
            break;
        }
        
        case(3):
        {
            cout << "the top element" << endl;
            cout << s.TopElement() << endl;
            break;
        }
        
        case(4):
        {
            cout << "the element of the stack" << endl;
            s.display();
            break;
        }

        default:
        {
            cout << "Thank You To Use My App :)";
            return 0;
        }
        }
        cin >> choice;

    }
    cout << "Thank You To Use My App :)";
    return 0;
}