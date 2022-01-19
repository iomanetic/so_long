/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:29:25 by tyuuki            #+#    #+#             */
/*   Updated: 2022/01/18 14:30:37 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	non_valid_numbers_arg(void)
{
	printf(YELLOW "%s", NVA);
	exit(0);
}

void	error_file_name(void)
{
	printf(YELLOW "%s", NVF);
	exit(0);
}

int	check_file_name(char *ag)
{
	int	i;

	i = 0;
	while (ag[i] && ag[i] != '.')
		i++;
	if (!(ft_strncmp(&ag[i], ".ber")))
		return (0);
	return (1);
}
