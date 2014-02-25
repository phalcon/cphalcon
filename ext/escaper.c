
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "escaper.h"
#include "escaperinterface.h"
#include "escaper/exception.h"

#include <ext/standard/html.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/filter.h"
#include "kernel/string.h"
#include "kernel/framework/url.h"

/**
 * Phalcon\Escaper
 *
 * Escapes different kinds of text securing them. By using this component you may
 * prevent XSS attacks.
 *
 * This component only works with UTF-8. The PREG extension needs to be compiled with UTF-8 support.
 *
 *<code>
 *	$escaper = new Phalcon\Escaper();
 *	$escaped = $escaper->escapeCss("font-family: <Verdana>");
 *	echo $escaped; // font\2D family\3A \20 \3C Verdana\3E
 *</code>
 */
zend_class_entry *phalcon_escaper_ce;

PHP_METHOD(Phalcon_Escaper, setEncoding);
PHP_METHOD(Phalcon_Escaper, getEncoding);
PHP_METHOD(Phalcon_Escaper, setHtmlQuoteType);
PHP_METHOD(Phalcon_Escaper, detectEncoding);
PHP_METHOD(Phalcon_Escaper, normalizeEncoding);
PHP_METHOD(Phalcon_Escaper, escapeHtml);
PHP_METHOD(Phalcon_Escaper, escapeHtmlAttr);
PHP_METHOD(Phalcon_Escaper, escapeCss);
PHP_METHOD(Phalcon_Escaper, escapeJs);
PHP_METHOD(Phalcon_Escaper, escapeUrl);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaper_detectencoding, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaper_normalizeencoding, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_escaper_method_entry[] = {
	PHP_ME(Phalcon_Escaper, setEncoding, arginfo_phalcon_escaperinterface_setencoding, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, getEncoding, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, setHtmlQuoteType, arginfo_phalcon_escaperinterface_sethtmlquotetype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, detectEncoding, arginfo_phalcon_escaper_detectencoding, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, normalizeEncoding, arginfo_phalcon_escaper_normalizeencoding, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, escapeHtml, arginfo_phalcon_escaperinterface_escapehtml, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, escapeHtmlAttr, arginfo_phalcon_escaperinterface_escapehtmlattr, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, escapeCss, arginfo_phalcon_escaperinterface_escapecss, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, escapeJs, arginfo_phalcon_escaperinterface_escapejs, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, escapeUrl, arginfo_phalcon_escaperinterface_escapeurl, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

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
 *<code>
 * $escaper->setEncoding('utf-8');
 *</code>
 *
 * @param string $encoding
 */
PHP_METHOD(Phalcon_Escaper, setEncoding){

	zval **encoding;

	phalcon_fetch_params_ex(1, 0, &encoding);
	PHALCON_ENSURE_IS_STRING(encoding);
	phalcon_update_property_this(this_ptr, SL("_encoding"), *encoding TSRMLS_CC);
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
 *<code>
 * $escaper->setHtmlQuoteType(ENT_XHTML);
 *</code>
 *
 * @param int $quoteType
 */
PHP_METHOD(Phalcon_Escaper, setHtmlQuoteType){

	zval **quote_type;

	phalcon_fetch_params_ex(1, 0, &quote_type);
	PHALCON_ENSURE_IS_LONG(quote_type);
	phalcon_update_property_this(this_ptr, SL("_htmlQuoteType"), *quote_type TSRMLS_CC);
}

/**
 * Detect the character encoding of a string to be handled by an encoder
 * Special-handling for chr(172) and chr(128) to chr(159) which fail to be detected by mb_detect_encoding()
 *
 * @param string $str
 * @param string $charset
 * @return string
 */
PHP_METHOD(Phalcon_Escaper, detectEncoding){

	zval *str, *charset = NULL, *strict_check, *detected = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &str);

	/**
	 * Check if charset is ASCII or ISO-8859-1
	 */
	PHALCON_INIT_VAR(charset);
	phalcon_is_basic_charset(charset, str);
	if (Z_TYPE_P(charset) == IS_STRING) {
		RETURN_CTOR(charset);
	}

	/**
	 * We require mbstring extension here
	 */
	if (phalcon_function_exists_ex(SS("mb_detect_encoding") TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}

	/**
	 * Strict encoding detection with fallback to non-strict detection.
	 */
	strict_check = PHALCON_GLOBAL(z_true);

	PHALCON_INIT_NVAR(charset);
	ZVAL_STRING(charset, "UTF-32", 1);

	/**
	 * Check for UTF-32 encoding
	 */
	PHALCON_CALL_FUNCTION(&detected, "mb_detect_encoding", str, charset, strict_check);
	if (zend_is_true(detected)) {
		RETURN_CTOR(charset);
	}

	PHALCON_INIT_NVAR(charset);
	ZVAL_STRING(charset, "UTF-16", 1);

	/**
	 * Check for UTF-16 encoding
	 */
	PHALCON_CALL_FUNCTION(&detected, "mb_detect_encoding", str, charset, strict_check);
	if (zend_is_true(detected)) {
		RETURN_CTOR(charset);
	}

	PHALCON_INIT_NVAR(charset);
	ZVAL_STRING(charset, "UTF-8", 1);

	/**
	 * Check for UTF-8 encoding
	 */
	PHALCON_CALL_FUNCTION(&detected, "mb_detect_encoding", str, charset, strict_check);
	if (zend_is_true(detected)) {
		RETURN_CTOR(charset);
	}

	PHALCON_INIT_NVAR(charset);
	ZVAL_STRING(charset, "ISO-8859-1", 1);

	/**
	 * Check for ISO-8859-1 encoding
	 */
	PHALCON_CALL_FUNCTION(&detected, "mb_detect_encoding", str, charset, strict_check);
	if (zend_is_true(detected)) {
		RETURN_CTOR(charset);
	}

	PHALCON_INIT_NVAR(charset);
	ZVAL_STRING(charset, "ASCII", 1);

	/**
	 * Check for ASCII encoding
	 */
	PHALCON_CALL_FUNCTION(&detected, "mb_detect_encoding", str, charset, strict_check);
	if (zend_is_true(detected)) {
		RETURN_CTOR(charset);
	}

	/**
	 * Fallback to global detection
	 */
	PHALCON_RETURN_CALL_FUNCTION("mb_detect_encoding", str);
	RETURN_MM();
}

/**
 * Utility to normalize a string's encoding to UTF-32.
 *
 * @param string $str
 * @return string
 */
PHP_METHOD(Phalcon_Escaper, normalizeEncoding){

	zval *str, *encoding = NULL, *charset;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &str);

	/**
	 * mbstring is required here
	 */
	if (phalcon_function_exists_ex(SS("mb_convert_encoding") TSRMLS_CC) == FAILURE) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_escaper_exception_ce, "Extension 'mbstring' is required");
		return;
	}

	PHALCON_CALL_METHOD(&encoding, this_ptr, "detectencoding", str);

	PHALCON_INIT_VAR(charset);
	ZVAL_STRING(charset, "UTF-32", 1);

	/**
	 * Convert to UTF-32 (4 byte characters, regardless of actual number of bytes in
	 * the character).
	 */
	PHALCON_RETURN_CALL_FUNCTION("mb_convert_encoding", str, charset, encoding);
	RETURN_MM();
}

/**
 * Escapes a HTML string. Internally uses htmlspecialchars
 *
 * @param string $text
 * @return string
 */
PHP_METHOD(Phalcon_Escaper, escapeHtml){

	zval *text;
	zval *html_quote_type, *encoding;

	phalcon_fetch_params(0, 1, 0, &text);

	if (Z_TYPE_P(text) == IS_STRING) {
		html_quote_type = phalcon_fetch_nproperty_this(this_ptr, SL("_htmlQuoteType"), PH_NOISY TSRMLS_CC);
		encoding        = phalcon_fetch_nproperty_this(this_ptr, SL("_encoding"), PH_NOISY TSRMLS_CC);

		phalcon_htmlspecialchars(return_value, text, html_quote_type, encoding TSRMLS_CC);
		return;
	}

	RETURN_ZVAL(text, 1, 0);
}

/**
 * Escapes a HTML attribute string
 *
 * @param string $attribute
 * @return string
 */
PHP_METHOD(Phalcon_Escaper, escapeHtmlAttr){

	zval *attribute, *encoding;

	phalcon_fetch_params(0, 1, 0, &attribute);

	if (Z_TYPE_P(attribute) == IS_STRING && zend_is_true(attribute)) {
		zval quoting;

		INIT_ZVAL(quoting);
		ZVAL_LONG(&quoting, ENT_QUOTES);

		encoding = phalcon_fetch_nproperty_this(this_ptr, SL("_encoding"), PH_NOISY TSRMLS_CC);

		phalcon_htmlspecialchars(return_value, attribute, &quoting, encoding TSRMLS_CC);
		return;
	}

	RETURN_ZVAL(attribute, 1, 0);
}

/**
 * Escape CSS strings by replacing non-alphanumeric chars by their hexadecimal escaped representation
 *
 * @param string $css
 * @return string
 */
PHP_METHOD(Phalcon_Escaper, escapeCss){

	zval *css, *normalized = NULL;

	phalcon_fetch_params(0, 1, 0, &css);

	if (Z_TYPE_P(css) == IS_STRING && zend_is_true(css)) {
		PHALCON_MM_GROW();

		/**
		 * Normalize encoding to UTF-32
		 */
		PHALCON_CALL_METHOD(&normalized, this_ptr, "normalizeencoding", css);

		/**
		 * Escape the string
		 */
		phalcon_escape_css(return_value, normalized);
		RETURN_MM();
	}

	RETURN_ZVAL(css, 1, 0);
}

/**
 * Escape javascript strings by replacing non-alphanumeric chars by their hexadecimal escaped representation
 *
 * @param string $js
 * @return string
 */
PHP_METHOD(Phalcon_Escaper, escapeJs){

	zval *js, *normalized = NULL;

	phalcon_fetch_params(0, 1, 0, &js);

	if (Z_TYPE_P(js) == IS_STRING && zend_is_true(js)) {
		PHALCON_MM_GROW();

		/**
		 * Normalize encoding to UTF-32
		 */
		PHALCON_CALL_METHOD(&normalized, this_ptr, "normalizeencoding", js);

		/**
		 * Escape the string
		 */
		phalcon_escape_js(return_value, normalized);
		RETURN_MM();
	}

	RETURN_ZVAL(js, 1, 0);
}

/**
 * Escapes a URL. Internally uses rawurlencode
 *
 * @param string $url
 * @return string
 */
PHP_METHOD(Phalcon_Escaper, escapeUrl){

	zval *url;

	phalcon_fetch_params(0, 1, 0, &url);

	phalcon_raw_url_encode(return_value, url);
}
