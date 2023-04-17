#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

template<class T>
class queue
{
    struct node
    {
        T value;
        node* next;
    };

    node* front;
    node* rear;
    int length;

public:

    queue() :front(NULL), rear(NULL), length(0)
    {}

    bool isEmpty()
    {
        return rear == NULL;
    }


    void push(T val)
    {

        node* addElement = new node;

        addElement->value = val;
        addElement->next = NULL;

        if (isEmpty())
        {
            front = rear = addElement;
        }
        else
        {
            if (val >= front->value)
            {
                addElement->next = front;
                front = addElement;
            }
            else if (val <= rear->value)
            {
                rear->next = addElement;
                rear = addElement;
            }
            else
            {
                node* temp = front;
                node* back = new node;

                while (temp != NULL)
                {
                    if (val > temp->value)
                    {
                        back->next = addElement;
                        addElement->next = temp;
                        back = NULL;
                        break;
                    }
                    back = temp;
                    temp = temp->next;
                }

                temp = NULL;
                delete back;
                delete temp;

            }


        }

        length++;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "The Queue is Empty " << endl;
        }
        else
        {
            node* temp = front;
            if (front == rear)
            {
                front = NULL;
                rear = NULL;
            }
            else
            {
                front = front->next;
                temp->next = NULL;
            }

            delete temp;
            length--;
        }
    }

    int front_queue()
    {
        assert(!isEmpty());
        return front->value;
    }

    int back()
    {
        assert(!isEmpty());
        return rear->value;
    }

    int size()
    {
        return length;
    }

    void clear()
    {
        node* current;

        while (front != NULL)
        {
            current = front;
            front = front->next;
            delete current;
        }
        rear = NULL;
        length = 0;
    }

    void display()
    {
        node* temp = front;
        cout << "[ ";
        while (temp != NULL)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        delete temp;
        cout << "] ";
    }

    bool search(T Element)
    {
        node* temp = front;
        while (temp != NULL)
        {
            if (temp->value == Element)
            {
                return true;
            }
            temp = temp->next;
        }
        delete temp;
    }

};

void Options()
{
    cout << "Choose what you like :" << endl;
    cout << "----------------------main table ------------------------------" << endl << endl;
    cout << "\t 1 - Add to Queue " << endl;
    cout << "\t 2 - Delete the Front ُElement " << endl;
    cout << "\t 3 - Search in The Queue " << endl;
    cout << "\t 4 - Print the Front of Queue " << endl;
    cout << "\t 5 - Print the Back of Queue " << endl;
    cout << "\t 6 - Print the Current Size " << endl;
    cout << "\t 7 - Print the Queue " << endl;
    cout << "\t 8 - Clear Queue " << endl;
    cout << "\t 9 - Exit" << endl;
}

int main()
{

    Options();

    int choice;
    cin >> choice;
    queue<int> qu;
    while (choice <= 9)
    {
        switch (choice)
        {
        case(1):
        {
            int val;
            cin >> val;
            qu.push(val);
            break;
        }

        case(2):
        {
            qu.pop();
            break;
        }
        case(3):
        {
            int num;
            cout << "Enter The Number : " << endl;
            cin >> num;
            cout << endl;
            if (qu.search(num))
            {
                cout << "Found" << endl;
            }
            else
            {
                cout << "Not Found" << endl;
            }
            break;
        }
        case(4):
        {
            cout << "the Front Element" << endl;
            cout << qu.front_queue() << endl;
            break;
        }

        case(5):
        {
            cout << "the Back Element" << endl;
            cout << qu.back() << endl;
            break;
        }

        case(6):
        {
            cout << "The Current Size is : " << endl;
            cout << qu.size() << endl;
            break;
        }
        case(7):
        {
            cout << "The Queue : " << endl;
            qu.display();
            cout << endl;
            break;
        }
        case(8):
        {
            qu.clear();
            cout << "The Queue is Cleared " << endl;
            break;
        }
        default:
        {
            cout << "Thank You To Use My App :)";
            return 0;
        }
        }

        char c;
        cout << "Do you want another operation ? (Y/N)  ";
        cin >> c;
        if (c == 'Y' || c == 'y')
        {
            system("cls");
        }
        else
        {
            cout << "Thank You To Use My App :)";
            return 0;
        }

        Options();
        cout << "Choose what you like : " << endl;
        cin >> choice;

    }
    cout << "Thank You To Use My App :)";
    return 0;


}