#
# XWiimote
#
# Copyright (c) 2011, 2012 David Herrmann <dh.herrmann@googlemail.com>
#
# Permission is hereby granted, free of charge, to any person obtaining
# a copy of this software and associated documentation files
# (the "Software"), to deal in the Software without restriction, including
# without limitation the rights to use, copy, modify, merge, publish,
# distribute, sublicense, and/or sell copies of the Software, and to
# permit persons to whom the Software is furnished to do so, subject to
# the following conditions:
#
# The above copyright notice and this permission notice shall be included
# in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
# OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
# IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
# CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
# TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
# SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#

ACLOCAL_AMFLAGS = -I m4

EXTRA_DIST = \
	README \
	COPYING \
	60-xorg-xwiimote.conf

man_MANS = \
	xorg-xwiimote.4
EXTRA_DIST += $(man_MANS)

AM_CFLAGS = $(XORG_CFLAGS) $(SYSDEP_CFLAGS) -Wno-redundant-decls -Wno-cast-qual

@DRIVER_NAME@_drv_la_LTLIBRARIES = @DRIVER_NAME@_drv.la
@DRIVER_NAME@_drv_la_LDFLAGS = -module -avoid-version
@DRIVER_NAME@_drv_la_LIBADD = $(SYSDEP_LIBS)
@DRIVER_NAME@_drv_ladir = @inputdir@
@DRIVER_NAME@_drv_la_SOURCES = src/util.c src/key.c src/xwiimote.c src/analog-stick-axis.c src/analog-stick.c src/nunchuk.c src/wiimote.c src/ir.c src/accelerometer.c src/motionplus.c src/properties.c

bin_PROGRAMS = xwiimote-daemon
xwiimote_daemon_SOURCES=src/xwiimote-daemon.c
xwiimote_daemon_LDADD=$(XCB_LIBS)
xwiimote_CPPFLAGS=$(XCB_CFLAGS)
