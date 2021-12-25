
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
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
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
 * This is a base class for form elements
 */
ZEPHIR_INIT_CLASS(Phalcon_Forms_Element_AbstractElement)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Forms\\Element, AbstractElement, phalcon, forms_element_abstractelement, phalcon_forms_element_abstractelement_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_forms_element_abstractelement_ce, SL("attributes"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_forms_element_abstractelement_ce, SL("filters"), ZEND_ACC_PROTECTED);
	/**
	 * @var Form|null
	 */
	zend_declare_property_null(phalcon_forms_element_abstractelement_ce, SL("form"), ZEND_ACC_PROTECTED);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_forms_element_abstractelement_ce, SL("label"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_forms_element_abstractelement_ce, SL("method"), "inputText", ZEND_ACC_PROTECTED);
	/**
	 * @var Messages
	 */
	zend_declare_property_null(phalcon_forms_element_abstractelement_ce, SL("messages"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_forms_element_abstractelement_ce, SL("name"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_forms_element_abstractelement_ce, SL("options"), ZEND_ACC_PROTECTED);
	/**
	 * @var TagFactory|null
	 */
	zend_declare_property_null(phalcon_forms_element_abstractelement_ce, SL("tagFactory"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_forms_element_abstractelement_ce, SL("validators"), ZEND_ACC_PROTECTED);
	/**
	 * @var mixed|null
	 */
	zend_declare_property_null(phalcon_forms_element_abstractelement_ce, SL("value"), ZEND_ACC_PROTECTED);
	phalcon_forms_element_abstractelement_ce->create_object = zephir_init_properties_Phalcon_Forms_Element_AbstractElement;

	zend_class_implements(phalcon_forms_element_abstractelement_ce, 1, phalcon_forms_element_elementinterface_ce);
	return SUCCESS;
}

/**
 * Phalcon\Forms\Element constructor
 *
 * @param string name       Attribute name (value of 'name' attribute of HTML element)
 * @param array  attributes Additional HTML element attributes
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zval *name_param = NULL, *attributes_param = NULL, _0, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&attributes);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &attributes_param);
	zephir_get_strval(&name, name_param);
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_trim(&_0, &name, NULL , ZEPHIR_TRIM_BOTH);
	zephir_get_strval(&name, &_0);
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&name))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Form element name is required", "phalcon/Forms/Element/AbstractElement.zep", 94);
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &name);
	zephir_update_property_zval(this_ptr, ZEND_STRL("attributes"), &attributes);
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, phalcon_messages_messages_ce);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 8);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("messages"), &_1);
	ZEPHIR_MM_RESTORE();
}

/**
 * Magic method __toString renders the widget without attributes
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, __toString)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "render", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds a filter to current list of filters
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, addFilter)
{
	zval _1$$5, _2$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *filter_param = NULL, filters, _0;
	zval filter;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filter)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filter_param);
	zephir_get_strval(&filter, filter_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("filters"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&filters, &_0);
	if (Z_TYPE_P(&filters) == IS_ARRAY) {
		zephir_update_property_array_append(this_ptr, SL("filters"), &filter);
	} else {
		if (Z_TYPE_P(&filters) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_1$$5);
			zephir_create_array(&_1$$5, 2, 0);
			zephir_array_fast_append(&_1$$5, &filters);
			zephir_array_fast_append(&_1$$5, &filter);
			zephir_update_property_zval(this_ptr, ZEND_STRL("filters"), &_1$$5);
		} else {
			ZEPHIR_INIT_VAR(&_2$$6);
			zephir_create_array(&_2$$6, 1, 0);
			zephir_array_fast_append(&_2$$6, &filter);
			zephir_update_property_zval(this_ptr, ZEND_STRL("filters"), &_2$$6);
		}
	}
	RETURN_THIS();
}

/**
 * Adds a validator to the element
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, addValidator)
{
	zval *validator, validator_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validator_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(validator, phalcon_filter_validation_validatorinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &validator);


	zephir_update_property_array_append(this_ptr, SL("validators"), validator);
	RETURN_THISW();
}

/**
 * Adds a group of validators
 *
 * @param \Phalcon\Filter\Validation\ValidatorInterface[] validators
 * @param bool                                            merge
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, addValidators)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool merge;
	zval *validators_param = NULL, *merge_param = NULL, validator, *_1, _2, _0$$3;
	zval validators;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validators);
	ZVAL_UNDEF(&validator);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(validators)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(merge)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &validators_param, &merge_param);
	ZEPHIR_OBS_COPY_OR_DUP(&validators, validators_param);
	if (!merge_param) {
		merge = 1;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (UNEXPECTED(!merge)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		array_init(&_0$$3);
		zephir_update_property_zval(this_ptr, ZEND_STRL("validators"), &_0$$3);
	}
	zephir_is_iterable(&validators, 0, "phalcon/Forms/Element/AbstractElement.zep", 160);
	if (Z_TYPE_P(&validators) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&validators), _1)
		{
			ZEPHIR_INIT_NVAR(&validator);
			ZVAL_COPY(&validator, _1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "addvalidator", &_3, 0, &validator);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &validators, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &validators, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&validator, &validators, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "addvalidator", &_3, 0, &validator);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &validators, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&validator);
	RETURN_THIS();
}

/**
 * Appends a message to the internal message list
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, appendMessage)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message, message_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(message, phalcon_messages_messageinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("messages"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "appendmessage", NULL, 0, message);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Clears element to its default value
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, clear)
{
	zval form, _0, name;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&form);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&name);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("form"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&form, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&name, &_0);
	if (Z_TYPE_P(&form) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, &form, "clear", NULL, 0, &name);
		zephir_check_call_status();
	}
	RETURN_THIS();
}

/**
 * Returns the value of an attribute if present
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getAttribute)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *attribute_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null, attributes, value, _0;
	zval attribute;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(attribute)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &attribute_param, &defaultValue);
	zephir_get_strval(&attribute, attribute_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&attributes, &_0);
	if (!(zephir_array_isset_fetch(&value, &attributes, &attribute, 1))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	RETURN_CTOR(&value);
}

/**
 * Returns the default attributes for the element
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getAttributes)
{
	zval attributes, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&attributes, &_0);
	RETURN_CCTOR(&attributes);
}

/**
 * Returns the default value assigned to the element
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getDefault)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "value");
}

/**
 * Returns the element filters
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getFilters)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "filters");
}

/**
 * Returns the parent form to the element
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getForm)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "form");
}

/**
 * Returns the element label
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getLabel)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "label");
}

/**
 * Returns the messages that belongs to the element
 * The element needs to be attached to a form
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getMessages)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "messages");
}

/**
 * Returns the element name
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getName)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "name");
}

/**
 * Returns the tagFactory; throws exception if not present
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getTagFactory)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "tagFactory");
}

/**
 * Returns the value of an option if present
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getUserOption)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *option_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null, value, _0;
	zval option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(option)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &option_param, &defaultValue);
	zephir_get_strval(&option, option_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&value, &_0, &option, 1))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	RETURN_CTOR(&value);
}

/**
 * Returns the options for the element
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getUserOptions)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "options");
}

/**
 * Returns the validators registered for the element
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getValidators)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "validators");
}

/**
 * Returns the element's value
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getValue)
{
	zval name, _0, form, value, _1$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&form);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1$$4);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&name, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("form"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&form, &_0);
	ZEPHIR_INIT_VAR(&value);
	ZVAL_NULL(&value);
	if (Z_TYPE_P(&form) == IS_OBJECT) {
		ZEPHIR_RETURN_CALL_METHOD(&form, "getvalue", NULL, 0, &name);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (Z_TYPE_P(&value) == IS_NULL) {
		zephir_read_property(&_1$$4, this_ptr, ZEND_STRL("value"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&value, &_1$$4);
	}
	RETURN_CCTOR(&value);
}

/**
 * Checks whether there are messages attached to the element
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, hasMessages)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("messages"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_fast_count_int(&_0) > 0);
}

/**
 * Generate the HTML to label the element
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, label)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, code, internalAttributes, labelName, name, tagFactory, _0$$3;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&internalAttributes);
	ZVAL_UNDEF(&labelName);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&tagFactory);
	ZVAL_UNDEF(&_0$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &attributes_param);
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}


	ZEPHIR_CALL_METHOD(&tagFactory, this_ptr, "getlocaltagfactory", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&internalAttributes);
	zephir_read_property(&internalAttributes, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&name);
	if (!(zephir_array_isset_string_fetch(&name, &internalAttributes, SL("id"), 0))) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&name, &_0$$3);
	}
	if (!(zephir_array_isset_string(&attributes, SL("for")))) {
		zephir_array_update_string(&attributes, SL("for"), &name, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(&labelName);
	zephir_read_property(&labelName, this_ptr, ZEND_STRL("label"), PH_NOISY_CC);
	_1 = zephir_is_true(&labelName);
	if (!(_1)) {
		_1 = zephir_is_numeric(&labelName);
	}
	if (!(_1)) {
		ZEPHIR_CPY_WRT(&labelName, &name);
	}
	ZEPHIR_CALL_METHOD(&code, &tagFactory, "label", NULL, 0, &labelName, &attributes);
	zephir_check_call_status();
	RETURN_CCTOR(&code);
}

/**
 * Renders the element widget returning HTML
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, render)
{
	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, helper, merged, method, name, result, tagFactory, value, _0;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&helper);
	ZVAL_UNDEF(&merged);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&tagFactory);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &attributes_param);
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&name, &_0);
	ZEPHIR_CALL_METHOD(&value, this_ptr, "getvalue", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("method"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&method, &_0);
	ZEPHIR_CALL_METHOD(&tagFactory, this_ptr, "getlocaltagfactory", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&helper, &tagFactory, "newinstance", NULL, 0, &method);
	zephir_check_call_status();
	if (zephir_array_isset_string(&attributes, SL("value"))) {
		ZEPHIR_OBS_NVAR(&value);
		zephir_array_fetch_string(&value, &attributes, SL("value"), PH_NOISY, "phalcon/Forms/Element/AbstractElement.zep", 388);
		zephir_array_unset_string(&attributes, SL("value"), PH_SEPARATE);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&merged);
	zephir_fast_array_merge(&merged, &_0, &attributes);
	ZEPHIR_CALL_METHOD(&result, &helper, "__invoke", NULL, 0, &name, &value, &merged);
	zephir_check_call_status();
	zephir_cast_to_string(&_1, &result);
	RETURN_CTOR(&_1);
}

/**
 * Sets a default attribute for the element
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, setAttribute)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *attribute_param = NULL, *value, value_sub;
	zval attribute;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&value_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(attribute)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &attribute_param, &value);
	zephir_get_strval(&attribute, attribute_param);


	zephir_update_property_array(this_ptr, SL("attributes"), &attribute, value);
	RETURN_THIS();
}

/**
 * Sets default attributes for the element
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, setAttributes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *attributes_param = NULL;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);
	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("attributes"), &attributes);
	RETURN_THIS();
}

/**
 * Sets a default value in case the form does not use an entity
 * or there is no value available for the element in _POST
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, setDefault)
{
	zval *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &value);


	zephir_update_property_zval(this_ptr, ZEND_STRL("value"), value);
	RETURN_THISW();
}

/**
 * Sets the element filters
 *
 * @param array|string filters
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, setFilters)
{
	zend_bool _0;
	zval *filters, filters_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filters_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(filters)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &filters);


	_0 = Z_TYPE_P(filters) != IS_STRING;
	if (_0) {
		_0 = Z_TYPE_P(filters) != IS_ARRAY;
	}
	if (UNEXPECTED(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_forms_exception_ce, "The filter needs to be an array or string", "phalcon/Forms/Element/AbstractElement.zep", 437);
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("filters"), filters);
	RETURN_THISW();
}

/**
 * Sets the parent form to the element
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, setForm)
{
	zval *form, form_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&form_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(form, phalcon_forms_form_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &form);


	zephir_update_property_zval(this_ptr, ZEND_STRL("form"), form);
	RETURN_THISW();
}

/**
 * Sets the element label
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, setLabel)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *label_param = NULL;
	zval label;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&label);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(label)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &label_param);
	zephir_get_strval(&label, label_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("label"), &label);
	RETURN_THIS();
}

/**
 * Sets the validation messages related to the element
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, setMessages)
{
	zval *messages, messages_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&messages_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(messages, phalcon_messages_messages_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &messages);


	zephir_update_property_zval(this_ptr, ZEND_STRL("messages"), messages);
	RETURN_THISW();
}

/**
 * Sets the element name
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, setName)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &name);
	RETURN_THIS();
}

/**
 * Sets the TagFactory
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, setTagFactory)
{
	zval *tagFactory, tagFactory_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tagFactory_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(tagFactory, phalcon_html_tagfactory_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &tagFactory);


	zephir_update_property_zval(this_ptr, ZEND_STRL("tagFactory"), tagFactory);
	RETURN_THISW();
}

/**
 * Sets an option for the element
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, setUserOption)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *option_param = NULL, *value, value_sub;
	zval option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&value_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(option)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &option_param, &value);
	zephir_get_strval(&option, option_param);


	zephir_update_property_array(this_ptr, SL("options"), &option, value);
	RETURN_THIS();
}

/**
 * Sets options for the element
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, setUserOptions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);
	zephir_get_arrval(&options, options_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("options"), &options);
	RETURN_THIS();
}

/**
 * Returns the tagFactory; throws exception if not present
 */
PHP_METHOD(Phalcon_Forms_Element_AbstractElement, getLocalTagFactory)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("tagFactory"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_forms_exception_ce, "The TagFactory must be set for this element to render", "phalcon/Forms/Element/AbstractElement.zep", 523);
		return;
	}
	RETURN_MEMBER(getThis(), "tagFactory");
}

zend_object *zephir_init_properties_Phalcon_Forms_Element_AbstractElement(zend_class_entry *class_type)
{
		zval _0, _2, _4, _6, _1$$3, _3$$4, _5$$5, _7$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("validators"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("validators"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("options"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("filters"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("filters"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("attributes"), &_7$$6);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

