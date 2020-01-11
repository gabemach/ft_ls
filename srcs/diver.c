/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diver.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 12:15:30 by gmachado          #+#    #+#             */
/*   Updated: 2020/01/09 15:03:08 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void    diver(t_ls *ls, struct dirent *dp)
{
    DIR *dr;

    if ((dr = opendir(ls->name)) == NULL)
        exit(1);
    while ((dp = readdir(dr)) != NULL)
    {
        // if (ls->active[0] == 'R')
        //     diver(ls, dp);
        ft_printf("%s\n", dp->d_name);
    }
    closedir(dr);
}