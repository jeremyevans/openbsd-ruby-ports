VERSION =		3.1.7
NEXTVER =		3.2

SHARED_LIBS =		ruby${BINREV}	0.0

PATCHFILES.github =	ruby-octeon-fix-1{fe6245b4309c855e6aca5b786ad50a72d53d278a}.patch
PATCHFILES.openssl +=	ruby-enable-hkdf-1{9bdd39a7e2a5851c9090889727f54859e63a4ec9}.patch
PATCHFILES.openssl +=	ruby-ed25519-fix-1{475b2bf766d6093370e49abd5dce5436cc0034ca}.patch

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
