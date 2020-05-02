
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AtlasPHP
 *
 * @link    https://github.com/atlasphp/Atlas.Query
 * @license https://github.com/atlasphp/Atlas.Qyert/blob/1.x/LICENSE.md
 */
/**
 * Class Bind
 *
 * @property int   $inlineCount
 * @property array $store
 */
ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Query_Bind) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\DataMapper\\Query, Bind, phalcon, datamapper_query_bind, phalcon_datamapper_query_bind_method_entry, 0);

	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_datamapper_query_bind_ce, SL("inlineCount"), 0, ZEND_ACC_PROTECTED);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_datamapper_query_bind_ce, SL("store"), ZEND_ACC_PROTECTED);

	phalcon_datamapper_query_bind_ce->create_object = zephir_init_properties_Phalcon_DataMapper_Query_Bind;
	return SUCCESS;

}

/**
 * @param mixed $value
 * @param int   $type
 *
 * @return string
 */
PHP_METHOD(Phalcon_DataMapper_Query_Bind, bindInline) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long type, ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, *type_param = NULL, key, _3, _4, _5, _1$$3, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &value, &type_param);

	if (!type_param) {
		type = -1;
	} else {
		type = zephir_get_intval(type_param);
	}


	_0 = Z_TYPE_P(value) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(value, phalcon_datamapper_query_select_ce);
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(&_1$$3, value, "getstatement", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CONCAT_SVS(return_value, "(", &_1$$3, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(value) == IS_ARRAY) {
		ZVAL_LONG(&_2$$4, type);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "inlinearray", NULL, 0, value, &_2$$4);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property(&_3, this_ptr, SL("inlineCount"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_ZVAL_NREF(_4);
	ZVAL_LONG(&_4, (zephir_get_numberval(&_3) + 1));
	zephir_update_property_zval(this_ptr, ZEND_STRL("inlineCount"), &_4);
	zephir_read_property(&_4, this_ptr, SL("inlineCount"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&key);
	ZEPHIR_CONCAT_SVS(&key, "__", &_4, "__");
	ZVAL_LONG(&_5, type);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setvalue", NULL, 0, &key, value, &_5);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SV(return_value, ":", &key);
	RETURN_MM();

}

/**
 * Removes a value from the store
 *
 * @param string $key
 */
PHP_METHOD(Phalcon_DataMapper_Query_Bind, remove) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, store, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&store);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(&key, key_param);


	zephir_read_property(&_0, this_ptr, SL("store"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&store, &_0);
	zephir_array_unset(&store, &key, PH_SEPARATE);
	zephir_update_property_zval(this_ptr, ZEND_STRL("store"), &store);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets a value
 *
 * @param string $key
 * @param mixed  $value
 * @param int    $type
 */
PHP_METHOD(Phalcon_DataMapper_Query_Bind, setValue) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long type, ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, value_sub, *type_param = NULL, localType;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&localType);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &key_param, &value, &type_param);

	zephir_get_strval(&key, key_param);
	if (!type_param) {
		type = -1;
	} else {
		type = zephir_get_intval(type_param);
	}


	ZEPHIR_INIT_VAR(&localType);
	ZVAL_LONG(&localType, type);
	if (ZEPHIR_IS_LONG_IDENTICAL(&localType, -1)) {
		ZEPHIR_CALL_METHOD(&localType, this_ptr, "gettype", NULL, 0, value);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	zephir_array_fast_append(&_0, value);
	zephir_array_fast_append(&_0, &localType);
	zephir_update_property_array(this_ptr, SL("store"), &key, &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets values from an array
 *
 * @param array $values
 * @param int   $type
 */
PHP_METHOD(Phalcon_DataMapper_Query_Bind, setValues) {

	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long type, ZEPHIR_LAST_CALL_STATUS;
	zval *values_param = NULL, *type_param = NULL, key, value, *_0, _1, _4$$3, _6$$4;
	zval values;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &values_param, &type_param);

	zephir_get_arrval(&values, values_param);
	if (!type_param) {
		type = -1;
	} else {
		type = zephir_get_intval(type_param);
	}


	zephir_is_iterable(&values, 0, "phalcon/DataMapper/Query/Bind.zep", 111);
	if (Z_TYPE_P(&values) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&values), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			ZVAL_LONG(&_4$$3, type);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setvalue", &_5, 0, &key, &value, &_4$$3);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &values, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &values, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &values, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &values, "current", NULL, 0);
			zephir_check_call_status();
				ZVAL_LONG(&_6$$4, type);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "setvalue", &_5, 0, &key, &value, &_6$$4);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &values, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the internal collection
 *
 * @return array
 */
PHP_METHOD(Phalcon_DataMapper_Query_Bind, toArray) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "store");

}

/**
 * Auto detects the PDO type
 *
 * @param mixed $value
 *
 * @return int
 */
PHP_METHOD(Phalcon_DataMapper_Query_Bind, getType) {

	zval *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &value);



	if (Z_TYPE_P(value) == IS_NULL) {
		RETURN_LONG(0);
	}
	if (((Z_TYPE_P(value) == IS_TRUE || Z_TYPE_P(value) == IS_FALSE) == 1)) {
		RETURN_LONG(5);
	}
	if (Z_TYPE_P(value) == IS_LONG) {
		RETURN_LONG(1);
	}
	RETURN_LONG(2);

}

/**
 * Processes an array - if passed as an `inline` parameter
 *
 * @param array $array
 * @param int   $type
 *
 * @return string
 */
PHP_METHOD(Phalcon_DataMapper_Query_Bind, inlineArray) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long type, ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *type_param = NULL, key, value, *_0, _1, _11, _2$$3, _3$$3, _4$$3, _6$$3, _7$$4, _8$$4, _9$$4, _10$$4;
	zval data, keys;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &data_param, &type_param);

	zephir_get_arrval(&data, data_param);
	type = zephir_get_intval(type_param);


	ZEPHIR_INIT_VAR(&keys);
	array_init(&keys);
	zephir_is_iterable(&data, 0, "phalcon/DataMapper/Query/Bind.zep", 170);
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&data), _0)
		{
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			zephir_read_property(&_2$$3, this_ptr, SL("inlineCount"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_ZVAL_NREF(_3$$3);
			ZVAL_LONG(&_3$$3, (zephir_get_numberval(&_2$$3) + 1));
			zephir_update_property_zval(this_ptr, ZEND_STRL("inlineCount"), &_3$$3);
			zephir_read_property(&_3$$3, this_ptr, SL("inlineCount"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_NVAR(&key);
			ZEPHIR_CONCAT_SVS(&key, "__", &_3$$3, "__");
			ZVAL_LONG(&_4$$3, type);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setvalue", &_5, 0, &key, &value, &_4$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_6$$3);
			ZEPHIR_CONCAT_SV(&_6$$3, ":", &key);
			zephir_array_append(&keys, &_6$$3, PH_SEPARATE, "phalcon/DataMapper/Query/Bind.zep", 167);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
			zephir_check_call_status();
				zephir_read_property(&_7$$4, this_ptr, SL("inlineCount"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_ZVAL_NREF(_8$$4);
				ZVAL_LONG(&_8$$4, (zephir_get_numberval(&_7$$4) + 1));
				zephir_update_property_zval(this_ptr, ZEND_STRL("inlineCount"), &_8$$4);
				zephir_read_property(&_8$$4, this_ptr, SL("inlineCount"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_NVAR(&key);
				ZEPHIR_CONCAT_SVS(&key, "__", &_8$$4, "__");
				ZVAL_LONG(&_9$$4, type);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "setvalue", &_5, 0, &key, &value, &_9$$4);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_10$$4);
				ZEPHIR_CONCAT_SV(&_10$$4, ":", &key);
				zephir_array_append(&keys, &_10$$4, PH_SEPARATE, "phalcon/DataMapper/Query/Bind.zep", 167);
			ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_VAR(&_11);
	zephir_fast_join_str(&_11, SL(", "), &keys);
	ZEPHIR_CONCAT_SVS(return_value, "(", &_11, ")");
	RETURN_MM();

}

zend_object *zephir_init_properties_Phalcon_DataMapper_Query_Bind(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("store"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zend_update_property(Z_OBJCE_P(this_ptr), this_ptr, ZEND_STRL("store"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

