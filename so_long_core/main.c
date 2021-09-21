/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 11:18:38 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/21 14:33:41 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	ft_swap(void *a, void *b)
{
	void	*tmp;

	tmp = ft_memsetmal('\0', sizeof(void) * 1);
	if (tmp == NULL)
		return ;
	ft_memcpy(tmp, a, 1);
	ft_memcpy(a, b, 1);
	ft_memcpy(b, tmp, 1);
	ft_memdel(&tmp);
}

void	ft_strrev(char *str)
{
	size_t	str_len;
	int		i;
	int		j;

	str_len = ft_strlen((const char *)str);
	i = -1;
	while (++i < (int)str_len / 2)
	{
		j = (int)str_len - i - 1;
		ft_swap(&str[i], &str[j]);
	}
}

int	main(int argc, char **argv)
{
	t_file	file;
	t_map	map;

char *str = "\"p V C V C C m p p p p p f 3 B V B m 2 < p p B p D Z p m p < % m f m m \"| \
\"p B m m m m m p p p p 3 n 2 m V B 3 < 2 m m B 3 R V m m B < % b p m m \"| \
\"3 V f f b m m i p 2 b g 0 z A B V 3 < 2 m m m p R V b m V : % p p m m \"| \
\"3 V m p f m m p f l q  . .= s A B p 2 3 p m m p H m m m m < % p f m m \"| \
\"3 N m m p B m p F F i J x.i.K w A m < p p B V p Z m f m m < : p f p m \"| \
\"3 m m m f m V 3 > % k O X.v.c...w 3 1 < p m m p G V f m m < i C m C m \"| \
\"< B 3 m m m m 3 m g n e | l.v.l.a.f = M f m Z p R V m m m < : a 2 i 3 \"| \
\"% p m B m m 3 m m B V h S k.c.b.5.g.x 0 Z p G g D B f p m < : p p m 3 \"| \
\"# 3 m m m m 3 m m 3 c V 2 g.5.~.~.&.h.P + n i < V B b m m < m G C G B \"| \
\"# 3 m B m m B 3 3 m b V ; p.1.B.#X^.*.x.W q D u 3 m B 3 p < 3 V 3 f m \"| \
\"# p p m m B B p m 3 m V , g.l.$..X%X).<.h.! t k 2 V B 3 m < 3 B f B m \"| \
\"$ p 3 m m m B p f m m m b h.z.@.(.%X$X_.1.u.U + m Z B 3 B < m m b m m \"| \
\"$ m p B C B V b 4 f M d L k.z.#./.%X+X$X_.1.0.d z H i p C : m m b m m \"| \
\"$ g i 2 g p 3 i p f M w  .z.z.@.(.%X@X@X$X_.,.y.A - < < 2 : m m m m f \"| \
\"% m m < 2 2 2 < p p A 0 0.z.l.@.{.$X@X@X#X$X^.>.P s V m F p N B m m f \"| \
\": C B p m f f < 3 m M r g.z.4.;.oX$X@X#X#X#X$XE.( I V B Z 3 Z V m m m \"| \
\": V p p m p 4 < i n ; L z.v.#.T.$X@X#X@X#X+X#X+Xn.  C m f 2 Z V m m b \"| \
\": B f f m f f < 3 A = 0.z.l.o.{.$X@X#X#X#X#X@X%XQ.@ p N m 2 C N c m p \"| \
\": m m m m f f < m m - u.v.#.M.$X@X#X#X#X#X#X#X$X XT & N m 3 Z Z f B b \"| \
\"% m m f m m f > A 0  .3.f.o.|.$X@X#X#X@X$X#X@X$X#X/ . N B 3 V Z B B p \"| \
\": m B m l B f < b 0 p.3.' T.%X@X#X@X#X@XW.}.%X X{.I.. m B 3 V V p f m \"| \
\": B m m m B 3 k 0  .z.3.' }.%X@X#X#X$X@X} P.%X].m.Y.u 1 N 2 V Z p p f \"| \
\": B p m 3 B p k 0 } z.g.' !.$X@X#X@X@X$XU.m.$X].W.].k i N 3 Z V i b f \"| \
\": B m B 3 m m < n 0 i.z.O.o..X$X#X'.`.OX#X#X#X$X+XB._ r B p C Z p B m \"| \
\": V p m m m m > b j K c.k.' T.$X+X`.H.J.'.XXOX|.N.1.9.w V 3 B G 2 g g \"| \
\"2 C m m m m m < : v + [ z.f.' /.%X'.H.L.J.J.G.=.j.s.i f m 3 2 < % : < \"| \
\"3 B m m m m m < m Z C [ -.z.4.O.[.XXJ.K.L.G.6.v.a.0 s m f 3 p F m F b \"| \
\"p N B m m m m < B a Y w.o.:.v.j.2.~.R.S.b.2.d.+.%.7.i f B p m C B Z B \"| \
\"4 Z m m m B m < c 8 ~ Z.o.' @.f.:.` ..{ [ ] %.o.t.A.y p V 4 2 B m m m \"| \
\"f Z m m m B m : Y 6 q.J.r.w.%.) C e X * e v  .e.F.J.Q 9 m 3 < V m m m \"| \
\"p V B m m B p c : Y F.K.J.A.E d B V l 1 M i s U ^ V.Q u V 3 % m m B m \"| \
\"p V m B p b m c 7 ^ D.C.8.U I D Z Z < : m l b 9 7 5 m B m 3 < m f m B \"| \
\"p Z T V C G m 2 b f 7 7 5 o m < i p % : m p B m N C C G m 2 < m m m m \"| \
\"3 f i < i p < < m p i V c c p p i 2 < : m p B p < : % % % $ % b b m f \"| \
\"2 2 < 2 2 3 < 2 m p p B m p G G Z C 3 : p b m p V G i m F < % B m m m \"";

	char **strs = ft_split(str, "|");
	for (int i = 0; strs[i] != NULL; i++)
	{
		ft_strrev(strs[i]);
		ft_putstr((const char *)strs[i]);
		ft_putendl(",");
	}
	
	if (argc == 2)
	{
		if (parse_file(&file, SET, argv[1]) == -1)
		{
			ft_memdel((void **)&file.content);
			system("leaks so_long");
			exit(EXIT_FAILURE);
		}
		if (parse_map(&map, file.content) == -1)
		{
			ft_memdel((void **)&file.content);
			system("leaks so_long");
			exit(EXIT_FAILURE);
		}
		if (so_long(map) == -1)
		{
			system("leaks so_long");
			exit(EXIT_FAILURE);
		}
	}
	exit(EXIT_FAILURE);
}
