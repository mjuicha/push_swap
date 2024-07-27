/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:18:54 by mjuicha           #+#    #+#             */
/*   Updated: 2024/07/27 16:04:09 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}
//check if the arguments are valid
char    **ft_check_args(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    if (ac == 2)
    {
        av = ft_split(av[1], ' ');
        i = 0;
    }
    while (av[i])
    {
        j = 0;
        while (av[i][j])
        {
            if (j == 0 && (av[i][0] == '+' || av[i][0] == '-'))
				j++;
            if (!ft_isdigit(av[i][j]))
                ft_error();
            j++;
        }
        i++;
    }    
    return (av);
}

void    check_dup_and_over(void)
{}
//fill the stack with the arguments
void    fill_stack(t_stack **stack, char **av)
{
       int i;
    
        i = 0;
        while (av[i])
        {
            ft_lstadd_back(stack, ft_lst_new(ft_atoi(av[i])));
            i++;
        }
        check_dup_and_over();

}