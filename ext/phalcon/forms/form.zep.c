
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
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/memory.h"
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
ZEPHIR_INIT_CLASS(Phalcon_Forms_Form)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Forms, Form, phalcon, forms_form, phalcon_di_injectable_ce, phalcon_forms_form_method_entry, 0);

	/**
	 * @var AttributesInterface|null
	 */
	zend_declare_property_null(phalcon_forms_form_ce, SL("attributes"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_forms_form_ce, SL("data"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_forms_form_ce, SL("filteredData"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_forms_form_ce, SL("elements"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_forms_form_ce, SL("elementsIndexed"), ZEND_ACC_PROTECTED);
	/**
	 * @var object|null
	 */
	zend_declare_property_null(phalcon_forms_form_ce, SL("entity"), ZEND_ACC_PROTECTED);
	/**
	 * @var Messages|array|null
	 */
	zend_declare_property_null(phalcon_forms_form_ce, SL("messages"), ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_forms_form_ce, SL("position"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_forms_form_ce, SL("options"), ZEND_ACC_PROTECTED);
	/**
	 * @var TagFactory|null
	 */
	zend_declare_property_null(phalcon_forms_form_ce, SL("tagFactory"), ZEND_ACC_PROTECTED);
	/**
	 * @var ValidationInterface|null
	 */
	zend_declare_property_null(phalcon_forms_form_ce, SL("validation"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_forms_form_ce, SL("whitelist"), ZEND_ACC_PROTECTED);
	phalcon_forms_form_ce->create_object = zephir_init_properties_Phalcon_Forms_Form;

	zend_class_implements(phalcon_forms_form_ce, 1, zend_ce_countable);
	zend_class_implements(phalcon_forms_form_ce, 1, zend_ce_iterator);
	zend_class_implements(phalcon_forms_form_ce, 1, phalcon_html_attributes_attributesinterface_ce);
	return SUCCESS;
}

/**
 * Phalcon\Forms\Form constructor
 */
PHP_METHOD(Phalcon_Forms_Form, __construct)
{
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
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(entity)
		Z_PARAM_ARRAY(userOptions)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_forms_exception_ce, "The base entity is not valid", "phalcon/Forms/Form.zep", 98);
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("entity"), entity);
	zephir_update_property_zval(this_ptr, ZEND_STRL("options"), &userOptions);
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, phalcon_html_attributes_ce);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 23);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("attributes"), &_1);
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("initialize")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", NULL, 0, entity, &userOptions);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Adds an element to the form
 */
PHP_METHOD(Phalcon_Forms_Form, add)
{
	zend_string *_9$$5;
	zend_ulong _8$$5;
	zval elements;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool type, _0, _3;
	zval position;
	zval *element, element_sub, *position_param = NULL, *type_param = NULL, name, key, value, _1, _4, _2$$3, _5$$5, *_6$$5, _7$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&elements);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_OBJECT_OF_CLASS(element, phalcon_forms_element_elementinterface_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(position)
		Z_PARAM_BOOL_OR_NULL(type, is_null_true)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 2, &element, &position_param, &type_param);
	if (!position_param) {
		ZEPHIR_INIT_VAR(&position);
	} else {
		zephir_get_strval(&position, position_param);
	}
	if (!type_param) {
		type = 0;
	} else {
		}
	ZEPHIR_CALL_METHOD(&name, element, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, element, "setform", NULL, 0, this_ptr);
	zephir_check_call_status();
	_0 = (zephir_method_exists_ex(element, ZEND_STRL("settagfactory")) == SUCCESS);
	if (_0) {
		zephir_read_property(&_1, this_ptr, ZEND_STRL("tagFactory"), PH_NOISY_CC | PH_READONLY);
		_0 = Z_TYPE_P(&_1) != IS_NULL;
	}
	if (_0) {
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("tagFactory"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, element, "settagfactory", NULL, 0, &_2$$3);
		zephir_check_call_status();
	}
	_3 = ZEPHIR_IS_NULL(&position);
	if (!(_3)) {
		zephir_read_property(&_4, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
		_3 = ZEPHIR_IS_EMPTY(&_4);
	}
	if (_3) {
		zephir_update_property_array(this_ptr, SL("elements"), &name, element);
	} else {
		ZEPHIR_INIT_VAR(&elements);
		array_init(&elements);
		zephir_read_property(&_5$$5, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_5$$5, 0, "phalcon/Forms/Form.zep", 176);
		if (Z_TYPE_P(&_5$$5) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_5$$5), _8$$5, _9$$5, _6$$5)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_9$$5 != NULL) { 
					ZVAL_STR_COPY(&key, _9$$5);
				} else {
					ZVAL_LONG(&key, _8$$5);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _6$$5);
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
			ZEPHIR_CALL_METHOD(NULL, &_5$$5, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_7$$5, &_5$$5, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_7$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, &_5$$5, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, &_5$$5, "current", NULL, 0);
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
				ZEPHIR_CALL_METHOD(NULL, &_5$$5, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
		zephir_update_property_zval(this_ptr, ZEND_STRL("elements"), &elements);
	}
	RETURN_THIS();
}

/**
 * Binds data to the entity
 *
 * @param object entity
 * @param array whitelist
 */
PHP_METHOD(Phalcon_Forms_Form, bind)
{
	zend_bool _7$$5, _16$$15;
	zend_string *_5;
	zend_ulong _4;
	zval method;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *entity = NULL, entity_sub, *whitelist_param = NULL, __$null, filter, key, value, element, filters, container, filteredValue, _0, *_2, _3, _1$$4, _6$$5, _9$$9, _10$$9, _11$$11, _12$$11, _13$$11, _15$$15, _17$$19, _18$$19, _19$$21, _20$$21, _21$$21;
	zval data, whitelist, assignData, filteredData;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&whitelist);
	ZVAL_UNDEF(&assignData);
	ZVAL_UNDEF(&filteredData);
	ZVAL_UNDEF(&entity_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&filteredValue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_15$$15);
	ZVAL_UNDEF(&_17$$19);
	ZVAL_UNDEF(&_18$$19);
	ZVAL_UNDEF(&_19$$21);
	ZVAL_UNDEF(&_20$$21);
	ZVAL_UNDEF(&_21$$21);
	ZVAL_UNDEF(&method);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ARRAY(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(entity)
		Z_PARAM_ARRAY(whitelist)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 2, &data_param, &entity, &whitelist_param);
	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);
	if (!entity) {
		entity = &entity_sub;
		ZEPHIR_CPY_WRT(entity, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(entity);
	}
	if (!whitelist_param) {
		ZEPHIR_INIT_VAR(&whitelist);
		array_init(&whitelist);
	} else {
		zephir_get_arrval(&whitelist, whitelist_param);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_forms_exception_ce, "There are no elements in the form", "phalcon/Forms/Form.zep", 195);
		return;
	}
	if (ZEPHIR_IS_EMPTY(&whitelist)) {
		zephir_read_property(&_1$$4, this_ptr, ZEND_STRL("whitelist"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&whitelist, &_1$$4);
	}
	ZEPHIR_INIT_VAR(&filter);
	ZVAL_NULL(&filter);
	ZEPHIR_INIT_VAR(&assignData);
	array_init(&assignData);
	ZEPHIR_INIT_VAR(&filteredData);
	array_init(&filteredData);
	zephir_is_iterable(&data, 0, "phalcon/Forms/Form.zep", 269);
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _4, _5, _2)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&key, _5);
			} else {
				ZVAL_LONG(&key, _4);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _2);
			ZEPHIR_OBS_NVAR(&element);
			zephir_read_property(&_6$$5, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
			if (!(zephir_array_isset_fetch(&element, &_6$$5, &key, 0))) {
				continue;
			}
			_7$$5 = !(ZEPHIR_IS_EMPTY(&whitelist));
			if (_7$$5) {
				_7$$5 = !(zephir_fast_in_array(&key, &whitelist));
			}
			if (_7$$5) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&filters, &element, "getfilters", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&filters)) {
				if (Z_TYPE_P(&filter) != IS_OBJECT) {
					ZEPHIR_CALL_METHOD(&container, this_ptr, "getdi", &_8, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_10$$9);
					ZVAL_STRING(&_10$$9, "filter");
					ZEPHIR_CALL_METHOD(&_9$$9, &container, "getshared", NULL, 0, &_10$$9);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&filter, &_9$$9);
				}
				ZEPHIR_CALL_METHOD(&filteredValue, &filter, "sanitize", NULL, 0, &value, &filters);
				zephir_check_call_status();
			} else {
				ZEPHIR_CPY_WRT(&filteredValue, &value);
			}
			zephir_array_update_zval(&assignData, &key, &value, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&filteredData, &key, &filteredValue, PH_COPY | PH_SEPARATE);
			if (Z_TYPE_P(entity) != IS_NULL) {
				ZEPHIR_INIT_NVAR(&_11$$11);
				zephir_camelize(&_11$$11, &key, NULL );
				ZEPHIR_INIT_NVAR(&_12$$11);
				ZEPHIR_CONCAT_SV(&_12$$11, "set", &_11$$11);
				zephir_get_strval(&method, &_12$$11);
				if ((zephir_method_exists(entity, &method)  == SUCCESS)) {
					ZEPHIR_CALL_METHOD_ZVAL(NULL, entity, &method, NULL, 0, &filteredValue);
					zephir_check_call_status();
					continue;
				}
				if (!(ZEPHIR_GLOBAL(form).strict_entity_property_check)) {
					zephir_update_property_zval_zval(entity, &key, &filteredValue);
					continue;
				}
				ZEPHIR_CALL_FUNCTION(&_13$$11, "property_exists", &_14, 290, entity, &key);
				zephir_check_call_status();
				if (zephir_is_true(&_13$$11)) {
					zephir_update_property_zval_zval(entity, &key, &filteredValue);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &data, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&element);
				zephir_read_property(&_15$$15, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
				if (!(zephir_array_isset_fetch(&element, &_15$$15, &key, 0))) {
					continue;
				}
				_16$$15 = !(ZEPHIR_IS_EMPTY(&whitelist));
				if (_16$$15) {
					_16$$15 = !(zephir_fast_in_array(&key, &whitelist));
				}
				if (_16$$15) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&filters, &element, "getfilters", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&filters)) {
					if (Z_TYPE_P(&filter) != IS_OBJECT) {
						ZEPHIR_CALL_METHOD(&container, this_ptr, "getdi", &_8, 0);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_18$$19);
						ZVAL_STRING(&_18$$19, "filter");
						ZEPHIR_CALL_METHOD(&_17$$19, &container, "getshared", NULL, 0, &_18$$19);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&filter, &_17$$19);
					}
					ZEPHIR_CALL_METHOD(&filteredValue, &filter, "sanitize", NULL, 0, &value, &filters);
					zephir_check_call_status();
				} else {
					ZEPHIR_CPY_WRT(&filteredValue, &value);
				}
				zephir_array_update_zval(&assignData, &key, &value, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&filteredData, &key, &filteredValue, PH_COPY | PH_SEPARATE);
				if (Z_TYPE_P(entity) != IS_NULL) {
					ZEPHIR_INIT_NVAR(&_19$$21);
					zephir_camelize(&_19$$21, &key, NULL );
					ZEPHIR_INIT_NVAR(&_20$$21);
					ZEPHIR_CONCAT_SV(&_20$$21, "set", &_19$$21);
					zephir_get_strval(&method, &_20$$21);
					if ((zephir_method_exists(entity, &method)  == SUCCESS)) {
						ZEPHIR_CALL_METHOD_ZVAL(NULL, entity, &method, NULL, 0, &filteredValue);
						zephir_check_call_status();
						continue;
					}
					if (!(ZEPHIR_GLOBAL(form).strict_entity_property_check)) {
						zephir_update_property_zval_zval(entity, &key, &filteredValue);
						continue;
					}
					ZEPHIR_CALL_FUNCTION(&_21$$21, "property_exists", &_14, 290, entity, &key);
					zephir_check_call_status();
					if (zephir_is_true(&_21$$21)) {
						zephir_update_property_zval_zval(entity, &key, &filteredValue);
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &assignData);
	zephir_update_property_zval(this_ptr, ZEND_STRL("filteredData"), &filteredData);
	RETURN_THIS();
}

/**
 * Clears every element in the form to its default value
 *
 * @param array|string|null fields
 */
PHP_METHOD(Phalcon_Forms_Form, clear)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fields = NULL, fields_sub, __$null, elements, element, data, field, _0, *_1$$3, _2$$3, _3$$4, _4$$4, _5$$5, _6$$5, _7$$7, *_8$$6, _9$$6, _10$$10, _11$$10, _12$$13, _13$$13;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&elements);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_12$$13);
	ZVAL_UNDEF(&_13$$13);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(fields)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &fields);
	if (!fields) {
		fields = &fields_sub;
		ZEPHIR_CPY_WRT(fields, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(fields);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&data, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&elements, &_0);
	if (Z_TYPE_P(fields) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&data);
		array_init(&data);
		zephir_is_iterable(&elements, 0, "phalcon/Forms/Form.zep", 298);
		if (Z_TYPE_P(&elements) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&elements), _1$$3)
			{
				ZEPHIR_INIT_NVAR(&element);
				ZVAL_COPY(&element, _1$$3);
				ZEPHIR_CALL_METHOD(&_3$$4, &element, "getdefault", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_4$$4, &element, "getname", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_zval(&data, &_4$$4, &_3$$4, PH_COPY | PH_SEPARATE);
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
					ZEPHIR_CALL_METHOD(&_5$$5, &element, "getdefault", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_6$$5, &element, "getname", NULL, 0);
					zephir_check_call_status();
					zephir_array_update_zval(&data, &_6$$5, &_5$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &elements, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&element);
	} else {
		if (Z_TYPE_P(fields) != IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_7$$7);
			zephir_create_array(&_7$$7, 1, 0);
			zephir_array_fast_append(&_7$$7, fields);
			ZEPHIR_CPY_WRT(fields, &_7$$7);
		}
		zephir_is_iterable(fields, 0, "phalcon/Forms/Form.zep", 312);
		if (Z_TYPE_P(fields) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(fields), _8$$6)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _8$$6);
				if (zephir_array_isset(&data, &field)) {
					zephir_array_unset(&data, &field, PH_SEPARATE);
				}
				ZEPHIR_OBS_NVAR(&element);
				if (zephir_array_isset_fetch(&element, &elements, &field, 0)) {
					ZEPHIR_CALL_METHOD(&_10$$10, &element, "getdefault", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_11$$10, &element, "getname", NULL, 0);
					zephir_check_call_status();
					zephir_array_update_zval(&data, &_11$$10, &_10$$10, PH_COPY | PH_SEPARATE);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, fields, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_9$$6, fields, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_9$$6)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&field, fields, "current", NULL, 0);
				zephir_check_call_status();
					if (zephir_array_isset(&data, &field)) {
						zephir_array_unset(&data, &field, PH_SEPARATE);
					}
					ZEPHIR_OBS_NVAR(&element);
					if (zephir_array_isset_fetch(&element, &elements, &field, 0)) {
						ZEPHIR_CALL_METHOD(&_12$$13, &element, "getdefault", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_13$$13, &element, "getname", NULL, 0);
						zephir_check_call_status();
						zephir_array_update_zval(&data, &_13$$13, &_12$$13, PH_COPY | PH_SEPARATE);
					}
				ZEPHIR_CALL_METHOD(NULL, fields, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&field);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &data);
	RETURN_THIS();
}

/**
 * Returns the number of elements in the form
 */
PHP_METHOD(Phalcon_Forms_Form, count)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
	RETURN_LONG(zephir_fast_count_int(&_0));
}

/**
 * Returns the current element in the iterator
 */
PHP_METHOD(Phalcon_Forms_Form, current)
{
	zval element, _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&element);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("elementsIndexed"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("position"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&element, &_0, &_1, 0))) {
		RETURN_MM_BOOL(0);
	}
	RETURN_CCTOR(&element);
}

/**
 * Returns an element added to the form by its name
 */
PHP_METHOD(Phalcon_Forms_Form, get)
{
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zephir_memory_observe(&element);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!(zephir_array_isset_fetch(&element, &_0, &name, 0)))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_forms_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Element with ID=", &name, " is not part of the form");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 33, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Forms/Form.zep", 351);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&element);
}

/**
 * Returns the form's action
 */
PHP_METHOD(Phalcon_Forms_Form, getAction)
{
	zval _3;
	zval _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getattributes", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "action");
	ZEPHIR_CALL_METHOD(&_1, &_0, "get", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_cast_to_string(&_3, &_1);
	RETURN_CTOR(&_3);
}

/**
 * Get Form attributes collection
 */
PHP_METHOD(Phalcon_Forms_Form, getAttributes)
{
	zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(Z_TYPE_P(&_0) == IS_NULL)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_html_attributes_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 23);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("attributes"), &_1$$3);
	}
	RETURN_MM_MEMBER(getThis(), "attributes");
}

/**
 * Returns the form elements added to the form
 */
PHP_METHOD(Phalcon_Forms_Form, getElements)
{

	RETURN_MEMBER(getThis(), "elements");
}

/**
 * Returns the entity related to the model
 *
 * @return object
 */
PHP_METHOD(Phalcon_Forms_Form, getEntity)
{

	RETURN_MEMBER(getThis(), "entity");
}

/**
 * Gets a value from the internal filtered data or calls getValue(name)
 */
PHP_METHOD(Phalcon_Forms_Form, getFilteredValue)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, filteredData, value, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&filteredData);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("filteredData"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&filteredData, &_0);
	if (Z_TYPE_P(&filteredData) == IS_ARRAY) {
		zephir_memory_observe(&value);
		if (zephir_array_isset_fetch(&value, &filteredData, &name, 0)) {
			RETURN_CCTOR(&value);
		}
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getvalue", NULL, 0, &name);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns a label for an element
 */
PHP_METHOD(Phalcon_Forms_Form, getLabel)
{
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zephir_memory_observe(&element);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!(zephir_array_isset_fetch(&element, &_0, &name, 0)))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_forms_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Element with ID=", &name, " is not part of the form");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 33, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Forms/Form.zep", 426);
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
PHP_METHOD(Phalcon_Forms_Form, getMessages)
{
	zend_bool _1;
	zval messages, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("messages"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&messages, &_0);
	_1 = Z_TYPE_P(&messages) == IS_OBJECT;
	if (_1) {
		_1 = zephir_instance_of_ev(&messages, phalcon_messages_messages_ce);
	}
	if (!(_1)) {
		object_init_ex(return_value, phalcon_messages_messages_ce);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 8);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(&messages);
}

/**
 * Returns the messages generated for a specific element
 */
PHP_METHOD(Phalcon_Forms_Form, getMessagesFor)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, &name);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		object_init_ex(return_value, phalcon_messages_messages_ce);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 8);
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
 * Returns the tagFactory object
 */
PHP_METHOD(Phalcon_Forms_Form, getTagFactory)
{

	RETURN_MEMBER(getThis(), "tagFactory");
}

/**
 * Returns the value of an option if present
 */
PHP_METHOD(Phalcon_Forms_Form, getUserOption)
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
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(option)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &option_param, &defaultValue);
	zephir_get_strval(&option, option_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	zephir_memory_observe(&value);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&value, &_0, &option, 0))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	RETURN_CCTOR(&value);
}

/**
 * Returns the options for the element
 */
PHP_METHOD(Phalcon_Forms_Form, getUserOptions)
{

	RETURN_MEMBER(getThis(), "options");
}

/**
 * Gets a value from the internal related entity or from the default value
 */
PHP_METHOD(Phalcon_Forms_Form, getValue)
{
	zval forbidden;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, __$true, entity, value, data, internalEntity, element, _0, _3, _4, _1$$4, _2$$4;
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
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&forbidden);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("entity"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&entity, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&data, &_0);
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("getcustomvalue")) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getcustomvalue", NULL, 0, &name, &entity, &data);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (Z_TYPE_P(&entity) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_camelize(&_1$$4, &name, NULL );
		ZEPHIR_INIT_VAR(&_2$$4);
		ZEPHIR_CONCAT_SV(&_2$$4, "get", &_1$$4);
		zephir_get_strval(&method, &_2$$4);
		if ((zephir_method_exists(&entity, &method)  == SUCCESS)) {
			ZEPHIR_RETURN_CALL_METHOD_ZVAL(&entity, &method, NULL, 0);
			zephir_check_call_status();
			RETURN_MM();
		}
		zephir_memory_observe(&value);
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
	zephir_create_array(&forbidden, 14, 0);
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
	zephir_array_update_string(&forbidden, SL("tagFactory"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&forbidden, SL("eventsmanager"), &__$true, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&internalEntity);
	zephir_fast_strtolower(&internalEntity, &name);
	if (zephir_array_isset(&forbidden, &internalEntity)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_3);
	zephir_camelize(&_3, &name, NULL );
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_SV(&_4, "get", &_3);
	zephir_get_strval(&method, &_4);
	if ((zephir_method_exists(this_ptr, &method)  == SUCCESS)) {
		ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, &method, NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_memory_observe(&element);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&element, &_0, &name, 0)) {
		ZEPHIR_RETURN_CALL_METHOD(&element, "getdefault", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_NULL();
}

/**
 * return ValidationInterface|null
 */
PHP_METHOD(Phalcon_Forms_Form, getValidation)
{

	RETURN_MEMBER(getThis(), "validation");
}

/**
 * return array
 */
PHP_METHOD(Phalcon_Forms_Form, getWhitelist)
{

	RETURN_MEMBER(getThis(), "whitelist");
}

/**
 * Check if the form contains an element
 */
PHP_METHOD(Phalcon_Forms_Form, has)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &name));
}

/**
 * Check if messages were generated for a specific element
 */
PHP_METHOD(Phalcon_Forms_Form, hasMessagesFor)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
 * @param array whitelist
 */
PHP_METHOD(Phalcon_Forms_Form, isValid)
{
	zend_object_iterator *_18$$20;
	zend_bool validationStatus = 0, _3, _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_13 = NULL, *_14 = NULL, *_21 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval whitelist;
	zval *data = NULL, data_sub, *entity = NULL, entity_sub, *whitelist_param = NULL, __$null, messages, element, validators, name, filters, validator, validation, elementMessage, _0, _4, _8, *_9, _10, _17, _1$$4, _2$$5, _5$$6, _6$$7, *_11$$10, _12$$10, *_15$$15, _16$$15, _19$$21, _20$$21;
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
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_16$$15);
	ZVAL_UNDEF(&_19$$21);
	ZVAL_UNDEF(&_20$$21);
	ZVAL_UNDEF(&whitelist);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(data)
		Z_PARAM_ZVAL_OR_NULL(entity)
		Z_PARAM_ARRAY(whitelist)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 3, &data, &entity, &whitelist_param);
	if (!data) {
		data = &data_sub;
		ZEPHIR_CPY_WRT(data, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(data);
	}
	if (!entity) {
		entity = &entity_sub;
		ZEPHIR_CPY_WRT(entity, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(entity);
	}
	if (!whitelist_param) {
		ZEPHIR_INIT_VAR(&whitelist);
		array_init(&whitelist);
	} else {
		zephir_get_arrval(&whitelist, whitelist_param);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		RETURN_MM_BOOL(1);
	}
	if (ZEPHIR_IS_EMPTY(&whitelist)) {
		zephir_read_property(&_1$$4, this_ptr, ZEND_STRL("whitelist"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&whitelist, &_1$$4);
	}
	if (Z_TYPE_P(data) != IS_ARRAY) {
		zephir_read_property(&_2$$5, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(data, &_2$$5);
	}
	_3 = Z_TYPE_P(entity) != IS_OBJECT;
	if (_3) {
		zephir_memory_observe(&_4);
		zephir_read_property(&_4, this_ptr, ZEND_STRL("entity"), PH_NOISY_CC);
		_3 = Z_TYPE_P(&_4) == IS_OBJECT;
	}
	if (_3) {
		zephir_read_property(&_5$$6, this_ptr, ZEND_STRL("entity"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(entity, &_5$$6);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "bind", NULL, 0, data, entity, &whitelist);
	zephir_check_call_status();
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("beforevalidation")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(&_6$$7, this_ptr, "beforevalidation", NULL, 0, data, entity);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_6$$7)) {
			RETURN_MM_BOOL(0);
		}
	}
	validationStatus = 1;
	ZEPHIR_CALL_METHOD(&validation, this_ptr, "getvalidation", NULL, 0);
	zephir_check_call_status();
	_7 = Z_TYPE_P(&validation) != IS_OBJECT;
	if (!(_7)) {
		_7 = !((zephir_instance_of_ev(&validation, phalcon_filter_validation_validationinterface_ce)));
	}
	if (_7) {
		ZEPHIR_INIT_NVAR(&validation);
		object_init_ex(&validation, phalcon_filter_validation_ce);
		ZEPHIR_CALL_METHOD(NULL, &validation, "__construct", NULL, 315);
		zephir_check_call_status();
	}
	zephir_read_property(&_8, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_8, 0, "phalcon/Forms/Form.zep", 722);
	if (Z_TYPE_P(&_8) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_8), _9)
		{
			ZEPHIR_INIT_NVAR(&element);
			ZVAL_COPY(&element, _9);
			ZEPHIR_CALL_METHOD(&validators, &element, "getvalidators", NULL, 0);
			zephir_check_call_status();
			if (zephir_fast_count_int(&validators) == 0) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&name, &element, "getname", NULL, 0);
			zephir_check_call_status();
			zephir_is_iterable(&validators, 0, "phalcon/Forms/Form.zep", 709);
			if (Z_TYPE_P(&validators) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&validators), _11$$10)
				{
					ZEPHIR_INIT_NVAR(&validator);
					ZVAL_COPY(&validator, _11$$10);
					ZEPHIR_CALL_METHOD(NULL, &validation, "add", &_13, 316, &name, &validator);
					zephir_check_call_status();
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &validators, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_12$$10, &validators, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_12$$10)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&validator, &validators, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &validation, "add", &_13, 316, &name, &validator);
						zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &validators, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&validator);
			ZEPHIR_CALL_METHOD(&filters, &element, "getfilters", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&filters) == IS_ARRAY) {
				ZEPHIR_CALL_METHOD(NULL, &validation, "setfilters", &_14, 317, &name, &filters);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_8, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_10, &_8, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_10)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&element, &_8, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&validators, &element, "getvalidators", NULL, 0);
				zephir_check_call_status();
				if (zephir_fast_count_int(&validators) == 0) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&name, &element, "getname", NULL, 0);
				zephir_check_call_status();
				zephir_is_iterable(&validators, 0, "phalcon/Forms/Form.zep", 709);
				if (Z_TYPE_P(&validators) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&validators), _15$$15)
					{
						ZEPHIR_INIT_NVAR(&validator);
						ZVAL_COPY(&validator, _15$$15);
						ZEPHIR_CALL_METHOD(NULL, &validation, "add", &_13, 316, &name, &validator);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &validators, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_16$$15, &validators, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_16$$15)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&validator, &validators, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_CALL_METHOD(NULL, &validation, "add", &_13, 316, &name, &validator);
							zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &validators, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&validator);
				ZEPHIR_CALL_METHOD(&filters, &element, "getfilters", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&filters) == IS_ARRAY) {
					ZEPHIR_CALL_METHOD(NULL, &validation, "setfilters", &_14, 317, &name, &filters);
					zephir_check_call_status();
				}
			ZEPHIR_CALL_METHOD(NULL, &_8, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&element);
	ZEPHIR_CALL_METHOD(&messages, &validation, "validate", NULL, 318, data, entity);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_17, &messages, "count", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_17)) {
		_18$$20 = zephir_get_iterator(&messages);
		_18$$20->funcs->rewind(_18$$20);
		for (;_18$$20->funcs->valid(_18$$20) == SUCCESS && !EG(exception); _18$$20->funcs->move_forward(_18$$20)) {
			{
				ZEPHIR_ITERATOR_COPY(&elementMessage, _18$$20);
			}
			ZEPHIR_CALL_METHOD(&_20$$21, &elementMessage, "getfield", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_19$$21, this_ptr, "get", &_21, 0, &_20$$21);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_19$$21, "appendmessage", NULL, 0, &elementMessage);
			zephir_check_call_status();
		}
		zend_iterator_dtor(_18$$20);
		ZEPHIR_CALL_METHOD(NULL, &messages, "rewind", NULL, 0);
		zephir_check_call_status();
		validationStatus = 0;
	}
	if (!(validationStatus)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("messages"), &messages);
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
PHP_METHOD(Phalcon_Forms_Form, key)
{

	RETURN_MEMBER(getThis(), "position");
}

/**
 * Generate the label of an element added to the form including HTML
 */
PHP_METHOD(Phalcon_Forms_Form, label)
{
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
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &name_param, &attributes_param);
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
	}
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	zephir_memory_observe(&element);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!(zephir_array_isset_fetch(&element, &_0, &name, 0)))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_forms_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Element with ID=", &name, " is not part of the form");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 33, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Forms/Form.zep", 772);
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
PHP_METHOD(Phalcon_Forms_Form, next)
{
	zval *this_ptr = getThis();
	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("position")));
}

/**
 * Renders a specific item in the form
 */
PHP_METHOD(Phalcon_Forms_Form, render)
{
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
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &name_param, &attributes_param);
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
	}
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	zephir_memory_observe(&element);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!(zephir_array_isset_fetch(&element, &_0, &name, 0)))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_forms_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Element with ID=", &name, " is not part of the form");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 33, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Forms/Form.zep", 796);
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
PHP_METHOD(Phalcon_Forms_Form, remove)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, __$null, _0, _1$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &name)) {
		zephir_unset_property_array(this_ptr, ZEND_STRL("elements"), &name);
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&_1$$3, &name, PH_SEPARATE);
		RETURN_MM_BOOL(1);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("elementsIndexed"), &__$null);
	RETURN_MM_BOOL(0);
}

/**
 * Rewinds the internal iterator
 */
PHP_METHOD(Phalcon_Forms_Form, rewind)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("position"), &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_1, "array_values", NULL, 14, &_0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("elementsIndexed"), &_1);
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets the form's action
 *
 * @return Form
 */
PHP_METHOD(Phalcon_Forms_Form, setAction)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *action_param = NULL, _0, _1;
	zval action;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&action);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(action)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &action_param);
	if (UNEXPECTED(Z_TYPE_P(action_param) != IS_STRING && Z_TYPE_P(action_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'action' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(action_param) == IS_STRING)) {
		zephir_get_strval(&action, action_param);
	} else {
		ZEPHIR_INIT_VAR(&action);
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
 * Set form attributes collection
 */
PHP_METHOD(Phalcon_Forms_Form, setAttributes)
{
	zval *attributes, attributes_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(attributes, phalcon_html_attributes_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &attributes);
	zephir_update_property_zval(this_ptr, ZEND_STRL("attributes"), attributes);
	RETURN_THISW();
}

/**
 * Sets the entity related to the model
 *
 * @param object entity
 */
PHP_METHOD(Phalcon_Forms_Form, setEntity)
{
	zval *entity, entity_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&entity_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(entity)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &entity);
	zephir_update_property_zval(this_ptr, ZEND_STRL("entity"), entity);
	RETURN_THISW();
}

/**
 * Sets the tagFactory for the form
 */
PHP_METHOD(Phalcon_Forms_Form, setTagFactory)
{
	zval *tagFactory, tagFactory_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tagFactory_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(tagFactory, phalcon_html_tagfactory_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &tagFactory);
	zephir_update_property_zval(this_ptr, ZEND_STRL("tagFactory"), tagFactory);
	RETURN_THISW();
}

/**
 * Sets the default validation
 *
 * @param ValidationInterface validation
 */
PHP_METHOD(Phalcon_Forms_Form, setValidation)
{
	zval *validation, validation_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(validation, phalcon_filter_validation_validationinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &validation);
	zephir_update_property_zval(this_ptr, ZEND_STRL("validation"), validation);
	RETURN_THISW();
}

/**
 * Sets the default whitelist
 *
 * @param array whitelist
 */
PHP_METHOD(Phalcon_Forms_Form, setWhitelist)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *whitelist_param = NULL;
	zval whitelist;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&whitelist);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(whitelist)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &whitelist_param);
	zephir_get_arrval(&whitelist, whitelist_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("whitelist"), &whitelist);
	RETURN_THIS();
}

/**
 * Sets an option for the form
 */
PHP_METHOD(Phalcon_Forms_Form, setUserOption)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *option_param = NULL, *value, value_sub;
	zval option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&value_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(option)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &option_param, &value);
	zephir_get_strval(&option, option_param);
	zephir_update_property_array(this_ptr, SL("options"), &option, value);
	RETURN_THIS();
}

/**
 * Sets options for the element
 */
PHP_METHOD(Phalcon_Forms_Form, setUserOptions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &options_param);
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("options"), &options);
	RETURN_THIS();
}

/**
 * Check if the current element in the iterator is valid
 */
PHP_METHOD(Phalcon_Forms_Form, valid)
{
	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("elementsIndexed"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("position"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset(&_0, &_1));
}

zend_object *zephir_init_properties_Phalcon_Forms_Form(zend_class_entry *class_type)
{
		zval _0, _2, _4, _6, _8, _10, _1$$3, _3$$4, _5$$5, _7$$6, _9$$7, _11$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$8);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("whitelist"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("whitelist"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("options"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("elementsIndexed"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("elementsIndexed"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("elements"), &_7$$6);
		}
		zephir_read_property_ex(&_8, this_ptr, ZEND_STRL("filteredData"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("filteredData"), &_9$$7);
		}
		zephir_read_property_ex(&_10, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_10) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_11$$8);
			array_init(&_11$$8);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("data"), &_11$$8);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

