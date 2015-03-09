
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Forms\Element
 *
 * This is a base class for form elements
 */
ZEPHIR_INIT_CLASS(Phalcon_Forms_Element) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Forms, Element, phalcon, forms_element, phalcon_forms_element_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_forms_element_ce, SL("_form"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_forms_element_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_forms_element_ce, SL("_value"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_forms_element_ce, SL("_label"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_forms_element_ce, SL("_attributes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_forms_element_ce, SL("_validators"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_forms_element_ce, SL("_filters"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_forms_element_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_forms_element_ce, SL("_messages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Forms\Element constructor
 *
 * @param string name
 * @param array attributes
 */
PHP_METHOD(Phalcon_Forms_Element, __construct) {

	zval *name_param = NULL, *attributes = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &attributes);

	zephir_get_strval(name, name_param);
	if (!attributes) {
		attributes = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_this(this_ptr, SL("_name"), name TSRMLS_CC);
	if (Z_TYPE_P(attributes) == IS_ARRAY) {
		zephir_update_property_this(this_ptr, SL("_attributes"), attributes TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the parent form to the element
 *
 * @param Phalcon\Forms\Form form
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, setForm) {

	zval *form;

	zephir_fetch_params(0, 1, 0, &form);



	if (!(zephir_instance_of_ev(form, phalcon_forms_form_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'form' must be an instance of 'Phalcon\\Forms\\Form'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("_form"), form TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the parent form to the element
 *
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, getForm) {


	RETURN_MEMBER(this_ptr, "_form");

}

/**
 * Sets the element name
 *
 * @param string name
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, setName) {

	zval *name_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	zephir_update_property_this(this_ptr, SL("_name"), name TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the element name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Forms_Element, getName) {


	RETURN_MEMBER(this_ptr, "_name");

}

/**
 * Sets the element filters
 *
 * @param array|string filters
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, setFilters) {

	zval *filters;

	zephir_fetch_params(0, 1, 0, &filters);



	zephir_update_property_this(this_ptr, SL("_filters"), filters TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Adds a filter to current list of filters
 *
 * @param string filter
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, addFilter) {

	zval *_0;
	zval *filter_param = NULL, *filters;
	zval *filter = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filter_param);

	zephir_get_strval(filter, filter_param);


	filters = zephir_fetch_nproperty_this(this_ptr, SL("_filters"), PH_NOISY_CC);
	if (Z_TYPE_P(filters) == IS_ARRAY) {
		zephir_update_property_array_append(this_ptr, SL("_filters"), filter TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(_0);
		array_init_size(_0, 3);
		zephir_array_fast_append(_0, filters);
		zephir_array_fast_append(_0, filter);
		zephir_update_property_this(this_ptr, SL("_filters"), _0 TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Returns the element filters
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Forms_Element, getFilters) {


	RETURN_MEMBER(this_ptr, "_filters");

}

/**
 * Adds a group of validators
 *
 * @param Phalcon\Validation\ValidatorInterface[]
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, addValidators) {

	zend_bool merge;
	zval *validators_param = NULL, *merge_param = NULL, *currentValidators, *mergedValidators = NULL;
	zval *validators = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &validators_param, &merge_param);

	validators = validators_param;

	if (!merge_param) {
		merge = 1;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (merge) {
		ZEPHIR_OBS_VAR(currentValidators);
		zephir_read_property_this(&currentValidators, this_ptr, SL("_validators"), PH_NOISY_CC);
		if (Z_TYPE_P(currentValidators) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(mergedValidators);
			zephir_fast_array_merge(mergedValidators, &(currentValidators), &(validators) TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(mergedValidators, validators);
		}
		zephir_update_property_this(this_ptr, SL("_validators"), mergedValidators TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Adds a validator to the element
 *
 * @param Phalcon\Validation\ValidatorInterface
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, addValidator) {

	zval *validator;

	zephir_fetch_params(0, 1, 0, &validator);



	if (!(zephir_instance_of_ev(validator, phalcon_validation_validatorinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'validator' must be an instance of 'Phalcon\\Validation\\ValidatorInterface'", "", 0);
		return;
	}
	zephir_update_property_array_append(this_ptr, SL("_validators"), validator TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the validators registered for the element
 *
 * @return Phalcon\Validation\ValidatorInterface[]
 */
PHP_METHOD(Phalcon_Forms_Element, getValidators) {


	RETURN_MEMBER(this_ptr, "_validators");

}

/**
 * Returns an array of prepared attributes for Phalcon\Tag helpers
 * according to the element parameters
 *
 * @param array attributes
 * @param boolean useChecked
 * @return array
 */
PHP_METHOD(Phalcon_Forms_Element, prepareAttributes) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool useChecked;
	zval *attributes = NULL, *useChecked_param = NULL, *value = NULL, *name, *widgetAttributes = NULL, *mergedAttributes = NULL, *defaultAttributes, *currentValue, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &attributes, &useChecked_param);

	if (!attributes) {
		attributes = ZEPHIR_GLOBAL(global_null);
	}
	if (!useChecked_param) {
		useChecked = 0;
	} else {
		useChecked = zephir_get_boolval(useChecked_param);
	}


	ZEPHIR_OBS_VAR(name);
	zephir_read_property_this(&name, this_ptr, SL("_name"), PH_NOISY_CC);
	if (Z_TYPE_P(attributes) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(widgetAttributes);
		array_init(widgetAttributes);
	} else {
		ZEPHIR_CPY_WRT(widgetAttributes, attributes);
	}
	zephir_array_update_long(&widgetAttributes, 0, &name, PH_COPY | PH_SEPARATE, "phalcon/forms/element.zep", 219);
	ZEPHIR_OBS_VAR(defaultAttributes);
	zephir_read_property_this(&defaultAttributes, this_ptr, SL("_attributes"), PH_NOISY_CC);
	if (Z_TYPE_P(defaultAttributes) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(mergedAttributes);
		zephir_fast_array_merge(mergedAttributes, &(defaultAttributes), &(widgetAttributes) TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(mergedAttributes, widgetAttributes);
	}
	ZEPHIR_CALL_METHOD(&value, this_ptr, "getvalue", NULL);
	zephir_check_call_status();
	if (Z_TYPE_P(value) != IS_NULL) {
		if (useChecked) {
			if (zephir_array_isset_string_fetch(&currentValue, mergedAttributes, SS("value"), 1 TSRMLS_CC)) {
				if (ZEPHIR_IS_EQUAL(currentValue, value)) {
					ZEPHIR_INIT_VAR(_0);
					ZVAL_STRING(_0, "checked", 1);
					zephir_array_update_string(&mergedAttributes, SL("checked"), &_0, PH_COPY | PH_SEPARATE);
				}
			} else {
				if (zephir_is_true(value)) {
					ZEPHIR_INIT_NVAR(_0);
					ZVAL_STRING(_0, "checked", 1);
					zephir_array_update_string(&mergedAttributes, SL("checked"), &_0, PH_COPY | PH_SEPARATE);
				}
				zephir_array_update_string(&mergedAttributes, SL("value"), &value, PH_COPY | PH_SEPARATE);
			}
		} else {
			zephir_array_update_string(&mergedAttributes, SL("value"), &value, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(mergedAttributes);

}

/**
 * Sets a default attribute for the element
 *
 * @param string attribute
 * @param mixed value
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, setAttribute) {

	zval *attribute_param = NULL, *value;
	zval *attribute = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &attribute_param, &value);

	zephir_get_strval(attribute, attribute_param);


	zephir_update_property_array(this_ptr, SL("_attributes"), attribute, value TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the value of an attribute if present
 *
 * @param string attribute
 * @param mixed defaultValue
 * @return mixed
 */
PHP_METHOD(Phalcon_Forms_Element, getAttribute) {

	zval *attribute_param = NULL, *defaultValue = NULL, *attributes, *value;
	zval *attribute = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &attribute_param, &defaultValue);

	zephir_get_strval(attribute, attribute_param);
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	attributes = zephir_fetch_nproperty_this(this_ptr, SL("_attributes"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&value, attributes, attribute, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

/**
 * Sets default attributes for the element
 *
 * @param array attributes
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, setAttributes) {

	zval *attributes_param = NULL;
	zval *attributes = NULL;

	zephir_fetch_params(0, 1, 0, &attributes_param);

	attributes = attributes_param;



	zephir_update_property_this(this_ptr, SL("_attributes"), attributes TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the default attributes for the element
 *
 * @return array
 */
PHP_METHOD(Phalcon_Forms_Element, getAttributes) {

	zval *attributes;


	attributes = zephir_fetch_nproperty_this(this_ptr, SL("_attributes"), PH_NOISY_CC);
	if (Z_TYPE_P(attributes) != IS_ARRAY) {
		array_init(return_value);
		return;
	}
	RETURN_CTORW(attributes);

}

/**
 * Sets an option for the element
 *
 * @param string option
 * @param mixed value
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, setUserOption) {

	zval *option_param = NULL, *value;
	zval *option = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &option_param, &value);

	zephir_get_strval(option, option_param);


	zephir_update_property_array(this_ptr, SL("_options"), option, value TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the value of an option if present
 *
 * @param string option
 * @param mixed defaultValue
 * @return mixed
 */
PHP_METHOD(Phalcon_Forms_Element, getUserOption) {

	zval *option, *defaultValue = NULL, *value, *_0;

	zephir_fetch_params(0, 1, 1, &option, &defaultValue);

	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&value, _0, option, 1 TSRMLS_CC)) {
		RETURN_CTORW(value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	return;

}

/**
 * Sets options for the element
 *
 * @param array options
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, setUserOptions) {

	zval *options;

	zephir_fetch_params(0, 1, 0, &options);



	zephir_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the options for the element
 *
 * @return array
 */
PHP_METHOD(Phalcon_Forms_Element, getUserOptions) {


	RETURN_MEMBER(this_ptr, "_options");

}

/**
 * Sets the element label
 *
 * @param string label
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, setLabel) {

	zval *label_param = NULL;
	zval *label = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &label_param);

	zephir_get_strval(label, label_param);


	zephir_update_property_this(this_ptr, SL("_label"), label TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the element label
 *
 * @return string
 */
PHP_METHOD(Phalcon_Forms_Element, getLabel) {


	RETURN_MEMBER(this_ptr, "_label");

}

/**
 * Generate the HTML to label the element
 *
 * @param array attributes
 * @return string
 */
PHP_METHOD(Phalcon_Forms_Element, label) {

	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *attributes = NULL, *internalAttributes = NULL, *label, *name = NULL, *code = NULL, *_1, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &attributes);

	if (!attributes) {
		ZEPHIR_CPY_WRT(attributes, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(attributes);
	}


	ZEPHIR_CALL_METHOD(&internalAttributes, this_ptr, "getattributes", NULL);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(name);
	if (!(zephir_array_isset_string_fetch(&name, internalAttributes, SS("id"), 0 TSRMLS_CC))) {
		ZEPHIR_OBS_NVAR(name);
		zephir_read_property_this(&name, this_ptr, SL("_name"), PH_NOISY_CC);
	}
	if (Z_TYPE_P(attributes) == IS_ARRAY) {
		if (!(zephir_array_isset_string(attributes, SS("for")))) {
			zephir_array_update_string(&attributes, SL("for"), &name, PH_COPY | PH_SEPARATE);
		}
	} else {
		ZEPHIR_INIT_NVAR(attributes);
		array_init_size(attributes, 2);
		zephir_array_update_string(&attributes, SL("for"), &name, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "<label", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&code, phalcon_tag_ce, "renderattributes", &_0, _1, attributes);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	label = zephir_fetch_nproperty_this(this_ptr, SL("_label"), PH_NOISY_CC);
	if (zephir_is_true(label)) {
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SVS(_2, ">", label, "</label>");
		zephir_concat_self(&code, _2 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_LNVAR(_2);
		ZEPHIR_CONCAT_SVS(_2, ">", name, "</label>");
		zephir_concat_self(&code, _2 TSRMLS_CC);
	}
	RETURN_CCTOR(code);

}

/**
 * Sets a default value in case the form does not use an entity
 * or there is no value available for the element in _POST
 *
 * @param mixed value
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, setDefault) {

	zval *value;

	zephir_fetch_params(0, 1, 0, &value);



	zephir_update_property_this(this_ptr, SL("_value"), value TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the default value assigned to the element
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Forms_Element, getDefault) {


	RETURN_MEMBER(this_ptr, "_value");

}

/**
 * Returns the element value
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Forms_Element, getValue) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *name, *form, *value = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(name);
	zephir_read_property_this(&name, this_ptr, SL("_name"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(value);
	ZVAL_NULL(value);
	ZEPHIR_OBS_VAR(form);
	zephir_read_property_this(&form, this_ptr, SL("_form"), PH_NOISY_CC);
	if (Z_TYPE_P(form) == IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(&_0, phalcon_tag_ce, "hasvalue", &_1, name);
		zephir_check_call_status();
		if (!(zephir_is_true(_0))) {
			ZEPHIR_CALL_METHOD(&value, form, "getvalue", NULL, name);
			zephir_check_call_status();
		}
	}
	if (Z_TYPE_P(value) == IS_NULL) {
		ZEPHIR_OBS_NVAR(value);
		zephir_read_property_this(&value, this_ptr, SL("_value"), PH_NOISY_CC);
	}
	RETURN_CCTOR(value);

}

/**
 * Returns the messages that belongs to the element
 * The element needs to be attached to a form
 *
 * @return Phalcon\Validation\Message\Group
 */
PHP_METHOD(Phalcon_Forms_Element, getMessages) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *messages = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(messages);
	zephir_read_property_this(&messages, this_ptr, SL("_messages"), PH_NOISY_CC);
	if (Z_TYPE_P(messages) == IS_OBJECT) {
		RETURN_CCTOR(messages);
	}
	ZEPHIR_INIT_NVAR(messages);
	object_init_ex(messages, phalcon_validation_message_group_ce);
	ZEPHIR_CALL_METHOD(NULL, messages, "__construct", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_messages"), messages TSRMLS_CC);
	RETURN_CCTOR(messages);

}

/**
 * Checks whether there are messages attached to the element
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Forms_Element, hasMessages) {

	zval *messages;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(messages);
	zephir_read_property_this(&messages, this_ptr, SL("_messages"), PH_NOISY_CC);
	if (Z_TYPE_P(messages) == IS_OBJECT) {
		RETURN_MM_BOOL(zephir_fast_count_int(messages TSRMLS_CC) > 0);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Sets the validation messages related to the element
 *
 * @param Phalcon\Validation\Message\Group group
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, setMessages) {

	zval *group;

	zephir_fetch_params(0, 1, 0, &group);



	if (!(zephir_instance_of_ev(group, phalcon_validation_message_group_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'group' must be an instance of 'Phalcon\\Validation\\Message\\Group'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("_messages"), group TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Appends a message to the internal message list
 *
 * @param Phalcon\Validation\Message message
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, appendMessage) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *message, *messages, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message);



	if (!(zephir_instance_of_ev(message, phalcon_validation_messageinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'message' must be an instance of 'Phalcon\\Validation\\MessageInterface'", "", 0);
		return;
	}
	ZEPHIR_OBS_VAR(messages);
	zephir_read_property_this(&messages, this_ptr, SL("_messages"), PH_NOISY_CC);
	if (Z_TYPE_P(messages) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, phalcon_validation_message_group_ce);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_messages"), _0 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(NULL, messages, "appendmessage", NULL, message);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Clears every element in the form to its default value
 *
 * @return Phalcon\Forms\Element
 */
PHP_METHOD(Phalcon_Forms_Element, clear) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1, *_2;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;

	ZEPHIR_MM_GROW();

	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_NULL(_2);
	ZEPHIR_CALL_CE_STATIC(NULL, phalcon_tag_ce, "setdefault", &_0, _1, _2);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Magic method __toString renders the widget without atttributes
 *
 * @return string
 */
PHP_METHOD(Phalcon_Forms_Element, __toString) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "render", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

