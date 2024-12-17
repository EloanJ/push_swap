/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejonsery <ejonsery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:07:42 by ejonsery          #+#    #+#             */
/*   Updated: 2024/12/17 15:04:25 by ejonsery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h>//////////////////////////////////////////////////////////////////

typedef struct s_id_val
{
	char*		value;
	char*		id;
}	t_id_val;

int		ft_tablen(char **tab);
void	rra(char	**tab);
void	ra(char **tab);
void	quiet_rra(char	**tab);
void	quiet_ra(char **tab);
void	sb(char **tab);
void	quiet_sb(char **tab);
void	sa(char **tab);
void	pb(char	**atab, char	**btab);
void	pa(char	**atab, char	**btab);
void	rb(char **tab);
void	rrb(char	**tab);
void	quiet_rb(char **tab);
void	quiet_rrb(char	**tab);
void	rrr(char **atab, char **btab);
void	rr(char **atab, char **btab);
void	ss(char **atab, char **btab);
int		the_biggest(char *nbr, char **tabb);
int		the_smallest(char *nbr, char **tabb);
char	**av_dup(char **av, int ac);
int		preswap2(char **tab);
int		best_moove(char **taba, char **tabb);
char	**tab_dup(char **tab, int len);
void	small_sort(char **taba);
void	push_groups(char **taba, char **tabb, int ac);
void	push_back(char **taba, char **tabb);
void	free_tabs(char **taba, char **tabb);
int		aff_error(int n);
int		power_of_two(int nb);
void	is_sort(char **taba);
void	sort_five(char **taba, char **tabb);
void	right_order(char **taba);

#endif