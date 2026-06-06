
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
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
	 * @var Messages
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
	zval *entity = NULL, entity_sub, *userOptions_param = NULL, __$null, _2, _3, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&entity_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
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
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_forms_exceptions_invalidentity_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Forms/Form.zep", 104);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("entity"), entity);
	zephir_update_property_zval(this_ptr, ZEND_STRL("options"), &userOptions);
	ZEPHIR_INIT_VAR(&_2);
	object_init_ex(&_2, phalcon_html_attributes_ce);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 41);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("attributes"), &_2);
	ZEPHIR_INIT_VAR(&_3);
	object_init_ex(&_3, phalcon_messages_messages_ce);
	ZEPHIR_CALL_METHOD(NULL, &_3, "__construct", NULL, 10);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("messages"), &_3);
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
	zend_ulong _7$$5;
	zval elements;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool type, _0, _3, _10$$5;
	zend_string *position = NULL, *_8$$5;
	zval *element, element_sub, position_zv, *type_param = NULL, name, key, value, _1, _4, _2$$3, _5$$5, *_6$$5, _9$$5;
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
	ZVAL_UNDEF(&_9$$5);
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
		zephir_is_iterable(&_5$$5, 0, "phalcon/Forms/Form.zep", 183);
		if (Z_TYPE_P(&_5$$5) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_5$$5), _7$$5, _8$$5, _6$$5)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_8$$5 != NULL) { 
					ZVAL_STR_COPY(&key, _8$$5);
				} else {
					ZVAL_LONG(&key, _7$$5);
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
			_10$$5 = 1;
			while (1) {
				if (_10$$5) {
					_10$$5 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &_5$$5, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_9$$5, &_5$$5, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_9$$5)) {
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
	zend_bool _13, _42, _8$$7, _14$$11, _30$$15, _27$$16, _52$$30, _49$$31;
	zend_string *_7, *_20;
	zend_ulong _6, _19;
	zval method;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_31 = NULL, *_37 = NULL, *_40 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *entity = NULL, entity_sub, *whitelist_param = NULL, __$null, filter, key, value, element, candidate, filters, container, filteredValue, elementName, dataKey, _0, _4, *_5, _12, *_18, _41, _1$$3, _2$$4, _3$$6, _9$$7, _10$$8, _11$$10, _15$$11, _16$$12, _17$$14, _21$$15, _22$$16, *_23$$16, _26$$16, _24$$17, _25$$17, _28$$19, _29$$19, _32$$24, _33$$24, _34$$26, _35$$26, _36$$26, _38$$26, _39$$26, _43$$30, _44$$31, *_45$$31, _48$$31, _46$$32, _47$$32, _50$$34, _51$$34, _53$$39, _54$$39, _55$$41, _56$$41, _57$$41, _58$$41, _59$$41;
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
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_41);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_17$$14);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_22$$16);
	ZVAL_UNDEF(&_26$$16);
	ZVAL_UNDEF(&_24$$17);
	ZVAL_UNDEF(&_25$$17);
	ZVAL_UNDEF(&_28$$19);
	ZVAL_UNDEF(&_29$$19);
	ZVAL_UNDEF(&_32$$24);
	ZVAL_UNDEF(&_33$$24);
	ZVAL_UNDEF(&_34$$26);
	ZVAL_UNDEF(&_35$$26);
	ZVAL_UNDEF(&_36$$26);
	ZVAL_UNDEF(&_38$$26);
	ZVAL_UNDEF(&_39$$26);
	ZVAL_UNDEF(&_43$$30);
	ZVAL_UNDEF(&_44$$31);
	ZVAL_UNDEF(&_48$$31);
	ZVAL_UNDEF(&_46$$32);
	ZVAL_UNDEF(&_47$$32);
	ZVAL_UNDEF(&_50$$34);
	ZVAL_UNDEF(&_51$$34);
	ZVAL_UNDEF(&_53$$39);
	ZVAL_UNDEF(&_54$$39);
	ZVAL_UNDEF(&_55$$41);
	ZVAL_UNDEF(&_56$$41);
	ZVAL_UNDEF(&_57$$41);
	ZVAL_UNDEF(&_58$$41);
	ZVAL_UNDEF(&_59$$41);
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
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_forms_exceptions_noformelements_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Forms/Form.zep", 203);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("beforebind")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "beforebind", NULL, 0, &data, entity);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_2$$4)) {
			RETURN_THIS();
		}
	}
	if (ZEPHIR_IS_EMPTY(&whitelist)) {
		zephir_read_property(&_3$$6, this_ptr, ZEND_STRL("whitelist"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&whitelist, &_3$$6);
	}
	zephir_read_property(&_4, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_4, 0, "phalcon/Forms/Form.zep", 237);
	if (Z_TYPE_P(&_4) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_4), _6, _7, _5)
		{
			ZEPHIR_INIT_NVAR(&elementName);
			if (_7 != NULL) { 
				ZVAL_STR_COPY(&elementName, _7);
			} else {
				ZVAL_LONG(&elementName, _6);
			}
			ZEPHIR_INIT_NVAR(&element);
			ZVAL_COPY(&element, _5);
			_8$$7 = zephir_instance_of_ev(&element, phalcon_forms_element_check_ce);
			if (_8$$7) {
				ZEPHIR_CALL_METHOD(&_9$$7, &element, "hasuncheckedvalue", NULL, 0);
				zephir_check_call_status();
				_8$$7 = zephir_is_true(&_9$$7);
			}
			if (_8$$7) {
				ZEPHIR_INIT_NVAR(&_10$$8);
				ZVAL_STRING(&_10$$8, "name");
				ZEPHIR_CALL_METHOD(&dataKey, &element, "getattribute", NULL, 0, &_10$$8);
				zephir_check_call_status();
				if (Z_TYPE_P(&dataKey) == IS_NULL) {
					ZEPHIR_CPY_WRT(&dataKey, &elementName);
				}
				if (!(zephir_array_key_exists(&data, &dataKey))) {
					ZEPHIR_CALL_METHOD(&_11$$10, &element, "getuncheckedvalue", NULL, 0);
					zephir_check_call_status();
					zephir_array_update_zval(&data, &dataKey, &_11$$10, PH_COPY | PH_SEPARATE);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_4, "rewind", NULL, 0);
		zephir_check_call_status();
		_13 = 1;
		while (1) {
			if (_13) {
				_13 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_4, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_12, &_4, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_12)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&elementName, &_4, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&element, &_4, "current", NULL, 0);
			zephir_check_call_status();
				_14$$11 = zephir_instance_of_ev(&element, phalcon_forms_element_check_ce);
				if (_14$$11) {
					ZEPHIR_CALL_METHOD(&_15$$11, &element, "hasuncheckedvalue", NULL, 0);
					zephir_check_call_status();
					_14$$11 = zephir_is_true(&_15$$11);
				}
				if (_14$$11) {
					ZEPHIR_INIT_NVAR(&_16$$12);
					ZVAL_STRING(&_16$$12, "name");
					ZEPHIR_CALL_METHOD(&dataKey, &element, "getattribute", NULL, 0, &_16$$12);
					zephir_check_call_status();
					if (Z_TYPE_P(&dataKey) == IS_NULL) {
						ZEPHIR_CPY_WRT(&dataKey, &elementName);
					}
					if (!(zephir_array_key_exists(&data, &dataKey))) {
						ZEPHIR_CALL_METHOD(&_17$$14, &element, "getuncheckedvalue", NULL, 0);
						zephir_check_call_status();
						zephir_array_update_zval(&data, &dataKey, &_17$$14, PH_COPY | PH_SEPARATE);
					}
				}
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
	zephir_is_iterable(&data, 0, "phalcon/Forms/Form.zep", 315);
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _19, _20, _18)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_20 != NULL) { 
				ZVAL_STR_COPY(&key, _20);
			} else {
				ZVAL_LONG(&key, _19);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _18);
			ZEPHIR_OBS_NVAR(&element);
			zephir_read_property(&_21$$15, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
			if (!(zephir_array_isset_fetch(&element, &_21$$15, &key, 0))) {
				ZEPHIR_INIT_NVAR(&element);
				ZVAL_NULL(&element);
				zephir_read_property(&_22$$16, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
				zephir_is_iterable(&_22$$16, 0, "phalcon/Forms/Form.zep", 255);
				if (Z_TYPE_P(&_22$$16) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_22$$16), _23$$16)
					{
						ZEPHIR_INIT_NVAR(&candidate);
						ZVAL_COPY(&candidate, _23$$16);
						ZEPHIR_INIT_NVAR(&_25$$17);
						ZVAL_STRING(&_25$$17, "name");
						ZEPHIR_CALL_METHOD(&_24$$17, &candidate, "getattribute", NULL, 0, &_25$$17);
						zephir_check_call_status();
						if (ZEPHIR_IS_IDENTICAL(&_24$$17, &key)) {
							ZEPHIR_CPY_WRT(&element, &candidate);
							break;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &_22$$16, "rewind", NULL, 0);
					zephir_check_call_status();
					_27$$16 = 1;
					while (1) {
						if (_27$$16) {
							_27$$16 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &_22$$16, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_26$$16, &_22$$16, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_26$$16)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&candidate, &_22$$16, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_29$$19);
							ZVAL_STRING(&_29$$19, "name");
							ZEPHIR_CALL_METHOD(&_28$$19, &candidate, "getattribute", NULL, 0, &_29$$19);
							zephir_check_call_status();
							if (ZEPHIR_IS_IDENTICAL(&_28$$19, &key)) {
								ZEPHIR_CPY_WRT(&element, &candidate);
								break;
							}
					}
				}
				ZEPHIR_INIT_NVAR(&candidate);
				if (Z_TYPE_P(&element) == IS_NULL) {
					continue;
				}
			}
			_30$$15 = !(ZEPHIR_IS_EMPTY(&whitelist));
			if (_30$$15) {
				_30$$15 = !(zephir_fast_in_array(&key, &whitelist));
			}
			if (_30$$15) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&filters, &element, "getfilters", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&filters)) {
				if (Z_TYPE_P(&filter) != IS_OBJECT) {
					ZEPHIR_CALL_METHOD(&container, this_ptr, "getdi", &_31, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_33$$24);
					ZVAL_STRING(&_33$$24, "filter");
					ZEPHIR_CALL_METHOD(&_32$$24, &container, "getshared", NULL, 0, &_33$$24);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&filter, &_32$$24);
				}
				ZEPHIR_CALL_METHOD(&filteredValue, &filter, "sanitize", NULL, 0, &value, &filters);
				zephir_check_call_status();
			} else {
				ZEPHIR_CPY_WRT(&filteredValue, &value);
			}
			zephir_array_update_zval(&assignData, &key, &value, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&filteredData, &key, &filteredValue, PH_COPY | PH_SEPARATE);
			if (Z_TYPE_P(entity) != IS_NULL) {
				ZEPHIR_INIT_NVAR(&_34$$26);
				zephir_camelize(&_34$$26, &key, NULL );
				ZEPHIR_INIT_NVAR(&_35$$26);
				ZEPHIR_CONCAT_SV(&_35$$26, "set", &_34$$26);
				zephir_get_strval(&method, &_35$$26);
				if ((zephir_method_exists(entity, &method)  == SUCCESS)) {
					ZEPHIR_CALL_METHOD_ZVAL(NULL, entity, &method, NULL, 0, &filteredValue);
					zephir_check_call_status();
					continue;
				}
				ZEPHIR_INIT_NVAR(&_38$$26);
				ZVAL_STRING(&_38$$26, "form.strict_entity_property_check");
				ZEPHIR_CALL_CE_STATIC(&_36$$26, phalcon_support_settings_ce, "get", &_37, 0, &_38$$26);
				zephir_check_call_status();
				if (!zephir_is_true(&_36$$26)) {
					zephir_update_property_zval_zval(entity, &key, &filteredValue);
					continue;
				}
				ZEPHIR_CALL_FUNCTION(&_39$$26, "property_exists", &_40, 14, entity, &key);
				zephir_check_call_status();
				if (zephir_is_true(&_39$$26)) {
					zephir_update_property_zval_zval(entity, &key, &filteredValue);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
		zephir_check_call_status();
		_42 = 1;
		while (1) {
			if (_42) {
				_42 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_41, &data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_41)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &data, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&element);
				zephir_read_property(&_43$$30, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
				if (!(zephir_array_isset_fetch(&element, &_43$$30, &key, 0))) {
					ZEPHIR_INIT_NVAR(&element);
					ZVAL_NULL(&element);
					zephir_read_property(&_44$$31, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
					zephir_is_iterable(&_44$$31, 0, "phalcon/Forms/Form.zep", 255);
					if (Z_TYPE_P(&_44$$31) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_44$$31), _45$$31)
						{
							ZEPHIR_INIT_NVAR(&candidate);
							ZVAL_COPY(&candidate, _45$$31);
							ZEPHIR_INIT_NVAR(&_47$$32);
							ZVAL_STRING(&_47$$32, "name");
							ZEPHIR_CALL_METHOD(&_46$$32, &candidate, "getattribute", NULL, 0, &_47$$32);
							zephir_check_call_status();
							if (ZEPHIR_IS_IDENTICAL(&_46$$32, &key)) {
								ZEPHIR_CPY_WRT(&element, &candidate);
								break;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &_44$$31, "rewind", NULL, 0);
						zephir_check_call_status();
						_49$$31 = 1;
						while (1) {
							if (_49$$31) {
								_49$$31 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, &_44$$31, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_48$$31, &_44$$31, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_48$$31)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&candidate, &_44$$31, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_51$$34);
								ZVAL_STRING(&_51$$34, "name");
								ZEPHIR_CALL_METHOD(&_50$$34, &candidate, "getattribute", NULL, 0, &_51$$34);
								zephir_check_call_status();
								if (ZEPHIR_IS_IDENTICAL(&_50$$34, &key)) {
									ZEPHIR_CPY_WRT(&element, &candidate);
									break;
								}
						}
					}
					ZEPHIR_INIT_NVAR(&candidate);
					if (Z_TYPE_P(&element) == IS_NULL) {
						continue;
					}
				}
				_52$$30 = !(ZEPHIR_IS_EMPTY(&whitelist));
				if (_52$$30) {
					_52$$30 = !(zephir_fast_in_array(&key, &whitelist));
				}
				if (_52$$30) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&filters, &element, "getfilters", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&filters)) {
					if (Z_TYPE_P(&filter) != IS_OBJECT) {
						ZEPHIR_CALL_METHOD(&container, this_ptr, "getdi", &_31, 0);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_54$$39);
						ZVAL_STRING(&_54$$39, "filter");
						ZEPHIR_CALL_METHOD(&_53$$39, &container, "getshared", NULL, 0, &_54$$39);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&filter, &_53$$39);
					}
					ZEPHIR_CALL_METHOD(&filteredValue, &filter, "sanitize", NULL, 0, &value, &filters);
					zephir_check_call_status();
				} else {
					ZEPHIR_CPY_WRT(&filteredValue, &value);
				}
				zephir_array_update_zval(&assignData, &key, &value, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&filteredData, &key, &filteredValue, PH_COPY | PH_SEPARATE);
				if (Z_TYPE_P(entity) != IS_NULL) {
					ZEPHIR_INIT_NVAR(&_55$$41);
					zephir_camelize(&_55$$41, &key, NULL );
					ZEPHIR_INIT_NVAR(&_56$$41);
					ZEPHIR_CONCAT_SV(&_56$$41, "set", &_55$$41);
					zephir_get_strval(&method, &_56$$41);
					if ((zephir_method_exists(entity, &method)  == SUCCESS)) {
						ZEPHIR_CALL_METHOD_ZVAL(NULL, entity, &method, NULL, 0, &filteredValue);
						zephir_check_call_status();
						continue;
					}
					ZEPHIR_INIT_NVAR(&_58$$41);
					ZVAL_STRING(&_58$$41, "form.strict_entity_property_check");
					ZEPHIR_CALL_CE_STATIC(&_57$$41, phalcon_support_settings_ce, "get", &_37, 0, &_58$$41);
					zephir_check_call_status();
					if (!zephir_is_true(&_57$$41)) {
						zephir_update_property_zval_zval(entity, &key, &filteredValue);
						continue;
					}
					ZEPHIR_CALL_FUNCTION(&_59$$41, "property_exists", &_40, 14, entity, &key);
					zephir_check_call_status();
					if (zephir_is_true(&_59$$41)) {
						zephir_update_property_zval_zval(entity, &key, &filteredValue);
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &assignData);
	zephir_update_property_zval(this_ptr, ZEND_STRL("filteredData"), &filteredData);
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("afterbind")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "afterbind", NULL, 0, entity);
		zephir_check_call_status();
	}
	RETURN_THIS();
}

/**
 * Clears every element in the form to its default value
 *
 * @param array|string|null fields
 */
PHP_METHOD(Phalcon_Forms_Form, clear)
{
	zend_bool _5$$3, _13$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fields = NULL, fields_sub, __$null, elements, element, data, field, _0, *_1$$3, _4$$3, _2$$4, _3$$4, _6$$5, _7$$5, _8$$7, *_9$$6, _12$$6, _10$$10, _11$$10, _14$$13, _15$$13;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&elements);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_14$$13);
	ZVAL_UNDEF(&_15$$13);
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
		zephir_is_iterable(&elements, 0, "phalcon/Forms/Form.zep", 351);
		if (Z_TYPE_P(&elements) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&elements), _1$$3)
			{
				ZEPHIR_INIT_NVAR(&element);
				ZVAL_COPY(&element, _1$$3);
				ZEPHIR_CALL_METHOD(&_2$$4, &element, "getdefault", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_3$$4, &element, "getname", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_zval(&data, &_3$$4, &_2$$4, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &elements, "rewind", NULL, 0);
			zephir_check_call_status();
			_5$$3 = 1;
			while (1) {
				if (_5$$3) {
					_5$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &elements, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_4$$3, &elements, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_4$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&element, &elements, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_6$$5, &element, "getdefault", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_7$$5, &element, "getname", NULL, 0);
					zephir_check_call_status();
					zephir_array_update_zval(&data, &_7$$5, &_6$$5, PH_COPY | PH_SEPARATE);
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
		zephir_is_iterable(fields, 0, "phalcon/Forms/Form.zep", 371);
		if (Z_TYPE_P(fields) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(fields), _9$$6)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _9$$6);
				if (zephir_array_key_exists(&data, &field)) {
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
			_13$$6 = 1;
			while (1) {
				if (_13$$6) {
					_13$$6 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, fields, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_12$$6, fields, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_12$$6)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&field, fields, "current", NULL, 0);
				zephir_check_call_status();
					if (zephir_array_key_exists(&data, &field)) {
						zephir_array_unset(&data, &field, PH_SEPARATE);
					}
					ZEPHIR_OBS_NVAR(&element);
					if (zephir_array_isset_fetch(&element, &elements, &field, 0)) {
						ZEPHIR_CALL_METHOD(&_14$$13, &element, "getdefault", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_15$$13, &element, "getname", NULL, 0);
						zephir_check_call_status();
						zephir_array_update_zval(&data, &_15$$13, &_14$$13, PH_COPY | PH_SEPARATE);
					}
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
	zval name_zv, element, _0, _1$$3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
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
		object_init_ex(&_1$$3, phalcon_forms_exceptions_elementnotinform_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0, &name_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Forms/Form.zep", 408);
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
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 41);
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
		object_init_ex(&_1$$3, phalcon_forms_exceptions_elementnotinform_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0, &name_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Forms/Form.zep", 481);
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

	RETURN_MEMBER(getThis(), "messages");
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
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 10);
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
	if (zephir_array_isset_value(&forbidden, &internalEntity)) {
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
	RETURN_BOOL(zephir_array_isset_value(&_0, &name_zv));
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
	zend_object_iterator *_23$$20;
	zend_bool validationStatus = 0, _3, _7, _17, _10$$10, _14$$10, _18$$15, _21$$15;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_12 = NULL, *_15 = NULL, *_26 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval whitelist;
	zval *data = NULL, data_sub, *entity = NULL, entity_sub, *whitelist_param = NULL, __$null, messages, element, validators, name, filters, validator, validation, elementMessage, _0, _4, _8, *_9, _16, _22, _1$$4, _2$$5, _5$$6, _6$$7, *_11$$10, _13$$10, *_19$$15, _20$$15, _24$$21, _25$$21;
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
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_20$$15);
	ZVAL_UNDEF(&_24$$21);
	ZVAL_UNDEF(&_25$$21);
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
		ZEPHIR_CALL_METHOD(NULL, &validation, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_read_property(&_8, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_8, 0, "phalcon/Forms/Form.zep", 776);
	if (Z_TYPE_P(&_8) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_8), _9)
		{
			ZEPHIR_INIT_NVAR(&element);
			ZVAL_COPY(&element, _9);
			ZEPHIR_CALL_METHOD(&validators, &element, "getvalidators", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&filters, &element, "getfilters", NULL, 0);
			zephir_check_call_status();
			_10$$10 = zephir_fast_count_int(&validators) == 0;
			if (_10$$10) {
				_10$$10 = ZEPHIR_IS_EMPTY(&filters);
			}
			if (_10$$10) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&name, &element, "getname", NULL, 0);
			zephir_check_call_status();
			zephir_is_iterable(&validators, 0, "phalcon/Forms/Form.zep", 768);
			if (Z_TYPE_P(&validators) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&validators), _11$$10)
				{
					ZEPHIR_INIT_NVAR(&validator);
					ZVAL_COPY(&validator, _11$$10);
					ZEPHIR_CALL_METHOD(NULL, &validation, "add", &_12, 0, &name, &validator);
					zephir_check_call_status();
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &validators, "rewind", NULL, 0);
				zephir_check_call_status();
				_14$$10 = 1;
				while (1) {
					if (_14$$10) {
						_14$$10 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, &validators, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_13$$10, &validators, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_13$$10)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&validator, &validators, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &validation, "add", &_12, 0, &name, &validator);
						zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&validator);
			if (Z_TYPE_P(&filters) == IS_ARRAY) {
				ZEPHIR_CALL_METHOD(NULL, &validation, "setfilters", &_15, 0, &name, &filters);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_8, "rewind", NULL, 0);
		zephir_check_call_status();
		_17 = 1;
		while (1) {
			if (_17) {
				_17 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_8, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_16, &_8, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_16)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&element, &_8, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&validators, &element, "getvalidators", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&filters, &element, "getfilters", NULL, 0);
				zephir_check_call_status();
				_18$$15 = zephir_fast_count_int(&validators) == 0;
				if (_18$$15) {
					_18$$15 = ZEPHIR_IS_EMPTY(&filters);
				}
				if (_18$$15) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&name, &element, "getname", NULL, 0);
				zephir_check_call_status();
				zephir_is_iterable(&validators, 0, "phalcon/Forms/Form.zep", 768);
				if (Z_TYPE_P(&validators) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&validators), _19$$15)
					{
						ZEPHIR_INIT_NVAR(&validator);
						ZVAL_COPY(&validator, _19$$15);
						ZEPHIR_CALL_METHOD(NULL, &validation, "add", &_12, 0, &name, &validator);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &validators, "rewind", NULL, 0);
					zephir_check_call_status();
					_21$$15 = 1;
					while (1) {
						if (_21$$15) {
							_21$$15 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &validators, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_20$$15, &validators, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_20$$15)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&validator, &validators, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_CALL_METHOD(NULL, &validation, "add", &_12, 0, &name, &validator);
							zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&validator);
				if (Z_TYPE_P(&filters) == IS_ARRAY) {
					ZEPHIR_CALL_METHOD(NULL, &validation, "setfilters", &_15, 0, &name, &filters);
					zephir_check_call_status();
				}
		}
	}
	ZEPHIR_INIT_NVAR(&element);
	ZEPHIR_CALL_METHOD(NULL, &validation, "validate", NULL, 0, data, entity);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&messages, &validation, "getmessages", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_22, &messages, "count", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_22)) {
		_23$$20 = zephir_get_iterator(&messages);
		if (EXPECTED(_23$$20 != NULL)) {
			_23$$20->funcs->rewind(_23$$20);
			for (;_23$$20->funcs->valid(_23$$20) == SUCCESS && !EG(exception); _23$$20->funcs->move_forward(_23$$20)) {
			{
				ZEPHIR_ITERATOR_COPY(&elementMessage, _23$$20);
			}
			ZEPHIR_CALL_METHOD(&_25$$21, &elementMessage, "getfield", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_24$$21, this_ptr, "get", &_26, 0, &_25$$21);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_24$$21, "appendmessage", NULL, 0, &elementMessage);
			zephir_check_call_status();
		}
		zend_iterator_dtor(_23$$20);
		}
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
 * @return static
 * @throws Exception
 */
PHP_METHOD(Phalcon_Forms_Form, load)
{
	zval _7$$3, _9$$3, _31$$8, _33$$8;
	zval _3$$3, _5$$3, _14$$4, _27$$8, _29$$8, _37$$9;
	zend_bool _25, _11$$3, _17$$3, _20$$3, _34$$8, _40$$8, _43$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL, *_23 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *schema, schema_sub, *locator, locator_sub, attributes, definition, element, factory, name, options, type, _0, *_1, _24, _2$$3, _4$$3, _6$$3, _8$$3, _12$$3, _15$$3, _18$$3, _21$$3, _13$$4, _16$$5, _19$$6, _22$$7, _26$$8, _28$$8, _30$$8, _32$$8, _35$$8, _38$$8, _41$$8, _44$$8, _36$$9, _39$$10, _42$$11, _45$$12;
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
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_21$$3);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_26$$8);
	ZVAL_UNDEF(&_28$$8);
	ZVAL_UNDEF(&_30$$8);
	ZVAL_UNDEF(&_32$$8);
	ZVAL_UNDEF(&_35$$8);
	ZVAL_UNDEF(&_38$$8);
	ZVAL_UNDEF(&_41$$8);
	ZVAL_UNDEF(&_44$$8);
	ZVAL_UNDEF(&_36$$9);
	ZVAL_UNDEF(&_39$$10);
	ZVAL_UNDEF(&_42$$11);
	ZVAL_UNDEF(&_45$$12);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_27$$8);
	ZVAL_UNDEF(&_29$$8);
	ZVAL_UNDEF(&_37$$9);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_31$$8);
	ZVAL_UNDEF(&_33$$8);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(schema, phalcon_contracts_forms_schema_ce)
		Z_PARAM_OBJECT_OF_CLASS(locator, phalcon_forms_formslocator_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &schema, &locator);
	ZEPHIR_CALL_METHOD(&_0, schema, "load", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/Forms/Form.zep", 861);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&definition);
			ZVAL_COPY(&definition, _1);
			ZEPHIR_OBS_NVAR(&_2$$3);
			zephir_array_fetch_string(&_2$$3, &definition, SL("type"), PH_NOISY, "phalcon/Forms/Form.zep", 835);
			zephir_cast_to_string(&_3$$3, &_2$$3);
			ZEPHIR_INIT_NVAR(&type);
			zephir_fast_strtolower(&type, &_3$$3);
			ZEPHIR_OBS_NVAR(&_4$$3);
			zephir_array_fetch_string(&_4$$3, &definition, SL("name"), PH_NOISY, "phalcon/Forms/Form.zep", 836);
			zephir_cast_to_string(&_5$$3, &_4$$3);
			ZEPHIR_CPY_WRT(&name, &_5$$3);
			if (zephir_array_isset_value_string(&definition, SL("attributes"))) {
				ZEPHIR_OBS_NVAR(&_6$$3);
				zephir_array_fetch_string(&_6$$3, &definition, SL("attributes"), PH_NOISY, "phalcon/Forms/Form.zep", 837);
				zephir_get_arrval(&_7$$3, &_6$$3);
				ZEPHIR_CPY_WRT(&attributes, &_7$$3);
			} else {
				ZEPHIR_INIT_NVAR(&attributes);
				array_init(&attributes);
			}
			if (zephir_array_isset_value_string(&definition, SL("options"))) {
				ZEPHIR_OBS_NVAR(&_8$$3);
				zephir_array_fetch_string(&_8$$3, &definition, SL("options"), PH_NOISY, "phalcon/Forms/Form.zep", 838);
				zephir_get_arrval(&_9$$3, &_8$$3);
				ZEPHIR_CPY_WRT(&options, &_9$$3);
			} else {
				ZEPHIR_INIT_NVAR(&options);
				array_init(&options);
			}
			ZEPHIR_CALL_METHOD(&factory, locator, "getelement", &_10, 0, &type);
			zephir_check_call_status();
			ZEPHIR_CALL_ZVAL_FUNCTION(&element, &factory, NULL, 0, &name, &options, &attributes);
			zephir_check_call_status();
			_11$$3 = zephir_array_isset_value_string(&definition, SL("label"));
			if (_11$$3) {
				zephir_array_fetch_string(&_12$$3, &definition, SL("label"), PH_NOISY | PH_READONLY, "phalcon/Forms/Form.zep", 842);
				_11$$3 = !(ZEPHIR_IS_EMPTY(&_12$$3));
			}
			if (_11$$3) {
				ZEPHIR_OBS_NVAR(&_13$$4);
				zephir_array_fetch_string(&_13$$4, &definition, SL("label"), PH_NOISY, "phalcon/Forms/Form.zep", 843);
				zephir_cast_to_string(&_14$$4, &_13$$4);
				ZEPHIR_CALL_METHOD(NULL, &element, "setlabel", NULL, 0, &_14$$4);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_NVAR(&_15$$3);
			ZVAL_STRING(&_15$$3, "default");
			if (zephir_array_key_exists(&definition, &_15$$3)) {
				zephir_array_fetch_string(&_16$$5, &definition, SL("default"), PH_NOISY | PH_READONLY, "phalcon/Forms/Form.zep", 847);
				ZEPHIR_CALL_METHOD(NULL, &element, "setdefault", NULL, 0, &_16$$5);
				zephir_check_call_status();
			}
			_17$$3 = zephir_array_isset_value_string(&definition, SL("filters"));
			if (_17$$3) {
				zephir_array_fetch_string(&_18$$3, &definition, SL("filters"), PH_NOISY | PH_READONLY, "phalcon/Forms/Form.zep", 850);
				_17$$3 = !(ZEPHIR_IS_EMPTY(&_18$$3));
			}
			if (_17$$3) {
				zephir_array_fetch_string(&_19$$6, &definition, SL("filters"), PH_NOISY | PH_READONLY, "phalcon/Forms/Form.zep", 851);
				ZEPHIR_CALL_METHOD(NULL, &element, "setfilters", NULL, 0, &_19$$6);
				zephir_check_call_status();
			}
			_20$$3 = zephir_array_isset_value_string(&definition, SL("validators"));
			if (_20$$3) {
				zephir_array_fetch_string(&_21$$3, &definition, SL("validators"), PH_NOISY | PH_READONLY, "phalcon/Forms/Form.zep", 854);
				_20$$3 = !(ZEPHIR_IS_EMPTY(&_21$$3));
			}
			if (_20$$3) {
				zephir_array_fetch_string(&_22$$7, &definition, SL("validators"), PH_NOISY | PH_READONLY, "phalcon/Forms/Form.zep", 855);
				ZEPHIR_CALL_METHOD(NULL, &element, "addvalidators", NULL, 0, &_22$$7);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", &_23, 0, &element);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		_25 = 1;
		while (1) {
			if (_25) {
				_25 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_24, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_24)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&definition, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&_26$$8);
				zephir_array_fetch_string(&_26$$8, &definition, SL("type"), PH_NOISY, "phalcon/Forms/Form.zep", 835);
				zephir_cast_to_string(&_27$$8, &_26$$8);
				ZEPHIR_INIT_NVAR(&type);
				zephir_fast_strtolower(&type, &_27$$8);
				ZEPHIR_OBS_NVAR(&_28$$8);
				zephir_array_fetch_string(&_28$$8, &definition, SL("name"), PH_NOISY, "phalcon/Forms/Form.zep", 836);
				zephir_cast_to_string(&_29$$8, &_28$$8);
				ZEPHIR_CPY_WRT(&name, &_29$$8);
				if (zephir_array_isset_value_string(&definition, SL("attributes"))) {
					ZEPHIR_OBS_NVAR(&_30$$8);
					zephir_array_fetch_string(&_30$$8, &definition, SL("attributes"), PH_NOISY, "phalcon/Forms/Form.zep", 837);
					zephir_get_arrval(&_31$$8, &_30$$8);
					ZEPHIR_CPY_WRT(&attributes, &_31$$8);
				} else {
					ZEPHIR_INIT_NVAR(&attributes);
					array_init(&attributes);
				}
				if (zephir_array_isset_value_string(&definition, SL("options"))) {
					ZEPHIR_OBS_NVAR(&_32$$8);
					zephir_array_fetch_string(&_32$$8, &definition, SL("options"), PH_NOISY, "phalcon/Forms/Form.zep", 838);
					zephir_get_arrval(&_33$$8, &_32$$8);
					ZEPHIR_CPY_WRT(&options, &_33$$8);
				} else {
					ZEPHIR_INIT_NVAR(&options);
					array_init(&options);
				}
				ZEPHIR_CALL_METHOD(&factory, locator, "getelement", &_10, 0, &type);
				zephir_check_call_status();
				ZEPHIR_CALL_ZVAL_FUNCTION(&element, &factory, NULL, 0, &name, &options, &attributes);
				zephir_check_call_status();
				_34$$8 = zephir_array_isset_value_string(&definition, SL("label"));
				if (_34$$8) {
					zephir_array_fetch_string(&_35$$8, &definition, SL("label"), PH_NOISY | PH_READONLY, "phalcon/Forms/Form.zep", 842);
					_34$$8 = !(ZEPHIR_IS_EMPTY(&_35$$8));
				}
				if (_34$$8) {
					ZEPHIR_OBS_NVAR(&_36$$9);
					zephir_array_fetch_string(&_36$$9, &definition, SL("label"), PH_NOISY, "phalcon/Forms/Form.zep", 843);
					zephir_cast_to_string(&_37$$9, &_36$$9);
					ZEPHIR_CALL_METHOD(NULL, &element, "setlabel", NULL, 0, &_37$$9);
					zephir_check_call_status();
				}
				ZEPHIR_INIT_NVAR(&_38$$8);
				ZVAL_STRING(&_38$$8, "default");
				if (zephir_array_key_exists(&definition, &_38$$8)) {
					zephir_array_fetch_string(&_39$$10, &definition, SL("default"), PH_NOISY | PH_READONLY, "phalcon/Forms/Form.zep", 847);
					ZEPHIR_CALL_METHOD(NULL, &element, "setdefault", NULL, 0, &_39$$10);
					zephir_check_call_status();
				}
				_40$$8 = zephir_array_isset_value_string(&definition, SL("filters"));
				if (_40$$8) {
					zephir_array_fetch_string(&_41$$8, &definition, SL("filters"), PH_NOISY | PH_READONLY, "phalcon/Forms/Form.zep", 850);
					_40$$8 = !(ZEPHIR_IS_EMPTY(&_41$$8));
				}
				if (_40$$8) {
					zephir_array_fetch_string(&_42$$11, &definition, SL("filters"), PH_NOISY | PH_READONLY, "phalcon/Forms/Form.zep", 851);
					ZEPHIR_CALL_METHOD(NULL, &element, "setfilters", NULL, 0, &_42$$11);
					zephir_check_call_status();
				}
				_43$$8 = zephir_array_isset_value_string(&definition, SL("validators"));
				if (_43$$8) {
					zephir_array_fetch_string(&_44$$8, &definition, SL("validators"), PH_NOISY | PH_READONLY, "phalcon/Forms/Form.zep", 854);
					_43$$8 = !(ZEPHIR_IS_EMPTY(&_44$$8));
				}
				if (_43$$8) {
					zephir_array_fetch_string(&_45$$12, &definition, SL("validators"), PH_NOISY | PH_READONLY, "phalcon/Forms/Form.zep", 855);
					ZEPHIR_CALL_METHOD(NULL, &element, "addvalidators", NULL, 0, &_45$$12);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", &_23, 0, &element);
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
		object_init_ex(&_1$$3, phalcon_forms_exceptions_elementnotinform_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0, &name_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Forms/Form.zep", 872);
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
	zval name_zv, *attributes_param = NULL, element, _0, _1$$3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&attributes);
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
		object_init_ex(&_1$$3, phalcon_forms_exceptions_elementnotinform_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0, &name_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Forms/Form.zep", 894);
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
	zval name_zv, _0, _2, _1$$3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_value(&_0, &name_zv)) {
		zephir_unset_property_array(this_ptr, ZEND_STRL("elements"), &name_zv);
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&_1$$3, &name_zv, PH_SEPARATE);
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	zephir_update_property_zval(this_ptr, ZEND_STRL("elementsIndexed"), &_2);
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
	ZEPHIR_CALL_FUNCTION(&_1, "array_values", NULL, 28, &_0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("elementsIndexed"), &_1);
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets the form's action
 *
 * @return static
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
	RETURN_BOOL(zephir_array_isset_value(&_0, &_1));
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

