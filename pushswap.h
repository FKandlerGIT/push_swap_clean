/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 01:38:23 by marvin            #+#    #+#             */
/*   Updated: 2025/12/29 20:13:04 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "Libft-v2/libft.h"
# include "PrintF-v2/ft_printf.h"
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_Variable
{
	int			i;
	int			value;
	int			newvalue;
	int			j;
	int			first;
	int			second;
	int			third;
}				t_ps;

struct			s_Node
{
	int			data;
	char		process;
	char		binary[10];

	struct s_Node	*next;
	struct s_Node	*prev;
};

typedef struct s_Sorting
{
	int			i;
	char		bit;
	int			bitindex;
	int			count;
	int			maxbits;
}				t_sort;

typedef enum move_command
{
	pa,
	pb,
	sa,
	ra,
	rb,
	rr,
	rrr,
}				t_cmd;

int				list_length(struct s_Node *head);

struct s_Node		*createNode(int value);
void			push(struct s_Node **src, struct s_Node **dest);
void			pop(struct s_Node **stack);
void			swap(struct s_Node **stack);
void			rotate(struct s_Node **stack);
void			reverse_rotate(struct s_Node **stack);
void			printStack(struct s_Node *stack);
void			loadNumbersFromFile(const char *filename, struct s_Node **head);

struct s_Node		*findLowestUnprocessedNumber(struct s_Node *head);
int				processLowestUnprocessedNumber(struct s_Node *head, int newValue);
void			intToBinary(int value, char *binary, int bitSize);
void			updateBinaryRepresentation(struct s_Node *head);
void			appendNode(struct s_Node **head, int value);
void			printList(struct s_Node *head);
int				allProcessed(struct s_Node *head);
void			countingSort(struct s_Node **head, int bit);
void			radixSort(struct s_Node **head);
void			freeList(struct s_Node *head);
int				is_integer(char *str);
int				check_for_dupes(struct s_Node *head);
int				check_all_ints(char *list[], int size);
void			Sorting(struct s_Node **head);
int				main(int argc, char *argv[]);
int				bitSize(struct s_Node *data);
int				ft_overflow(int result, int digit, int sign);
int				check_overflow_single(char *str);
int				countStack(struct s_Node *Stack_A);
int				move_and_write(t_cmd command, struct s_Node **Stack_A,
					struct s_Node **Stack_B);
void			move_Stacks(struct s_Node **Stack_A, struct s_Node **Stack_B,
					int bitIndex);
void			sort_3(struct s_Node **head);
void			sort_4(struct s_Node **head);
void			sort_5(struct s_Node **head);

int				ft_atoi(const char *str);

void			ft_sa(struct s_Node **head);
void			ft_rra(struct s_Node **head);
void			ft_ra(struct s_Node **head);
void			ft_pa(struct s_Node **A, struct s_Node **B);
void			ft_pb(struct s_Node **A, struct s_Node **B);
void			ft_sa_ra(struct s_Node **head);
void			ft_sa_rra(struct s_Node **head);
void			ft_rb(struct s_Node **head);

#endif