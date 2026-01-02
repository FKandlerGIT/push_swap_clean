/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 01:39:16 by marvin            #+#    #+#             */
/*   Updated: 2026/01/02 21:07:52 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	move_and_write(t_cmd command, struct s_Node **stack_a,
		struct s_Node **stack_b)
{
	int	count;

	count = 0;
	if (command == pa)
	{
		push(stack_b, stack_a);
		printf("pa\n");
		count++;
	}
	else if (command == pb)
	{
		push(stack_a, stack_b);
		printf("pb\n");
		count++;
	}
	else if (command == ra)
	{
		rotate(stack_a);
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
	struct s_Node	*stack_b;

	stack_b = NULL;
	while (list_length(*head) > 3)
	{
		if ((*head)->data == 0)
			ft_pb(head, &stack_b);
		else
			ft_ra(head);
	}
	if (list_length(*head) == 3)
		sort_3(head);
	while (stack_b != NULL)
	{
		ft_pa(head, &stack_b);
		printf("stack_b after pa: %p\n", (void *)stack_b);
	}
	if ((*head) && (*head)->next && (*head)->data > (*head)->next->data)
		ft_sa(head);
}

void	sort_5(struct s_Node **head)
{
	struct s_Node	*stack_b;

	stack_b = NULL;
	while (list_length(*head) > 3)
	{
		if ((*head)->data == 0 || (*head)->data == 1)
			ft_pb(head, &stack_b);
		else
			ft_ra(head);
	}
	if (list_length(*head) == 3)
		sort_3(head);
	while (stack_b != NULL)
	{
		ft_pa(head, &stack_b);
		printf("stack_b after pa: %p\n", (void *)stack_b);
	}
	if ((*head) && (*head)->next && (*head)->data > (*head)->next->data)
		ft_sa(head);
}

void	sorting(struct s_Node **head)
{
	t_sort			s;
	struct s_Node	*stack_a;
	struct s_Node	*stack_b;

	if (*head == NULL)
		return ;
	s.maxbits = bit_size(*head);
	stack_a = *head;
	stack_b = NULL;
	s.bitindex = s.maxbits - 1;
	while (s.bitindex >= 0)
	{
		s.count = count_stack(stack_a);
		s.i = 0;
		while (s.i < s.count)
		{
			move_stacks(&stack_a, &stack_b, s.bitindex);
			s.i++;
		}
		while (stack_b != NULL)
			move_and_write(pa, &stack_a, &stack_b);
		s.bitindex--;
	}
	*head = stack_a;
	print_stack(*head);
}
