VERSION =		3.2.9
NEXTVER =		3.3
REVISION =		0

SHARED_LIBS =		ruby${BINREV}	0.0

post-extract:
	rm ${WRKSRC}/.bundle/gems/net-imap-0.3.9/net-imap.gemspec

pre-configure:
	${FIX_RIPPER}

pre-install:
	${PRE_INSTALL}

post-install:
	rm -rf ${PREFIX}/lib/ruby/gems/${REV}/gems/{debug,rbs}-*/ext/
	${FIX_RBCONFIG}

do-test:
	-cd ${WRKSRC} && make test-sample
	-cd ${WRKSRC} && make btest-ruby
	cd ${WRKSRC} && make test-all TESTOPTS="-v -q -x test/ruby/test_io.rb \
		-x test/net/http/test_http.rb"

.include <bsd.port.mk>
