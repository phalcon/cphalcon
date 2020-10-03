
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Class Ol
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Ol) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper, Ol, phalcon, html_helper_ol, phalcon_html_helper_abstractlist_ce, phalcon_html_helper_ol_method_entry, 0);

	return SUCCESS;

}

/**
 * Add an element to the list
 *
 * @param string $text
 * @param array  $attributes
 * @param bool   $raw
 *
 * @return $this
 */
PHP_METHOD(Phalcon_Html_Helper_Ol, add) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool raw;
	zval attributes, _0, _2;
	zval *text_param = NULL, *attributes_param = NULL, *raw_param = NULL, _1, _3, _4;
	zval text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &text_param, &attributes_param, &raw_param);

	zephir_get_strval(&text, text_param);
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	if (!raw_param) {
		raw = 0;
	} else {
		raw = zephir_get_boolval(raw_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "renderFullElement");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 4, 0);
	ZEPHIR_OBS_VAR(&_3);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("elementTag"), PH_NOISY_CC);
	zephir_array_fast_append(&_2, &_3);
	zephir_array_fast_append(&_2, &text);
	zephir_array_fast_append(&_2, &attributes);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_BOOL(&_1, raw);
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "indent", NULL, 0);
	zephir_check_call_status();
	zephir_array_fast_append(&_0, &_4);
	zephir_update_property_array_append(this_ptr, SL("store"), &_0);
	RETURN_THIS();

}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Html_Helper_Ol, getTag) {

	zval *this_ptr = getThis();


	RETURN_STRING("ol");

}

