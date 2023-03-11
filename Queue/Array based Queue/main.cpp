#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

template<class T>
class queue
{
    int front, rear;
    int length;
    int maxSize=0;
    T* arr;

public:

    queue(int size)
    {
        front = 0;
        maxSize = size;
        arr = new T[maxSize];
        rear = maxSize - 1;
        length = 0;
    }

    ~queue()
    {
        delete [] arr;
    }
   
    bool isEmpty()
    {
        return length == 0;
    }

    bool isFull()
    {
        return length == maxSize;
    }

    void push(T val)
    {
        if (isFull())
        {
            cout << "The Queue is Full " << endl;
        }
        else
        {
            rear = (rear + 1) % maxSize;
            arr[rear] = val;
            length++;
            cout << "The Value is Saved" << endl;
            
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "The Queue is Empty " << endl;
        }
        else
        {
            front = (front + 1) % maxSize;
            --length;
            cout << "The Value is Deleted" << endl;
        }
    }

    int front_queue()
    {
        assert(!isEmpty());
        return arr[front];
    }

    int back()
    {
        assert(!isEmpty());
        return arr[rear];
    }

    int size()
    {
        return length;
    }

    void display()
    {
        if (!isEmpty()) {
            cout << "{ ";
            for (size_t i = front; i != rear ; i = (i + 1) % maxSize)
            {
                cout << arr[i] << " ";
            }
            cout << arr[rear] << " ";

            cout << "}";
        }
        else
        {
            cout << "The queue is Empty" << endl;
        }
    }

    bool search(T Element)
    {
        int pos = -1;

        for (size_t i = front; i < rear; i = (i+1)%maxSize)
        {
            if (Element == arr[i])
            {
                pos = i;
                break;
            }
        }

        if (Element == arr[rear]&& pos == -1)
        {
            pos = rear;
        }

        if (pos == -1)
        {
            return false;
        }
        else
        {
            return true;
        }
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
    cout << "\t 8 - Exit " << endl;
}

int main()
{
    int size;
    cout << "Hi, Please Enter The Size Of The Queue to Start :- ";
    cin >> size;
    system("cls");
    Options();

    int choice;
    cin >> choice;
    queue<int> qu(size);
    while (choice <= 8)
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
        default:
        {
            cout << "Thank You To Use My App :)";
            return 0;
        }
        }
        char c;
        cout << "Do you want another operation ? (Y/N)  ";
        cin >> c;
        if (c == 'Y'||c=='y')
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