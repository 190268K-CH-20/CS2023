#include <iostream>
#include <chrono>
using namespace std;

#define MAX_SIZE 1000

class StackArray
{
private:
    int arr[MAX_SIZE];
    int top;
    int size;

public:
    StackArray()
    {
        top = -1;
        size = MAX_SIZE;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == size - 1;
    }

    void push(int x)
    {
        if (isFull())
        {
            cout << "Stack Overflow\n";
        }
        else
        {
            top++;
            arr[top] = x;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow\n";
            return -1;
        }
        else
        {
            int x = arr[top];
            top--;
            return x;
        }
    }

    int stackTop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty\n";
            return -1;
        }
        else
        {
            return arr[top];
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty\n";
        }
        else
        {
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
    }
};

// Node class for the linked list
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

// Stack class using linked list
class StackList
{
private:
    Node *head;
    Node *top;

public:
    StackList()
    {
        head = NULL;
        top = NULL;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    bool isFull()
    {
        return false;
    }

    void push(int data)
    {
        Node *newNode = new Node(data);
        if (isEmpty())
        {
            head = newNode;
            top = newNode;
        }
        else
        {
            top->next = newNode;
            top = newNode;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            throw "Stack Underflow";
        }
        else
        {
            int x;
            if (top == head)
            {
                x = top->data;
                top = NULL;
                head = NULL;
            }
            else
            {
                Node *tmp = head;
                while (tmp->next != top)
                {
                    tmp = tmp->next;
                }
                x = top->data;
                top = tmp;
                top->next = NULL;
            }
            return x;
        }
    }

    int stackTop()
    {
        if (isEmpty())
        {
            throw "Stack is Empty";
        }
        else
        {
            return top->data;
        }
    }

    void display()
    {
        Node *tmp = head;
        while (tmp != NULL)
        {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
};

int main()
{

    for (int k = 1; k < 11; k++)
    {
        StackArray s1;
        auto start1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10; i++)
        {
            int x = rand();
            s1.push(x);
        }
        s1.display();
        for (int i = 0; i < 5; i++)
        {
            s1.pop();
        }
        s1.display();
        for (int i = 0; i < 4; i++)
        {
            int x = rand();
            s1.push(x);
        }
        s1.display();
        auto stop1 = chrono::high_resolution_clock::now();
        auto duration1 = chrono::duration_cast<chrono::microseconds>(stop1 - start1);
        cout << "       Time taken by StackArray for Loop " << k << " : " << duration1.count() << " microseconds" << endl;

        StackList s2;
        auto start2 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10; i++)
        {
            int x = rand();
            s2.push(x);
        }
        s2.display();
        for (int i = 0; i < 5; i++)
        {
            s2.pop();
        }
        s2.display();
        for (int i = 0; i < 4; i++)
        {
            int x = rand();
            s2.push(x);
        }
        s2.display();
        auto stop2 = chrono::high_resolution_clock::now();
        auto duration2 = chrono::duration_cast<chrono::microseconds>(stop2 - start2);
        cout << "       Time taken by StackList for Loop " << k << " : " << duration2.count() << " microseconds" << endl;
    }

    return 0;
}
