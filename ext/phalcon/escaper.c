
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/exception.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
ZEPHIR_INIT_CLASS(Phalcon_Escaper) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Escaper, phalcon, escaper, phalcon_escaper_method_entry, 0);

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
 * @param string encoding
 */
PHP_METHOD(Phalcon_Escaper, setEncoding) {

	zval *encoding_param = NULL;
	zval *encoding = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &encoding_param);

		zephir_get_strval(encoding, encoding_param);


	zephir_update_property_this(this_ptr, SL("_encoding"), encoding TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the internal encoding used by the escaper
 *
 * @return string
 */
PHP_METHOD(Phalcon_Escaper, getEncoding) {


	RETURN_MEMBER(this_ptr, "_encoding");

}

/**
 * Sets the HTML quoting type for htmlspecialchars
 *
 *<code>
 * $escaper->setHtmlQuoteType(ENT_XHTML);
 *</code>
 *
 * @param int quoteType
 */
PHP_METHOD(Phalcon_Escaper, setHtmlQuoteType) {

	zval *quoteType_param = NULL, *_0;
	int quoteType;

	zephir_fetch_params(0, 1, 0, &quoteType_param);

		quoteType = zephir_get_intval(quoteType_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, quoteType);
	zephir_update_property_zval(this_ptr, SL("_htmlQuoteType"), _0 TSRMLS_CC);

}

/**
 * Detect the character encoding of a string to be handled by an encoder
 * Special-handling for chr(172) and chr(128) to chr(159) which fail to be detected by mb_detect_encoding()
 *
 * @param string $str
 * @return string/null
 */
PHP_METHOD(Phalcon_Escaper, detectEncoding) {

	HashTable *_4;
	HashPosition _3;
	zval *str, *charset = NULL, *detected = NULL, *charsets, _0, *_1, *_2, **_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str);



	ZEPHIR_INIT_VAR(charset);
	zephir_call_func_p1(charset, "phalcon_is_basic_charset", str);
	if ((Z_TYPE_P(charset) == IS_STRING)) {
		RETURN_CCTOR(charset);
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "mb_detect_encoding", 0);
	ZEPHIR_INIT_VAR(_1);
	zephir_call_func_p1(_1, "function_exists", &_0);
	if (!(zephir_is_true(_1))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(charsets);
	array_init(charsets);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "UTF-32", 1);
	zephir_array_fast_append(charsets, _2);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "UTF-8", 1);
	zephir_array_fast_append(charsets, _2);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "ISO-8859-1", 1);
	zephir_array_fast_append(charsets, _2);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "ASCII", 1);
	zephir_array_fast_append(charsets, _2);
	zephir_is_iterable(charsets, &_4, &_3, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
		; zend_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(charset, _5);
		ZEPHIR_INIT_NVAR(detected);
		zephir_call_func_p3(detected, "mb_detect_encoding", str, charset, ZEPHIR_GLOBAL(global_true));
		if (zephir_is_true(detected)) {
			RETURN_CCTOR(charset);
		}
	}
	zephir_call_func_p1(return_value, "mb_detect_encoding", str);
	RETURN_MM();

}

/**
 * Utility to normalize a string's encoding to UTF-32.
 *
 * @param string $str
 * @return string
 */
PHP_METHOD(Phalcon_Escaper, normalizeEncoding) {

	zval *str, *encoding, _0 = zval_used_for_init, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str);



	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "mb_convert_encoding", 0);
	ZEPHIR_INIT_VAR(_1);
	zephir_call_func_p1(_1, "function_exists", &_0);
	if (!(zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_escaper_exception_ce, "Extension 'mbstring' is required");
		return;
	}
	ZEPHIR_INIT_VAR(encoding);
	zephir_call_method_p1(encoding, this_ptr, "detectencoding", str);
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "UTF-32", 0);
	zephir_call_func_p3(return_value, "mb_convert_encoding", str, &_0, encoding);
	RETURN_MM();

}

/**
 * Escapes a HTML string. Internally uses htmlspecialchars
 *
 * @param string $text
 * @return string
 */
PHP_METHOD(Phalcon_Escaper, escapeHtml) {

	zval *text_param = NULL, *htmlQuoteType, *encoding;
	zval *text = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text_param);

		zephir_get_strval(text, text_param);


	htmlQuoteType = zephir_fetch_nproperty_this(this_ptr, SL("_htmlQuoteType"), PH_NOISY_CC);
	encoding = zephir_fetch_nproperty_this(this_ptr, SL("_encoding"), PH_NOISY_CC);
	zephir_call_func_p3(return_value, "htmlspecialchars", text, htmlQuoteType, encoding);
	RETURN_MM();

}

/**
 * Escapes a HTML attribute string
 *
 * @param string $attribute
 * @return string
 */
PHP_METHOD(Phalcon_Escaper, escapeHtmlAttr) {

	zval *attribute_param = NULL, *encoding, _0;
	zval *attribute = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attribute_param);

		zephir_get_strval(attribute, attribute_param);


	encoding = zephir_fetch_nproperty_this(this_ptr, SL("_encoding"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 3);
	zephir_call_func_p3(return_value, "htmlspecialchars", attribute, &_0, encoding);
	RETURN_MM();

}

/**
 * Escape CSS strings by replacing non-alphanumeric chars by their hexadecimal escaped representation
 *
 * @param string $css
 * @return string
 */
PHP_METHOD(Phalcon_Escaper, escapeCss) {

	zval *css_param = NULL, *normalize;
	zval *css = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &css_param);

		zephir_get_strval(css, css_param);


	ZEPHIR_INIT_VAR(normalize);
	zephir_call_method_p1(normalize, this_ptr, "normalizeencoding", css);
	zephir_call_func_p1(return_value, "phalcon_escape_css", normalize);
	RETURN_MM();

}

/**
 * Escape javascript strings by replacing non-alphanumeric chars by their hexadecimal escaped representation
 *
 * @param string $js
 * @return string
 */
PHP_METHOD(Phalcon_Escaper, escapeJs) {

	zval *js_param = NULL, *normalize;
	zval *js = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &js_param);

		zephir_get_strval(js, js_param);


	ZEPHIR_INIT_VAR(normalize);
	zephir_call_method_p1(normalize, this_ptr, "normalizeencoding", js);
	zephir_call_func_p1(return_value, "phalcon_escape_js", normalize);
	RETURN_MM();

}

/**
 * Escapes a URL. Internally uses rawurlencode
 *
 * @param string $url
 * @return string
 */
PHP_METHOD(Phalcon_Escaper, escapeUrl) {

	zval *url_param = NULL;
	zval *url = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &url_param);

		zephir_get_strval(url, url_param);


	zephir_call_func_p1(return_value, "rawurlencode", url);
	RETURN_MM();

}

