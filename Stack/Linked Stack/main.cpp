#include <iostream>

using namespace std;

template<class T >
class stack
{
    struct node
    {
        int value;
        node* next;
    };

    node* top;

public:

    stack()
    {
        top = NULL;
    }
    
    bool isEmpty()
    {
        return top == NULL;
    }

    void push(T& element)
    {
        node *addElement = new node;
        if (addElement == NULL)
        {
            cout << "Stack Push Cannot allocate Memory" << endl;
        }
        else
        {
            addElement->value = element;
            addElement->next = top;
            top = addElement;
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
            node* temp = top;
            top = top->next;
            temp = temp->next = NULL;
            delete temp;
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
            return top->value;
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
            node* temp = top;
            cout << "[ ";
            while (temp != NULL)
            {
                cout << temp->value<<" ";
                temp = temp->next;
            }
            cout << "]" << endl;
        }
    }

};

int main()
{
    cout << "choose the choice :" << endl;
    cout << "----------------------main table ------------------------------" << endl << endl;
    cout << "\t 1 - Add to stack " << endl;
    cout << "\t 2 - Delete the top element " << endl;
    cout << "\t 3 - Print the top of stack " << endl;
    cout << "\t 4 - Print the Stack " << endl;
    cout << "\t 5 - Exit " << endl;

    int choice;
    cin >> choice;
    stack<int> s;
    while (choice <= 5)
    {
        switch (choice)
        {
        case(1):
        {
            int val;
            cin >> val;
            s.push(val);
            cout << "The Value is Saved" << endl;
            break;
        }

        case(2):
        {
            s.pop();
            cout << "The Value is Deleted" << endl;
            break;
        }

        case(3):
        {
            cout << "The Top Element" << endl;
            cout << s.TopElement() << endl;
            break;
        }

        case(4):
        {
            cout << "The Element Of The Stack" << endl;
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