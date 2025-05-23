<?php

/**
 * This is the header, which will be added to the start of generated phalcon.c file
 */

return <<<HEADER
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <math.h>
#include <ctype.h>
#include <stdlib.h>

#include <main/php.h>

#define ZEPHIR_RELEASE 1
#define PHALCON_RELEASE 1

#include "php_phalcon.h"
#include "phalcon.zep.h"

#include <main/php_main.h>
#include <main/php_variables.h>
#include <main/php_streams.h>
#include <main/php_output.h>
#include <main/php_ini.h>
#include <main/SAPI.h>
#include <ext/standard/php_string.h>
#include <ext/standard/php_smart_string.h>
#include <ext/standard/info.h>
#include <ext/standard/file.h>
#include <ext/standard/php_filestat.h>
#if PHP_VERSION_ID < 80400
#include <ext/standard/php_rand.h>
#include <ext/standard/php_lcg.h>
#endif
#include <ext/standard/php_math.h>
#include <ext/standard/php_array.h>
#include <ext/standard/php_var.h>
#include <ext/standard/php_http.h>
#include <ext/standard/php_versioning.h>
#include <ext/standard/html.h>
#include <ext/standard/base64.h>
#include <ext/standard/md5.h>
#include <ext/standard/head.h>
#include <ext/standard/url.h>
#include <ext/standard/crc32.h>

#include <ext/spl/spl_heap.h>
#include <ext/spl/spl_exceptions.h>
#include <ext/spl/spl_directory.h>
#include <ext/spl/spl_iterators.h>
#include <ext/spl/spl_array.h>

#if defined ZEPHIR_USE_PHP_PCRE && ZEPHIR_USE_PHP_PCRE
#include <ext/pcre/php_pcre.h>
#endif

#include <ext/pdo/php_pdo_driver.h>
#include <ext/hash/php_hash.h>
#include <ext/date/php_date.h>
#include <ext/json/php_json.h>
#include <ext/session/php_session.h>

#include <Zend/zend_API.h>
#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>
#include <Zend/zend_execute.h>
#include <Zend/zend_extensions.h>
#include <Zend/zend_builtin_functions.h>
#include <Zend/zend_closures.h>
#include <Zend/zend_multiply.h>
#include <Zend/zend_generators.h>

HEADER;
