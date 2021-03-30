List Merge( List L1, List L2 )
{
    List head = (List)malloc(sizeof(List));
    List pHead = head;
    
    List p1 = L1->Next, p2 = L2->Next;
    while(p1&&p2)
    {
        if(p1->Data<=p2->Data)
        {
            head->Next = p1;
            p1 = p1->Next;
        }
        else
        {
            head->Next = p2;
            p2 = p2->Next;
        }
        head = head ->Next; 
    }
    head->Next = p1?p1:p2;
    L1->Next = NULL;
    L2->Next = NULL;
    return pHead;
}
