
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * ACL adapter that persists its policy to any Phalcon\Storage backend
 * (Redis, Apcu, Stream, Memcached, ...) as a whole-policy snapshot.
 *
 * Coarse granularity: the entire policy is loaded into memory and all
 * decisions are computed in memory (inherited from Memory). The backend is a
 * blob sink - it knows nothing about ACL structure.
 *
 * @see Persistable for the closure-persistence caveat.
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl_Adapter_Storage)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Acl\\Adapter, Storage, phalcon, acl_adapter_storage, phalcon_acl_adapter_memory_ce, phalcon_acl_adapter_storage_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_acl_adapter_storage_ce, SL("key"), ZEND_ACC_PROTECTED);
	/**
	 * @var StorageInterface
	 */
	zend_declare_property_null(phalcon_acl_adapter_storage_ce, SL("storage"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_acl_adapter_storage_ce, 1, phalcon_contracts_acl_adapter_persistable_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Acl_Adapter_Storage, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *key = NULL;
	zval *storage, storage_sub, key_zv;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&storage_sub);
	ZVAL_UNDEF(&key_zv);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(storage, phalcon_storage_adapter_adapterinterface_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	storage = ZEND_CALL_ARG(execute_data, 1);
	if (!key) {
		key = zend_string_init(ZEND_STRL("acl-data"), 0);
		zephir_memory_observe(&key_zv);
		ZVAL_STR(&key_zv, key);
	} else {
		zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("storage"), storage);
	zephir_update_property_zval(this_ptr, ZEND_STRL("key"), &key_zv);
	ZEPHIR_CALL_PARENT(NULL, phalcon_acl_adapter_storage_ce, getThis(), "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "load", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Loads the policy snapshot from the backing store, replacing current
 * in-memory state. Returns false if no snapshot was found.
 */
PHP_METHOD(Phalcon_Acl_Adapter_Storage, load)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, data, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("storage"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("key"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&data, &_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(&data) != IS_ARRAY) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_2);
	if (zephir_array_isset_value_string(&data, SL("access"))) {
		ZEPHIR_OBS_NVAR(&_2);
		zephir_array_fetch_string(&_2, &data, SL("access"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 63);
	} else {
		ZEPHIR_INIT_NVAR(&_2);
		array_init(&_2);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("access"), &_2);
	ZEPHIR_INIT_VAR(&_3);
	if (zephir_array_isset_value_string(&data, SL("accessList"))) {
		ZEPHIR_OBS_NVAR(&_3);
		zephir_array_fetch_string(&_3, &data, SL("accessList"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 64);
	} else {
		ZEPHIR_INIT_VAR(&_4);
		zephir_create_array(&_4, 1, 0);
		zephir_array_update_string(&_4, SL("*!*"), &__$true, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&_3, &_4);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("accessList"), &_3);
	ZEPHIR_INIT_VAR(&_5);
	if (zephir_array_isset_value_string(&data, SL("components"))) {
		ZEPHIR_OBS_NVAR(&_5);
		zephir_array_fetch_string(&_5, &data, SL("components"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 65);
	} else {
		ZEPHIR_INIT_NVAR(&_5);
		array_init(&_5);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("components"), &_5);
	ZEPHIR_INIT_VAR(&_6);
	if (zephir_array_isset_value_string(&data, SL("componentsNames"))) {
		ZEPHIR_OBS_NVAR(&_6);
		zephir_array_fetch_string(&_6, &data, SL("componentsNames"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 66);
	} else {
		ZEPHIR_INIT_VAR(&_7);
		zephir_create_array(&_7, 1, 0);
		zephir_array_update_string(&_7, SL("*"), &__$true, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&_6, &_7);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("componentsNames"), &_6);
	ZEPHIR_INIT_VAR(&_8);
	if (zephir_array_isset_value_string(&data, SL("roles"))) {
		ZEPHIR_OBS_NVAR(&_8);
		zephir_array_fetch_string(&_8, &data, SL("roles"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 67);
	} else {
		ZEPHIR_INIT_NVAR(&_8);
		array_init(&_8);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("roles"), &_8);
	ZEPHIR_INIT_VAR(&_9);
	if (zephir_array_isset_value_string(&data, SL("roleInherits"))) {
		ZEPHIR_OBS_NVAR(&_9);
		zephir_array_fetch_string(&_9, &data, SL("roleInherits"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 68);
	} else {
		ZEPHIR_INIT_NVAR(&_9);
		array_init(&_9);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("roleInherits"), &_9);
	ZEPHIR_INIT_VAR(&_10);
	if (zephir_array_isset_value_string(&data, SL("defaultAccess"))) {
		ZEPHIR_OBS_NVAR(&_10);
		zephir_array_fetch_string(&_10, &data, SL("defaultAccess"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 69);
	} else {
		ZEPHIR_INIT_NVAR(&_10);
		ZVAL_LONG(&_10, 0);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultAccess"), &_10);
	ZEPHIR_INIT_VAR(&_11);
	if (zephir_array_isset_value_string(&data, SL("noArgumentsDefaultAction"))) {
		ZEPHIR_OBS_NVAR(&_11);
		zephir_array_fetch_string(&_11, &data, SL("noArgumentsDefaultAction"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 70);
	} else {
		ZEPHIR_INIT_NVAR(&_11);
		ZVAL_LONG(&_11, 0);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("noArgumentsDefaultAction"), &_11);
	RETURN_MM_BOOL(1);
}

/**
 * Persists the policy snapshot. Callable rules (`functions`) are excluded -
 * closures are not serializable; the static rule set in `access` survives.
 */
PHP_METHOD(Phalcon_Acl_Adapter_Storage, save)
{
	zval _2;
	zval _0, _1, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("storage"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("key"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 8, 0);
	zephir_memory_observe(&_3);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("access"), PH_NOISY_CC);
	zephir_array_update_string(&_2, SL("access"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_3);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("accessList"), PH_NOISY_CC);
	zephir_array_update_string(&_2, SL("accessList"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_3);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("components"), PH_NOISY_CC);
	zephir_array_update_string(&_2, SL("components"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_3);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("componentsNames"), PH_NOISY_CC);
	zephir_array_update_string(&_2, SL("componentsNames"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_3);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("roles"), PH_NOISY_CC);
	zephir_array_update_string(&_2, SL("roles"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_3);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC);
	zephir_array_update_string(&_2, SL("roleInherits"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_3);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("defaultAccess"), PH_NOISY_CC);
	zephir_array_update_string(&_2, SL("defaultAccess"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_3);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("noArgumentsDefaultAction"), PH_NOISY_CC);
	zephir_array_update_string(&_2, SL("noArgumentsDefaultAction"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "set", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

