PHP_ARG_ENABLE(phalcon, whether to enable phalcon framework, [ --enable-phalcon   Enable phalcon framework]);

AC_MSG_CHECKING([if debug is enabled])
old_CPPFLAGS=$CPPFLAGS
CPPFLAGS="-I$phpincludedir"
AC_EGREP_CPP(php_debug_is_enabled,[
#include <main/php_config.h>
#if ZEND_DEBUG
php_debug_is_enabled
#endif
],[
  PHP_DEBUG=yes
],[
  PHP_DEBUG=no
])
CPPFLAGS=$old_CPPFLAGS
AC_MSG_RESULT([$PHP_DEBUG])

if test "$PHP_DEBUG" = "no"; then
  CFLAGS="-O2 -fno-delete-null-pointer-checks"
fi

if test "$PHP_PHALCON" = "yes"; then
  AC_DEFINE(HAVE_PHALCON, 1, [Whether you have Phalcon Framework])
  PHP_NEW_EXTENSION(phalcon, phalcon.c, $ext_shared)
fi
