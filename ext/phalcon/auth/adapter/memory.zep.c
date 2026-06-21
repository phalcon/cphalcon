
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */
/**
 * In-memory adapter - useful for tests and small read-only user lists.
 *
 * @phpstan-import-type AuthUserRow from AbstractArrayAdapter
 *
 * @extends AbstractArrayAdapter<MemoryAdapterConfig>
 */
ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_Memory)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Auth\\Adapter, Memory, phalcon, auth_adapter_memory, phalcon_auth_adapter_abstractarrayadapter_ce, phalcon_auth_adapter_memory_method_entry, 0);

	/**
	 * Map of id => user row for O(1) retrieveById lookup.
	 *
	 * @phpstan-var array<int|string, AuthUserRow>
	 * @var array
	 */
	zend_declare_property_null(phalcon_auth_adapter_memory_ce, SL("idStore"), ZEND_ACC_PRIVATE);
	phalcon_auth_adapter_memory_ce->create_object = zephir_init_properties_Phalcon_Auth_Adapter_Memory;

	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_Adapter_Memory, __construct)
{
	zend_bool _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *hasher, hasher_sub, *config, config_sub, row, _0, *_1, _3, _2$$4, _5$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&hasher_sub);
	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_5$$6);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(hasher, phalcon_contracts_encryption_security_security_ce)
		Z_PARAM_OBJECT_OF_CLASS(config, phalcon_auth_adapter_config_memoryadapterconfig_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &hasher, &config);
	ZEPHIR_CALL_PARENT(NULL, phalcon_auth_adapter_memory_ce, getThis(), "__construct", NULL, 0, hasher, config);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "loadusers", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/Auth/Adapter/Memory.zep", 49);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&row);
			ZVAL_COPY(&row, _1);
			if (zephir_array_isset_value_string(&row, SL("id"))) {
				ZEPHIR_OBS_NVAR(&_2$$4);
				zephir_array_fetch_string(&_2$$4, &row, SL("id"), PH_NOISY, "phalcon/Auth/Adapter/Memory.zep", 46);
				zephir_update_property_array(this_ptr, SL("idStore"), &_2$$4, &row);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		_4 = 1;
		while (1) {
			if (_4) {
				_4 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_3, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&row, &_0, "current", NULL, 0);
			zephir_check_call_status();
				if (zephir_array_isset_value_string(&row, SL("id"))) {
					ZEPHIR_OBS_NVAR(&_5$$6);
					zephir_array_fetch_string(&_5$$6, &row, SL("id"), PH_NOISY, "phalcon/Auth/Adapter/Memory.zep", 46);
					zephir_update_property_array(this_ptr, SL("idStore"), &_5$$6, &row);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&row);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_Adapter_Memory, fromOptions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *hasher, hasher_sub, *options_param = NULL, _0, _1, _2, _3, _4;

	ZVAL_UNDEF(&hasher_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(hasher, phalcon_contracts_encryption_security_security_ce)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &hasher, &options_param);
	zephir_get_arrval(&options, options_param);
	object_init_ex(return_value, zend_get_called_scope(execute_data));
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_auth_adapter_config_memoryadapterconfig_ce);
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "users");
	ZEPHIR_CALL_CE_STATIC(&_1, phalcon_auth_internal_options_ce, "arrayoption", NULL, 0, &options, &_3, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "model");
	ZEPHIR_CALL_CE_STATIC(&_4, phalcon_auth_internal_options_ce, "stringornull", NULL, 0, &options, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 313, &_1, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 314, hasher, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Overridden for O(1) lookup via the id index built in the constructor.
 */
PHP_METHOD(Phalcon_Auth_Adapter_Memory, retrieveById)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id, id_sub, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(id)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &id);
	_0 = Z_TYPE_P(id) != IS_LONG;
	if (_0) {
		_0 = Z_TYPE_P(id) != IS_STRING;
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_ce_type_error, "The parameter must be 'int' or 'string'", "phalcon/Auth/Adapter/Memory.zep", 68);
		return;
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("idStore"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_value(&_1, id))) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("idStore"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_3, &_2, id, PH_NOISY | PH_READONLY, "phalcon/Auth/Adapter/Memory.zep", 75);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "hydrate", NULL, 0, &_3);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @phpstan-return list<AuthUserRow>
 */
PHP_METHOD(Phalcon_Auth_Adapter_Memory, loadUsers)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getusers", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

zend_object *zephir_init_properties_Phalcon_Auth_Adapter_Memory(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("idStore"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("idStore"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

