# $OpenBSD: Makefile,v 1.22 2017/09/16 22:45:26 jeremy Exp $

VERSION =		2.3.8
NEXTVER =		2.4
REVISION =		4

SHARED_LIBS =		ruby${BINREV}	2.0

DISTFILES =	ruby-${VERSION}.tar.gz \
		ruby-2.4.9.tar.gz:0

post-extract:
	rm -rf ${WRKSRC}/ext/fiddle/libffi-*
	rm -rf ${WRKSRC}/ext/openssl
	cp -Rp ${WRKSRC}/../ruby-2.4.9/ext/openssl ${WRKSRC}/ext/
	fgrep -v backward.h ${WRKSRC}/ext/openssl/depend > \
		${WRKSRC}/ext/openssl/depend.new
	mv ${WRKSRC}/ext/openssl/depend{.new,}

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
