# $OpenBSD: Makefile,v 1.22 2017/09/16 22:45:26 jeremy Exp $

VERSION =		2.2.10
NEXTVER =		2.3
REVISION =		6

SHARED_LIBS =		ruby${BINREV}	1.3

DISTFILES =	ruby-${VERSION}.tar.gz \
		ruby-2.4.9.tar.gz:0

CONFIGURE_ARGS =	--enable-shared \
			--program-suffix=${BINREV} \
			--with-soname=ruby${BINREV} \
			--with-ruby-version=minor \
			--with-mantype=doc \
			--enable-pthread \
			--enable-ipv6 \
			--without-bundled-libffi \
			--with-bundled-md5 \
			--with-bundled-rmd160 \
			--with-bundled-sha1 \
			--with-bundled-sha2 \
			--disable-option-checking

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
