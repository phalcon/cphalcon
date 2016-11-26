
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/concat.h"


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

	phalcon_forms_element_ce->create_object = zephir_init_properties_Phalcon_Forms_Element;

	zend_class_implements(phalcon_forms_element_ce TSRMLS_CC, 1, phalcon_forms_elementinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Forms\Element constructor
 *
 * @param string name
 * @param array attributes
 */
PHP_METHOD(Phalcon_Forms_Element, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *attributes = NULL, attributes_sub, __$null, _0;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&attributes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &attributes);

	zephir_get_strval(&name, name_param);
	if (!attributes) {
		attributes = &attributes_sub;
		attributes = &__$null;
	}


	zephir_update_property_zval(this_ptr, SL("_name"), &name);
	if (Z_TYPE_P(attributes) == IS_ARRAY) {
		zephir_update_property_zval(this_ptr, SL("_attributes"), attributes);
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_validation_message_group_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 3);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_messages"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the parent form to the element
 */
PHP_METHOD(Phalcon_Forms_Element, setForm) {

	zval *form, form_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&form_sub);

	zephir_fetch_params(0, 1, 0, &form);



	zephir_update_property_zval(this_ptr, SL("_form"), form);
	RETURN_THISW();

}

/**
 * Returns the parent form to the element
 */
PHP_METHOD(Phalcon_Forms_Element, getForm) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_form");

}

/**
 * Sets the element name
 */
PHP_METHOD(Phalcon_Forms_Element, setName) {

	zval *name_param = NULL;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_update_property_zval(this_ptr, SL("_name"), &name);
	RETURN_THIS();

}

/**
 * Returns the element name
 */
PHP_METHOD(Phalcon_Forms_Element, getName) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_name");

}

/**
 * Sets the element filters
 *
 * @param array|string filters
 * @return \Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, setFilters) {

	zend_bool _0;
	zval *filters, filters_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&filters_sub);

	zephir_fetch_params(0, 1, 0, &filters);



	_0 = Z_TYPE_P(filters) != IS_STRING;
	if (_0) {
		_0 = Z_TYPE_P(filters) != IS_ARRAY;
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_forms_exception_ce, "Wrong filter type added", "phalcon/forms/element.zep", 113);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("_filters"), filters);
	RETURN_THISW();

}

/**
 * Adds a filter to current list of filters
 */
PHP_METHOD(Phalcon_Forms_Element, addFilter) {

	zval _0$$5, _1$$6;
	zval *filter_param = NULL, filters;
	zval filter;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filter_param);

	zephir_get_strval(&filter, filter_param);


	zephir_read_property(&filters, this_ptr, SL("_filters"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&filters) == IS_ARRAY) {
		zephir_update_property_array_append(this_ptr, SL("_filters"), &filter TSRMLS_CC);
	} else {
		if (Z_TYPE_P(&filters) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_0$$5);
			zephir_create_array(&_0$$5, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(&_0$$5, &filters);
			zephir_array_fast_append(&_0$$5, &filter);
			zephir_update_property_zval(this_ptr, SL("_filters"), &_0$$5);
		} else {
			ZEPHIR_INIT_VAR(&_1$$6);
			zephir_create_array(&_1$$6, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(&_1$$6, &filter);
			zephir_update_property_zval(this_ptr, SL("_filters"), &_1$$6);
		}
	}
	RETURN_THIS();

}

/**
 * Returns the element filters
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Forms_Element, getFilters) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_filters");

}

/**
 * Adds a group of validators
 *
 * @param \Phalcon\Validation\ValidatorInterface[]
 * @return \Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, addValidators) {

	zend_bool merge;
	zval *validators_param = NULL, *merge_param = NULL, currentValidators, mergedValidators;
	zval validators;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&validators);
	ZVAL_UNDEF(&currentValidators);
	ZVAL_UNDEF(&mergedValidators);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &validators_param, &merge_param);

	ZEPHIR_OBS_COPY_OR_DUP(&validators, validators_param);
	if (!merge_param) {
		merge = 1;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (merge) {
		ZEPHIR_OBS_VAR(&currentValidators);
		zephir_read_property(&currentValidators, this_ptr, SL("_validators"), PH_NOISY_CC);
		if (Z_TYPE_P(&currentValidators) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&mergedValidators);
			zephir_fast_array_merge(&mergedValidators, &currentValidators, &validators TSRMLS_CC);
		}
	} else {
		ZEPHIR_CPY_WRT(&mergedValidators, &validators);
	}
	zephir_update_property_zval(this_ptr, SL("_validators"), &mergedValidators);
	RETURN_THIS();

}

/**
 * Adds a validator to the element
 */
PHP_METHOD(Phalcon_Forms_Element, addValidator) {

	zval *validator, validator_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&validator_sub);

	zephir_fetch_params(0, 1, 0, &validator);



	zephir_update_property_array_append(this_ptr, SL("_validators"), validator TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the validators registered for the element
 */
PHP_METHOD(Phalcon_Forms_Element, getValidators) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_validators");

}

/**
 * Returns an array of prepared attributes for Phalcon\Tag helpers
 * according to the element parameters
 */
PHP_METHOD(Phalcon_Forms_Element, prepareAttributes) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool useChecked;
	zval *attributes_param = NULL, *useChecked_param = NULL, value, name, widgetAttributes, mergedAttributes, defaultAttributes, currentValue, _0$$10, _1$$12;
	zval attributes;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&widgetAttributes);
	ZVAL_UNDEF(&mergedAttributes);
	ZVAL_UNDEF(&defaultAttributes);
	ZVAL_UNDEF(&currentValue);
	ZVAL_UNDEF(&_0$$10);
	ZVAL_UNDEF(&_1$$12);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &attributes_param, &useChecked_param);

	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	if (!useChecked_param) {
		useChecked = 0;
	} else {
		useChecked = zephir_get_boolval(useChecked_param);
	}


	ZEPHIR_OBS_VAR(&name);
	zephir_read_property(&name, this_ptr, SL("_name"), PH_NOISY_CC);
	if (1 != 1) {
		ZEPHIR_INIT_VAR(&widgetAttributes);
		array_init(&widgetAttributes);
	} else {
		ZEPHIR_CPY_WRT(&widgetAttributes, &attributes);
	}
	zephir_array_update_long(&widgetAttributes, 0, &name, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	ZEPHIR_OBS_VAR(&defaultAttributes);
	zephir_read_property(&defaultAttributes, this_ptr, SL("_attributes"), PH_NOISY_CC);
	if (Z_TYPE_P(&defaultAttributes) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&mergedAttributes);
		zephir_fast_array_merge(&mergedAttributes, &defaultAttributes, &widgetAttributes TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(&mergedAttributes, &widgetAttributes);
	}
	ZEPHIR_CALL_METHOD(&value, this_ptr, "getvalue", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&value) != IS_NULL) {
		if (useChecked) {
			if (zephir_array_isset_string_fetch(&currentValue, &mergedAttributes, SL("value"), 1)) {
				if (ZEPHIR_IS_EQUAL(&currentValue, &value)) {
					ZEPHIR_INIT_VAR(&_0$$10);
					ZVAL_STRING(&_0$$10, "checked");
					zephir_array_update_string(&mergedAttributes, SL("checked"), &_0$$10, PH_COPY | PH_SEPARATE);
				}
			} else {
				if (zephir_is_true(&value)) {
					ZEPHIR_INIT_VAR(&_1$$12);
					ZVAL_STRING(&_1$$12, "checked");
					zephir_array_update_string(&mergedAttributes, SL("checked"), &_1$$12, PH_COPY | PH_SEPARATE);
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
 * @return \Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, setAttribute) {

	zval *attribute_param = NULL, *value, value_sub;
	zval attribute;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &attribute_param, &value);

	zephir_get_strval(&attribute, attribute_param);


	zephir_update_property_array(this_ptr, SL("_attributes"), &attribute, value TSRMLS_CC);
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

	zval *attribute_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null, attributes, value;
	zval attribute;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &attribute_param, &defaultValue);

	zephir_get_strval(&attribute, attribute_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	zephir_read_property(&attributes, this_ptr, SL("_attributes"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&value, &attributes, &attribute, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

/**
 * Sets default attributes for the element
 */
PHP_METHOD(Phalcon_Forms_Element, setAttributes) {

	zval *attributes_param = NULL;
	zval attributes;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&attributes);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);

	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);


	zephir_update_property_zval(this_ptr, SL("_attributes"), &attributes);
	RETURN_THIS();

}

/**
 * Returns the default attributes for the element
 */
PHP_METHOD(Phalcon_Forms_Element, getAttributes) {

	zval attributes;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&attributes);


	zephir_read_property(&attributes, this_ptr, SL("_attributes"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&attributes) != IS_ARRAY) {
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
 * @return \Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, setUserOption) {

	zval *option_param = NULL, *value, value_sub;
	zval option;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &option_param, &value);

	zephir_get_strval(&option, option_param);


	zephir_update_property_array(this_ptr, SL("_options"), &option, value TSRMLS_CC);
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

	zval *option_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null, value, _0;
	zval option;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &option_param, &defaultValue);

	zephir_get_strval(&option, option_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("_options"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&value, &_0, &option, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

/**
 * Sets options for the element
 */
PHP_METHOD(Phalcon_Forms_Element, setUserOptions) {

	zval *options_param = NULL;
	zval options;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(&options, options_param);


	zephir_update_property_zval(this_ptr, SL("_options"), &options);
	RETURN_THIS();

}

/**
 * Returns the options for the element
 */
PHP_METHOD(Phalcon_Forms_Element, getUserOptions) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_options");

}

/**
 * Sets the element label
 */
PHP_METHOD(Phalcon_Forms_Element, setLabel) {

	zval *label_param = NULL;
	zval label;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&label);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &label_param);

	zephir_get_strval(&label, label_param);


	zephir_update_property_zval(this_ptr, SL("_label"), &label);
	RETURN_THIS();

}

/**
 * Returns the element label
 */
PHP_METHOD(Phalcon_Forms_Element, getLabel) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_label");

}

/**
 * Generate the HTML to label the element
 *
 * @param array attributes
 */
PHP_METHOD(Phalcon_Forms_Element, label) {

	zephir_fcall_cache_entry *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *attributes = NULL, attributes_sub, __$null, internalAttributes, label, name, code, _1, _2$$7, _3$$8;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&attributes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&internalAttributes);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_3$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &attributes);

	if (!attributes) {
		attributes = &attributes_sub;
		ZEPHIR_CPY_WRT(attributes, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(attributes);
	}


	ZEPHIR_CALL_METHOD(&internalAttributes, this_ptr, "getattributes", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&name);
	if (!(zephir_array_isset_string_fetch(&name, &internalAttributes, SL("id"), 0))) {
		ZEPHIR_OBS_NVAR(&name);
		zephir_read_property(&name, this_ptr, SL("_name"), PH_NOISY_CC);
	}
	if (Z_TYPE_P(attributes) == IS_ARRAY) {
		if (!(zephir_array_isset_string(attributes, SL("for")))) {
			zephir_array_update_string(attributes, SL("for"), &name, PH_COPY | PH_SEPARATE);
		}
	} else {
		ZEPHIR_INIT_NVAR(attributes);
		zephir_create_array(attributes, 1, 0 TSRMLS_CC);
		zephir_array_update_string(attributes, SL("for"), &name, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "<label");
	ZEPHIR_CALL_CE_STATIC(&code, phalcon_tag_ce, "renderattributes", &_0, 4, &_1, attributes);
	zephir_check_call_status();
	zephir_read_property(&label, this_ptr, SL("_label"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&label)) {
		ZEPHIR_INIT_VAR(&_2$$7);
		ZEPHIR_CONCAT_SVS(&_2$$7, ">", &label, "</label>");
		zephir_concat_self(&code, &_2$$7 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(&_3$$8);
		ZEPHIR_CONCAT_SVS(&_3$$8, ">", &name, "</label>");
		zephir_concat_self(&code, &_3$$8 TSRMLS_CC);
	}
	RETURN_CCTOR(code);

}

/**
 * Sets a default value in case the form does not use an entity
 * or there is no value available for the element in _POST
 *
 * @param mixed value
 * @return \Phalcon\Forms\ElementInterface
 */
PHP_METHOD(Phalcon_Forms_Element, setDefault) {

	zval *value, value_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&value_sub);

	zephir_fetch_params(0, 1, 0, &value);



	zephir_update_property_zval(this_ptr, SL("_value"), value);
	RETURN_THISW();

}

/**
 * Returns the default value assigned to the element
 */
PHP_METHOD(Phalcon_Forms_Element, getDefault) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_value");

}

/**
 * Returns the element value
 */
PHP_METHOD(Phalcon_Forms_Element, getValue) {

	zend_bool _0$$3;
	zval name, form, value, _1$$3;
	zephir_fcall_cache_entry *_2 = NULL, *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&form);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&name);
	zephir_read_property(&name, this_ptr, SL("_name"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&value);
	ZVAL_NULL(&value);
	ZEPHIR_OBS_VAR(&form);
	zephir_read_property(&form, this_ptr, SL("_form"), PH_NOISY_CC);
	if (Z_TYPE_P(&form) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&value, &form, "getvalue", NULL, 0, &name);
		zephir_check_call_status();
		_0$$3 = Z_TYPE_P(&value) == IS_NULL;
		if (_0$$3) {
			ZEPHIR_CALL_CE_STATIC(&_1$$3, phalcon_tag_ce, "hasvalue", &_2, 5, &name);
			zephir_check_call_status();
			_0$$3 = zephir_is_true(&_1$$3);
		}
		if (_0$$3) {
			ZEPHIR_CALL_CE_STATIC(&value, phalcon_tag_ce, "getvalue", &_3, 6, &name);
			zephir_check_call_status();
		}
	}
	if (Z_TYPE_P(&value) == IS_NULL) {
		ZEPHIR_OBS_NVAR(&value);
		zephir_read_property(&value, this_ptr, SL("_value"), PH_NOISY_CC);
	}
	RETURN_CCTOR(value);

}

/**
 * Returns the messages that belongs to the element
 * The element needs to be attached to a form
 */
PHP_METHOD(Phalcon_Forms_Element, getMessages) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_messages");

}

/**
 * Checks whether there are messages attached to the element
 */
PHP_METHOD(Phalcon_Forms_Element, hasMessages) {

	zval _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("_messages"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_fast_count_int(&_0 TSRMLS_CC) > 0);

}

/**
 * Sets the validation messages related to the element
 */
PHP_METHOD(Phalcon_Forms_Element, setMessages) {

	zval *group, group_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&group_sub);

	zephir_fetch_params(0, 1, 0, &group);



	zephir_update_property_zval(this_ptr, SL("_messages"), group);
	RETURN_THISW();

}

/**
 * Appends a message to the internal message list
 */
PHP_METHOD(Phalcon_Forms_Element, appendMessage) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *message, message_sub, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message);



	zephir_read_property(&_0, this_ptr, SL("_messages"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "appendmessage", NULL, 0, message);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Clears every element in the form to its default value
 */
PHP_METHOD(Phalcon_Forms_Element, clear) {

	zval _1, _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_1, this_ptr, SL("_name"), PH_NOISY_CC | PH_READONLY);
	ZVAL_NULL(&_2);
	ZEPHIR_CALL_CE_STATIC(NULL, phalcon_tag_ce, "setdefault", &_0, 7, &_1, &_2);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Magic method __toString renders the widget without attributes
 */
PHP_METHOD(Phalcon_Forms_Element, __toString) {

	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "render", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object *zephir_init_properties_Phalcon_Forms_Element(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("_validators"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("_validators"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

