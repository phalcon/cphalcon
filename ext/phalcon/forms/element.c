
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
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

	ZEPHIR_REGISTER_CLASS(Phalcon\\Forms, Element, phalcon, forms_element, phalcon_forms_element_method_entry, 0);

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
		ZEPHIR_CPY_WRT(attributes, ZEPHIR_GLOBAL(global_null));
	}


	zephir_update_property_this(this_ptr, SL("_name"), name TSRMLS_CC);
	if ((Z_TYPE_P(attributes) == IS_ARRAY)) {
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

		zephir_get_strval(name, name_param);


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

	zval *filter_param = NULL, *filters, *_0;
	zval *filter = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filter_param);

		zephir_get_strval(filter, filter_param);


	filters = zephir_fetch_nproperty_this(this_ptr, SL("_filters"), PH_NOISY_CC);
	if ((Z_TYPE_P(filters) == IS_ARRAY)) {
		zephir_update_property_array_append(this_ptr, SL("_filters"), filter TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(_0);
		array_init(_0);
		zephir_array_append(&_0, filters, 0);
		zephir_array_append(&_0, filter, 0);
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
	zval *validators, *merge_param = NULL, *currentValidators, *mergedValidators = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &validators, &merge_param);

	if (!merge_param) {
		merge = 1;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if ((Z_TYPE_P(validators) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_forms_exception_ce, "The validators parameter must be an array");
		return;
	}
	if (merge) {
		currentValidators = zephir_fetch_nproperty_this(this_ptr, SL("_validators"), PH_NOISY_CC);
		if ((Z_TYPE_P(currentValidators) == IS_ARRAY)) {
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



	if ((Z_TYPE_P(validator) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_forms_exception_ce, "The validators parameter must be an object");
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

	zend_bool useChecked;
	zval *attributes = NULL, *useChecked_param = NULL, *value, *name, *widgetAttributes = NULL, *mergedAttributes = NULL, *defaultAttributes, *currentValue, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &attributes, &useChecked_param);

	if (!attributes) {
		ZEPHIR_CPY_WRT(attributes, ZEPHIR_GLOBAL(global_null));
	}
	if (!useChecked_param) {
		useChecked = 0;
	} else {
		useChecked = zephir_get_boolval(useChecked_param);
	}


	name = zephir_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY_CC);
	if ((Z_TYPE_P(attributes) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(widgetAttributes);
		array_init(widgetAttributes);
	} else {
		ZEPHIR_CPY_WRT(widgetAttributes, attributes);
	}
	zephir_array_update_long(&widgetAttributes, 0, &name, PH_COPY | PH_SEPARATE);
	defaultAttributes = zephir_fetch_nproperty_this(this_ptr, SL("_attributes"), PH_NOISY_CC);
	if ((Z_TYPE_P(defaultAttributes) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(mergedAttributes);
		zephir_fast_array_merge(mergedAttributes, &(defaultAttributes), &(widgetAttributes) TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(mergedAttributes, widgetAttributes);
	}
	ZEPHIR_INIT_VAR(value);
	zephir_call_method(value, this_ptr, "getvalue");
	if ((Z_TYPE_P(value) != IS_NULL)) {
		if (useChecked) {
			ZEPHIR_OBS_VAR(currentValue);
			if (zephir_array_isset_string_fetch(&currentValue, mergedAttributes, SS("value") TSRMLS_CC)) {
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
		ZEPHIR_CPY_WRT(defaultValue, ZEPHIR_GLOBAL(global_null));
	}


	attributes = zephir_fetch_nproperty_this(this_ptr, SL("_attributes"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(value);
	if (zephir_array_isset_fetch(&value, attributes, attribute TSRMLS_CC)) {
		RETURN_CCTOR(value);
	}
	RETURN_CCTOR(defaultValue);

}

/**
 * Sets default attributes for the element
 *
 * @param array attributes
 * @return Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, setAttributes) {

	zval *attributes;

	zephir_fetch_params(0, 1, 0, &attributes);



	if ((Z_TYPE_P(attributes) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_forms_exception_ce, "Parameter 'attributes' must be an array");
		return;
	}
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
	if ((Z_TYPE_P(attributes) != IS_ARRAY)) {
		array_init(return_value);
		return;
	}
	RETURN_ZVAL(attributes, 1, 0);

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

	zval *option, *defaultValue = NULL, *value, *options;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &option, &defaultValue);

	if (!defaultValue) {
		ZEPHIR_CPY_WRT(defaultValue, ZEPHIR_GLOBAL(global_null));
	}


	options = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(value);
	if (zephir_array_isset_fetch(&value, options, option TSRMLS_CC)) {
		RETURN_CCTOR(value);
	}
	RETURN_CCTOR(defaultValue);

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
 * @return string
 */
PHP_METHOD(Phalcon_Forms_Element, label) {

	zval *attributes, *label, *name = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();

	attributes = zephir_fetch_nproperty_this(this_ptr, SL("_attributes"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(name);
	if (zephir_array_isset_string_fetch(&name, attributes, SS("id") TSRMLS_CC)) {
		ZEPHIR_OBS_NVAR(name);
		zephir_read_property_this(&name, this_ptr, SL("_name"), PH_NOISY_CC);
	}
	label = zephir_fetch_nproperty_this(this_ptr, SL("_label"), PH_NOISY_CC);
	if (zephir_is_true(label)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SV(_0, "<label for=\"", name);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_VS(_1, _0, "\">");
		ZEPHIR_INIT_VAR(_2);
		concat_function(_2, _1, label TSRMLS_CC);
		ZEPHIR_CONCAT_VS(return_value, _2, "</label>");
		RETURN_MM();
	}
	ZEPHIR_INIT_LNVAR(_0);
	ZEPHIR_CONCAT_SV(_0, "<label for=\"", name);
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_VS(_1, _0, "\">");
	ZEPHIR_INIT_LNVAR(_2);
	concat_function(_2, _1, name TSRMLS_CC);
	ZEPHIR_CONCAT_VS(return_value, _2, "</label>");
	RETURN_MM();

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

	zval *name, *form, *value = NULL, *_0;

	ZEPHIR_MM_GROW();

	name = zephir_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(value);
	ZVAL_NULL(value);
	form = zephir_fetch_nproperty_this(this_ptr, SL("_form"), PH_NOISY_CC);
	if ((Z_TYPE_P(form) == IS_OBJECT)) {
		ZEPHIR_INIT_VAR(_0);
		zephir_call_static_p1(_0, "Phalcon\\Tag", "hasvalue", name);
		if (!(zephir_is_true(_0))) {
			ZEPHIR_INIT_BNVAR(value);
			zephir_call_method_p1(value, form, "getvalue", name);
		}
	}
	if ((Z_TYPE_P(value) == IS_NULL)) {
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

	zval *messages;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(messages);
	zephir_read_property_this(&messages, this_ptr, SL("_messages"), PH_NOISY_CC);
	if ((Z_TYPE_P(messages) == IS_OBJECT)) {
		RETURN_CCTOR(messages);
	}
	ZEPHIR_INIT_BNVAR(messages);
	object_init_ex(messages, phalcon_validation_message_group_ce);
	zephir_call_method_noret(messages, "__construct");
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


	messages = zephir_fetch_nproperty_this(this_ptr, SL("_messages"), PH_NOISY_CC);
	if ((Z_TYPE_P(messages) == IS_OBJECT)) {
		RETURN_BOOL((zephir_fast_count_int(messages TSRMLS_CC) > 0));
	}
	RETURN_BOOL(0);

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

	zval *message, *messages, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message);



	messages = zephir_fetch_nproperty_this(this_ptr, SL("_messages"), PH_NOISY_CC);
	if ((Z_TYPE_P(messages) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, phalcon_validation_message_group_ce);
		zephir_call_method_noret(_0, "__construct");
		zephir_update_property_this(this_ptr, SL("_messages"), _0 TSRMLS_CC);
	}
	zephir_call_method_p1_noret(messages, "appendmessage", message);
	RETURN_THIS();

}

/**
 * Clears every element in the form to its default value
 *
 * @return Phalcon\Forms\Element
 */
PHP_METHOD(Phalcon_Forms_Element, clear) {

	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY_CC);
	zephir_call_static_p2_noret("Phalcon\\Tag", "setdefault", _0, ZEPHIR_GLOBAL(global_null));
	RETURN_THIS();

}

/**
 * Magic method __toString renders the widget without atttributes
 *
 * @return string
 */
PHP_METHOD(Phalcon_Forms_Element, __toString) {

	ZEPHIR_MM_GROW();

	zephir_call_method(return_value, this_ptr, "render");
	RETURN_MM();

}

