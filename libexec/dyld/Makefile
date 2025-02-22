# $FreeBSD$

# Use the following command to build local debug version of dynamic
# linker:
# make DEBUG_FLAGS=-g WITHOUT_TESTS=yes all

.include <src.opts.mk>
PACKAGE=	clibs
MK_PIE=		no # Always position independent using local rules
MK_SSP=		no

CONFS=		libmap.conf
PROG?=		dyld
#ALTPROG?=	ld-elf.so.1
SRCS= \
	stub_binding_helper.S \
	dyld_stub_binder.S \
	rtld_start.S \
	reloc.c \
	rtld.c \
	rtld_lock.c \
	rtld_malloc.c \
	rtld_printf.c \
	map_object.c \
	xmalloc.c \
	debug.c \
	libmap.c
MAN=		rtld.1
CSTD?=		c11
CFLAGS+=	-Wall -DFREEBSD_ELF -DFREEBSD_MACHO -DIN_RTLD -ffreestanding
CFLAGS+=	-I${SRCTOP}/lib/csu/common -I${SRCTOP}/sys
.if exists(${.CURDIR}/${MACHINE_ARCH})
RTLD_ARCH=	${MACHINE_ARCH}
.else
RTLD_ARCH=	${MACHINE_CPUARCH}
.endif
CFLAGS+=	-I${.CURDIR}/${RTLD_ARCH} -I${.CURDIR}
.if ${MACHINE_ARCH} == "powerpc64"
LDFLAGS+=	-nostdlib -e _rtld_start
.else
LDFLAGS+=	-nostdlib -e .rtld_start
.endif

NO_WCAST_ALIGN=	yes
MK_WERROR= no
WARNS?=		6
INSTALLFLAGS=	-C -b
PRECIOUSPROG=
#BINDIR=		/libexec
BINDIR=		${LIBDIR}
# Symlink /libexec/ld-elf.so.1
#SYMLINKS=	../..${BINDIR}/${PROG} ${BINDIR}/${ALTPROG}
# Symlink /usr/lib/dyld
#SYMLINKS+=	../..${BINDIR}/${PROG} ${LIBDIR}/${PROG}

.if ${MACHINE_CPUARCH} == "sparc64"
CFLAGS+=	-fPIC
.else
CFLAGS+=	-fpic 
.endif
CFLAGS+=	-DPIC $(DEBUG)
.if ${MACHINE_CPUARCH} == "amd64" || ${MACHINE_CPUARCH} == "i386"
CFLAGS+=	-fvisibility=hidden
.endif
.if ${MACHINE_CPUARCH} == "mips"
CFLAGS.reloc.c+=-fno-jump-tables
.endif
LDFLAGS+=	-shared -Wl,-Bsymbolic -Wl,-z,defs
LIBADD=		c_nossp_pic
.if ${MK_TOOLCHAIN} == "no"
LDFLAGS+=	-L${LIBCDIR}
.endif

.if ${MACHINE_CPUARCH} == "arm"
# Some of the required math functions (div & mod) are implemented in
# libcompiler_rt on ARM. The library also needs to be placed first to be
# correctly linked. As some of the functions are used before we have
# shared libraries.
LIBADD+=	compiler_rt
.endif



#.if ${MK_SYMVER} == "yes"
VERSION_DEF=	${LIBCSRCDIR}/Versions.def
SYMBOL_MAPS=	${.CURDIR}/Symbol.map
VERSION_MAP=	Version.map
LDFLAGS+=	-Wl,--version-script=${VERSION_MAP}

.if exists(${.CURDIR}/${RTLD_ARCH}/Symbol.map)
SYMBOL_MAPS+=	${.CURDIR}/${RTLD_ARCH}/Symbol.map
.endif
#.endif

.sinclude "${.CURDIR}/${RTLD_ARCH}/Makefile.inc"

.PATH: ${.CURDIR}/${RTLD_ARCH}

HAS_TESTS=
SUBDIR.${MK_TESTS}+= tests
SUBDIR+= progname

.include <bsd.prog.mk>
${PROG_FULL}:	${VERSION_MAP}
.include <bsd.symver.mk>

.if ${COMPILER_TYPE} == "gcc"
# GCC warns about redeclarations even though they have __exported
# and are therefore not identical to the ones from the system headers.
CFLAGS+=	-Wno-redundant-decls
.if ${COMPILER_VERSION} < 40300
# Silence -Wshadow false positives in ancient GCC
CFLAGS+=	-Wno-shadow
.endif
.endif
