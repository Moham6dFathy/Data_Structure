#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

template<class T>
class linkedList
{
    struct node
    {
        T value;
        node* next;
    };

    node* head;
    node* back;
    int length;

public:

    linkedList() :head(NULL), back(NULL), length(0)
    {}

    bool isEmpty()
    {
        return head == NULL;
    }

    void insertFirst(T& val)
    {

        node* addElement = new node;
        addElement->value = val;
        addElement->next = NULL;

        if (isEmpty())
        {
            head = back = addElement;
        }
        else
        {
            addElement->next = head;
            head = addElement;
        }
        length++;
    }

    void insertEnd(T& val)
    {
        node* addElement = new node;
        addElement->value = val;
        addElement->next = NULL;

        if (isEmpty())
        {
            head = back = addElement;
        }
        else
        {
            back->next = addElement;
            back = addElement;
        }
        length++;
    }

    void insertAtPostion(int pos, T& val)
    {
        node* addElement = new node;
        addElement->value = val;
        addElement->next = NULL;
        if (pos<0 || pos>length)
        {
            cout << "Out of Range" << endl;
        }
        else {
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
            head = back = NULL;
            length--;
            cout << "The Element is removed " << endl;
        }
        else
        {
            node* temp = head;
            head = head->next;
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
            node* temp = head;
            node* curr = new node;
            while (temp != NULL)
            {
                if (temp->next == back)
                {
                    curr = temp;
                    break;
                }
                temp = temp->next;
            }
            delete temp;
            curr->next = NULL;
            back = curr;
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
            node* temp, * curr;
            if (head->value == element)
            {
                curr = head;
                head = head->next;
                delete curr;
                if (length == 0)back = NULL;
            }
            else
            {
                curr = head->next;
                temp = head;
                while (curr != 0)
                {
                    if (curr->value == element)
                    {
                        break;
                    }
                    temp = curr;
                    curr = curr->next;
                }

                if (curr == NULL)
                {
                    cout << "Not Found" << endl;
                }
                else
                {
                    temp->next = curr->next;
                    if (back == curr)
                    {
                        back = temp;
                        length--;
                    }
                }
                
                curr = NULL;
                delete curr;
            }
            cout << "The Element is removed " << endl;
        }
        
    }

    void reverse()
    {
        node* curr = head, * next = head, * prev = NULL;

        while (next != NULL)
        {
            curr = next;
            next = next->next;
            curr->next = prev;
            prev = curr;
        }
        head = prev;
        delete next, curr, prev;
        cout << "The list reversed" << endl;

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

    void clear()
    {
        node* current;

        while (head != NULL)
        {
            current = head;
            head = head->next;
            delete current;
        }
        back = NULL;
        length = 0;
        cout << "The list is Cleared" << endl;
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
    cout << "\t 9 - print first element " << endl;
    cout << "\t 10 - print last element " << endl;
    cout << "\t 11 - print The List " << endl;
    cout << "\t 12 - print size of list  " << endl;
    cout << "\t 13 - Clear The list " << endl;
    cout << "\t 14 - Exit " << endl;


}

int main()
{

    Options();

    int choice;
    cin >> choice;
    linkedList <int> link;
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
            link.reverse();
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
        }case(13):
        {
            link.clear();
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