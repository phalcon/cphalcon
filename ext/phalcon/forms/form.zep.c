
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/string.h"


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

	phalcon_forms_form_ce->create_object = zephir_init_properties_Phalcon_Forms_Form;

	zend_class_implements(phalcon_forms_form_ce TSRMLS_CC, 1, spl_ce_Countable);
	zend_class_implements(phalcon_forms_form_ce TSRMLS_CC, 1, zend_ce_iterator);
	return SUCCESS;

}

PHP_METHOD(Phalcon_Forms_Form, setValidation) {

	zval *validation, validation_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&validation_sub);

	zephir_fetch_params(0, 1, 0, &validation);



	zephir_update_property_zval(this_ptr, SL("_validation"), validation);

}

PHP_METHOD(Phalcon_Forms_Form, getValidation) {

	ZEPHIR_INIT_THIS();


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
	zval *entity = NULL, entity_sub, *userOptions = NULL, userOptions_sub, __$null;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&entity_sub);
	ZVAL_UNDEF(&userOptions_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &entity, &userOptions);

	if (!entity) {
		entity = &entity_sub;
		entity = &__$null;
	}
	if (!userOptions) {
		userOptions = &userOptions_sub;
		userOptions = &__$null;
	}


	if (Z_TYPE_P(entity) != IS_NULL) {
		if (Z_TYPE_P(entity) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_forms_exception_ce, "The base entity is not valid", "phalcon/forms/form.zep", 65);
			return;
		}
		zephir_update_property_zval(this_ptr, SL("_entity"), entity);
	}
	if (Z_TYPE_P(userOptions) == IS_ARRAY) {
		zephir_update_property_zval(this_ptr, SL("_options"), userOptions);
	}
	if ((zephir_method_exists_ex(this_ptr, SL("initialize") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", NULL, 0, entity, userOptions);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the form's action
 */
PHP_METHOD(Phalcon_Forms_Form, setAction) {

	zval *action_param = NULL;
	zval action;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&action);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &action_param);

	if (unlikely(Z_TYPE_P(action_param) != IS_STRING && Z_TYPE_P(action_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'action' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(action_param) == IS_STRING)) {
		zephir_get_strval(&action, action_param);
	} else {
		ZEPHIR_INIT_VAR(&action);
		ZVAL_EMPTY_STRING(&action);
	}


	zephir_update_property_zval(this_ptr, SL("_action"), &action);
	RETURN_THIS();

}

/**
 * Returns the form's action
 */
PHP_METHOD(Phalcon_Forms_Form, getAction) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_action");

}

/**
 * Sets an option for the form
 *
 * @param string option
 * @param mixed value
 */
PHP_METHOD(Phalcon_Forms_Form, setUserOption) {

	zval *option, option_sub, *value, value_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&option_sub);
	ZVAL_UNDEF(&value_sub);

	zephir_fetch_params(0, 2, 0, &option, &value);



	zephir_update_property_array(this_ptr, SL("_options"), option, value TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the value of an option if present
 *
 * @param string option
 * @param mixed defaultValue
 */
PHP_METHOD(Phalcon_Forms_Form, getUserOption) {

	zval *option, option_sub, *defaultValue = NULL, defaultValue_sub, __$null, value, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&option_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 1, &option, &defaultValue);

	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("_options"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&value, &_0, option, 1 TSRMLS_CC)) {
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
	zval options;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	ZEPHIR_OBS_VAR_ONCE(&options);
	ZVAL_COPY(&options, options_param);


	zephir_update_property_zval(this_ptr, SL("_options"), &options);
	RETURN_THIS();

}

/**
 * Returns the options for the element
 */
PHP_METHOD(Phalcon_Forms_Form, getUserOptions) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_options");

}

/**
 * Sets the entity related to the model
 *
 * @param object entity
 */
PHP_METHOD(Phalcon_Forms_Form, setEntity) {

	zval *entity, entity_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&entity_sub);

	zephir_fetch_params(0, 1, 0, &entity);



	zephir_update_property_zval(this_ptr, SL("_entity"), entity);
	RETURN_THISW();

}

/**
 * Returns the entity related to the model
 *
 * @return object
 */
PHP_METHOD(Phalcon_Forms_Form, getEntity) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_entity");

}

/**
 * Returns the form elements added to the form
 */
PHP_METHOD(Phalcon_Forms_Form, getElements) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_elements");

}

/**
 * Binds data to the entity
 *
 * @param array data
 * @param object entity
 * @param array whitelist
 */
PHP_METHOD(Phalcon_Forms_Form, bind) {

	zend_string *_3;
	zend_ulong _2;
	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *entity, entity_sub, *whitelist = NULL, whitelist_sub, __$null, filter, key, value, element, filters, dependencyInjector, filteredValue, method, _0, *_1, _4$$4, _8$$4, _6$$9, _7$$9;
	zval data;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&entity_sub);
	ZVAL_UNDEF(&whitelist_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&filteredValue);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_7$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &data_param, &entity, &whitelist);

	ZEPHIR_OBS_VAR_ONCE(&data);
	ZVAL_COPY(&data, data_param);
	ZEPHIR_SEPARATE_PARAM(entity);
	if (!whitelist) {
		whitelist = &whitelist_sub;
		whitelist = &__$null;
	}


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("_elements"), PH_NOISY_CC);
	if (Z_TYPE_P(&_0) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_forms_exception_ce, "There are no elements in the form", "phalcon/forms/form.zep", 188);
		return;
	}
	ZEPHIR_INIT_VAR(&filter);
	ZVAL_NULL(&filter);
	zephir_is_iterable(&data, 0, "phalcon/forms/form.zep", 245);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&key, _3);
		} else {
			ZVAL_LONG(&key, _2);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _1);
		ZEPHIR_OBS_NVAR(&element);
		zephir_read_property(&_4$$4, this_ptr, SL("_elements"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_array_isset_fetch(&element, &_4$$4, &key, 0 TSRMLS_CC))) {
			continue;
		}
		if (Z_TYPE_P(whitelist) == IS_ARRAY) {
			if (!(zephir_fast_in_array(&key, whitelist TSRMLS_CC))) {
				continue;
			}
		}
		ZEPHIR_CALL_METHOD(&filters, &element, "getfilters", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&filters)) {
			if (Z_TYPE_P(&filter) != IS_OBJECT) {
				ZEPHIR_CALL_METHOD(&dependencyInjector, this_ptr, "getdi", &_5, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_7$$9);
				ZVAL_STRING(&_7$$9, "filter");
				ZEPHIR_CALL_METHOD(&_6$$9, &dependencyInjector, "getshared", NULL, 0, &_7$$9);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&filter, &_6$$9);
			}
			ZEPHIR_CALL_METHOD(&filteredValue, &filter, "sanitize", NULL, 0, &value, &filters);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(&filteredValue, &value);
		}
		ZEPHIR_INIT_NVAR(&_8$$4);
		zephir_camelize(&_8$$4, &key, NULL  );
		ZEPHIR_INIT_NVAR(&method);
		ZEPHIR_CONCAT_SV(&method, "set", &_8$$4);
		if ((zephir_method_exists(entity, &method TSRMLS_CC)  == SUCCESS)) {
			ZEPHIR_CALL_METHOD_ZVAL(NULL, entity, &method, NULL, 0, &filteredValue);
			zephir_check_call_status();
			continue;
		}
		zephir_update_property_zval_zval(entity, &key, &filteredValue TSRMLS_CC);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	zephir_update_property_zval(this_ptr, SL("_data"), &data);
	RETURN_THIS();

}

/**
 * Validates the form
 *
 * @param array data
 * @param object entity
 */
PHP_METHOD(Phalcon_Forms_Form, isValid) {

	zval _8$$13;
	zend_bool notFailed = 0;
	zephir_fcall_cache_entry *_1 = NULL, *_9 = NULL, *_10 = NULL, *_11 = NULL, *_12 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, data_sub, *entity = NULL, entity_sub, __$null, messages, element, validators, name, preparedValidators, filters, validator, validation, elementMessages, _0, _5, *_6, _2$$6, _3$$7, _4$$8, *_7$$10;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&entity_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&validators);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&preparedValidators);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&validator);
	ZVAL_UNDEF(&validation);
	ZVAL_UNDEF(&elementMessages);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_8$$13);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &data, &entity);

	if (!data) {
		data = &data_sub;
		ZEPHIR_CPY_WRT(data, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(data);
	}
	if (!entity) {
		entity = &entity_sub;
		entity = &__$null;
	}


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("_elements"), PH_NOISY_CC);
	if (Z_TYPE_P(&_0) != IS_ARRAY) {
		RETURN_MM_BOOL(1);
	}
	if (Z_TYPE_P(data) != IS_ARRAY) {
		ZEPHIR_OBS_NVAR(data);
		zephir_read_property(data, this_ptr, SL("_data"), PH_NOISY_CC);
	}
	if (Z_TYPE_P(entity) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "bind", &_1, 0, data, entity);
		zephir_check_call_status();
	} else {
		ZEPHIR_OBS_VAR(&_2$$6);
		zephir_read_property(&_2$$6, this_ptr, SL("_entity"), PH_NOISY_CC);
		if (Z_TYPE_P(&_2$$6) == IS_OBJECT) {
			zephir_read_property(&_3$$7, this_ptr, SL("_entity"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "bind", &_1, 0, data, &_3$$7);
			zephir_check_call_status();
		}
	}
	if ((zephir_method_exists_ex(this_ptr, SL("beforevalidation") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(&_4$$8, this_ptr, "beforevalidation", NULL, 0, data, entity);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_4$$8)) {
			RETURN_MM_BOOL(0);
		}
	}
	notFailed = 1;
	ZEPHIR_INIT_VAR(&messages);
	array_init(&messages);
	zephir_read_property(&_5, this_ptr, SL("_elements"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_5, 0, "phalcon/forms/form.zep", 358);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_5), _6)
	{
		ZEPHIR_INIT_NVAR(&element);
		ZVAL_COPY(&element, _6);
		ZEPHIR_CALL_METHOD(&validators, &element, "getvalidators", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&validators) != IS_ARRAY) {
			continue;
		}
		if (zephir_fast_count_int(&validators TSRMLS_CC) == 0) {
			continue;
		}
		ZEPHIR_CALL_METHOD(&name, &element, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&preparedValidators);
		array_init(&preparedValidators);
		zephir_is_iterable(&validators, 0, "phalcon/forms/form.zep", 321);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&validators), _7$$10)
		{
			ZEPHIR_INIT_NVAR(&validator);
			ZVAL_COPY(&validator, _7$$10);
			ZEPHIR_INIT_NVAR(&_8$$13);
			zephir_create_array(&_8$$13, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(&_8$$13, &name);
			zephir_array_fast_append(&_8$$13, &validator);
			zephir_array_append(&preparedValidators, &_8$$13, PH_SEPARATE, "phalcon/forms/form.zep", 318);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&validator);
		ZEPHIR_CALL_METHOD(&validation, this_ptr, "getvalidation", &_9, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&validation) == IS_OBJECT) {
			if (zephir_instance_of_ev(&validation, phalcon_validation_ce TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, &validation, "setvalidators", NULL, 0, &preparedValidators);
				zephir_check_call_status();
			}
		} else {
			ZEPHIR_INIT_NVAR(&validation);
			object_init_ex(&validation, phalcon_validation_ce);
			ZEPHIR_CALL_METHOD(NULL, &validation, "__construct", &_10, 219, &preparedValidators);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&filters, &element, "getfilters", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&filters) == IS_ARRAY) {
			ZEPHIR_CALL_METHOD(NULL, &validation, "setfilters", &_11, 220, &name, &filters);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&elementMessages, &validation, "validate", &_12, 221, data, entity);
		zephir_check_call_status();
		if (zephir_fast_count_int(&elementMessages TSRMLS_CC)) {
			zephir_array_update_zval(&messages, &name, &elementMessages, PH_COPY | PH_SEPARATE);
			notFailed = 0;
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&element);
	if (!(notFailed)) {
		zephir_update_property_zval(this_ptr, SL("_messages"), &messages);
	}
	if ((zephir_method_exists_ex(this_ptr, SL("aftervalidation") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "aftervalidation", NULL, 0, &messages);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(notFailed);

}

/**
 * Returns the messages generated in the validation
 */
PHP_METHOD(Phalcon_Forms_Form, getMessages) {

	zephir_fcall_cache_entry *_0 = NULL, *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *byItemName_param = NULL, messages, group, elementMessages, *_1$$5;
	zend_bool byItemName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&group);
	ZVAL_UNDEF(&elementMessages);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &byItemName_param);

	if (!byItemName_param) {
		byItemName = 0;
	} else {
		byItemName = zephir_get_boolval(byItemName_param);
	}


	ZEPHIR_OBS_VAR(&messages);
	zephir_read_property(&messages, this_ptr, SL("_messages"), PH_NOISY_CC);
	if (byItemName) {
		if (Z_TYPE_P(&messages) != IS_ARRAY) {
			object_init_ex(return_value, phalcon_validation_message_group_ce);
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", &_0, 3);
			zephir_check_call_status();
			RETURN_MM();
		}
		RETURN_CCTOR(messages);
	}
	ZEPHIR_INIT_VAR(&group);
	object_init_ex(&group, phalcon_validation_message_group_ce);
	ZEPHIR_CALL_METHOD(NULL, &group, "__construct", &_0, 3);
	zephir_check_call_status();
	if (Z_TYPE_P(&messages) == IS_ARRAY) {
		zephir_is_iterable(&messages, 0, "phalcon/forms/form.zep", 396);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&messages), _1$$5)
		{
			ZEPHIR_INIT_NVAR(&elementMessages);
			ZVAL_COPY(&elementMessages, _1$$5);
			ZEPHIR_CALL_METHOD(NULL, &group, "appendmessages", &_2, 222, &elementMessages);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&elementMessages);
	}
	RETURN_CCTOR(group);

}

/**
 * Returns the messages generated for a specific element
 */
PHP_METHOD(Phalcon_Forms_Form, getMessagesFor) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, messages, elementMessages, group;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&elementMessages);
	ZVAL_UNDEF(&group);

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


	zephir_read_property(&messages, this_ptr, SL("_messages"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&elementMessages, &messages, &name, 1 TSRMLS_CC)) {
		RETURN_CTOR(elementMessages);
	}
	ZEPHIR_INIT_VAR(&group);
	object_init_ex(&group, phalcon_validation_message_group_ce);
	ZEPHIR_CALL_METHOD(NULL, &group, "__construct", NULL, 3);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("_messages"), &name, &group TSRMLS_CC);
	RETURN_CCTOR(group);

}

/**
 * Check if messages were generated for a specific element
 */
PHP_METHOD(Phalcon_Forms_Form, hasMessagesFor) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0, _1;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmessagesfor", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, &_0, "count", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_GT_LONG(&_1, 0));

}

/**
 * Adds an element to the form
 */
PHP_METHOD(Phalcon_Forms_Form, add) {

	zend_string *_5$$4;
	zend_ulong _4$$4;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool type, _0;
	zval postion;
	zval *element, element_sub, *postion_param = NULL, *type_param = NULL, name, key, value, elements, _1, _2$$4, *_3$$4;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&elements);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&postion);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &element, &postion_param, &type_param);

	if (!postion_param) {
		ZEPHIR_INIT_VAR(&postion);
		ZVAL_STRING(&postion, "");
	} else {
		zephir_get_strval(&postion, postion_param);
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
	_0 = ZEPHIR_IS_STRING(&postion, "");
	if (!(_0)) {
		ZEPHIR_OBS_VAR(&_1);
		zephir_read_property(&_1, this_ptr, SL("_elements"), PH_NOISY_CC);
		_0 = Z_TYPE_P(&_1) != IS_ARRAY;
	}
	if (_0) {
		zephir_update_property_array(this_ptr, SL("_elements"), &name, element TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(&elements);
		array_init(&elements);
		zephir_read_property(&_2$$4, this_ptr, SL("_elements"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_2$$4, 0, "phalcon/forms/form.zep", 474);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_2$$4), _4$$4, _5$$4, _3$$4)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_5$$4 != NULL) { 
				ZVAL_STR_COPY(&key, _5$$4);
			} else {
				ZVAL_LONG(&key, _4$$4);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _3$$4);
			if (ZEPHIR_IS_EQUAL(&key, &postion)) {
				if (type) {
					zephir_array_update_zval(&elements, &name, element, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&elements, &key, &value, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_zval(&elements, &key, &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&elements, &name, element, PH_COPY | PH_SEPARATE);
				}
			} else {
				zephir_array_update_zval(&elements, &key, &value, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
		zephir_update_property_zval(this_ptr, SL("_elements"), &elements);
	}
	RETURN_THIS();

}

/**
 * Renders a specific item in the form
 *
 * @param string name
 * @param array attributes
 */
PHP_METHOD(Phalcon_Forms_Form, render) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *attributes = NULL, attributes_sub, __$null, element, _0, _1$$3;
	zval name, _2$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&attributes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &attributes);

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
	if (!attributes) {
		attributes = &attributes_sub;
		attributes = &__$null;
	}


	ZEPHIR_OBS_VAR(&element);
	zephir_read_property(&_0, this_ptr, SL("_elements"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&element, &_0, &name, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_forms_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Element with ID=", &name, " is not part of the form");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 9, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/forms/form.zep", 490 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD(&element, "render", NULL, 0, attributes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns an element added to the form by its name
 */
PHP_METHOD(Phalcon_Forms_Form, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, element, _0, _1;
	zval name, _2;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

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


	ZEPHIR_OBS_VAR(&element);
	zephir_read_property(&_0, this_ptr, SL("_elements"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&element, &_0, &name, 0 TSRMLS_CC)) {
		RETURN_CCTOR(element);
	}
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, phalcon_forms_exception_ce);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SVS(&_2, "Element with ID=", &name, " is not part of the form");
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 9, &_2);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_1, "phalcon/forms/form.zep", 507 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Generate the label of a element added to the form including HTML
 */
PHP_METHOD(Phalcon_Forms_Form, label) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zval *name_param = NULL, *attributes_param = NULL, element, _0, _1;
	zval name, _2;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&attributes);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &attributes_param);

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
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}


	ZEPHIR_OBS_VAR(&element);
	zephir_read_property(&_0, this_ptr, SL("_elements"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&element, &_0, &name, 0 TSRMLS_CC)) {
		ZEPHIR_RETURN_CALL_METHOD(&element, "label", NULL, 0, &attributes);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, phalcon_forms_exception_ce);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SVS(&_2, "Element with ID=", &name, " is not part of the form");
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 9, &_2);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_1, "phalcon/forms/form.zep", 521 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Returns a label for an element
 */
PHP_METHOD(Phalcon_Forms_Form, getLabel) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, element, label, _0, _1$$3;
	zval name, _2$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

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


	ZEPHIR_OBS_VAR(&element);
	zephir_read_property(&_0, this_ptr, SL("_elements"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&element, &_0, &name, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_forms_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Element with ID=", &name, " is not part of the form");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 9, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/forms/form.zep", 532 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&label, &element, "getlabel", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&label))) {
		RETURN_CTOR(name);
	}
	RETURN_CCTOR(label);

}

/**
 * Gets a value from the internal related entity or from the default value
 */
PHP_METHOD(Phalcon_Forms_Form, getValue) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, entity, method, value, data, _1, _0$$4;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&entity);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0$$4);

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


	ZEPHIR_OBS_VAR(&entity);
	zephir_read_property(&entity, this_ptr, SL("_entity"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&data);
	zephir_read_property(&data, this_ptr, SL("_data"), PH_NOISY_CC);
	if ((zephir_method_exists_ex(this_ptr, SL("getcustomvalue") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getcustomvalue", NULL, 0, &name, &entity, &data);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (Z_TYPE_P(&entity) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_0$$4);
		zephir_camelize(&_0$$4, &name, NULL  );
		ZEPHIR_INIT_VAR(&method);
		ZEPHIR_CONCAT_SV(&method, "get", &_0$$4);
		if ((zephir_method_exists(&entity, &method TSRMLS_CC)  == SUCCESS)) {
			ZEPHIR_RETURN_CALL_METHOD_ZVAL(&entity, &method, NULL, 0);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_OBS_VAR(&value);
		if (zephir_fetch_property_zval(&value, &entity, &name, PH_SILENT_CC)) {
			RETURN_CCTOR(value);
		}
	}
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		ZEPHIR_OBS_NVAR(&value);
		if (zephir_array_isset_fetch(&value, &data, &name, 0 TSRMLS_CC)) {
			RETURN_CCTOR(value);
		}
	}
	ZEPHIR_INIT_VAR(&_1);
	zephir_camelize(&_1, &name, NULL  );
	ZEPHIR_INIT_NVAR(&method);
	ZEPHIR_CONCAT_SV(&method, "get", &_1);
	if ((zephir_method_exists(this_ptr, &method TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, &method, NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_NULL();

}

/**
 * Check if the form contains an element
 */
PHP_METHOD(Phalcon_Forms_Form, has) {

	zval *name_param = NULL, _0;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

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


	zephir_read_property(&_0, this_ptr, SL("_elements"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &name));

}

/**
 * Removes an element from the form
 */
PHP_METHOD(Phalcon_Forms_Form, remove) {

	zval *name_param = NULL, __$null, _0, _1$$3;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

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


	zephir_read_property(&_0, this_ptr, SL("_elements"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &name)) {
		zephir_read_property(&_1$$3, this_ptr, SL("_elements"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&_1$$3, &name, PH_SEPARATE);
		RETURN_MM_BOOL(1);
	}
	zephir_update_property_zval(this_ptr, SL("_elementsIndexed"), &__$null);
	RETURN_MM_BOOL(0);

}

/**
 * Clears every element in the form to its default value
 *
 * @param array fields
 */
PHP_METHOD(Phalcon_Forms_Form, clear) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *fields = NULL, fields_sub, __$null, elements, element, *_0$$3, _1$$6;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&elements);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_1$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &fields);

	if (!fields) {
		fields = &fields_sub;
		fields = &__$null;
	}


	ZEPHIR_OBS_VAR(&elements);
	zephir_read_property(&elements, this_ptr, SL("_elements"), PH_NOISY_CC);
	if (Z_TYPE_P(&elements) == IS_ARRAY) {
		zephir_is_iterable(&elements, 0, "phalcon/forms/form.zep", 655);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&elements), _0$$3)
		{
			ZEPHIR_INIT_NVAR(&element);
			ZVAL_COPY(&element, _0$$3);
			if (Z_TYPE_P(fields) != IS_ARRAY) {
				ZEPHIR_CALL_METHOD(NULL, &element, "clear", NULL, 0);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(&_1$$6, &element, "getname", NULL, 0);
				zephir_check_call_status();
				if (zephir_fast_in_array(&_1$$6, fields TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(NULL, &element, "clear", NULL, 0);
					zephir_check_call_status();
				}
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&element);
	}
	RETURN_THIS();

}

/**
 * Returns the number of elements in the form
 */
PHP_METHOD(Phalcon_Forms_Form, count) {

	zval _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("_elements"), PH_NOISY_CC | PH_READONLY);
	RETURN_LONG(zephir_fast_count_int(&_0 TSRMLS_CC));

}

/**
 * Rewinds the internal iterator
 */
PHP_METHOD(Phalcon_Forms_Form, rewind) {

	zval _0, _1;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval(this_ptr, SL("_position"), &_0);
	zephir_read_property(&_0, this_ptr, SL("_elements"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_1, "array_values", NULL, 223, &_0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_elementsIndexed"), &_1);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the current element in the iterator
 */
PHP_METHOD(Phalcon_Forms_Form, current) {

	zval element, _0, _1;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("_elementsIndexed"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("_position"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&element, &_0, &_1, 1 TSRMLS_CC)) {
		RETURN_CTORW(element);
	}
	RETURN_BOOL(0);

}

/**
 * Returns the current position/key in the iterator
 */
PHP_METHOD(Phalcon_Forms_Form, key) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_position");

}

/**
 * Moves the internal iteration pointer to the next position
 */
PHP_METHOD(Phalcon_Forms_Form, next) {

	ZEPHIR_INIT_THIS();


	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("_position") TSRMLS_CC));

}

/**
 * Check if the current element in the iterator is valid
 */
PHP_METHOD(Phalcon_Forms_Form, valid) {

	zval _0, _1;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("_elementsIndexed"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("_position"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset(&_0, &_1));

}

zend_object *zephir_init_properties_Phalcon_Forms_Form(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("_options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("_options"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

