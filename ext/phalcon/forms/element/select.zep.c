
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
#include "kernel/string.h"
#include "kernel/exception.h"


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
 */
ZEPHIR_INIT_CLASS(Phalcon_Forms_Element_Select)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Forms\\Element, Select, phalcon, forms_element_select, phalcon_forms_element_abstractelement_ce, phalcon_forms_element_select_method_entry, 0);

	/**
	 * @var object|array|null
	 */
	zend_declare_property_null(phalcon_forms_element_select_ce, SL("optionsValues"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Constructor
 *
 * @param string            name
 * @param object|array|null options
 * @param array             attributes
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
	zephir_update_property_zval(this_ptr, ZEND_STRL("optionsValues"), options);
	ZEPHIR_CALL_PARENT(NULL, phalcon_forms_element_select_ce, getThis(), "__construct", NULL, 0, &name_zv, &attributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Adds an option to the current options
 *
 * @param array|string option
 */
PHP_METHOD(Phalcon_Forms_Element_Select, addOption)
{
	zend_string *_3$$3;
	zend_ulong _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *option, option_sub, key, value, *_0$$3, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(option)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &option);
	if (Z_TYPE_P(option) == IS_ARRAY) {
		zephir_is_iterable(option, 0, "phalcon/Forms/Element/Select.zep", 56);
		if (Z_TYPE_P(option) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(option), _2$$3, _3$$3, _0$$3)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_3$$3 != NULL) { 
					ZVAL_STR_COPY(&key, _3$$3);
				} else {
					ZVAL_LONG(&key, _2$$3);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _0$$3);
				zephir_update_property_array(this_ptr, SL("optionsValues"), &key, &value);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, option, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, option, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, option, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, option, "current", NULL, 0);
				zephir_check_call_status();
					zephir_update_property_array(this_ptr, SL("optionsValues"), &key, &value);
				ZEPHIR_CALL_METHOD(NULL, option, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
	} else {
		zephir_update_property_array_append(this_ptr, SL("optionsValues"), option);
	}
	RETURN_THIS();
}

/**
 * Returns the choices' options
 *
 * @return array|object
 */
PHP_METHOD(Phalcon_Forms_Element_Select, getOptions)
{

	RETURN_MEMBER(getThis(), "optionsValues");
}

/**
 * Renders the element widget returning HTML
 */
PHP_METHOD(Phalcon_Forms_Element_Select, render)
{
	zval _13, _5$$15;
	zend_bool _2, _8, _10$$18;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, attrs, emptyText, emptyValue, html, name, options, select, tagFactory, using, useEmpty, value, _0, _1, _3, _4, _6$$16, _7$$16, _9$$17, _12$$18, _11$$19, _14$$20, _15$$20, _16$$20, _17$$20;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&attrs);
	ZVAL_UNDEF(&emptyText);
	ZVAL_UNDEF(&emptyValue);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&select);
	ZVAL_UNDEF(&tagFactory);
	ZVAL_UNDEF(&using);
	ZVAL_UNDEF(&useEmpty);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6$$16);
	ZVAL_UNDEF(&_7$$16);
	ZVAL_UNDEF(&_9$$17);
	ZVAL_UNDEF(&_12$$18);
	ZVAL_UNDEF(&_11$$19);
	ZVAL_UNDEF(&_14$$20);
	ZVAL_UNDEF(&_15$$20);
	ZVAL_UNDEF(&_16$$20);
	ZVAL_UNDEF(&_17$$20);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_5$$15);
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
	ZEPHIR_CALL_METHOD(&attrs, this_ptr, "prepareattributes", NULL, 0, &attributes);
	zephir_check_call_status();
	zephir_memory_observe(&name);
	zephir_array_fetch_long(&name, &attrs, 0, PH_NOISY, "phalcon/Forms/Element/Select.zep", 83);
	zephir_array_unset_long(&attrs, 0, PH_SEPARATE);
	if (zephir_array_isset_string(&attrs, SL("value"))) {
		zephir_memory_observe(&value);
		zephir_array_fetch_string(&value, &attrs, SL("value"), PH_NOISY, "phalcon/Forms/Element/Select.zep", 87);
		zephir_array_unset_string(&attrs, SL("value"), PH_SEPARATE);
	} else {
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_NULL(&value);
	}
	if (zephir_array_isset_string(&attrs, SL("useEmpty"))) {
		zephir_memory_observe(&useEmpty);
		zephir_array_fetch_string(&useEmpty, &attrs, SL("useEmpty"), PH_NOISY, "phalcon/Forms/Element/Select.zep", 94);
	} else {
		ZEPHIR_INIT_NVAR(&useEmpty);
		ZVAL_BOOL(&useEmpty, 0);
	}
	if (zephir_array_isset_string(&attrs, SL("emptyValue"))) {
		zephir_memory_observe(&emptyValue);
		zephir_array_fetch_string(&emptyValue, &attrs, SL("emptyValue"), PH_NOISY, "phalcon/Forms/Element/Select.zep", 100);
	} else {
		ZEPHIR_INIT_NVAR(&emptyValue);
		ZVAL_STRING(&emptyValue, "");
	}
	if (zephir_array_isset_string(&attrs, SL("emptyText"))) {
		zephir_memory_observe(&emptyText);
		zephir_array_fetch_string(&emptyText, &attrs, SL("emptyText"), PH_NOISY, "phalcon/Forms/Element/Select.zep", 106);
	} else {
		ZEPHIR_INIT_NVAR(&emptyText);
		ZVAL_STRING(&emptyText, "Choose...");
	}
	if (zephir_array_isset_string(&attrs, SL("using"))) {
		zephir_memory_observe(&using);
		zephir_array_fetch_string(&using, &attrs, SL("using"), PH_NOISY, "phalcon/Forms/Element/Select.zep", 112);
	} else {
		ZEPHIR_INIT_NVAR(&using);
		ZVAL_NULL(&using);
	}
	zephir_array_unset_string(&attrs, SL("useEmpty"), PH_SEPARATE);
	zephir_array_unset_string(&attrs, SL("emptyValue"), PH_SEPARATE);
	zephir_array_unset_string(&attrs, SL("emptyText"), PH_SEPARATE);
	zephir_array_unset_string(&attrs, SL("using"), PH_SEPARATE);
	if (!(zephir_array_isset_string(&attrs, SL("name")))) {
		zephir_array_update_string(&attrs, SL("name"), &name, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "[");
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strpos(&_1, &name, &_0, 0 );
	_2 = !zephir_is_true(&_1);
	if (_2) {
		_2 = !(zephir_array_isset_string(&attrs, SL("id")));
	}
	if (_2) {
		zephir_array_update_string(&attrs, SL("id"), &name, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_METHOD(&tagFactory, this_ptr, "getlocaltagfactory", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "inputSelect");
	ZEPHIR_CALL_METHOD(&select, &tagFactory, "newinstance", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "");
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "");
	ZEPHIR_CALL_METHOD(NULL, &select, "__invoke", NULL, 0, &_3, &_4, &attrs);
	zephir_check_call_status();
	if (Z_TYPE_P(&value) != IS_NULL) {
		zephir_cast_to_string(&_5$$15, &value);
		ZEPHIR_CALL_METHOD(NULL, &select, "selected", NULL, 0, &_5$$15);
		zephir_check_call_status();
	}
	if (zephir_is_true(&useEmpty)) {
		ZEPHIR_INIT_VAR(&_6$$16);
		array_init(&_6$$16);
		ZVAL_BOOL(&_7$$16, 1);
		ZEPHIR_CALL_METHOD(NULL, &select, "addplaceholder", NULL, 0, &emptyText, &emptyValue, &_6$$16, &_7$$16);
		zephir_check_call_status();
	}
	zephir_memory_observe(&options);
	zephir_read_property(&options, this_ptr, ZEND_STRL("optionsValues"), PH_NOISY_CC);
	_8 = Z_TYPE_P(&options) == IS_OBJECT;
	if (_8) {
		_8 = zephir_instance_of_ev(&options, phalcon_mvc_model_resultsetinterface_ce);
	}
	if (Z_TYPE_P(&options) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_9$$17);
		object_init_ex(&_9$$17, phalcon_html_helper_input_select_arraydata_ce);
		ZEPHIR_CALL_METHOD(NULL, &_9$$17, "__construct", NULL, 317, &options);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &select, "fromdata", NULL, 0, &_9$$17);
		zephir_check_call_status();
	} else if (_8) {
		_10$$18 = Z_TYPE_P(&using) == IS_NULL;
		if (!(_10$$18)) {
			_10$$18 = Z_TYPE_P(&using) != IS_ARRAY;
		}
		if (UNEXPECTED(_10$$18)) {
			ZEPHIR_CALL_CE_STATIC(&_11$$19, phalcon_forms_exception_ce, "usingparameterrequired", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_11$$19, "phalcon/Forms/Element/Select.zep", 149);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_12$$18);
		object_init_ex(&_12$$18, phalcon_html_helper_input_select_resultsetdata_ce);
		ZEPHIR_CALL_METHOD(NULL, &_12$$18, "__construct", NULL, 318, &options, &using);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &select, "fromdata", NULL, 0, &_12$$18);
		zephir_check_call_status();
	}
	zephir_cast_to_string(&_13, &select);
	ZEPHIR_CPY_WRT(&html, &_13);
	if (ZEPHIR_IS_STRING_IDENTICAL(&html, "")) {
		ZEPHIR_INIT_VAR(&_15$$20);
		ZVAL_STRING(&_15$$20, "element");
		ZEPHIR_CALL_METHOD(&_14$$20, &tagFactory, "newinstance", NULL, 0, &_15$$20);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_15$$20);
		ZEPHIR_GET_CONSTANT(&_15$$20, "PHP_EOL");
		ZEPHIR_INIT_VAR(&_16$$20);
		ZVAL_STRING(&_16$$20, "select");
		ZVAL_BOOL(&_17$$20, 1);
		ZEPHIR_RETURN_CALL_METHOD(&_14$$20, "__invoke", NULL, 0, &_16$$20, &_15$$20, &attrs, &_17$$20);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(&html);
}

/**
 * Set the choice's options
 *
 * @param array|object options
 */
PHP_METHOD(Phalcon_Forms_Element_Select, setOptions)
{
	zval *options, options_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(options)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &options);
	zephir_update_property_zval(this_ptr, ZEND_STRL("optionsValues"), options);
	RETURN_THISW();
}

/**
 * Returns an array of prepared attributes for Phalcon\Html\TagFactory
 * helpers according to the element parameters
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&name, &_0);
	zephir_array_update_long(&attributes, 0, &name, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_memory_observe(&defaultAttributes);
	zephir_read_property(&defaultAttributes, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&mergedAttributes);
	zephir_fast_array_merge(&mergedAttributes, &defaultAttributes, &attributes);
	ZEPHIR_CALL_METHOD(&value, this_ptr, "getvalue", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&value) != IS_NULL) {
		zephir_array_update_string(&mergedAttributes, SL("value"), &value, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(&mergedAttributes);
}

