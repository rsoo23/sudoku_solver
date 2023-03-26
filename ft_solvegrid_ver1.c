/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solvegrid_recursive.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:09:12 by rsoo              #+#    #+#             */
/*   Updated: 2023/03/26 18:09:12 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// recursive solution: 

//worked for easy - expert diffculty
//seg fault for others: stack overflow due to too many recursive function calls

void    ft_solvegrid(char dir, char num, char **grid, char **flag, int *startpoint, int r, int c)
{
    // printf("flag: %c, dir: %c, num: %c, grid: %c, r: %d, c: %d\n", flag[r][c], dir, num, grid[r][c], r, c);
    ft_reachrowend(grid, flag, startpoint, r, c);

    if (flag[r][c] == '0' && dir == '-')
    {
        if (c == 0 && r != 0)
            ft_solvegrid('-', grid[r - 1][8], grid, flag, startpoint, r - 1, 8);
        ft_solvegrid('-', grid[r][c - 1], grid, flag, startpoint, r, c - 1);
    }
    else if (flag[r][c] == '1')
        ft_testnum(dir, num, grid, flag, startpoint, r, c);
    ft_solvegrid('+', '1', grid, flag, startpoint, r, c + 1);
}

void    ft_biggerthannine(char **grid, char **flag, int *startpoint, int r, int c)
{
    if (r == startpoint[0] && c == startpoint[1])
    {
        ft_putstr("No existing solution");
        ft_putstr("\n");
        exit(0);
    }
    grid[r][c] = '.';
    if (c == 0 && r != 0)
        ft_solvegrid('-', grid[r - 1][8], grid, flag, startpoint, r - 1, 8);
    ft_solvegrid('-', grid[r][c - 1], grid, flag, startpoint, r, c - 1);
}

void    ft_reachrowend(char **grid, char **flag, int *startpoint, int r, int c)
{
    if (c == 9)
    {
        if (r == 8)
        {
            ft_printgrid(grid);
            exit(0);
        }
        ft_solvegrid('+', '1', grid, flag, startpoint, r + 1, 0);
    }
}

void    ft_testnum(char dir, char num, char **grid, char **flag, int *startpoint, int r, int c)
{
    if (dir == '-')
        num++;
    while (num <= '9')
    {
        if (ft_isvalid(num, grid, r, c))
        {
            grid[r][c] = num;
            // printf("input: %c\n", num);
            break ;
        }
        num++;
    }
    if (num > '9')
        ft_biggerthannine(grid, flag, startpoint, r, c);
}