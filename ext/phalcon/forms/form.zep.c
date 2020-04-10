
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
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/iterator.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * This component allows to build forms using an object-oriented interface
 */
ZEPHIR_INIT_CLASS(Phalcon_Forms_Form) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Forms, Form, phalcon, forms_form, phalcon_di_injectable_ce, phalcon_forms_form_method_entry, 0);

	/**
	 * @var Attributes | null
	 */
	zend_declare_property_null(phalcon_forms_form_ce, SL("attributes"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_forms_form_ce, SL("data"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_forms_form_ce, SL("elements"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_forms_form_ce, SL("elementsIndexed"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_forms_form_ce, SL("entity"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_forms_form_ce, SL("messages"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_forms_form_ce, SL("position"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_forms_form_ce, SL("options"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_forms_form_ce, SL("validation"), ZEND_ACC_PROTECTED);

	phalcon_forms_form_ce->create_object = zephir_init_properties_Phalcon_Forms_Form;

	zend_class_implements(phalcon_forms_form_ce, 1, spl_ce_Countable);
	zend_class_implements(phalcon_forms_form_ce, 1, zend_ce_iterator);
	zend_class_implements(phalcon_forms_form_ce, 1, phalcon_html_attributes_attributesinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phalcon_Forms_Form, setValidation) {

	zval *validation, validation_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &validation);



	zephir_update_property_zval(this_ptr, SL("validation"), validation);
	RETURN_THISW();

}

PHP_METHOD(Phalcon_Forms_Form, getValidation) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "validation");

}

/**
 * Phalcon\Forms\Form constructor
 */
PHP_METHOD(Phalcon_Forms_Form, __construct) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval userOptions;
	zval *entity = NULL, entity_sub, *userOptions_param = NULL, __$null, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&entity_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_1);
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


	_0 = Z_TYPE_P(entity) != IS_NULL;
	if (_0) {
		_0 = Z_TYPE_P(entity) != IS_OBJECT;
	}
	if (UNEXPECTED(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_forms_exception_ce, "The base entity is not valid", "phalcon/Forms/Form.zep", 58);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("entity"), entity);
	zephir_update_property_zval(this_ptr, SL("options"), &userOptions);
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, phalcon_html_attributes_ce);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 22);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("attributes"), &_1);
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("initialize")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", NULL, 0, entity, &userOptions);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Adds an element to the form
 */
PHP_METHOD(Phalcon_Forms_Form, add) {

	zend_string *_6$$4;
	zend_ulong _5$$4;
	zval elements;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool type, _0;
	zval position;
	zval *element, element_sub, *position_param = NULL, *type_param = NULL, name, key, value, _1, _2$$4, *_3$$4, _4$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&elements);

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
		zephir_read_property(&_1, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
		_0 = ZEPHIR_IS_EMPTY(&_1);
	}
	if (_0) {
		zephir_update_property_array(this_ptr, SL("elements"), &name, element);
	} else {
		ZEPHIR_INIT_VAR(&elements);
		array_init(&elements);
		zephir_read_property(&_2$$4, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_2$$4, 0, "phalcon/Forms/Form.zep", 133);
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
		zephir_update_property_zval(this_ptr, SL("elements"), &elements);
	}
	RETURN_THIS();

}

/**
 * Binds data to the entity
 *
 * @param object entity
 * @param array whitelist
 */
PHP_METHOD(Phalcon_Forms_Form, bind) {

	zend_bool _6$$4, _13$$11;
	zend_string *_4;
	zend_ulong _3;
	zval method;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *entity, entity_sub, *whitelist = NULL, whitelist_sub, __$null, filter, key, value, element, filters, container, filteredValue, _0, *_1, _2, _5$$4, _10$$4, _11$$4, _8$$8, _9$$8, _12$$11, _16$$11, _17$$11, _14$$15, _15$$15;
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
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&filteredValue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_14$$15);
	ZVAL_UNDEF(&_15$$15);
	ZVAL_UNDEF(&method);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &data_param, &entity, &whitelist);

	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);
	ZEPHIR_SEPARATE_PARAM(entity);
	if (!whitelist) {
		whitelist = &whitelist_sub;
		whitelist = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_forms_exception_ce, "There are no elements in the form", "phalcon/Forms/Form.zep", 151);
		return;
	}
	ZEPHIR_INIT_VAR(&filter);
	ZVAL_NULL(&filter);
	zephir_is_iterable(&data, 0, "phalcon/Forms/Form.zep", 206);
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
			zephir_read_property(&_5$$4, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
			if (!(zephir_array_isset_fetch(&element, &_5$$4, &key, 0))) {
				continue;
			}
			_6$$4 = Z_TYPE_P(whitelist) == IS_ARRAY;
			if (_6$$4) {
				_6$$4 = !(zephir_fast_in_array(&key, whitelist));
			}
			if (_6$$4) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&filters, &element, "getfilters", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&filters)) {
				if (Z_TYPE_P(&filter) != IS_OBJECT) {
					ZEPHIR_CALL_METHOD(&container, this_ptr, "getdi", &_7, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_9$$8);
					ZVAL_STRING(&_9$$8, "filter");
					ZEPHIR_CALL_METHOD(&_8$$8, &container, "getshared", NULL, 0, &_9$$8);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&filter, &_8$$8);
				}
				ZEPHIR_CALL_METHOD(&filteredValue, &filter, "sanitize", NULL, 0, &value, &filters);
				zephir_check_call_status();
			} else {
				ZEPHIR_CPY_WRT(&filteredValue, &value);
			}
			ZEPHIR_INIT_NVAR(&_10$$4);
			zephir_camelize(&_10$$4, &key, NULL  );
			ZEPHIR_INIT_NVAR(&_11$$4);
			ZEPHIR_CONCAT_SV(&_11$$4, "set", &_10$$4);
			zephir_get_strval(&method, &_11$$4);
			if ((zephir_method_exists(entity, &method)  == SUCCESS)) {
				ZEPHIR_CALL_METHOD_ZVAL(NULL, entity, &method, NULL, 0, &filteredValue);
				zephir_check_call_status();
				continue;
			}
			zephir_update_property_zval_zval(entity, &key, &filteredValue);
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
				zephir_read_property(&_12$$11, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
				if (!(zephir_array_isset_fetch(&element, &_12$$11, &key, 0))) {
					continue;
				}
				_13$$11 = Z_TYPE_P(whitelist) == IS_ARRAY;
				if (_13$$11) {
					_13$$11 = !(zephir_fast_in_array(&key, whitelist));
				}
				if (_13$$11) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&filters, &element, "getfilters", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&filters)) {
					if (Z_TYPE_P(&filter) != IS_OBJECT) {
						ZEPHIR_CALL_METHOD(&container, this_ptr, "getdi", &_7, 0);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_15$$15);
						ZVAL_STRING(&_15$$15, "filter");
						ZEPHIR_CALL_METHOD(&_14$$15, &container, "getshared", NULL, 0, &_15$$15);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&filter, &_14$$15);
					}
					ZEPHIR_CALL_METHOD(&filteredValue, &filter, "sanitize", NULL, 0, &value, &filters);
					zephir_check_call_status();
				} else {
					ZEPHIR_CPY_WRT(&filteredValue, &value);
				}
				ZEPHIR_INIT_NVAR(&_16$$11);
				zephir_camelize(&_16$$11, &key, NULL  );
				ZEPHIR_INIT_NVAR(&_17$$11);
				ZEPHIR_CONCAT_SV(&_17$$11, "set", &_16$$11);
				zephir_get_strval(&method, &_17$$11);
				if ((zephir_method_exists(entity, &method)  == SUCCESS)) {
					ZEPHIR_CALL_METHOD_ZVAL(NULL, entity, &method, NULL, 0, &filteredValue);
					zephir_check_call_status();
					continue;
				}
				zephir_update_property_zval_zval(entity, &key, &filteredValue);
			ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	zephir_update_property_zval(this_ptr, SL("data"), &data);
	RETURN_THIS();

}

/**
 * Clears every element in the form to its default value
 *
 * @param array|string|null fields
 */
PHP_METHOD(Phalcon_Forms_Form, clear) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fields = NULL, fields_sub, __$null, elements, element, data, field, _0, *_1$$3, _2$$3, _4$$4, _5$$4, _6$$5, _7$$5, _8$$7, *_9$$6, _10$$6, _11$$10, _12$$10, _13$$13, _14$$13;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&elements);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$13);
	ZVAL_UNDEF(&_14$$13);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &fields);

	if (!fields) {
		fields = &fields_sub;
		ZEPHIR_CPY_WRT(fields, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(fields);
	}


	zephir_read_property(&_0, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&data, &_0);
	zephir_read_property(&_0, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&elements, &_0);
	if (Z_TYPE_P(fields) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&data);
		array_init(&data);
		zephir_is_iterable(&elements, 0, "phalcon/Forms/Form.zep", 237);
		if (Z_TYPE_P(&elements) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&elements), _1$$3)
			{
				ZEPHIR_INIT_NVAR(&element);
				ZVAL_COPY(&element, _1$$3);
				ZEPHIR_CALL_METHOD(&_4$$4, &element, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_5$$4, &element, "getdefault", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_CE_STATIC(NULL, phalcon_tag_ce, "setdefault", &_3, 0, &_4$$4, &_5$$4);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &elements, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_2$$3, &elements, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_2$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&element, &elements, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_6$$5, &element, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_7$$5, &element, "getdefault", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_CE_STATIC(NULL, phalcon_tag_ce, "setdefault", &_3, 0, &_6$$5, &_7$$5);
					zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &elements, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&element);
	} else {
		if (Z_TYPE_P(fields) != IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_8$$7);
			zephir_create_array(&_8$$7, 1, 0);
			zephir_array_fast_append(&_8$$7, fields);
			ZEPHIR_CPY_WRT(fields, &_8$$7);
		}
		zephir_is_iterable(fields, 0, "phalcon/Forms/Form.zep", 254);
		if (Z_TYPE_P(fields) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(fields), _9$$6)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _9$$6);
				if (zephir_array_isset(&data, &field)) {
					zephir_array_unset(&data, &field, PH_SEPARATE);
				}
				ZEPHIR_OBS_NVAR(&element);
				if (zephir_array_isset_fetch(&element, &elements, &field, 0)) {
					ZEPHIR_CALL_METHOD(&_11$$10, &element, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_12$$10, &element, "getdefault", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_CE_STATIC(NULL, phalcon_tag_ce, "setdefault", &_3, 0, &_11$$10, &_12$$10);
					zephir_check_call_status();
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, fields, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_10$$6, fields, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_10$$6)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&field, fields, "current", NULL, 0);
				zephir_check_call_status();
					if (zephir_array_isset(&data, &field)) {
						zephir_array_unset(&data, &field, PH_SEPARATE);
					}
					ZEPHIR_OBS_NVAR(&element);
					if (zephir_array_isset_fetch(&element, &elements, &field, 0)) {
						ZEPHIR_CALL_METHOD(&_13$$13, &element, "getname", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_14$$13, &element, "getdefault", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_CE_STATIC(NULL, phalcon_tag_ce, "setdefault", &_3, 0, &_13$$13, &_14$$13);
						zephir_check_call_status();
					}
				ZEPHIR_CALL_METHOD(NULL, fields, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&field);
	}
	zephir_update_property_zval(this_ptr, SL("data"), &data);
	RETURN_THIS();

}

/**
 * Returns the number of elements in the form
 */
PHP_METHOD(Phalcon_Forms_Form, count) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
	RETURN_LONG(zephir_fast_count_int(&_0));

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


	zephir_read_property(&_0, this_ptr, SL("elementsIndexed"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("position"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&element, &_0, &_1, 1))) {
		RETURN_BOOL(0);
	}
	RETURN_CTORW(&element);

}

/**
 * Returns an element added to the form by its name
 */
PHP_METHOD(Phalcon_Forms_Form, get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, element, _0, _1$$3;
	zval name, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

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
		ZVAL_EMPTY_STRING(&name);
	}


	ZEPHIR_OBS_VAR(&element);
	zephir_read_property(&_0, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!(zephir_array_isset_fetch(&element, &_0, &name, 0)))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_forms_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Element with ID=", &name, " is not part of the form");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 8, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Forms/Form.zep", 293);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&element);

}

/**
 * Returns the form's action
 */
PHP_METHOD(Phalcon_Forms_Form, getAction) {

	zval _3;
	zval _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getattributes", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "action");
	ZEPHIR_CALL_METHOD(&_1, &_0, "get", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_get_strval(&_3, &_1);
	RETURN_CTOR(&_3);

}

/**
 * Get Form attributes collection
 */
PHP_METHOD(Phalcon_Forms_Form, getAttributes) {

	zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("attributes"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(Z_TYPE_P(&_0) == IS_NULL)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_html_attributes_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 22);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("attributes"), &_1$$3);
	}
	RETURN_MM_MEMBER(getThis(), "attributes");

}

/**
 * Returns the form elements added to the form
 */
PHP_METHOD(Phalcon_Forms_Form, getElements) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "elements");

}

/**
 * Returns the entity related to the model
 *
 * @return object
 */
PHP_METHOD(Phalcon_Forms_Form, getEntity) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "entity");

}

/**
 * Returns a label for an element
 */
PHP_METHOD(Phalcon_Forms_Form, getLabel) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	ZEPHIR_OBS_VAR(&element);
	zephir_read_property(&_0, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!(zephir_array_isset_fetch(&element, &_0, &name, 0)))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_forms_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Element with ID=", &name, " is not part of the form");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 8, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Forms/Form.zep", 347);
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
 * Returns the messages generated in the validation.
 *
 * ```php
 * if ($form->isValid($_POST) == false) {
 *     $messages = $form->getMessages();
 *
 *     foreach ($messages as $message) {
 *         echo $message, "<br>";
 *     }
 * }
 * ```
 */
PHP_METHOD(Phalcon_Forms_Form, getMessages) {

	zend_bool _1;
	zval messages, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("messages"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&messages, &_0);
	_1 = Z_TYPE_P(&messages) == IS_OBJECT;
	if (_1) {
		_1 = zephir_instance_of_ev(&messages, phalcon_messages_messages_ce);
	}
	if (!(_1)) {
		object_init_ex(return_value, phalcon_messages_messages_ce);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 9);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(&messages);

}

/**
 * Returns the messages generated for a specific element
 */
PHP_METHOD(Phalcon_Forms_Form, getMessagesFor) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
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
	if (!(zephir_is_true(&_0))) {
		object_init_ex(return_value, phalcon_messages_messages_ce);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 9);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "get", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_1, "getmessages", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the value of an option if present
 */
PHP_METHOD(Phalcon_Forms_Form, getUserOption) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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


	zephir_read_property(&_0, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&value, &_0, &option, 1))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	RETURN_CTOR(&value);

}

/**
 * Returns the options for the element
 */
PHP_METHOD(Phalcon_Forms_Form, getUserOptions) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "options");

}

/**
 * Gets a value from the internal related entity or from the default value
 */
PHP_METHOD(Phalcon_Forms_Form, getValue) {

	zval forbidden;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, __$true, entity, value, data, internalEntity, element, _0, _3, _4, _5, _1$$4, _2$$4;
	zval name, method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&method);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&entity);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&internalEntity);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&forbidden);

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
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_read_property(&_0, this_ptr, SL("entity"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&entity, &_0);
	zephir_read_property(&_0, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&data, &_0);
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("getcustomvalue")) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getcustomvalue", NULL, 0, &name, &entity, &data);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (Z_TYPE_P(&entity) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_camelize(&_1$$4, &name, NULL  );
		ZEPHIR_INIT_VAR(&_2$$4);
		ZEPHIR_CONCAT_SV(&_2$$4, "get", &_1$$4);
		zephir_get_strval(&method, &_2$$4);
		if ((zephir_method_exists(&entity, &method)  == SUCCESS)) {
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
		if (zephir_array_isset_fetch(&value, &data, &name, 0)) {
			RETURN_CCTOR(&value);
		}
	}
	ZEPHIR_INIT_VAR(&forbidden);
	zephir_create_array(&forbidden, 13, 0);
	zephir_array_update_string(&forbidden, SL("attributes"), &__$true, PH_COPY | PH_SEPARATE);
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
	ZEPHIR_INIT_VAR(&internalEntity);
	zephir_fast_strtolower(&internalEntity, &name);
	if (zephir_array_isset(&forbidden, &internalEntity)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_3);
	zephir_camelize(&_3, &name, NULL  );
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_SV(&_4, "get", &_3);
	zephir_get_strval(&method, &_4);
	if ((zephir_method_exists(this_ptr, &method)  == SUCCESS)) {
		ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, &method, NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_CE_STATIC(&_5, phalcon_tag_ce, "hasvalue", &_6, 0, &name);
	zephir_check_call_status();
	if (zephir_is_true(&_5)) {
		ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_tag_ce, "getvalue", &_7, 0, &name);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(&element);
	zephir_read_property(&_0, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&element, &_0, &name, 0)) {
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

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
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_read_property(&_0, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &name));

}

/**
 * Check if messages were generated for a specific element
 */
PHP_METHOD(Phalcon_Forms_Form, hasMessagesFor) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
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
 * Validates the form
 *
 * @param array data
 * @param object entity
 */
PHP_METHOD(Phalcon_Forms_Form, isValid) {

	zend_object_iterator *_16$$21;
	zend_bool validationStatus = 0, _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL, *_12 = NULL, *_19 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, data_sub, *entity = NULL, entity_sub, __$null, messages, element, validators, name, filters, validator, validation, elementMessage, _0, _6, *_7, _8, _15, _1$$4, _2$$6, _3$$7, _4$$8, *_9$$11, _10$$11, *_13$$16, _14$$16, _17$$22, _18$$22;
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
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_14$$16);
	ZVAL_UNDEF(&_17$$22);
	ZVAL_UNDEF(&_18$$22);

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


	zephir_read_property(&_0, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		RETURN_MM_BOOL(1);
	}
	if (Z_TYPE_P(data) != IS_ARRAY) {
		zephir_read_property(&_1$$4, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(data, &_1$$4);
	}
	if (Z_TYPE_P(entity) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "bind", NULL, 0, data, entity);
		zephir_check_call_status();
	} else {
		ZEPHIR_OBS_VAR(&_2$$6);
		zephir_read_property(&_2$$6, this_ptr, SL("entity"), PH_NOISY_CC);
		if (Z_TYPE_P(&_2$$6) == IS_OBJECT) {
			zephir_read_property(&_3$$7, this_ptr, SL("entity"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "bind", NULL, 0, data, &_3$$7);
			zephir_check_call_status();
		}
	}
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("beforevalidation")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(&_4$$8, this_ptr, "beforevalidation", NULL, 0, data, entity);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_4$$8)) {
			RETURN_MM_BOOL(0);
		}
	}
	validationStatus = 1;
	ZEPHIR_CALL_METHOD(&validation, this_ptr, "getvalidation", NULL, 0);
	zephir_check_call_status();
	_5 = Z_TYPE_P(&validation) != IS_OBJECT;
	if (!(_5)) {
		_5 = !((zephir_instance_of_ev(&validation, phalcon_validation_validationinterface_ce)));
	}
	if (_5) {
		ZEPHIR_INIT_NVAR(&validation);
		object_init_ex(&validation, phalcon_validation_ce);
		ZEPHIR_CALL_METHOD(NULL, &validation, "__construct", NULL, 263);
		zephir_check_call_status();
	}
	zephir_read_property(&_6, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_6, 0, "phalcon/Forms/Form.zep", 622);
	if (Z_TYPE_P(&_6) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_6), _7)
		{
			ZEPHIR_INIT_NVAR(&element);
			ZVAL_COPY(&element, _7);
			ZEPHIR_CALL_METHOD(&validators, &element, "getvalidators", NULL, 0);
			zephir_check_call_status();
			if (zephir_fast_count_int(&validators) == 0) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&name, &element, "getname", NULL, 0);
			zephir_check_call_status();
			zephir_is_iterable(&validators, 0, "phalcon/Forms/Form.zep", 609);
			if (Z_TYPE_P(&validators) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&validators), _9$$11)
				{
					ZEPHIR_INIT_NVAR(&validator);
					ZVAL_COPY(&validator, _9$$11);
					ZEPHIR_CALL_METHOD(NULL, &validation, "add", &_11, 264, &name, &validator);
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
						ZEPHIR_CALL_METHOD(NULL, &validation, "add", &_11, 264, &name, &validator);
						zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &validators, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&validator);
			ZEPHIR_CALL_METHOD(&filters, &element, "getfilters", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&filters) == IS_ARRAY) {
				ZEPHIR_CALL_METHOD(NULL, &validation, "setfilters", &_12, 265, &name, &filters);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_6, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_8, &_6, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_8)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&element, &_6, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&validators, &element, "getvalidators", NULL, 0);
				zephir_check_call_status();
				if (zephir_fast_count_int(&validators) == 0) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&name, &element, "getname", NULL, 0);
				zephir_check_call_status();
				zephir_is_iterable(&validators, 0, "phalcon/Forms/Form.zep", 609);
				if (Z_TYPE_P(&validators) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&validators), _13$$16)
					{
						ZEPHIR_INIT_NVAR(&validator);
						ZVAL_COPY(&validator, _13$$16);
						ZEPHIR_CALL_METHOD(NULL, &validation, "add", &_11, 264, &name, &validator);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &validators, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_14$$16, &validators, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_14$$16)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&validator, &validators, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_CALL_METHOD(NULL, &validation, "add", &_11, 264, &name, &validator);
							zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &validators, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&validator);
				ZEPHIR_CALL_METHOD(&filters, &element, "getfilters", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&filters) == IS_ARRAY) {
					ZEPHIR_CALL_METHOD(NULL, &validation, "setfilters", &_12, 265, &name, &filters);
					zephir_check_call_status();
				}
			ZEPHIR_CALL_METHOD(NULL, &_6, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&element);
	ZEPHIR_CALL_METHOD(&messages, &validation, "validate", NULL, 266, data, entity);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_15, &messages, "count", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_15)) {
		_16$$21 = zephir_get_iterator(&messages);
		_16$$21->funcs->rewind(_16$$21);
		for (;_16$$21->funcs->valid(_16$$21) == SUCCESS && !EG(exception); _16$$21->funcs->move_forward(_16$$21)) {
			{
				ZEPHIR_ITERATOR_COPY(&elementMessage, _16$$21);
			}
			ZEPHIR_CALL_METHOD(&_18$$22, &elementMessage, "getfield", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_17$$22, this_ptr, "get", &_19, 0, &_18$$22);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_17$$22, "appendmessage", NULL, 0, &elementMessage);
			zephir_check_call_status();
		}
		zend_iterator_dtor(_16$$21);
		ZEPHIR_CALL_METHOD(NULL, &messages, "rewind", NULL, 0);
		zephir_check_call_status();
		validationStatus = 0;
	}
	if (!(validationStatus)) {
		zephir_update_property_zval(this_ptr, SL("messages"), &messages);
	}
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("aftervalidation")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "aftervalidation", NULL, 0, &messages);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(validationStatus);

}

/**
 * Returns the current position/key in the iterator
 */
PHP_METHOD(Phalcon_Forms_Form, key) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "position");

}

/**
 * Generate the label of an element added to the form including HTML
 */
PHP_METHOD(Phalcon_Forms_Form, label) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
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
	zephir_read_property(&_0, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!(zephir_array_isset_fetch(&element, &_0, &name, 0)))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_forms_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Element with ID=", &name, " is not part of the form");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 8, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Forms/Form.zep", 672);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD(&element, "label", NULL, 0, &attributes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Moves the internal iteration pointer to the next position
 */
PHP_METHOD(Phalcon_Forms_Form, next) {

	zval *this_ptr = getThis();


	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("position")));

}

/**
 * Renders a specific item in the form
 */
PHP_METHOD(Phalcon_Forms_Form, render) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
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
	zephir_read_property(&_0, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!(zephir_array_isset_fetch(&element, &_0, &name, 0)))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_forms_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Element with ID=", &name, " is not part of the form");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 8, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Forms/Form.zep", 696);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD(&element, "render", NULL, 0, &attributes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Removes an element from the form
 */
PHP_METHOD(Phalcon_Forms_Form, remove) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_read_property(&_0, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &name)) {
		zephir_read_property(&_1$$3, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&_1$$3, &name, PH_SEPARATE);
		RETURN_MM_BOOL(1);
	}
	zephir_update_property_zval(this_ptr, SL("elementsIndexed"), &__$null);
	RETURN_MM_BOOL(0);

}

/**
 * Rewinds the internal iterator
 */
PHP_METHOD(Phalcon_Forms_Form, rewind) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval(this_ptr, SL("position"), &_0);
	zephir_read_property(&_0, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_1, "array_values", NULL, 12, &_0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("elementsIndexed"), &_1);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the form's action
 *
 * @return Form
 */
PHP_METHOD(Phalcon_Forms_Form, setAction) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *action_param = NULL, _0, _1;
	zval action;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&action);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &action_param);

	if (UNEXPECTED(Z_TYPE_P(action_param) != IS_STRING && Z_TYPE_P(action_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'action' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(action_param) == IS_STRING)) {
		zephir_get_strval(&action, action_param);
	} else {
		ZEPHIR_INIT_VAR(&action);
		ZVAL_EMPTY_STRING(&action);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getattributes", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "action");
	ZEPHIR_CALL_METHOD(NULL, &_0, "set", NULL, 0, &_1, &action);
	zephir_check_call_status();
	RETURN_THIS();

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

	zephir_fetch_params_without_memory_grow(1, 0, &entity);



	zephir_update_property_zval(this_ptr, SL("entity"), entity);
	RETURN_THISW();

}

/**
 * Set form attributes collection
 */
PHP_METHOD(Phalcon_Forms_Form, setAttributes) {

	zval *attributes, attributes_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &attributes);



	zephir_update_property_zval(this_ptr, SL("attributes"), attributes);
	RETURN_THISW();

}

/**
 * Sets an option for the form
 */
PHP_METHOD(Phalcon_Forms_Form, setUserOption) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *option_param = NULL, *value, value_sub;
	zval option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &option_param, &value);

	zephir_get_strval(&option, option_param);


	zephir_update_property_array(this_ptr, SL("options"), &option, value);
	RETURN_THIS();

}

/**
 * Sets options for the element
 */
PHP_METHOD(Phalcon_Forms_Form, setUserOptions) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);


	zephir_update_property_zval(this_ptr, SL("options"), &options);
	RETURN_THIS();

}

/**
 * Check if the current element in the iterator is valid
 */
PHP_METHOD(Phalcon_Forms_Form, valid) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("elementsIndexed"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("position"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset(&_0, &_1));

}

zend_object *zephir_init_properties_Phalcon_Forms_Form(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("elements"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

