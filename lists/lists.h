#include <bits/stdc++.h>

using namespace std;

#ifndef LISTS_H
#define LISTS_H

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x);
};


ListNode* createList(vector<int>);
void printList(ListNode*);

#endif