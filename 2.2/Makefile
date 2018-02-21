# $OpenBSD: Makefile,v 1.22 2017/09/16 22:45:26 jeremy Exp $

VERSION =		2.2.9
NEXTVER =		2.3

REVISION =		0
PATCHFILES =		7030/rubygems-276-for-ruby22.patch:0
MASTER_SITES0 ?=	https://bugs.ruby-lang.org/attachments/download/

SHARED_LIBS =		ruby${BINREV}	1.3

post-extract:
	rm -rf ${WRKSRC}/ext/fiddle/libffi-*

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
