.include "../framework.common.mk"

FRAMEWORK=OpenGL
SRCS= OpenGL.m
INCS= \
	include/OpenGL/CGLCurrent.h \
	include/OpenGL/CGLTypes.h \
	include/OpenGL/gl.h \
	include/OpenGL/glext.h \
	include/OpenGL/gltypes.h \
	include/OpenGL/glu.h \
	include/OpenGL/glweak.h \
	include/OpenGL/OpenGL.h \
	include/OpenGL/wglext.h
RESOURCES=Info.plist
CFLAGS+= ${FMWK_CFLAGS} -I.. -Iinclude -I../libobjc2 -I../Foundation/Headers

_install-hook:
	rm -rf ${BUILDROOT}/System/Library/Frameworks/${FRAMEWORK}.framework
	cp -av ${.CURDIR}/${FRAMEWORK}.framework ${BUILDROOT}/System/Library/Frameworks/

.include <airyx.framework.mk>

installresources: _install-hook