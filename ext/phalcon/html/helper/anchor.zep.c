
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zval *href_param = NULL, *text_param = NULL, *attributes_param = NULL, overrides, _0;
	zval href, text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&href);
	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&overrides);
	ZVAL_UNDEF(&_0);
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
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_array_merge(&_0, &overrides, &attributes TSRMLS_CC);
	ZEPHIR_CPY_WRT(&overrides, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "a");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "renderfullelement", NULL, 0, &_0, &text, &overrides);
	zephir_check_call_status();
	RETURN_MM();

}

