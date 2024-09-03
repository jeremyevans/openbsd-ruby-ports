VERSION =		2.5.9
NEXTVER =		2.6
REVISION =		3

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
