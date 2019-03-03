
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
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/iterator.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
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
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);

	zephir_fetch_params(0, 1, 0, &validation);



	zephir_update_property_zval(this_ptr, SL("_validation"), validation);
	RETURN_THISW();

}

PHP_METHOD(Phalcon_Forms_Form, getValidation) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_validation");

}

/**
 * Phalcon\Forms\Form constructor
 *
 * @param object entity
 */
PHP_METHOD(Phalcon_Forms_Form, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval userOptions;
	zval *entity = NULL, entity_sub, *userOptions_param = NULL, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&entity_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&userOptions);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &entity, &userOptions_param);

	if (!entity) {
		entity = &entity_sub;
		entity = &__$null;
	}
	if (!userOptions_param) {
		ZEPHIR_INIT_VAR(&userOptions);
		array_init(&userOptions);
	} else {
		zephir_get_arrval(&userOptions, userOptions_param);
	}


	if (Z_TYPE_P(entity) != IS_NULL) {
		if (Z_TYPE_P(entity) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_forms_exception_ce, "The base entity is not valid", "phalcon/forms/form.zep", 58);
			return;
		}
		zephir_update_property_zval(this_ptr, SL("_entity"), entity);
	}
	zephir_update_property_zval(this_ptr, SL("_options"), &userOptions);
	if ((zephir_method_exists_ex(this_ptr, SL("initialize") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", NULL, 0, entity, &userOptions);
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
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&action);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &action_param);

	if (UNEXPECTED(Z_TYPE_P(action_param) != IS_STRING && Z_TYPE_P(action_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'action' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(action_param) == IS_STRING)) {
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

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_action");

}

/**
 * Sets an option for the form
 */
PHP_METHOD(Phalcon_Forms_Form, setUserOption) {

	zval *option_param = NULL, *value, value_sub;
	zval option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &option_param, &value);

	zephir_get_strval(&option, option_param);


	zephir_update_property_array(this_ptr, SL("_options"), &option, value);
	RETURN_THIS();

}

/**
 * Returns the value of an option if present
 */
PHP_METHOD(Phalcon_Forms_Form, getUserOption) {

	zval *option_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null, value, _0;
	zval option;
	zval *this_ptr = getThis();

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
		RETURN_CTOR(&value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

/**
 * Sets options for the element
 */
PHP_METHOD(Phalcon_Forms_Form, setUserOptions) {

	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);


	zephir_update_property_zval(this_ptr, SL("_options"), &options);
	RETURN_THIS();

}

/**
 * Returns the options for the element
 */
PHP_METHOD(Phalcon_Forms_Form, getUserOptions) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_options");

}

/**
 * Sets the entity related to the model
 *
 * @param object entity
 */
PHP_METHOD(Phalcon_Forms_Form, setEntity) {

	zval *entity, entity_sub;
	zval *this_ptr = getThis();

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

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_entity");

}

/**
 * Returns the form elements added to the form
 */
PHP_METHOD(Phalcon_Forms_Form, getElements) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_elements");

}

/**
 * Binds data to the entity
 *
 * @param object entity
 * @param array whitelist
 */
PHP_METHOD(Phalcon_Forms_Form, bind) {

	zend_string *_4;
	zend_ulong _3;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *entity, entity_sub, *whitelist = NULL, whitelist_sub, __$null, filter, key, value, element, filters, dependencyInjector, filteredValue, method, _0, *_1, _2, _5$$4, _9$$4, _7$$9, _8$$9, _10$$12, _13$$12, _11$$17, _12$$17;
	zval data;
	zval *this_ptr = getThis();

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
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_10$$12);
	ZVAL_UNDEF(&_13$$12);
	ZVAL_UNDEF(&_11$$17);
	ZVAL_UNDEF(&_12$$17);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &data_param, &entity, &whitelist);

	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);
	ZEPHIR_SEPARATE_PARAM(entity);
	if (!whitelist) {
		whitelist = &whitelist_sub;
		whitelist = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("_elements"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_forms_exception_ce, "There are no elements in the form", "phalcon/forms/form.zep", 172);
		return;
	}
	ZEPHIR_INIT_VAR(&filter);
	ZVAL_NULL(&filter);
	zephir_is_iterable(&data, 0, "phalcon/forms/form.zep", 230);
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&key, _4);
			} else {
				ZVAL_LONG(&key, _3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			ZEPHIR_OBS_NVAR(&element);
			zephir_read_property(&_5$$4, this_ptr, SL("_elements"), PH_NOISY_CC | PH_READONLY);
			if (!(zephir_array_isset_fetch(&element, &_5$$4, &key, 0 TSRMLS_CC))) {
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
					ZEPHIR_CALL_METHOD(&dependencyInjector, this_ptr, "getdi", &_6, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_8$$9);
					ZVAL_STRING(&_8$$9, "filter");
					ZEPHIR_CALL_METHOD(&_7$$9, &dependencyInjector, "getshared", NULL, 0, &_8$$9);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&filter, &_7$$9);
				}
				ZEPHIR_CALL_METHOD(&filteredValue, &filter, "sanitize", NULL, 0, &value, &filters);
				zephir_check_call_status();
			} else {
				ZEPHIR_CPY_WRT(&filteredValue, &value);
			}
			ZEPHIR_INIT_NVAR(&_9$$4);
			zephir_camelize(&_9$$4, &key, NULL  );
			ZEPHIR_INIT_NVAR(&method);
			ZEPHIR_CONCAT_SV(&method, "set", &_9$$4);
			if ((zephir_method_exists(entity, &method TSRMLS_CC)  == SUCCESS)) {
				ZEPHIR_CALL_METHOD_ZVAL(NULL, entity, &method, NULL, 0, &filteredValue);
				zephir_check_call_status();
				continue;
			}
			zephir_update_property_zval_zval(entity, &key, &filteredValue TSRMLS_CC);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &data, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&element);
				zephir_read_property(&_10$$12, this_ptr, SL("_elements"), PH_NOISY_CC | PH_READONLY);
				if (!(zephir_array_isset_fetch(&element, &_10$$12, &key, 0 TSRMLS_CC))) {
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
						ZEPHIR_CALL_METHOD(&dependencyInjector, this_ptr, "getdi", &_6, 0);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_12$$17);
						ZVAL_STRING(&_12$$17, "filter");
						ZEPHIR_CALL_METHOD(&_11$$17, &dependencyInjector, "getshared", NULL, 0, &_12$$17);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&filter, &_11$$17);
					}
					ZEPHIR_CALL_METHOD(&filteredValue, &filter, "sanitize", NULL, 0, &value, &filters);
					zephir_check_call_status();
				} else {
					ZEPHIR_CPY_WRT(&filteredValue, &value);
				}
				ZEPHIR_INIT_NVAR(&_13$$12);
				zephir_camelize(&_13$$12, &key, NULL  );
				ZEPHIR_INIT_NVAR(&method);
				ZEPHIR_CONCAT_SV(&method, "set", &_13$$12);
				if ((zephir_method_exists(entity, &method TSRMLS_CC)  == SUCCESS)) {
					ZEPHIR_CALL_METHOD_ZVAL(NULL, entity, &method, NULL, 0, &filteredValue);
					zephir_check_call_status();
					continue;
				}
				zephir_update_property_zval_zval(entity, &key, &filteredValue TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
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

	zend_object_iterator *_17$$21;
	zend_bool validationStatus = 0, _4, _8$$11, _13$$16;
	zephir_fcall_cache_entry *_11 = NULL, *_12 = NULL, *_20 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, data_sub, *entity = NULL, entity_sub, __$null, messages, element, validators, name, filters, validator, validation, elementMessage, _0, _5, *_6, _7, _16, _1$$6, _2$$7, _3$$8, *_9$$11, _10$$11, *_14$$16, _15$$16, _18$$22, _19$$22;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&entity_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&validators);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&validator);
	ZVAL_UNDEF(&validation);
	ZVAL_UNDEF(&elementMessage);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_3$$8);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_15$$16);
	ZVAL_UNDEF(&_18$$22);
	ZVAL_UNDEF(&_19$$22);

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


	zephir_read_property(&_0, this_ptr, SL("_elements"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		RETURN_MM_BOOL(1);
	}
	if (Z_TYPE_P(data) != IS_ARRAY) {
		ZEPHIR_OBS_NVAR(data);
		zephir_read_property(data, this_ptr, SL("_data"), PH_NOISY_CC);
	}
	if (Z_TYPE_P(entity) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "bind", NULL, 0, data, entity);
		zephir_check_call_status();
	} else {
		ZEPHIR_OBS_VAR(&_1$$6);
		zephir_read_property(&_1$$6, this_ptr, SL("_entity"), PH_NOISY_CC);
		if (Z_TYPE_P(&_1$$6) == IS_OBJECT) {
			zephir_read_property(&_2$$7, this_ptr, SL("_entity"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "bind", NULL, 0, data, &_2$$7);
			zephir_check_call_status();
		}
	}
	if ((zephir_method_exists_ex(this_ptr, SL("beforevalidation") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(&_3$$8, this_ptr, "beforevalidation", NULL, 0, data, entity);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_3$$8)) {
			RETURN_MM_BOOL(0);
		}
	}
	validationStatus = 1;
	ZEPHIR_CALL_METHOD(&validation, this_ptr, "getvalidation", NULL, 0);
	zephir_check_call_status();
	_4 = Z_TYPE_P(&validation) != IS_OBJECT;
	if (!(_4)) {
		_4 = !((zephir_instance_of_ev(&validation, phalcon_validationinterface_ce TSRMLS_CC)));
	}
	if (_4) {
		ZEPHIR_INIT_NVAR(&validation);
		object_init_ex(&validation, phalcon_validation_ce);
		ZEPHIR_CALL_METHOD(NULL, &validation, "__construct", NULL, 194);
		zephir_check_call_status();
	}
	zephir_read_property(&_5, this_ptr, SL("_elements"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_5, 0, "phalcon/forms/form.zep", 322);
	if (Z_TYPE_P(&_5) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_5), _6)
		{
			ZEPHIR_INIT_NVAR(&element);
			ZVAL_COPY(&element, _6);
			ZEPHIR_CALL_METHOD(&validators, &element, "getvalidators", NULL, 0);
			zephir_check_call_status();
			_8$$11 = Z_TYPE_P(&validators) != IS_ARRAY;
			if (!(_8$$11)) {
				_8$$11 = zephir_fast_count_int(&validators TSRMLS_CC) == 0;
			}
			if (_8$$11) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&name, &element, "getname", NULL, 0);
			zephir_check_call_status();
			zephir_is_iterable(&validators, 0, "phalcon/forms/form.zep", 309);
			if (Z_TYPE_P(&validators) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&validators), _9$$11)
				{
					ZEPHIR_INIT_NVAR(&validator);
					ZVAL_COPY(&validator, _9$$11);
					ZEPHIR_CALL_METHOD(NULL, &validation, "add", &_11, 195, &name, &validator);
					zephir_check_call_status();
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &validators, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_10$$11, &validators, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_10$$11)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&validator, &validators, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &validation, "add", &_11, 195, &name, &validator);
						zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &validators, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&validator);
			ZEPHIR_CALL_METHOD(&filters, &element, "getfilters", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&filters) == IS_ARRAY) {
				ZEPHIR_CALL_METHOD(NULL, &validation, "setfilters", &_12, 196, &name, &filters);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_5, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_7, &_5, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&element, &_5, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&validators, &element, "getvalidators", NULL, 0);
				zephir_check_call_status();
				_13$$16 = Z_TYPE_P(&validators) != IS_ARRAY;
				if (!(_13$$16)) {
					_13$$16 = zephir_fast_count_int(&validators TSRMLS_CC) == 0;
				}
				if (_13$$16) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&name, &element, "getname", NULL, 0);
				zephir_check_call_status();
				zephir_is_iterable(&validators, 0, "phalcon/forms/form.zep", 309);
				if (Z_TYPE_P(&validators) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&validators), _14$$16)
					{
						ZEPHIR_INIT_NVAR(&validator);
						ZVAL_COPY(&validator, _14$$16);
						ZEPHIR_CALL_METHOD(NULL, &validation, "add", &_11, 195, &name, &validator);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &validators, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_15$$16, &validators, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_15$$16)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&validator, &validators, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_CALL_METHOD(NULL, &validation, "add", &_11, 195, &name, &validator);
							zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &validators, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&validator);
				ZEPHIR_CALL_METHOD(&filters, &element, "getfilters", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&filters) == IS_ARRAY) {
					ZEPHIR_CALL_METHOD(NULL, &validation, "setfilters", &_12, 196, &name, &filters);
					zephir_check_call_status();
				}
			ZEPHIR_CALL_METHOD(NULL, &_5, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&element);
	ZEPHIR_CALL_METHOD(&messages, &validation, "validate", NULL, 197, data, entity);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_16, &messages, "count", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_16)) {
		_17$$21 = zephir_get_iterator(&messages TSRMLS_CC);
		_17$$21->funcs->rewind(_17$$21 TSRMLS_CC);
		for (;_17$$21->funcs->valid(_17$$21 TSRMLS_CC) == SUCCESS && !EG(exception); _17$$21->funcs->move_forward(_17$$21 TSRMLS_CC)) {
			{
				ZEPHIR_ITERATOR_COPY(&elementMessage, _17$$21);
			}
			ZEPHIR_CALL_METHOD(&_19$$22, &elementMessage, "getfield", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_18$$22, this_ptr, "get", &_20, 0, &_19$$22);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_18$$22, "appendmessage", NULL, 0, &elementMessage);
			zephir_check_call_status();
		}
		zend_iterator_dtor(_17$$21);
		ZEPHIR_CALL_METHOD(NULL, &messages, "rewind", NULL, 0);
		zephir_check_call_status();
		validationStatus = 0;
	}
	if (!(validationStatus)) {
		zephir_update_property_zval(this_ptr, SL("_messages"), &messages);
	}
	if ((zephir_method_exists_ex(this_ptr, SL("aftervalidation") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "aftervalidation", NULL, 0, &messages);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(validationStatus);

}

/**
 * Returns the messages generated in the validation.
 *
 * <code>
 * if ($form->isValid($_POST) == false) {
 *     // Get messages separated by the item name
 *     // $messages is an array of Messages object
 *     $messages = $form->getMessages(true);
 *
 *     foreach ($messages as $message) {
 *         echo $message, "<br>";
 *     }
 *
 *     // Default behavior.
 *     // $messages is a Messages object
 *     $messages = $form->getMessages();
 *
 *     foreach ($messages as $message) {
 *         echo $message, "<br>";
 *     }
 * }
 * </code>
 */
PHP_METHOD(Phalcon_Forms_Form, getMessages) {

	zval _5$$5;
	zephir_fcall_cache_entry *_2 = NULL, *_6 = NULL, *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *byItemName_param = NULL, messages, messagesByItem, elementMessage, fieldName, _1$$4, _3$$6, _4$$5;
	zend_bool byItemName, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&messagesByItem);
	ZVAL_UNDEF(&elementMessage);
	ZVAL_UNDEF(&fieldName);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &byItemName_param);

	if (!byItemName_param) {
		byItemName = 0;
	} else {
		byItemName = zephir_get_boolval(byItemName_param);
	}


	ZEPHIR_OBS_VAR(&messages);
	zephir_read_property(&messages, this_ptr, SL("_messages"), PH_NOISY_CC);
	_0 = Z_TYPE_P(&messages) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(&messages, phalcon_messages_messages_ce TSRMLS_CC);
	}
	if (_0) {
		if (UNEXPECTED(byItemName)) {
			ZEPHIR_INIT_VAR(&messagesByItem);
			array_init(&messagesByItem);
			ZEPHIR_CALL_METHOD(NULL, &messages, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$4, &messages, "valid", NULL, 0);
				zephir_check_call_status();
				if (!(zephir_is_true(&_1$$4))) {
					break;
				}
				ZEPHIR_CALL_METHOD(&elementMessage, &messages, "current", &_2, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&fieldName, &elementMessage, "getfield", NULL, 0);
				zephir_check_call_status();
				if (!(zephir_array_isset(&messagesByItem, &fieldName))) {
					ZEPHIR_INIT_NVAR(&_3$$6);
					array_init(&_3$$6);
					zephir_array_update_zval(&messagesByItem, &fieldName, &_3$$6, PH_COPY | PH_SEPARATE);
				}
				ZEPHIR_INIT_NVAR(&_4$$5);
				object_init_ex(&_4$$5, phalcon_messages_messages_ce);
				ZEPHIR_INIT_NVAR(&_5$$5);
				zephir_create_array(&_5$$5, 1, 0 TSRMLS_CC);
				zephir_array_fast_append(&_5$$5, &elementMessage);
				ZEPHIR_CALL_METHOD(NULL, &_4$$5, "__construct", &_6, 2, &_5$$5);
				zephir_check_call_status();
				zephir_array_update_multi(&messagesByItem, &_4$$5 TSRMLS_CC, SL("za"), 2, &fieldName);
				ZEPHIR_CALL_METHOD(NULL, &messages, "next", &_7, 0);
				zephir_check_call_status();
			}
			RETURN_CCTOR(&messagesByItem);
		}
		RETURN_CCTOR(&messages);
	}
	object_init_ex(return_value, phalcon_messages_messages_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", &_6, 2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the messages generated for a specific element
 */
PHP_METHOD(Phalcon_Forms_Form, getMessagesFor) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0, _1$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, &name);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "get", NULL, 0, &name);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(&_1$$3, "getmessages", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	object_init_ex(return_value, phalcon_messages_messages_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check if messages were generated for a specific element
 */
PHP_METHOD(Phalcon_Forms_Form, hasMessagesFor) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
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

	zend_string *_6$$4;
	zend_ulong _5$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool type, _0;
	zval position;
	zval *element, element_sub, *position_param = NULL, *type_param = NULL, name, key, value, elements, _1, _2$$4, *_3$$4, _4$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&elements);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&position);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &element, &position_param, &type_param);

	if (!position_param) {
		ZEPHIR_INIT_VAR(&position);
		ZVAL_STRING(&position, "");
	} else {
		zephir_get_strval(&position, position_param);
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
	_0 = ZEPHIR_IS_STRING(&position, "");
	if (!(_0)) {
		zephir_read_property(&_1, this_ptr, SL("_elements"), PH_NOISY_CC | PH_READONLY);
		_0 = ZEPHIR_IS_EMPTY(&_1);
	}
	if (_0) {
		zephir_update_property_array(this_ptr, SL("_elements"), &name, element);
	} else {
		ZEPHIR_INIT_VAR(&elements);
		array_init(&elements);
		zephir_read_property(&_2$$4, this_ptr, SL("_elements"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_2$$4, 0, "phalcon/forms/form.zep", 474);
		if (Z_TYPE_P(&_2$$4) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_2$$4), _5$$4, _6$$4, _3$$4)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_6$$4 != NULL) { 
					ZVAL_STR_COPY(&key, _6$$4);
				} else {
					ZVAL_LONG(&key, _5$$4);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _3$$4);
				if (ZEPHIR_IS_EQUAL(&key, &position)) {
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
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_2$$4, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_4$$4, &_2$$4, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_4$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, &_2$$4, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, &_2$$4, "current", NULL, 0);
				zephir_check_call_status();
					if (ZEPHIR_IS_EQUAL(&key, &position)) {
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
				ZEPHIR_CALL_METHOD(NULL, &_2$$4, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
		zephir_update_property_zval(this_ptr, SL("_elements"), &elements);
	}
	RETURN_THIS();

}

/**
 * Renders a specific item in the form
 */
PHP_METHOD(Phalcon_Forms_Form, render) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zval *name_param = NULL, *attributes_param = NULL, element, _0, _1$$3;
	zval name, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&attributes);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &attributes_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
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
	if (!(zephir_array_isset_fetch(&element, &_0, &name, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_forms_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Element with ID=", &name, " is not part of the form");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 4, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/forms/form.zep", 487 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD(&element, "render", NULL, 0, &attributes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns an element added to the form by its name
 */
PHP_METHOD(Phalcon_Forms_Form, get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, element, _0, _1;
	zval name, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	ZEPHIR_OBS_VAR(&element);
	zephir_read_property(&_0, this_ptr, SL("_elements"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&element, &_0, &name, 0 TSRMLS_CC)) {
		RETURN_CCTOR(&element);
	}
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, phalcon_forms_exception_ce);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SVS(&_2, "Element with ID=", &name, " is not part of the form");
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 4, &_2);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_1, "phalcon/forms/form.zep", 504 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Generate the label of an element added to the form including HTML
 */
PHP_METHOD(Phalcon_Forms_Form, label) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zval *name_param = NULL, *attributes_param = NULL, element, _0, _1;
	zval name, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&attributes);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &attributes_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
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
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 4, &_2);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_1, "phalcon/forms/form.zep", 518 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Returns a label for an element
 */
PHP_METHOD(Phalcon_Forms_Form, getLabel) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, element, label, _0, _1$$3;
	zval name, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
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
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 4, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/forms/form.zep", 529 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&label, &element, "getlabel", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&label))) {
		RETURN_CTOR(&name);
	}
	RETURN_CCTOR(&label);

}

/**
 * Gets a value from the internal related entity or from the default value
 */
PHP_METHOD(Phalcon_Forms_Form, getValue) {

	zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, __$true, entity, method, value, data, internal, forbidden, element, _1, _2, _5, _0$$4;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&entity);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&internal);
	ZVAL_UNDEF(&forbidden);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_0$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
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
			RETURN_CCTOR(&value);
		}
	}
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		ZEPHIR_OBS_NVAR(&value);
		if (zephir_array_isset_fetch(&value, &data, &name, 0 TSRMLS_CC)) {
			RETURN_CCTOR(&value);
		}
	}
	ZEPHIR_INIT_VAR(&forbidden);
	zephir_create_array(&forbidden, 12, 0 TSRMLS_CC);
	zephir_array_update_string(&forbidden, SL("validation"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&forbidden, SL("action"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&forbidden, SL("useroption"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&forbidden, SL("useroptions"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&forbidden, SL("entity"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&forbidden, SL("elements"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&forbidden, SL("messages"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&forbidden, SL("messagesfor"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&forbidden, SL("label"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&forbidden, SL("value"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&forbidden, SL("di"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&forbidden, SL("eventsmanager"), &__$true, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&internal);
	zephir_fast_strtolower(&internal, &name);
	if (zephir_array_isset(&forbidden, &internal)) {
		RETURN_MM_NULL();
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
	ZEPHIR_CALL_CE_STATIC(&_2, phalcon_tag_ce, "hasvalue", &_3, 0, &name);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_tag_ce, "getvalue", &_4, 0, &name);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(&element);
	zephir_read_property(&_5, this_ptr, SL("_elements"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&element, &_5, &name, 0 TSRMLS_CC)) {
		ZEPHIR_RETURN_CALL_METHOD(&element, "getdefault", NULL, 0);
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
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
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
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
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
 * @param array|string|null fields
 */
PHP_METHOD(Phalcon_Forms_Form, clear) {

	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fields = NULL, fields_sub, __$null, elements, element, data, field, *_0$$5, _1$$5, *_2$$13, _3$$13, _5$$14, _6$$14, _7$$15, _8$$15, *_9$$17, _10$$17, _11$$18, _12$$19, _13$$19, _14$$20, _15$$21, _16$$21, _17$$23, _18$$23;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&elements);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_3$$13);
	ZVAL_UNDEF(&_5$$14);
	ZVAL_UNDEF(&_6$$14);
	ZVAL_UNDEF(&_7$$15);
	ZVAL_UNDEF(&_8$$15);
	ZVAL_UNDEF(&_10$$17);
	ZVAL_UNDEF(&_11$$18);
	ZVAL_UNDEF(&_12$$19);
	ZVAL_UNDEF(&_13$$19);
	ZVAL_UNDEF(&_14$$20);
	ZVAL_UNDEF(&_15$$21);
	ZVAL_UNDEF(&_16$$21);
	ZVAL_UNDEF(&_17$$23);
	ZVAL_UNDEF(&_18$$23);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &fields);

	if (!fields) {
		fields = &fields_sub;
		fields = &__$null;
	}


	ZEPHIR_OBS_VAR(&data);
	zephir_read_property(&data, this_ptr, SL("_data"), PH_NOISY_CC);
	if (Z_TYPE_P(fields) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&data);
		array_init(&data);
	} else {
		if (Z_TYPE_P(fields) == IS_ARRAY) {
			zephir_is_iterable(fields, 0, "phalcon/forms/form.zep", 688);
			if (Z_TYPE_P(fields) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(fields), _0$$5)
				{
					ZEPHIR_INIT_NVAR(&field);
					ZVAL_COPY(&field, _0$$5);
					if (zephir_array_isset(&data, &field)) {
						zephir_array_unset(&data, &field, PH_SEPARATE);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, fields, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_1$$5, fields, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_1$$5)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&field, fields, "current", NULL, 0);
					zephir_check_call_status();
						if (zephir_array_isset(&data, &field)) {
							zephir_array_unset(&data, &field, PH_SEPARATE);
						}
					ZEPHIR_CALL_METHOD(NULL, fields, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&field);
		} else {
			if (zephir_array_isset(&data, &field)) {
				zephir_array_unset(&data, &field, PH_SEPARATE);
			}
		}
	}
	zephir_update_property_zval(this_ptr, SL("_data"), &data);
	ZEPHIR_OBS_VAR(&elements);
	zephir_read_property(&elements, this_ptr, SL("_elements"), PH_NOISY_CC);
	if (Z_TYPE_P(&elements) == IS_ARRAY) {
		if (Z_TYPE_P(fields) == IS_NULL) {
			zephir_is_iterable(&elements, 0, "phalcon/forms/form.zep", 708);
			if (Z_TYPE_P(&elements) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&elements), _2$$13)
				{
					ZEPHIR_INIT_NVAR(&element);
					ZVAL_COPY(&element, _2$$13);
					ZEPHIR_CALL_METHOD(&_5$$14, &element, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_6$$14, &element, "getdefault", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_CE_STATIC(NULL, phalcon_tag_ce, "setdefault", &_4, 0, &_5$$14, &_6$$14);
					zephir_check_call_status();
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &elements, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_3$$13, &elements, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_3$$13)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&element, &elements, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_7$$15, &element, "getname", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_8$$15, &element, "getdefault", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_CE_STATIC(NULL, phalcon_tag_ce, "setdefault", &_4, 0, &_7$$15, &_8$$15);
						zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &elements, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&element);
		} else {
			if (Z_TYPE_P(fields) == IS_ARRAY) {
				zephir_is_iterable(&elements, 0, "phalcon/forms/form.zep", 715);
				if (Z_TYPE_P(&elements) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&elements), _9$$17)
					{
						ZEPHIR_INIT_NVAR(&element);
						ZVAL_COPY(&element, _9$$17);
						ZEPHIR_CALL_METHOD(&_11$$18, &element, "getname", NULL, 0);
						zephir_check_call_status();
						if (zephir_fast_in_array(&_11$$18, fields TSRMLS_CC)) {
							ZEPHIR_CALL_METHOD(&_12$$19, &element, "getname", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_13$$19, &element, "getdefault", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_CE_STATIC(NULL, phalcon_tag_ce, "setdefault", &_4, 0, &_12$$19, &_13$$19);
							zephir_check_call_status();
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &elements, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_10$$17, &elements, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_10$$17)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&element, &elements, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_14$$20, &element, "getname", NULL, 0);
							zephir_check_call_status();
							if (zephir_fast_in_array(&_14$$20, fields TSRMLS_CC)) {
								ZEPHIR_CALL_METHOD(&_15$$21, &element, "getname", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&_16$$21, &element, "getdefault", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_CE_STATIC(NULL, phalcon_tag_ce, "setdefault", &_4, 0, &_15$$21, &_16$$21);
								zephir_check_call_status();
							}
						ZEPHIR_CALL_METHOD(NULL, &elements, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&element);
			} else {
				ZEPHIR_OBS_NVAR(&element);
				if (zephir_array_isset_fetch(&element, &elements, fields, 0 TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(&_17$$23, &element, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_18$$23, &element, "getdefault", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_CE_STATIC(NULL, phalcon_tag_ce, "setdefault", &_4, 0, &_17$$23, &_18$$23);
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

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("_elements"), PH_NOISY_CC | PH_READONLY);
	RETURN_LONG(zephir_fast_count_int(&_0 TSRMLS_CC));

}

/**
 * Rewinds the internal iterator
 */
PHP_METHOD(Phalcon_Forms_Form, rewind) {

	zval _0, _1, _2$$3, _3$$3, _4$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval(this_ptr, SL("_position"), &_0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, SL("_elements"), PH_NOISY_CC);
	if (Z_TYPE_P(&_1) == IS_ARRAY) {
		zephir_read_property(&_2$$3, this_ptr, SL("_elements"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "array_values", NULL, 118, &_2$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_elementsIndexed"), &_3$$3);
	} else {
		ZEPHIR_INIT_VAR(&_4$$4);
		array_init(&_4$$4);
		zephir_update_property_zval(this_ptr, SL("_elementsIndexed"), &_4$$4);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the current element in the iterator
 */
PHP_METHOD(Phalcon_Forms_Form, current) {

	zval element, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("_elementsIndexed"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("_position"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&element, &_0, &_1, 1 TSRMLS_CC)) {
		RETURN_CTORW(&element);
	}
	RETURN_BOOL(0);

}

/**
 * Returns the current position/key in the iterator
 */
PHP_METHOD(Phalcon_Forms_Form, key) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_position");

}

/**
 * Moves the internal iteration pointer to the next position
 */
PHP_METHOD(Phalcon_Forms_Form, next) {

	zval *this_ptr = getThis();


	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("_position") TSRMLS_CC));

}

/**
 * Check if the current element in the iterator is valid
 */
PHP_METHOD(Phalcon_Forms_Form, valid) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("_elementsIndexed"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("_position"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset(&_0, &_1));

}

zend_object *zephir_init_properties_Phalcon_Forms_Form(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("_elements"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("_elements"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("_options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("_options"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

