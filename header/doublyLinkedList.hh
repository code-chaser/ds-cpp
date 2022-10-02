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
            node *newNode = new node;
            newNode->val = val;
            newNode->next = nullptr;
            if (this->head == nullptr)
            {
                this->head = newNode;
                this->tail = newNode;
                newNode->prev = nullptr;
            }
            else
            {
                this->tail->next = newNode;
                newNode->prev = this->tail;
                this->tail = newNode;
            }
            this->sizeOfList++;
            return;
        }

        void push_front(const T &val)
        {   
            node *newNode = new node;
            newNode->val = val;
            newNode->prev = nullptr;
            if (!this->head)
            {
                this->head = newNode;
                this->tail = newNode;
                newNode->next = nullptr;
            }
            else
            {
                newNode->next = this->head;
                this->head->prev = newNode;
                this->head = newNode;
            }
            this->sizeOfList++;
            return;
        }

        T pop_back()
        {
            if (this->tail == nullptr)
            {
                throw std::runtime_error("cannot pop from an empty list");
            }
            T val = this->tail->val;
            if (this->head == this->tail)
            {
                this->head = nullptr;
                this->tail = nullptr;
            }
            else
            {   
                node *curr = this->tail;
                this->tail = this->tail->prev;
                this->tail->next = nullptr;
                delete curr;
            }

            this->sizeOfList--;
            return val;
        }

        T pop_front()
        {
            if (this->head == nullptr)
            {
                throw std::runtime_error("cannot pop from an empty list");
            }
            T val = this->head->val;
            node *curr = this->head;
            this->head = this->head->next;
            if (this->head == nullptr)
            {
                this->tail = nullptr;
            }
            else
            {
                this->head->prev = nullptr;
            }
            delete curr;
            this->sizeOfList--;
            return val;
        }

        T &back()
        {
            if (this->tail == nullptr)
            {
                throw std::runtime_error("list is empty");
            }
            return this->tail->val;
        }

        const T &back() const
        {
            if (this->tail == nullptr)
            {
                throw std::runtime_error("list is empty");
            }
            return this->tail->val;
        }

        T &front()
        {
            if (this->head == nullptr)
            {
                throw std::runtime_error("list is empty");
            }
            return this->head->val;
        }

        const T &front() const
        {
            if (this->head == nullptr)
            {
                throw std::runtime_error("list is empty");
            }
            return this->head->val;
        }

        void insert(const T &val)
        {
            this->push_back(val);
            return;
        }

        void insert(const T &val, int index)
        {
            if (index < 0 || index > this->size())
            {
                throw std::runtime_error("list index out of bounds");
            }
            if (index == 0)
            {
                this->push_front(val);
            }
            else if (index == this->size())
            {
                this->push_back(val);
            }
            else
            {   
                node *newNode = new node;
                newNode->val = val;
                node *curr = this->head;
                for (int i = 0; i < index - 1; i++)
                {
                    curr = curr->next;
                }
                newNode->next = curr->next;
                newNode->prev = curr;
                curr->next->prev = newNode;
                curr->next = newNode;
                this->sizeOfList++;
            }
            return;
        }

        void erase()
        {
            node *curr = this->head;
            while (curr != nullptr) 
            {
                node *temp = curr->next;
                delete curr;
                curr = temp;
            }
            this->head = nullptr;
            this->tail = nullptr;
            this->sizeOfList = 0;
            return;
        }

        void erase(int index)
        {
            if (index < 0 || index >= this->size())
            {
                throw std::runtime_error("list index out of bounds");
            }
            if (index == 0)
            {
                node *temp = this->head->next;
                delete this->head;
                this->head = temp;
                if (this->head == nullptr)
                {
                    this->tail = nullptr;
                }
                else
                {
                    temp->prev = nullptr;
                }
            }
            else
            {
                node *curr = this->head;
                for (int i = 0; i < index - 1; i++)
                {
                    curr = curr->next;
                }
                node *temp = curr->next->next;
                delete curr->next;
                curr->next = temp;
                if (curr->next == nullptr)
                {
                    this->tail = curr;
                }
                else
                {
                    temp->prev = curr;
                }
                
            }
            this->sizeOfList--;
            return;
        }

        void erase(int start, int end)
        {
            if (start < 0 || start >= this->size() || end < 0 || end >= this->size())
            {
                throw std::runtime_error("list index out of bounds");
            }
            if (start > end)
            {
                throw std::runtime_error("starting index is greater than ending index");
            }
            node *nodeOneBeforeStart = nullptr;
            node *curr = this->head;
            for (int i = 0; i < start; i++)
            {
                nodeOneBeforeStart = curr;
                curr = curr->next;
            }
            node *nodeOneAfterEnd = curr;
            for (int i = start; i <= end; i++)
            {
                nodeOneAfterEnd = nodeOneAfterEnd->next;
            }
            if (nodeOneBeforeStart == nullptr)
            {
                curr = this->head;
                while (curr != nodeOneAfterEnd)
                {
                    node *temp = curr->next;
                    delete curr;
                    curr = temp;
                }
                this->head = nodeOneAfterEnd;
                if (this->head == nullptr)
                {
                    this->tail = nullptr;
                }
            }
            else
            {
                curr = nodeOneBeforeStart->next;
                while (curr != nodeOneAfterEnd)
                {
                    node *temp = curr->next;
                    delete curr;
                    curr = temp;
                }
                nodeOneBeforeStart->next = nodeOneAfterEnd;
                if (nodeOneAfterEnd == nullptr)
                {
                    this->tail = nodeOneBeforeStart;
                }
            }
            this->sizeOfList -= (end - start + 1);
            return;
        }

        void clear()
        {
            this->erase();
            return;
        }

        void reverse()
        {

        }

        int size() const
        {
            return this->sizeOfList;
        }

        bool empty()
        {
            return this->sizeOfList == 0;
        }

        ~doublyLinkedList()
        {
            this->clear();
        }
    };
}

#endif // !DOUBLY_LINKED_LIST