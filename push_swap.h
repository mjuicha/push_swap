/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:42:58 by mjuicha           #+#    #+#             */
/*   Updated: 2024/07/29 19:49:43 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

char		**ft_check_args(char **av);
void		fill_stack(t_stack **stack, char **av);
t_stack		*ft_lstlast(t_stack *lst);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack		*ft_lstnew(int content);
int			ft_lstsize(t_stack *lst);
void		ft_error(void);
void		push_swap_error(t_stack **stack);
void		free_stack(t_stack *stack);
char		**ft_split(char const *s, char c);
int			ft_isdigit(int c);
int			isoverflow(long long int check, long long int res);
int			is_sspace( char *str, int *pt);
int			max_int(long long int r, int s, t_stack **stack);
long int	ft_atoi(char *str, t_stack **stack);
void		free_2d_array(char **av);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);
int     	check_sorted(t_stack *stack);
t_stack		*max(t_stack **stack);
t_stack		*min(t_stack **stack);
void    	indexing_stack(t_stack *to_stack);
void		sort_stack(t_stack **stack_a, t_stack **stack_b);
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);

#endif
