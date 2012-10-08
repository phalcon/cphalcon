
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"

/**
 * Phalcon\Escaper
 *
 * Escapes different kinds of text securing them
 */

PHP_METHOD(Phalcon_Escaper, __construct){

	zval *map;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(map);
	array_init(map);
	add_index_stringl(map, 34, SL("quot"), 1);
	add_index_stringl(map, 38, SL("amp"), 1);
	add_index_stringl(map, 60, SL("lt"), 1);
	add_index_stringl(map, 62, SL("gt"), 1);
	phalcon_update_property_zval(this_ptr, SL("_escapeMap"), map TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the encoding to be used by the escaper
 *
 * @param string $encoding
 */
PHP_METHOD(Phalcon_Escaper, setEnconding){

	zval *encoding;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &encoding) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(encoding) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_escaper_exception_ce, "The character set must be string");
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_encoding"), encoding TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the internal encoding used by the escaper
 *
 * @return string
 */
PHP_METHOD(Phalcon_Escaper, getEncoding){

	zval *encoding;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(encoding);
	phalcon_read_property(&encoding, this_ptr, SL("_encoding"), PH_NOISY_CC);
	
	RETURN_CCTOR(encoding);
}

/**
 * Escapes a HTML string. Internally uses htmlspeciarchars
 *
 * @param string $text
 * @return string
 */
PHP_METHOD(Phalcon_Escaper, escapeHtml){

	zval *text, *escape_map, *encoding, *escaped;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &text) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(escape_map);
	phalcon_read_property(&escape_map, this_ptr, SL("_escapeMap"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(encoding);
	phalcon_read_property(&encoding, this_ptr, SL("_encoding"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(escaped);
	PHALCON_CALL_FUNC_PARAMS_3(escaped, "htmlspecialchars", text, escape_map, encoding);
	
	RETURN_CCTOR(escaped);
}

/**
 * Escapes a URL. Internally uses rawurlencode
 *
 * @param string $url
 * @return string
 */
PHP_METHOD(Phalcon_Escaper, escapeUrl){

	zval *url, *escaped;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &url) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(escaped);
	PHALCON_CALL_FUNC_PARAMS_1(escaped, "rawurlencode", url);
	
	RETURN_CCTOR(escaped);
}

