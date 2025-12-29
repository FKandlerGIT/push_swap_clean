/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_prep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 01:38:45 by marvin            #+#    #+#             */
/*   Updated: 2025/12/29 20:28:15 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

struct s_Node	*find_lowest_unprocessed_number(struct s_Node *head)
{
	struct s_Node	*lowest_node;
	struct s_Node	*current;

	lowest_node = NULL;
	current = head;
	while (current != NULL)
	{
		if (current->process == 'u')
		{
			if (lowest_node == NULL || current->data < lowest_node->data)
			{
				lowest_node = current;
			}
		}
		current = current->next;
	}
	return (lowest_node);
}

int	process_lowest_unprocessed_number(struct s_Node *head, int newValue)
{
	struct s_Node	*lowest_node;

	lowest_node = find_lowest_unprocessed_number(head);
	if (lowest_node != NULL)
	{
		lowest_node->data = newValue;
		lowest_node->process = 'p';
		return (1);
	}
	return (0);
}

int	bitsize(struct s_Node *data)
{
	int				count;
	struct s_Node	*temp;
	int				bit_length;

	count = 0;
	temp = data;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	if (count == 0)
		return (0);
	bit_length = 0;
	while ((1 << bit_length) < count)
		bit_length++;
	return (bit_length);
}

void	int_to_binary(int value, char *binary, int bitSize)
{
	int	i;

	i = 0;
	while (i < bitSize)
	{
		binary[i] = '0';
		i++;
	}
	i = bitSize - 1;
	while (i >= 0)
	{
		if (value & 1)
			binary[i] = '1';
		else
			binary[i] = '0';
		value >>= 1;
		i--;
	}
	binary[bitSize] = '\0';
}

void	update_binary_representation(struct s_Node *head)
{
	struct s_Node	*current;
	int				bit_length;

	current = head;
	while (current != NULL)
	{
		bit_length = bitsize(head);
		int_to_binary(current->data, current->binary, bit_length);
		current = current->next;
	}
}

int	all_processed(struct s_Node *head)
{
	struct s_Node	*current;

	current = head;
	while (current != NULL)
	{
		if (current->process == 'u')
			return (0);
		current = current->next;
	}
	return (1);
}
