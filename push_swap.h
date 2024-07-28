/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:42:58 by mjuicha           #+#    #+#             */
/*   Updated: 2024/07/28 16:43:29 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_stack
{
    int value;
    struct s_stack *next;
} t_stack;

char    **ft_check_args(char **av);
void    fill_stack(t_stack **stack, char **av);
t_stack *ft_lstlast(t_stack *lst);
void    ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack    *ft_lstnew(int content);
void    ft_error(void);
void    push_swap_error(t_stack **stack);
void    free_stack(t_stack *stack);
char	**ft_split(char const *s, char c);
int	ft_isdigit(int c);
int	isoverflow(long long int check, long long int res);
int	is_sspace( char *str, int *pt);
int	max_int(long long int r, int s, t_stack **stack);
int	ft_atoi(char *str, t_stack **stack);
void free_2d_array(char **av);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);

#endif
