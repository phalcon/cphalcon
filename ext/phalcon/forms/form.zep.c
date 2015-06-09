
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
#include "ext/spl/spl_iterators.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/hash.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


/**
 * Phalcon\Forms\Form
 *
 * This component allows to build forms using an object-oriented interface
 */
ZEPHIR_INIT_CLASS(Phalcon_Forms_Form) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Forms, Form, phalcon, forms_form, phalcon_di_injectable_ce, phalcon_forms_form_method_entry, 0);

	zend_declare_property_null(phalcon_forms_form_ce, SL("_position"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_forms_form_ce, SL("_entity"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_forms_form_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_forms_form_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_forms_form_ce, SL("_elements"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_forms_form_ce, SL("_elementsIndexed"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_forms_form_ce, SL("_messages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_forms_form_ce, SL("_action"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_forms_form_ce, SL("_validation"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_forms_form_ce TSRMLS_CC, 1, spl_ce_Countable);
	zend_class_implements(phalcon_forms_form_ce TSRMLS_CC, 1, zend_ce_iterator);
	return SUCCESS;

}

PHP_METHOD(Phalcon_Forms_Form, setValidation) {

	zval *validation;

	zephir_fetch_params(0, 1, 0, &validation);



	zephir_update_property_this(this_ptr, SL("_validation"), validation TSRMLS_CC);

}

PHP_METHOD(Phalcon_Forms_Form, getValidation) {


	RETURN_MEMBER(this_ptr, "_validation");

}

/**
 * Phalcon\Forms\Form constructor
 *
 * @param object entity
 * @param array userOptions
 */
PHP_METHOD(Phalcon_Forms_Form, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *entity = NULL, *userOptions = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &entity, &userOptions);

	if (!entity) {
		entity = ZEPHIR_GLOBAL(global_null);
	}
	if (!userOptions) {
		userOptions = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(entity) != IS_NULL) {
		if (Z_TYPE_P(entity) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_forms_exception_ce, "The base entity is not valid", "phalcon/forms/form.zep", 65);
			return;
		}
		zephir_update_property_this(this_ptr, SL("_entity"), entity TSRMLS_CC);
	}
	if (Z_TYPE_P(userOptions) == IS_ARRAY) {
		zephir_update_property_this(this_ptr, SL("_options"), userOptions TSRMLS_CC);
	}
	if ((zephir_method_exists_ex(this_ptr, SS("initialize") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", NULL, 0, entity, userOptions);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the form's action
 *
 * @param string action
 * @return Phalcon\Forms\Form
 */
PHP_METHOD(Phalcon_Forms_Form, setAction) {

	zval *action;

	zephir_fetch_params(0, 1, 0, &action);



	zephir_update_property_this(this_ptr, SL("_action"), action TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the form's action
 */
PHP_METHOD(Phalcon_Forms_Form, getAction) {


	RETURN_MEMBER(this_ptr, "_action");

}

/**
 * Sets an option for the form
 *
 * @param string option
 * @param mixed value
 * @return Phalcon\Forms\Form
 */
PHP_METHOD(Phalcon_Forms_Form, setUserOption) {

	zval *option, *value;

	zephir_fetch_params(0, 2, 0, &option, &value);



	zephir_update_property_array(this_ptr, SL("_options"), option, value TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the value of an option if present
 *
 * @param string option
 * @param mixed defaultValue
 * @return mixed
 */
PHP_METHOD(Phalcon_Forms_Form, getUserOption) {

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
 */
PHP_METHOD(Phalcon_Forms_Form, setUserOptions) {

	zval *options_param = NULL;
	zval *options = NULL;

	zephir_fetch_params(0, 1, 0, &options_param);

	options = options_param;



	zephir_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the options for the element
 *
 * @return array
 */
PHP_METHOD(Phalcon_Forms_Form, getUserOptions) {


	RETURN_MEMBER(this_ptr, "_options");

}

/**
 * Sets the entity related to the model
 *
 * @param object entity
 * @return Phalcon\Forms\Form
 */
PHP_METHOD(Phalcon_Forms_Form, setEntity) {

	zval *entity;

	zephir_fetch_params(0, 1, 0, &entity);



	zephir_update_property_this(this_ptr, SL("_entity"), entity TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the entity related to the model
 *
 * @return object
 */
PHP_METHOD(Phalcon_Forms_Form, getEntity) {


	RETURN_MEMBER(this_ptr, "_entity");

}

/**
 * Returns the form elements added to the form
 */
PHP_METHOD(Phalcon_Forms_Form, getElements) {


	RETURN_MEMBER(this_ptr, "_elements");

}

/**
 * Binds data to the entity
 *
 * @param array data
 * @param object entity
 * @param array whitelist
 * @return Phalcon\Forms\Form
 */
PHP_METHOD(Phalcon_Forms_Form, bind) {

	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *data_param = NULL, *entity, *whitelist = NULL, *elements, *filter = NULL, *key = NULL, *value = NULL, *element = NULL, *filters = NULL, *dependencyInjector = NULL, *filteredValue = NULL, *method = NULL, **_2, *_4 = NULL, *_5 = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &data_param, &entity, &whitelist);

	data = data_param;

	ZEPHIR_SEPARATE_PARAM(entity);
	if (!whitelist) {
		whitelist = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(elements);
	zephir_read_property_this(&elements, this_ptr, SL("_elements"), PH_NOISY_CC);
	if (Z_TYPE_P(elements) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_forms_exception_ce, "There are no elements in the form", "phalcon/forms/form.zep", 198);
		return;
	}
	ZEPHIR_INIT_VAR(filter);
	ZVAL_NULL(filter);
	zephir_is_iterable(data, &_1, &_0, 0, 0, "phalcon/forms/form.zep", 255);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_OBS_NVAR(element);
		if (!(zephir_array_isset_fetch(&element, elements, key, 0 TSRMLS_CC))) {
			continue;
		}
		if (Z_TYPE_P(whitelist) == IS_ARRAY) {
			if (!(zephir_fast_in_array(key, whitelist TSRMLS_CC))) {
				continue;
			}
		}
		ZEPHIR_CALL_METHOD(&filters, element, "getfilters", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(filters)) {
			if (Z_TYPE_P(filter) != IS_OBJECT) {
				ZEPHIR_CALL_METHOD(&dependencyInjector, this_ptr, "getdi", &_3, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_STRING(_5, "filter", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_4, dependencyInjector, "getshared", NULL, 0, _5);
				zephir_check_temp_parameter(_5);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(filter, _4);
			}
			ZEPHIR_CALL_METHOD(&filteredValue, filter, "sanitize", NULL, 0, value, filters);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(filteredValue, value);
		}
		ZEPHIR_INIT_NVAR(method);
		ZEPHIR_CONCAT_SV(method, "set", key);
		if ((zephir_method_exists(entity, method TSRMLS_CC)  == SUCCESS)) {
			ZEPHIR_CALL_METHOD_ZVAL(NULL, entity, method, NULL, 0, filteredValue);
			zephir_check_call_status();
			continue;
		}
		zephir_update_property_zval_zval(entity, key, filteredValue TSRMLS_CC);
	}
	zephir_update_property_this(this_ptr, SL("_data"), data TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Validates the form
 *
 * @param array data
 * @param object entity
 * @return boolean
 */
PHP_METHOD(Phalcon_Forms_Form, isValid) {

	zephir_fcall_cache_entry *_10 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL;
	zval *_9 = NULL;
	HashTable *_4, *_7;
	HashPosition _3, _6;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool notFailed;
	zval *data = NULL, *entity = NULL, *elements, *messages, *element = NULL, *validators = NULL, *name = NULL, *preparedValidators = NULL, *filters = NULL, *validator = NULL, *validation = NULL, *elementMessages = NULL, *_0, *_1, *_2 = NULL, **_5, **_8, *_14 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &data, &entity);

	if (!data) {
		ZEPHIR_CPY_WRT(data, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(data);
	}
	if (!entity) {
		entity = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(elements);
	zephir_read_property_this(&elements, this_ptr, SL("_elements"), PH_NOISY_CC);
	if (Z_TYPE_P(elements) != IS_ARRAY) {
		RETURN_MM_BOOL(1);
	}
	if (Z_TYPE_P(data) != IS_ARRAY) {
		ZEPHIR_OBS_NVAR(data);
		zephir_read_property_this(&data, this_ptr, SL("_data"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_entity"), PH_NOISY_CC);
	if (Z_TYPE_P(entity) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "bind", NULL, 0, data, entity);
		zephir_check_call_status();
	} else if (Z_TYPE_P(_0) == IS_OBJECT) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_entity"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "bind", NULL, 0, data, _1);
		zephir_check_call_status();
	}
	if ((zephir_method_exists_ex(this_ptr, SS("beforevalidation") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "beforevalidation", NULL, 0, data, entity);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_2)) {
			RETURN_MM_BOOL(0);
		}
	}
	notFailed = 1;
	ZEPHIR_INIT_VAR(messages);
	array_init(messages);
	zephir_is_iterable(elements, &_4, &_3, 0, 0, "phalcon/forms/form.zep", 370);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(element, _5);
		ZEPHIR_CALL_METHOD(&validators, element, "getvalidators", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(validators) == IS_ARRAY) {
			if (zephir_fast_count_int(validators TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(&name, element, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(preparedValidators);
				array_init(preparedValidators);
				zephir_is_iterable(validators, &_7, &_6, 0, 0, "phalcon/forms/form.zep", 326);
				for (
				  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
				  ; zephir_hash_move_forward_ex(_7, &_6)
				) {
					ZEPHIR_GET_HVALUE(validator, _8);
					ZEPHIR_INIT_NVAR(_9);
					zephir_create_array(_9, 2, 0 TSRMLS_CC);
					zephir_array_fast_append(_9, name);
					zephir_array_fast_append(_9, validator);
					zephir_array_append(&preparedValidators, _9, PH_SEPARATE, "phalcon/forms/form.zep", 323);
				}
				ZEPHIR_CALL_METHOD(&validation, this_ptr, "getvalidation", &_10, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(validation) == IS_OBJECT) {
					if (zephir_instance_of_ev(validation, phalcon_validation_ce TSRMLS_CC)) {
						ZEPHIR_CALL_METHOD(NULL, validation, "setvalidators", NULL, 0, preparedValidators);
						zephir_check_call_status();
					}
				} else {
					ZEPHIR_INIT_NVAR(validation);
					object_init_ex(validation, phalcon_validation_ce);
					ZEPHIR_CALL_METHOD(NULL, validation, "__construct", &_11, 188, preparedValidators);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&filters, element, "getfilters", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(filters) == IS_ARRAY) {
					ZEPHIR_CALL_METHOD(&_2, element, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, validation, "setfilters", &_12, 189, _2, filters);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&elementMessages, validation, "validate", &_13, 190, data, entity);
				zephir_check_call_status();
				if (zephir_fast_count_int(elementMessages TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(&_14, element, "getname", NULL, 0);
					zephir_check_call_status();
					zephir_array_update_zval(&messages, _14, &elementMessages, PH_COPY | PH_SEPARATE);
					notFailed = 0;
				}
			}
		}
	}
	if (!(notFailed)) {
		zephir_update_property_this(this_ptr, SL("_messages"), messages TSRMLS_CC);
	}
	if ((zephir_method_exists_ex(this_ptr, SS("aftervalidation") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "aftervalidation", NULL, 0, messages);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(notFailed);

}

/**
 * Returns the messages generated in the validation
 */
PHP_METHOD(Phalcon_Forms_Form, getMessages) {

	HashTable *_2;
	HashPosition _1;
	zephir_fcall_cache_entry *_0 = NULL, *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *byItemName_param = NULL, *messages, *group, *elementMessages = NULL, **_3;
	zend_bool byItemName;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &byItemName_param);

	if (!byItemName_param) {
		byItemName = 0;
	} else {
		byItemName = zephir_get_boolval(byItemName_param);
	}


	ZEPHIR_OBS_VAR(messages);
	zephir_read_property_this(&messages, this_ptr, SL("_messages"), PH_NOISY_CC);
	if (byItemName) {
		if (Z_TYPE_P(messages) != IS_ARRAY) {
			object_init_ex(return_value, phalcon_validation_message_group_ce);
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", &_0, 173);
			zephir_check_call_status();
			RETURN_MM();
		}
		RETURN_CCTOR(messages);
	}
	ZEPHIR_INIT_VAR(group);
	object_init_ex(group, phalcon_validation_message_group_ce);
	ZEPHIR_CALL_METHOD(NULL, group, "__construct", &_0, 173);
	zephir_check_call_status();
	if (Z_TYPE_P(messages) == IS_ARRAY) {
		zephir_is_iterable(messages, &_2, &_1, 0, 0, "phalcon/forms/form.zep", 407);
		for (
		  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HVALUE(elementMessages, _3);
			ZEPHIR_CALL_METHOD(NULL, group, "appendmessages", &_4, 191, elementMessages);
			zephir_check_call_status();
		}
	}
	RETURN_CCTOR(group);

}

/**
 * Returns the messages generated for a specific element
 *
 * @param string name
 * @return Phalcon\Validation\Message\Group
 */
PHP_METHOD(Phalcon_Forms_Form, getMessagesFor) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name, *messages, *elementMessages, *group;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	messages = zephir_fetch_nproperty_this(this_ptr, SL("_messages"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&elementMessages, messages, name, 1 TSRMLS_CC)) {
		RETURN_CTOR(elementMessages);
	}
	ZEPHIR_INIT_VAR(group);
	object_init_ex(group, phalcon_validation_message_group_ce);
	ZEPHIR_CALL_METHOD(NULL, group, "__construct", NULL, 173);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("_messages"), name, group TSRMLS_CC);
	RETURN_CCTOR(group);

}

/**
 * Check if messages were generated for a specific element
 *
 * @param string name
 * @return boolean
 */
PHP_METHOD(Phalcon_Forms_Form, hasMessagesFor) {

	zval *name, *_0;

	zephir_fetch_params(0, 1, 0, &name);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_messages"), PH_NOISY_CC);
	RETURN_BOOL(zephir_array_isset(_0, name));

}

/**
 * Adds an element to the form
 *
 * @param Phalcon\Forms\ElementInterface element
 * @param string $postion
 * @param bool $type If $type is TRUE, the element wile add before $postion, else is after
 * @return Phalcon\Forms\Form
 */
PHP_METHOD(Phalcon_Forms_Form, add) {

	HashTable *_4;
	HashPosition _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool type, _0;
	zval *postion = NULL;
	zval *element, *postion_param = NULL, *type_param = NULL, *name = NULL, *key = NULL, *value = NULL, *elements, *_1, *_2, **_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &element, &postion_param, &type_param);

	if (!postion_param) {
		ZEPHIR_INIT_VAR(postion);
		ZVAL_EMPTY_STRING(postion);
	} else {
		zephir_get_strval(postion, postion_param);
	}
	if (!type_param) {
		type = 0;
	} else {
		type = zephir_get_boolval(type_param);
	}


	ZEPHIR_CALL_METHOD(&name, element, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, element, "setform", NULL, 0, this_ptr);
	zephir_check_call_status();
	_0 = ZEPHIR_IS_STRING(postion, "");
	if (!(_0)) {
		ZEPHIR_OBS_VAR(_1);
		zephir_read_property_this(&_1, this_ptr, SL("_elements"), PH_NOISY_CC);
		_0 = Z_TYPE_P(_1) != IS_ARRAY;
	}
	if (_0) {
		zephir_update_property_array(this_ptr, SL("_elements"), name, element TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(elements);
		array_init(elements);
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_elements"), PH_NOISY_CC);
		zephir_is_iterable(_2, &_4, &_3, 0, 0, "phalcon/forms/form.zep", 496);
		for (
		  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_4, &_3)
		) {
			ZEPHIR_GET_HMKEY(key, _4, _3);
			ZEPHIR_GET_HVALUE(value, _5);
			if (ZEPHIR_IS_EQUAL(key, postion)) {
				if (type) {
					zephir_array_update_zval(&elements, name, &element, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&elements, key, &value, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_zval(&elements, key, &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&elements, name, &element, PH_COPY | PH_SEPARATE);
				}
			} else {
				zephir_array_update_zval(&elements, key, &value, PH_COPY | PH_SEPARATE);
			}
		}
		zephir_update_property_this(this_ptr, SL("_elements"), elements TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Renders a specific item in the form
 *
 * @param string name
 * @param array attributes
 * @return string
 */
PHP_METHOD(Phalcon_Forms_Form, render) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *attributes = NULL, *element, *_0, *_1;
	zval *name = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &attributes);

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
	if (!attributes) {
		attributes = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(element);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_elements"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&element, _0, name, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, phalcon_forms_exception_ce);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SVS(_2, "Element with ID=", name, " is not part of the form");
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 2, _2);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "phalcon/forms/form.zep", 513 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD(element, "render", NULL, 0, attributes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns an element added to the form by its name
 */
PHP_METHOD(Phalcon_Forms_Form, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *element, *_0, *_1;
	zval *name = NULL, *_2;

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


	ZEPHIR_OBS_VAR(element);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_elements"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&element, _0, name, 0 TSRMLS_CC)) {
		RETURN_CCTOR(element);
	}
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, phalcon_forms_exception_ce);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SVS(_2, "Element with ID=", name, " is not part of the form");
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 2, _2);
	zephir_check_call_status();
	zephir_throw_exception_debug(_1, "phalcon/forms/form.zep", 530 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Generate the label of a element added to the form including HTML
 */
PHP_METHOD(Phalcon_Forms_Form, label) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *attributes = NULL;
	zval *name_param = NULL, *attributes_param = NULL, *element, *_0, *_1;
	zval *name = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &attributes_param);

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
	if (!attributes_param) {
	ZEPHIR_INIT_VAR(attributes);
	array_init(attributes);
	} else {
		zephir_get_arrval(attributes, attributes_param);
	}


	ZEPHIR_OBS_VAR(element);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_elements"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&element, _0, name, 0 TSRMLS_CC)) {
		ZEPHIR_RETURN_CALL_METHOD(element, "label", NULL, 0, attributes);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, phalcon_forms_exception_ce);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SVS(_2, "Element with ID=", name, " is not part of the form");
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 2, _2);
	zephir_check_call_status();
	zephir_throw_exception_debug(_1, "phalcon/forms/form.zep", 544 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Returns a label for an element
 */
PHP_METHOD(Phalcon_Forms_Form, getLabel) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *element, *label = NULL, *_0, *_1;
	zval *name = NULL, *_2;

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


	ZEPHIR_OBS_VAR(element);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_elements"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&element, _0, name, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, phalcon_forms_exception_ce);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SVS(_2, "Element with ID=", name, " is not part of the form");
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 2, _2);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "phalcon/forms/form.zep", 555 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&label, element, "getlabel", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(label))) {
		RETURN_CTOR(name);
	}
	RETURN_CCTOR(label);

}

/**
 * Gets a value from the internal related entity or from the default value
 *
 * @param string name
 * @return mixed
 */
PHP_METHOD(Phalcon_Forms_Form, getValue) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *entity, *method = NULL, *value = NULL, *data;
	zval *name = NULL, *_0 = NULL;

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


	ZEPHIR_OBS_VAR(entity);
	zephir_read_property_this(&entity, this_ptr, SL("_entity"), PH_NOISY_CC);
	if (Z_TYPE_P(entity) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SV(_0, "get", name);
		ZEPHIR_CPY_WRT(method, _0);
		if ((zephir_method_exists(entity, method TSRMLS_CC)  == SUCCESS)) {
			ZEPHIR_RETURN_CALL_METHOD_ZVAL(entity, method, NULL, 0);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_OBS_VAR(value);
		if (zephir_fetch_property_zval(&value, entity, name, PH_SILENT_CC)) {
			RETURN_CCTOR(value);
		}
	}
	ZEPHIR_OBS_VAR(data);
	zephir_read_property_this(&data, this_ptr, SL("_data"), PH_NOISY_CC);
	if (Z_TYPE_P(data) == IS_ARRAY) {
		ZEPHIR_OBS_NVAR(value);
		if (zephir_array_isset_fetch(&value, data, name, 0 TSRMLS_CC)) {
			RETURN_CCTOR(value);
		}
	}
	ZEPHIR_INIT_LNVAR(_0);
	ZEPHIR_CONCAT_SV(_0, "get", name);
	ZEPHIR_CPY_WRT(method, _0);
	if ((zephir_method_exists(this_ptr, method TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, method, NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_NULL();

}

/**
 * Check if the form contains an element
 */
PHP_METHOD(Phalcon_Forms_Form, has) {

	zval *name_param = NULL, *_0;
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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_elements"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, name));

}

/**
 * Removes an element from the form
 */
PHP_METHOD(Phalcon_Forms_Form, remove) {

	zval *name_param = NULL, *elements, *_0;
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


	elements = zephir_fetch_nproperty_this(this_ptr, SL("_elements"), PH_NOISY_CC);
	if (zephir_array_isset(elements, name)) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_elements"), PH_NOISY_CC);
		zephir_array_unset(&_0, name, PH_SEPARATE);
		RETURN_MM_BOOL(1);
	}
	zephir_update_property_this(this_ptr, SL("_elementsIndexed"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	RETURN_MM_BOOL(0);

}

/**
 * Clears every element in the form to its default value
 *
 * @param array fields
 * @return Phalcon\Forms\Form
 */
PHP_METHOD(Phalcon_Forms_Form, clear) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *fields = NULL, *elements, *element = NULL, **_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &fields);

	if (!fields) {
		fields = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(elements);
	zephir_read_property_this(&elements, this_ptr, SL("_elements"), PH_NOISY_CC);
	if (Z_TYPE_P(elements) == IS_ARRAY) {
		zephir_is_iterable(elements, &_1, &_0, 0, 0, "phalcon/forms/form.zep", 678);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(element, _2);
			if (Z_TYPE_P(fields) != IS_ARRAY) {
				ZEPHIR_CALL_METHOD(NULL, element, "clear", NULL, 0);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(&_3, element, "getname", NULL, 0);
				zephir_check_call_status();
				if (zephir_fast_in_array(_3, fields TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(NULL, element, "clear", NULL, 0);
					zephir_check_call_status();
				}
			}
		}
	}
	RETURN_THIS();

}

/**
 * Returns the number of elements in the form
 */
PHP_METHOD(Phalcon_Forms_Form, count) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_elements"), PH_NOISY_CC);
	RETURN_LONG(zephir_fast_count_int(_0 TSRMLS_CC));

}

/**
 * Rewinds the internal iterator
 */
PHP_METHOD(Phalcon_Forms_Form, rewind) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 0);
	zephir_update_property_this(this_ptr, SL("_position"), _0 TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_elements"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "array_values", NULL, 192, _0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_elementsIndexed"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the current element in the iterator
 */
PHP_METHOD(Phalcon_Forms_Form, current) {

	zval *element, *_0, *_1;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_elementsIndexed"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_position"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&element, _0, _1, 1 TSRMLS_CC)) {
		RETURN_CTORW(element);
	}
	RETURN_BOOL(0);

}

/**
 * Returns the current position/key in the iterator
 */
PHP_METHOD(Phalcon_Forms_Form, key) {


	RETURN_MEMBER(this_ptr, "_position");

}

/**
 * Moves the internal iteration pointer to the next position
 */
PHP_METHOD(Phalcon_Forms_Form, next) {


	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("_position") TSRMLS_CC));

}

/**
 * Check if the current element in the iterator is valid
 */
PHP_METHOD(Phalcon_Forms_Form, valid) {

	zval *_0, *_1;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_elementsIndexed"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_position"), PH_NOISY_CC);
	RETURN_BOOL(zephir_array_isset(_0, _1));

}

