#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST
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

    public:
        singlyLinkedList();
        singlyLinkedList(const singlyLinkedList<T> &list);
        ~singlyLinkedList();
        void push_back(const T &val);
        void push_front(const T &val);
        T pop_back();
        T pop_front();
        T &back();
        T &front();
        void insert(const T &val, int index);
        void insert(const T &val, const node* pos);
        void erase(int index);
        void erase(const node* pos);
        void clear();
        void print();
        void reverse();
        int size();
        bool empty();
        T& operator[](int index);
        singlyLinkedList<T>& operator=(const singlyLinkedList<T> &list);
    };
}
#endif // !SINGLY_LINKED_LIST