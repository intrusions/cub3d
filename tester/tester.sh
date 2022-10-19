# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pducos <pducos@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 03:39:34 by pducos            #+#    #+#              #
#    Updated: 2022/10/07 23:58:11 by pducos           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

INFILES=tester/infiles/*.cub
INDIR=infiles
OUTDIR=outfiles
VALGRIND=true

OK="\033[0;32mOK\033[0m\n"
KO="\033[1;31mKO\033[0m\n"

if [[ $(uname) == 'Linux' ]];
	then
		DIFF_FLAGS="--color -Tp"
		if ! command -v valgrind > /dev/null;
			then
				>&2 echo "Notice: valgrind not installed"
				VALGRIND=false
		fi
	else
		>&2 echo "Notice: valgrind not enabled"
		VALGRIND=false
		DIFF_FLAGS="-Tp"
fi

mkdir -vp tester/$OUTDIR > /dev/null
for infile in $INFILES;
	do
		name=$(basename $infile)
		base=${name%.cub}
		outfile=tester/$OUTDIR/$base.out
		valgrind_out=tester/$OUTDIR/$base.valgrind
		expected=tester/$INDIR/$base.expected
		if [ $VALGRIND = true ];
			then
				valgrind                     \
					-q                       \
					--leak-check=full        \
					--show-leak-kinds=all    \
					--track-origins=yes      \
					--log-file=$valgrind_out \
				./cub3D --parsing-only $infile &> $outfile
			else
				./cub3D --parsing-only $infile &> $outfile
		fi
		printf $name
		printf " "
		python3 -c                                           \
			"import os;                                      \
			 name_len = len('$name');                        \
			 term_len = $(/usr/bin/tput cols);               \
			 print(('.' * (term_len - name_len - 4)), end='')"
		printf " "
		if (cmp -s $outfile $expected)
			then
				printf $OK
			else
				printf $KO
				diff $DIFF_FLAGS $outfile $expected
		fi
		if [ -s $valgrind_out ];
			then
				printf "\033[1;31mMEMORY ERROR\033[0m\n"
				cat $valgrind_out
		fi
done
rm -rf tester/$OUTDIR
