/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:14:30 by mjuicha           #+#    #+#             */
/*   Updated: 2024/07/28 16:58:52 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void f()
// {
//     system("leaks a.out");
// }

void free_2d_array(char **av)
{
    int i;

    i = 0;
    while (av[i])
    {
        free(av[i]);
        i++;
    }
    free(av);
}

int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    if (ac == 1)
        return (0);
    av = ft_check_args(av);
    fill_stack(&stack_a, av);
    free_stack(stack_a);
    free_2d_array(av);
    // atexit(f);
}