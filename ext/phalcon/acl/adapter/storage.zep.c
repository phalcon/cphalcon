
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
 *
 * @phpstan-import-type acl_snapshot from AclTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl_Adapter_Storage)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Acl\\Adapter, Storage, phalcon, acl_adapter_storage, phalcon_acl_adapter_memory_ce, phalcon_acl_adapter_storage_method_entry, 0);

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_acl_adapter_storage_ce, SL("key"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_acl_adapter_storage_ce, SL("storage"), &_zc0, ZEND_ACC_PROTECTED, 0, SL("Phalcon\\Storage\\Adapter\\AdapterInterface"));
	}

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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("storage", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("key", 3, 1);
	}

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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 380, storage);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 381, &key_zv);
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
	zend_string *_23, *_39$$21, *_48$$21;
	zend_ulong _22, _38$$21, _47$$21;
	zend_bool _7, _9, _11, _13, _15, _17, _18, _19, _30, _27$$9, _25$$11, _28$$13, _34$$15, _32$$17, _35$$19, _43$$21, _52$$21;
	zval data, version, name, description, rebuiltRoles, rebuiltComponents, defaultAccess, noArgumentsDefaultAction, inherits, inherit, e, _0, _1, _6, _8, _10, _12, _14, _16, _20, *_21, _29, _54, _58, _59, _60, _61, _2$$3, _3$$6, _4$$6, _5$$6, *_24$$9, _26$$9, *_31$$15, _33$$15, _36$$21, *_37$$21, _42$$21, _45$$21, *_46$$21, _51$$21, _40$$22, _44$$23, _49$$24, _53$$25, _55$$26, _56$$26, _57$$26;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_41 = NULL, *_50 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&description);
	ZVAL_UNDEF(&rebuiltRoles);
	ZVAL_UNDEF(&rebuiltComponents);
	ZVAL_UNDEF(&defaultAccess);
	ZVAL_UNDEF(&noArgumentsDefaultAction);
	ZVAL_UNDEF(&inherits);
	ZVAL_UNDEF(&inherit);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_54);
	ZVAL_UNDEF(&_58);
	ZVAL_UNDEF(&_59);
	ZVAL_UNDEF(&_60);
	ZVAL_UNDEF(&_61);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_26$$9);
	ZVAL_UNDEF(&_33$$15);
	ZVAL_UNDEF(&_36$$21);
	ZVAL_UNDEF(&_42$$21);
	ZVAL_UNDEF(&_45$$21);
	ZVAL_UNDEF(&_51$$21);
	ZVAL_UNDEF(&_40$$22);
	ZVAL_UNDEF(&_44$$23);
	ZVAL_UNDEF(&_49$$24);
	ZVAL_UNDEF(&_53$$25);
	ZVAL_UNDEF(&_55$$26);
	ZVAL_UNDEF(&_56$$26);
	ZVAL_UNDEF(&_57$$26);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	static zend_string *_zephir_prop_7 = NULL;
	static zend_string *_zephir_prop_8 = NULL;
	static zend_string *_zephir_prop_9 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("storage", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("key", 3, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("access", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("accessList", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("components", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("componentsNames", 15, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("roles", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_7)) {
		_zephir_prop_7 = zend_string_init("roleInherits", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_8)) {
		_zephir_prop_8 = zend_string_init("defaultAccess", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_9)) {
		_zephir_prop_9 = zend_string_init("noArgumentsDefaultAction", 24, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 380, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 381, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&data, &_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(&data) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "normalizetoarray", NULL, 356, &data);
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
	zephir_array_fetch_string(&version, &data, SL("version"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 85);
	if (!ZEPHIR_IS_LONG(&version, 1)) {
		ZEPHIR_INIT_VAR(&_3$$6);
		object_init_ex(&_3$$6, phalcon_acl_exceptions_invalidsnapshot_ce);
		ZEPHIR_INIT_VAR(&_4$$6);
		ZVAL_LONG(&_4$$6, 1);
		ZEPHIR_INIT_VAR(&_5$$6);
		ZEPHIR_CONCAT_SVSVS(&_5$$6, "Incompatible ACL snapshot version '", &version, "'; expected '", &_4$$6, "'");
		ZEPHIR_CALL_METHOD(NULL, &_3$$6, "__construct", NULL, 9, &_5$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$6, "phalcon/Acl/Adapter/Storage.zep", 91);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&_6);
	zephir_array_fetch_string(&_6, &data, SL("access"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 95);
	_7 = Z_TYPE_P(&_6) != IS_ARRAY;
	if (!(_7)) {
		zephir_memory_observe(&_8);
		zephir_array_fetch_string(&_8, &data, SL("accessList"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 96);
		_7 = Z_TYPE_P(&_8) != IS_ARRAY;
	}
	_9 = _7;
	if (!(_9)) {
		zephir_memory_observe(&_10);
		zephir_array_fetch_string(&_10, &data, SL("components"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 97);
		_9 = Z_TYPE_P(&_10) != IS_ARRAY;
	}
	_11 = _9;
	if (!(_11)) {
		zephir_memory_observe(&_12);
		zephir_array_fetch_string(&_12, &data, SL("componentsNames"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 98);
		_11 = Z_TYPE_P(&_12) != IS_ARRAY;
	}
	_13 = _11;
	if (!(_13)) {
		zephir_memory_observe(&_14);
		zephir_array_fetch_string(&_14, &data, SL("roles"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 99);
		_13 = Z_TYPE_P(&_14) != IS_ARRAY;
	}
	_15 = _13;
	if (!(_15)) {
		zephir_memory_observe(&_16);
		zephir_array_fetch_string(&_16, &data, SL("roleInherits"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 100);
		_15 = Z_TYPE_P(&_16) != IS_ARRAY;
	}
	if (UNEXPECTED(_15)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_invalidsnapshot_ce, "Malformed ACL snapshot structure", "phalcon/Acl/Adapter/Storage.zep", 102);
		return;
	}
	if (zephir_array_isset_value_string(&data, SL("defaultAccess"))) {
		zephir_memory_observe(&defaultAccess);
		zephir_array_fetch_string(&defaultAccess, &data, SL("defaultAccess"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 109);
	} else {
		ZEPHIR_INIT_NVAR(&defaultAccess);
		ZVAL_LONG(&defaultAccess, 0);
	}
	if (zephir_array_isset_value_string(&data, SL("noArgumentsDefaultAction"))) {
		zephir_memory_observe(&noArgumentsDefaultAction);
		zephir_array_fetch_string(&noArgumentsDefaultAction, &data, SL("noArgumentsDefaultAction"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 110);
	} else {
		ZEPHIR_INIT_NVAR(&noArgumentsDefaultAction);
		ZVAL_LONG(&noArgumentsDefaultAction, 0);
	}
	_17 = !ZEPHIR_IS_LONG_IDENTICAL(&defaultAccess, 1);
	if (_17) {
		_17 = !ZEPHIR_IS_LONG_IDENTICAL(&defaultAccess, 0);
	}
	_18 = _17;
	if (!(_18)) {
		_19 = !ZEPHIR_IS_LONG_IDENTICAL(&noArgumentsDefaultAction, 1);
		if (_19) {
			_19 = !ZEPHIR_IS_LONG_IDENTICAL(&noArgumentsDefaultAction, 0);
		}
		_18 = _19;
	}
	if (UNEXPECTED(_18)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_invalidsnapshot_ce, "Malformed ACL snapshot default action", "phalcon/Acl/Adapter/Storage.zep", 116);
		return;
	}
	zephir_array_fetch_string(&_20, &data, SL("roleInherits"), PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Storage.zep", 119);
	zephir_is_iterable(&_20, 0, "phalcon/Acl/Adapter/Storage.zep", 132);
	if (Z_TYPE_P(&_20) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_20), _22, _23, _21)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_23 != NULL) { 
				ZVAL_STR_COPY(&name, _23);
			} else {
				ZVAL_LONG(&name, _22);
			}
			ZEPHIR_INIT_NVAR(&inherits);
			ZVAL_COPY(&inherits, _21);
			if (UNEXPECTED(Z_TYPE_P(&inherits) != IS_ARRAY)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_invalidsnapshot_ce, "Malformed ACL snapshot role inheritance", "phalcon/Acl/Adapter/Storage.zep", 121);
				return;
			}
			zephir_is_iterable(&inherits, 0, "phalcon/Acl/Adapter/Storage.zep", 129);
			if (Z_TYPE_P(&inherits) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&inherits), _24$$9)
				{
					ZEPHIR_INIT_NVAR(&inherit);
					ZVAL_COPY(&inherit, _24$$9);
					_25$$11 = Z_TYPE_P(&inherit) != IS_STRING;
					if (_25$$11) {
						_25$$11 = Z_TYPE_P(&inherit) != IS_LONG;
					}
					if (UNEXPECTED(_25$$11)) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_invalidsnapshot_ce, "Malformed ACL snapshot role inheritance", "phalcon/Acl/Adapter/Storage.zep", 126);
						return;
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &inherits, "rewind", NULL, 0);
				zephir_check_call_status();
				_27$$9 = 1;
				while (1) {
					if (_27$$9) {
						_27$$9 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, &inherits, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_26$$9, &inherits, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_26$$9)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&inherit, &inherits, "current", NULL, 0);
					zephir_check_call_status();
						_28$$13 = Z_TYPE_P(&inherit) != IS_STRING;
						if (_28$$13) {
							_28$$13 = Z_TYPE_P(&inherit) != IS_LONG;
						}
						if (UNEXPECTED(_28$$13)) {
							ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_invalidsnapshot_ce, "Malformed ACL snapshot role inheritance", "phalcon/Acl/Adapter/Storage.zep", 126);
							return;
						}
				}
			}
			ZEPHIR_INIT_NVAR(&inherit);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_20, "rewind", NULL, 0);
		zephir_check_call_status();
		_30 = 1;
		while (1) {
			if (_30) {
				_30 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_20, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_29, &_20, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_29)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &_20, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&inherits, &_20, "current", NULL, 0);
			zephir_check_call_status();
				if (UNEXPECTED(Z_TYPE_P(&inherits) != IS_ARRAY)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_invalidsnapshot_ce, "Malformed ACL snapshot role inheritance", "phalcon/Acl/Adapter/Storage.zep", 121);
					return;
				}
				zephir_is_iterable(&inherits, 0, "phalcon/Acl/Adapter/Storage.zep", 129);
				if (Z_TYPE_P(&inherits) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&inherits), _31$$15)
					{
						ZEPHIR_INIT_NVAR(&inherit);
						ZVAL_COPY(&inherit, _31$$15);
						_32$$17 = Z_TYPE_P(&inherit) != IS_STRING;
						if (_32$$17) {
							_32$$17 = Z_TYPE_P(&inherit) != IS_LONG;
						}
						if (UNEXPECTED(_32$$17)) {
							ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_invalidsnapshot_ce, "Malformed ACL snapshot role inheritance", "phalcon/Acl/Adapter/Storage.zep", 126);
							return;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &inherits, "rewind", NULL, 0);
					zephir_check_call_status();
					_34$$15 = 1;
					while (1) {
						if (_34$$15) {
							_34$$15 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &inherits, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_33$$15, &inherits, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_33$$15)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&inherit, &inherits, "current", NULL, 0);
						zephir_check_call_status();
							_35$$19 = Z_TYPE_P(&inherit) != IS_STRING;
							if (_35$$19) {
								_35$$19 = Z_TYPE_P(&inherit) != IS_LONG;
							}
							if (UNEXPECTED(_35$$19)) {
								ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_invalidsnapshot_ce, "Malformed ACL snapshot role inheritance", "phalcon/Acl/Adapter/Storage.zep", 126);
								return;
							}
					}
				}
				ZEPHIR_INIT_NVAR(&inherit);
		}
	}
	ZEPHIR_INIT_NVAR(&inherits);
	ZEPHIR_INIT_NVAR(&name);

	/* try_start_1: */

		ZEPHIR_INIT_VAR(&rebuiltRoles);
		array_init(&rebuiltRoles);
		zephir_array_fetch_string(&_36$$21, &data, SL("roles"), PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Storage.zep", 134);
		zephir_is_iterable(&_36$$21, 0, "phalcon/Acl/Adapter/Storage.zep", 138);
		if (Z_TYPE_P(&_36$$21) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_36$$21), _38$$21, _39$$21, _37$$21)
			{
				ZEPHIR_INIT_NVAR(&name);
				if (_39$$21 != NULL) { 
					ZVAL_STR_COPY(&name, _39$$21);
				} else {
					ZVAL_LONG(&name, _38$$21);
				}
				ZEPHIR_INIT_NVAR(&description);
				ZVAL_COPY(&description, _37$$21);
				ZEPHIR_INIT_NVAR(&_40$$22);
				object_init_ex(&_40$$22, phalcon_acl_role_ce);
				ZEPHIR_CALL_METHOD(NULL, &_40$$22, "__construct", &_41, 238, &name, &description);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_array_update_zval(&rebuiltRoles, &name, &_40$$22, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_36$$21, "rewind", NULL, 0);
			zephir_check_call_status();
			_43$$21 = 1;
			while (1) {
				if (_43$$21) {
					_43$$21 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &_36$$21, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_42$$21, &_36$$21, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_42$$21)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&name, &_36$$21, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&description, &_36$$21, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_44$$23);
					object_init_ex(&_44$$23, phalcon_acl_role_ce);
					ZEPHIR_CALL_METHOD(NULL, &_44$$23, "__construct", &_41, 238, &name, &description);
					zephir_check_call_status_or_jump(try_end_1);
					zephir_array_update_zval(&rebuiltRoles, &name, &_44$$23, PH_COPY | PH_SEPARATE);
			}
		}
		ZEPHIR_INIT_NVAR(&description);
		ZEPHIR_INIT_NVAR(&name);
		ZEPHIR_INIT_VAR(&rebuiltComponents);
		array_init(&rebuiltComponents);
		zephir_array_fetch_string(&_45$$21, &data, SL("components"), PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Storage.zep", 139);
		zephir_is_iterable(&_45$$21, 0, "phalcon/Acl/Adapter/Storage.zep", 142);
		if (Z_TYPE_P(&_45$$21) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_45$$21), _47$$21, _48$$21, _46$$21)
			{
				ZEPHIR_INIT_NVAR(&name);
				if (_48$$21 != NULL) { 
					ZVAL_STR_COPY(&name, _48$$21);
				} else {
					ZVAL_LONG(&name, _47$$21);
				}
				ZEPHIR_INIT_NVAR(&description);
				ZVAL_COPY(&description, _46$$21);
				ZEPHIR_INIT_NVAR(&_49$$24);
				object_init_ex(&_49$$24, phalcon_acl_component_ce);
				ZEPHIR_CALL_METHOD(NULL, &_49$$24, "__construct", &_50, 229, &name, &description);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_array_update_zval(&rebuiltComponents, &name, &_49$$24, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_45$$21, "rewind", NULL, 0);
			zephir_check_call_status();
			_52$$21 = 1;
			while (1) {
				if (_52$$21) {
					_52$$21 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &_45$$21, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_51$$21, &_45$$21, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_51$$21)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&name, &_45$$21, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&description, &_45$$21, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_53$$25);
					object_init_ex(&_53$$25, phalcon_acl_component_ce);
					ZEPHIR_CALL_METHOD(NULL, &_53$$25, "__construct", &_50, 229, &name, &description);
					zephir_check_call_status_or_jump(try_end_1);
					zephir_array_update_zval(&rebuiltComponents, &name, &_53$$25, PH_COPY | PH_SEPARATE);
			}
		}
		ZEPHIR_INIT_NVAR(&description);
		ZEPHIR_INIT_NVAR(&name);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_54);
		ZVAL_OBJ(&_54, EG(exception));
		Z_ADDREF_P(&_54);
		if (zephir_is_instance_of(&_54, SL("Throwable"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&e, &_54);
			ZEPHIR_INIT_VAR(&_55$$26);
			object_init_ex(&_55$$26, phalcon_acl_exceptions_invalidsnapshot_ce);
			ZEPHIR_CALL_METHOD(&_56$$26, &e, "getmessage", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_57$$26);
			ZEPHIR_CONCAT_SV(&_57$$26, "Malformed ACL snapshot element: ", &_56$$26);
			ZEPHIR_CALL_METHOD(NULL, &_55$$26, "__construct", NULL, 9, &_57$$26);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_55$$26, "phalcon/Acl/Adapter/Storage.zep", 145);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_array_fetch_string(&_58, &data, SL("access"), PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Storage.zep", 148);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 382, &_58);
	zephir_array_fetch_string(&_59, &data, SL("accessList"), PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Storage.zep", 149);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 383, &_59);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 384, &rebuiltComponents);
	zephir_array_fetch_string(&_60, &data, SL("componentsNames"), PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Storage.zep", 151);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 385, &_60);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 386, &rebuiltRoles);
	zephir_array_fetch_string(&_61, &data, SL("roleInherits"), PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Storage.zep", 153);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 387, &_61);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_8, 388, &defaultAccess);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_9, 389, &noArgumentsDefaultAction);
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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	static zend_string *_zephir_prop_7 = NULL;
	static zend_string *_zephir_prop_8 = NULL;
	static zend_string *_zephir_prop_9 = NULL;
	static zend_string *_zephir_prop_10 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("access", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("functions", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("components", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("roles", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("storage", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("key", 3, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("accessList", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_7)) {
		_zephir_prop_7 = zend_string_init("componentsNames", 15, 1);
	}
	if (UNEXPECTED(!_zephir_prop_8)) {
		_zephir_prop_8 = zend_string_init("roleInherits", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_9)) {
		_zephir_prop_9 = zend_string_init("defaultAccess", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_10)) {
		_zephir_prop_10 = zend_string_init("noArgumentsDefaultAction", 24, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 382, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&access, &_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 390, PH_NOISY_CC | PH_READONLY);
	zephir_array_keys(&_1, &_0);
	zephir_is_iterable(&_1, 0, "phalcon/Acl/Adapter/Storage.zep", 175);
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
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_2, 384, PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_4, 0, "phalcon/Acl/Adapter/Storage.zep", 180);
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
	zephir_read_property_cached(&_12, this_ptr, _zephir_prop_3, 386, PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_12, 0, "phalcon/Acl/Adapter/Storage.zep", 185);
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
	zephir_read_property_cached(&_20, this_ptr, _zephir_prop_4, 380, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_21, this_ptr, _zephir_prop_5, 381, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_22);
	zephir_create_array(&_22, 9, 0);
	add_assoc_long_ex(&_22, SL("version"), 1);
	zephir_array_update_string(&_22, SL("access"), &access, PH_COPY | PH_SEPARATE);
	zephir_memory_observe(&_23);
	zephir_read_property_cached(&_23, this_ptr, _zephir_prop_6, 383, PH_NOISY_CC);
	zephir_array_update_string(&_22, SL("accessList"), &_23, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_22, SL("components"), &components, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_23);
	zephir_read_property_cached(&_23, this_ptr, _zephir_prop_7, 385, PH_NOISY_CC);
	zephir_array_update_string(&_22, SL("componentsNames"), &_23, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_22, SL("roles"), &roles, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_23);
	zephir_read_property_cached(&_23, this_ptr, _zephir_prop_8, 387, PH_NOISY_CC);
	zephir_array_update_string(&_22, SL("roleInherits"), &_23, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_23);
	zephir_read_property_cached(&_23, this_ptr, _zephir_prop_9, 388, PH_NOISY_CC);
	zephir_array_update_string(&_22, SL("defaultAccess"), &_23, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_23);
	zephir_read_property_cached(&_23, this_ptr, _zephir_prop_10, 389, PH_NOISY_CC);
	zephir_array_update_string(&_22, SL("noArgumentsDefaultAction"), &_23, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(&_20, "set", NULL, 0, &_21, &_22);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Recursively converts stdClass into nested arrays so a snapshot stored
 * through an object-decoding serializer (e.g. JSON) is read back the same
 * way as the array-decoding serializers (php, igbinary, msgpack). A
 * snapshot is at most three levels deep; a deeper (or cyclic) graph is
 * rejected.
 */
PHP_METHOD(Phalcon_Acl_Adapter_Storage, normalizeToArray)
{
	zend_bool _8;
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long depth, ZEPHIR_LAST_CALL_STATUS;
	zval *value = NULL, value_sub, *depth_param = NULL, item, key, result, *_1, _7, _0$$4, _4$$6, _5$$6, _9$$7, _10$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(value)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(depth)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &value, &depth_param);
	ZEPHIR_SEPARATE_PARAM(value);
	if (!depth_param) {
		depth = 0;
	} else {
		}
	if (UNEXPECTED(depth > 4)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_invalidsnapshot_ce, "ACL snapshot nesting is too deep", "phalcon/Acl/Adapter/Storage.zep", 213);
		return;
	}
	if (Z_TYPE_P(value) == IS_OBJECT) {
		ZEPHIR_CALL_FUNCTION(&_0$$4, "get_object_vars", NULL, 357, value);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(value, &_0$$4);
	}
	if (Z_TYPE_P(value) != IS_ARRAY) {
		RETVAL_ZVAL(value, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	zephir_is_iterable(value, 0, "phalcon/Acl/Adapter/Storage.zep", 229);
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
			ZVAL_LONG(&_5$$6, (depth + 1));
			ZEPHIR_CALL_METHOD(&_4$$6, this_ptr, "normalizetoarray", &_6, 356, &item, &_5$$6);
			zephir_check_call_status();
			zephir_array_update_zval(&result, &key, &_4$$6, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, value, "rewind", NULL, 0);
		zephir_check_call_status();
		_8 = 1;
		while (1) {
			if (_8) {
				_8 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, value, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_7, value, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, value, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&item, value, "current", NULL, 0);
			zephir_check_call_status();
				ZVAL_LONG(&_10$$7, (depth + 1));
				ZEPHIR_CALL_METHOD(&_9$$7, this_ptr, "normalizetoarray", &_6, 356, &item, &_10$$7);
				zephir_check_call_status();
				zephir_array_update_zval(&result, &key, &_9$$7, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&result);
}

