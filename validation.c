/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 01:39:30 by marvin            #+#    #+#             */
/*   Updated: 2026/01/02 20:59:38 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_for_dupes(struct s_Node *head)
{
	struct s_Node	*current;
	struct s_Node	*duplicate_finder;

	current = head;
	duplicate_finder = NULL;
	while (current != NULL)
	{
		duplicate_finder = current->next;
		while (duplicate_finder != NULL)
		{
			if (current->data == duplicate_finder->data)
				return (1);
			duplicate_finder = duplicate_finder->next;
		}
		current = current->next;
	}
	return (0);
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_integer(char *str)
{
	if (*str == '-' || *str == '+')
	{
		str++;
		if (!is_digit(*str))
			return (0);
	}
	while (*str)
	{
		if (*str == '\0' || !is_digit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	check_all_ints(char *list[], int size)
{
	char	*arg;
	int		i;

	i = 0;
	while (i < size)
	{
		arg = list[i];
		if (*arg == '\0')
			return (1);
		if ((*arg == '+' || *arg == '-') && *(arg + 1) == '\0')
			return (1);
		if (*arg == '+' || *arg == '-')
			arg++;
		while (*arg)
		{
			if (!is_digit(*arg))
				return (1);
			arg++;
		}
		i++;
	}
	return (0);
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
