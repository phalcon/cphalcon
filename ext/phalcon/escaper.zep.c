
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
#include "kernel/filter.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"


/**
 * Phalcon\Escaper
 *
 * Escapes different kinds of text securing them. By using this component you may
 * prevent XSS attacks.
 *
 * This component only works with UTF-8. The PREG extension needs to be compiled with UTF-8 support.
 *
 *<code>
 *	$escaper = new \Phalcon\Escaper();
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
 */
PHP_METHOD(Phalcon_Escaper, setHtmlQuoteType) {

	zval *quoteType_param = NULL, *_0;
	int quoteType;

	zephir_fetch_params(0, 1, 0, &quoteType_param);

	quoteType = zephir_get_intval(quoteType_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, quoteType);
	zephir_update_property_this(this_ptr, SL("_htmlQuoteType"), _0 TSRMLS_CC);

}

/**
 * Detect the character encoding of a string to be handled by an encoder
 * Special-handling for chr(172) and chr(128) to chr(159) which fail to be detected by mb_detect_encoding()
 */
PHP_METHOD(Phalcon_Escaper, detectEncoding) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_6 = NULL;
	HashTable *_3;
	HashPosition _2;
	zval *_0;
	zval *str_param = NULL, *charset = NULL, *_1 = NULL, **_4, *_5 = NULL;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	ZEPHIR_INIT_VAR(charset);
	zephir_is_basic_charset(charset, str);
	if (Z_TYPE_P(charset) == IS_STRING) {
		RETURN_CCTOR(charset);
	}
	if (!((zephir_function_exists_ex(SS("mb_detect_encoding") TSRMLS_CC) == SUCCESS))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 4, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "UTF-32", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "UTF-8", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "ISO-8859-1", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "ASCII", 1);
	zephir_array_fast_append(_0, _1);
	zephir_is_iterable(_0, &_3, &_2, 0, 0, "phalcon/escaper.zep", 116);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(charset, _4);
		ZEPHIR_CALL_FUNCTION(&_5, "mb_detect_encoding", &_6, 152, str, charset, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		if (zephir_is_true(_5)) {
			RETURN_CCTOR(charset);
		}
	}
	ZEPHIR_RETURN_CALL_FUNCTION("mb_detect_encoding", &_6, 152, str);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Utility to normalize a string's encoding to UTF-32.
 */
PHP_METHOD(Phalcon_Escaper, normalizeEncoding) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, *_0 = NULL, _1;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	if (!((zephir_function_exists_ex(SS("mb_convert_encoding") TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_escaper_exception_ce, "Extension 'mbstring' is required", "phalcon/escaper.zep", 128);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "detectencoding", NULL, 153, str);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "UTF-32", 0);
	ZEPHIR_RETURN_CALL_FUNCTION("mb_convert_encoding", NULL, 154, str, &_1, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Escapes a HTML string. Internally uses htmlspecialchars
 */
PHP_METHOD(Phalcon_Escaper, escapeHtml) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *_0, *_1;
	zval *text = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text_param);

	zephir_get_strval(text, text_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_htmlQuoteType"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_encoding"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("htmlspecialchars", NULL, 155, text, _0, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Escapes a HTML attribute string
 */
PHP_METHOD(Phalcon_Escaper, escapeHtmlAttr) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *attribute_param = NULL, *_0, _1;
	zval *attribute = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attribute_param);

	zephir_get_strval(attribute, attribute_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_encoding"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 3);
	ZEPHIR_RETURN_CALL_FUNCTION("htmlspecialchars", NULL, 155, attribute, &_1, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Escape CSS strings by replacing non-alphanumeric chars by their hexadecimal escaped representation
 */
PHP_METHOD(Phalcon_Escaper, escapeCss) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *css_param = NULL, *_0 = NULL;
	zval *css = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &css_param);

	zephir_get_strval(css, css_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalizeencoding", NULL, 156, css);
	zephir_check_call_status();
	zephir_escape_css(return_value, _0);
	RETURN_MM();

}

/**
 * Escape javascript strings by replacing non-alphanumeric chars by their hexadecimal escaped representation
 */
PHP_METHOD(Phalcon_Escaper, escapeJs) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *js_param = NULL, *_0 = NULL;
	zval *js = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &js_param);

	zephir_get_strval(js, js_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalizeencoding", NULL, 156, js);
	zephir_check_call_status();
	zephir_escape_js(return_value, _0);
	RETURN_MM();

}

/**
 * Escapes a URL. Internally uses rawurlencode
 */
PHP_METHOD(Phalcon_Escaper, escapeUrl) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *url_param = NULL;
	zval *url = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &url_param);

	zephir_get_strval(url, url_param);


	ZEPHIR_RETURN_CALL_FUNCTION("rawurlencode", NULL, 157, url);
	zephir_check_call_status();
	RETURN_MM();

}

