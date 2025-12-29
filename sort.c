/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 01:39:16 by marvin            #+#    #+#             */
/*   Updated: 2025/12/29 20:20:11 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	move_and_write(t_cmd command, struct s_Node **Stack_A, struct s_Node **Stack_B)
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

void	sort_3(struct s_Node **head)
{
	t_ps	v;

	v.first = (*head)->data;
	v.second = (*head)->next->data;
	v.third = (*head)->next->next->data;
	if (v.first < v.second && v.second < v.third)
		return ;
	if (v.first > v.second && v.second < v.third && v.first < v.third)
		ft_sa(head);
	else if (v.first < v.second && v.second > v.third && v.first < v.third)
		ft_sa_ra(head);
	else if (v.first < v.second && v.second > v.third && v.first > v.third)
		ft_rra(head);
	else if (v.first > v.second && v.second < v.third && v.first > v.third)
		ft_ra(head);
	else if (v.first > v.second && v.second > v.third)
		ft_sa_rra(head);
}

void	sort_4(struct s_Node **head)
{
	struct s_Node	*Stack_B;

	Stack_B = NULL;
	while (list_length(*head) > 3)
	{
		if ((*head)->data == 0)
			ft_pb(head, &Stack_B);
		else
			ft_ra(head);
	}
	if (list_length(*head) == 3)
		sort_3(head);
	while (Stack_B != NULL)
	{
		ft_pa(head, &Stack_B);
		printf("Stack_B after pa: %p\n", (void *)Stack_B);
	}
	if ((*head) && (*head)->next && (*head)->data > (*head)->next->data)
		ft_sa(head);
}

void	sort_5(struct s_Node **head)
{
	struct s_Node	*Stack_B;

	Stack_B = NULL;
	while (list_length(*head) > 3)
	{
		if ((*head)->data == 0 || (*head)->data == 1)
			ft_pb(head, &Stack_B);
		else
			ft_ra(head);
	}
	if (list_length(*head) == 3)
		sort_3(head);
	while (Stack_B != NULL)
	{
		ft_pa(head, &Stack_B);
		printf("Stack_B after pa: %p\n", (void *)Stack_B);
	}
	if ((*head) && (*head)->next && (*head)->data > (*head)->next->data)
		ft_sa(head);
}

void	Sorting(struct s_Node **head)
{
	t_sort		s;
	struct s_Node	*Stack_A;
	struct s_Node	*Stack_B;

	if (*head == NULL)
		return ;
	s.maxbits = bitSize(*head);
	Stack_A = *head;
	Stack_B = NULL;
	s.bitindex = s.maxbits - 1;
	while (s.bitindex >= 0)
	{
		s.count = countStack(Stack_A);
		s.i = 0;
		while (s.i < s.count)
		{
			move_Stacks(&Stack_A, &Stack_B, s.bitindex);
			s.i++;
		}
		while (Stack_B != NULL)
			move_and_write(pa, &Stack_A, &Stack_B);
		s.bitindex--;
	}
	*head = Stack_A;
	printStack(*head);
	ft_printf("%d\n ", s.count);
}
