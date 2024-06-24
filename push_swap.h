/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:37:04 by mjuicha           #+#    #+#             */
/*   Updated: 2024/06/23 17:15:54 by mjuicha          ###   ########.fr       */
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
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct s_stack_pair
{
	t_stack	*sta;
	t_stack	*stb;
}	t_stack_pair;

// int			main(int ac, char **av);
int			check_input(int ac, char **av);
static int	count_words(char *s, char c);
static char	*get_word(char *s, char c);
static void	*ft_free(char **arr, int n);
void		refill(t_stack **a, t_stack **b, t_stack **sa, t_stack **sb);
char		**ft_split(char *s, char c);
int			ft_isdigit(int c);
t_stack		*create_node(int value);
t_stack		*push_stack(t_stack **a, char *av);
int			ft_atoi( char *str);
static int	is_sspace(char *str, int *pt);
static int	isoverflow(long long int check, long long int res);
static int	max_int(long long int r, int s);
void		print(t_stack *a);
int			check_rep(t_stack *a, t_stack *b);
void		swap(t_stack **a);
void		swap_a(t_stack **a, int i);
void		swap_b(t_stack **b, int i);
void		swap_s(t_stack **a, t_stack **b, int i);
void		rotate(t_stack **a);
void		rot_a(t_stack **a, int i);
void		rot_b(t_stack **b, int i);
void		rot_r(t_stack **a, t_stack **b, int i);
void		r_rotate(t_stack **a);
void		r_rot_a(t_stack **a, int i);
void		r_rot_b(t_stack **b, int i);
void		r_rot_r(t_stack **a, t_stack **b, int i);
int			push(t_stack **a, t_stack **b);
void		push_a(t_stack **a, t_stack **b, int i);
void		push_b(t_stack **a, t_stack **b, int i);
void		algorithem(t_stack **a, t_stack **b);
int			less_stack_a(t_stack **sta);
void		last_swap(t_stack **a);
int			check_asc(t_stack **sta);
void		sort_three(t_stack **a);
t_stack		*max(t_stack **a);
t_stack		*min(t_stack **a);
t_stack		*cheap_max(int c, t_stack **a);
void		give_index(t_stack **a);
int			cheapest(t_stack **a, t_stack **b, int *pi);
int			count_stack(t_stack **sta);
t_stack		*clever_chosing(t_stack **a, t_stack **b, int *pi);
void		class_b(t_stack **a, t_stack **b, int *pi);
void		first_push(t_stack **sta, t_stack **stb, int *pi);
void		less_3(t_stack **sta);
void		logic(t_stack **a, t_stack **b);
t_stack		*choosing(t_stack **a, int i);
void		done_a(t_stack **a, t_stack *node, int *pi, t_stack **b);
void		do_a(t_stack **a, t_stack *node, int *pi, t_stack **b);
void		done_b(t_stack **a, t_stack **b, int *pi);
void		do_b(t_stack *a, t_stack **b, int *pi);
t_stack		*copy_stack(t_stack *original);
t_stack		*br(t_stack *a, t_stack *b);
void		clever_class(t_stack **a, t_stack **b);
t_stack		*cheap_min(int c, t_stack **a);
void		class_a(t_stack **a, t_stack **b);
void		asc(t_stack **a);
t_stack		*br1(t_stack *a, t_stack *b);
void		free_prev_stack(t_stack *stack);
void		free_stack(t_stack *stack);
int			new_winner(t_stack *node, t_stack **w, int *pt);
void		free_stacks(t_stack *sta, t_stack *stb);
void		rra(t_stack **sta, int *pt, int i);
void		ra(t_stack **sta, int *pt, int i);
void		rrb(t_stack **stb, int *pt, int i);
void		rb(t_stack **stb, int *pt, int i);
void		rr1(t_stack **sta, t_stack **a, t_stack **b, int *pt);
void		rrr1(t_stack **sta, t_stack **a, t_stack **b, int *pt);
void		rr0(t_stack **sta, t_stack **a, t_stack **b, int *pt);
void		rrr0(t_stack **sta, t_stack **a, t_stack **b, int *pt);
void		give_indexs(t_stack **a, t_stack **b);
int			init(t_stack **sa, t_stack **a, t_stack **b);
t_stack		*store_stack(t_stack *new);
t_stack		*loop(t_stack *sta, int *pi, t_stack **a, t_stack **b);
/*get_next_line prototype*/

char		*get_next_line(int fd);
size_t		ft_strlen(char *s);
char		*empty_str(void);
char		*ft_strchr(const char *str, int c);
char		*ft_strjoin(char *str, char *buff);
char		*the_line(char *str);
char		*next_line(char *str);
char		*read_line(int fd, char *str);

/*checker prototype*/
int			main(int ac, char *av[]);
void		my_algo(t_stack **a, t_stack **b);
void		xxxx(t_stack **a, char *av, int *pt);
void		do_it(char *s, t_stack **a, t_stack **b, int i);
int			correct_input(char *s);
void		doswap(char *s, t_stack **a, t_stack **b);
void		dorot(char *s, t_stack **a, t_stack **b);
void		dorrot(char *s, t_stack **a, t_stack **b);
void		dopush(char *s, t_stack **a, t_stack **b);
#endif
