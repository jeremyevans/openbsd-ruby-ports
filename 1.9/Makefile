VERSION =		1.9.3
PATCHLEVEL =		551
NEXTVER =		2.0
DISTNAME =		ruby-${VERSION}-p${PATCHLEVEL}

SHARED_LIBS =		ruby${BINREV} 1.1
PKGNAME =		ruby-${VERSION}.${PATCHLEVEL}

REVISION =		10

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

DISTFILES.ruby24 =	ruby-2.4.9.tar.gz

CONFIGURE_ENV = CFLAGS="${CFLAGS} -O0"

post-extract:
	rm -rf ${WRKSRC}/ext/openssl
	cp -Rp ${WRKSRC}/../ruby-2.4.9/ext/openssl ${WRKSRC}/ext/
	egrep -v '(backward\.h|thread_native\.h|thread.h)' ${WRKSRC}/ext/openssl/depend > \
		${WRKSRC}/ext/openssl/depend.new
	mv ${WRKSRC}/ext/openssl/depend{.new,}
	rm ${WRKSRC}/ext/openssl/openssl.gemspec
	sed -i 's/rb_nativethread_self/pthread_self/g' ${WRKSRC}/ext/openssl/ossl.c
	sed -i 's/rb_nativethread/rb_thread/g' ${WRKSRC}/ext/openssl/ossl.c
	sed -i 's/RUBY_TYPED_FREE_IMMEDIATELY,//g' ${WRKSRC}/ext/openssl/*.c

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
