/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:59:30 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/02 20:33:10 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_stack
{
	int				value;
	int				index;
	int				best_score;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

char		**ft_split(char *s, char c);
int			ft_atoi(char *str);
void		algorithem(t_stack **a, t_stack **b);
void		sort_three(t_stack **a);
int			check_asc(t_stack **sta);
int			count_stack(t_stack	**sta);
t_stack		*max(t_stack **a);
t_stack		*min(t_stack **a);
void		class_b(t_stack **a, t_stack **b, int *pi);
t_stack		*loop(t_stack *sta, int *pi, t_stack **a, t_stack **b);
int			init(t_stack **sa, t_stack **a, t_stack **b);
t_stack		*choosing(t_stack **a, int i);
t_stack		*cheap_max(int c, t_stack **b);
t_stack		*copy_stack(t_stack *original);
void		give_index(t_stack **a);
void		free_stack(t_stack *stack);
void		refill(t_stack **a, t_stack **b, t_stack **sa, t_stack **sb);
void		free_stacks(t_stack *sta, t_stack *stb);
int			new_winner(t_stack *node, t_stack **w, int *pt);
void		done_a(t_stack **a, t_stack *node, int *pi);
void		done_b(t_stack **a, t_stack **b, int *pi);
void		class_a(t_stack **a, t_stack **b);
void		asc(t_stack **a);
void		push_a(t_stack **a, t_stack **b, int i);
void		push_b(t_stack **a, t_stack **b, int i);
void		swap_a(t_stack **a, int i);
void		swap_b(t_stack **b, int i);
void		swap_s(t_stack **a, t_stack **b, int i);
void		r_rot_a(t_stack **a, int i);
void		r_rot_b(t_stack **b, int i);
void		r_rot_r(t_stack **a, t_stack **b, int i);
void		rot_a(t_stack **a, int i);
void		rot_b(t_stack **b, int i);
void		rot_r(t_stack **a, t_stack **b, int i);
void		rra(t_stack **sta, int *pt, int i);
void		ra(t_stack **sta, int *pt, int i);
void		rrb(t_stack **stb, int *pt, int i);
void		rb(t_stack **stb, int *pt, int i);
void		do_a(t_stack **a, t_stack *node, int *pi);
void		do_b(t_stack *a, t_stack **b, int *pi);
void		my_algo(t_stack **a, t_stack **b);
int			ft_strcmp(char *s1, char *s2);
void		doswap(char *s, t_stack **a, t_stack **b);
void		dorot(char *s, t_stack **a, t_stack **b);
void		dorrot(char *s, t_stack **a, t_stack **b);
void		dopush(char *s, t_stack **a, t_stack **b);
char		*get_next_line(int fd);
size_t		ft_strlen(char *s);
char		*empty_str(void);
char		*ft_strchr(const char *str, int c);
t_stack		*ft_lstlast(t_stack *lst);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack		*ft_lstnew(int content);
void		ft_error(void);
void		push_swap_error(t_stack **stack);
void		fill_stack(t_stack **stack, char **av);
char		*ft_strdup(char *s1);
char		*ft_strjoin(char *s1, char *s2);
char		**ft_check_args(char **av);
void		free_2d_array(char **av);
void		spec(t_stack **sta, t_stack **stb);
#endif