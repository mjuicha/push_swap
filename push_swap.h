/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:59:30 by mjuicha           #+#    #+#             */
/*   Updated: 2024/07/09 01:41:47 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>

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

//utils.c
int			count_words(char *s, char c);
char		*get_word(char *s, char c);
void		*ft_free(char **arr, int n);
char		**ft_split(char *s, char c);
//checker.c
int			check_input(int ac, char **av);
int			check_rep(t_stack *a, t_stack *b);
void		pusher(t_stack **a, char *av, int *pt);
void		check_over(long long int i, int *pt);
//ft_isdigit.c
int			ft_isdigit(int c);
//ft_atoi.c
int			isoverflow(long long int check, long long int res);
int			max_int(long long int r, int s);
int			is_sspace( char *str, int *pt);
int			ft_atoi(char *str);
//push_stack.c
t_stack		*create_node(int value);
t_stack		*push_stack(t_stack **a, char *av);
//algo.c
void		algorithem(t_stack **a, t_stack **b);
void		logic(t_stack **a, t_stack **b);
void		first_push(t_stack **sta, t_stack **stb, int *pi);
void		sort_three(t_stack **a);
void		less_3(t_stack **sta);
//algo_utils.c
int			check_asc(t_stack **sta);
int			count_stack(t_stack	**sta);
t_stack		*max(t_stack **a);
t_stack		*min(t_stack **a);
//class_b.c
void		class_b(t_stack **a, t_stack **b, int *pi);
t_stack		*clever_chosing(t_stack **a, t_stack **b, int *pi);
//class_utils3.c
t_stack		*loop(t_stack *sta, int *pi, t_stack **a, t_stack **b);
int			init(t_stack **sa, t_stack **a, t_stack **b);
//class_utils1.c
t_stack		*choosing(t_stack **a, int i);
t_stack		*cheap_max(int c, t_stack **b);
t_stack		*copy_stack(t_stack *original);
void		give_index(t_stack **a);
void		free_stack(t_stack *stack);
//class_utils2.c
void		refill(t_stack **a, t_stack **b, t_stack **sa, t_stack **sb);
void		free_stacks(t_stack *sta, t_stack *stb);
int			new_winner(t_stack *node, t_stack **w, int *pt);
t_stack		*rboth(t_stack *a, t_stack *b);
t_stack		*rrboth(t_stack *a, t_stack *b);
//hypo.c
void		done_a(t_stack **a, t_stack *node, int *pi, t_stack **b);
void		done_b(t_stack **a, t_stack **b, int *pi);
//class2.c
t_stack		*cheap_min(int c, t_stack **a);
void		clever_class(t_stack **a, t_stack **b);
void		class_a(t_stack **a, t_stack **b);
void		asc(t_stack **a);
//push.c
int			push(t_stack **a, t_stack **b);
void		push_a(t_stack **a, t_stack **b, int i);
void		push_b(t_stack **a, t_stack **b, int i);
//swap.c
void		swap(t_stack **a);
void		swap_a(t_stack **a, int i);
void		swap_b(t_stack **b, int i);
void		swap_s(t_stack **a, t_stack **b, int i);
//r_rotate.c
void		r_rotate(t_stack **a);
void		r_rot_a(t_stack **a, int i);
void		r_rot_b(t_stack **b, int i);
void		r_rot_r(t_stack **a, t_stack **b, int i);
//rotate.c
void		rotate(t_stack **a);
void		rot_a(t_stack **a, int i);
void		rot_b(t_stack **b, int i);
void		rot_r(t_stack **a, t_stack **b, int i);
//rr_ab.c
void		rrr1(t_stack **sta, t_stack **a, t_stack **b, int *pt);
void		rr1(t_stack **sta, t_stack **a, t_stack **b, int *pt);
void		rrr0(t_stack **sta, t_stack **a, t_stack **b, int *pt);
void		rr0(t_stack **sta, t_stack **a, t_stack **b, int *pt);
//rab.c
void		rra(t_stack **sta, int *pt, int i);
void		ra(t_stack **sta, int *pt, int i);
void		rrb(t_stack **stb, int *pt, int i);
void		rb(t_stack **stb, int *pt, int i);
//real.c
void		do_a(t_stack **a, t_stack *node, int *pi, t_stack **b);
void		do_b(t_stack *a, t_stack **b, int *pi);
//my_algo.c
int			correct_input(char *s);
void		do_it(char *s, t_stack **a, t_stack **b, int i);
void		my_algo(t_stack **a, t_stack **b);
int			ft_strcmp(char *s1, char *s2);

//do.c
void		doswap(char *s, t_stack **a, t_stack **b);
void		dorot(char *s, t_stack **a, t_stack **b);
void		dorrot(char *s, t_stack **a, t_stack **b);
void		dopush(char *s, t_stack **a, t_stack **b);
//get_next_line.c
char		*read_line(int fd, char *str);
char		*the_line(char *str);
char		*next_line(char *str);
char		*get_next_line(int fd);
//get_next_line_utils.c
size_t		ft_strlen(char *s);
char		*empty_str(void);
char		*ft_strchr(const char *str, int c);
char		*ft_strjoin(char *str, char *buffer);

#endif