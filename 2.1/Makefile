# $OpenBSD: Makefile,v 1.28 2017/09/16 22:52:40 jeremy Exp $

VERSION =		2.1.9
NEXTVER =		2.2

SHARED_LIBS =		ruby${BINREV}	1.2

REVISION =		7

CONFIGURE_ARGS2 =	--program-suffix=21 \
			--with-soname=ruby21 \
			--with-ruby-version=minor \
			--with-mantype=doc \
			--enable-pthread \
			--enable-ipv6 \
			--disable-option-checking

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
