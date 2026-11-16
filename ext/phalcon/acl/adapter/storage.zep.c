
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
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 386, storage);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 387, &key_zv);
	ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "load", &_zephir_call_cache[0]);
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
	zend_string *_28, *_50$$21, *_60$$21;
	zend_ulong _27, _49$$21, _59$$21;
	zend_bool _3, _8, _10, _12, _14, _16, _18, _19, _20, _21, _22, _37, _34$$9, _32$$11, _35$$13, _43$$15, _41$$17, _44$$19, _53$$21, _63$$21;
	zval data, version, name, description, rebuiltRoles, rebuiltComponents, defaultAccess, noArgumentsDefaultAction, inherits, inherit, e, _0, _1, _7, _9, _11, _13, _15, _17, _23, *_24, _25, *_26, _36, _65, _69, _70, _71, _72, _2$$3, _4$$6, _5$$6, _6$$6, *_29$$9, _30$$9, *_31$$9, _33$$9, *_38$$15, _39$$15, *_40$$15, _42$$15, _45$$21, *_46$$21, _47$$21, *_48$$21, _52$$21, _55$$21, *_56$$21, _57$$21, *_58$$21, _62$$21, _51$$22, _54$$23, _61$$24, _64$$25, _66$$26, _67$$26, _68$$26;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&_65);
	ZVAL_UNDEF(&_69);
	ZVAL_UNDEF(&_70);
	ZVAL_UNDEF(&_71);
	ZVAL_UNDEF(&_72);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_30$$9);
	ZVAL_UNDEF(&_33$$9);
	ZVAL_UNDEF(&_39$$15);
	ZVAL_UNDEF(&_42$$15);
	ZVAL_UNDEF(&_45$$21);
	ZVAL_UNDEF(&_47$$21);
	ZVAL_UNDEF(&_52$$21);
	ZVAL_UNDEF(&_55$$21);
	ZVAL_UNDEF(&_57$$21);
	ZVAL_UNDEF(&_62$$21);
	ZVAL_UNDEF(&_51$$22);
	ZVAL_UNDEF(&_54$$23);
	ZVAL_UNDEF(&_61$$24);
	ZVAL_UNDEF(&_64$$25);
	ZVAL_UNDEF(&_66$$26);
	ZVAL_UNDEF(&_67$$26);
	ZVAL_UNDEF(&_68$$26);
	ZEND_TLS zephir_method_cache _zephir_call_cache[32];
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

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 386, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 387, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&data, &_0, "get", &_zephir_call_cache[0], &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(&data) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD_CACHED(&_2$$3, this_ptr, "normalizeToArray", &_zephir_call_cache[1], &data);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&data, &_2$$3);
	}
	if (Z_TYPE_P(&data) != IS_ARRAY) {
		RETURN_MM_BOOL(0);
	}
	_3 = zephir_array_isset_value_string(&data, SL("version"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_3)) {
		RETURN_MM_BOOL(0);
	}
	zephir_memory_observe(&version);
	zephir_array_fetch_string(&version, &data, SL("version"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 86);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!ZEPHIR_IS_LONG(&version, 1)) {
		ZEPHIR_INIT_VAR(&_4$$6);
		object_init_ex(&_4$$6, phalcon_acl_exceptions_invalidsnapshot_ce);
		ZEPHIR_INIT_VAR(&_5$$6);
		ZVAL_LONG(&_5$$6, 1);
		ZEPHIR_INIT_VAR(&_6$$6);
		ZEPHIR_CONCAT_SVSVS(&_6$$6, "Incompatible ACL snapshot version '", &version, "'; expected '", &_5$$6, "'");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_4$$6, "__construct", &_zephir_call_cache[2], &_6$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$6, "phalcon/Acl/Adapter/Storage.zep", 92);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&_7);
	zephir_array_fetch_string(&_7, &data, SL("access"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 96);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_8 = Z_TYPE_P(&_7) != IS_ARRAY;
	if (!(_8)) {
		zephir_memory_observe(&_9);
		zephir_array_fetch_string(&_9, &data, SL("accessList"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 97);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_8 = Z_TYPE_P(&_9) != IS_ARRAY;
	}
	_10 = _8;
	if (!(_10)) {
		zephir_memory_observe(&_11);
		zephir_array_fetch_string(&_11, &data, SL("components"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 98);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_10 = Z_TYPE_P(&_11) != IS_ARRAY;
	}
	_12 = _10;
	if (!(_12)) {
		zephir_memory_observe(&_13);
		zephir_array_fetch_string(&_13, &data, SL("componentsNames"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 99);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_12 = Z_TYPE_P(&_13) != IS_ARRAY;
	}
	_14 = _12;
	if (!(_14)) {
		zephir_memory_observe(&_15);
		zephir_array_fetch_string(&_15, &data, SL("roles"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 100);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_14 = Z_TYPE_P(&_15) != IS_ARRAY;
	}
	_16 = _14;
	if (!(_16)) {
		zephir_memory_observe(&_17);
		zephir_array_fetch_string(&_17, &data, SL("roleInherits"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 101);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_16 = Z_TYPE_P(&_17) != IS_ARRAY;
	}
	if (UNEXPECTED(_16)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_invalidsnapshot_ce, "Malformed ACL snapshot structure", "phalcon/Acl/Adapter/Storage.zep", 103);
		return;
	}
	_18 = zephir_array_isset_value_string(&data, SL("defaultAccess"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_18) {
		zephir_memory_observe(&defaultAccess);
		zephir_array_fetch_string(&defaultAccess, &data, SL("defaultAccess"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 110);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_INIT_NVAR(&defaultAccess);
		ZVAL_LONG(&defaultAccess, 0);
	}
	_19 = zephir_array_isset_value_string(&data, SL("noArgumentsDefaultAction"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_19) {
		zephir_memory_observe(&noArgumentsDefaultAction);
		zephir_array_fetch_string(&noArgumentsDefaultAction, &data, SL("noArgumentsDefaultAction"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 111);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_INIT_NVAR(&noArgumentsDefaultAction);
		ZVAL_LONG(&noArgumentsDefaultAction, 0);
	}
	_20 = !ZEPHIR_IS_LONG_IDENTICAL(&defaultAccess, 1);
	if (_20) {
		_20 = !ZEPHIR_IS_LONG_IDENTICAL(&defaultAccess, 0);
	}
	_21 = _20;
	if (!(_21)) {
		_22 = !ZEPHIR_IS_LONG_IDENTICAL(&noArgumentsDefaultAction, 1);
		if (_22) {
			_22 = !ZEPHIR_IS_LONG_IDENTICAL(&noArgumentsDefaultAction, 0);
		}
		_21 = _22;
	}
	if (UNEXPECTED(_21)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_invalidsnapshot_ce, "Malformed ACL snapshot default action", "phalcon/Acl/Adapter/Storage.zep", 117);
		return;
	}
	zephir_memory_observe(&_23);
	zephir_array_fetch_string(&_23, &data, SL("roleInherits"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 120);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_23) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_25);
		zephir_string_to_char_array(&_25, &_23);
		_24 = &_25;
	} else {
		_24 = &_23;
	}
	zephir_is_iterable(_24, 0, "phalcon/Acl/Adapter/Storage.zep", 133);
	if (Z_TYPE_P(_24) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_24), _27, _28, _26)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_28 != NULL) { 
				ZVAL_STR_COPY(&name, _28);
			} else {
				ZVAL_LONG(&name, _27);
			}
			ZEPHIR_INIT_NVAR(&inherits);
			ZVAL_COPY(&inherits, _26);
			if (UNEXPECTED(Z_TYPE_P(&inherits) != IS_ARRAY)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_invalidsnapshot_ce, "Malformed ACL snapshot role inheritance", "phalcon/Acl/Adapter/Storage.zep", 122);
				return;
			}
			if (Z_TYPE_P(&inherits) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_30$$9);
				zephir_string_to_char_array(&_30$$9, &inherits);
				_29$$9 = &_30$$9;
			} else {
				_29$$9 = &inherits;
			}
			zephir_is_iterable(_29$$9, 0, "phalcon/Acl/Adapter/Storage.zep", 130);
			if (Z_TYPE_P(_29$$9) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_29$$9), _31$$9)
				{
					ZEPHIR_INIT_NVAR(&inherit);
					ZVAL_COPY(&inherit, _31$$9);
					_32$$11 = Z_TYPE_P(&inherit) != IS_STRING;
					if (_32$$11) {
						_32$$11 = Z_TYPE_P(&inherit) != IS_LONG;
					}
					if (UNEXPECTED(_32$$11)) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_invalidsnapshot_ce, "Malformed ACL snapshot role inheritance", "phalcon/Acl/Adapter/Storage.zep", 127);
						return;
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _29$$9, "rewind", &_zephir_call_cache[3]);
				zephir_check_call_status();
				_34$$9 = 1;
				while (1) {
					if (_34$$9) {
						_34$$9 = 0;
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _29$$9, "next", &_zephir_call_cache[4]);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD_CACHED(&_33$$9, _29$$9, "valid", &_zephir_call_cache[5]);
					zephir_check_call_status();
					if (!zend_is_true(&_33$$9)) {
						break;
					}
					ZEPHIR_CALL_METHOD_CACHED(&inherit, _29$$9, "current", &_zephir_call_cache[6]);
					zephir_check_call_status();
						_35$$13 = Z_TYPE_P(&inherit) != IS_STRING;
						if (_35$$13) {
							_35$$13 = Z_TYPE_P(&inherit) != IS_LONG;
						}
						if (UNEXPECTED(_35$$13)) {
							ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_invalidsnapshot_ce, "Malformed ACL snapshot role inheritance", "phalcon/Acl/Adapter/Storage.zep", 127);
							return;
						}
				}
			}
			ZEPHIR_INIT_NVAR(&inherit);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _24, "rewind", &_zephir_call_cache[7]);
		zephir_check_call_status();
		_37 = 1;
		while (1) {
			if (_37) {
				_37 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _24, "next", &_zephir_call_cache[8]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_36, _24, "valid", &_zephir_call_cache[9]);
			zephir_check_call_status();
			if (!zend_is_true(&_36)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&name, _24, "key", &_zephir_call_cache[10]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&inherits, _24, "current", &_zephir_call_cache[11]);
			zephir_check_call_status();
				if (UNEXPECTED(Z_TYPE_P(&inherits) != IS_ARRAY)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_invalidsnapshot_ce, "Malformed ACL snapshot role inheritance", "phalcon/Acl/Adapter/Storage.zep", 122);
					return;
				}
				if (Z_TYPE_P(&inherits) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_39$$15);
					zephir_string_to_char_array(&_39$$15, &inherits);
					_38$$15 = &_39$$15;
				} else {
					_38$$15 = &inherits;
				}
				zephir_is_iterable(_38$$15, 0, "phalcon/Acl/Adapter/Storage.zep", 130);
				if (Z_TYPE_P(_38$$15) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_38$$15), _40$$15)
					{
						ZEPHIR_INIT_NVAR(&inherit);
						ZVAL_COPY(&inherit, _40$$15);
						_41$$17 = Z_TYPE_P(&inherit) != IS_STRING;
						if (_41$$17) {
							_41$$17 = Z_TYPE_P(&inherit) != IS_LONG;
						}
						if (UNEXPECTED(_41$$17)) {
							ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_invalidsnapshot_ce, "Malformed ACL snapshot role inheritance", "phalcon/Acl/Adapter/Storage.zep", 127);
							return;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _38$$15, "rewind", &_zephir_call_cache[12]);
					zephir_check_call_status();
					_43$$15 = 1;
					while (1) {
						if (_43$$15) {
							_43$$15 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _38$$15, "next", &_zephir_call_cache[13]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_42$$15, _38$$15, "valid", &_zephir_call_cache[14]);
						zephir_check_call_status();
						if (!zend_is_true(&_42$$15)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&inherit, _38$$15, "current", &_zephir_call_cache[15]);
						zephir_check_call_status();
							_44$$19 = Z_TYPE_P(&inherit) != IS_STRING;
							if (_44$$19) {
								_44$$19 = Z_TYPE_P(&inherit) != IS_LONG;
							}
							if (UNEXPECTED(_44$$19)) {
								ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_invalidsnapshot_ce, "Malformed ACL snapshot role inheritance", "phalcon/Acl/Adapter/Storage.zep", 127);
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
		zephir_memory_observe(&_45$$21);
		zephir_array_fetch_string(&_45$$21, &data, SL("roles"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 135);
		if (UNEXPECTED(EG(exception))) {
			goto try_end_1;
		}
		if (Z_TYPE_P(&_45$$21) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_47$$21);
			zephir_string_to_char_array(&_47$$21, &_45$$21);
			_46$$21 = &_47$$21;
		} else {
			_46$$21 = &_45$$21;
		}
		zephir_is_iterable(_46$$21, 0, "phalcon/Acl/Adapter/Storage.zep", 139);
		if (Z_TYPE_P(_46$$21) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_46$$21), _49$$21, _50$$21, _48$$21)
			{
				ZEPHIR_INIT_NVAR(&name);
				if (_50$$21 != NULL) { 
					ZVAL_STR_COPY(&name, _50$$21);
				} else {
					ZVAL_LONG(&name, _49$$21);
				}
				ZEPHIR_INIT_NVAR(&description);
				ZVAL_COPY(&description, _48$$21);
				ZEPHIR_INIT_NVAR(&_51$$22);
				object_init_ex(&_51$$22, phalcon_acl_role_ce);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_51$$22, "__construct", &_zephir_call_cache[16], &name, &description);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_array_update_zval(&rebuiltRoles, &name, &_51$$22, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					goto try_end_1;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _46$$21, "rewind", &_zephir_call_cache[17]);
			zephir_check_call_status();
			_53$$21 = 1;
			while (1) {
				if (_53$$21) {
					_53$$21 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _46$$21, "next", &_zephir_call_cache[18]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_52$$21, _46$$21, "valid", &_zephir_call_cache[19]);
				zephir_check_call_status();
				if (!zend_is_true(&_52$$21)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&name, _46$$21, "key", &_zephir_call_cache[20]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&description, _46$$21, "current", &_zephir_call_cache[21]);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_54$$23);
					object_init_ex(&_54$$23, phalcon_acl_role_ce);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_54$$23, "__construct", &_zephir_call_cache[22], &name, &description);
					zephir_check_call_status_or_jump(try_end_1);
					zephir_array_update_zval(&rebuiltRoles, &name, &_54$$23, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						goto try_end_1;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&description);
		ZEPHIR_INIT_NVAR(&name);
		ZEPHIR_INIT_VAR(&rebuiltComponents);
		array_init(&rebuiltComponents);
		zephir_memory_observe(&_55$$21);
		zephir_array_fetch_string(&_55$$21, &data, SL("components"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 140);
		if (UNEXPECTED(EG(exception))) {
			goto try_end_1;
		}
		if (Z_TYPE_P(&_55$$21) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_57$$21);
			zephir_string_to_char_array(&_57$$21, &_55$$21);
			_56$$21 = &_57$$21;
		} else {
			_56$$21 = &_55$$21;
		}
		zephir_is_iterable(_56$$21, 0, "phalcon/Acl/Adapter/Storage.zep", 143);
		if (Z_TYPE_P(_56$$21) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_56$$21), _59$$21, _60$$21, _58$$21)
			{
				ZEPHIR_INIT_NVAR(&name);
				if (_60$$21 != NULL) { 
					ZVAL_STR_COPY(&name, _60$$21);
				} else {
					ZVAL_LONG(&name, _59$$21);
				}
				ZEPHIR_INIT_NVAR(&description);
				ZVAL_COPY(&description, _58$$21);
				ZEPHIR_INIT_NVAR(&_61$$24);
				object_init_ex(&_61$$24, phalcon_acl_component_ce);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_61$$24, "__construct", &_zephir_call_cache[23], &name, &description);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_array_update_zval(&rebuiltComponents, &name, &_61$$24, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					goto try_end_1;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _56$$21, "rewind", &_zephir_call_cache[24]);
			zephir_check_call_status();
			_63$$21 = 1;
			while (1) {
				if (_63$$21) {
					_63$$21 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _56$$21, "next", &_zephir_call_cache[25]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_62$$21, _56$$21, "valid", &_zephir_call_cache[26]);
				zephir_check_call_status();
				if (!zend_is_true(&_62$$21)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&name, _56$$21, "key", &_zephir_call_cache[27]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&description, _56$$21, "current", &_zephir_call_cache[28]);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_64$$25);
					object_init_ex(&_64$$25, phalcon_acl_component_ce);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_64$$25, "__construct", &_zephir_call_cache[29], &name, &description);
					zephir_check_call_status_or_jump(try_end_1);
					zephir_array_update_zval(&rebuiltComponents, &name, &_64$$25, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						goto try_end_1;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&description);
		ZEPHIR_INIT_NVAR(&name);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_65);
		ZVAL_OBJ(&_65, EG(exception));
		Z_ADDREF_P(&_65);
		if (zephir_is_instance_of(&_65, SL("Throwable"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&e, &_65);
			ZEPHIR_INIT_VAR(&_66$$26);
			object_init_ex(&_66$$26, phalcon_acl_exceptions_invalidsnapshot_ce);
			ZEPHIR_CALL_METHOD_CACHED(&_67$$26, &e, "getMessage", &_zephir_call_cache[30]);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_68$$26);
			ZEPHIR_CONCAT_SV(&_68$$26, "Malformed ACL snapshot element: ", &_67$$26);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_66$$26, "__construct", &_zephir_call_cache[31], &_68$$26);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_66$$26, "phalcon/Acl/Adapter/Storage.zep", 146);
			ZEPHIR_MM_RESTORE();
			return;
		} else {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_memory_observe(&_69);
	zephir_array_fetch_string(&_69, &data, SL("access"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 149);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 388, &_69);
	zephir_memory_observe(&_70);
	zephir_array_fetch_string(&_70, &data, SL("accessList"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 150);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 389, &_70);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 390, &rebuiltComponents);
	zephir_memory_observe(&_71);
	zephir_array_fetch_string(&_71, &data, SL("componentsNames"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 152);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 391, &_71);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 392, &rebuiltRoles);
	zephir_memory_observe(&_72);
	zephir_array_fetch_string(&_72, &data, SL("roleInherits"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 154);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 393, &_72);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_8, 394, &defaultAccess);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_9, 395, &noArgumentsDefaultAction);
	RETURN_MM_BOOL(1);
}

/**
 * Persists the policy snapshot. Closure-backed access keys are written as
 * DENY (fail closed); roles/components are written as scalar name =>
 * description maps for serializer independence.
 */
PHP_METHOD(Phalcon_Acl_Adapter_Storage, save)
{
	zval _28;
	zend_bool _14, _24;
	zend_string *_11, *_21;
	zend_ulong _10, _20;
	zval accessKey, componentName, componentObject, roleName, roleObject, access, components, roles, _0, _1, *_2, _3, *_4, _6, *_7, _8, *_9, _13, _16, *_17, _18, *_19, _23, _26, _27, _29, _5$$3, _12$$4, _15$$5, _22$$6, _25$$7;
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
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_22$$6);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_28);
	ZEND_TLS zephir_method_cache _zephir_call_cache[15];
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

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 388, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&access, &_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 396, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_keys(&_1, &_0);
	if (Z_TYPE_P(&_1) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_3);
		zephir_string_to_char_array(&_3, &_1);
		_2 = &_3;
	} else {
		_2 = &_1;
	}
	zephir_is_iterable(_2, 0, "phalcon/Acl/Adapter/Storage.zep", 176);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_2), _4)
	{
		ZEPHIR_INIT_NVAR(&accessKey);
		ZVAL_COPY(&accessKey, _4);
		ZEPHIR_INIT_NVAR(&_5$$3);
		ZVAL_LONG(&_5$$3, 0);
		zephir_array_update_zval(&access, &accessKey, &_5$$3, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&accessKey);
	ZEPHIR_INIT_VAR(&components);
	array_init(&components);
	zephir_read_property_cached(&_6, this_ptr, _zephir_prop_2, 390, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_6) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_8);
		zephir_string_to_char_array(&_8, &_6);
		_7 = &_8;
	} else {
		_7 = &_6;
	}
	zephir_is_iterable(_7, 0, "phalcon/Acl/Adapter/Storage.zep", 181);
	if (Z_TYPE_P(_7) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_7), _10, _11, _9)
		{
			ZEPHIR_INIT_NVAR(&componentName);
			if (_11 != NULL) { 
				ZVAL_STR_COPY(&componentName, _11);
			} else {
				ZVAL_LONG(&componentName, _10);
			}
			ZEPHIR_INIT_NVAR(&componentObject);
			ZVAL_COPY(&componentObject, _9);
			ZEPHIR_CALL_METHOD_CACHED(&_12$$4, &componentObject, "getDescription", &_zephir_call_cache[0]);
			zephir_check_call_status();
			zephir_array_update_zval(&components, &componentName, &_12$$4, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _7, "rewind", &_zephir_call_cache[1]);
		zephir_check_call_status();
		_14 = 1;
		while (1) {
			if (_14) {
				_14 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _7, "next", &_zephir_call_cache[2]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_13, _7, "valid", &_zephir_call_cache[3]);
			zephir_check_call_status();
			if (!zend_is_true(&_13)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&componentName, _7, "key", &_zephir_call_cache[4]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&componentObject, _7, "current", &_zephir_call_cache[5]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_15$$5, &componentObject, "getDescription", &_zephir_call_cache[6]);
				zephir_check_call_status();
				zephir_array_update_zval(&components, &componentName, &_15$$5, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&componentObject);
	ZEPHIR_INIT_NVAR(&componentName);
	ZEPHIR_INIT_VAR(&roles);
	array_init(&roles);
	zephir_read_property_cached(&_16, this_ptr, _zephir_prop_3, 392, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_16) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_18);
		zephir_string_to_char_array(&_18, &_16);
		_17 = &_18;
	} else {
		_17 = &_16;
	}
	zephir_is_iterable(_17, 0, "phalcon/Acl/Adapter/Storage.zep", 186);
	if (Z_TYPE_P(_17) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_17), _20, _21, _19)
		{
			ZEPHIR_INIT_NVAR(&roleName);
			if (_21 != NULL) { 
				ZVAL_STR_COPY(&roleName, _21);
			} else {
				ZVAL_LONG(&roleName, _20);
			}
			ZEPHIR_INIT_NVAR(&roleObject);
			ZVAL_COPY(&roleObject, _19);
			ZEPHIR_CALL_METHOD_CACHED(&_22$$6, &roleObject, "getDescription", &_zephir_call_cache[7]);
			zephir_check_call_status();
			zephir_array_update_zval(&roles, &roleName, &_22$$6, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _17, "rewind", &_zephir_call_cache[8]);
		zephir_check_call_status();
		_24 = 1;
		while (1) {
			if (_24) {
				_24 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _17, "next", &_zephir_call_cache[9]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_23, _17, "valid", &_zephir_call_cache[10]);
			zephir_check_call_status();
			if (!zend_is_true(&_23)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&roleName, _17, "key", &_zephir_call_cache[11]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&roleObject, _17, "current", &_zephir_call_cache[12]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_25$$7, &roleObject, "getDescription", &_zephir_call_cache[13]);
				zephir_check_call_status();
				zephir_array_update_zval(&roles, &roleName, &_25$$7, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&roleObject);
	ZEPHIR_INIT_NVAR(&roleName);
	zephir_read_property_cached(&_26, this_ptr, _zephir_prop_4, 386, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_27, this_ptr, _zephir_prop_5, 387, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_28);
	zephir_create_array(&_28, 9, 0);
	add_assoc_long_ex(&_28, SL("version"), 1);
	zephir_array_update_string(&_28, SL("access"), &access, PH_COPY | PH_SEPARATE);
	zephir_memory_observe(&_29);
	zephir_read_property_cached(&_29, this_ptr, _zephir_prop_6, 389, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(&_28, SL("accessList"), &_29, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_28, SL("components"), &components, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_29);
	zephir_read_property_cached(&_29, this_ptr, _zephir_prop_7, 391, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(&_28, SL("componentsNames"), &_29, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_28, SL("roles"), &roles, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_29);
	zephir_read_property_cached(&_29, this_ptr, _zephir_prop_8, 393, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(&_28, SL("roleInherits"), &_29, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_29);
	zephir_read_property_cached(&_29, this_ptr, _zephir_prop_9, 394, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(&_28, SL("defaultAccess"), &_29, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_29);
	zephir_read_property_cached(&_29, this_ptr, _zephir_prop_10, 395, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(&_28, SL("noArgumentsDefaultAction"), &_29, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD_CACHED(&_26, "set", &_zephir_call_cache[14], &_27, &_28);
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
	zend_bool _9;
	zend_string *_5;
	zend_ulong _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long depth, ZEPHIR_LAST_CALL_STATUS;
	zval *value = NULL, value_sub, *depth_param = NULL, item, key, result, *_1, _2, *_3, _8, _0$$4, _6$$6, _7$$6, _10$$7, _11$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZEND_TLS zephir_method_cache _zephir_call_cache[7];
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_invalidsnapshot_ce, "ACL snapshot nesting is too deep", "phalcon/Acl/Adapter/Storage.zep", 214);
		return;
	}
	if (Z_TYPE_P(value) == IS_OBJECT) {
		ZEPHIR_CALL_FUNCTION(&_0$$4, "get_object_vars", NULL, 107, value);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(value, &_0$$4);
	}
	if (Z_TYPE_P(value) != IS_ARRAY) {
		RETVAL_ZVAL(value, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	if (Z_TYPE_P(value) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, value);
		_1 = &_2;
	} else {
		_1 = value;
	}
	zephir_is_iterable(_1, 0, "phalcon/Acl/Adapter/Storage.zep", 230);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_1), _4, _5, _3)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&key, _5);
			} else {
				ZVAL_LONG(&key, _4);
			}
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _3);
			ZVAL_LONG(&_7$$6, (depth + 1));
			ZEPHIR_CALL_METHOD_CACHED(&_6$$6, this_ptr, "normalizeToArray", &_zephir_call_cache[0], &item, &_7$$6);
			zephir_check_call_status();
			zephir_array_update_zval(&result, &key, &_6$$6, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "rewind", &_zephir_call_cache[1]);
		zephir_check_call_status();
		_9 = 1;
		while (1) {
			if (_9) {
				_9 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "next", &_zephir_call_cache[2]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_8, _1, "valid", &_zephir_call_cache[3]);
			zephir_check_call_status();
			if (!zend_is_true(&_8)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&key, _1, "key", &_zephir_call_cache[4]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&item, _1, "current", &_zephir_call_cache[5]);
			zephir_check_call_status();
				ZVAL_LONG(&_11$$7, (depth + 1));
				ZEPHIR_CALL_METHOD_CACHED(&_10$$7, this_ptr, "normalizeToArray", &_zephir_call_cache[6], &item, &_11$$7);
				zephir_check_call_status();
				zephir_array_update_zval(&result, &key, &_10$$7, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&result);
}

