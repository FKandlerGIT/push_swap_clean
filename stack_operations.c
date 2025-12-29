/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 01:39:23 by marvin            #+#    #+#             */
/*   Updated: 2025/12/29 20:21:30 by fekandle         ###   ########.fr       */
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

void	appendNode(struct s_Node **head, int value)
{
	struct s_Node	*newNode;
	struct s_Node	*temp;

	newNode = createNode(value);
	if (*head == NULL)
	{
		*head = newNode;
		return ;
	}
	temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
}

void	push(struct s_Node **src, struct s_Node **dest)
{
	struct s_Node	*temp;

	if (*src == NULL)
		return ;
	temp = *src;
	*src = (*src)->next;
	if (*src != NULL)
		(*src)->prev = NULL;
	temp->prev = NULL;
	temp->next = *dest;
	if (*dest != NULL)
		(*dest)->prev = temp;
	else
		temp->next = NULL;
	*dest = temp;
}

void	rotate(struct s_Node **stack)
{
	struct s_Node	*tail;
	struct s_Node	*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	tail = temp;
	temp->prev->next = NULL;
	tail->prev = NULL;
	tail->next = *stack;
	(*stack)->prev = temp;
	*stack = tail;
}

void	reverse_rotate(struct s_Node **stack)
{
	struct s_Node	*current;
	struct s_Node	*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	*stack = temp->next;
	(*stack)->prev = NULL;
	current = *stack;
	while (current->next != NULL)
		current = current->next;
	current->next = temp;
	temp->prev = current;
	temp->next = NULL;
}
void	swap(struct s_Node **stack)
{
	struct s_Node	*first;
	struct s_Node	*second;
	struct s_Node	*third;

	first = *stack;
	second = first->next;
	third = second->next;
	*stack = second;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third)
		third->prev = first;
}

void	printStack(struct s_Node *stack)
{
	while (stack != NULL)
	{
		printf("%d -> ", stack->data);
		stack = stack->next;
	}
	printf("NULL\n");
}

void	freeList(struct s_Node *head)
{
	struct s_Node	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
