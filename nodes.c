/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    nodes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:54:41 by fekandle          #+#    #+#             */
/*   Updated: 2026/01/02 21:00:24 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

struct s_Node	*createnode(int value)
{
	struct s_Node	*newnode;

	newnode = (struct s_Node *)malloc(sizeof(struct s_Node));
	if (newnode == NULL)
	{
		printf("Memory allocation failed\n");
		exit(1);
	}
	newnode->data = value;
	newnode->process = 'u';
	newnode->binary[0] = '\0';
	newnode->next = NULL;
	newnode->prev = NULL;
	return (newnode);
}

void	append_node(struct s_Node **head, int value)
{
	struct s_Node	*newnode;
	struct s_Node	*temp;

	newnode = createnode(value);
	if (*head == NULL)
	{
		*head = newnode;
		return ;
	}
	temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newnode;
	newnode->prev = temp;
}

void	print_stack(struct s_Node *stack)
{
	while (stack != NULL)
	{
		printf("%d -> ", stack->data);
		stack = stack->next;
	}
	printf("NULL\n");
}

void	free_list(struct s_Node *head)
{
	struct s_Node	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
