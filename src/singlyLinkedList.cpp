#include "./../include/singlyLinkedList.hh"

template <class T>
ds_cpp::singlyLinkedList<T>::singlyLinkedList()
{
    this = new singlyLinkedList<T>();
    head = nullptr;
    tail = nullptr;
}

template <class T>
ds_cpp::singlyLinkedList<T>::singlyLinkedList(const singlyLinkedList<T> &list)
{
    this = new singlyLinkedList<T>();
    this->head = nullptr;
    this->tail = nullptr;
    node *curr = list.head;
    while (curr != nullptr)
    {
        this->push_back(curr->val);
        curr = curr->next;
    }
}

template <class T>
ds_cpp::singlyLinkedList<T>::~singlyLinkedList()
{
    delete this;
}

template <class T>
void ds_cpp::singlyLinkedList<T>::push_back(const T &val)
{
    node *newNode = new node;
    newNode->val = val;
    newNode->next = nullptr;
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

