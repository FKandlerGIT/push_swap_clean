/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveplusprint2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:28:42 by fekandle          #+#    #+#             */
/*   Updated: 2025/11/20 17:37:41 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_sa_rra(struct Node **head)
{
	swap(head);
	rotate(head);
	ft_printf("sa\nrra\n");
}

void	ft_sa_ra(struct Node **head)
{
	swap(head);
	reverse_rotate(head);
	ft_printf("sa\nra\n");
}

void	ft_rb(struct Node **head)
{
	reverse_rotate(head);
	ft_printf("rb\n");
}