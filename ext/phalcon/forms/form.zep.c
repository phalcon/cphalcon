
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
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/main.h"
#include "kernel/concat.h"
#include "kernel/iterator.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * This component allows to build forms using an object-oriented interface
 *
 * @phpstan-import-type forms_data from FormsTypes
 * @phpstan-import-type forms_elements from FormsTypes
 * @phpstan-import-type forms_elements_indexed from FormsTypes
 * @phpstan-import-type forms_options from FormsTypes
 * @phpstan-import-type forms_schema_definition from FormsTypes
 * @phpstan-import-type forms_whitelist from FormsTypes
 * @phpstan-import-type html_attributes from HtmlTypes
 *
 * @implements Iterator<int, ElementInterface>
 */
ZEPHIR_INIT_CLASS(Phalcon_Forms_Form)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Forms, Form, phalcon, forms_form, phalcon_di_injectable_ce, phalcon_forms_form_method_entry, 0);

	/**
	 * @var AttributesInterface|null
	 */
	zend_declare_property_null(phalcon_forms_form_ce, SL("attributes"), ZEND_ACC_PROTECTED);
	/**
	 * @phpstan-var forms_data
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_forms_form_ce, SL("data"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @phpstan-var forms_elements
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_forms_form_ce, SL("elements"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @phpstan-var forms_elements_indexed
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_forms_form_ce, SL("elementsIndexed"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @var object|null
	 */
	zend_declare_property_null(phalcon_forms_form_ce, SL("entity"), ZEND_ACC_PROTECTED);
	/**
	 * @phpstan-var forms_data
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_forms_form_ce, SL("filteredData"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_forms_form_ce, SL("messages"), &_zc0, ZEND_ACC_PROTECTED, 0, SL("Phalcon\\Messages\\Messages"));
	}

	/**
	 * @phpstan-var forms_options
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_forms_form_ce, SL("options"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_LONG(&_zc0, 0);
		zephir_declare_typed_property(phalcon_forms_form_ce, SL("position"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_LONG, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_forms_form_ce, SL("tagFactory"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_NULL, SL("Phalcon\\Html\\TagFactory"));
	}

	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_forms_form_ce, SL("validation"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_NULL, SL("Phalcon\\Filter\\Validation\\ValidationInterface"));
	}

	/**
	 * @phpstan-var forms_whitelist
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_forms_form_ce, SL("whitelist"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	zend_class_implements(phalcon_forms_form_ce, 1, zend_ce_countable);
	zend_class_implements(phalcon_forms_form_ce, 1, zend_ce_iterator);
	zend_class_implements(phalcon_forms_form_ce, 1, phalcon_html_attributes_attributesinterface_ce);
	return SUCCESS;
}

/**
 * Phalcon\Forms\Form constructor
 *
 * @phpstan-param forms_options $userOptions
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("entity", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("options", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("attributes", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("messages", 8, 1);
	}

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
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Forms/Form.zep", 95);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 801, entity);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 802, &userOptions);
	ZEPHIR_INIT_VAR(&_2);
	object_init_ex(&_2, phalcon_html_attributes_ce);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_2, "__construct", &_zephir_call_cache[1]);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 803, &_2);
	ZEPHIR_INIT_VAR(&_3);
	object_init_ex(&_3, phalcon_messages_messages_ce);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_3, "__construct", &_zephir_call_cache[2]);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 804, &_3);
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("initialize")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "initialize", &_zephir_call_cache[3], entity, &userOptions);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Adds an element to the form
 */
PHP_METHOD(Phalcon_Forms_Form, add)
{
	zend_ulong _9$$5;
	zval elements;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool type, _0, _3, _4, _13$$5, _11$$6, _14$$11;
	zend_string *position = NULL, *_10$$5;
	zval *element, element_sub, position_zv, *type_param = NULL, name, key, value, _1, _2$$3, _5$$5, *_6$$5, _7$$5, *_8$$5, _12$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&position_zv);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&elements);
	ZEND_TLS zephir_method_cache _zephir_call_cache[8];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("tagFactory", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("elements", 8, 1);
	}

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
	ZEPHIR_CALL_METHOD_CACHED(&name, element, "getName", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, element, "setForm", &_zephir_call_cache[1], this_ptr);
	zephir_check_call_status();
	_0 = (zephir_method_exists_ex(element, ZEND_STRL("settagfactory")) == SUCCESS);
	if (_0) {
		zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 805, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_0 = Z_TYPE_P(&_1) != IS_NULL;
	}
	if (_0) {
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_0, 805, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, element, "setTagFactory", &_zephir_call_cache[2], &_2$$3);
		zephir_check_call_status();
	}
	_3 = Z_TYPE_P(&position_zv) == IS_NULL;
	if (!(_3)) {
		_4 = zephir_isempty_property_fast(this_ptr, _zephir_prop_1);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_3 = _4;
	}
	if (_3) {
		zephir_update_property_array(this_ptr, SL("elements"), &name, element);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_INIT_VAR(&elements);
		array_init(&elements);
		zephir_read_property_cached(&_5$$5, this_ptr, _zephir_prop_1, 806, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (Z_TYPE_P(&_5$$5) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_7$$5);
			zephir_string_to_char_array(&_7$$5, &_5$$5);
			_6$$5 = &_7$$5;
		} else {
			_6$$5 = &_5$$5;
		}
		zephir_is_iterable(_6$$5, 0, "phalcon/Forms/Form.zep", 177);
		if (Z_TYPE_P(_6$$5) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_6$$5), _9$$5, _10$$5, _8$$5)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_10$$5 != NULL) { 
					ZVAL_STR_COPY(&key, _10$$5);
				} else {
					ZVAL_LONG(&key, _9$$5);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _8$$5);
				_11$$6 = ZEPHIR_IS_EQUAL(&key, &position_zv);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_11$$6) {
					if (type) {
						zephir_array_update_zval(&elements, &name, element, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_update_zval(&elements, &key, &value, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						zephir_array_update_zval(&elements, &key, &value, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_update_zval(&elements, &name, element, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				} else {
					zephir_array_update_zval(&elements, &key, &value, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _6$$5, "rewind", &_zephir_call_cache[3]);
			zephir_check_call_status();
			_13$$5 = 1;
			while (1) {
				if (_13$$5) {
					_13$$5 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _6$$5, "next", &_zephir_call_cache[4]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_12$$5, _6$$5, "valid", &_zephir_call_cache[5]);
				zephir_check_call_status();
				if (!zend_is_true(&_12$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&key, _6$$5, "key", &_zephir_call_cache[6]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&value, _6$$5, "current", &_zephir_call_cache[7]);
				zephir_check_call_status();
					_14$$11 = ZEPHIR_IS_EQUAL(&key, &position_zv);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_14$$11) {
						if (type) {
							zephir_array_update_zval(&elements, &name, element, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_zval(&elements, &key, &value, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} else {
							zephir_array_update_zval(&elements, &key, &value, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_zval(&elements, &name, element, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					} else {
						zephir_array_update_zval(&elements, &key, &value, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 806, &elements);
	}
	RETURN_THIS();
}

/**
 * Binds data to the entity
 *
 * @phpstan-param forms_data      $data
 * @param object|null             $entity
 * @phpstan-param forms_whitelist $whitelist
 */
PHP_METHOD(Phalcon_Forms_Form, bind)
{
	zend_string *_10, *_25;
	zend_ulong _9, _24;
	zend_bool _0, _2, _17, _49, _11$$6, _14$$7, _18$$10, _21$$11, _27$$14, _38$$14, _39$$14, _35$$15, _51$$29, _62$$29, _63$$29, _59$$30;
	zval method;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_47 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *entity = NULL, entity_sub, *whitelist_param = NULL, __$null, filter, key, value, element, candidate, filters, container, filteredValue, elementName, dataKey, _3, _5, *_6, _7, *_8, _16, *_23, _48, _1$$3, _4$$5, _12$$6, _13$$7, _15$$9, _19$$10, _20$$11, _22$$13, _26$$14, _28$$15, *_29$$15, _30$$15, *_31$$15, _34$$15, _32$$16, _33$$16, _36$$18, _37$$18, _40$$23, _41$$23, _42$$25, _43$$25, _44$$25, _45$$25, _46$$25, _50$$29, _52$$30, *_53$$30, _54$$30, *_55$$30, _58$$30, _56$$31, _57$$31, _60$$33, _61$$33, _64$$38, _65$$38, _66$$40, _67$$40, _68$$40, _69$$40, _70$$40;
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
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_48);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_22$$13);
	ZVAL_UNDEF(&_26$$14);
	ZVAL_UNDEF(&_28$$15);
	ZVAL_UNDEF(&_30$$15);
	ZVAL_UNDEF(&_34$$15);
	ZVAL_UNDEF(&_32$$16);
	ZVAL_UNDEF(&_33$$16);
	ZVAL_UNDEF(&_36$$18);
	ZVAL_UNDEF(&_37$$18);
	ZVAL_UNDEF(&_40$$23);
	ZVAL_UNDEF(&_41$$23);
	ZVAL_UNDEF(&_42$$25);
	ZVAL_UNDEF(&_43$$25);
	ZVAL_UNDEF(&_44$$25);
	ZVAL_UNDEF(&_45$$25);
	ZVAL_UNDEF(&_46$$25);
	ZVAL_UNDEF(&_50$$29);
	ZVAL_UNDEF(&_52$$30);
	ZVAL_UNDEF(&_54$$30);
	ZVAL_UNDEF(&_58$$30);
	ZVAL_UNDEF(&_56$$31);
	ZVAL_UNDEF(&_57$$31);
	ZVAL_UNDEF(&_60$$33);
	ZVAL_UNDEF(&_61$$33);
	ZVAL_UNDEF(&_64$$38);
	ZVAL_UNDEF(&_65$$38);
	ZVAL_UNDEF(&_66$$40);
	ZVAL_UNDEF(&_67$$40);
	ZVAL_UNDEF(&_68$$40);
	ZVAL_UNDEF(&_69$$40);
	ZVAL_UNDEF(&_70$$40);
	ZVAL_UNDEF(&method);
	ZEND_TLS zephir_method_cache _zephir_call_cache[41];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("elements", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("whitelist", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("data", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("filteredData", 12, 1);
	}

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
	zephir_get_arrval(&data, data_param);
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
	_0 = zephir_isempty_property_fast(this_ptr, _zephir_prop_0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_forms_exceptions_noformelements_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Forms/Form.zep", 201);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_2 = (zephir_method_exists_ex(this_ptr, ZEND_STRL("beforebind")) == SUCCESS);
	if (_2) {
		ZEPHIR_CALL_METHOD_CACHED(&_3, this_ptr, "beforeBind", &_zephir_call_cache[1], &data, entity);
		zephir_check_call_status();
		_2 = ZEPHIR_IS_FALSE_IDENTICAL(&_3);
	}
	if (_2) {
		RETURN_THIS();
	}
	if (ZEPHIR_IS_EMPTY(&whitelist)) {
		zephir_read_property_cached(&_4$$5, this_ptr, _zephir_prop_1, 807, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (UNEXPECTED(Z_TYPE_P(&_4$$5) != IS_ARRAY)) {
			zephir_throw_variable_type_error(&_4$$5, "whitelist", "array");
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&whitelist, &_4$$5);
	}
	zephir_read_property_cached(&_5, this_ptr, _zephir_prop_0, 806, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_5) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_7);
		zephir_string_to_char_array(&_7, &_5);
		_6 = &_7;
	} else {
		_6 = &_5;
	}
	zephir_is_iterable(_6, 0, "phalcon/Forms/Form.zep", 234);
	if (Z_TYPE_P(_6) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_6), _9, _10, _8)
		{
			ZEPHIR_INIT_NVAR(&elementName);
			if (_10 != NULL) { 
				ZVAL_STR_COPY(&elementName, _10);
			} else {
				ZVAL_LONG(&elementName, _9);
			}
			ZEPHIR_INIT_NVAR(&element);
			ZVAL_COPY(&element, _8);
			_11$$6 = zephir_instance_of_ev(&element, phalcon_forms_element_check_ce);
			if (_11$$6) {
				ZEPHIR_CALL_METHOD_CACHED(&_12$$6, &element, "hasUncheckedValue", &_zephir_call_cache[2]);
				zephir_check_call_status();
				_11$$6 = zephir_is_true(&_12$$6);
			}
			if (_11$$6) {
				ZEPHIR_INIT_NVAR(&_13$$7);
				ZVAL_STRING(&_13$$7, "name");
				ZEPHIR_CALL_METHOD_CACHED(&dataKey, &element, "getAttribute", &_zephir_call_cache[3], &_13$$7);
				zephir_check_call_status();
				if (Z_TYPE_P(&dataKey) == IS_NULL) {
					ZEPHIR_CPY_WRT(&dataKey, &elementName);
				}
				_14$$7 = zephir_array_key_exists(&data, &dataKey);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_14$$7)) {
					ZEPHIR_CALL_METHOD_CACHED(&_15$$9, &element, "getUncheckedValue", &_zephir_call_cache[4]);
					zephir_check_call_status();
					zephir_array_update_zval(&data, &dataKey, &_15$$9, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _6, "rewind", &_zephir_call_cache[5]);
		zephir_check_call_status();
		_17 = 1;
		while (1) {
			if (_17) {
				_17 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _6, "next", &_zephir_call_cache[6]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_16, _6, "valid", &_zephir_call_cache[7]);
			zephir_check_call_status();
			if (!zend_is_true(&_16)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&elementName, _6, "key", &_zephir_call_cache[8]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&element, _6, "current", &_zephir_call_cache[9]);
			zephir_check_call_status();
				_18$$10 = zephir_instance_of_ev(&element, phalcon_forms_element_check_ce);
				if (_18$$10) {
					ZEPHIR_CALL_METHOD_CACHED(&_19$$10, &element, "hasUncheckedValue", &_zephir_call_cache[10]);
					zephir_check_call_status();
					_18$$10 = zephir_is_true(&_19$$10);
				}
				if (_18$$10) {
					ZEPHIR_INIT_NVAR(&_20$$11);
					ZVAL_STRING(&_20$$11, "name");
					ZEPHIR_CALL_METHOD_CACHED(&dataKey, &element, "getAttribute", &_zephir_call_cache[11], &_20$$11);
					zephir_check_call_status();
					if (Z_TYPE_P(&dataKey) == IS_NULL) {
						ZEPHIR_CPY_WRT(&dataKey, &elementName);
					}
					_21$$11 = zephir_array_key_exists(&data, &dataKey);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_21$$11)) {
						ZEPHIR_CALL_METHOD_CACHED(&_22$$13, &element, "getUncheckedValue", &_zephir_call_cache[12]);
						zephir_check_call_status();
						zephir_array_update_zval(&data, &dataKey, &_22$$13, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
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
	zephir_is_iterable(&data, 0, "phalcon/Forms/Form.zep", 312);
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _24, _25, _23)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_25 != NULL) { 
				ZVAL_STR_COPY(&key, _25);
			} else {
				ZVAL_LONG(&key, _24);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _23);
			ZEPHIR_OBS_NVAR(&element);
			zephir_read_property_cached(&_26$$14, this_ptr, _zephir_prop_0, 806, PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_27$$14 = zephir_array_isset_fetch(&element, &_26$$14, &key, 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (!(_27$$14)) {
				ZEPHIR_INIT_NVAR(&element);
				ZVAL_NULL(&element);
				zephir_read_property_cached(&_28$$15, this_ptr, _zephir_prop_0, 806, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&_28$$15) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_30$$15);
					zephir_string_to_char_array(&_30$$15, &_28$$15);
					_29$$15 = &_30$$15;
				} else {
					_29$$15 = &_28$$15;
				}
				zephir_is_iterable(_29$$15, 0, "phalcon/Forms/Form.zep", 252);
				if (Z_TYPE_P(_29$$15) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_29$$15), _31$$15)
					{
						ZEPHIR_INIT_NVAR(&candidate);
						ZVAL_COPY(&candidate, _31$$15);
						ZEPHIR_INIT_NVAR(&_33$$16);
						ZVAL_STRING(&_33$$16, "name");
						ZEPHIR_CALL_METHOD_CACHED(&_32$$16, &candidate, "getAttribute", &_zephir_call_cache[13], &_33$$16);
						zephir_check_call_status();
						if (ZEPHIR_IS_IDENTICAL(&_32$$16, &key)) {
							ZEPHIR_CPY_WRT(&element, &candidate);
							break;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _29$$15, "rewind", &_zephir_call_cache[14]);
					zephir_check_call_status();
					_35$$15 = 1;
					while (1) {
						if (_35$$15) {
							_35$$15 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _29$$15, "next", &_zephir_call_cache[15]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_34$$15, _29$$15, "valid", &_zephir_call_cache[16]);
						zephir_check_call_status();
						if (!zend_is_true(&_34$$15)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&candidate, _29$$15, "current", &_zephir_call_cache[17]);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_37$$18);
							ZVAL_STRING(&_37$$18, "name");
							ZEPHIR_CALL_METHOD_CACHED(&_36$$18, &candidate, "getAttribute", &_zephir_call_cache[18], &_37$$18);
							zephir_check_call_status();
							if (ZEPHIR_IS_IDENTICAL(&_36$$18, &key)) {
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
			_38$$14 = !(ZEPHIR_IS_EMPTY(&whitelist));
			if (_38$$14) {
				_39$$14 = zephir_fast_in_array(&key, &whitelist);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_38$$14 = !(_39$$14);
			}
			if (_38$$14) {
				continue;
			}
			ZEPHIR_CALL_METHOD_CACHED(&filters, &element, "getFilters", &_zephir_call_cache[19]);
			zephir_check_call_status();
			if (zephir_is_true(&filters)) {
				if (Z_TYPE_P(&filter) != IS_OBJECT) {
					ZEPHIR_CALL_METHOD_CACHED(&container, this_ptr, "getDI", &_zephir_call_cache[20]);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_41$$23);
					ZVAL_STRING(&_41$$23, "filter");
					ZEPHIR_CALL_METHOD_CACHED(&_40$$23, &container, "getShared", &_zephir_call_cache[21], &_41$$23);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&filter, &_40$$23);
				}
				ZEPHIR_CALL_METHOD_CACHED(&filteredValue, &filter, "sanitize", &_zephir_call_cache[22], &value, &filters);
				zephir_check_call_status();
			} else {
				ZEPHIR_CPY_WRT(&filteredValue, &value);
			}
			zephir_array_update_zval(&assignData, &key, &value, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_zval(&filteredData, &key, &filteredValue, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(entity) != IS_NULL) {
				ZEPHIR_INIT_NVAR(&_42$$25);
				zephir_camelize(&_42$$25, &key, NULL );
				ZEPHIR_INIT_NVAR(&_43$$25);
				ZEPHIR_CONCAT_SV(&_43$$25, "set", &_42$$25);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_get_strval(&method, &_43$$25);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if ((zephir_method_exists(entity, &method)  == SUCCESS)) {
					ZEPHIR_CALL_METHOD_ZVAL(NULL, entity, &method, NULL, 0, &filteredValue);
					zephir_check_call_status();
					continue;
				}
				ZEPHIR_INIT_NVAR(&_45$$25);
				ZVAL_STRING(&_45$$25, "form.strict_entity_property_check");
				ZEPHIR_CALL_CE_STATIC_CACHED(&_44$$25, phalcon_support_settings_ce, "get", &_zephir_call_cache[23], &_45$$25);
				zephir_check_call_status();
				if (!zephir_is_true(&_44$$25)) {
					zephir_update_property_zval_zval(entity, &key, &filteredValue);
					continue;
				}
				ZEPHIR_CALL_FUNCTION(&_46$$25, "property_exists", &_47, 7, entity, &key);
				zephir_check_call_status();
				if (zephir_is_true(&_46$$25)) {
					zephir_update_property_zval_zval(entity, &key, &filteredValue);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &data, "rewind", &_zephir_call_cache[24]);
		zephir_check_call_status();
		_49 = 1;
		while (1) {
			if (_49) {
				_49 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &data, "next", &_zephir_call_cache[25]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_48, &data, "valid", &_zephir_call_cache[26]);
			zephir_check_call_status();
			if (!zend_is_true(&_48)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&key, &data, "key", &_zephir_call_cache[27]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&value, &data, "current", &_zephir_call_cache[28]);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&element);
				zephir_read_property_cached(&_50$$29, this_ptr, _zephir_prop_0, 806, PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_51$$29 = zephir_array_isset_fetch(&element, &_50$$29, &key, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_51$$29)) {
					ZEPHIR_INIT_NVAR(&element);
					ZVAL_NULL(&element);
					zephir_read_property_cached(&_52$$30, this_ptr, _zephir_prop_0, 806, PH_NOISY_CC | PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (Z_TYPE_P(&_52$$30) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_54$$30);
						zephir_string_to_char_array(&_54$$30, &_52$$30);
						_53$$30 = &_54$$30;
					} else {
						_53$$30 = &_52$$30;
					}
					zephir_is_iterable(_53$$30, 0, "phalcon/Forms/Form.zep", 252);
					if (Z_TYPE_P(_53$$30) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_53$$30), _55$$30)
						{
							ZEPHIR_INIT_NVAR(&candidate);
							ZVAL_COPY(&candidate, _55$$30);
							ZEPHIR_INIT_NVAR(&_57$$31);
							ZVAL_STRING(&_57$$31, "name");
							ZEPHIR_CALL_METHOD_CACHED(&_56$$31, &candidate, "getAttribute", &_zephir_call_cache[29], &_57$$31);
							zephir_check_call_status();
							if (ZEPHIR_IS_IDENTICAL(&_56$$31, &key)) {
								ZEPHIR_CPY_WRT(&element, &candidate);
								break;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _53$$30, "rewind", &_zephir_call_cache[30]);
						zephir_check_call_status();
						_59$$30 = 1;
						while (1) {
							if (_59$$30) {
								_59$$30 = 0;
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _53$$30, "next", &_zephir_call_cache[31]);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD_CACHED(&_58$$30, _53$$30, "valid", &_zephir_call_cache[32]);
							zephir_check_call_status();
							if (!zend_is_true(&_58$$30)) {
								break;
							}
							ZEPHIR_CALL_METHOD_CACHED(&candidate, _53$$30, "current", &_zephir_call_cache[33]);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_61$$33);
								ZVAL_STRING(&_61$$33, "name");
								ZEPHIR_CALL_METHOD_CACHED(&_60$$33, &candidate, "getAttribute", &_zephir_call_cache[34], &_61$$33);
								zephir_check_call_status();
								if (ZEPHIR_IS_IDENTICAL(&_60$$33, &key)) {
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
				_62$$29 = !(ZEPHIR_IS_EMPTY(&whitelist));
				if (_62$$29) {
					_63$$29 = zephir_fast_in_array(&key, &whitelist);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_62$$29 = !(_63$$29);
				}
				if (_62$$29) {
					continue;
				}
				ZEPHIR_CALL_METHOD_CACHED(&filters, &element, "getFilters", &_zephir_call_cache[35]);
				zephir_check_call_status();
				if (zephir_is_true(&filters)) {
					if (Z_TYPE_P(&filter) != IS_OBJECT) {
						ZEPHIR_CALL_METHOD_CACHED(&container, this_ptr, "getDI", &_zephir_call_cache[36]);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_65$$38);
						ZVAL_STRING(&_65$$38, "filter");
						ZEPHIR_CALL_METHOD_CACHED(&_64$$38, &container, "getShared", &_zephir_call_cache[37], &_65$$38);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&filter, &_64$$38);
					}
					ZEPHIR_CALL_METHOD_CACHED(&filteredValue, &filter, "sanitize", &_zephir_call_cache[38], &value, &filters);
					zephir_check_call_status();
				} else {
					ZEPHIR_CPY_WRT(&filteredValue, &value);
				}
				zephir_array_update_zval(&assignData, &key, &value, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&filteredData, &key, &filteredValue, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(entity) != IS_NULL) {
					ZEPHIR_INIT_NVAR(&_66$$40);
					zephir_camelize(&_66$$40, &key, NULL );
					ZEPHIR_INIT_NVAR(&_67$$40);
					ZEPHIR_CONCAT_SV(&_67$$40, "set", &_66$$40);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_get_strval(&method, &_67$$40);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if ((zephir_method_exists(entity, &method)  == SUCCESS)) {
						ZEPHIR_CALL_METHOD_ZVAL(NULL, entity, &method, NULL, 0, &filteredValue);
						zephir_check_call_status();
						continue;
					}
					ZEPHIR_INIT_NVAR(&_69$$40);
					ZVAL_STRING(&_69$$40, "form.strict_entity_property_check");
					ZEPHIR_CALL_CE_STATIC_CACHED(&_68$$40, phalcon_support_settings_ce, "get", &_zephir_call_cache[39], &_69$$40);
					zephir_check_call_status();
					if (!zephir_is_true(&_68$$40)) {
						zephir_update_property_zval_zval(entity, &key, &filteredValue);
						continue;
					}
					ZEPHIR_CALL_FUNCTION(&_70$$40, "property_exists", &_47, 7, entity, &key);
					zephir_check_call_status();
					if (zephir_is_true(&_70$$40)) {
						zephir_update_property_zval_zval(entity, &key, &filteredValue);
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 808, &assignData);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 809, &filteredData);
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("afterbind")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "afterBind", &_zephir_call_cache[40], entity);
		zephir_check_call_status();
	}
	RETURN_THIS();
}

/**
 * Clears every element in the form to its default value
 *
 * @phpstan-param array<array-key, string>|string|null $fields
 */
PHP_METHOD(Phalcon_Forms_Form, clear)
{
	zend_bool _7$$3, _19$$6, _14$$8, _15$$8, _20$$11, _21$$11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fields = NULL, fields_sub, __$null, elements, element, data, field, _0, *_1$$3, _2$$3, *_3$$3, _6$$3, _4$$4, _5$$4, _8$$5, _9$$5, _10$$7, *_11$$6, _12$$6, *_13$$6, _18$$6, _16$$10, _17$$10, _22$$13, _23$$13;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&elements);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_22$$13);
	ZVAL_UNDEF(&_23$$13);
	ZEND_TLS zephir_method_cache _zephir_call_cache[16];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("data", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("elements", 8, 1);
	}

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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 808, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&data, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 806, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&elements, &_0);
	if (Z_TYPE_P(fields) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&data);
		array_init(&data);
		if (Z_TYPE_P(&elements) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_2$$3);
			zephir_string_to_char_array(&_2$$3, &elements);
			_1$$3 = &_2$$3;
		} else {
			_1$$3 = &elements;
		}
		zephir_is_iterable(_1$$3, 0, "phalcon/Forms/Form.zep", 348);
		if (Z_TYPE_P(_1$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1$$3), _3$$3)
			{
				ZEPHIR_INIT_NVAR(&element);
				ZVAL_COPY(&element, _3$$3);
				ZEPHIR_CALL_METHOD_CACHED(&_4$$4, &element, "getName", &_zephir_call_cache[0]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_5$$4, &element, "getDefault", &_zephir_call_cache[1]);
				zephir_check_call_status();
				zephir_array_update_zval(&data, &_4$$4, &_5$$4, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _1$$3, "rewind", &_zephir_call_cache[2]);
			zephir_check_call_status();
			_7$$3 = 1;
			while (1) {
				if (_7$$3) {
					_7$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _1$$3, "next", &_zephir_call_cache[3]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_6$$3, _1$$3, "valid", &_zephir_call_cache[4]);
				zephir_check_call_status();
				if (!zend_is_true(&_6$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&element, _1$$3, "current", &_zephir_call_cache[5]);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&_8$$5, &element, "getName", &_zephir_call_cache[6]);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&_9$$5, &element, "getDefault", &_zephir_call_cache[7]);
					zephir_check_call_status();
					zephir_array_update_zval(&data, &_8$$5, &_9$$5, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&element);
	} else {
		if (Z_TYPE_P(fields) != IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_10$$7);
			zephir_create_array(&_10$$7, 1, 0);
			zephir_array_fast_append(&_10$$7, fields);
			ZEPHIR_CPY_WRT(fields, &_10$$7);
		}
		if (Z_TYPE_P(fields) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_12$$6);
			zephir_string_to_char_array(&_12$$6, fields);
			_11$$6 = &_12$$6;
		} else {
			_11$$6 = fields;
		}
		zephir_is_iterable(_11$$6, 0, "phalcon/Forms/Form.zep", 368);
		if (Z_TYPE_P(_11$$6) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_11$$6), _13$$6)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _13$$6);
				_14$$8 = zephir_array_key_exists(&data, &field);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_14$$8) {
					zephir_array_unset(&data, &field, PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				ZEPHIR_OBS_NVAR(&element);
				_15$$8 = zephir_array_isset_fetch(&element, &elements, &field, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_15$$8) {
					ZEPHIR_CALL_METHOD_CACHED(&_16$$10, &element, "getName", &_zephir_call_cache[8]);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&_17$$10, &element, "getDefault", &_zephir_call_cache[9]);
					zephir_check_call_status();
					zephir_array_update_zval(&data, &_16$$10, &_17$$10, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _11$$6, "rewind", &_zephir_call_cache[10]);
			zephir_check_call_status();
			_19$$6 = 1;
			while (1) {
				if (_19$$6) {
					_19$$6 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _11$$6, "next", &_zephir_call_cache[11]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_18$$6, _11$$6, "valid", &_zephir_call_cache[12]);
				zephir_check_call_status();
				if (!zend_is_true(&_18$$6)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&field, _11$$6, "current", &_zephir_call_cache[13]);
				zephir_check_call_status();
					_20$$11 = zephir_array_key_exists(&data, &field);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_20$$11) {
						zephir_array_unset(&data, &field, PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					ZEPHIR_OBS_NVAR(&element);
					_21$$11 = zephir_array_isset_fetch(&element, &elements, &field, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_21$$11) {
						ZEPHIR_CALL_METHOD_CACHED(&_22$$13, &element, "getName", &_zephir_call_cache[14]);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD_CACHED(&_23$$13, &element, "getDefault", &_zephir_call_cache[15]);
						zephir_check_call_status();
						zephir_array_update_zval(&data, &_22$$13, &_23$$13, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
			}
		}
		ZEPHIR_INIT_NVAR(&field);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 808, &data);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("elements", 8, 1);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 806, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	RETURN_LONG(zephir_fast_count_int(&_0));
}

/**
 * Returns the current element in the iterator
 *
 * @psalm-suppress LessSpecificImplementedReturnType
 */
PHP_METHOD(Phalcon_Forms_Form, current)
{
	zend_bool _2;
	zval element, _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("elementsIndexed", 15, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("position", 8, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&element);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 810, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 811, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_2 = zephir_array_isset_fetch(&element, &_0, &_1, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_2)) {
		RETURN_MM_BOOL(0);
	}
	RETURN_CCTOR(&element);
}

/**
 * Returns an element added to the form by its name
 */
PHP_METHOD(Phalcon_Forms_Form, get)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, element, _0, _2$$3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("elements", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_memory_observe(&element);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 806, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1 = zephir_array_isset_fetch(&element, &_0, &name_zv, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_1))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_forms_exceptions_elementnotinform_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_2$$3, "__construct", &_zephir_call_cache[0], &name_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Forms/Form.zep", 407);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "getAttributes", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "action");
	ZEPHIR_CALL_METHOD_CACHED(&_1, &_0, "get", &_zephir_call_cache[1], &_2);
	zephir_check_call_status();
	zephir_cast_to_string(&_3, &_1);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("attributes", 10, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 803, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(Z_TYPE_P(&_0) == IS_NULL)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_html_attributes_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 803, &_1$$3);
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
 * @return object|null
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
	zend_bool _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, filteredData, value, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&filteredData);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("filteredData", 12, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 809, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&filteredData, &_0);
	if (Z_TYPE_P(&filteredData) == IS_ARRAY) {
		zephir_memory_observe(&value);
		_1$$3 = zephir_array_isset_fetch(&value, &filteredData, &name_zv, 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_1$$3) {
			RETURN_CCTOR(&value);
		}
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "getValue", &_zephir_call_cache[0], &name_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns a label for an element
 */
PHP_METHOD(Phalcon_Forms_Form, getLabel)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, element, label, _0, _2$$3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("elements", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_memory_observe(&element);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 806, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1 = zephir_array_isset_fetch(&element, &_0, &name_zv, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_1))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_forms_exceptions_elementnotinform_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_2$$3, "__construct", &_zephir_call_cache[0], &name_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Forms/Form.zep", 480);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&label, &element, "getLabel", &_zephir_call_cache[1]);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "has", &_zephir_call_cache[0], &name_zv);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		object_init_ex(return_value, phalcon_messages_messages_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, return_value, "__construct", &_zephir_call_cache[1]);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD_CACHED(&_1, this_ptr, "get", &_zephir_call_cache[2], &name_zv);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD_CACHED(&_1, "getMessages", &_zephir_call_cache[3]);
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
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval option_zv, *defaultValue = NULL, defaultValue_sub, __$null, value, _0;
	zend_string *option = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option_zv);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("options", 7, 1);
	}

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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 802, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1 = zephir_array_isset_fetch(&value, &_0, &option_zv, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_1)) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	RETURN_CCTOR(&value);
}

/**
 * Returns the options for the element
 *
 * @phpstan-return forms_options
 */
PHP_METHOD(Phalcon_Forms_Form, getUserOptions)
{

	RETURN_MEMBER_TYPED(getThis(), "options", IS_ARRAY);
}

/**
 * return ValidationInterface|null
 */
PHP_METHOD(Phalcon_Forms_Form, getValidation)
{

	RETURN_MEMBER(getThis(), "validation");
}

/**
 * Gets a value from the internal related entity or from the default value
 */
PHP_METHOD(Phalcon_Forms_Form, getValue)
{
	zend_bool _4, _5, _8, _3$$7;
	zval method;
	zval forbidden;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, _POST, __$true, entity, value, data, internalEntity, element, _0, _6, _7, _1$$4, _2$$4;
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
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&forbidden);
	ZVAL_UNDEF(&method);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("entity", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("data", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("elements", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_get_global(&_POST, SL("_POST"));
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 801, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&entity, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 808, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&data, &_0);
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("getcustomvalue")) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "getCustomValue", &_zephir_call_cache[0], &name_zv, &entity, &data);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (Z_TYPE_P(&entity) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_camelize(&_1$$4, &name_zv, NULL );
		ZEPHIR_INIT_VAR(&_2$$4);
		ZEPHIR_CONCAT_SV(&_2$$4, "get", &_1$$4);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_get_strval(&method, &_2$$4);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
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
		_3$$7 = zephir_array_isset_fetch(&value, &data, &name_zv, 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_3$$7) {
			RETURN_CCTOR(&value);
		}
	}
	ZEPHIR_OBS_NVAR(&value);
	_4 = zephir_array_isset_fetch(&value, &_POST, &name_zv, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_4) {
		RETURN_CCTOR(&value);
	}
	ZEPHIR_INIT_VAR(&forbidden);
	zephir_create_array(&forbidden, 14, 0);
	zephir_array_update_string(&forbidden, SL("action"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&forbidden, SL("attributes"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&forbidden, SL("di"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&forbidden, SL("elements"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&forbidden, SL("entity"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&forbidden, SL("eventsmanager"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&forbidden, SL("label"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&forbidden, SL("messages"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&forbidden, SL("messagesfor"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&forbidden, SL("tagfactory"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&forbidden, SL("useroption"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&forbidden, SL("useroptions"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&forbidden, SL("validation"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&forbidden, SL("value"), &__$true, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&internalEntity);
	zephir_fast_strtolower(&internalEntity, &name_zv);
	_5 = zephir_array_isset_value(&forbidden, &internalEntity);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_5) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_6);
	zephir_camelize(&_6, &name_zv, NULL );
	ZEPHIR_INIT_VAR(&_7);
	ZEPHIR_CONCAT_SV(&_7, "get", &_6);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_get_strval(&method, &_7);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if ((zephir_method_exists(this_ptr, &method)  == SUCCESS)) {
		ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, &method, NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_memory_observe(&element);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 806, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_8 = zephir_array_isset_fetch(&element, &_0, &name_zv, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_8) {
		ZEPHIR_RETURN_CALL_METHOD_CACHED(&element, "getDefault", &_zephir_call_cache[1]);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_NULL();
}

/**
 * @phpstan-return forms_whitelist
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
	zend_bool _1;
	zval name_zv, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("elements", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&name_zv, name);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 806, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	_1 = zephir_array_isset_value(&_0, &name_zv);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	RETURN_BOOL(_1);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "getMessagesFor", &_zephir_call_cache[0], &name_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_1, &_0, "count", &_zephir_call_cache[1]);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_GT_LONG(&_1, 0));
}

/**
 * Validates the form
 *
 * @phpstan-param forms_data      $data
 * @phpstan-param object|null     $entity
 * @phpstan-param forms_whitelist $whitelist
 */
PHP_METHOD(Phalcon_Forms_Form, isValid)
{
	zend_object_iterator *_27$$20;
	zend_bool validationStatus = 0, _0, _3, _7, _19, _12$$10, _17$$10, _20$$15, _25$$15;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval whitelist;
	zval *data = NULL, data_sub, *entity = NULL, entity_sub, *whitelist_param = NULL, __$null, messages, element, validators, name, filters, validator, validation, elementMessage, _4, _8, *_9, _10, *_11, _18, _26, _1$$4, _2$$5, _5$$6, _6$$7, *_13$$10, _14$$10, *_15$$10, _16$$10, *_21$$15, _22$$15, *_23$$15, _24$$15, _28$$21, _29$$21;
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
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_24$$15);
	ZVAL_UNDEF(&_28$$21);
	ZVAL_UNDEF(&_29$$21);
	ZVAL_UNDEF(&whitelist);
	ZEND_TLS zephir_method_cache _zephir_call_cache[36];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("elements", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("whitelist", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("data", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("entity", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("messages", 8, 1);
	}

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
	_0 = zephir_isempty_property_fast(this_ptr, _zephir_prop_0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_0) {
		RETURN_MM_BOOL(1);
	}
	if (ZEPHIR_IS_EMPTY(&whitelist)) {
		zephir_read_property_cached(&_1$$4, this_ptr, _zephir_prop_1, 807, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (UNEXPECTED(Z_TYPE_P(&_1$$4) != IS_ARRAY)) {
			zephir_throw_variable_type_error(&_1$$4, "whitelist", "array");
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&whitelist, &_1$$4);
	}
	if (Z_TYPE_P(data) != IS_ARRAY) {
		zephir_read_property_cached(&_2$$5, this_ptr, _zephir_prop_2, 808, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(data, &_2$$5);
	}
	_3 = Z_TYPE_P(entity) != IS_OBJECT;
	if (_3) {
		zephir_memory_observe(&_4);
		zephir_read_property_cached(&_4, this_ptr, _zephir_prop_3, 801, PH_NOISY_CC);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_3 = Z_TYPE_P(&_4) == IS_OBJECT;
	}
	if (_3) {
		zephir_read_property_cached(&_5$$6, this_ptr, _zephir_prop_3, 801, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(entity, &_5$$6);
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "bind", &_zephir_call_cache[0], data, entity, &whitelist);
	zephir_check_call_status();
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("beforevalidation")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD_CACHED(&_6$$7, this_ptr, "beforeValidation", &_zephir_call_cache[1], data, entity);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_6$$7)) {
			RETURN_MM_BOOL(0);
		}
	}
	validationStatus = 1;
	ZEPHIR_CALL_METHOD_CACHED(&validation, this_ptr, "getValidation", &_zephir_call_cache[2]);
	zephir_check_call_status();
	_7 = Z_TYPE_P(&validation) != IS_OBJECT;
	if (!(_7)) {
		_7 = !((zephir_instance_of_ev(&validation, phalcon_filter_validation_validationinterface_ce)));
	}
	if (_7) {
		ZEPHIR_INIT_NVAR(&validation);
		object_init_ex(&validation, phalcon_filter_validation_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &validation, "__construct", &_zephir_call_cache[3]);
		zephir_check_call_status();
	}
	zephir_read_property_cached(&_8, this_ptr, _zephir_prop_0, 806, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_8) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_10);
		zephir_string_to_char_array(&_10, &_8);
		_9 = &_10;
	} else {
		_9 = &_8;
	}
	zephir_is_iterable(_9, 0, "phalcon/Forms/Form.zep", 777);
	if (Z_TYPE_P(_9) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_9), _11)
		{
			ZEPHIR_INIT_NVAR(&element);
			ZVAL_COPY(&element, _11);
			ZEPHIR_CALL_METHOD_CACHED(&validators, &element, "getValidators", &_zephir_call_cache[4]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&filters, &element, "getFilters", &_zephir_call_cache[5]);
			zephir_check_call_status();
			_12$$10 = ZEPHIR_IS_EMPTY(&validators);
			if (_12$$10) {
				_12$$10 = ZEPHIR_IS_EMPTY(&filters);
			}
			if (_12$$10) {
				continue;
			}
			ZEPHIR_CALL_METHOD_CACHED(&name, &element, "getName", &_zephir_call_cache[6]);
			zephir_check_call_status();
			if (Z_TYPE_P(&validators) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_14$$10);
				zephir_string_to_char_array(&_14$$10, &validators);
				_13$$10 = &_14$$10;
			} else {
				_13$$10 = &validators;
			}
			zephir_is_iterable(_13$$10, 0, "phalcon/Forms/Form.zep", 769);
			if (Z_TYPE_P(_13$$10) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_13$$10), _15$$10)
				{
					ZEPHIR_INIT_NVAR(&validator);
					ZVAL_COPY(&validator, _15$$10);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &validation, "add", &_zephir_call_cache[7], &name, &validator);
					zephir_check_call_status();
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _13$$10, "rewind", &_zephir_call_cache[8]);
				zephir_check_call_status();
				_17$$10 = 1;
				while (1) {
					if (_17$$10) {
						_17$$10 = 0;
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _13$$10, "next", &_zephir_call_cache[9]);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD_CACHED(&_16$$10, _13$$10, "valid", &_zephir_call_cache[10]);
					zephir_check_call_status();
					if (!zend_is_true(&_16$$10)) {
						break;
					}
					ZEPHIR_CALL_METHOD_CACHED(&validator, _13$$10, "current", &_zephir_call_cache[11]);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD_CACHED(NULL, &validation, "add", &_zephir_call_cache[12], &name, &validator);
						zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&validator);
			if (Z_TYPE_P(&filters) == IS_ARRAY) {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &validation, "setFilters", &_zephir_call_cache[13], &name, &filters);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _9, "rewind", &_zephir_call_cache[14]);
		zephir_check_call_status();
		_19 = 1;
		while (1) {
			if (_19) {
				_19 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _9, "next", &_zephir_call_cache[15]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_18, _9, "valid", &_zephir_call_cache[16]);
			zephir_check_call_status();
			if (!zend_is_true(&_18)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&element, _9, "current", &_zephir_call_cache[17]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&validators, &element, "getValidators", &_zephir_call_cache[18]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&filters, &element, "getFilters", &_zephir_call_cache[19]);
				zephir_check_call_status();
				_20$$15 = ZEPHIR_IS_EMPTY(&validators);
				if (_20$$15) {
					_20$$15 = ZEPHIR_IS_EMPTY(&filters);
				}
				if (_20$$15) {
					continue;
				}
				ZEPHIR_CALL_METHOD_CACHED(&name, &element, "getName", &_zephir_call_cache[20]);
				zephir_check_call_status();
				if (Z_TYPE_P(&validators) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_22$$15);
					zephir_string_to_char_array(&_22$$15, &validators);
					_21$$15 = &_22$$15;
				} else {
					_21$$15 = &validators;
				}
				zephir_is_iterable(_21$$15, 0, "phalcon/Forms/Form.zep", 769);
				if (Z_TYPE_P(_21$$15) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_21$$15), _23$$15)
					{
						ZEPHIR_INIT_NVAR(&validator);
						ZVAL_COPY(&validator, _23$$15);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &validation, "add", &_zephir_call_cache[21], &name, &validator);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _21$$15, "rewind", &_zephir_call_cache[22]);
					zephir_check_call_status();
					_25$$15 = 1;
					while (1) {
						if (_25$$15) {
							_25$$15 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _21$$15, "next", &_zephir_call_cache[23]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_24$$15, _21$$15, "valid", &_zephir_call_cache[24]);
						zephir_check_call_status();
						if (!zend_is_true(&_24$$15)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&validator, _21$$15, "current", &_zephir_call_cache[25]);
						zephir_check_call_status();
							ZEPHIR_CALL_METHOD_CACHED(NULL, &validation, "add", &_zephir_call_cache[26], &name, &validator);
							zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&validator);
				if (Z_TYPE_P(&filters) == IS_ARRAY) {
					ZEPHIR_CALL_METHOD_CACHED(NULL, &validation, "setFilters", &_zephir_call_cache[27], &name, &filters);
					zephir_check_call_status();
				}
		}
	}
	ZEPHIR_INIT_NVAR(&element);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &validation, "validate", &_zephir_call_cache[28], data, entity);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&messages, &validation, "getMessages", &_zephir_call_cache[29]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_26, &messages, "count", &_zephir_call_cache[30]);
	zephir_check_call_status();
	if (zephir_is_true(&_26)) {
		_27$$20 = zephir_get_iterator(&messages);
		if (EXPECTED(_27$$20 != NULL)) {
			_27$$20->funcs->rewind(_27$$20);
			for (;_27$$20->funcs->valid(_27$$20) == SUCCESS && !EG(exception); _27$$20->funcs->move_forward(_27$$20)) {
			{
				ZEPHIR_ITERATOR_COPY(&elementMessage, _27$$20);
			}
			ZEPHIR_CALL_METHOD_CACHED(&_29$$21, &elementMessage, "getField", &_zephir_call_cache[31]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&_28$$21, this_ptr, "get", &_zephir_call_cache[32], &_29$$21);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_28$$21, "appendMessage", &_zephir_call_cache[33], &elementMessage);
			zephir_check_call_status();
		}
		zend_iterator_dtor(_27$$20);
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, &messages, "rewind", &_zephir_call_cache[34]);
		zephir_check_call_status();
		validationStatus = 0;
	}
	if (!(validationStatus)) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 804, &messages);
	}
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("aftervalidation")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "afterValidation", &_zephir_call_cache[35], &messages);
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
 * Generate the label of an element added to the form including HTML
 *
 * @phpstan-param html_attributes $attributes
 */
PHP_METHOD(Phalcon_Forms_Form, label)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zval name_zv, *attributes_param = NULL, element, _0, _2$$3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&attributes);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("elements", 8, 1);
	}

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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 806, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1 = zephir_array_isset_fetch(&element, &_0, &name_zv, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_1))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_forms_exceptions_elementnotinform_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_2$$3, "__construct", &_zephir_call_cache[0], &name_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Forms/Form.zep", 828);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(&element, "label", &_zephir_call_cache[1], &attributes);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Loads elements into the form from a Schema source.
 *
 * Each definition in the schema must have at least 'type' and 'name'.
 * The locator resolves the type string to an element factory; custom
 * types can be registered on the locator with setElement().
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Forms_Form, load)
{
	zval _10$$3, _13$$3, _38$$8, _41$$8;
	zval _5$$3, _7$$3, _18$$4, _33$$8, _35$$8, _46$$9;
	zend_bool _31, _8$$3, _11$$3, _14$$3, _15$$3, _16$$3, _20$$3, _22$$3, _23$$3, _24$$3, _26$$3, _27$$3, _28$$3, _36$$8, _39$$8, _42$$8, _43$$8, _44$$8, _48$$8, _50$$8, _51$$8, _52$$8, _54$$8, _55$$8, _56$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *schema, schema_sub, *locator, locator_sub, attributes, definition, element, factory, name, options, type, _0, *_1, _2, *_3, _30, _4$$3, _6$$3, _9$$3, _12$$3, _19$$3, _17$$4, _21$$5, _25$$6, _29$$7, _32$$8, _34$$8, _37$$8, _40$$8, _47$$8, _45$$9, _49$$10, _53$$11, _57$$12;
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
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_19$$3);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_25$$6);
	ZVAL_UNDEF(&_29$$7);
	ZVAL_UNDEF(&_32$$8);
	ZVAL_UNDEF(&_34$$8);
	ZVAL_UNDEF(&_37$$8);
	ZVAL_UNDEF(&_40$$8);
	ZVAL_UNDEF(&_47$$8);
	ZVAL_UNDEF(&_45$$9);
	ZVAL_UNDEF(&_49$$10);
	ZVAL_UNDEF(&_53$$11);
	ZVAL_UNDEF(&_57$$12);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_18$$4);
	ZVAL_UNDEF(&_33$$8);
	ZVAL_UNDEF(&_35$$8);
	ZVAL_UNDEF(&_46$$9);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_38$$8);
	ZVAL_UNDEF(&_41$$8);
	ZEND_TLS zephir_method_cache _zephir_call_cache[17];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(schema, phalcon_contracts_forms_schema_ce)
		Z_PARAM_OBJECT_OF_CLASS(locator, phalcon_forms_formslocator_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &schema, &locator);
	ZEPHIR_CALL_METHOD_CACHED(&_0, schema, "load", &_zephir_call_cache[0]);
	zephir_check_call_status();
	if (Z_TYPE_P(&_0) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &_0);
		_1 = &_2;
	} else {
		_1 = &_0;
	}
	zephir_is_iterable(_1, 0, "phalcon/Forms/Form.zep", 874);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1), _3)
		{
			ZEPHIR_INIT_NVAR(&definition);
			ZVAL_COPY(&definition, _3);
			ZEPHIR_OBS_NVAR(&_4$$3);
			zephir_array_fetch_string(&_4$$3, &definition, SL("type"), PH_NOISY, "phalcon/Forms/Form.zep", 848);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_cast_to_string(&_5$$3, &_4$$3);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&type);
			zephir_fast_strtolower(&type, &_5$$3);
			ZEPHIR_OBS_NVAR(&_6$$3);
			zephir_array_fetch_string(&_6$$3, &definition, SL("name"), PH_NOISY, "phalcon/Forms/Form.zep", 849);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_cast_to_string(&_7$$3, &_6$$3);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CPY_WRT(&name, &_7$$3);
			_8$$3 = zephir_array_isset_value_string(&definition, SL("attributes"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_8$$3) {
				ZEPHIR_OBS_NVAR(&_9$$3);
				zephir_array_fetch_string(&_9$$3, &definition, SL("attributes"), PH_NOISY, "phalcon/Forms/Form.zep", 850);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_get_arrval(&_10$$3, &_9$$3);
				ZEPHIR_CPY_WRT(&attributes, &_10$$3);
			} else {
				ZEPHIR_INIT_NVAR(&attributes);
				array_init(&attributes);
			}
			_11$$3 = zephir_array_isset_value_string(&definition, SL("options"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_11$$3) {
				ZEPHIR_OBS_NVAR(&_12$$3);
				zephir_array_fetch_string(&_12$$3, &definition, SL("options"), PH_NOISY, "phalcon/Forms/Form.zep", 851);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_get_arrval(&_13$$3, &_12$$3);
				ZEPHIR_CPY_WRT(&options, &_13$$3);
			} else {
				ZEPHIR_INIT_NVAR(&options);
				array_init(&options);
			}
			ZEPHIR_CALL_METHOD_CACHED(&factory, locator, "getElement", &_zephir_call_cache[1], &type);
			zephir_check_call_status();
			ZEPHIR_CALL_ZVAL_FUNCTION(&element, &factory, NULL, 0, &name, &options, &attributes);
			zephir_check_call_status();
			_14$$3 = zephir_array_isset_value_string(&definition, SL("label"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_15$$3 = _14$$3;
			if (_15$$3) {
				_16$$3 = zephir_isempty_dim_string(&definition, SL("label"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_15$$3 = !(_16$$3);
			}
			if (_15$$3) {
				ZEPHIR_OBS_NVAR(&_17$$4);
				zephir_array_fetch_string(&_17$$4, &definition, SL("label"), PH_NOISY, "phalcon/Forms/Form.zep", 856);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_cast_to_string(&_18$$4, &_17$$4);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(NULL, &element, "setLabel", &_zephir_call_cache[2], &_18$$4);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_NVAR(&_19$$3);
			ZVAL_STRING(&_19$$3, "default");
			_20$$3 = zephir_array_key_exists(&definition, &_19$$3);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_20$$3) {
				ZEPHIR_OBS_NVAR(&_21$$5);
				zephir_array_fetch_string(&_21$$5, &definition, SL("default"), PH_NOISY, "phalcon/Forms/Form.zep", 860);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(NULL, &element, "setDefault", &_zephir_call_cache[3], &_21$$5);
				zephir_check_call_status();
			}
			_22$$3 = zephir_array_isset_value_string(&definition, SL("filters"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_23$$3 = _22$$3;
			if (_23$$3) {
				_24$$3 = zephir_isempty_dim_string(&definition, SL("filters"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_23$$3 = !(_24$$3);
			}
			if (_23$$3) {
				ZEPHIR_OBS_NVAR(&_25$$6);
				zephir_array_fetch_string(&_25$$6, &definition, SL("filters"), PH_NOISY, "phalcon/Forms/Form.zep", 864);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(NULL, &element, "setFilters", &_zephir_call_cache[4], &_25$$6);
				zephir_check_call_status();
			}
			_26$$3 = zephir_array_isset_value_string(&definition, SL("validators"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_27$$3 = _26$$3;
			if (_27$$3) {
				_28$$3 = zephir_isempty_dim_string(&definition, SL("validators"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_27$$3 = !(_28$$3);
			}
			if (_27$$3) {
				ZEPHIR_OBS_NVAR(&_29$$7);
				zephir_array_fetch_string(&_29$$7, &definition, SL("validators"), PH_NOISY, "phalcon/Forms/Form.zep", 868);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(NULL, &element, "addValidators", &_zephir_call_cache[5], &_29$$7);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "add", &_zephir_call_cache[6], &element);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "rewind", &_zephir_call_cache[7]);
		zephir_check_call_status();
		_31 = 1;
		while (1) {
			if (_31) {
				_31 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "next", &_zephir_call_cache[8]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_30, _1, "valid", &_zephir_call_cache[9]);
			zephir_check_call_status();
			if (!zend_is_true(&_30)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&definition, _1, "current", &_zephir_call_cache[10]);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&_32$$8);
				zephir_array_fetch_string(&_32$$8, &definition, SL("type"), PH_NOISY, "phalcon/Forms/Form.zep", 848);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_cast_to_string(&_33$$8, &_32$$8);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&type);
				zephir_fast_strtolower(&type, &_33$$8);
				ZEPHIR_OBS_NVAR(&_34$$8);
				zephir_array_fetch_string(&_34$$8, &definition, SL("name"), PH_NOISY, "phalcon/Forms/Form.zep", 849);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_cast_to_string(&_35$$8, &_34$$8);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CPY_WRT(&name, &_35$$8);
				_36$$8 = zephir_array_isset_value_string(&definition, SL("attributes"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_36$$8) {
					ZEPHIR_OBS_NVAR(&_37$$8);
					zephir_array_fetch_string(&_37$$8, &definition, SL("attributes"), PH_NOISY, "phalcon/Forms/Form.zep", 850);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_get_arrval(&_38$$8, &_37$$8);
					ZEPHIR_CPY_WRT(&attributes, &_38$$8);
				} else {
					ZEPHIR_INIT_NVAR(&attributes);
					array_init(&attributes);
				}
				_39$$8 = zephir_array_isset_value_string(&definition, SL("options"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_39$$8) {
					ZEPHIR_OBS_NVAR(&_40$$8);
					zephir_array_fetch_string(&_40$$8, &definition, SL("options"), PH_NOISY, "phalcon/Forms/Form.zep", 851);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_get_arrval(&_41$$8, &_40$$8);
					ZEPHIR_CPY_WRT(&options, &_41$$8);
				} else {
					ZEPHIR_INIT_NVAR(&options);
					array_init(&options);
				}
				ZEPHIR_CALL_METHOD_CACHED(&factory, locator, "getElement", &_zephir_call_cache[11], &type);
				zephir_check_call_status();
				ZEPHIR_CALL_ZVAL_FUNCTION(&element, &factory, NULL, 0, &name, &options, &attributes);
				zephir_check_call_status();
				_42$$8 = zephir_array_isset_value_string(&definition, SL("label"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_43$$8 = _42$$8;
				if (_43$$8) {
					_44$$8 = zephir_isempty_dim_string(&definition, SL("label"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_43$$8 = !(_44$$8);
				}
				if (_43$$8) {
					ZEPHIR_OBS_NVAR(&_45$$9);
					zephir_array_fetch_string(&_45$$9, &definition, SL("label"), PH_NOISY, "phalcon/Forms/Form.zep", 856);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_cast_to_string(&_46$$9, &_45$$9);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(NULL, &element, "setLabel", &_zephir_call_cache[12], &_46$$9);
					zephir_check_call_status();
				}
				ZEPHIR_INIT_NVAR(&_47$$8);
				ZVAL_STRING(&_47$$8, "default");
				_48$$8 = zephir_array_key_exists(&definition, &_47$$8);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_48$$8) {
					ZEPHIR_OBS_NVAR(&_49$$10);
					zephir_array_fetch_string(&_49$$10, &definition, SL("default"), PH_NOISY, "phalcon/Forms/Form.zep", 860);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(NULL, &element, "setDefault", &_zephir_call_cache[13], &_49$$10);
					zephir_check_call_status();
				}
				_50$$8 = zephir_array_isset_value_string(&definition, SL("filters"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_51$$8 = _50$$8;
				if (_51$$8) {
					_52$$8 = zephir_isempty_dim_string(&definition, SL("filters"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_51$$8 = !(_52$$8);
				}
				if (_51$$8) {
					ZEPHIR_OBS_NVAR(&_53$$11);
					zephir_array_fetch_string(&_53$$11, &definition, SL("filters"), PH_NOISY, "phalcon/Forms/Form.zep", 864);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(NULL, &element, "setFilters", &_zephir_call_cache[14], &_53$$11);
					zephir_check_call_status();
				}
				_54$$8 = zephir_array_isset_value_string(&definition, SL("validators"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_55$$8 = _54$$8;
				if (_55$$8) {
					_56$$8 = zephir_isempty_dim_string(&definition, SL("validators"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_55$$8 = !(_56$$8);
				}
				if (_55$$8) {
					ZEPHIR_OBS_NVAR(&_57$$12);
					zephir_array_fetch_string(&_57$$12, &definition, SL("validators"), PH_NOISY, "phalcon/Forms/Form.zep", 868);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(NULL, &element, "addValidators", &_zephir_call_cache[15], &_57$$12);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "add", &_zephir_call_cache[16], &element);
				zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&definition);
	RETURN_THIS();
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
 * Removes an element from the form
 */
PHP_METHOD(Phalcon_Forms_Form, remove)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval name_zv, _0, _2;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("elements", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("elementsIndexed", 15, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 806, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1 = zephir_array_isset_value(&_0, &name_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_1) {
		zephir_unset_property_array(this_ptr, ZEND_STRL("elements"), &name_zv);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 810, &_2);
	RETURN_MM_BOOL(0);
}

/**
 * Renders a specific item in the form
 *
 * @phpstan-param html_attributes $attributes
 */
PHP_METHOD(Phalcon_Forms_Form, render)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zval name_zv, *attributes_param = NULL, element, _0, _2$$3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&attributes);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("elements", 8, 1);
	}

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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 806, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1 = zephir_array_isset_fetch(&element, &_0, &name_zv, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_1))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_forms_exceptions_elementnotinform_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_2$$3, "__construct", &_zephir_call_cache[0], &name_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Forms/Form.zep", 917);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(&element, "render", &_zephir_call_cache[1], &attributes);
	zephir_check_call_status();
	RETURN_MM();
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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("position", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("elements", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("elementsIndexed", 15, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 811, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 806, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_1, "array_values", NULL, 18, &_0);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 810, &_1);
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets the form's action
 *
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(action)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&action_zv);
	ZVAL_STR_COPY(&action_zv, action);
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "getAttributes", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "action");
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "set", &_zephir_call_cache[1], &_1, &action_zv);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("attributes", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(attributes, phalcon_html_attributes_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &attributes);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 803, attributes);
	RETURN_THISW();
}

/**
 * Sets the entity related to the model
 *
 * @param object $entity
 */
PHP_METHOD(Phalcon_Forms_Form, setEntity)
{
	zval *entity, entity_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&entity_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("entity", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(entity)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &entity);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 801, entity);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("tagFactory", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(tagFactory, phalcon_html_tagfactory_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &tagFactory);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 805, tagFactory);
	RETURN_THISW();
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
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	RETURN_THISW();
}

/**
 * Sets options for the element
 *
 * @phpstan-param forms_options $options
 */
PHP_METHOD(Phalcon_Forms_Form, setUserOptions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("options", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &options_param);
	zephir_get_arrval(&options, options_param);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 802, &options);
	RETURN_THIS();
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("validation", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(validation, phalcon_filter_validation_validationinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &validation);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 812, validation);
	RETURN_THISW();
}

/**
 * Sets the default whitelist
 *
 * @phpstan-param forms_whitelist $whitelist
 */
PHP_METHOD(Phalcon_Forms_Form, setWhitelist)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *whitelist_param = NULL;
	zval whitelist;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&whitelist);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("whitelist", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(whitelist, whitelist_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &whitelist_param);
	zephir_get_arrval(&whitelist, whitelist_param);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 807, &whitelist);
	RETURN_THIS();
}

/**
 * Check if the current element in the iterator is valid
 */
PHP_METHOD(Phalcon_Forms_Form, valid)
{
	zend_bool _2;
	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("elementsIndexed", 15, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("position", 8, 1);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 810, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 811, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	_2 = zephir_array_isset_value(&_0, &_1);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	RETURN_BOOL(_2);
}

