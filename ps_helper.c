/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 12:04:00 by fekandle          #+#    #+#             */
/*   Updated: 2025/12/29 20:17:20 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	list_length(struct s_Node *head)
{
	int	len;

	len = 0;
	while (head)
	{
		len++;
		head = head->next;
	}
	return (len);
}

int	countStack(struct s_Node *Stack_A)
{
	struct s_Node	*counter;
	int			count;

	count = 0;
	counter = Stack_A;
	while (counter)
	{
		count++;
		counter = counter->next;
	}
	return (count);
}

void	move_Stacks(struct s_Node **Stack_A, struct s_Node **Stack_B, int bitIndex)
{
	char	bit;

	bit = (*Stack_A)->binary[bitIndex];
	if (bit == '0')
		move_and_write(pb, Stack_A, Stack_B);
	else
		move_and_write(ra, Stack_A, Stack_B);
}
