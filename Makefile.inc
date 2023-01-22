COMMENT ?=	object oriented script language with threads

DISTNAME ?=	ruby-${VERSION}

PKGNAME ?=	ruby-${VERSION}

PKGSPEC ?=	ruby->=${REV},<${NEXTVER}

CATEGORIES ?=	lang

HOMEPAGE ?=	http://www.ruby-lang.org/

MAINTAINER ?=	Jeremy Evans <jeremy@openbsd.org>

# GPL/Artistic/BSD/Public Domain/Beer-Ware
PERMIT_PACKAGE ?= Yes

MASTER_SITES ?=	http://cache.ruby-lang.org/pub/ruby/${VERSION:R}/
MASTER_SITES0 ?=http://cache.ruby-lang.org/pub/ruby/2.4/
MASTER_SITES1 ?=https://github.com/ruby/ruby/commit/
PATCH_DIST_STRIP ?=     -p1

CONFIGURE_STYLE ?=	gnu
CONFIGURE_ARGS ?=	--enable-shared \
			--program-suffix=${BINREV} \
			--with-soname=ruby${BINREV} \
			--with-ruby-version=minor \
			--with-mantype=doc \
			--enable-pthread \
			--enable-ipv6 \
			--without-bundled-libffi \
			--disable-option-checking

CONFIGURE_ENV +=	LIBruby${BINREV}_VERSION=${LIBruby${BINREV}_VERSION} \
			PREFIX="${PREFIX}" \
			CPPFLAGS="-DOPENSSL_NO_STATIC_ENGINE -I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib" \
			DLDFLAGS="-L${LOCALBASE}/lib" \
			ac_cv_prog_DOXYGEN="" \
			ac_cv_prog_DOT="" \

MAKE_ENV +=		DLDFLAGS="-I${LOCALBASE}/lib"

WANTLIB +=		c crypto ffi gmp m ncurses pthread readline ssl \
			util yaml z
LIB_DEPENDS +=		devel/gmp,-main \
			devel/libyaml \
			devel/libffi

ALL_TARGET ?=		V=1 main
INSTALL_TARGET ?=	V=1 install-nodoc

TEST_DEPENDS ?=		${PKGNAME}:${BUILD_PKGPATH}

POST_EXTRACT ?=		rm -rf ${WRKSRC}/ext/fiddle/libffi-* \
				${WRKSRC}/tool/downloader.rb;

PRE_INSTALL ?=	find ${WRKSRC} -name '*.orig' -print0 | xargs -0r rm; \
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ruby \
		${PREFIX}/lib/ruby/gems/${REV}/extensions/${SUB} \
		${PREFIX}/lib/ruby/gems/${REV}/extensions/${SUB}/${REV};

# Ruby itself is clean, but some extensions (e.g. devel/ruby-therubyracer)
# need W|X mappings.
USE_WXNEEDED ?=		Yes

REV ?=			${VERSION:R}
BINREV ?=		${REV:S/.//}
SUB ?=			${MACHINE_ARCH:S/amd64/x86_64/}-openbsd
SUBST_VARS +=		SUB REV
FILESDIR ?=		${.CURDIR}/../files

FIX_RIPPER ?=	sed -i 's/%%CFLAGS_OVERRIDE%%/${CFLAGS_OVERRIDE}/g' \
			${WRKSRC}/ext/ripper/depend;

FIX_RBCONFIG ?=		sed 's/INSTALL_ARGS/-c -o ${BINOWN} -g ${BINGRP}/' < \
				${FILESDIR}/rbconfig_fix.rb >> \
				${PREFIX}/lib/ruby/${REV}/${SUB}/rbconfig.rb
