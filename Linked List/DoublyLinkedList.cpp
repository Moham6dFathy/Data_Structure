#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

template<class T>
class DoublylinkedList
{
    struct node
    {
        T value;
        node* next;
        node* prev;
    };

    node* head;
    node* back;
    int length;

public:

    DoublylinkedList() :head(NULL), back(NULL), length(0)
    {}
    
    ~DoublylinkedList()
    {
        delete head;
        delete back;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    void insertFirst(T& val)
    {

        node* addElement = new node;
        addElement->value = val;

        if (isEmpty())
        {
            head = back = addElement;
            addElement->next = addElement->prev = NULL;
        }
        else
        {
            addElement->next = head;
            addElement->prev = NULL;
            head ->prev = addElement;
            head = addElement;
        }
        length++;
    }

    void insertEnd(T& val)
    {
        node* addElement = new node;
        addElement->value = val;

        if (isEmpty())
        {
            head = back = addElement;
            addElement->next = addElement->prev = NULL;
        }
        else
        {
            addElement->prev = back;
            addElement->next = NULL;
            back->next = addElement;
            back = addElement;
        }
        length++;
    }

    void insertAtPostion(int pos, T& val)
    {
        
        if (pos<0 || pos>length)
        {
            cout << "Out of Range" << endl;
        }
        else {
            node* addElement = new node;
            addElement->value = val;
          
            if (pos == 0)
            {
                insertFirst(val);
            }
            else if (pos == length)
            {
                insertEnd(val);
            }
            else
            {
                node* current = head;
                for (int i = 1; i < pos; i++)
                {
                    current = current->next;
                }

                addElement->next = current->next;
                addElement->prev = current;
                current->next->prev = addElement;
                current->next = addElement;
                current = NULL;
                delete current; 
                length++;
            }
           
        }
    }

    void removeFirst()
    {
        if(isEmpty())
        {
            return;
        }
        else if (length == 1)
        {
            delete head;
            head = back = NULL;
            length--;
            cout << "The Element is removed " << endl;
        }
        else
        {
            node* temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
            length--;
            cout << "The Element is removed " << endl;
        }
    }

    void removeLast()
    {
        if (isEmpty())
        {
            cout << "the list is empty" << endl;
        }
        else if (length == 1)
        {
            delete head;
            head = back = NULL;
            length--;
            cout << "The Element is removed " << endl;
        }
        else {
            node* curr = new node;
            back = back->prev;
            back->next = NULL;
            delete curr;
            length--;
            cout << "The Element is removed " << endl;
        }
        
    }

    void remove(T& element)
    {
        if (isEmpty())
        {
            cout << "The list is empty " << endl;
        }
        else
        {
            node* curr;
            if (head->value == element)
            {
                removeFirst();
            }
            else
            {
                curr = head->next;
        
                while (curr != NULL && curr->value != element)
                {
                    curr = curr->next;
                }

                if (curr == NULL)
                {
                    cout << "The Element not found" << endl;
                }
                else if (curr->next == NULL)
                {
                    removeLast();
                }
                else {

                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                    delete curr;
                }
            }
            length--;
            cout << "The Element is removed " << endl;
        }
        
    }

    int firstElement()
    {
        assert(!isEmpty());
        return head->value;
    }

    int lastElement()
    {
        assert(!isEmpty());
        return back->value;
    }
    
    int size()
    {
        cout << "the size of a list " << endl;
        return length;
    }

    void display()
    {
        node* temp = head;
        cout << "[ ";
        while (temp != NULL)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        delete temp;
        cout << "] ";
    }

    void reverseDisplay()
    {
        node* temp = back;
        cout << "[ ";
        while (temp != NULL)
        {
            cout << temp->value << " ";
            temp = temp->prev;
        }
        delete temp;
        cout << "] ";
    }

    bool search(T Element)
    {
        node* temp = head;
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
    cout << "\t 1 - Add at First a List " << endl;
    cout << "\t 2 - Add at End a List " << endl;
    cout << "\t 3 - Add at Position in a list " << endl;
    cout << "\t 4 - Remove from first of a list " << endl;
    cout << "\t 5 - Remove from last of a list " << endl;
    cout << "\t 6 - Remove Element form a list" << endl;
    cout << "\t 7 - Reverse The List " << endl;
    cout << "\t 8 - Search in a list " << endl;
    cout << "\t 9 - Print first element " << endl;
    cout << "\t 10 - Print last element " << endl;
    cout << "\t 11 - Display The List " << endl;
    cout << "\t 12 - Print size of list  " << endl;
    cout << "\t 13 - Exit " << endl;


}

int main()
{

    Options();

    int choice;
    cin >> choice;
    DoublylinkedList <int> link;
    int element;
    while (choice <= 14)
    {
        switch (choice)
        {
        case(1):
        {
            cout << "Enter The Element : " << endl;
            cin >> element;
            link.insertFirst(element);
            break;
        }
        case(2):
        {
            cout << "Enter The Element : " << endl;
            cin >> element;
            link.insertEnd(element);
            break;
        }
        case(3):
        {
            int pos;
            cout << "Enter The Position then The Element : " << endl;
            cin >> pos >> element;
            link.insertAtPostion(pos, element);
            break;
        }
        case(4):
        {
            link.removeFirst();
            break;
        }
        case(5):
        {
            link.removeLast();
            break;
        }
        case(6):
        {
            cout << "Enter The Element : " << endl;
            cin >> element;
            link.remove(element);
            break;
        }
        case(7):
        {
            cout << "The Reversed List ...." << endl;
            link.reverseDisplay();
            break;
        }
        case(8):
        {
            cout << "Enter The Element : " << endl;
            cin >> element;
            if (link.search(element))
            {
                cout << "Found" << endl;
            }
            else
            {
                cout << "Not Found" << endl;
            }
            break;
        }
        case(9):
        {
            cout << "the First Element is : ";
            cout << link.firstElement() << endl;
            break;
        }
        case(10):
        {
            cout << "The last Element : " << endl;
            cout << link.lastElement() << endl;
            break;
        }
        case(11):
        {
            link.display();
            cout << endl;
            break;
        }
        case(12):
        {
            cout << link.size() << endl;
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