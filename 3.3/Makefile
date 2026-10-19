VERSION =		3.3.12
NEXTVER =		3.4
REVISION =		0

SHARED_LIBS =		ruby${BINREV}	0.0

pre-configure:
	${FIX_RIPPER}
	/usr/bin/touch ${WRKSRC}/ext/ripper/ripper.c

pre-install:
	${PRE_INSTALL}

post-install:
	rm -rf ${PREFIX}/lib/ruby/gems/${REV}/gems/{debug,rbs}-*/ext/
	${FIX_RBCONFIG}
	rm -f ${PREFIX}/bin/*.lock

do-test:
	-cd ${WRKSRC} && make test-sample
	-cd ${WRKSRC} && make btest-ruby
	cd ${WRKSRC} && make test-all TESTOPTS="-v -q -x test/ruby/test_io.rb \
		-x test/net/http/test_http.rb"

.include <bsd.port.mk>
