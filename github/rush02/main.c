/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:45:37 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/02/16 14:01:18 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	sum(char n1, char n2)
{
	//int total;
	//total=n1+n2;
	return (n1);
}

int	main(int argc, char **argv)
{
	char numero;
	int i;
	i= sum(&argv[1], &argv[2]);
	numero=i+'0';
	write(1, &numero,1);
}
