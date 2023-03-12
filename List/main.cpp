#include <iostream>

using namespace std;

template<class T>
class List
{
    int* arr;
    int maxSize;
    int length;


public:

    List(int size)
    {
        if (size < 0)
        {
            maxSize = 10;
        }
        else
        {
            maxSize = size;
        }
        length = 0;
        arr = new int[maxSize];
    }

    ~List()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        return length == 0;
    }

    bool isFull()
    {
        return length == maxSize;
    }

    void insert(T Element, int pos)
    {
        if (isFull())
        {
            cout << "The List is Full" << endl;
        }
        else if (pos<0 || pos > length)
        {
            cout << "Out of Range " << endl;
        }
        else
        {
            for (int i = length; i > pos; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[pos] = Element;
            length++;
        }
    }
    void insertAtEnd(int Element)
    {
        if (isFull())
        {
            cout << "The List is Full Can't insert" << endl;
        }
        else
            arr[length] = Element;
        length++;
    }

    bool search(int Element)
    {
        if (isEmpty())
        {
            cout << "The List is Empty" << endl;
        }
        else
        {
            for (int i = 0; i < length; i++)
            {
                if (arr[i] == Element)
                {
                    return true;
                }
            }

            return false;
        }
    }

    void insertNoDuplicate(int element)
    {

        if (!search(element))
        {
            insertAtEnd(element);
        }
        else
        {
            cout << "The Element is there !";
        }
    }

    void updateItem(int Element, int pos)
    {
        if (pos < 0 || pos >= length)
        {
            cout << "Out of Range" << endl;
        }
        else
        {
            arr[pos] = Element;
        }
    }

    int getElement(int pos)
    {
        if (pos<0 || pos>length)
        {
            cout << "Out of Range" << endl;
        }
        else
        {
            return arr[pos];
        }

    }

    int getSize()
    {
        return length;
    }

    void delteitem(int pos)
    {
        if (isEmpty())
        {
            cout << "The List is Empty" << endl;
        }
        else if (pos < 0 || pos>maxSize)
        {
            cout << "Out of Range " << endl;
        }
        else
        {
            for (int i = pos; i < length; i++)
            {
                arr[i] = arr[i + 1];
            }
            length--;
        }
    }

    void display()
    {
        cout << "{ ";
        for (int i = 0; i < length; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "}" << endl;
    }

};


void Options()
{

    cout << "----------------------main table ------------------------------" << endl << endl;
    cout << "\t 1 - Insert at List " << endl;
    cout << "\t 2 - Delete the Element " << endl;
    cout << "\t 3 - Search at The List " << endl;
    cout << "\t 4 - Insert Non Duplicate Element " << endl;
    cout << "\t 5 - Insert at End of list " << endl;
    cout << "\t 6 - Update The Element" << endl;
    cout << "\t 7 - Print the Element by the postion " << endl;
    cout << "\t 8 - Print the Current Size " << endl;
    cout << "\t 9 - Print the Queue " << endl;
    cout << "\t 10 - Exit" << endl;
}


int main()
{
    int size;
    cout << "Enter The size of the list : ";
    cin >> size;
    system("cls");

    List<int> l(size);
    Options();

    int choice;
    cin >> choice;
    int val, s;
    while (choice <= 9)
    {
        switch (choice)
        {
        case(1):
        {
            cout << "please , Enter The Element and The Postion : " << endl;
            cin >> val >> s;
            l.insert(val, s);
            break;
        }
        case(2):
        {
            cout << "Please, Enter The postion of the Element " << endl;
            cin >> s;
            l.delteitem(s);
            break;
        }
        case(3):
        {
            cout << "Please , Enter The Element : " << endl;
            cin >> val;
            if (l.search(val))
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
            cout << "please , Enter The Element and The Postion : " << endl;
            cin >> val >> s;
            l.insertNoDuplicate(val);
            break;
        }
        case(5):
        {
            cout << "Please , Enter The Element : " << endl;
            cin >> val;
            l.insertAtEnd(val);
            break;
        }

        case(6):
        {
            cout << "please , Enter The Element and The Postion : " << endl;
            cin >> val >> s;
            l.updateItem(val, s);
            break;

        }
        case(7):
        {
            cout << "Please, Enter The postion of the Element " << endl;
            cin >> s;
            cout << l.getElement(s) << endl;
            break;
        }
        case(8):
        {
            cout << l.getSize() << endl;
            break;
        }
        case(9):
        {
            cout << "the List is : " << endl;
            l.display();
            break;
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