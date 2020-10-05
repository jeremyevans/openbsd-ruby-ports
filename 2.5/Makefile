# $OpenBSD: Makefile,v 1.22 2017/09/16 22:45:26 jeremy Exp $

VERSION =		2.5.8
NEXTVER =		2.5
REVISION =		1

SHARED_LIBS =		ruby${BINREV}	0.0

post-extract:
	rm -rf ${WRKSRC}/ext/fiddle/libffi-*

pre-configure:
	${FIX_RIPPER}

pre-install:
	${PRE_INSTALL}

post-install:
	${FIX_RBCONFIG}

do-test:
	-cd ${WRKSRC} && make test-sample
	-cd ${WRKSRC} && make btest-ruby
	cd ${WRKSRC} && make test-all TESTOPTS="-v -q -x test/ruby/test_io.rb \
		-x test/net/http/test_http.rb"

.include <bsd.port.mk>
