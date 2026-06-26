
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
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


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
 * The snapshot is a versioned, scalar-only structure: roles and components are
 * stored as `name => description` maps and rebuilt into objects on load, so the
 * snapshot round-trips through any serializer (php, json, igbinary, msgpack).
 *
 * Callable (closure) rules are not serializable. Any access key backed by a
 * closure is persisted as DENY, so a reloaded policy fails closed until the
 * closure is re-registered after load().
 *
 * Single-writer contract: mutations are in-memory until save() is called, and
 * save() writes the whole snapshot (last-write-wins, no atomic check-and-set).
 * Use external locking when multiple processes write the same key.
 *
 * @see Persistable
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
	/**
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_acl_adapter_storage_ce, SL("SNAPSHOT_VERSION"), 1);

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
 * in-memory state. Returns false when no compatible snapshot exists; throws
 * Phalcon\Acl\Exceptions\InvalidSnapshot on an incompatible version or a
 * malformed structure.
 */
PHP_METHOD(Phalcon_Acl_Adapter_Storage, load)
{
	zend_string *_20, *_29;
	zend_ulong _19, _28;
	zend_bool _7, _9, _11, _13, _15, _24, _33;
	zval data, version, name, description, rebuiltRoles, rebuiltComponents, _0, _1, _6, _8, _10, _12, _14, _16, _17, *_18, _23, _26, *_27, _32, _35, _36, _37, _38, _39, _40, _2$$3, _3$$6, _4$$6, _5$$6, _21$$8, _25$$9, _30$$10, _34$$11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_22 = NULL, *_31 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&description);
	ZVAL_UNDEF(&rebuiltRoles);
	ZVAL_UNDEF(&rebuiltComponents);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&_38);
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&_40);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_25$$9);
	ZVAL_UNDEF(&_30$$10);
	ZVAL_UNDEF(&_34$$11);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("storage"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("key"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&data, &_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(&data) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "normalizetoarray", NULL, 286, &data);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&data, &_2$$3);
	}
	if (Z_TYPE_P(&data) != IS_ARRAY) {
		RETURN_MM_BOOL(0);
	}
	if (!(zephir_array_isset_value_string(&data, SL("version")))) {
		RETURN_MM_BOOL(0);
	}
	zephir_memory_observe(&version);
	zephir_array_fetch_string(&version, &data, SL("version"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 89);
	if (!ZEPHIR_IS_LONG(&version, 1)) {
		ZEPHIR_INIT_VAR(&_3$$6);
		object_init_ex(&_3$$6, phalcon_acl_exceptions_invalidsnapshot_ce);
		ZEPHIR_INIT_VAR(&_4$$6);
		ZVAL_LONG(&_4$$6, 1);
		ZEPHIR_INIT_VAR(&_5$$6);
		ZEPHIR_CONCAT_SVSVS(&_5$$6, "Incompatible ACL snapshot version '", &version, "'; expected '", &_4$$6, "'");
		ZEPHIR_CALL_METHOD(NULL, &_3$$6, "__construct", NULL, 8, &_5$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$6, "phalcon/Acl/Adapter/Storage.zep", 95);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&_6);
	zephir_array_fetch_string(&_6, &data, SL("access"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 99);
	_7 = Z_TYPE_P(&_6) != IS_ARRAY;
	if (!(_7)) {
		zephir_memory_observe(&_8);
		zephir_array_fetch_string(&_8, &data, SL("accessList"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 100);
		_7 = Z_TYPE_P(&_8) != IS_ARRAY;
	}
	_9 = _7;
	if (!(_9)) {
		zephir_memory_observe(&_10);
		zephir_array_fetch_string(&_10, &data, SL("components"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 101);
		_9 = Z_TYPE_P(&_10) != IS_ARRAY;
	}
	_11 = _9;
	if (!(_11)) {
		zephir_memory_observe(&_12);
		zephir_array_fetch_string(&_12, &data, SL("componentsNames"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 102);
		_11 = Z_TYPE_P(&_12) != IS_ARRAY;
	}
	_13 = _11;
	if (!(_13)) {
		zephir_memory_observe(&_14);
		zephir_array_fetch_string(&_14, &data, SL("roles"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 103);
		_13 = Z_TYPE_P(&_14) != IS_ARRAY;
	}
	_15 = _13;
	if (!(_15)) {
		zephir_memory_observe(&_16);
		zephir_array_fetch_string(&_16, &data, SL("roleInherits"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 104);
		_15 = Z_TYPE_P(&_16) != IS_ARRAY;
	}
	if (UNEXPECTED(_15)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_invalidsnapshot_ce, "Malformed ACL snapshot structure", "phalcon/Acl/Adapter/Storage.zep", 106);
		return;
	}
	ZEPHIR_INIT_VAR(&rebuiltRoles);
	array_init(&rebuiltRoles);
	zephir_array_fetch_string(&_17, &data, SL("roles"), PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Storage.zep", 110);
	zephir_is_iterable(&_17, 0, "phalcon/Acl/Adapter/Storage.zep", 114);
	if (Z_TYPE_P(&_17) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_17), _19, _20, _18)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_20 != NULL) { 
				ZVAL_STR_COPY(&name, _20);
			} else {
				ZVAL_LONG(&name, _19);
			}
			ZEPHIR_INIT_NVAR(&description);
			ZVAL_COPY(&description, _18);
			ZEPHIR_INIT_NVAR(&_21$$8);
			object_init_ex(&_21$$8, phalcon_acl_role_ce);
			ZEPHIR_CALL_METHOD(NULL, &_21$$8, "__construct", &_22, 211, &name, &description);
			zephir_check_call_status();
			zephir_array_update_zval(&rebuiltRoles, &name, &_21$$8, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_17, "rewind", NULL, 0);
		zephir_check_call_status();
		_24 = 1;
		while (1) {
			if (_24) {
				_24 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_17, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_23, &_17, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_23)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &_17, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&description, &_17, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_25$$9);
				object_init_ex(&_25$$9, phalcon_acl_role_ce);
				ZEPHIR_CALL_METHOD(NULL, &_25$$9, "__construct", &_22, 211, &name, &description);
				zephir_check_call_status();
				zephir_array_update_zval(&rebuiltRoles, &name, &_25$$9, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&description);
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_INIT_VAR(&rebuiltComponents);
	array_init(&rebuiltComponents);
	zephir_array_fetch_string(&_26, &data, SL("components"), PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Storage.zep", 115);
	zephir_is_iterable(&_26, 0, "phalcon/Acl/Adapter/Storage.zep", 119);
	if (Z_TYPE_P(&_26) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_26), _28, _29, _27)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_29 != NULL) { 
				ZVAL_STR_COPY(&name, _29);
			} else {
				ZVAL_LONG(&name, _28);
			}
			ZEPHIR_INIT_NVAR(&description);
			ZVAL_COPY(&description, _27);
			ZEPHIR_INIT_NVAR(&_30$$10);
			object_init_ex(&_30$$10, phalcon_acl_component_ce);
			ZEPHIR_CALL_METHOD(NULL, &_30$$10, "__construct", &_31, 203, &name, &description);
			zephir_check_call_status();
			zephir_array_update_zval(&rebuiltComponents, &name, &_30$$10, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_26, "rewind", NULL, 0);
		zephir_check_call_status();
		_33 = 1;
		while (1) {
			if (_33) {
				_33 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_26, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_32, &_26, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_32)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &_26, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&description, &_26, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_34$$11);
				object_init_ex(&_34$$11, phalcon_acl_component_ce);
				ZEPHIR_CALL_METHOD(NULL, &_34$$11, "__construct", &_31, 203, &name, &description);
				zephir_check_call_status();
				zephir_array_update_zval(&rebuiltComponents, &name, &_34$$11, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&description);
	ZEPHIR_INIT_NVAR(&name);
	zephir_array_fetch_string(&_35, &data, SL("access"), PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Storage.zep", 119);
	zephir_update_property_zval(this_ptr, ZEND_STRL("access"), &_35);
	zephir_array_fetch_string(&_36, &data, SL("accessList"), PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Storage.zep", 120);
	zephir_update_property_zval(this_ptr, ZEND_STRL("accessList"), &_36);
	zephir_update_property_zval(this_ptr, ZEND_STRL("components"), &rebuiltComponents);
	zephir_array_fetch_string(&_37, &data, SL("componentsNames"), PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Storage.zep", 122);
	zephir_update_property_zval(this_ptr, ZEND_STRL("componentsNames"), &_37);
	zephir_update_property_zval(this_ptr, ZEND_STRL("roles"), &rebuiltRoles);
	zephir_array_fetch_string(&_38, &data, SL("roleInherits"), PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Storage.zep", 124);
	zephir_update_property_zval(this_ptr, ZEND_STRL("roleInherits"), &_38);
	ZEPHIR_INIT_VAR(&_39);
	if (zephir_array_isset_value_string(&data, SL("defaultAccess"))) {
		ZEPHIR_OBS_NVAR(&_39);
		zephir_array_fetch_string(&_39, &data, SL("defaultAccess"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 125);
	} else {
		ZEPHIR_INIT_NVAR(&_39);
		ZVAL_LONG(&_39, 0);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultAccess"), &_39);
	ZEPHIR_INIT_VAR(&_40);
	if (zephir_array_isset_value_string(&data, SL("noArgumentsDefaultAction"))) {
		ZEPHIR_OBS_NVAR(&_40);
		zephir_array_fetch_string(&_40, &data, SL("noArgumentsDefaultAction"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 126);
	} else {
		ZEPHIR_INIT_NVAR(&_40);
		ZVAL_LONG(&_40, 0);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("noArgumentsDefaultAction"), &_40);
	RETURN_MM_BOOL(1);
}

/**
 * Persists the policy snapshot. Closure-backed access keys are written as
 * DENY (fail closed); roles/components are written as scalar name =>
 * description maps for serializer independence.
 */
PHP_METHOD(Phalcon_Acl_Adapter_Storage, save)
{
	zval _22;
	zend_bool _10, _18;
	zend_string *_7, *_15;
	zend_ulong _6, _14;
	zval accessKey, componentName, componentObject, roleName, roleObject, access, components, roles, _0, _1, *_2, _4, *_5, _9, _12, *_13, _17, _20, _21, _23, _3$$3, _8$$4, _11$$5, _16$$6, _19$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&accessKey);
	ZVAL_UNDEF(&componentName);
	ZVAL_UNDEF(&componentObject);
	ZVAL_UNDEF(&roleName);
	ZVAL_UNDEF(&roleObject);
	ZVAL_UNDEF(&access);
	ZVAL_UNDEF(&components);
	ZVAL_UNDEF(&roles);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_22);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("access"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&access, &_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("functions"), PH_NOISY_CC | PH_READONLY);
	zephir_array_keys(&_1, &_0);
	zephir_is_iterable(&_1, 0, "phalcon/Acl/Adapter/Storage.zep", 146);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_1), _2)
	{
		ZEPHIR_INIT_NVAR(&accessKey);
		ZVAL_COPY(&accessKey, _2);
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_LONG(&_3$$3, 0);
		zephir_array_update_zval(&access, &accessKey, &_3$$3, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&accessKey);
	ZEPHIR_INIT_VAR(&components);
	array_init(&components);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("components"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_4, 0, "phalcon/Acl/Adapter/Storage.zep", 151);
	if (Z_TYPE_P(&_4) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_4), _6, _7, _5)
		{
			ZEPHIR_INIT_NVAR(&componentName);
			if (_7 != NULL) { 
				ZVAL_STR_COPY(&componentName, _7);
			} else {
				ZVAL_LONG(&componentName, _6);
			}
			ZEPHIR_INIT_NVAR(&componentObject);
			ZVAL_COPY(&componentObject, _5);
			ZEPHIR_CALL_METHOD(&_8$$4, &componentObject, "getdescription", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_zval(&components, &componentName, &_8$$4, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_4, "rewind", NULL, 0);
		zephir_check_call_status();
		_10 = 1;
		while (1) {
			if (_10) {
				_10 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_4, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_9, &_4, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_9)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&componentName, &_4, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&componentObject, &_4, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_11$$5, &componentObject, "getdescription", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_zval(&components, &componentName, &_11$$5, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&componentObject);
	ZEPHIR_INIT_NVAR(&componentName);
	ZEPHIR_INIT_VAR(&roles);
	array_init(&roles);
	zephir_read_property(&_12, this_ptr, ZEND_STRL("roles"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_12, 0, "phalcon/Acl/Adapter/Storage.zep", 156);
	if (Z_TYPE_P(&_12) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_12), _14, _15, _13)
		{
			ZEPHIR_INIT_NVAR(&roleName);
			if (_15 != NULL) { 
				ZVAL_STR_COPY(&roleName, _15);
			} else {
				ZVAL_LONG(&roleName, _14);
			}
			ZEPHIR_INIT_NVAR(&roleObject);
			ZVAL_COPY(&roleObject, _13);
			ZEPHIR_CALL_METHOD(&_16$$6, &roleObject, "getdescription", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_zval(&roles, &roleName, &_16$$6, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_12, "rewind", NULL, 0);
		zephir_check_call_status();
		_18 = 1;
		while (1) {
			if (_18) {
				_18 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_12, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_17, &_12, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_17)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&roleName, &_12, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&roleObject, &_12, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_19$$7, &roleObject, "getdescription", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_zval(&roles, &roleName, &_19$$7, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&roleObject);
	ZEPHIR_INIT_NVAR(&roleName);
	zephir_read_property(&_20, this_ptr, ZEND_STRL("storage"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_21, this_ptr, ZEND_STRL("key"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_22);
	zephir_create_array(&_22, 9, 0);
	add_assoc_long_ex(&_22, SL("version"), 1);
	zephir_array_update_string(&_22, SL("access"), &access, PH_COPY | PH_SEPARATE);
	zephir_memory_observe(&_23);
	zephir_read_property(&_23, this_ptr, ZEND_STRL("accessList"), PH_NOISY_CC);
	zephir_array_update_string(&_22, SL("accessList"), &_23, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_22, SL("components"), &components, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_23);
	zephir_read_property(&_23, this_ptr, ZEND_STRL("componentsNames"), PH_NOISY_CC);
	zephir_array_update_string(&_22, SL("componentsNames"), &_23, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_22, SL("roles"), &roles, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_23);
	zephir_read_property(&_23, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC);
	zephir_array_update_string(&_22, SL("roleInherits"), &_23, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_23);
	zephir_read_property(&_23, this_ptr, ZEND_STRL("defaultAccess"), PH_NOISY_CC);
	zephir_array_update_string(&_22, SL("defaultAccess"), &_23, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_23);
	zephir_read_property(&_23, this_ptr, ZEND_STRL("noArgumentsDefaultAction"), PH_NOISY_CC);
	zephir_array_update_string(&_22, SL("noArgumentsDefaultAction"), &_23, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(&_20, "set", NULL, 0, &_21, &_22);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Recursively converts stdClass into nested arrays so a snapshot stored
 * through an object-decoding serializer (e.g. JSON) is read back the same
 * way as the array-decoding serializers (php, igbinary, msgpack).
 */
PHP_METHOD(Phalcon_Acl_Adapter_Storage, normalizeToArray)
{
	zend_bool _7;
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value = NULL, value_sub, item, key, result, *_1, _6, _0$$3, _4$$5, _8$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_8$$6);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &value);
	ZEPHIR_SEPARATE_PARAM(value);
	if (Z_TYPE_P(value) == IS_OBJECT) {
		ZEPHIR_CALL_FUNCTION(&_0$$3, "get_object_vars", NULL, 287, value);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(value, &_0$$3);
	}
	if (Z_TYPE_P(value) != IS_ARRAY) {
		RETVAL_ZVAL(value, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	zephir_is_iterable(value, 0, "phalcon/Acl/Adapter/Storage.zep", 194);
	if (Z_TYPE_P(value) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(value), _2, _3, _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _1);
			ZEPHIR_CALL_METHOD(&_4$$5, this_ptr, "normalizetoarray", &_5, 286, &item);
			zephir_check_call_status();
			zephir_array_update_zval(&result, &key, &_4$$5, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, value, "rewind", NULL, 0);
		zephir_check_call_status();
		_7 = 1;
		while (1) {
			if (_7) {
				_7 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, value, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_6, value, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, value, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&item, value, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_8$$6, this_ptr, "normalizetoarray", &_5, 286, &item);
				zephir_check_call_status();
				zephir_array_update_zval(&result, &key, &_8$$6, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&result);
}

