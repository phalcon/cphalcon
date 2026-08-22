
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
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AuraPHP
 * @link    https://github.com/auraphp/Aura.Html
 * @license https://github.com/auraphp/Aura.Html/blob/2.x/LICENSE
 */
/**
 * Class AbstractInput
 *
 * @phpstan-import-type html_attributes from HtmlTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Input_AbstractInput)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper\\Input, AbstractInput, phalcon, html_helper_input_abstractinput, phalcon_html_helper_abstracthelper_ce, phalcon_html_helper_input_abstractinput_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @phpstan-var html_attributes
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_html_helper_input_abstractinput_ce, SL("attributes"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "text", sizeof("text") - 1);
		zephir_declare_typed_property(phalcon_html_helper_input_abstractinput_ce, SL("type"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	return SUCCESS;
}

/**
 * @phpstan-param html_attributes $attributes
 */
PHP_METHOD(Phalcon_Html_Helper_Input_AbstractInput, __invoke)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes, _0;
	zval name_zv, value_zv, *attributes_param = NULL, _1, _4, _5, _3$$3;
	zend_string *name = NULL, *value = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&value_zv);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("type", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("attributes", 10, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(value)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		attributes_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	if (!value) {
		ZEPHIR_INIT_VAR(&value_zv);
	} else {
		zephir_memory_observe(&value_zv);
	ZVAL_STR_COPY(&value_zv, value);
	}
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	zephir_memory_observe(&_1);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 58, PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("type"), &_1, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("name"), &name_zv, PH_COPY | PH_SEPARATE);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 59, &_0);
	_2 = !(zephir_array_isset_value_string(&attributes, SL("id")));
	if (_2) {
		_2 = !(zephir_memnstr_str(&name_zv, SL("["), "phalcon/Html/Helper/Input/AbstractInput.zep", 47));
	}
	if (_2) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "id");
		zephir_update_property_array(this_ptr, SL("attributes"), &_3$$3, &name_zv);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setvalue", NULL, 0, &value_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	zephir_read_property_cached(&_5, this_ptr, _zephir_prop_1, 59, PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(&_4, &_5, &attributes);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 59, &_4);
	RETURN_THIS();
}

/**
 * Returns the HTML for the input.
 */
PHP_METHOD(Phalcon_Html_Helper_Input_AbstractInput, __toString)
{
	zend_bool _1;
	zval closeTag, output, _0, _2, _3, _4, _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&closeTag);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("doctype", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("attributes", 10, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&closeTag);
	ZVAL_STRING(&closeTag, "");
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 60, PH_NOISY_CC | PH_READONLY);
	_1 = Z_TYPE_P(&_0) != IS_NULL;
	if (_1) {
		zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 60, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_3, &_2, "gettype", NULL, 0);
		zephir_check_call_status();
		_1 = ZEPHIR_GT_LONG(&_3, 5);
	}
	if (_1) {
		ZEPHIR_INIT_NVAR(&closeTag);
		ZVAL_STRING(&closeTag, "/");
	}
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_1, 59, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "input");
	ZEPHIR_CALL_METHOD(&output, this_ptr, "rendertag", NULL, 0, &_5, &_4, &closeTag);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_5);
	array_init(&_5);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 59, &_5);
	RETURN_CCTOR(&output);
}

/**
 * Sets the value of the element
 */
PHP_METHOD(Phalcon_Html_Helper_Input_AbstractInput, setValue)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval value_zv, _0$$3;
	zend_string *value = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_zv);
	ZVAL_UNDEF(&_0$$3);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!value) {
		ZEPHIR_INIT_VAR(&value_zv);
	} else {
		zephir_memory_observe(&value_zv);
	ZVAL_STR_COPY(&value_zv, value);
	}
	if (!ZEPHIR_IS_NULL(&value_zv)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "value");
		zephir_update_property_array(this_ptr, SL("attributes"), &_0$$3, &value_zv);
	}
	RETURN_THIS();
}

