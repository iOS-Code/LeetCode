
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *p1 = NULL, *m1 = NULL;
    struct ListNode *tmpNode = NULL;
    
    p1 = l1;
    m1 = l2;
    
    struct ListNode *retList = NULL;
    struct ListNode *lastNode = retList;
    
    int carry = 0, TotalSum = 0, tmpSum = 0, val1 = 0, val2 = 0;
    
    while(p1 || m1)
    {
        val1 = (p1 ? p1->val : 0);
        val2 = (m1 ? m1->val : 0);
        
        TotalSum = val1 + val2 +carry;
        
        carry = TotalSum / 10;
        
        tmpSum = TotalSum % 10;
        
        tmpNode = malloc(sizeof(struct ListNode));
        tmpNode->next = NULL;
        tmpNode->val = tmpSum;
        
        if (!retList)
        {
            retList = tmpNode;
            lastNode = retList;
        }
        else
        {
            lastNode->next = tmpNode;
            lastNode = tmpNode;
        }
        
        //go ahead
        if(p1)
            p1 = p1->next;
        
        if(m1)
            m1 = m1->next;
    }
    
    if (carry)
    {
        tmpNode = malloc(sizeof(struct ListNode));
        tmpNode->next = NULL;
        tmpNode->val = carry;
        
        if (!retList)
        {
            retList = tmpNode;
            lastNode = retList;
        }
        else
        {
            lastNode->next = tmpNode;
            lastNode = tmpNode;
        }
    }
    
    return retList;
}
