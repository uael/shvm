/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shvm/word.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/12/06 12:00:10 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHVM_WORD_H
# define SHVM_WORD_H

# include <libft.h>

extern size_t	shvm_wordres(t_sds *dst, char const *src, size_t n, uint8_t *f);
extern void		shvm_wordexp(uint16_t *ac, char *av[], char const *s, size_t n);
extern t_bool	shvm_wordisvar(char const *word, size_t len);

#endif
