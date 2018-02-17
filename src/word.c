/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/12/13 08:28:05 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shvm/word.h"

extern size_t	shvm_wordres(t_sds *dst, char const *src, size_t n, uint8_t *f);
extern void		shvm_wordexp(uint16_t *ac, char *av[], char const *s, size_t n);
extern t_bool	shvm_wordisvar(char const *word, size_t len);
