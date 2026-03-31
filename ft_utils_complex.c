/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_complex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zo-rakot <[zo-rakot@student.42antananar    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 21:00:19 by zo-rakot          #+#    #+#             */
/*   Updated: 2026/03/28 04:05:28 by zo-rakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void ft_radix(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
    int     i;
    int     j;
    int     size;
    int     max_bits;

    size = ft_lstsize(*stack_a);
    max_bits = 0;
    // 1. Trouver le nombre de bits du plus grand index
    // Si tu as 8 éléments (0-7), 7 en binaire est 111, donc 3 bits.
    while (((size - 1) >> max_bits) != 0)
        max_bits++;
    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            // On vérifie le bit 'i' de l'index de l'élément au sommet
            if ((((*stack_a)->index >> i) & 1))
                ft_ra(stack_a, bench); // Le bit est 1 : on le laisse dans A (rotation)
            else
                ft_pb(stack_a, stack_b, bench); // Le bit est 0 : on l'envoie dans B
            j++;
        }
        // Une fois qu'on a fait le tour de A, on vide B dans A pour le prochain bit
        while (*stack_b)
            ft_pa(stack_a, stack_b, bench);
        i++;
    }
}