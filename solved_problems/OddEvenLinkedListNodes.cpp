#include "minclude.h"

pair<ListNode*, ListNode*> OddEven(ListNode* head)
{
    if(!head) return {nullptr, nullptr};
    if(!head->next) return {head, nullptr};

    auto even_head = head;
    auto odd_head = head->next;

    auto even = head;
    auto odd = head->next;

    while(even && odd)
    {
        even->next = odd->next;
        even = even->next;
        if(!even) break;
        odd->next = even->next;
        odd = odd->next;
    }
    
    if(even) even->next = nullptr;
    if(odd) odd->next = nullptr;

    return {even_head, odd_head};
}

int main()
{
    ListNode* a = new ListNode(0);
    ListNode* b = new ListNode(1);
    ListNode* c = new ListNode(2);
    ListNode* d = new ListNode(3);
    ListNode* e = new ListNode(4);
    ListNode* f = new ListNode(5);
    ListNode* g = new ListNode(6);
    ListNode* h = new ListNode(7);
    ListNode* i = new ListNode(8);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g;
    g->next = h;
    h->next = i;

    const auto [even, odd] = OddEven(a);
    LogList(even);
    cout<<"\n";
    LogList(odd);
}