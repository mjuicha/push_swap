/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:29:12 by mjuicha           #+#    #+#             */
/*   Updated: 2024/07/28 12:24:38 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//return the last element of the list
t_stack *ft_lstlast(t_stack *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next)
        lst = lst->next;
    return (lst);
}
//add a new element at the end of the list
void    ft_lstadd_back(t_stack **lst, t_stack *new)
{
    t_stack *node;

    if (!*lst)
    {
        *lst = new;
        return ;
    }
    node = *lst;
    node = ft_lstlast(node);
    node->next = new;
}
//create a new element
t_stack    *ft_lstnew(int content)
{
    t_stack *new;

    new = (t_stack *)malloc(sizeof(t_stack));
    if (!new)
        return (NULL);
    new->value = content;
    new->next = NULL;
    return (new);
}
//error message
void    ft_error(void)
{
    write(2, "Error\n", 6);
    exit(0);
}
//error message and free the stack
void    push_swap_error(t_stack **stack)
{
    free_stack(*stack); 
    ft_error();
}
//free the stack
void    free_stack(t_stack *stack)
{
    t_stack *tmp;

    while (stack)
    {
        printf("%d\n", stack->value);
        tmp = stack;
        stack = stack->next;
        free(tmp);
    }
    printf("free\n");
}