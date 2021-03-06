# $NetBSD: Makefile.inc,v 1.7 2016/10/13 18:11:19 martin Exp $

WARNS=		2

SRCDIR:=	${.PARSEDIR}/dist

.PATH: ${SRCDIR}

CPPFLAGS+=	\
		-DHAVE_GMTIME_R=1 \
		-DHAVE_INTTYPES_H=1 \
		-DHAVE_LOCALTIME_R=1 \
		-DHAVE_READLINE=1 \
		-DHAVE_STDINT_H=1 \
		-DHAVE_STRERROR_R=1 \
		-DHAVE_USLEEP=1 \
		-DHAVE_SYS_ENDIAN_H=1 \
		-DSQLITE_ENABLE_COLUMN_METADATA \
		-DSQLITE_ENABLE_FTS3_PARENTHESIS \
		-DSQLITE_ENABLE_FTS4 \
		-DSQLITE_ENABLE_LOAD_EXTENSION \
		-DSQLITE_ENABLE_UNLOCK_NOTIFY \
		-DSQLITE_HAVE_ISNAN \
        -DSQLITE_MAX_WORKER_THREADS=0

.if defined(__MINIX)
CPPFLAGS+=	\
		-DSQLITE_THREADSAFE=0 \
		-DSQLITE_OMIT_WAL
.endif # defined(__MINIX)


CWARNFLAGS+=	-Wno-shadow -Wno-unused
