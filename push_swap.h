/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejonsery <ejonsery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:07:42 by ejonsery          #+#    #+#             */
/*   Updated: 2024/11/26 13:40:15 by ejonsery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h>/////////////////////////////////////

//int		*aaraytoiaray(char **av, int ac);
int		ft_tablen(char **tab);
void	rra(char	**tab);
void	ra(char **tab);
void	sb(char **tab);
void	sa(char **tab);
void	pb(char	**atab, char	**btab);
void	pa(char	**atab, char	**btab);
void	rb(char **tab);
void	rrb(char	**tab);
void	rrr(char **atab, char **btab);
void	rr(char **atab, char **btab);
void	ss(char **atab, char **btab);
int		the_biggest(char *nbr, char **tabb);
int		the_smallest(char *nbr, char **tabb);

#endif