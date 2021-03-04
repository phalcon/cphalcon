
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Class Textarea
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Input_Textarea) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper\\Input, Textarea, phalcon, html_helper_input_textarea, phalcon_html_helper_input_abstractinput_ce, phalcon_html_helper_input_textarea_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_html_helper_input_textarea_ce, SL("type"), "textarea", ZEND_ACC_PROTECTED);

	return SUCCESS;

}

/**
 * Returns the HTML for the input.
 *
 * @return string
 * @throws Exception
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Textarea, __toString) {

	zval attributes;
	zval value, _0, _2, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&attributes);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&attributes, &_0);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "value");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "");
	ZEPHIR_CALL_CE_STATIC(&value, phalcon_helper_arr_ce, "get", &_1, 16, &attributes, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	array_init(&_2);
	zephir_update_property_zval(this_ptr, ZEND_STRL("attributes"), &_2);
	zephir_array_unset_string(&attributes, SL("type"), PH_SEPARATE);
	zephir_array_unset_string(&attributes, SL("value"), PH_SEPARATE);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("type"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "renderfullelement", NULL, 0, &_4, &value, &attributes);
	zephir_check_call_status();
	RETURN_MM();

}

