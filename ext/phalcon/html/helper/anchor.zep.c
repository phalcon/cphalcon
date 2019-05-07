
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Html\Helper\Anchor
 *
 * Creates an anchor
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Anchor) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper, Anchor, phalcon, html_helper_anchor, phalcon_html_helper_abstracthelper_ce, phalcon_html_helper_anchor_method_entry, 0);

	return SUCCESS;

}

/**
 * @var string href       The href tag
 * @var string text       The text for the anchor
 * @var array  attributes Any additional attributes
 */
PHP_METHOD(Phalcon_Html_Helper_Anchor, __invoke) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zval *href_param = NULL, *text_param = NULL, *attributes_param = NULL, escapedText, overrides, _0, _1, _2;
	zval href, text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&href);
	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&escapedText);
	ZVAL_UNDEF(&overrides);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&attributes);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &href_param, &text_param, &attributes_param);

	if (UNEXPECTED(Z_TYPE_P(href_param) != IS_STRING && Z_TYPE_P(href_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'href' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(href_param) == IS_STRING)) {
		zephir_get_strval(&href, href_param);
	} else {
		ZEPHIR_INIT_VAR(&href);
		ZVAL_EMPTY_STRING(&href);
	}
	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(&text, text_param);
	} else {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_EMPTY_STRING(&text);
	}
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}


	ZEPHIR_INIT_VAR(&overrides);
	zephir_create_array(&overrides, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&overrides, SL("href"), &href, PH_COPY | PH_SEPARATE);
	zephir_array_unset_string(&attributes, SL("href"), PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "orderattributes", NULL, 0, &overrides, &attributes);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&overrides, &_0);
	zephir_read_property(&_1, this_ptr, SL("escaper"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&escapedText, &_1, "escapehtml", NULL, 0, &text);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "renderattributes", NULL, 0, &overrides);
	zephir_check_call_status();
	zephir_fast_trim(&_2, &_0, NULL , ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	ZEPHIR_CONCAT_SVSVS(return_value, "<a ", &_2, ">", &escapedText, "</a>");
	RETURN_MM();

}

