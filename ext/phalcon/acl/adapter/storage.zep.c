
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
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 387, &key_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
	zend_string *_33, *_55$$22, *_65$$22;
	zend_ulong _32, _54$$22, _64$$22;
	zend_bool _3, _4, _13, _15, _17, _19, _21, _23, _24, _25, _26, _27, _42, _39$$10, _37$$12, _40$$14, _48$$16, _46$$18, _49$$20, _58$$22, _68$$22;
	zval data, version, name, description, rebuiltRoles, rebuiltComponents, defaultAccess, noArgumentsDefaultAction, inherits, inherit, e, _0, _1, _12, _14, _16, _18, _20, _22, _28, *_29, _30, *_31, _41, _70, _74, _75, _76, _77, _2$$3, _5$$6, _6$$6, _7$$6, _8$$6, _9$$7, _10$$7, _11$$7, *_34$$10, _35$$10, *_36$$10, _38$$10, *_43$$16, _44$$16, *_45$$16, _47$$16, _50$$22, *_51$$22, _52$$22, *_53$$22, _57$$22, _60$$22, *_61$$22, _62$$22, *_63$$22, _67$$22, _56$$23, _59$$24, _66$$25, _69$$26, _71$$27, _72$$27, _73$$27;
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
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_41);
	ZVAL_UNDEF(&_70);
	ZVAL_UNDEF(&_74);
	ZVAL_UNDEF(&_75);
	ZVAL_UNDEF(&_76);
	ZVAL_UNDEF(&_77);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_35$$10);
	ZVAL_UNDEF(&_38$$10);
	ZVAL_UNDEF(&_44$$16);
	ZVAL_UNDEF(&_47$$16);
	ZVAL_UNDEF(&_50$$22);
	ZVAL_UNDEF(&_52$$22);
	ZVAL_UNDEF(&_57$$22);
	ZVAL_UNDEF(&_60$$22);
	ZVAL_UNDEF(&_62$$22);
	ZVAL_UNDEF(&_67$$22);
	ZVAL_UNDEF(&_56$$23);
	ZVAL_UNDEF(&_59$$24);
	ZVAL_UNDEF(&_66$$25);
	ZVAL_UNDEF(&_69$$26);
	ZVAL_UNDEF(&_71$$27);
	ZVAL_UNDEF(&_72$$27);
	ZVAL_UNDEF(&_73$$27);
	ZEND_TLS zephir_method_cache _zephir_call_cache[33];
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
	_4 = Z_TYPE_P(&version) != IS_LONG;
	if (_4) {
		_4 = Z_TYPE_P(&version) != IS_STRING;
	}
	if (UNEXPECTED(_4)) {
		ZEPHIR_INIT_VAR(&_5$$6);
		object_init_ex(&_5$$6, phalcon_acl_exceptions_invalidsnapshot_ce);
		zephir_constructor_start(&_5$$6);
		ZEPHIR_INIT_VAR(&_6$$6);
		zephir_gettype(&_6$$6, &version);
		ZEPHIR_INIT_VAR(&_7$$6);
		ZVAL_LONG(&_7$$6, 1);
		ZEPHIR_INIT_VAR(&_8$$6);
		ZEPHIR_CONCAT_SVSVS(&_8$$6, "Incompatible ACL snapshot version of type '", &_6$$6, "'; expected '", &_7$$6, "'");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_5$$6, "__construct", &_zephir_call_cache[2], &_8$$6);
		zephir_check_call_status();
		zephir_constructor_finish(&_5$$6);
		zephir_throw_exception_debug(&_5$$6, "phalcon/Acl/Adapter/Storage.zep", 95);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!ZEPHIR_IS_LONG(&version, 1)) {
		ZEPHIR_INIT_VAR(&_9$$7);
		object_init_ex(&_9$$7, phalcon_acl_exceptions_invalidsnapshot_ce);
		zephir_constructor_start(&_9$$7);
		ZEPHIR_INIT_VAR(&_10$$7);
		ZVAL_LONG(&_10$$7, 1);
		ZEPHIR_INIT_VAR(&_11$$7);
		ZEPHIR_CONCAT_SVSVS(&_11$$7, "Incompatible ACL snapshot version '", &version, "'; expected '", &_10$$7, "'");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_9$$7, "__construct", &_zephir_call_cache[3], &_11$$7);
		zephir_check_call_status();
		zephir_constructor_finish(&_9$$7);
		zephir_throw_exception_debug(&_9$$7, "phalcon/Acl/Adapter/Storage.zep", 102);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&_12);
	zephir_array_fetch_string(&_12, &data, SL("access"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 106);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_13 = Z_TYPE_P(&_12) != IS_ARRAY;
	if (!(_13)) {
		zephir_memory_observe(&_14);
		zephir_array_fetch_string(&_14, &data, SL("accessList"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 107);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_13 = Z_TYPE_P(&_14) != IS_ARRAY;
	}
	_15 = _13;
	if (!(_15)) {
		zephir_memory_observe(&_16);
		zephir_array_fetch_string(&_16, &data, SL("components"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 108);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_15 = Z_TYPE_P(&_16) != IS_ARRAY;
	}
	_17 = _15;
	if (!(_17)) {
		zephir_memory_observe(&_18);
		zephir_array_fetch_string(&_18, &data, SL("componentsNames"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 109);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_17 = Z_TYPE_P(&_18) != IS_ARRAY;
	}
	_19 = _17;
	if (!(_19)) {
		zephir_memory_observe(&_20);
		zephir_array_fetch_string(&_20, &data, SL("roles"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 110);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_19 = Z_TYPE_P(&_20) != IS_ARRAY;
	}
	_21 = _19;
	if (!(_21)) {
		zephir_memory_observe(&_22);
		zephir_array_fetch_string(&_22, &data, SL("roleInherits"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 111);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_21 = Z_TYPE_P(&_22) != IS_ARRAY;
	}
	if (UNEXPECTED(_21)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_invalidsnapshot_ce, "Malformed ACL snapshot structure", "phalcon/Acl/Adapter/Storage.zep", 113);
		return;
	}
	_23 = zephir_array_isset_value_string(&data, SL("defaultAccess"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_23) {
		zephir_memory_observe(&defaultAccess);
		zephir_array_fetch_string(&defaultAccess, &data, SL("defaultAccess"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 120);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_INIT_NVAR(&defaultAccess);
		ZVAL_LONG(&defaultAccess, 0);
	}
	_24 = zephir_array_isset_value_string(&data, SL("noArgumentsDefaultAction"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_24) {
		zephir_memory_observe(&noArgumentsDefaultAction);
		zephir_array_fetch_string(&noArgumentsDefaultAction, &data, SL("noArgumentsDefaultAction"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 121);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_INIT_NVAR(&noArgumentsDefaultAction);
		ZVAL_LONG(&noArgumentsDefaultAction, 0);
	}
	_25 = !ZEPHIR_IS_LONG_IDENTICAL(&defaultAccess, 1);
	if (_25) {
		_25 = !ZEPHIR_IS_LONG_IDENTICAL(&defaultAccess, 0);
	}
	_26 = _25;
	if (!(_26)) {
		_27 = !ZEPHIR_IS_LONG_IDENTICAL(&noArgumentsDefaultAction, 1);
		if (_27) {
			_27 = !ZEPHIR_IS_LONG_IDENTICAL(&noArgumentsDefaultAction, 0);
		}
		_26 = _27;
	}
	if (UNEXPECTED(_26)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_invalidsnapshot_ce, "Malformed ACL snapshot default action", "phalcon/Acl/Adapter/Storage.zep", 127);
		return;
	}
	zephir_memory_observe(&_28);
	zephir_array_fetch_string(&_28, &data, SL("roleInherits"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 130);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_28) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_30);
		zephir_string_to_char_array(&_30, &_28);
		_29 = &_30;
	} else {
		_29 = &_28;
	}
	zephir_is_iterable(_29, 0, "phalcon/Acl/Adapter/Storage.zep", 143);
	if (Z_TYPE_P(_29) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_29), _32, _33, _31)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_33 != NULL) { 
				ZVAL_STR_COPY(&name, _33);
			} else {
				ZVAL_LONG(&name, _32);
			}
			ZEPHIR_INIT_NVAR(&inherits);
			ZVAL_COPY(&inherits, _31);
			if (UNEXPECTED(Z_TYPE_P(&inherits) != IS_ARRAY)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_invalidsnapshot_ce, "Malformed ACL snapshot role inheritance", "phalcon/Acl/Adapter/Storage.zep", 132);
				return;
			}
			if (Z_TYPE_P(&inherits) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_35$$10);
				zephir_string_to_char_array(&_35$$10, &inherits);
				_34$$10 = &_35$$10;
			} else {
				_34$$10 = &inherits;
			}
			zephir_is_iterable(_34$$10, 0, "phalcon/Acl/Adapter/Storage.zep", 140);
			if (Z_TYPE_P(_34$$10) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_34$$10), _36$$10)
				{
					ZEPHIR_INIT_NVAR(&inherit);
					ZVAL_COPY(&inherit, _36$$10);
					_37$$12 = Z_TYPE_P(&inherit) != IS_STRING;
					if (_37$$12) {
						_37$$12 = Z_TYPE_P(&inherit) != IS_LONG;
					}
					if (UNEXPECTED(_37$$12)) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_invalidsnapshot_ce, "Malformed ACL snapshot role inheritance", "phalcon/Acl/Adapter/Storage.zep", 137);
						return;
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _34$$10, "rewind", &_zephir_call_cache[4]);
				zephir_check_call_status();
				_39$$10 = 1;
				while (1) {
					if (_39$$10) {
						_39$$10 = 0;
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _34$$10, "next", &_zephir_call_cache[5]);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD_CACHED(&_38$$10, _34$$10, "valid", &_zephir_call_cache[6]);
					zephir_check_call_status();
					if (!zend_is_true(&_38$$10)) {
						break;
					}
					ZEPHIR_CALL_METHOD_CACHED(&inherit, _34$$10, "current", &_zephir_call_cache[7]);
					zephir_check_call_status();
						_40$$14 = Z_TYPE_P(&inherit) != IS_STRING;
						if (_40$$14) {
							_40$$14 = Z_TYPE_P(&inherit) != IS_LONG;
						}
						if (UNEXPECTED(_40$$14)) {
							ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_invalidsnapshot_ce, "Malformed ACL snapshot role inheritance", "phalcon/Acl/Adapter/Storage.zep", 137);
							return;
						}
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _29, "rewind", &_zephir_call_cache[8]);
		zephir_check_call_status();
		_42 = 1;
		while (1) {
			if (_42) {
				_42 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _29, "next", &_zephir_call_cache[9]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_41, _29, "valid", &_zephir_call_cache[10]);
			zephir_check_call_status();
			if (!zend_is_true(&_41)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&name, _29, "key", &_zephir_call_cache[11]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&inherits, _29, "current", &_zephir_call_cache[12]);
			zephir_check_call_status();
				if (UNEXPECTED(Z_TYPE_P(&inherits) != IS_ARRAY)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_invalidsnapshot_ce, "Malformed ACL snapshot role inheritance", "phalcon/Acl/Adapter/Storage.zep", 132);
					return;
				}
				if (Z_TYPE_P(&inherits) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_44$$16);
					zephir_string_to_char_array(&_44$$16, &inherits);
					_43$$16 = &_44$$16;
				} else {
					_43$$16 = &inherits;
				}
				zephir_is_iterable(_43$$16, 0, "phalcon/Acl/Adapter/Storage.zep", 140);
				if (Z_TYPE_P(_43$$16) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_43$$16), _45$$16)
					{
						ZEPHIR_INIT_NVAR(&inherit);
						ZVAL_COPY(&inherit, _45$$16);
						_46$$18 = Z_TYPE_P(&inherit) != IS_STRING;
						if (_46$$18) {
							_46$$18 = Z_TYPE_P(&inherit) != IS_LONG;
						}
						if (UNEXPECTED(_46$$18)) {
							ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_invalidsnapshot_ce, "Malformed ACL snapshot role inheritance", "phalcon/Acl/Adapter/Storage.zep", 137);
							return;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _43$$16, "rewind", &_zephir_call_cache[13]);
					zephir_check_call_status();
					_48$$16 = 1;
					while (1) {
						if (_48$$16) {
							_48$$16 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _43$$16, "next", &_zephir_call_cache[14]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_47$$16, _43$$16, "valid", &_zephir_call_cache[15]);
						zephir_check_call_status();
						if (!zend_is_true(&_47$$16)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&inherit, _43$$16, "current", &_zephir_call_cache[16]);
						zephir_check_call_status();
							_49$$20 = Z_TYPE_P(&inherit) != IS_STRING;
							if (_49$$20) {
								_49$$20 = Z_TYPE_P(&inherit) != IS_LONG;
							}
							if (UNEXPECTED(_49$$20)) {
								ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_invalidsnapshot_ce, "Malformed ACL snapshot role inheritance", "phalcon/Acl/Adapter/Storage.zep", 137);
								return;
							}
					}
				}
		}
	}

	/* try_start_1: */

		ZEPHIR_INIT_VAR(&rebuiltRoles);
		array_init(&rebuiltRoles);
		zephir_memory_observe(&_50$$22);
		zephir_array_fetch_string(&_50$$22, &data, SL("roles"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 145);
		if (UNEXPECTED(EG(exception))) {
			goto try_end_1;
		}
		if (Z_TYPE_P(&_50$$22) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_52$$22);
			zephir_string_to_char_array(&_52$$22, &_50$$22);
			_51$$22 = &_52$$22;
		} else {
			_51$$22 = &_50$$22;
		}
		zephir_is_iterable(_51$$22, 0, "phalcon/Acl/Adapter/Storage.zep", 149);
		if (Z_TYPE_P(_51$$22) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_51$$22), _54$$22, _55$$22, _53$$22)
			{
				ZEPHIR_INIT_NVAR(&name);
				if (_55$$22 != NULL) { 
					ZVAL_STR_COPY(&name, _55$$22);
				} else {
					ZVAL_LONG(&name, _54$$22);
				}
				ZEPHIR_INIT_NVAR(&description);
				ZVAL_COPY(&description, _53$$22);
				ZEPHIR_INIT_NVAR(&_56$$23);
				object_init_ex(&_56$$23, phalcon_acl_role_ce);
				zephir_constructor_start(&_56$$23);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_56$$23, "__construct", &_zephir_call_cache[17], &name, &description);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_constructor_finish(&_56$$23);
				zephir_array_update_zval(&rebuiltRoles, &name, &_56$$23, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					goto try_end_1;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _51$$22, "rewind", &_zephir_call_cache[18]);
			zephir_check_call_status();
			_58$$22 = 1;
			while (1) {
				if (_58$$22) {
					_58$$22 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _51$$22, "next", &_zephir_call_cache[19]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_57$$22, _51$$22, "valid", &_zephir_call_cache[20]);
				zephir_check_call_status();
				if (!zend_is_true(&_57$$22)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&name, _51$$22, "key", &_zephir_call_cache[21]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&description, _51$$22, "current", &_zephir_call_cache[22]);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_59$$24);
					object_init_ex(&_59$$24, phalcon_acl_role_ce);
					zephir_constructor_start(&_59$$24);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_59$$24, "__construct", &_zephir_call_cache[23], &name, &description);
					zephir_check_call_status_or_jump(try_end_1);
					zephir_constructor_finish(&_59$$24);
					zephir_array_update_zval(&rebuiltRoles, &name, &_59$$24, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						goto try_end_1;
					}
			}
		}
		ZEPHIR_INIT_VAR(&rebuiltComponents);
		array_init(&rebuiltComponents);
		zephir_memory_observe(&_60$$22);
		zephir_array_fetch_string(&_60$$22, &data, SL("components"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 150);
		if (UNEXPECTED(EG(exception))) {
			goto try_end_1;
		}
		if (Z_TYPE_P(&_60$$22) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_62$$22);
			zephir_string_to_char_array(&_62$$22, &_60$$22);
			_61$$22 = &_62$$22;
		} else {
			_61$$22 = &_60$$22;
		}
		zephir_is_iterable(_61$$22, 0, "phalcon/Acl/Adapter/Storage.zep", 153);
		if (Z_TYPE_P(_61$$22) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_61$$22), _64$$22, _65$$22, _63$$22)
			{
				ZEPHIR_INIT_NVAR(&name);
				if (_65$$22 != NULL) { 
					ZVAL_STR_COPY(&name, _65$$22);
				} else {
					ZVAL_LONG(&name, _64$$22);
				}
				ZEPHIR_INIT_NVAR(&description);
				ZVAL_COPY(&description, _63$$22);
				ZEPHIR_INIT_NVAR(&_66$$25);
				object_init_ex(&_66$$25, phalcon_acl_component_ce);
				zephir_constructor_start(&_66$$25);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_66$$25, "__construct", &_zephir_call_cache[24], &name, &description);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_constructor_finish(&_66$$25);
				zephir_array_update_zval(&rebuiltComponents, &name, &_66$$25, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					goto try_end_1;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _61$$22, "rewind", &_zephir_call_cache[25]);
			zephir_check_call_status();
			_68$$22 = 1;
			while (1) {
				if (_68$$22) {
					_68$$22 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _61$$22, "next", &_zephir_call_cache[26]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_67$$22, _61$$22, "valid", &_zephir_call_cache[27]);
				zephir_check_call_status();
				if (!zend_is_true(&_67$$22)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&name, _61$$22, "key", &_zephir_call_cache[28]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&description, _61$$22, "current", &_zephir_call_cache[29]);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_69$$26);
					object_init_ex(&_69$$26, phalcon_acl_component_ce);
					zephir_constructor_start(&_69$$26);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_69$$26, "__construct", &_zephir_call_cache[30], &name, &description);
					zephir_check_call_status_or_jump(try_end_1);
					zephir_constructor_finish(&_69$$26);
					zephir_array_update_zval(&rebuiltComponents, &name, &_69$$26, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						goto try_end_1;
					}
			}
		}

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_70);
		ZVAL_OBJ(&_70, EG(exception));
		Z_ADDREF_P(&_70);
		if (zephir_is_instance_of(&_70, SL("Throwable"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&e, &_70);
			ZEPHIR_INIT_VAR(&_71$$27);
			object_init_ex(&_71$$27, phalcon_acl_exceptions_invalidsnapshot_ce);
			zephir_constructor_start(&_71$$27);
			ZEPHIR_CALL_METHOD_CACHED(&_72$$27, &e, "getMessage", &_zephir_call_cache[31]);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_73$$27);
			ZEPHIR_CONCAT_SV(&_73$$27, "Malformed ACL snapshot element: ", &_72$$27);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_71$$27, "__construct", &_zephir_call_cache[32], &_73$$27);
			zephir_check_call_status();
			zephir_constructor_finish(&_71$$27);
			zephir_throw_exception_debug(&_71$$27, "phalcon/Acl/Adapter/Storage.zep", 156);
			ZEPHIR_MM_RESTORE();
			return;
		} else {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_memory_observe(&_74);
	zephir_array_fetch_string(&_74, &data, SL("access"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 159);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 388, &_74);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&_75);
	zephir_array_fetch_string(&_75, &data, SL("accessList"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 160);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 389, &_75);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 390, &rebuiltComponents);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&_76);
	zephir_array_fetch_string(&_76, &data, SL("componentsNames"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 162);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 391, &_76);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 392, &rebuiltRoles);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&_77);
	zephir_array_fetch_string(&_77, &data, SL("roleInherits"), PH_NOISY, "phalcon/Acl/Adapter/Storage.zep", 164);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 393, &_77);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_8, 394, &defaultAccess);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_9, 395, &noArgumentsDefaultAction);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
	zephir_is_iterable(_2, 0, "phalcon/Acl/Adapter/Storage.zep", 186);
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
	zephir_is_iterable(_7, 0, "phalcon/Acl/Adapter/Storage.zep", 191);
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
	zephir_is_iterable(_17, 0, "phalcon/Acl/Adapter/Storage.zep", 196);
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
	zend_long depth = 0, ZEPHIR_LAST_CALL_STATUS;
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
	if (UNEXPECTED(depth > 4)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_invalidsnapshot_ce, "ACL snapshot nesting is too deep", "phalcon/Acl/Adapter/Storage.zep", 224);
		return;
	}
	if (Z_TYPE_P(value) == IS_OBJECT) {
		ZEPHIR_CALL_FUNCTION(&_0$$4, "get_object_vars", NULL, 109, value);
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
	zephir_is_iterable(_1, 0, "phalcon/Acl/Adapter/Storage.zep", 240);
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
	RETURN_CCTOR(&result);
}

