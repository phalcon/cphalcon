
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
#include "kernel/string.h"
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
 * Component SELECT (choice) for forms
 *
 * @phpstan-import-type forms_attributes from FormsTypes
 * @phpstan-import-type forms_select_options from FormsTypes
 * @phpstan-import-type html_attributes from HtmlTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Forms_Element_Select)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Forms\\Element, Select, phalcon, forms_element_select, phalcon_forms_element_abstractelement_ce, phalcon_forms_element_select_method_entry, 0);

	/**
	 * @var array|object|null
	 *
	 * @phpstan-var forms_select_options|object|null
	 */
	zend_declare_property_null(phalcon_forms_element_select_ce, SL("optionsValues"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Constructor
 *
 * @phpstan-param forms_select_options|object|null $options
 * @phpstan-param forms_attributes $attributes
 */
PHP_METHOD(Phalcon_Forms_Element_Select, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zval name_zv, *options = NULL, options_sub, *attributes_param = NULL, __$null;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&options_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&attributes);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("optionsValues", 13, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(options)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		options = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		attributes_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	if (!options) {
		options = &options_sub;
		options = &__$null;
	}
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 780, options);
	ZEPHIR_CALL_PARENT(NULL, phalcon_forms_element_select_ce, getThis(), "__construct", NULL, 0, &name_zv, &attributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Adds an option to the current options
 *
 * @param mixed option
 */
PHP_METHOD(Phalcon_Forms_Element_Select, addOption)
{
	zend_bool _9$$5;
	zend_string *_7$$5;
	zend_ulong _6$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *option, option_sub, key, value, _0, _2, _1$$3, *_3$$5, _4$$5, *_5$$5, _8$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_8$$5);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("optionsValues", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(option)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &option);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 780, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		array_init(&_1$$3);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 780, &_1$$3);
	}
	zephir_memory_observe(&_2);
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 780, PH_NOISY_CC);
	if (Z_TYPE_P(&_2) == IS_ARRAY) {
		if (Z_TYPE_P(option) == IS_ARRAY) {
			if (Z_TYPE_P(option) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_4$$5);
				zephir_string_to_char_array(&_4$$5, option);
				_3$$5 = &_4$$5;
			} else {
				_3$$5 = option;
			}
			zephir_is_iterable(_3$$5, 0, "phalcon/Forms/Element/Select.zep", 64);
			if (Z_TYPE_P(_3$$5) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_3$$5), _6$$5, _7$$5, _5$$5)
				{
					ZEPHIR_INIT_NVAR(&key);
					if (_7$$5 != NULL) { 
						ZVAL_STR_COPY(&key, _7$$5);
					} else {
						ZVAL_LONG(&key, _6$$5);
					}
					ZEPHIR_INIT_NVAR(&value);
					ZVAL_COPY(&value, _5$$5);
					zephir_update_property_array(this_ptr, SL("optionsValues"), &key, &value);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _3$$5, "rewind", NULL, 0);
				zephir_check_call_status();
				_9$$5 = 1;
				while (1) {
					if (_9$$5) {
						_9$$5 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _3$$5, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_8$$5, _3$$5, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_8$$5)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&key, _3$$5, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&value, _3$$5, "current", NULL, 0);
					zephir_check_call_status();
						zephir_update_property_array(this_ptr, SL("optionsValues"), &key, &value);
				}
			}
			ZEPHIR_INIT_NVAR(&value);
			ZEPHIR_INIT_NVAR(&key);
		} else {
			zephir_update_property_array_append(this_ptr, SL("optionsValues"), option);
		}
	}
	RETURN_THIS();
}

/**
 * Returns the choices' options
 *
 * @phpstan-return forms_select_options|object|null
 */
PHP_METHOD(Phalcon_Forms_Element_Select, getOptions)
{

	RETURN_MEMBER(getThis(), "optionsValues");
}

/**
 * Renders the element widget returning HTML
 *
 * @phpstan-param html_attributes $attributes
 */
PHP_METHOD(Phalcon_Forms_Element_Select, render)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, _0, _1;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("optionsValues", 13, 1);
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
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "prepareattributes", NULL, 0, &attributes);
	zephir_check_call_status();
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 780, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_tag_select_ce, "selectfield", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Set the choice's options
 *
 * @phpstan-param forms_select_options|object $options
 */
PHP_METHOD(Phalcon_Forms_Element_Select, setOptions)
{
	zval *options, options_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("optionsValues", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(options)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &options);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 780, options);
	RETURN_THISW();
}

/**
 * Returns an array of prepared attributes for Phalcon\Html\TagFactory
 * helpers according to the element parameters
 *
 * @phpstan-param html_attributes $attributes
 * @phpstan-return array<array-key, mixed>
 */
PHP_METHOD(Phalcon_Forms_Element_Select, prepareAttributes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, value, name, mergedAttributes, defaultAttributes, _0;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&mergedAttributes);
	ZVAL_UNDEF(&defaultAttributes);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("name", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("attributes", 10, 1);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 781, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&name, &_0);
	zephir_array_update_long(&attributes, 0, &name, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_memory_observe(&defaultAttributes);
	zephir_read_property_cached(&defaultAttributes, this_ptr, _zephir_prop_1, 782, PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&mergedAttributes);
	zephir_fast_array_merge(&mergedAttributes, &defaultAttributes, &attributes);
	ZEPHIR_CALL_METHOD(&value, this_ptr, "getvalue", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&value) != IS_NULL) {
		zephir_array_update_string(&mergedAttributes, SL("value"), &value, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(&mergedAttributes);
}

