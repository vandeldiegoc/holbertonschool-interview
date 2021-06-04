#include "lists.h"
/**
 * detec_loop - return loop inf
 * @pt: pointer next headposition
 * @pt_next: next pt
 * Return: poibter where the loop start
 */
listint_t *detec_loop(listint_t *pt, listint_t *pt_next)
{
	while (pt != pt_next)
	{
		pt = pt->next;
		pt_next = pt_next->next;
	}
	return (pt);
}
/**
 * find_listint_loop - that finds the loop in a linked lis
 * @head: address pointer head
 * Return: number of nodes
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *pt, *pt_next;

	if (head)
	{
		pt = head->next;
		pt_next = head->next->next;
		while (pt && pt_next)
		{
			if (pt == pt_next)
			{
				pt = head;
				return (detec_loop(pt, pt_next));
			}
			pt = pt->next;
			pt_next = pt_next->next->next;
		}
	}
	return (0);
}
