// Miras_Kamatay__EIRfuc-22_K2.cpp 
// Made by: Miras Kamatay
// Date: 2023/11/17 
// Description: This program contains code for the second homework of the Algorithms and Data Structures course

#include <iostream>
#include <string>

using namespace std;

struct NodeDeque
{
    std::string data;
    NodeDeque* next;
    NodeDeque* prev;

    NodeDeque(const std::string& value) : data(value), next(nullptr), prev(nullptr) {}
};

struct Deque
{
    NodeDeque* front;
    NodeDeque* back;

    Deque() : front(nullptr), back(nullptr) {}

    void push_front(const std::string& value)
    {
        NodeDeque* newNode = new NodeDeque(value);
        if (front == nullptr)
        {
            front = newNode;
            back = newNode;
        }
        else
        {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    void push_back(const std::string& value)
    {
        NodeDeque* newNode = new NodeDeque(value);
        if (back == nullptr)
        {
            front = newNode;
            back = newNode;
        }
        else
        {
            newNode->prev = back;
            back->next = newNode;
            back = newNode;
        }
    }

    std::string pop_front()
    {
        if (front == nullptr)
        {
            return "";
        }
        std::string value = front->data;
        NodeDeque* temp = front;
        front = front->next;
        if (front == nullptr)
        {
            back = nullptr;
        }
        else
        {
            front->prev = nullptr;
        }
        delete temp;
        return value;
    }

    std::string pop_back()
    {
        if (back == nullptr)
        {
            return "";
        }
        std::string value = back->data;
        NodeDeque* temp = back;
        back = back->prev;
        if (back == nullptr)
        {
            front = nullptr;
        }
        else
        {
            back->next = nullptr;
        }
        delete temp;
        return value;
    }

    void print()
    {
        NodeDeque* current = front;
        if (current == nullptr)
        {
            cout << "Deque is empty";
        }
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void print_and_delete()
    {
        print();
        NodeDeque* current = front;
        while (current != nullptr)
        {
            NodeDeque* temp = current;
            current = current->next;
            delete temp;
        }
        front = nullptr;
        back = nullptr;
    }
};

struct NodeStack
{
    string data;
    NodeStack* prev;
    NodeStack* next;
};

class Stack
{
public:
    NodeStack* top;
    Stack()
    {
        top = nullptr;
    }

    void push(string value)
    {
        NodeStack* newNode = new NodeStack;
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = top;

        if (top != nullptr)
        {
            top->prev = newNode;
        }

        top = newNode;
    }

    void pop()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty." << endl;
            return;
        }

        NodeStack* temp = top;

        if (top->next != nullptr)
        {
            top->next->prev = nullptr;
        }

        top = top->next;
        delete temp;
    }

    void print()
    {
        NodeStack* temp = top;
        if (temp == nullptr)
        {
            cout << "Stack is empty";
        }
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    void print_and_delete()
    {
        NodeStack* temp = top;

        while (temp != nullptr)
        {
            cout << temp->data << " ";
            NodeStack* prev = temp;
            temp = temp->next;
            delete prev;
        }

        top = nullptr;
        cout << endl;
    }
};


struct Node
{
    string surname;
    Node* left;
    Node* right;
};

class BinaryTree
{
public:
    BinaryTree()
    {
        root = nullptr;
    }

    void insert(string surname)
    {
        root = insertRecursive(root, surname);
    }

    Node* search(string surname)
    {
        return searchRecursive(root, surname);
    }

    void print()
    {
        printRecursive(root);
    }

    void deleteNode(string surname)
    {
        root = deleteRecursive(root, surname);
    }

    void insertSurnamesLengthGreaterThan5(Deque& surnameDeque)
    {
        insertSurnamesLengthGreaterThan5Recursive(root, surnameDeque);
    }

    void insertSurnamesLengthBetween6And10(Deque& surnameDeque)
    {
        insertSurnamesLengthBetween6And10Recursive(root, surnameDeque);
    }

    void removeSurnamesLengthGreaterThan10(Stack& surnameStack)
    {
        removeSurnamesLengthGreaterThan10Recursive(root, surnameStack);
    }

    void printDequeAndStack(Deque& surnameDeque, Stack& surnameStack)
    {
        cout << "Deque Contents: ";
        surnameDeque.print_and_delete();

        cout << "Stack Contents: ";
        surnameStack.print_and_delete();
        cout << endl;
    }

private:
    Node* root;

    Node* createNode(string surname)
    {
        Node* newNode = new Node;
        newNode->surname = surname;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    Node* insertRecursive(Node* currentNode, string surname)
    {
        if (currentNode == nullptr)
        {
            return createNode(surname);
        }

        if (surname < currentNode->surname)
        {
            currentNode->left = insertRecursive(currentNode->left, surname);
        }
        else if (surname > currentNode->surname)
        {
            currentNode->right = insertRecursive(currentNode->right, surname);
        }

        return currentNode;
    }

    Node* searchRecursive(Node* currentNode, string surname)
    {
        if (currentNode == nullptr || currentNode->surname == surname)
        {
            return currentNode;
        }

        if (surname < currentNode->surname)
        {
            return searchRecursive(currentNode->left, surname);
        }
        else
        {
            return searchRecursive(currentNode->right, surname);
        }
    }

    void printRecursive(Node* currentNode)
    {
        if (currentNode != nullptr)
        {
            printRecursive(currentNode->left);
            cout << currentNode->surname << " ";
            printRecursive(currentNode->right);
        }
    }

    Node* deleteRecursive(Node* currentNode, string surname)
    {
        if (currentNode == nullptr)
        {
            return currentNode;
        }

        if (surname < currentNode->surname)
        {
            currentNode->left = deleteRecursive(currentNode->left, surname);
        }
        else if (surname > currentNode->surname)
        {
            currentNode->right = deleteRecursive(currentNode->right, surname);
        }
        else
        {
            if (currentNode->left == nullptr)
            {
                Node* temp = currentNode->right;
                delete currentNode;
                return temp;
            }
            else if (currentNode->right == nullptr)
            {
                Node* temp = currentNode->left;
                delete currentNode;
                return temp;
            }

            Node* temp = findMinNode(currentNode->right);
            currentNode->surname = temp->surname;
            currentNode->right = deleteRecursive(currentNode->right, temp->surname);
        }

        return currentNode;
    }

    Node* findMinNode(Node* currentNode)
    {
        Node* current = currentNode;
        while (current && current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

    void insertSurnamesLengthGreaterThan5Recursive(Node* currentNode, Deque& surnameDeque)
    {
        if (currentNode != nullptr)
        {
            insertSurnamesLengthGreaterThan5Recursive(currentNode->left, surnameDeque);
            if (currentNode->surname.length() > 5)
            {
                surnameDeque.push_front(currentNode->surname);
            }
            insertSurnamesLengthGreaterThan5Recursive(currentNode->right, surnameDeque);
        }
    }

    void insertSurnamesLengthBetween6And10Recursive(Node* currentNode, Deque& surnameDeque)
    {
        if (currentNode != nullptr)
        {
            insertSurnamesLengthBetween6And10Recursive(currentNode->left, surnameDeque);
            if (currentNode->surname.length() > 5 && currentNode->surname.length() < 11)
            {
                surnameDeque.push_back(currentNode->surname);
            }
            insertSurnamesLengthBetween6And10Recursive(currentNode->right, surnameDeque);
        }
    }

    void removeSurnamesLengthGreaterThan10Recursive(Node* currentNode, Stack& surnameStack)
    {
        if (currentNode != nullptr)
        {
            removeSurnamesLengthGreaterThan10Recursive(currentNode->left, surnameStack);
            if (currentNode->surname.length() > 10)
            {
                surnameStack.push(currentNode->surname);
                root = deleteRecursive(root, currentNode->surname);
            }
            removeSurnamesLengthGreaterThan10Recursive(currentNode->right, surnameStack);
        }
    }
};

int main()
{
    BinaryTree tree;
    Deque A;
    Stack B;
    char option;
    string data;
    Node* temp;

    while (true)
    {
        std::cout << std::endl;
        std::cout << "- - - - - - - - - - - " << std::endl;
        std::cout << "Choose an option: " << std::endl;
        std::cout << "- - - - - - - - - - - " << std::endl;
        std::cout << "1. Insert surnames with length greater than 5 at the beginning of the deque " << std::endl;
        std::cout << "2. Insert surnames with length between 6 and 10 at the end of the deque " << std::endl;
        std::cout << "3. Remove surnames with length greater than 10 from the tree and push onto the stack " << std::endl;
        std::cout << "4. Insert surnames " << std::endl;
        std::cout << "5. Delete surname " << std::endl;
        std::cout << "6. Find surname " << std::endl;
        std::cout << "7. Print tree " << std::endl;
        std::cout << "8. Print deque " << std::endl;
        std::cout << "9. Print stack " << std::endl;
        std::cout << "0. Delete deque and stack by printing them on the console" << std::endl;
        std::cout << "+. Exit " << std::endl;
        std::cin >> option;
        switch (option)
        {
        case '1':
            tree.insertSurnamesLengthGreaterThan5(A);
            break;
        case '2':
            tree.insertSurnamesLengthBetween6And10(A);
            break;
        case '3':
            tree.removeSurnamesLengthGreaterThan10(B);
            break;
        case '4':
            int n;
            std::cout << "How many surnames you want to insert to the tree: ";
            std::cin >> n;
            std::cout << "Enter surnames: \n";
            for (int i = 0; i < n; i++)
            {
                std::cin >> data;
                tree.insert(data);
            }
            break;
        case '5':
            std::cout << "What surname do you want to delete from the tree: ";
            std::cin >> data;
            tree.deleteNode(data);
            break;
        case '6':
            std::cout << "What surname do you want to find in the tree: ";
            std::cin >> data;
            temp = tree.search(data);
            if (temp != nullptr)
                std::cout << "Surname found in the tree" << std::endl;
            else
                std::cout << "Surname not found in the tree" << std::endl;
            break;
        case '7':
            std::cout << "Tree: " << std::endl;
            tree.print();
            break;
        case '8':
            std::cout << "Deque: " << std::endl;
            A.print();
            break;
        case '9':
            std::cout << "Stack: " << std::endl;
            B.print();
            break;
        case '0':
            A.print_and_delete();
            B.print_and_delete();
            break;
        case '+':
            return 0;
            break;
        default:
            std::cout << "Invalid option. Try again" << std::endl;
            break;
        }
    }
    return 0;
}
