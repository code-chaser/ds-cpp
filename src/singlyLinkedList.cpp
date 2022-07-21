#include "./../include/singlyLinkedList.hh"

template <class T>
ds_cpp::singlyLinkedList<T>::singlyLinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
}

template <class T>
ds_cpp::singlyLinkedList<T>::singlyLinkedList(const singlyLinkedList<T> &list)
{
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
    this->clear();
}

template <class T>
void ds_cpp::singlyLinkedList<T>::push_back(const T &val)
{
    node *newNode = new node;
    newNode->val = val;
    newNode->next = nullptr;
    if (this->head == nullptr)
    {
        this->head = newNode;
        this->tail = newNode;
    }
    else
    {
        this->tail->next = newNode;
        this->tail = newNode;
    }
    return;
}

template <class T>
void ds_cpp::singlyLinkedList<T>::push_front(const T &val)
{
    node *newNode = new node;
    newNode->val = val;
    newNode->next = this->head;
    this->head = newNode;
    if (this->tail == nullptr)
    {
        this->tail = newNode;
    }
    return;
}

template <class T>
T ds_cpp::singlyLinkedList<T>::pop_back()
{
    if (this->tail == nullptr)
    {
        throw std::runtime_error("cannot pop from an empty list");
    }
    T val = this->tail->val;
    node *curr = this->head;
    while (curr->next != this->tail)
    {
        curr = curr->next;
    }
    delete this->tail;
    this->tail = curr;
    this->tail->next = nullptr;
    return val;
}

template <class T>
T ds_cpp::singlyLinkedList<T>::pop_front()
{
    if (this->head == nullptr)
    {
        throw std::runtime_error("cannot pop from an empty list");
    }
    T val = this->head->val;
    node *curr = this->head;
    this->head = this->head->next;
    delete curr;
    return val;
}

template <class T>
T &ds_cpp::singlyLinkedList<T>::back()
{
    if (this->tail == nullptr)
    {
        throw std::runtime_error("list is empty");
    }
    return this->tail->val;
}

template <class T>
T &ds_cpp::singlyLinkedList<T>::front()
{
    if (this->head == nullptr)
    {
        throw std::runtime_error("list is empty");
    }
    return this->head->val;
}

template <class T>
void ds_cpp::singlyLinkedList<T>::insert(const T &val, int index)
{
    if (index < 0 || index > this->size())
    {
        throw std::runtime_error("list index out of bounds");
    }
    node *newNode = new node;
    newNode->val = val;
    newNode->next = nullptr;
    if (index == 0)
    {
        newNode->next = this->head;
        this->head = newNode;
    }
    else
    {
        node *curr = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
    return;
}

template <class T>
void ds_cpp::singlyLinkedList<T>::insert(const T &val, const node* pos)
{
    node *newNode = new node;
    newNode->val = val;
    newNode->next = pos;
    node *curr = this->head;
    while (curr->next != pos)
    {
        curr = curr->next;
    }
    curr->next = newNode;
    return;
}

template <class T>
void ds_cpp::singlyLinkedList<T>::insertAfter(const T &val, const node* pos)
{
    node *newNode = new node;
    newNode->val = val;
    newNode->next = pos->next;
    pos->next = newNode;
    return;
}

template <class T>
void ds_cpp::singlyLinkedList<T>::erase(int index)
{
    if (index < 0 || index >= this->size())
    {
        throw std::runtime_error("list index out of bounds");
    }
    node *curr = this->head;
    if (index == 0)
    {
        this->head = this->head->next;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            curr = curr->next;
        }
        curr->next = curr->next->next;
    }
    delete curr->next;
    curr->next = nullptr;
    return;
}

template <class T>

