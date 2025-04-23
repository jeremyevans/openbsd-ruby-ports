VERSION =		2.1.9
NEXTVER =		2.2
REVISION =		18

SHARED_LIBS =		ruby${BINREV}	1.2

CONFIGURE_ENV +=	CFLAGS="-O0 -ggdb"

DISTFILES.ruby24 =	ruby-2.4.9.tar.gz

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
	rm -rf ${WRKSRC}/ext/openssl
	cp -Rp ${WRKSRC}/../ruby-2.4.9/ext/openssl ${WRKSRC}/ext/
	egrep -v '(backward\.h|thread_native\.h)' ${WRKSRC}/ext/openssl/depend > \
		${WRKSRC}/ext/openssl/depend.new
	mv ${WRKSRC}/ext/openssl/depend{.new,}
	rm ${WRKSRC}/ext/openssl/openssl.gemspec

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
