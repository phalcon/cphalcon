
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
 * Class AbstractInput
 *
 * @property array  $attributes
 * @property string $type
 * @property string $value
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Input_AbstractInput) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper\\Input, AbstractInput, phalcon, html_helper_input_abstractinput, phalcon_html_helper_abstracthelper_ce, phalcon_html_helper_input_abstractinput_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_html_helper_input_abstractinput_ce, SL("type"), "text", ZEND_ACC_PROTECTED);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_html_helper_input_abstractinput_ce, SL("attributes"), ZEND_ACC_PROTECTED);

	phalcon_html_helper_input_abstractinput_ce->create_object = zephir_init_properties_Phalcon_Html_Helper_Input_AbstractInput;
	return SUCCESS;

}

/**
 * @param string      $name
 * @param string|null $value
 * @param array       $attributes
 *
 * @return AbstractInput
 */
PHP_METHOD(Phalcon_Html_Helper_Input_AbstractInput, __invoke) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes, _0;
	zval *name_param = NULL, *value_param = NULL, *attributes_param = NULL, _1, _3, _4, _2$$3;
	zval name, value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &name_param, &value_param, &attributes_param);

	zephir_get_strval(&name, name_param);
	if (!value_param) {
		ZEPHIR_INIT_VAR(&value);
		ZVAL_STRING(&value, "");
	} else {
		zephir_get_strval(&value, value_param);
	}
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, SL("type"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("type"), &_1, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("name"), &name, PH_COPY | PH_SEPARATE);
	zephir_update_property_zval(this_ptr, SL("attributes"), &_0);
	if (!(zephir_array_isset_string(&attributes, SL("id")))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "id");
		zephir_update_property_array(this_ptr, SL("attributes"), &_2$$3, &name);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setvalue", NULL, 0, &value);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	zephir_read_property(&_4, this_ptr, SL("attributes"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(&_3, &_4, &attributes);
	zephir_update_property_zval(this_ptr, SL("attributes"), &_3);
	RETURN_THIS();

}

/**
 * Returns the HTML for the input.
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Helper_Input_AbstractInput, __toString) {

	zval _0, _1, _2, _3;
	zval attributes;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("attributes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&attributes, &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_property_zval(this_ptr, SL("attributes"), &_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "input");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "/");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "rendertag", NULL, 0, &_2, &attributes, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets the value of the element
 *
 * @param string|null $value
 *
 * @return AbstractInput
 */
PHP_METHOD(Phalcon_Html_Helper_Input_AbstractInput, setValue) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *value_param = NULL, _1$$3;
	zval value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &value_param);

	if (!value_param) {
		ZEPHIR_INIT_VAR(&value);
		ZVAL_STRING(&value, "");
	} else {
		zephir_get_strval(&value, value_param);
	}


	_0 = zephir_is_numeric(&value);
	if (!(_0)) {
		_0 = !(ZEPHIR_IS_EMPTY(&value));
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "value");
		zephir_update_property_array(this_ptr, SL("attributes"), &_1$$3, &value);
	}
	RETURN_THIS();

}

zend_object *zephir_init_properties_Phalcon_Html_Helper_Input_AbstractInput(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("attributes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("attributes"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

