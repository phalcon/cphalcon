
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Component for a group of INPUT[type=radio] elements.
 *
 * Options are passed as an associative array:
 *   ['value' => 'Label']
 * or with per-item attributes:
 *   ['value' => ['label' => 'Label', 'disabled' => true]]
 *
 * @phpstan-import-type forms_attributes from FormsTypes
 * @phpstan-import-type forms_group_options from FormsTypes
 * @phpstan-import-type html_attributes from HtmlTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Forms_Element_RadioGroup)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Forms\\Element, RadioGroup, phalcon, forms_element_radiogroup, phalcon_forms_element_abstractelement_ce, phalcon_forms_element_radiogroup_method_entry, 0);

	/**
	 * @phpstan-var forms_group_options
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_forms_element_radiogroup_ce, SL("optionsValues"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	return SUCCESS;
}

/**
 * Constructor
 *
 * @phpstan-param forms_group_options $options
 * @phpstan-param forms_attributes $attributes
 */
PHP_METHOD(Phalcon_Forms_Element_RadioGroup, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options, attributes;
	zval name_zv, *options_param = NULL, *attributes_param = NULL;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&attributes);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("optionsValues", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		options_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		attributes_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 778, &options);
	ZEPHIR_CALL_PARENT(NULL, phalcon_forms_element_radiogroup_ce, getThis(), "__construct", NULL, 0, &name_zv, &attributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the group options
 *
 * @phpstan-return forms_group_options
 */
PHP_METHOD(Phalcon_Forms_Element_RadioGroup, getOptions)
{

	RETURN_MEMBER_TYPED(getThis(), "optionsValues", IS_ARRAY);
}

/**
 * Renders the radio group returning HTML
 *
 * @phpstan-param html_attributes $attributes
 */
PHP_METHOD(Phalcon_Forms_Element_RadioGroup, render)
{
	zval _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, helper, merged, value, _0, _1, _2, _3, _4, _5;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&helper);
	ZVAL_UNDEF(&merged);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("attributes", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("name", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("optionsValues", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &attributes_param);
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	ZEPHIR_CALL_METHOD(&value, this_ptr, "getvalue", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 779, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&merged);
	zephir_fast_array_merge(&merged, &_0, &attributes);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getlocaltagfactory", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "inputRadioGroup");
	ZEPHIR_CALL_METHOD(&helper, &_1, "newinstance", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_1, 780, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_5, this_ptr, _zephir_prop_2, 778, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_3, &helper, "__invoke", NULL, 0, &_4, &_5, &value, &merged);
	zephir_check_call_status();
	zephir_cast_to_string(&_6, &_3);
	RETURN_CTOR(&_6);
}

/**
 * Sets the group options
 *
 * @phpstan-param forms_group_options $options
 */
PHP_METHOD(Phalcon_Forms_Element_RadioGroup, setOptions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("optionsValues", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &options_param);
	zephir_get_arrval(&options, options_param);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 778, &options);
	RETURN_THIS();
}

