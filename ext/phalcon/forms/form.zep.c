
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
		ZEPHIR_Z_PARAM_ARRAY(userOptions, userOptions_param)
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_forms_exception_ce, "The base entity is not valid", "phalcon/Forms/Form.zep", 101);
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("entity"), entity);
	zephir_update_property_zval(this_ptr, ZEND_STRL("options"), &userOptions);
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, phalcon_html_attributes_ce);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 36);
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
	zend_ulong _8$$5;
	zval elements;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool type, _0, _3;
	zend_string *position = NULL, *_9$$5;
	zval *element, element_sub, position_zv, *type_param = NULL, name, key, value, _1, _4, _2$$3, _5$$5, *_6$$5, _7$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&position_zv);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$5);
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
	element = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		type_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (!position) {
		ZEPHIR_INIT_VAR(&position_zv);
	} else {
		zephir_memory_observe(&position_zv);
	ZVAL_STR_COPY(&position_zv, position);
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
	_3 = ZEPHIR_IS_NULL(&position_zv);
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
		zephir_is_iterable(&_5$$5, 0, "phalcon/Forms/Form.zep", 179);
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
				if (ZEPHIR_IS_EQUAL(&key, &position_zv)) {
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
					if (ZEPHIR_IS_EQUAL(&key, &position_zv)) {
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
	zend_bool _7$$5, _11$$9, _27$$13, _46$$28;
	zend_string *_6, *_18;
	zend_ulong _5, _17;
	zval method;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_28 = NULL, *_34 = NULL, *_37 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *entity = NULL, entity_sub, *whitelist_param = NULL, __$null, filter, key, value, element, candidate, filters, container, filteredValue, elementName, dataKey, _0, _2, *_3, _4, *_15, _16, _1$$4, _8$$5, _9$$6, _10$$8, _12$$9, _13$$10, _14$$12, _19$$13, _20$$14, *_21$$14, _22$$14, _23$$15, _24$$15, _25$$17, _26$$17, _29$$22, _30$$22, _31$$24, _32$$24, _33$$24, _35$$24, _36$$24, _38$$28, _39$$29, *_40$$29, _41$$29, _42$$30, _43$$30, _44$$32, _45$$32, _47$$37, _48$$37, _49$$39, _50$$39, _51$$39, _52$$39, _53$$39;
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
	ZVAL_UNDEF(&candidate);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&filteredValue);
	ZVAL_UNDEF(&elementName);
	ZVAL_UNDEF(&dataKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_14$$12);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_20$$14);
	ZVAL_UNDEF(&_22$$14);
	ZVAL_UNDEF(&_23$$15);
	ZVAL_UNDEF(&_24$$15);
	ZVAL_UNDEF(&_25$$17);
	ZVAL_UNDEF(&_26$$17);
	ZVAL_UNDEF(&_29$$22);
	ZVAL_UNDEF(&_30$$22);
	ZVAL_UNDEF(&_31$$24);
	ZVAL_UNDEF(&_32$$24);
	ZVAL_UNDEF(&_33$$24);
	ZVAL_UNDEF(&_35$$24);
	ZVAL_UNDEF(&_36$$24);
	ZVAL_UNDEF(&_38$$28);
	ZVAL_UNDEF(&_39$$29);
	ZVAL_UNDEF(&_41$$29);
	ZVAL_UNDEF(&_42$$30);
	ZVAL_UNDEF(&_43$$30);
	ZVAL_UNDEF(&_44$$32);
	ZVAL_UNDEF(&_45$$32);
	ZVAL_UNDEF(&_47$$37);
	ZVAL_UNDEF(&_48$$37);
	ZVAL_UNDEF(&_49$$39);
	ZVAL_UNDEF(&_50$$39);
	ZVAL_UNDEF(&_51$$39);
	ZVAL_UNDEF(&_52$$39);
	ZVAL_UNDEF(&_53$$39);
	ZVAL_UNDEF(&method);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(entity)
		ZEPHIR_Z_PARAM_ARRAY(whitelist, whitelist_param)
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_forms_exception_ce, "There are no elements in the form", "phalcon/Forms/Form.zep", 199);
		return;
	}
	if (ZEPHIR_IS_EMPTY(&whitelist)) {
		zephir_read_property(&_1$$4, this_ptr, ZEND_STRL("whitelist"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&whitelist, &_1$$4);
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_2, 0, "phalcon/Forms/Form.zep", 224);
	if (Z_TYPE_P(&_2) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_2), _5, _6, _3)
		{
			ZEPHIR_INIT_NVAR(&elementName);
			if (_6 != NULL) { 
				ZVAL_STR_COPY(&elementName, _6);
			} else {
				ZVAL_LONG(&elementName, _5);
			}
			ZEPHIR_INIT_NVAR(&element);
			ZVAL_COPY(&element, _3);
			_7$$5 = zephir_instance_of_ev(&element, phalcon_forms_element_check_ce);
			if (_7$$5) {
				ZEPHIR_CALL_METHOD(&_8$$5, &element, "hasuncheckedvalue", NULL, 0);
				zephir_check_call_status();
				_7$$5 = zephir_is_true(&_8$$5);
			}
			if (_7$$5) {
				ZEPHIR_INIT_NVAR(&_9$$6);
				ZVAL_STRING(&_9$$6, "name");
				ZEPHIR_CALL_METHOD(&dataKey, &element, "getattribute", NULL, 0, &_9$$6);
				zephir_check_call_status();
				if (Z_TYPE_P(&dataKey) == IS_NULL) {
					ZEPHIR_CPY_WRT(&dataKey, &elementName);
				}
				if (!(zephir_array_key_exists(&data, &dataKey))) {
					ZEPHIR_CALL_METHOD(&_10$$8, &element, "getuncheckedvalue", NULL, 0);
					zephir_check_call_status();
					zephir_array_update_zval(&data, &dataKey, &_10$$8, PH_COPY | PH_SEPARATE);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_2, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_4, &_2, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&elementName, &_2, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&element, &_2, "current", NULL, 0);
			zephir_check_call_status();
				_11$$9 = zephir_instance_of_ev(&element, phalcon_forms_element_check_ce);
				if (_11$$9) {
					ZEPHIR_CALL_METHOD(&_12$$9, &element, "hasuncheckedvalue", NULL, 0);
					zephir_check_call_status();
					_11$$9 = zephir_is_true(&_12$$9);
				}
				if (_11$$9) {
					ZEPHIR_INIT_NVAR(&_13$$10);
					ZVAL_STRING(&_13$$10, "name");
					ZEPHIR_CALL_METHOD(&dataKey, &element, "getattribute", NULL, 0, &_13$$10);
					zephir_check_call_status();
					if (Z_TYPE_P(&dataKey) == IS_NULL) {
						ZEPHIR_CPY_WRT(&dataKey, &elementName);
					}
					if (!(zephir_array_key_exists(&data, &dataKey))) {
						ZEPHIR_CALL_METHOD(&_14$$12, &element, "getuncheckedvalue", NULL, 0);
						zephir_check_call_status();
						zephir_array_update_zval(&data, &dataKey, &_14$$12, PH_COPY | PH_SEPARATE);
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &_2, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&element);
	ZEPHIR_INIT_NVAR(&elementName);
	ZEPHIR_INIT_VAR(&filter);
	ZVAL_NULL(&filter);
	ZEPHIR_INIT_VAR(&assignData);
	array_init(&assignData);
	ZEPHIR_INIT_VAR(&filteredData);
	array_init(&filteredData);
	zephir_is_iterable(&data, 0, "phalcon/Forms/Form.zep", 302);
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _17, _18, _15)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_18 != NULL) { 
				ZVAL_STR_COPY(&key, _18);
			} else {
				ZVAL_LONG(&key, _17);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _15);
			ZEPHIR_OBS_NVAR(&element);
			zephir_read_property(&_19$$13, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
			if (!(zephir_array_isset_fetch(&element, &_19$$13, &key, 0))) {
				ZEPHIR_INIT_NVAR(&element);
				ZVAL_NULL(&element);
				zephir_read_property(&_20$$14, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
				zephir_is_iterable(&_20$$14, 0, "phalcon/Forms/Form.zep", 242);
				if (Z_TYPE_P(&_20$$14) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_20$$14), _21$$14)
					{
						ZEPHIR_INIT_NVAR(&candidate);
						ZVAL_COPY(&candidate, _21$$14);
						ZEPHIR_INIT_NVAR(&_24$$15);
						ZVAL_STRING(&_24$$15, "name");
						ZEPHIR_CALL_METHOD(&_23$$15, &candidate, "getattribute", NULL, 0, &_24$$15);
						zephir_check_call_status();
						if (ZEPHIR_IS_IDENTICAL(&_23$$15, &key)) {
							ZEPHIR_CPY_WRT(&element, &candidate);
							break;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &_20$$14, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_22$$14, &_20$$14, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_22$$14)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&candidate, &_20$$14, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_26$$17);
							ZVAL_STRING(&_26$$17, "name");
							ZEPHIR_CALL_METHOD(&_25$$17, &candidate, "getattribute", NULL, 0, &_26$$17);
							zephir_check_call_status();
							if (ZEPHIR_IS_IDENTICAL(&_25$$17, &key)) {
								ZEPHIR_CPY_WRT(&element, &candidate);
								break;
							}
						ZEPHIR_CALL_METHOD(NULL, &_20$$14, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&candidate);
				if (Z_TYPE_P(&element) == IS_NULL) {
					continue;
				}
			}
			_27$$13 = !(ZEPHIR_IS_EMPTY(&whitelist));
			if (_27$$13) {
				_27$$13 = !(zephir_fast_in_array(&key, &whitelist));
			}
			if (_27$$13) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&filters, &element, "getfilters", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&filters)) {
				if (Z_TYPE_P(&filter) != IS_OBJECT) {
					ZEPHIR_CALL_METHOD(&container, this_ptr, "getdi", &_28, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_30$$22);
					ZVAL_STRING(&_30$$22, "filter");
					ZEPHIR_CALL_METHOD(&_29$$22, &container, "getshared", NULL, 0, &_30$$22);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&filter, &_29$$22);
				}
				ZEPHIR_CALL_METHOD(&filteredValue, &filter, "sanitize", NULL, 0, &value, &filters);
				zephir_check_call_status();
			} else {
				ZEPHIR_CPY_WRT(&filteredValue, &value);
			}
			zephir_array_update_zval(&assignData, &key, &value, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&filteredData, &key, &filteredValue, PH_COPY | PH_SEPARATE);
			if (Z_TYPE_P(entity) != IS_NULL) {
				ZEPHIR_INIT_NVAR(&_31$$24);
				zephir_camelize(&_31$$24, &key, NULL );
				ZEPHIR_INIT_NVAR(&_32$$24);
				ZEPHIR_CONCAT_SV(&_32$$24, "set", &_31$$24);
				zephir_get_strval(&method, &_32$$24);
				if ((zephir_method_exists(entity, &method)  == SUCCESS)) {
					ZEPHIR_CALL_METHOD_ZVAL(NULL, entity, &method, NULL, 0, &filteredValue);
					zephir_check_call_status();
					continue;
				}
				ZEPHIR_INIT_NVAR(&_35$$24);
				ZVAL_STRING(&_35$$24, "form.strict_entity_property_check");
				ZEPHIR_CALL_CE_STATIC(&_33$$24, phalcon_support_settings_ce, "get", &_34, 0, &_35$$24);
				zephir_check_call_status();
				if (!zephir_is_true(&_33$$24)) {
					zephir_update_property_zval_zval(entity, &key, &filteredValue);
					continue;
				}
				ZEPHIR_CALL_FUNCTION(&_36$$24, "property_exists", &_37, 23, entity, &key);
				zephir_check_call_status();
				if (zephir_is_true(&_36$$24)) {
					zephir_update_property_zval_zval(entity, &key, &filteredValue);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_16, &data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_16)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &data, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&element);
				zephir_read_property(&_38$$28, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
				if (!(zephir_array_isset_fetch(&element, &_38$$28, &key, 0))) {
					ZEPHIR_INIT_NVAR(&element);
					ZVAL_NULL(&element);
					zephir_read_property(&_39$$29, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
					zephir_is_iterable(&_39$$29, 0, "phalcon/Forms/Form.zep", 242);
					if (Z_TYPE_P(&_39$$29) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_39$$29), _40$$29)
						{
							ZEPHIR_INIT_NVAR(&candidate);
							ZVAL_COPY(&candidate, _40$$29);
							ZEPHIR_INIT_NVAR(&_43$$30);
							ZVAL_STRING(&_43$$30, "name");
							ZEPHIR_CALL_METHOD(&_42$$30, &candidate, "getattribute", NULL, 0, &_43$$30);
							zephir_check_call_status();
							if (ZEPHIR_IS_IDENTICAL(&_42$$30, &key)) {
								ZEPHIR_CPY_WRT(&element, &candidate);
								break;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &_39$$29, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_41$$29, &_39$$29, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_41$$29)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&candidate, &_39$$29, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_45$$32);
								ZVAL_STRING(&_45$$32, "name");
								ZEPHIR_CALL_METHOD(&_44$$32, &candidate, "getattribute", NULL, 0, &_45$$32);
								zephir_check_call_status();
								if (ZEPHIR_IS_IDENTICAL(&_44$$32, &key)) {
									ZEPHIR_CPY_WRT(&element, &candidate);
									break;
								}
							ZEPHIR_CALL_METHOD(NULL, &_39$$29, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&candidate);
					if (Z_TYPE_P(&element) == IS_NULL) {
						continue;
					}
				}
				_46$$28 = !(ZEPHIR_IS_EMPTY(&whitelist));
				if (_46$$28) {
					_46$$28 = !(zephir_fast_in_array(&key, &whitelist));
				}
				if (_46$$28) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&filters, &element, "getfilters", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&filters)) {
					if (Z_TYPE_P(&filter) != IS_OBJECT) {
						ZEPHIR_CALL_METHOD(&container, this_ptr, "getdi", &_28, 0);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_48$$37);
						ZVAL_STRING(&_48$$37, "filter");
						ZEPHIR_CALL_METHOD(&_47$$37, &container, "getshared", NULL, 0, &_48$$37);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&filter, &_47$$37);
					}
					ZEPHIR_CALL_METHOD(&filteredValue, &filter, "sanitize", NULL, 0, &value, &filters);
					zephir_check_call_status();
				} else {
					ZEPHIR_CPY_WRT(&filteredValue, &value);
				}
				zephir_array_update_zval(&assignData, &key, &value, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&filteredData, &key, &filteredValue, PH_COPY | PH_SEPARATE);
				if (Z_TYPE_P(entity) != IS_NULL) {
					ZEPHIR_INIT_NVAR(&_49$$39);
					zephir_camelize(&_49$$39, &key, NULL );
					ZEPHIR_INIT_NVAR(&_50$$39);
					ZEPHIR_CONCAT_SV(&_50$$39, "set", &_49$$39);
					zephir_get_strval(&method, &_50$$39);
					if ((zephir_method_exists(entity, &method)  == SUCCESS)) {
						ZEPHIR_CALL_METHOD_ZVAL(NULL, entity, &method, NULL, 0, &filteredValue);
						zephir_check_call_status();
						continue;
					}
					ZEPHIR_INIT_NVAR(&_52$$39);
					ZVAL_STRING(&_52$$39, "form.strict_entity_property_check");
					ZEPHIR_CALL_CE_STATIC(&_51$$39, phalcon_support_settings_ce, "get", &_34, 0, &_52$$39);
					zephir_check_call_status();
					if (!zephir_is_true(&_51$$39)) {
						zephir_update_property_zval_zval(entity, &key, &filteredValue);
						continue;
					}
					ZEPHIR_CALL_FUNCTION(&_53$$39, "property_exists", &_37, 23, entity, &key);
					zephir_check_call_status();
					if (zephir_is_true(&_53$$39)) {
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
		zephir_is_iterable(&elements, 0, "phalcon/Forms/Form.zep", 331);
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
		zephir_is_iterable(fields, 0, "phalcon/Forms/Form.zep", 345);
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
	zval _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, element, _0, _1$$3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_memory_observe(&element);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!(zephir_array_isset_fetch(&element, &_0, &name_zv, 0)))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_forms_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Element with ID=", &name_zv, " is not part of the form");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 49, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Forms/Form.zep", 384);
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
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 36);
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

	RETURN_MEMBER_TYPED(getThis(), "elements", IS_ARRAY);
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
	zval name_zv, filteredData, value, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&filteredData);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("filteredData"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&filteredData, &_0);
	if (Z_TYPE_P(&filteredData) == IS_ARRAY) {
		zephir_memory_observe(&value);
		if (zephir_array_isset_fetch(&value, &filteredData, &name_zv, 0)) {
			RETURN_CCTOR(&value);
		}
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getvalue", NULL, 0, &name_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns a label for an element
 */
PHP_METHOD(Phalcon_Forms_Form, getLabel)
{
	zval _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, element, label, _0, _1$$3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_memory_observe(&element);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!(zephir_array_isset_fetch(&element, &_0, &name_zv, 0)))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_forms_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Element with ID=", &name_zv, " is not part of the form");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 49, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Forms/Form.zep", 459);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&label, &element, "getlabel", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&label))) {
		RETURN_MM_STR(zend_string_copy(name));
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
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 7);
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
	zval name_zv, _0, _1;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, &name_zv);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		object_init_ex(return_value, phalcon_messages_messages_ce);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 7);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "get", NULL, 0, &name_zv);
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
	zval option_zv, *defaultValue = NULL, defaultValue_sub, __$null, value, _0;
	zend_string *option = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option_zv);
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
	if (ZEND_NUM_ARGS() > 1) {
		defaultValue = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&option_zv);
	ZVAL_STR_COPY(&option_zv, option);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	zephir_memory_observe(&value);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&value, &_0, &option_zv, 0))) {
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

	RETURN_MEMBER_TYPED(getThis(), "options", IS_ARRAY);
}

/**
 * Gets a value from the internal related entity or from the default value
 */
PHP_METHOD(Phalcon_Forms_Form, getValue)
{
	zval method;
	zval forbidden;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, _POST, __$true, entity, value, data, internalEntity, element, _0, _3, _4, _1$$4, _2$$4;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_POST);
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
	ZVAL_UNDEF(&method);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_get_global(&_POST, SL("_POST"));
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("entity"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&entity, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&data, &_0);
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("getcustomvalue")) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getcustomvalue", NULL, 0, &name_zv, &entity, &data);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (Z_TYPE_P(&entity) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_camelize(&_1$$4, &name_zv, NULL );
		ZEPHIR_INIT_VAR(&_2$$4);
		ZEPHIR_CONCAT_SV(&_2$$4, "get", &_1$$4);
		zephir_get_strval(&method, &_2$$4);
		if ((zephir_method_exists(&entity, &method)  == SUCCESS)) {
			ZEPHIR_RETURN_CALL_METHOD_ZVAL(&entity, &method, NULL, 0);
			zephir_check_call_status();
			RETURN_MM();
		}
		zephir_memory_observe(&value);
		if (zephir_fetch_property_zval(&value, &entity, &name_zv, PH_SILENT_CC)) {
			RETURN_CCTOR(&value);
		}
	}
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		ZEPHIR_OBS_NVAR(&value);
		if (zephir_array_isset_fetch(&value, &data, &name_zv, 0)) {
			RETURN_CCTOR(&value);
		}
	}
	ZEPHIR_OBS_NVAR(&value);
	if (zephir_array_isset_fetch(&value, &_POST, &name_zv, 0)) {
		RETURN_CCTOR(&value);
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
	zephir_fast_strtolower(&internalEntity, &name_zv);
	if (zephir_array_isset(&forbidden, &internalEntity)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_3);
	zephir_camelize(&_3, &name_zv, NULL );
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
	if (zephir_array_isset_fetch(&element, &_0, &name_zv, 0)) {
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

	RETURN_MEMBER_TYPED(getThis(), "whitelist", IS_ARRAY);
}

/**
 * Check if the form contains an element
 */
PHP_METHOD(Phalcon_Forms_Form, has)
{
	zval name_zv, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&name_zv, name);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset(&_0, &name_zv));
}

/**
 * Check if messages were generated for a specific element
 */
PHP_METHOD(Phalcon_Forms_Form, hasMessagesFor)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, _0, _1;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmessagesfor", NULL, 0, &name_zv);
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
	zend_object_iterator *_20$$20;
	zend_bool validationStatus = 0, _3, _7, _11$$10, _16$$15;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_14 = NULL, *_15 = NULL, *_23 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval whitelist;
	zval *data = NULL, data_sub, *entity = NULL, entity_sub, *whitelist_param = NULL, __$null, messages, element, validators, name, filters, validator, validation, elementMessage, _0, _4, _8, *_9, _10, _19, _1$$4, _2$$5, _5$$6, _6$$7, *_12$$10, _13$$10, *_17$$15, _18$$15, _21$$21, _22$$21;
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
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_18$$15);
	ZVAL_UNDEF(&_21$$21);
	ZVAL_UNDEF(&_22$$21);
	ZVAL_UNDEF(&whitelist);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(data)
		Z_PARAM_ZVAL_OR_NULL(entity)
		ZEPHIR_Z_PARAM_ARRAY(whitelist, whitelist_param)
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
		ZEPHIR_CALL_METHOD(NULL, &validation, "__construct", NULL, 352);
		zephir_check_call_status();
	}
	zephir_read_property(&_8, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_8, 0, "phalcon/Forms/Form.zep", 762);
	if (Z_TYPE_P(&_8) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_8), _9)
		{
			ZEPHIR_INIT_NVAR(&element);
			ZVAL_COPY(&element, _9);
			ZEPHIR_CALL_METHOD(&validators, &element, "getvalidators", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&filters, &element, "getfilters", NULL, 0);
			zephir_check_call_status();
			_11$$10 = zephir_fast_count_int(&validators) == 0;
			if (_11$$10) {
				_11$$10 = ZEPHIR_IS_EMPTY(&filters);
			}
			if (_11$$10) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&name, &element, "getname", NULL, 0);
			zephir_check_call_status();
			zephir_is_iterable(&validators, 0, "phalcon/Forms/Form.zep", 754);
			if (Z_TYPE_P(&validators) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&validators), _12$$10)
				{
					ZEPHIR_INIT_NVAR(&validator);
					ZVAL_COPY(&validator, _12$$10);
					ZEPHIR_CALL_METHOD(NULL, &validation, "add", &_14, 353, &name, &validator);
					zephir_check_call_status();
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &validators, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_13$$10, &validators, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_13$$10)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&validator, &validators, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &validation, "add", &_14, 353, &name, &validator);
						zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &validators, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&validator);
			if (Z_TYPE_P(&filters) == IS_ARRAY) {
				ZEPHIR_CALL_METHOD(NULL, &validation, "setfilters", &_15, 354, &name, &filters);
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
				ZEPHIR_CALL_METHOD(&filters, &element, "getfilters", NULL, 0);
				zephir_check_call_status();
				_16$$15 = zephir_fast_count_int(&validators) == 0;
				if (_16$$15) {
					_16$$15 = ZEPHIR_IS_EMPTY(&filters);
				}
				if (_16$$15) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&name, &element, "getname", NULL, 0);
				zephir_check_call_status();
				zephir_is_iterable(&validators, 0, "phalcon/Forms/Form.zep", 754);
				if (Z_TYPE_P(&validators) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&validators), _17$$15)
					{
						ZEPHIR_INIT_NVAR(&validator);
						ZVAL_COPY(&validator, _17$$15);
						ZEPHIR_CALL_METHOD(NULL, &validation, "add", &_14, 353, &name, &validator);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &validators, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_18$$15, &validators, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_18$$15)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&validator, &validators, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_CALL_METHOD(NULL, &validation, "add", &_14, 353, &name, &validator);
							zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &validators, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&validator);
				if (Z_TYPE_P(&filters) == IS_ARRAY) {
					ZEPHIR_CALL_METHOD(NULL, &validation, "setfilters", &_15, 354, &name, &filters);
					zephir_check_call_status();
				}
			ZEPHIR_CALL_METHOD(NULL, &_8, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&element);
	ZEPHIR_CALL_METHOD(NULL, &validation, "validate", NULL, 355, data, entity);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&messages, &validation, "getmessages", NULL, 356);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_19, &messages, "count", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_19)) {
		_20$$20 = zephir_get_iterator(&messages);
		_20$$20->funcs->rewind(_20$$20);
		for (;_20$$20->funcs->valid(_20$$20) == SUCCESS && !EG(exception); _20$$20->funcs->move_forward(_20$$20)) {
			{
				ZEPHIR_ITERATOR_COPY(&elementMessage, _20$$20);
			}
			ZEPHIR_CALL_METHOD(&_22$$21, &elementMessage, "getfield", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_21$$21, this_ptr, "get", &_23, 0, &_22$$21);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_21$$21, "appendmessage", NULL, 0, &elementMessage);
			zephir_check_call_status();
		}
		zend_iterator_dtor(_20$$20);
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

	RETURN_MEMBER_TYPED(getThis(), "position", IS_LONG);
}

/**
 * Loads elements into the form from a Schema source.
 *
 * Each definition in the schema must have at least 'type' and 'name'.
 * The locator resolves the type string to an element factory; custom
 * types can be registered on the locator with setElement().
 *
 * @param Schema       $schema
 * @param FormsLocator $locator
 *
 * @return Form
 * @throws Exception
 */
PHP_METHOD(Phalcon_Forms_Form, load)
{
	zend_bool _12$$3, _18$$3, _21$$3, _33$$8, _39$$8, _42$$8;
	zval _8$$3, _10$$3, _30$$8, _32$$8;
	zval _4$$3, _6$$3, _15$$4, _26$$8, _28$$8, _36$$9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL, *_24 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *schema, schema_sub, *locator, locator_sub, attributes, definition, element, factory, name, options, type, _0, *_1, _2, _3$$3, _5$$3, _7$$3, _9$$3, _13$$3, _16$$3, _19$$3, _22$$3, _14$$4, _17$$5, _20$$6, _23$$7, _25$$8, _27$$8, _29$$8, _31$$8, _34$$8, _37$$8, _40$$8, _43$$8, _35$$9, _38$$10, _41$$11, _44$$12;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&schema_sub);
	ZVAL_UNDEF(&locator_sub);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&factory);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_19$$3);
	ZVAL_UNDEF(&_22$$3);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_25$$8);
	ZVAL_UNDEF(&_27$$8);
	ZVAL_UNDEF(&_29$$8);
	ZVAL_UNDEF(&_31$$8);
	ZVAL_UNDEF(&_34$$8);
	ZVAL_UNDEF(&_37$$8);
	ZVAL_UNDEF(&_40$$8);
	ZVAL_UNDEF(&_43$$8);
	ZVAL_UNDEF(&_35$$9);
	ZVAL_UNDEF(&_38$$10);
	ZVAL_UNDEF(&_41$$11);
	ZVAL_UNDEF(&_44$$12);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_26$$8);
	ZVAL_UNDEF(&_28$$8);
	ZVAL_UNDEF(&_36$$9);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_30$$8);
	ZVAL_UNDEF(&_32$$8);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(schema, phalcon_contracts_forms_schema_ce)
		Z_PARAM_OBJECT_OF_CLASS(locator, phalcon_forms_formslocator_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &schema, &locator);
	ZEPHIR_CALL_METHOD(&_0, schema, "load", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/Forms/Form.zep", 847);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&definition);
			ZVAL_COPY(&definition, _1);
			ZEPHIR_OBS_NVAR(&_3$$3);
			zephir_array_fetch_string(&_3$$3, &definition, SL("type"), PH_NOISY, "phalcon/Forms/Form.zep", 821);
			zephir_cast_to_string(&_4$$3, &_3$$3);
			ZEPHIR_INIT_NVAR(&type);
			zephir_fast_strtolower(&type, &_4$$3);
			ZEPHIR_OBS_NVAR(&_5$$3);
			zephir_array_fetch_string(&_5$$3, &definition, SL("name"), PH_NOISY, "phalcon/Forms/Form.zep", 822);
			zephir_cast_to_string(&_6$$3, &_5$$3);
			ZEPHIR_CPY_WRT(&name, &_6$$3);
			if (zephir_array_isset_string(&definition, SL("attributes"))) {
				ZEPHIR_OBS_NVAR(&_7$$3);
				zephir_array_fetch_string(&_7$$3, &definition, SL("attributes"), PH_NOISY, "phalcon/Forms/Form.zep", 823);
				zephir_get_arrval(&_8$$3, &_7$$3);
				ZEPHIR_CPY_WRT(&attributes, &_8$$3);
			} else {
				ZEPHIR_INIT_NVAR(&attributes);
				array_init(&attributes);
			}
			if (zephir_array_isset_string(&definition, SL("options"))) {
				ZEPHIR_OBS_NVAR(&_9$$3);
				zephir_array_fetch_string(&_9$$3, &definition, SL("options"), PH_NOISY, "phalcon/Forms/Form.zep", 824);
				zephir_get_arrval(&_10$$3, &_9$$3);
				ZEPHIR_CPY_WRT(&options, &_10$$3);
			} else {
				ZEPHIR_INIT_NVAR(&options);
				array_init(&options);
			}
			ZEPHIR_CALL_METHOD(&factory, locator, "getelement", &_11, 0, &type);
			zephir_check_call_status();
			ZEPHIR_CALL_ZVAL_FUNCTION(&element, &factory, NULL, 0, &name, &options, &attributes);
			zephir_check_call_status();
			_12$$3 = zephir_array_isset_string(&definition, SL("label"));
			if (_12$$3) {
				zephir_array_fetch_string(&_13$$3, &definition, SL("label"), PH_NOISY | PH_READONLY, "phalcon/Forms/Form.zep", 828);
				_12$$3 = !(ZEPHIR_IS_EMPTY(&_13$$3));
			}
			if (_12$$3) {
				ZEPHIR_OBS_NVAR(&_14$$4);
				zephir_array_fetch_string(&_14$$4, &definition, SL("label"), PH_NOISY, "phalcon/Forms/Form.zep", 829);
				zephir_cast_to_string(&_15$$4, &_14$$4);
				ZEPHIR_CALL_METHOD(NULL, &element, "setlabel", NULL, 0, &_15$$4);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_NVAR(&_16$$3);
			ZVAL_STRING(&_16$$3, "default");
			if (zephir_array_key_exists(&definition, &_16$$3)) {
				zephir_array_fetch_string(&_17$$5, &definition, SL("default"), PH_NOISY | PH_READONLY, "phalcon/Forms/Form.zep", 833);
				ZEPHIR_CALL_METHOD(NULL, &element, "setdefault", NULL, 0, &_17$$5);
				zephir_check_call_status();
			}
			_18$$3 = zephir_array_isset_string(&definition, SL("filters"));
			if (_18$$3) {
				zephir_array_fetch_string(&_19$$3, &definition, SL("filters"), PH_NOISY | PH_READONLY, "phalcon/Forms/Form.zep", 836);
				_18$$3 = !(ZEPHIR_IS_EMPTY(&_19$$3));
			}
			if (_18$$3) {
				zephir_array_fetch_string(&_20$$6, &definition, SL("filters"), PH_NOISY | PH_READONLY, "phalcon/Forms/Form.zep", 837);
				ZEPHIR_CALL_METHOD(NULL, &element, "setfilters", NULL, 0, &_20$$6);
				zephir_check_call_status();
			}
			_21$$3 = zephir_array_isset_string(&definition, SL("validators"));
			if (_21$$3) {
				zephir_array_fetch_string(&_22$$3, &definition, SL("validators"), PH_NOISY | PH_READONLY, "phalcon/Forms/Form.zep", 840);
				_21$$3 = !(ZEPHIR_IS_EMPTY(&_22$$3));
			}
			if (_21$$3) {
				zephir_array_fetch_string(&_23$$7, &definition, SL("validators"), PH_NOISY | PH_READONLY, "phalcon/Forms/Form.zep", 841);
				ZEPHIR_CALL_METHOD(NULL, &element, "addvalidators", NULL, 0, &_23$$7);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", &_24, 0, &element);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&definition, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&_25$$8);
				zephir_array_fetch_string(&_25$$8, &definition, SL("type"), PH_NOISY, "phalcon/Forms/Form.zep", 821);
				zephir_cast_to_string(&_26$$8, &_25$$8);
				ZEPHIR_INIT_NVAR(&type);
				zephir_fast_strtolower(&type, &_26$$8);
				ZEPHIR_OBS_NVAR(&_27$$8);
				zephir_array_fetch_string(&_27$$8, &definition, SL("name"), PH_NOISY, "phalcon/Forms/Form.zep", 822);
				zephir_cast_to_string(&_28$$8, &_27$$8);
				ZEPHIR_CPY_WRT(&name, &_28$$8);
				if (zephir_array_isset_string(&definition, SL("attributes"))) {
					ZEPHIR_OBS_NVAR(&_29$$8);
					zephir_array_fetch_string(&_29$$8, &definition, SL("attributes"), PH_NOISY, "phalcon/Forms/Form.zep", 823);
					zephir_get_arrval(&_30$$8, &_29$$8);
					ZEPHIR_CPY_WRT(&attributes, &_30$$8);
				} else {
					ZEPHIR_INIT_NVAR(&attributes);
					array_init(&attributes);
				}
				if (zephir_array_isset_string(&definition, SL("options"))) {
					ZEPHIR_OBS_NVAR(&_31$$8);
					zephir_array_fetch_string(&_31$$8, &definition, SL("options"), PH_NOISY, "phalcon/Forms/Form.zep", 824);
					zephir_get_arrval(&_32$$8, &_31$$8);
					ZEPHIR_CPY_WRT(&options, &_32$$8);
				} else {
					ZEPHIR_INIT_NVAR(&options);
					array_init(&options);
				}
				ZEPHIR_CALL_METHOD(&factory, locator, "getelement", &_11, 0, &type);
				zephir_check_call_status();
				ZEPHIR_CALL_ZVAL_FUNCTION(&element, &factory, NULL, 0, &name, &options, &attributes);
				zephir_check_call_status();
				_33$$8 = zephir_array_isset_string(&definition, SL("label"));
				if (_33$$8) {
					zephir_array_fetch_string(&_34$$8, &definition, SL("label"), PH_NOISY | PH_READONLY, "phalcon/Forms/Form.zep", 828);
					_33$$8 = !(ZEPHIR_IS_EMPTY(&_34$$8));
				}
				if (_33$$8) {
					ZEPHIR_OBS_NVAR(&_35$$9);
					zephir_array_fetch_string(&_35$$9, &definition, SL("label"), PH_NOISY, "phalcon/Forms/Form.zep", 829);
					zephir_cast_to_string(&_36$$9, &_35$$9);
					ZEPHIR_CALL_METHOD(NULL, &element, "setlabel", NULL, 0, &_36$$9);
					zephir_check_call_status();
				}
				ZEPHIR_INIT_NVAR(&_37$$8);
				ZVAL_STRING(&_37$$8, "default");
				if (zephir_array_key_exists(&definition, &_37$$8)) {
					zephir_array_fetch_string(&_38$$10, &definition, SL("default"), PH_NOISY | PH_READONLY, "phalcon/Forms/Form.zep", 833);
					ZEPHIR_CALL_METHOD(NULL, &element, "setdefault", NULL, 0, &_38$$10);
					zephir_check_call_status();
				}
				_39$$8 = zephir_array_isset_string(&definition, SL("filters"));
				if (_39$$8) {
					zephir_array_fetch_string(&_40$$8, &definition, SL("filters"), PH_NOISY | PH_READONLY, "phalcon/Forms/Form.zep", 836);
					_39$$8 = !(ZEPHIR_IS_EMPTY(&_40$$8));
				}
				if (_39$$8) {
					zephir_array_fetch_string(&_41$$11, &definition, SL("filters"), PH_NOISY | PH_READONLY, "phalcon/Forms/Form.zep", 837);
					ZEPHIR_CALL_METHOD(NULL, &element, "setfilters", NULL, 0, &_41$$11);
					zephir_check_call_status();
				}
				_42$$8 = zephir_array_isset_string(&definition, SL("validators"));
				if (_42$$8) {
					zephir_array_fetch_string(&_43$$8, &definition, SL("validators"), PH_NOISY | PH_READONLY, "phalcon/Forms/Form.zep", 840);
					_42$$8 = !(ZEPHIR_IS_EMPTY(&_43$$8));
				}
				if (_42$$8) {
					zephir_array_fetch_string(&_44$$12, &definition, SL("validators"), PH_NOISY | PH_READONLY, "phalcon/Forms/Form.zep", 841);
					ZEPHIR_CALL_METHOD(NULL, &element, "addvalidators", NULL, 0, &_44$$12);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", &_24, 0, &element);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&definition);
	RETURN_THIS();
}

/**
 * Generate the label of an element added to the form including HTML
 */
PHP_METHOD(Phalcon_Forms_Form, label)
{
	zval _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zval name_zv, *attributes_param = NULL, element, _0, _1$$3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_2$$3);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		attributes_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	zephir_memory_observe(&element);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!(zephir_array_isset_fetch(&element, &_0, &name_zv, 0)))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_forms_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Element with ID=", &name_zv, " is not part of the form");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 49, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Forms/Form.zep", 860);
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
	zval _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zval name_zv, *attributes_param = NULL, element, _0, _1$$3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_2$$3);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		attributes_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	zephir_memory_observe(&element);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!(zephir_array_isset_fetch(&element, &_0, &name_zv, 0)))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_forms_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Element with ID=", &name_zv, " is not part of the form");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 49, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Forms/Form.zep", 884);
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
	zval name_zv, __$null, _0, _1$$3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&name_zv, name);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &name_zv)) {
		zephir_unset_property_array(this_ptr, ZEND_STRL("elements"), &name_zv);
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&_1$$3, &name_zv, PH_SEPARATE);
		RETURN_BOOL(1);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("elementsIndexed"), &__$null);
	RETURN_BOOL(0);
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
	ZEPHIR_CALL_FUNCTION(&_1, "array_values", NULL, 22, &_0);
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
	zval action_zv, _0, _1;
	zend_string *action = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&action_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(action)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&action_zv);
	ZVAL_STR_COPY(&action_zv, action);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getattributes", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "action");
	ZEPHIR_CALL_METHOD(NULL, &_0, "set", NULL, 0, &_1, &action_zv);
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
		ZEPHIR_Z_PARAM_ARRAY(whitelist, whitelist_param)
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
	zval option_zv, *value, value_sub;
	zend_string *option = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option_zv);
	ZVAL_UNDEF(&value_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(option)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	value = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR(&option_zv, option);
	zephir_update_property_array(this_ptr, SL("options"), &option_zv, value);
	RETURN_THISW();
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
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
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

