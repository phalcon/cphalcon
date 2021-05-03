
PHP_ARG_ENABLE(phalcon, whether to enable phalcon, [ --enable-phalcon   Enable Phalcon])

if test "$PHP_PHALCON" = "yes"; then

    PHP_VERSION=$($PHP_CONFIG --vernum)
    PHP_STRING=$($PHP_CONFIG --version)
    AC_MSG_CHECKING(PHP version)

    if test $PHP_VERSION -lt 70401; then
      AC_MSG_ERROR(PHP version $PHP_STRING is not supported)
    fi

    subdir=build/phalcon
    AC_MSG_RESULT($PHP_STRING)
	AC_DEFINE(HAVE_PHALCON, 1, [Whether you have Phalcon])
	PHP_NEW_EXTENSION(phalcon, $subdir/phalcon.zep.c, $ext_shared)
    PHP_ADD_BUILD_DIR($abs_builddir/$subdir, 1)
    PHP_ADD_INCLUDE([$ext_srcdir/$subdir])
	PHP_SUBST(PHALCON_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([phalcon], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
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
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/phalcon], [$subdir/php_phalcon.h])
fi
