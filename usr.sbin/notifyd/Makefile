.include <src.opts.mk>
PROG= notifyd
MK_WERROR= no

.PATH: .
.PATH: ${.CURDIR}
.PATH: ${.CURDIR}/support
.PATH: ${.CURDIR}/uuid
.PATH: ${.CURDIR}/init


MK_MAN= no

BASE_INCLUDE=  -I. -I${.CURDIR} -I${.CURDIR}/init -I${.CURDIR}/../../include/apple -I${MACHINE_INCLUDES}
BASE_INCLUDE+= -I${.CURDIR}/../../include -I${.CURDIR}/../../sys -I${.CURDIR}/../../lib/libnotify
DEFINES= -D__APPLE__ -fblocks -DLIBC_NO_LIBCRASHREPORTERCLIENT -DPRIVATE
MIG_FLAGS= ${BASE_INCLUDE} 	${DEFINES}
#override default CFLAGS
CFLAGS= ${MIG_FLAGS}  -D__MigTypeCheck
CFLAGS+= -I${.CURDIR}/../../contrib/openbsm -I${.CURDIR}/../../lib/liblaunch
CFLAGS+= -DHAVE_INTTYPES_H

DEBUG_FLAGS+= -g -O0

LDFLAGS+= -lBlocksRuntime -lbsm -lprivateauditd
LDFLAGS+= -lutil -ldispatch -lmach -llaunch -losxsupport -lxpc -lnv -lsbuf -lnotify
LDFLAGS+= -pthread

notify_ipc.h notify_ipcServer.c: ${.CURDIR}/../../lib/libnotify/notify_ipc.defs
	mig ${MIG_FLAGS} ${.CURDIR}/../../lib/libnotify/notify_ipc.defs

notify_proc: notify_ipcServer.c

SRCS=notify_proc.c notifyd.c service.c timer.c	notify_ipcServer.c


CLEANFILES+= *Server.c *User.c job.h helper.h job_reply.h job_forward.h notify.h \
	internal.h mach_exc.h *Server.h *~ cscope.*
.include <bsd.prog.mk>
