/*
namespace ds_cpp
{

    class singlyLinkedList
    {
    private:
        struct node
        {
            T val;
            node *next;
        };
        node *head;
        node *tail;
        int sizeOfList;

    public:
        singlyLinkedList();
        singlyLinkedList(int);
        singlyLinkedList(int, const T &);
        singlyLinkedList(const singlyLinkedList<T> &);
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
        singlyLinkedList<T> &operator=(const singlyLinkedList<T> &);
        bool operator==(const singlyLinkedList<T> &);
        bool operator!=(const singlyLinkedList<T> &);
        singlyLinkedList<T> operator+(const singlyLinkedList<T> &);
        singlyLinkedList<T> operator+=(const singlyLinkedList<T> &);
        ~singlyLinkedList();
    };
}
*/

#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST
#include <stdexcept>

namespace ds_cpp
{
    template <class T>
    class singlyLinkedList
    {
    private:
        struct node
        {
            T val;
            node *next;
        };
        node *head;
        node *tail;
        int sizeOfList;

    public:
        singlyLinkedList()
        {
            this->head = nullptr;
            this->tail = nullptr;
            this->sizeOfList = 0;
        }

        singlyLinkedList(const singlyLinkedList<T> &list)
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

        singlyLinkedList(int sizeOfList)
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

        singlyLinkedList(int sizeOfList, const T &val)
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
            }
            else
            {
                this->tail->next = newNode;
                this->tail = newNode;
            }
            this->sizeOfList++;
            return;
        }

        void push_front(const T &val)
        {
            node *newNode = new node;
            newNode->val = val;
            newNode->next = this->head;
            this->head = newNode;
            if (this->tail == nullptr)
            {
                this->tail = newNode;
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
            node *curr = this->head;
            while (curr->next != this->tail)
            {
                curr = curr->next;
            }
            delete this->tail;
            this->tail = curr;
            this->tail->next = nullptr;
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
            this->sizeOfList++;
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
            this->tail = nodeOneBeforeStart;
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
            node *prev = nullptr;
            node *curr = this->head;
            while (curr != nullptr)
            {
                node *temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            this->tail = this->head;
            this->head = prev;
            return;
        }

        int size() const
        {
            return this->sizeOfList;
        }

        bool empty()
        {
            return this->sizeOfList == 0;
        }

        T &operator[](int index)
        {
            if (index < 0 || index >= this->size())
            {
                throw std::runtime_error("list index out of bounds");
            }
            node *curr = this->head;
            for (int i = 0; i < index; i++)
            {
                curr = curr->next;
            }
            return curr->val;
        }
        
        const T &operator[](int index) const
        {
            if (index < 0 || index >= this->size())
            {
                throw std::runtime_error("list index out of bounds");
            }
            node *curr = this->head;
            for (int i = 0; i < index; i++)
            {
                curr = curr->next;
            }
            return curr->val;
        }

        ds_cpp::singlyLinkedList<T> &operator=(const singlyLinkedList<T> &rhs)
        {
            if (this == &rhs)
            {
                return *this;
            }
            this->clear();
            node *curr = rhs.head;
            while (curr != nullptr)
            {
                this->push_back(curr->val);
                curr = curr->next;
            }
            return *this;
        }

        bool operator==(const singlyLinkedList<T> &rhs)
        {
            if (this->size() != rhs.size())
            {
                return false;
            }
            node *curr = this->head;
            node *rhsCurr = rhs.head;
            while (curr != nullptr)
            {
                if (curr->val != rhsCurr->val)
                {
                    return false;
                }
                curr = curr->next;
                rhsCurr = rhsCurr->next;
            }
            return true;
        }

        bool operator!=(const singlyLinkedList<T> &rhs)
        {
            return !(*this == rhs);
        }

        ds_cpp::singlyLinkedList<T> operator+(const singlyLinkedList<T> &rhs)
        {
            singlyLinkedList<T> *newList = new singlyLinkedList<T>(*this);
            node *curr = rhs.head;
            while (curr != nullptr)
            {
                newList->push_back(curr->val);
                curr = curr->next;
            }
            return *newList;
        }

        ds_cpp::singlyLinkedList<T> operator+=(const singlyLinkedList<T> &rhs)
        {
            node *curr = rhs.head;
            while (curr != nullptr)
            {
                this->push_back(curr->val);
                curr = curr->next;
            }
            return *this;
        }

        ~singlyLinkedList()
        {
            this->clear();
        }
    };
}

#endif // !SINGLY_LINKED_LIST