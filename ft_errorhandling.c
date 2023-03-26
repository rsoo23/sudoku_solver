/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errorhandling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 01:00:23 by rsoo              #+#    #+#             */
/*   Updated: 2023/03/22 01:00:23 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush-1.h"

int ft_checkarg(int ac, char **av)
{
    if (ac != 10 || !ft_checkarglen(av))
    {
        if (ac != 10)
            ft_putstr("argument count error: 9 strings required");
        if (!ft_checkarglen(av))
            ft_putstr("argument length error: 9 characters in each string required");
        return (0);
    }
    return (1);
}

int     ft_checkarglen(char **av)
{
    int y;
    int x;

    y = 1;
    while (av[y])
    {
        x = 0;
        while (av[y][x])
            x++;
        if (x == 9)
            y++;
        else
            return (0);
    }
    return (1);
}