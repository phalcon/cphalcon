
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
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/iterator.h"


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

	zval *validation;

	zephir_fetch_params(0, 1, 0, &validation);



	zephir_update_property_this(getThis(), SL("_validation"), validation TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Phalcon_Forms_Form, getValidation) {

	

	RETURN_MEMBER(getThis(), "_validation");

}

/**
 * Phalcon\Forms\Form constructor
 *
 * @param object entity
 * @param array userOptions
 */
PHP_METHOD(Phalcon_Forms_Form, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
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
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_forms_exception_ce, "The base entity is not valid", "phalcon/forms/form.zep", 66);
			return;
		}
		zephir_update_property_this(getThis(), SL("_entity"), entity TSRMLS_CC);
	}
	if (Z_TYPE_P(userOptions) == IS_ARRAY) {
		zephir_update_property_this(getThis(), SL("_options"), userOptions TSRMLS_CC);
	}
	if ((zephir_method_exists_ex(this_ptr, SS("initialize") TSRMLS_CC) == SUCCESS)) {
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
	zval *action = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &action_param);

	if (UNEXPECTED(Z_TYPE_P(action_param) != IS_STRING && Z_TYPE_P(action_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'action' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(action_param) == IS_STRING)) {
		zephir_get_strval(action, action_param);
	} else {
		ZEPHIR_INIT_VAR(action);
		ZVAL_EMPTY_STRING(action);
	}


	zephir_update_property_this(getThis(), SL("_action"), action TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the form's action
 */
PHP_METHOD(Phalcon_Forms_Form, getAction) {

	

	RETURN_MEMBER(getThis(), "_action");

}

/**
 * Sets an option for the form
 *
 * @param string option
 * @param mixed value
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
 */
PHP_METHOD(Phalcon_Forms_Form, getUserOption) {

	zval *option, *defaultValue = NULL, *value = NULL, *_0;

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


	zephir_update_property_this(getThis(), SL("_options"), options TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the options for the element
 */
PHP_METHOD(Phalcon_Forms_Form, getUserOptions) {

	

	RETURN_MEMBER(getThis(), "_options");

}

/**
 * Sets the entity related to the model
 *
 * @param object entity
 */
PHP_METHOD(Phalcon_Forms_Form, setEntity) {

	zval *entity;

	zephir_fetch_params(0, 1, 0, &entity);



	zephir_update_property_this(getThis(), SL("_entity"), entity TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the entity related to the model
 *
 * @return object
 */
PHP_METHOD(Phalcon_Forms_Form, getEntity) {

	

	RETURN_MEMBER(getThis(), "_entity");

}

/**
 * Returns the form elements added to the form
 */
PHP_METHOD(Phalcon_Forms_Form, getElements) {

	

	RETURN_MEMBER(getThis(), "_elements");

}

/**
 * Binds data to the entity
 *
 * @param array data
 * @param object entity
 * @param array whitelist
 */
PHP_METHOD(Phalcon_Forms_Form, bind) {

	HashTable *_2;
	HashPosition _1;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *entity, *whitelist = NULL, *filter = NULL, *key = NULL, *value = NULL, *element = NULL, *filters = NULL, *dependencyInjector = NULL, *filteredValue = NULL, *method = NULL, *_0, **_3, *_4$$4, *_8$$4 = NULL, *_6$$9 = NULL, *_7$$9 = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &data_param, &entity, &whitelist);

	data = data_param;
	ZEPHIR_SEPARATE_PARAM(entity);
	if (!whitelist) {
		whitelist = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_elements"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_forms_exception_ce, "There are no elements in the form", "phalcon/forms/form.zep", 189);
		return;
	}
	ZEPHIR_INIT_VAR(filter);
	ZVAL_NULL(filter);
	zephir_is_iterable(data, &_2, &_1, 0, 0, "phalcon/forms/form.zep", 246);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		ZEPHIR_OBS_NVAR(element);
		_4$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_elements"), PH_NOISY_CC);
		if (!(zephir_array_isset_fetch(&element, _4$$4, key, 0 TSRMLS_CC))) {
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
				ZEPHIR_CALL_METHOD(&dependencyInjector, this_ptr, "getdi", &_5, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_7$$9);
				ZVAL_STRING(_7$$9, "filter", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_6$$9, dependencyInjector, "getshared", NULL, 0, _7$$9);
				zephir_check_temp_parameter(_7$$9);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(filter, _6$$9);
			}
			ZEPHIR_CALL_METHOD(&filteredValue, filter, "sanitize", NULL, 0, value, filters);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(filteredValue, value);
		}
		ZEPHIR_INIT_NVAR(_8$$4);
		zephir_camelize(_8$$4, key, NULL  );
		ZEPHIR_INIT_NVAR(method);
		ZEPHIR_CONCAT_SV(method, "set", _8$$4);
		if ((zephir_method_exists(entity, method TSRMLS_CC)  == SUCCESS)) {
			ZEPHIR_CALL_METHOD_ZVAL(NULL, entity, method, NULL, 0, filteredValue);
			zephir_check_call_status();
			continue;
		}
		zephir_update_property_zval_zval(entity, key, filteredValue TSRMLS_CC);
	}
	zephir_update_property_this(getThis(), SL("_data"), data TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Validates the form
 *
 * @param array data
 * @param object entity
 */
PHP_METHOD(Phalcon_Forms_Form, isValid) {

	zend_object_iterator *_16$$15;
	HashTable *_7, *_11$$11;
	HashPosition _6, _10$$11;
	zend_bool validationStatus = 0, _4, _9$$11;
	zephir_fcall_cache_entry *_13 = NULL, *_14 = NULL, *_19 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, *entity = NULL, *messages = NULL, *element = NULL, *validators = NULL, *name = NULL, *filters = NULL, *validator = NULL, *validation = NULL, *elementMessage = NULL, *_0, *_5, **_8, *_15 = NULL, *_1$$6, *_2$$7, *_3$$8 = NULL, **_12$$11, *_17$$16 = NULL, *_18$$16 = NULL;

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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_elements"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		RETURN_MM_BOOL(1);
	}
	if (Z_TYPE_P(data) != IS_ARRAY) {
		ZEPHIR_OBS_NVAR(data);
		zephir_read_property_this(&data, this_ptr, SL("_data"), PH_NOISY_CC);
	}
	if (Z_TYPE_P(entity) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "bind", NULL, 0, data, entity);
		zephir_check_call_status();
	} else {
		ZEPHIR_OBS_VAR(_1$$6);
		zephir_read_property_this(&_1$$6, this_ptr, SL("_entity"), PH_NOISY_CC);
		if (Z_TYPE_P(_1$$6) == IS_OBJECT) {
			_2$$7 = zephir_fetch_nproperty_this(this_ptr, SL("_entity"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "bind", NULL, 0, data, _2$$7);
			zephir_check_call_status();
		}
	}
	if ((zephir_method_exists_ex(this_ptr, SS("beforevalidation") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(&_3$$8, this_ptr, "beforevalidation", NULL, 0, data, entity);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_3$$8)) {
			RETURN_MM_BOOL(0);
		}
	}
	validationStatus = 1;
	ZEPHIR_CALL_METHOD(&validation, this_ptr, "getvalidation", NULL, 0);
	zephir_check_call_status();
	_4 = Z_TYPE_P(validation) != IS_OBJECT;
	if (!(_4)) {
		_4 = !((zephir_instance_of_ev(validation, phalcon_validationinterface_ce TSRMLS_CC)));
	}
	if (_4) {
		ZEPHIR_INIT_NVAR(validation);
		object_init_ex(validation, phalcon_validation_ce);
		ZEPHIR_CALL_METHOD(NULL, validation, "__construct", NULL, 231);
		zephir_check_call_status();
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_elements"), PH_NOISY_CC);
	zephir_is_iterable(_5, &_7, &_6, 0, 0, "phalcon/forms/form.zep", 338);
	for (
	  ; zend_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
	  ; zend_hash_move_forward_ex(_7, &_6)
	) {
		ZEPHIR_GET_HVALUE(element, _8);
		ZEPHIR_CALL_METHOD(&validators, element, "getvalidators", NULL, 0);
		zephir_check_call_status();
		_9$$11 = Z_TYPE_P(validators) != IS_ARRAY;
		if (!(_9$$11)) {
			_9$$11 = zephir_fast_count_int(validators TSRMLS_CC) == 0;
		}
		if (_9$$11) {
			continue;
		}
		ZEPHIR_CALL_METHOD(&name, element, "getname", NULL, 0);
		zephir_check_call_status();
		zephir_is_iterable(validators, &_11$$11, &_10$$11, 0, 0, "phalcon/forms/form.zep", 325);
		for (
		  ; zend_hash_get_current_data_ex(_11$$11, (void**) &_12$$11, &_10$$11) == SUCCESS
		  ; zend_hash_move_forward_ex(_11$$11, &_10$$11)
		) {
			ZEPHIR_GET_HVALUE(validator, _12$$11);
			ZEPHIR_CALL_METHOD(NULL, validation, "add", &_13, 232, name, validator);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&filters, element, "getfilters", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(filters) == IS_ARRAY) {
			ZEPHIR_CALL_METHOD(NULL, validation, "setfilters", &_14, 233, name, filters);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_METHOD(&messages, validation, "validate", NULL, 234, data, entity);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_15, messages, "count", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(_15)) {
		_16$$15 = zephir_get_iterator(messages TSRMLS_CC);
		_16$$15->funcs->rewind(_16$$15 TSRMLS_CC);
		for (;_16$$15->funcs->valid(_16$$15 TSRMLS_CC) == SUCCESS && !EG(exception); _16$$15->funcs->move_forward(_16$$15 TSRMLS_CC)) {
			{
				zval **ZEPHIR_TMP_ITERATOR_PTR;
				_16$$15->funcs->get_current_data(_16$$15, &ZEPHIR_TMP_ITERATOR_PTR TSRMLS_CC);
				ZEPHIR_CPY_WRT(elementMessage, (*ZEPHIR_TMP_ITERATOR_PTR));
			}
			ZEPHIR_CALL_METHOD(&_18$$16, elementMessage, "getfield", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_17$$16, this_ptr, "get", &_19, 0, _18$$16);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _17$$16, "appendmessage", NULL, 0, elementMessage);
			zephir_check_call_status();
		}
		_16$$15->funcs->dtor(_16$$15 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, messages, "rewind", NULL, 0);
		zephir_check_call_status();
		validationStatus = 0;
	}
	if (!(validationStatus)) {
		zephir_update_property_this(getThis(), SL("_messages"), messages TSRMLS_CC);
	}
	if ((zephir_method_exists_ex(this_ptr, SS("aftervalidation") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "aftervalidation", NULL, 0, messages);
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
 *     // $messages is an array of Group object
 *     $messages = $form->getMessages(true);
 *
 *     foreach ($messages as $message) {
 *         echo $message, "<br>";
 *     }
 *
 *     // Default behavior.
 *     // $messages is a Group object
 *     $messages = $form->getMessages();
 *
 *     foreach ($messages as $message) {
 *         echo $message, "<br>";
 *     }
 * }
 * </code>
 */
PHP_METHOD(Phalcon_Forms_Form, getMessages) {

	zval *_5$$5 = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_6 = NULL, *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *byItemName_param = NULL, *messages = NULL, *messagesByItem = NULL, *elementMessage = NULL, *fieldName = NULL, *_1$$4 = NULL, *_3$$6 = NULL, *_4$$5 = NULL;
	zend_bool byItemName, _0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &byItemName_param);

	if (!byItemName_param) {
		byItemName = 0;
	} else {
		byItemName = zephir_get_boolval(byItemName_param);
	}


	ZEPHIR_OBS_VAR(messages);
	zephir_read_property_this(&messages, this_ptr, SL("_messages"), PH_NOISY_CC);
	_0 = Z_TYPE_P(messages) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(messages, phalcon_validation_message_group_ce TSRMLS_CC);
	}
	if (_0) {
		if (UNEXPECTED(byItemName)) {
			ZEPHIR_INIT_VAR(messagesByItem);
			array_init(messagesByItem);
			ZEPHIR_CALL_METHOD(NULL, messages, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$4, messages, "valid", NULL, 0);
				zephir_check_call_status();
				if (!(zephir_is_true(_1$$4))) {
					break;
				}
				ZEPHIR_CALL_METHOD(&elementMessage, messages, "current", &_2, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&fieldName, elementMessage, "getfield", NULL, 0);
				zephir_check_call_status();
				if (!(zephir_array_isset(messagesByItem, fieldName))) {
					ZEPHIR_INIT_NVAR(_3$$6);
					array_init(_3$$6);
					zephir_array_update_zval(&messagesByItem, fieldName, &_3$$6, PH_COPY | PH_SEPARATE);
				}
				ZEPHIR_INIT_NVAR(_4$$5);
				object_init_ex(_4$$5, phalcon_validation_message_group_ce);
				ZEPHIR_INIT_NVAR(_5$$5);
				zephir_create_array(_5$$5, 1, 0 TSRMLS_CC);
				zephir_array_fast_append(_5$$5, elementMessage);
				ZEPHIR_CALL_METHOD(NULL, _4$$5, "__construct", &_6, 3, _5$$5);
				zephir_check_call_status();
				zephir_array_update_multi(&messagesByItem, &_4$$5 TSRMLS_CC, SL("za"), 2, fieldName);
				ZEPHIR_CALL_METHOD(NULL, messages, "next", &_7, 0);
				zephir_check_call_status();
			}
			RETURN_CCTOR(messagesByItem);
		}
		RETURN_CCTOR(messages);
	}
	object_init_ex(return_value, phalcon_validation_message_group_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", &_6, 3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the messages generated for a specific element
 */
PHP_METHOD(Phalcon_Forms_Form, getMessagesFor) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *_0 = NULL, *_1$$3 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, name);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "get", NULL, 0, name);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(_1$$3, "getmessages", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	object_init_ex(return_value, phalcon_validation_message_group_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check if messages were generated for a specific element
 */
PHP_METHOD(Phalcon_Forms_Form, hasMessagesFor) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *_0 = NULL, *_1 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmessagesfor", NULL, 0, name);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, _0, "count", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_GT_LONG(_1, 0));

}

/**
 * Adds an element to the form
 */
PHP_METHOD(Phalcon_Forms_Form, add) {

	HashTable *_4$$4;
	HashPosition _3$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool type, _0;
	zval *position = NULL;
	zval *element, *position_param = NULL, *type_param = NULL, *name = NULL, *key = NULL, *value = NULL, *elements = NULL, *_1, *_2$$4, **_5$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &element, &position_param, &type_param);

	if (!position_param) {
		ZEPHIR_INIT_VAR(position);
		ZVAL_EMPTY_STRING(position);
	} else {
		zephir_get_strval(position, position_param);
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
	_0 = ZEPHIR_IS_STRING(position, "");
	if (!(_0)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_elements"), PH_NOISY_CC);
		_0 = ZEPHIR_IS_EMPTY(_1);
	}
	if (_0) {
		zephir_update_property_array(this_ptr, SL("_elements"), name, element TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(elements);
		array_init(elements);
		_2$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_elements"), PH_NOISY_CC);
		zephir_is_iterable(_2$$4, &_4$$4, &_3$$4, 0, 0, "phalcon/forms/form.zep", 490);
		for (
		  ; zend_hash_get_current_data_ex(_4$$4, (void**) &_5$$4, &_3$$4) == SUCCESS
		  ; zend_hash_move_forward_ex(_4$$4, &_3$$4)
		) {
			ZEPHIR_GET_HMKEY(key, _4$$4, _3$$4);
			ZEPHIR_GET_HVALUE(value, _5$$4);
			if (ZEPHIR_IS_EQUAL(key, position)) {
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
		zephir_update_property_this(getThis(), SL("_elements"), elements TSRMLS_CC);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *attributes = NULL, *element = NULL, *_0, *_1$$3;
	zval *name = NULL, *_2$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &attributes);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
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
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, phalcon_forms_exception_ce);
		ZEPHIR_INIT_VAR(_2$$3);
		ZEPHIR_CONCAT_SVS(_2$$3, "Element with ID=", name, " is not part of the form");
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 9, _2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "phalcon/forms/form.zep", 506 TSRMLS_CC);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *element = NULL, *_0, *_1;
	zval *name = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
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
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 9, _2);
	zephir_check_call_status();
	zephir_throw_exception_debug(_1, "phalcon/forms/form.zep", 523 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Generate the label of an element added to the form including HTML
 */
PHP_METHOD(Phalcon_Forms_Form, label) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes = NULL;
	zval *name_param = NULL, *attributes_param = NULL, *element = NULL, *_0, *_1;
	zval *name = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &attributes_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
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
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 9, _2);
	zephir_check_call_status();
	zephir_throw_exception_debug(_1, "phalcon/forms/form.zep", 537 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Returns a label for an element
 */
PHP_METHOD(Phalcon_Forms_Form, getLabel) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *element = NULL, *label = NULL, *_0, *_1$$3;
	zval *name = NULL, *_2$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_OBS_VAR(element);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_elements"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&element, _0, name, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, phalcon_forms_exception_ce);
		ZEPHIR_INIT_VAR(_2$$3);
		ZEPHIR_CONCAT_SVS(_2$$3, "Element with ID=", name, " is not part of the form");
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 9, _2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "phalcon/forms/form.zep", 548 TSRMLS_CC);
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
 */
PHP_METHOD(Phalcon_Forms_Form, getValue) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *entity = NULL, *method = NULL, *value = NULL, *data = NULL, *internal = NULL, *forbidden = NULL, *_1, *_0$$4;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_OBS_VAR(entity);
	zephir_read_property_this(&entity, this_ptr, SL("_entity"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(data);
	zephir_read_property_this(&data, this_ptr, SL("_data"), PH_NOISY_CC);
	if ((zephir_method_exists_ex(this_ptr, SS("getcustomvalue") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getcustomvalue", NULL, 0, name, entity, data);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (Z_TYPE_P(entity) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_0$$4);
		zephir_camelize(_0$$4, name, NULL  );
		ZEPHIR_INIT_VAR(method);
		ZEPHIR_CONCAT_SV(method, "get", _0$$4);
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
	if (Z_TYPE_P(data) == IS_ARRAY) {
		ZEPHIR_OBS_NVAR(value);
		if (zephir_array_isset_fetch(&value, data, name, 0 TSRMLS_CC)) {
			RETURN_CCTOR(value);
		}
	}
	ZEPHIR_INIT_VAR(forbidden);
	zephir_create_array(forbidden, 12, 0 TSRMLS_CC);
	zephir_array_update_string(&forbidden, SL("validation"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&forbidden, SL("action"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&forbidden, SL("useroption"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&forbidden, SL("useroptions"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&forbidden, SL("entity"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&forbidden, SL("elements"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&forbidden, SL("messages"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&forbidden, SL("messagesfor"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&forbidden, SL("label"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&forbidden, SL("value"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&forbidden, SL("di"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&forbidden, SL("eventsmanager"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(internal);
	zephir_fast_strtolower(internal, name);
	if (zephir_array_isset(forbidden, internal)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(_1);
	zephir_camelize(_1, name, NULL  );
	ZEPHIR_INIT_NVAR(method);
	ZEPHIR_CONCAT_SV(method, "get", _1);
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

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
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

	zval *name_param = NULL, *_0, *_1$$3;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_elements"), PH_NOISY_CC);
	if (zephir_array_isset(_0, name)) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_elements"), PH_NOISY_CC);
		zephir_array_unset(&_1$$3, name, PH_SEPARATE);
		RETURN_MM_BOOL(1);
	}
	zephir_update_property_this(getThis(), SL("_elementsIndexed"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	RETURN_MM_BOOL(0);

}

/**
 * Clears every element in the form to its default value
 *
 * @param array fields
 */
PHP_METHOD(Phalcon_Forms_Form, clear) {

	HashTable *_1$$5, *_4$$10;
	HashPosition _0$$5, _3$$10;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fields = NULL, *elements = NULL, *element = NULL, *data = NULL, *field = NULL, **_2$$5, **_5$$10, *_6$$13 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &fields);

	if (!fields) {
		fields = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(data);
	zephir_read_property_this(&data, this_ptr, SL("_data"), PH_NOISY_CC);
	if (Z_TYPE_P(fields) == IS_NULL) {
		ZEPHIR_INIT_NVAR(data);
		array_init(data);
	} else {
		if (Z_TYPE_P(fields) == IS_ARRAY) {
			zephir_is_iterable(fields, &_1$$5, &_0$$5, 0, 0, "phalcon/forms/form.zep", 693);
			for (
			  ; zend_hash_get_current_data_ex(_1$$5, (void**) &_2$$5, &_0$$5) == SUCCESS
			  ; zend_hash_move_forward_ex(_1$$5, &_0$$5)
			) {
				ZEPHIR_GET_HVALUE(field, _2$$5);
				if (zephir_array_isset(data, field)) {
					zephir_array_unset(&data, field, PH_SEPARATE);
				}
			}
		} else {
			if (zephir_array_isset(data, field)) {
				zephir_array_unset(&data, field, PH_SEPARATE);
			}
		}
	}
	zephir_update_property_this(getThis(), SL("_data"), data TSRMLS_CC);
	ZEPHIR_OBS_VAR(elements);
	zephir_read_property_this(&elements, this_ptr, SL("_elements"), PH_NOISY_CC);
	if (Z_TYPE_P(elements) == IS_ARRAY) {
		zephir_is_iterable(elements, &_4$$10, &_3$$10, 0, 0, "phalcon/forms/form.zep", 713);
		for (
		  ; zend_hash_get_current_data_ex(_4$$10, (void**) &_5$$10, &_3$$10) == SUCCESS
		  ; zend_hash_move_forward_ex(_4$$10, &_3$$10)
		) {
			ZEPHIR_GET_HVALUE(element, _5$$10);
			if (Z_TYPE_P(fields) != IS_ARRAY) {
				ZEPHIR_CALL_METHOD(NULL, element, "clear", NULL, 0);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(&_6$$13, element, "getname", NULL, 0);
				zephir_check_call_status();
				if (zephir_fast_in_array(_6$$13, fields TSRMLS_CC)) {
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

	zval *_0, *_1, *_2$$3, *_3$$3 = NULL, *_4$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 0);
	zephir_update_property_this(getThis(), SL("_position"), _0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("_elements"), PH_NOISY_CC);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		_2$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_elements"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "array_values", NULL, 235, _2$$3);
		zephir_check_call_status();
		zephir_update_property_this(getThis(), SL("_elementsIndexed"), _3$$3 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(_4$$4);
		array_init(_4$$4);
		zephir_update_property_this(getThis(), SL("_elementsIndexed"), _4$$4 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the current element in the iterator
 */
PHP_METHOD(Phalcon_Forms_Form, current) {

	zval *element = NULL, *_0, *_1;


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

	

	RETURN_MEMBER(getThis(), "_position");

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

zend_object_value zephir_init_properties_Phalcon_Forms_Form(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_2, *_1$$3, *_3$$4;

		ZEPHIR_MM_GROW();
	
	{
		zval zthis       = zval_used_for_init;
		zval *this_ptr   = &zthis;
		zend_object* obj = ecalloc(1, sizeof(zend_object));
		zend_object_value retval;

		zend_object_std_init(obj, class_type TSRMLS_CC);
		object_properties_init(obj, class_type);
		retval.handle   = zend_objects_store_put(obj, (zend_objects_store_dtor_t)zend_objects_destroy_object, zephir_free_object_storage, NULL TSRMLS_CC);
		retval.handlers = zend_get_std_object_handlers();

		Z_TYPE(zthis)   = IS_OBJECT;
		Z_OBJVAL(zthis) = retval;

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_elements"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(getThis(), SL("_elements"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			array_init(_3$$4);
			zephir_update_property_this(getThis(), SL("_options"), _3$$4 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}

