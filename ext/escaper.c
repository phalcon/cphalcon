
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

#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/operators.h"

/**
 * Phalcon\Escaper
 *
 * Escapes different kinds of text securing them. By using this component you may
 * prevent XSS attacks.
 *
 * This component only works with UTF-8. The PREG extension needs to be compiled with UTF-8 support.
 *
 *<code>
 * $escaper = new Phalcon\Escaper();
 * $escaped = $escaper->escapeCss("font-family: <Verdana>");
 * echo $escaped; // font\2D family\3A \20 \3C Verdana\3E
 *</code>
 */


/**
 * Phalcon\Escaper initializer
 */
PHALCON_INIT_CLASS(Phalcon_Escaper){

	PHALCON_REGISTER_CLASS(Phalcon, Escaper, escaper, phalcon_escaper_method_entry, 0);

	zend_declare_property_string(phalcon_escaper_ce, SL("_encoding"), "utf-8", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_escaper_ce, SL("_htmlEscapeMap"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_escaper_ce, SL("_htmlQuoteType"), 3, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_escaper_ce TSRMLS_CC, 1, phalcon_escaperinterface_ce);

	return SUCCESS;
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
		RETURN_MM_NULL();
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


	RETURN_MEMBER(this_ptr, "_encoding");
}

/**
 * Sets the HTML quoting type for htmlspecialchars
 *
 * @param int $quoteType
 */
PHP_METHOD(Phalcon_Escaper, setHtmlQuoteType){

	zval *quote_type;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &quote_type) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_htmlQuoteType"), quote_type TSRMLS_CC);
	
}

/**
 * Escapes a HTML string. Internally uses htmlspeciarchars
 *
 * @param string $text
 * @return string
 */
PHP_METHOD(Phalcon_Escaper, escapeHtml){

	zval *text, *html_quote_type, *encoding, *escaped;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &text) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(text) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_escaper_exception_ce, "The text must be string");
		return;
	}
	
	PHALCON_OBS_VAR(html_quote_type);
	phalcon_read_property(&html_quote_type, this_ptr, SL("_htmlQuoteType"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(encoding);
	phalcon_read_property(&encoding, this_ptr, SL("_encoding"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(escaped);
	PHALCON_CALL_FUNC_PARAMS_3(escaped, "htmlspecialchars", text, html_quote_type, encoding);
	
	RETURN_CCTOR(escaped);
}

/**
 * Escapes a HTML attribute string
 *
 * @param string $text
 * @return string
 */
PHP_METHOD(Phalcon_Escaper, escapeHtmlAttr){

	zval *text, *html_map = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &text) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(html_map);
	phalcon_read_property(&html_map, this_ptr, SL("_htmlEscapeMap"), PH_NOISY_CC);
	if (Z_TYPE_P(html_map) == IS_NULL) {
		PHALCON_INIT_NVAR(html_map);
		array_init_size(html_map, 4);
		add_index_stringl(html_map, 34, SL("quot"), 1);
		add_index_stringl(html_map, 38, SL("amp"), 1);
		add_index_stringl(html_map, 60, SL("lt"), 1);
		add_index_stringl(html_map, 62, SL("gt"), 1);
		phalcon_update_property_zval(this_ptr, SL("_htmlEscapeMap"), html_map TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Sanitizes CSS strings converting non-alphanumeric chars to their hexadecimal representation
 *
 * @param array $matches
 * @return string
 */
PHP_METHOD(Phalcon_Escaper, cssSanitize){

	zval *matches, *chr, *length, *ord = NULL, *format, *css_sanitize;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &matches) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(matches) == IS_ARRAY) { 
		if (phalcon_array_isset_long(matches, 0)) {
	
			PHALCON_OBS_VAR(chr);
			phalcon_array_fetch_long(&chr, matches, 0, PH_NOISY_CC);
	
			PHALCON_INIT_VAR(length);
			phalcon_fast_strlen(length, chr);
			if (phalcon_compare_strict_long(length, 1 TSRMLS_CC)) {
				PHALCON_INIT_VAR(ord);
				PHALCON_CALL_FUNC_PARAMS_1(ord, "ord", chr);
			} else {
				PHALCON_INIT_NVAR(ord);
				PHALCON_CALL_FUNC_PARAMS_1(ord, "hexdec", chr);
			}
	
			PHALCON_INIT_VAR(format);
			ZVAL_STRING(format, "\\%X ", 1);
	
			PHALCON_INIT_VAR(css_sanitize);
			PHALCON_CALL_FUNC_PARAMS_2(css_sanitize, "sprintf", format, ord);
	
			RETURN_CCTOR(css_sanitize);
		}
	}
	RETURN_MM_NULL();
}

/**
 * Escape CSS strings by replacing non-alphanumeric chars by their hexadecimal representation
 *
 * @param string $css
 */
PHP_METHOD(Phalcon_Escaper, escapeCss){

	zval *css, *pattern, *callback, *sanitized;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &css) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(css) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_escaper_exception_ce, "The CSS must be string");
		return;
	}
	if (zend_is_true(css)) {
		PHALCON_INIT_VAR(pattern);
		ZVAL_STRING(pattern, "/[^a-z0-9]/iSu", 1);
	
		PHALCON_INIT_VAR(callback);
		array_init_size(callback, 2);
		phalcon_array_append(&callback, this_ptr, PH_SEPARATE TSRMLS_CC);
		add_next_index_stringl(callback, SL("cssSanitize"), 1);
	
		PHALCON_INIT_VAR(sanitized);
		PHALCON_CALL_FUNC_PARAMS_3(sanitized, "preg_replace_callback", pattern, callback, css);
		RETURN_CCTOR(sanitized);
	}
	
	RETURN_MM_NULL();
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
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(escaped);
	PHALCON_CALL_FUNC_PARAMS_1(escaped, "rawurlencode", url);
	RETURN_CCTOR(escaped);
}

