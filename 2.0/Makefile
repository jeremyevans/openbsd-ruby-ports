VERSION =		2.0.0
PATCHLEVEL =		648
REVISION =		12

NEXTVER =		2.1
DISTNAME =		ruby-${VERSION}-p${PATCHLEVEL}

SHARED_LIBS =		ruby${BINREV}	1.1
PKGNAME =		ruby-${VERSION}.${PATCHLEVEL}

BUILD_DEPENDS =		shells/bash

CONFIGURE_SCRIPT =	${LOCALBASE}/bin/bash ./configure

WANTLIB =		ncursesw termcap

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

DISTFILES.ruby24 =	ruby-2.4.9.tar.gz

post-extract:
	rm -rf ${WRKSRC}/ext/openssl
	cp -Rp ${WRKSRC}/../ruby-2.4.9/ext/openssl ${WRKSRC}/ext/
	egrep -v '(backward\.h|thread_native\.h)' ${WRKSRC}/ext/openssl/depend > \
		${WRKSRC}/ext/openssl/depend.new
	mv ${WRKSRC}/ext/openssl/depend{.new,}
	rm ${WRKSRC}/ext/openssl/openssl.gemspec
	sed -i 's/rb_nativethread_self/pthread_self/g' ${WRKSRC}/ext/openssl/ossl.c
	sed -i 's/rb_nativethread/rb_thread/g' ${WRKSRC}/ext/openssl/ossl.c
	sed -i 's/RUBY_TYPED_FREE_IMMEDIATELY,//g' ${WRKSRC}/ext/openssl/*.c

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
