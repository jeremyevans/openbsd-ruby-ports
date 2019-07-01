# $OpenBSD: Makefile,v 1.30 2016/09/01 14:23:58 jeremy Exp $

VERSION =		2.0.0
PATCHLEVEL =		648
NEXTVER =		2.1
DISTNAME =		ruby-${VERSION}-p${PATCHLEVEL}

SHARED_LIBS =		ruby${BINREV}	1.1
PKGNAME =		ruby-${VERSION}.${PATCHLEVEL}

REVISION =		6

BUILD_DEPENDS =		shells/bash

CONFIGURE_SCRIPT =	${LOCALBASE}/bin/bash ./configure

WANTLIB =		ncursesw termcap

pre-install:
	find ${WRKSRC} -name '*.orig' -print0 | xargs -0r rm
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ruby

post-install:
	${FIX_RBCONFIG}

do-test:
	-cd ${WRKSRC} && make test-sample
	-cd ${WRKSRC} && make btest-ruby
	cd ${WRKSRC} && make test-all TESTOPTS="-v -q -x test/ruby/test_io.rb -x test/net/http/test_http.rb"

.include <bsd.port.mk>
