# $OpenBSD: Makefile,v 1.51 2015/04/15 21:58:16 jeremy Exp $

VERSION =		1.9.3
PATCHLEVEL =		551
NEXTVER =		2.0
DISTNAME =		ruby-${VERSION}-p${PATCHLEVEL}

SHARED_LIBS =		ruby${BINREV} 1.1
PKGNAME =		ruby-${VERSION}.${PATCHLEVEL}

REVISION =		6

CONFIGURE_ARGS =	--enable-shared \
			--program-suffix=${BINREV} \
			--with-soname=ruby${BINREV} \
			--with-mantype=doc \
			--enable-pthread \
			--enable-ipv6 \
			--disable-option-checking

WANTLIB =		ncursesw termcap iconv
LIB_DEPENDS =		converters/libiconv

RUBYLIBREV =		1.9.1
SUBST_VARS +=		RUBYLIBREV

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ruby

post-install:
	sed 's/INSTALL_ARGS/-c -o ${BINOWN} -g ${BINGRP}/' < \
		${FILESDIR}/rbconfig_fix.rb >> \
		${PREFIX}/lib/ruby/${RUBYLIBREV}/${SUB}/rbconfig.rb

do-test:
	-cd ${WRKSRC} && make test-sample
	-cd ${WRKSRC} && make btest-ruby
	cd ${WRKSRC} && make test-all

.include <bsd.port.mk>
