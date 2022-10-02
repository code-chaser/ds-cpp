/*
namespace ds_cpp
{
    class doublyLinkedList
    {
    private:
        struct node
        {
            T val;
            node *next;
            node *prev;
        };
        node *head;
        node *tail;
        int sizeOfList;

    public:
        doublyLinkedList();
        doublyLinkedList(int);
        doublyLinkedList(int, const T &);
        doublyLinkedList(const doublyLinkedList<T> &);
        void push_back(const T &);
        void push_front(const T &);
        T pop_back();
        T pop_front();
        T &back();
        const T &back() const;
        T &front();
        const T &front() const;
        void insert(const T &);
        void insert(const T &, int);
        void erase();
        void erase(int);
        void erase(int, int);
        void clear();
        void reverse();
        int size() const;
        bool empty() const;
        T &operator[](int);
        const T &operator[](int) const;
        doublyLinkedList<T> &operator=(const doublyLinkedList<T> &);
        bool operator==(const doublyLinkedList<T> &);
        bool operator!=(const doublyLinkedList<T> &);
        doublyLinkedList<T> operator+(const doublyLinkedList<T> &);
        doublyLinkedList<T> operator+=(const doublyLinkedList<T> &);
        ~doublyLinkedList();
    };
}
*/

#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST
#include <stdexcept>

namespace ds_cpp 
{
    template <class T>
    class doublyLinkedList
    {
        private:
            struct node
            {
                T val;
                node *next;
                node *prev;
            };
            node *head;
            node *tail;
            int sizeOfList;

        public:
            doublyLinkedList()
            {
                this->head = nullptr;
                this->tail = nullptr;
                this->sizeOfList = 0;
            }

            doublyLinkedList(const doublyLinkedList<T> &list)
            {
                this->head = nullptr;
                this->tail = nullptr;
                this->sizeOfList = 0;
                node *curr = list.head;
                while (curr != nullptr)
                {
                    this->push_back(curr->val);
                    curr = curr->next;
                }
            }

            doublyLinkedList(int sizeOfList)
            {
                this->head = nullptr;
                this->tail = nullptr;
                this->sizeOfList = 0;
                for (int i = 0; i < sizeOfList; i++)
                {
                    T garbageValue;
                    this->push_back(garbageValue);
                }
            }

            doublyLinkedList(int sizeOfList, const T &val)
            {
                this->head = nullptr;
                this->tail = nullptr;
                this->sizeOfList = 0;
                for (int i = 0; i < sizeOfList; i++)
                {
                    this->push_back(val);
                }
            }

            void push_back(const T &val)
            {
                
            }

    };
}

#endif // !DOUBLY_LINKED_LIST