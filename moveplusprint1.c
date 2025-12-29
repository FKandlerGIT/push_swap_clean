/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveplusprint1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:17:48 by fekandle          #+#    #+#             */
/*   Updated: 2025/12/15 19:04:40 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_sa(struct Node **head)
{
	swap(head);
	ft_printf("sa\n");
}
void	ft_rra(struct Node **head)
{
	rotate(head);
	ft_printf("rra\n");
}
void	ft_ra(struct Node **head)
{
	if (*head == NULL || (*head)->next == NULL)
        return;
	reverse_rotate(head);
	ft_printf("ra\n");
}
void	ft_pa(struct Node **A, struct Node **B)
{
	push(B, A);
	ft_printf("pa\n");
}
void	ft_pb(struct Node **A, struct Node **B)
{
	push(A, B);
	ft_printf("pb\n");
}
