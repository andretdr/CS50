


if (list == NULL)
{
    list = n;
}
else
    if (n->number < list->number) // if number is at start
    {
        n->next = list;
        list = n;
    }
    else // iterate
    {
        for (node *ptr = list; ptr != NULL; ptr = ptr->next)
        {
            if (ptr->next == NULL) // If at the end
            {   // append
                ptr->next = n;
                break;
            }
            if (n->number < ptr->next->number)
            {
                n->next = ptr->next;
                ptr->next = n;
                break;
            }
        }
    }
