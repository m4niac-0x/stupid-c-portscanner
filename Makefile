CC ?= gcc

all : s-pscan debug

s-pscan: s-pscan.c scanner.c
	${CC} -o s-pscan s-pscan.c scanner.c

debug: s-pscan.c scanner.c
	${CC} -g -o s-pscan_debug s-pscan.c scanner.c
