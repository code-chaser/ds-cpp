#include <iostream>
#include <stdexcept>
#include "./../header/doublyLinkedList.hh"

template <class T>
void listOperations(ds_cpp::doublyLinkedList<T> &list)
{
    std::cout << "\nCurrent List: [ ";
    for (int i = 0; i < list.size(); i++)
        std::cout << list[i] << (i == list.size() - 1 ? "" : ", ");
    std::cout << " ]\n";
    std::cout << "\n";
    std::cout << "Select an operation:\n";
    std::cout << "0. [Go Back]\n";
    std::cout << "1. Push Back\n";
    std::cout << "2. Push Front\n";
    std::cout << "3. Pop Back\n";
    std::cout << "4. Pop Front\n";
    std::cout << "5. Back Element\n";
    std::cout << "6. Front Element\n";
    std::cout << "7. Insert Element at\n";
    std::cout << "8. Erase Element at\n";
    std::cout << "9. Clear List\n";
    std::cout << "10. Reverse List\n";
    std::cout << "11. Size of List\n";
    std::cout << "12. Is the List empty?\n";
    std::cout << "13. Get Element by []\n";
    std::cout << "14. Assign a list (to be input) to the List\n";
    std::cout << "15. Is the List equal to a list (to be input)?\n";
    std::cout << "16. Is the List not equal to a list (to be input)?\n";
    std::cout << "17. Concatenate a list (to be input) at the end\n\n";
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;
    try
    {
        switch (choice)
        {
        case 0:
        {
            break;
        }
        case 1:
        {
            std::cout << "Enter the element to be pushed: ";
            T element;
            std::cin >> element;
            list.push_back(element);
            listOperations(list);
            break;
        }
        case 2:
        {
            std::cout << "Enter the element to be pushed: ";
            T element;
            std::cin >> element;
            list.push_front(element);
            listOperations(list);
            break;
        }
        case 3:
        {
            std::cout << "The popped element is: " << list.pop_back() << "\n";
            listOperations(list);
            break;
        }
        case 4:
        {
            std::cout << "The popped element is: " << list.pop_front() << "\n";
            listOperations(list);
            break;
        }
        case 5:
        {
            std::cout << "The back element is: " << list.back() << "\n";
            listOperations(list);
            break;
        }
        case 6:
        {
            std::cout << "The front element is: " << list.front() << "\n";
            listOperations(list);
            break;
        }
        case 7:
        {
            std::cout << "Enter the element to be inserted: ";
            T element;
            std::cin >> element;
            std::cout << "Enter the index at which '" << element << "' is to be inserted: ";
            int index;
            std::cin >> index;
            list.insert(element, index);
            listOperations(list);
            break;
        }
        case 8:
        {
            std::cout << "Enter the index at which the element is to be erased: ";
            int index;
            std::cin >> index;
            list.erase(index);
            listOperations(list);
            break;
        }
        case 9:
        {
            list.clear();
            listOperations(list);
            break;
        }
        case 10:
        {
            list.reverse();
            listOperations(list);
            break;
        }
        case 11:
        {
            std::cout << "The size of the list is: " << list.size() << "\n";
            listOperations(list);
            break;
        }
        case 12:
        {
            std::cout << (list.empty() ? "Yes" : "No") << "\n";
            listOperations(list);
            break;
        }
        case 13:
        {
            std::cout << "Enter the index of the element to be accessed: ";
            int index;
            std::cin >> index;
            std::cout << "The element at index " << index << " is: " << list[index] << "\n";
            std::cout << "Enter a new value for the element: ";
            T newValue;
            std::cin >> newValue;
            list[index] = newValue;
            std::cout << "Now, the element at index " << index << " is: " << list[index] << "\n";
            listOperations(list);
            break;
        }
        case 14:
        case 15:
        case 16:
        case 17:
        {
            std::cout << "Enter the size of reference list: ";
            int size;
            std::cin >> size;
            ds_cpp::doublyLinkedList<T> referencelist(size);
            std::cout << "Enter the elements of the reference list: ";
            for (int i = 0; i < size; i++)
            {
                std::cin >> referencelist[i];
            }
            if (choice == 14)
                list = referencelist;
            else if (choice == 15)
                std::cout << (list == referencelist ? "Yes" : "No") << "\n";
            else if (choice == 16)
                std::cout << (list != referencelist ? "Yes" : "No") << "\n";
            else if (choice == 17)
            {
                std::cout << "After concatenation, the list will be: [ ";
                ds_cpp::doublyLinkedList<T> tempList(list + referencelist);
                for (int i = 0; i < tempList.size(); i++)
                    std::cout << tempList[i] << (i == tempList.size() - 1 ? " ]" : ", ");
                std::cout << "\n";
                std::cout << "Current List: [ ";
                for (int i = 0; i < list.size(); i++)
                    std::cout << list[i] << (i == list.size() - 1 ? "" : ", ");
                std::cout << " ]\nConcatenating...\n";
                list += referencelist;
            }
            listOperations(list);
            break;
        }
        default:
        {
            std::cout << "Invalid choice!\nGoing Back!\n";
            break;
        }
        }
    }
    catch (std::runtime_error err)
    {
        std::cout << err.what() << "\n";
    }
    catch (...)
    {
        std::cout << "Unknown error!\n";
    }
    return;
}

template <class T>
void listConstructor()
{
    std::cout << "\nSelect how do you want to construct the list:\n";
    std::cout << "0. [Go Back]\n";
    std::cout << "1. Construct an empty list\n";
    std::cout << "2. Construct a list of given size filled with given value\n";
    std::cout << "3. Construct a list of given size filled with garbage value\n";
    std::cout << "4. Construct a list from another list (to be input)\n\n";
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;
    switch (choice)
    {
    case 0:
    {
        break;
    }

    case 1:
    {
        ds_cpp::doublyLinkedList<T> list;
        listOperations(list);
        break;
    }

    case 2:
    {
        std::cout << "Enter the size of the list: ";
        int size;
        std::cin >> size;
        std::cout << "Enter the value to be filled: ";
        T value;
        std::cin >> value;
        ds_cpp::doublyLinkedList<T> list(size, value);
        listOperations(list);
        break;
    }

    case 3:
    {
        std::cout << "Enter the size of the list: ";
        int size;
        std::cin >> size;
        ds_cpp::doublyLinkedList<T> list(size);
        listOperations(list);
        break;
    }

    case 4:
    {
        std::cout << "Enter the size of reference list: ";
        int size;
        std::cin >> size;
        ds_cpp::doublyLinkedList<T> referenceList(size);
        std::cout << "Enter the elements of reference list: ";
        for (int i = 0; i < size; i++)
        {
            std::cin >> referenceList[i];
        }
        ds_cpp::doublyLinkedList<T> list(referenceList);
        listOperations(list);
        break;
    }

    default:
    {
        std::cout << "Invalid choice!\nGoing Back!\n";
        break;
    }
    }
    return;
}

int main()
{
    bool tryAgain = true;
    while (tryAgain)
    {
        std::cout << "\nSelect the type of list you want to use:\n";
        std::cout << "0. [Exit]\n";
        std::cout << "1. String  (string)\n";
        std::cout << "2. Integer (int)\n";
        std::cout << "3. Double  (double)\n";
        std::cout << "4. Character (char)\n\n";
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;
        switch (choice)
        {
        case 0:
        {
            tryAgain = false;
            break;
        }
        case 1:
        {
            listConstructor<std::string>();
            break;
        }
        case 2:
        {
            listConstructor<int>();
            break;
        }
        case 3:
        {
            listConstructor<double>();
            break;
        }
        case 4:
        {
            listConstructor<char>();
            break;
        }
        default:
        {
            std::cout << "Invalid choice!\nExiting!\n";
            tryAgain = false;
            break;
        }
        }
    }
    return 0;
}