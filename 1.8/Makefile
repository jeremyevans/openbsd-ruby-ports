# $OpenBSD: Makefile,v 1.45 2017/09/16 22:54:58 jeremy Exp $

VERSION=		1.8.7
PATCHLEVEL=		374
NEXTVER=		1.9
DISTNAME =		ruby-${VERSION}-p${PATCHLEVEL}

SHARED_LIBS=		ruby${BINREV} 0.0
PKGNAME=		ruby-${VERSION}.${PATCHLEVEL}

REVISION=		10

CONFIGURE_ARGS=		--enable-shared \
			--program-suffix=${BINREV} \
			--enable-ipv6 \
			--with-dbm-type=bogus \
			--with-opt-dir="${LOCALBASE}" \
			--disable-option-checking

WANTLIB =		iconv
LIB_DEPENDS =		converters/libiconv

ALL_TARGET =		
INSTALL_TARGET =	install-nodoc

post-install:
	${FIX_RBCONFIG}

# Known regression failures in OpenSSL extension on sparc64
# Known regression failure in IO.readpartial on all arch
# Known regression failure in test_connection_refused_in_request on all arch

.include <bsd.port.mk>
