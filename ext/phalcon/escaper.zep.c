
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
#include "kernel/memory.h"
#include "kernel/filter.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Escaper
 *
 * Escapes different kinds of text securing them. By using this component you
 * may prevent XSS attacks.
 *
 * This component only works with UTF-8. The PREG extension needs to be compiled
 * with UTF-8 support.
 *
 *<code>
 * $escaper = new \Phalcon\Escaper();
 * 
 * $escaped = $escaper->escapeCss("font-family: <Verdana>");
 * 
 * echo $escaped; // font\2D family\3A \20 \3C Verdana\3E
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Escaper) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Escaper, phalcon, escaper, phalcon_escaper_method_entry, 0);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_escaper_ce, SL("doubleEncode"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_escaper_ce, SL("encoding"), "utf-8", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_escaper_ce, SL("htmlEscapeMap"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(phalcon_escaper_ce, SL("htmlQuoteType"), 3, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_escaper_ce TSRMLS_CC, 1, phalcon_escaperinterface_ce);
	return SUCCESS;

}

/**
 * Detect the character encoding of a string to be handled by an encoder.
 * Special-handling for chr(172) and chr(128) to chr(159) which fail to be
 * detected by mb_detect_encoding()
 */
PHP_METHOD(Phalcon_Escaper, detectEncoding) {

	zval _0;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, __$true, charset, _1, *_2, _3, _4$$5, _6$$7;
	zval str;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&str);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&charset);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(&str, str_param);


	ZEPHIR_INIT_VAR(&charset);
	zephir_is_basic_charset(&charset, &str);
	if (Z_TYPE_P(&charset) == IS_STRING) {
		RETURN_CCTOR(&charset);
	}
	if (!((zephir_function_exists_ex(SL("mb_detect_encoding") TSRMLS_CC) == SUCCESS))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 4, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "UTF-32");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "UTF-8");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ISO-8859-1");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ASCII");
	zephir_array_fast_append(&_0, &_1);
	zephir_is_iterable(&_0, 0, "phalcon/Escaper.zep", 87);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _2)
		{
			ZEPHIR_INIT_NVAR(&charset);
			ZVAL_COPY(&charset, _2);
			ZEPHIR_CALL_FUNCTION(&_4$$5, "mb_detect_encoding", &_5, 214, &str, &charset, &__$true);
			zephir_check_call_status();
			if (zephir_is_true(&_4$$5)) {
				RETURN_CCTOR(&charset);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&charset, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_6$$7, "mb_detect_encoding", &_5, 214, &str, &charset, &__$true);
				zephir_check_call_status();
				if (zephir_is_true(&_6$$7)) {
					RETURN_CCTOR(&charset);
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&charset);
	ZEPHIR_RETURN_CALL_FUNCTION("mb_detect_encoding", &_5, 214, &str);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Escape CSS strings by replacing non-alphanumeric chars by their
 * hexadecimal escaped representation
 */
PHP_METHOD(Phalcon_Escaper, escapeCss) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *css_param = NULL, _0;
	zval css;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&css);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &css_param);

	zephir_get_strval(&css, css_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalizeencoding", NULL, 215, &css);
	zephir_check_call_status();
	zephir_escape_css(return_value, &_0);
	RETURN_MM();

}

/**
 * Escape javascript strings by replacing non-alphanumeric chars by their
 * hexadecimal escaped representation
 */
PHP_METHOD(Phalcon_Escaper, escapeJs) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *js_param = NULL, _0;
	zval js;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&js);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &js_param);

	zephir_get_strval(&js, js_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalizeencoding", NULL, 215, &js);
	zephir_check_call_status();
	zephir_escape_js(return_value, &_0);
	RETURN_MM();

}

/**
 * Escapes a HTML string. Internally uses htmlspecialchars
 */
PHP_METHOD(Phalcon_Escaper, escapeHtml) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, _0, _1, _2;
	zval text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text_param);

	zephir_get_strval(&text, text_param);


	zephir_read_property(&_0, this_ptr, SL("htmlQuoteType"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("encoding"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_2, this_ptr, SL("doubleEncode"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("htmlspecialchars", NULL, 216, &text, &_0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Escapes a HTML attribute string
 */
PHP_METHOD(Phalcon_Escaper, escapeHtmlAttr) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attribute_param = NULL, _0, _1, _2;
	zval attribute;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attribute_param);

	zephir_get_strval(&attribute, attribute_param);


	zephir_read_property(&_0, this_ptr, SL("encoding"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("doubleEncode"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_2, 3);
	ZEPHIR_RETURN_CALL_FUNCTION("htmlspecialchars", NULL, 216, &attribute, &_2, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Escapes a URL. Internally uses rawurlencode
 */
PHP_METHOD(Phalcon_Escaper, escapeUrl) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *url_param = NULL;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &url_param);

	zephir_get_strval(&url, url_param);


	ZEPHIR_RETURN_CALL_FUNCTION("rawurlencode", NULL, 217, &url);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the internal encoding used by the escaper
 */
PHP_METHOD(Phalcon_Escaper, getEncoding) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "encoding");

}

/**
 * Utility to normalize a string's encoding to UTF-32.
 */
PHP_METHOD(Phalcon_Escaper, normalizeEncoding) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, _0, _1;
	zval str;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&str);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(&str, str_param);


	if (UNEXPECTED(!((zephir_function_exists_ex(SL("mb_convert_encoding") TSRMLS_CC) == SUCCESS)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_escaper_exception_ce, "Extension 'mbstring' is required", "phalcon/Escaper.zep", 171);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "detectencoding", NULL, 218, &str);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "UTF-32");
	ZEPHIR_RETURN_CALL_FUNCTION("mb_convert_encoding", NULL, 219, &str, &_1, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets the double_encode to be used by the escaper
 *
 *<code>
 * $escaper->setDoubleEncode(false);
 *</code>
 */
PHP_METHOD(Phalcon_Escaper, setDoubleEncode) {

	zval *doubleEncode_param = NULL, __$true, __$false;
	zend_bool doubleEncode;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &doubleEncode_param);

	doubleEncode = zephir_get_boolval(doubleEncode_param);


	if (doubleEncode) {
		zephir_update_property_zval(this_ptr, SL("doubleEncode"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("doubleEncode"), &__$false);
	}

}

/**
 * Sets the encoding to be used by the escaper
 *
 *<code>
 * $escaper->setEncoding("utf-8");
 *</code>
 */
PHP_METHOD(Phalcon_Escaper, setEncoding) {

	zval *encoding_param = NULL;
	zval encoding;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&encoding);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &encoding_param);

	zephir_get_strval(&encoding, encoding_param);


	zephir_update_property_zval(this_ptr, SL("encoding"), &encoding);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the HTML quoting type for htmlspecialchars
 *
 *<code>
 * $escaper->setHtmlQuoteType(ENT_XHTML);
 *</code>
 */
PHP_METHOD(Phalcon_Escaper, setHtmlQuoteType) {

	zval *quoteType_param = NULL, _0;
	zend_long quoteType;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &quoteType_param);

	quoteType = zephir_get_intval(quoteType_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, quoteType);
	zephir_update_property_zval(this_ptr, SL("htmlQuoteType"), &_0);

}

