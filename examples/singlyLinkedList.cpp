#include "./../header/singlyLinkedList.hh"
#include <iostream>
#include <string>
#include <vector>

using namespace ds_cpp;
using namespace std;

int main()
{
    cout << endl;
    cout << endl;

    // Instantiating a singly linked list of strings:
    singlyLinkedList<string> list_1;

    // You can make a list of any combination of data structures:
    singlyLinkedList<pair<int, vector<int>>> list_2;

    // Adding elements to the list:
    list_1.push_front("World!");
    list_1.push_front("Hello");

    // [] operator can be used as well:
    for (int i = 0; i < list_1.size(); i++)
        cout << list_1[i] << " ";
    cout << endl;
    cout << endl;

    list_1.push_back("This");
    list_1.push_back("is");
    list_1.push_back("a");
    list_1.push_back("Singly Linked");
    list_1[5] += " List";
    list_1.push_back("of");
    list_1.push_back("Strings!");

    // Removing elements from the list one by one (list.clear() can also be used):
    while (list_1.size())
        cout << list_1.pop_front() << " ";
    cout << endl;
    cout << endl;

    // Adding elements to list_2:
    list_2.push_front(make_pair(2, vector<int>{2, 3}));
    list_2.push_front(make_pair(1, vector<int>{1}));
    list_2.push_back(make_pair(3, vector<int>{4, 5, 6}));

    cout << "Follwing is a Singly Linked List of pair<int, vector<int>>: " << endl;
    for (int i = 0; i < list_2.size(); i++)
    {
        cout << list_2[i].first << ": ";
        for (int j = 0; j < list_2[i].second.size(); j++)
            cout << list_2[i].second[j] << " ";
        cout << endl;
    }
    cout << endl;

    return 0;
}

/*

OUTPUT:


Hello World!

Hello World! This is a Singly Linked List of Strings!

Follwing is a Singly Linked List of pair<int, vector<int>>:
1: 1
2: 2 3
3: 4 5 6


*/