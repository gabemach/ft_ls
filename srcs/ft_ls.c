/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:59:03 by gmachado          #+#    #+#             */
/*   Updated: 2020/01/09 16:18:03 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void    set_flag(char flag, t_ls *ls)
{
    if (flag == 'R')
        ls->active[0] = 'R';
    if (flag == 'l')
        ls->active[1] = 'l';
    if (flag == 'a')
        ls->active[2] = 'a';
    if (flag == 'r')
        ls->active[3] = 'r';
    if (flag == 't')
        ls->active[4] = 't';
}

void    check_flags(char *flag_s, t_ls *ls)
{
    int i;
    int j;
    
    i = 1;
    while (flag_s[++i] != '\0')
    {
        j = 0;
        while (ls->flags[j] != '\0')
        {
            if (flag_s[i] == ls->flags[j])
                set_flag(flag_s[i], ls);
        }
        j++;
    }
}

void    init_struct(t_ls *ls)
{
    ls->active[0] = '\0';
    ls->active[1] = '\0';
    ls->active[2] = '\0';
    ls->active[3] = '\0';
    ls->active[4] = '\0';
    ls->flags = "Rlart";
}

void    check_input(int ac, char **av, t_ls *ls)
{
    if (av[1])
    {
        if(ft_strncmp(av[1], "-", 1) == 0)
            check_flags(av[1], ls);
        if (ft_strncmp(av[1], "-", 1) != 0 && ft_strlen(av[1]) != 0)
            ls->name = av[1];
        else if (ft_strncmp(av[1], "-", 1) == 0 && av[2])
            ls->name = av[2];
    }
    else
        ls->name = ".";
}

int main(int ac, char **av)
{
    t_ls *ls;
    t_dir   **dir;
    struct dirent   *dp;

    if (!(ls = (t_ls *)malloc(sizeof(t_ls))))
        return (-1);
    init_struct(ls);
    check_input(ac, av, ls);
    // if (av[1])
    //     ls->name = av[1];
    // else
    //     ls->name = ".";
    diver(ls, dp);
    return (0);
}