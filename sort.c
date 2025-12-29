/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 01:39:16 by marvin            #+#    #+#             */
/*   Updated: 2025/12/27 18:00:59 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	move_and_write(cmd command, struct Node **Stack_A, struct Node **Stack_B)
{
	int	count;

	count = 0;
	if (command == pa)
	{
		push(Stack_B, Stack_A);
		printf("pa\n");
		count++;
	}
	else if (command == pb)
	{
		push(Stack_A, Stack_B);
		printf("pb\n");
		count++;
	}
	else if (command == ra)
	{
		rotate(Stack_A);
		printf("ra\n");
		count++;
	}
	else
		return (0);
	return (1);
}

void	sort_3(struct Node **head)
{
	ps	v;

	v.first = (*head)->data;
	v.second = (*head)->next->data;
	v.third = (*head)->next->next->data;
	if (v.first < v.second && v.first < v.third)
		ft_sa_ra(head);
	else if (v.third < v.first && v.third < v.second)
		ft_sa(head);
	else if (v.second < v.first && v.second < v.third)
		ft_ra(head);
	else if (v.first > v.second && v.second < v.third)
		ft_rra(head);
	else
		ft_sa_rra(head);
}

void	sort_5(struct Node **head)
{
	struct Node	*Stack_B;
	//struct Node	*current;
	//int			i;

	Stack_B = NULL;
	while (list_length(*head) > 3)
	{
		if ((*head)->data == 0 || (*head)->data == 1)
			ft_pb(head, &Stack_B);
		 else
			ft_ra(head);
		}
	if (list_length(*head)== 3)
	sort_3(head);
	while (list_length(Stack_B)==2)
	{
		ft_pa(&Stack_B, head);
		ft_pa(&Stack_B, head);
	}	
	if((*head)->data>(*head)->next->data)
		ft_sa(head);
	//*head = Stack_A;
}

void	Sorting(struct Node **head)
{
	sort		s;
	struct Node	*Stack_A;
	struct Node	*Stack_B;
	if (*head == NULL)
		return ;
	s.maxBits = bitSize(*head);
	Stack_A = *head;
	Stack_B = NULL;
	s.bitIndex = s.maxBits - 1;
	while (s.bitIndex >= 0)
	{
		s.count = countStack(Stack_A);
		s.i = 0;
		while (s.i < s.count)
		{
			move_Stacks(&Stack_A, &Stack_B, s.bitIndex);
			s.i++;
		}
		while (Stack_B != NULL)
			move_and_write(pa, &Stack_A, &Stack_B);
		s.bitIndex--;
	}
	*head = Stack_A;
	printStack(*head);
	ft_printf("%d\n ", s.count);
}
