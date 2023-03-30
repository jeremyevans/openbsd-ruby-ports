VERSION =		2.7.8
NEXTVER =		2.8

SHARED_LIBS =		ruby${BINREV}	0.0

PATCHFILES =            ruby-2.7-ffi-closure-fix{040cfc89b9a110cd0fb2abdcd35e8215b4a71f60}.patch:1

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
