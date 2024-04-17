/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:46:54 by kamsingh          #+#    #+#             */
/*   Updated: 2024/03/26 18:30:48 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "LIBFT/libft.h"

typedef struct s_list
{
	int				content;
	int				index;
	int				cost;
	struct s_list	*target;
	int				cheapest;
	int				above_median;
	struct s_list	*next;
	int				counter;
}			t_list;

typedef struct s_Stack
{
	int		cheapest;
	t_list	*stacka;
	t_list	*stackb;
}		t_Stack;

void	indexing(t_list **stack);
void	median(t_list **stack);
int		count(t_list *stack);
void	cost(t_list **stack);
void	init_stack(t_list **stacka, t_list **stackb);

int		ft_check_error2(char **s);
int		ft_isduplicate(t_list *stack);
int		ft_check_error1(char **s);
int		ft_isdigits_str(const char *str);
int		ft_error(void);
void	stack_init(t_list **stack, char **argv);
void	free_list(t_list *head);
void	sort(t_list **stacka, t_list **stackb);

void	sb(t_list **stackb);
void	sa(t_list **stacka);
void	ra(t_list **stacka);
void	rb(t_list **stackb);
void	rrb(t_list **stackb);
void	sa_r(t_list **stacka);
void	sb_r(t_list **stackb);
void	ss(t_list **stacka, t_list **stackb);
void	ra_p(t_list **stacka);
void	rb_p(t_list **stackb);
void	rra_p(t_list **stacka);
void	rrb_p(t_list **stackb);
void	rra(t_list **stacka);
void	pa(t_list **stacka, t_list **stackb);
void	pb(t_list **stacka, t_list **stackb);
void	rr(t_list **stacka, t_list **stackb);
void	rrr(t_list **stacka, t_list **stackb);

int		stacksorted(t_list **stacka);

void	sorthree(t_list **stacka);
void	sortwo(t_list **stacka);
void	easy_move_b(t_list **stackb, t_list *small);
void	easy_move_a(t_list **stacka, t_list *node);
void	move_nodes(t_list **stacka, t_list **stackb);

t_list	*smallestnumber(t_list *stacka);
t_list	*biggestnumber(t_list *stacka);
void	target_check(t_list **stacka, t_list **stackb);
void	cheapest(t_list **stacka, t_list **stackb);
t_list	*most_cheapest(t_list *stacka, t_list *stackb);

int		ft_atoi(const char *str);
int		ft_isdigits(int c);
long	ft_atol(const char *str);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **stack, t_list *newnode);
void	ft_free_all(char **s);
void	ft_checkdouble(const char *str);