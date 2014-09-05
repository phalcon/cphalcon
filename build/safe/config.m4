PHP_ARG_ENABLE(phalcon, whether to enable phalcon framework, [ --enable-phalcon   Enable phalcon framework])
PHP_ARG_WITH(non-free, wheter to enable non-free css and js minifier, [ --without-non-free Disable non-free minifiers], yes, no)

if test "$PHP_PHALCON" = "yes"; then
	AC_DEFINE(HAVE_PHALCON, 1, [Whether you have Phalcon Framework])
	PHP_NEW_EXTENSION(phalcon, phalcon.c, $ext_shared)
	PHP_ADD_EXTENSION_DEP([phalcon], [spl])

	PHP_C_BIGENDIAN

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_HEADERS(
		[ext/igbinary/igbinary.h],
		[
			PHP_ADD_EXTENSION_DEP([phalcon], [igbinary])
			AC_DEFINE([PHALCON_USE_PHP_IGBINARY], [1], [Whether PHP igbinary extension is present at compile time])
		],
		,
		[[#include "main/php.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([phalcon], [pcre])
					AC_DEFINE([PHALCON_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([phalcon], [json])
					AC_DEFINE([PHALCON_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_PHP_SESSION],
		[
			AC_CHECK_HEADERS(
				[ext/session/php_session.h],
				[
					PHP_ADD_EXTENSION_DEP([phalcon], [session])
					AC_DEFINE([PHALCON_USE_PHP_SESSION], [1], [Whether PHP session extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_HASH_EXT],
		[
			AC_CHECK_HEADERS(
				[ext/hash/php_hash.h],
				[
					PHP_ADD_EXTENSION_DEP([phalcon], [hash])
					AC_DEFINE([PHALCON_USE_PHP_HASH], [1], [Whether PHP hash extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	for i in /usr /usr/local; do
		if test -r $i/include/png.h; then
			PNG_CFLAGS=`pkg-config --cflags libpng`
			PNG_LDFLAGS=`pkg-config --libs libpng`

			PHP_ADD_INCLUDE($i/include)

			CPPFLAGS="${CPPFLAGS} ${PNG_CFLAGS}"
			EXTRA_LDFLAGS="${EXTRA_LDFLAGS} ${PNG_LDFLAGS}"

			AC_MSG_RESULT("libpng found")

			AC_DEFINE([PHALCON_USE_PNG], [1], [Have libpng support])
			break
		fi
	done

	if test -n "$PNG_CFLAGS"; then
		for i in /usr /usr/local; do
			if test -r $i/include/qrencode.h; then
				QR_CFLAGS=`pkg-config --cflags libqrencode`
				QR_LDFLAGS=`pkg-config --libs libqrencode`

				PHP_ADD_INCLUDE($i/include)

				CPPFLAGS="${CPPFLAGS} ${QR_CFLAGS}"
				EXTRA_LDFLAGS="${EXTRA_LDFLAGS} ${QR_LDFLAGS}"

				AC_MSG_RESULT("libqrencode found")

				AC_DEFINE([PHALCON_USE_QRENCODE], [1], [Have libqrencode support])
				break
			fi
		done
	else
		AC_MSG_RESULT([libpng not found])
	fi

	for i in /usr /usr/local; do
		if test -r $i/bin/MagickWand-config; then
			WAND_BINARY=$i/bin/MagickWand-config

			WAND_CFLAGS=`$WAND_BINARY --cflags`
			WAND_LDFLAGS=`$WAND_BINARY --libs`

			PHP_ADD_INCLUDE($i/include)

			CPPFLAGS="${CPPFLAGS} ${WAND_CFLAGS}"
			EXTRA_LDFLAGS="${EXTRA_LDFLAGS} ${WAND_LDFLAGS}"

			AC_DEFINE([PHALCON_USE_MAGICKWAND], [1], [Have ImageMagick MagickWand support])
			break
		fi
	done

	if test -r "$WAND_BINARY"; then
		for i in /usr /usr/local; do
			if test -r $i/include/zbar.h; then
				ZBAR_CFLAGS=`pkg-config --cflags zbar`
				ZBAR_LDFLAGS=`pkg-config --libs zbar`

				PHP_ADD_INCLUDE($i/include)

				CPPFLAGS="${CPPFLAGS} ${ZBAR_CFLAGS}"
				EXTRA_LDFLAGS="${EXTRA_LDFLAGS} ${ZBAR_LDFLAGS}"

				AC_MSG_RESULT("libzbar found")

				AC_DEFINE([PHALCON_USE_ZBAR], [1], [Have libzbar support])
				break
			fi
		done
	fi

	AC_MSG_CHECKING([for scws.h])
	for i in /usr/local /usr /usr/local/include/scws; do
		if test -r $i/include/scws/scws.h; then
			AC_MSG_RESULT([yes, found in $i])

			PHP_ADD_INCLUDE($i/include)

			PHP_CHECK_LIBRARY(scws, scws_new,
			[
				PHP_ADD_LIBRARY_WITH_PATH(scws, $i/lib, PHALCON_SHARED_LIBADD)
				PHP_SUBST(PHALCON_SHARED_LIBADD)

				AC_DEFINE(PHALCON_USE_SCWS,1,[Have libscws support])
			],[
				AC_MSG_ERROR([Incorrect scws library])
			],[
				-L$i/lib -lm
			])

			break
		else
			AC_MSG_RESULT([no, found in $i])
		fi
	done

	PHP_ADD_MAKEFILE_FRAGMENT([Makefile.frag])
fi

PHP_ARG_ENABLE(coverage,  whether to include code coverage symbols,
[  --enable-coverage         Enable code coverage symbols, maintainers only!], no, no)

if test "$PHP_COVERAGE" = "yes"; then
	if test "$GCC" != "yes"; then
		AC_MSG_ERROR([GCC is required for --enable-coverage])
	fi

	case `$php_shtool path $CC` in
		*ccache*[)] gcc_ccache=yes;;
		*[)] gcc_ccache=no;;
	esac

	if test "$gcc_ccache" = "yes" && (test -z "$CCACHE_DISABLE" || test "$CCACHE_DISABLE" != "1"); then
		AC_MSG_ERROR([ccache must be disabled when --enable-coverage option is used. You can disable ccache by setting environment variable CCACHE_DISABLE=1.])
	fi

	lcov_version_list="1.5 1.6 1.7 1.9 1.10"

	AC_CHECK_PROG(LCOV, lcov, lcov)
	AC_CHECK_PROG(GENHTML, genhtml, genhtml)
	PHP_SUBST(LCOV)
	PHP_SUBST(GENHTML)

	if test "$LCOV"; then
		AC_CACHE_CHECK([for lcov version], php_cv_lcov_version, [
			php_cv_lcov_version=invalid
			lcov_version=`$LCOV -v 2>/dev/null | $SED -e 's/^.* //'` #'
			for lcov_check_version in $lcov_version_list; do
				if test "$lcov_version" = "$lcov_check_version"; then
					php_cv_lcov_version="$lcov_check_version (ok)"
				fi
			done
		])
	else
		lcov_msg="To enable code coverage reporting you must have one of the following LCOV versions installed: $lcov_version_list"
		AC_MSG_ERROR([$lcov_msg])
	fi

	case $php_cv_lcov_version in
		""|invalid[)]
			lcov_msg="You must have one of the following versions of LCOV: $lcov_version_list (found: $lcov_version)."
			AC_MSG_ERROR([$lcov_msg])
			LCOV="exit 0;"
		;;
	esac

	if test -z "$GENHTML"; then
		AC_MSG_ERROR([Could not find genhtml from the LCOV package])
	fi

	changequote({,})
	CFLAGS=`echo "$CFLAGS" | $SED -e 's/-O[0-9s]*//g'`
	CXXFLAGS=`echo "$CXXFLAGS" | $SED -e 's/-O[0-9s]*//g'`
	changequote([,])

	CFLAGS="$CFLAGS -O0 --coverage"
	CXXFLAGS="$CXXFLAGS -O0 --coverage"
	EXTRA_LDFLAGS="$EXTRA_LDFLAGS -precious-files-regex \.gcno\\\$$"

	PHP_ADD_MAKEFILE_FRAGMENT([Makefile.frag.coverage])
fi

if test "$GCC" = "yes"; then
	PHP_ADD_MAKEFILE_FRAGMENT([Makefile.frag.deps])
fi
