
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 379, storage);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 380, &key_zv);
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
	zend_string *_25, *_47$$21, *_58$$21;
	zend_ulong _24, _46$$21, _57$$21;
	zend_bool _7, _9, _11, _13, _15, _17, _18, _19, _34, _31$$9, _29$$11, _32$$13, _40$$15, _38$$17, _41$$19, _51$$21, _62$$21;
	zval data, version, name, description, rebuiltRoles, rebuiltComponents, defaultAccess, noArgumentsDefaultAction, inherits, inherit, e, _0, _1, _6, _8, _10, _12, _14, _16, _20, *_21, _22, *_23, _33, _64, _68, _69, _70, _71, _2$$3, _3$$6, _4$$6, _5$$6, *_26$$9, _27$$9, *_28$$9, _30$$9, *_35$$15, _36$$15, *_37$$15, _39$$15, _42$$21, *_43$$21, _44$$21, *_45$$21, _50$$21, _53$$21, *_54$$21, _55$$21, *_56$$21, _61$$21, _48$$22, _52$$23, _59$$24, _63$$25, _65$$26, _66$$26, _67$$26;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_49 = NULL, *_60 = NULL;
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
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_64);
	ZVAL_UNDEF(&_68);
	ZVAL_UNDEF(&_69);
	ZVAL_UNDEF(&_70);
	ZVAL_UNDEF(&_71);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_27$$9);
	ZVAL_UNDEF(&_30$$9);
	ZVAL_UNDEF(&_36$$15);
	ZVAL_UNDEF(&_39$$15);
	ZVAL_UNDEF(&_42$$21);
	ZVAL_UNDEF(&_44$$21);
	ZVAL_UNDEF(&_50$$21);
	ZVAL_UNDEF(&_53$$21);
	ZVAL_UNDEF(&_55$$21);
	ZVAL_UNDEF(&_61$$21);
	ZVAL_UNDEF(&_48$$22);
	ZVAL_UNDEF(&_52$$23);
	ZVAL_UNDEF(&_59$$24);
	ZVAL_UNDEF(&_63$$25);
	ZVAL_UNDEF(&_65$$26);
	ZVAL_UNDEF(&_66$$26);
	ZVAL_UNDEF(&_67$$26);
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

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 379, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 380, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&data, &_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(&data) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "normalizetoarray", NULL, 358, &data);
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
	if (Z_TYPE_P(&_20) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_22);
		zephir_string_to_char_array(&_22, &_20);
		_21 = &_22;
	} else {
		_21 = &_20;
	}
	zephir_is_iterable(_21, 0, "phalcon/Acl/Adapter/Storage.zep", 132);
	if (Z_TYPE_P(_21) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_21), _24, _25, _23)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_25 != NULL) { 
				ZVAL_STR_COPY(&name, _25);
			} else {
				ZVAL_LONG(&name, _24);
			}
			ZEPHIR_INIT_NVAR(&inherits);
			ZVAL_COPY(&inherits, _23);
			if (UNEXPECTED(Z_TYPE_P(&inherits) != IS_ARRAY)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_invalidsnapshot_ce, "Malformed ACL snapshot role inheritance", "phalcon/Acl/Adapter/Storage.zep", 121);
				return;
			}
			if (Z_TYPE_P(&inherits) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_27$$9);
				zephir_string_to_char_array(&_27$$9, &inherits);
				_26$$9 = &_27$$9;
			} else {
				_26$$9 = &inherits;
			}
			zephir_is_iterable(_26$$9, 0, "phalcon/Acl/Adapter/Storage.zep", 129);
			if (Z_TYPE_P(_26$$9) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_26$$9), _28$$9)
				{
					ZEPHIR_INIT_NVAR(&inherit);
					ZVAL_COPY(&inherit, _28$$9);
					_29$$11 = Z_TYPE_P(&inherit) != IS_STRING;
					if (_29$$11) {
						_29$$11 = Z_TYPE_P(&inherit) != IS_LONG;
					}
					if (UNEXPECTED(_29$$11)) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_invalidsnapshot_ce, "Malformed ACL snapshot role inheritance", "phalcon/Acl/Adapter/Storage.zep", 126);
						return;
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _26$$9, "rewind", NULL, 0);
				zephir_check_call_status();
				_31$$9 = 1;
				while (1) {
					if (_31$$9) {
						_31$$9 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _26$$9, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_30$$9, _26$$9, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_30$$9)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&inherit, _26$$9, "current", NULL, 0);
					zephir_check_call_status();
						_32$$13 = Z_TYPE_P(&inherit) != IS_STRING;
						if (_32$$13) {
							_32$$13 = Z_TYPE_P(&inherit) != IS_LONG;
						}
						if (UNEXPECTED(_32$$13)) {
							ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_invalidsnapshot_ce, "Malformed ACL snapshot role inheritance", "phalcon/Acl/Adapter/Storage.zep", 126);
							return;
						}
				}
			}
			ZEPHIR_INIT_NVAR(&inherit);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _21, "rewind", NULL, 0);
		zephir_check_call_status();
		_34 = 1;
		while (1) {
			if (_34) {
				_34 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _21, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_33, _21, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_33)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, _21, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&inherits, _21, "current", NULL, 0);
			zephir_check_call_status();
				if (UNEXPECTED(Z_TYPE_P(&inherits) != IS_ARRAY)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_invalidsnapshot_ce, "Malformed ACL snapshot role inheritance", "phalcon/Acl/Adapter/Storage.zep", 121);
					return;
				}
				if (Z_TYPE_P(&inherits) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_36$$15);
					zephir_string_to_char_array(&_36$$15, &inherits);
					_35$$15 = &_36$$15;
				} else {
					_35$$15 = &inherits;
				}
				zephir_is_iterable(_35$$15, 0, "phalcon/Acl/Adapter/Storage.zep", 129);
				if (Z_TYPE_P(_35$$15) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_35$$15), _37$$15)
					{
						ZEPHIR_INIT_NVAR(&inherit);
						ZVAL_COPY(&inherit, _37$$15);
						_38$$17 = Z_TYPE_P(&inherit) != IS_STRING;
						if (_38$$17) {
							_38$$17 = Z_TYPE_P(&inherit) != IS_LONG;
						}
						if (UNEXPECTED(_38$$17)) {
							ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_invalidsnapshot_ce, "Malformed ACL snapshot role inheritance", "phalcon/Acl/Adapter/Storage.zep", 126);
							return;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _35$$15, "rewind", NULL, 0);
					zephir_check_call_status();
					_40$$15 = 1;
					while (1) {
						if (_40$$15) {
							_40$$15 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _35$$15, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_39$$15, _35$$15, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_39$$15)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&inherit, _35$$15, "current", NULL, 0);
						zephir_check_call_status();
							_41$$19 = Z_TYPE_P(&inherit) != IS_STRING;
							if (_41$$19) {
								_41$$19 = Z_TYPE_P(&inherit) != IS_LONG;
							}
							if (UNEXPECTED(_41$$19)) {
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
		zephir_array_fetch_string(&_42$$21, &data, SL("roles"), PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Storage.zep", 134);
		if (Z_TYPE_P(&_42$$21) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_44$$21);
			zephir_string_to_char_array(&_44$$21, &_42$$21);
			_43$$21 = &_44$$21;
		} else {
			_43$$21 = &_42$$21;
		}
		zephir_is_iterable(_43$$21, 0, "phalcon/Acl/Adapter/Storage.zep", 138);
		if (Z_TYPE_P(_43$$21) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_43$$21), _46$$21, _47$$21, _45$$21)
			{
				ZEPHIR_INIT_NVAR(&name);
				if (_47$$21 != NULL) { 
					ZVAL_STR_COPY(&name, _47$$21);
				} else {
					ZVAL_LONG(&name, _46$$21);
				}
				ZEPHIR_INIT_NVAR(&description);
				ZVAL_COPY(&description, _45$$21);
				ZEPHIR_INIT_NVAR(&_48$$22);
				object_init_ex(&_48$$22, phalcon_acl_role_ce);
				ZEPHIR_CALL_METHOD(NULL, &_48$$22, "__construct", &_49, 240, &name, &description);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_array_update_zval(&rebuiltRoles, &name, &_48$$22, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _43$$21, "rewind", NULL, 0);
			zephir_check_call_status();
			_51$$21 = 1;
			while (1) {
				if (_51$$21) {
					_51$$21 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _43$$21, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_50$$21, _43$$21, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_50$$21)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&name, _43$$21, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&description, _43$$21, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_52$$23);
					object_init_ex(&_52$$23, phalcon_acl_role_ce);
					ZEPHIR_CALL_METHOD(NULL, &_52$$23, "__construct", &_49, 240, &name, &description);
					zephir_check_call_status_or_jump(try_end_1);
					zephir_array_update_zval(&rebuiltRoles, &name, &_52$$23, PH_COPY | PH_SEPARATE);
			}
		}
		ZEPHIR_INIT_NVAR(&description);
		ZEPHIR_INIT_NVAR(&name);
		ZEPHIR_INIT_VAR(&rebuiltComponents);
		array_init(&rebuiltComponents);
		zephir_array_fetch_string(&_53$$21, &data, SL("components"), PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Storage.zep", 139);
		if (Z_TYPE_P(&_53$$21) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_55$$21);
			zephir_string_to_char_array(&_55$$21, &_53$$21);
			_54$$21 = &_55$$21;
		} else {
			_54$$21 = &_53$$21;
		}
		zephir_is_iterable(_54$$21, 0, "phalcon/Acl/Adapter/Storage.zep", 142);
		if (Z_TYPE_P(_54$$21) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_54$$21), _57$$21, _58$$21, _56$$21)
			{
				ZEPHIR_INIT_NVAR(&name);
				if (_58$$21 != NULL) { 
					ZVAL_STR_COPY(&name, _58$$21);
				} else {
					ZVAL_LONG(&name, _57$$21);
				}
				ZEPHIR_INIT_NVAR(&description);
				ZVAL_COPY(&description, _56$$21);
				ZEPHIR_INIT_NVAR(&_59$$24);
				object_init_ex(&_59$$24, phalcon_acl_component_ce);
				ZEPHIR_CALL_METHOD(NULL, &_59$$24, "__construct", &_60, 231, &name, &description);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_array_update_zval(&rebuiltComponents, &name, &_59$$24, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _54$$21, "rewind", NULL, 0);
			zephir_check_call_status();
			_62$$21 = 1;
			while (1) {
				if (_62$$21) {
					_62$$21 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _54$$21, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_61$$21, _54$$21, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_61$$21)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&name, _54$$21, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&description, _54$$21, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_63$$25);
					object_init_ex(&_63$$25, phalcon_acl_component_ce);
					ZEPHIR_CALL_METHOD(NULL, &_63$$25, "__construct", &_60, 231, &name, &description);
					zephir_check_call_status_or_jump(try_end_1);
					zephir_array_update_zval(&rebuiltComponents, &name, &_63$$25, PH_COPY | PH_SEPARATE);
			}
		}
		ZEPHIR_INIT_NVAR(&description);
		ZEPHIR_INIT_NVAR(&name);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_64);
		ZVAL_OBJ(&_64, EG(exception));
		Z_ADDREF_P(&_64);
		if (zephir_is_instance_of(&_64, SL("Throwable"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&e, &_64);
			ZEPHIR_INIT_VAR(&_65$$26);
			object_init_ex(&_65$$26, phalcon_acl_exceptions_invalidsnapshot_ce);
			ZEPHIR_CALL_METHOD(&_66$$26, &e, "getmessage", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_67$$26);
			ZEPHIR_CONCAT_SV(&_67$$26, "Malformed ACL snapshot element: ", &_66$$26);
			ZEPHIR_CALL_METHOD(NULL, &_65$$26, "__construct", NULL, 9, &_67$$26);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_65$$26, "phalcon/Acl/Adapter/Storage.zep", 145);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_array_fetch_string(&_68, &data, SL("access"), PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Storage.zep", 148);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 381, &_68);
	zephir_array_fetch_string(&_69, &data, SL("accessList"), PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Storage.zep", 149);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 382, &_69);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 383, &rebuiltComponents);
	zephir_array_fetch_string(&_70, &data, SL("componentsNames"), PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Storage.zep", 151);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 384, &_70);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 385, &rebuiltRoles);
	zephir_array_fetch_string(&_71, &data, SL("roleInherits"), PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Storage.zep", 153);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 386, &_71);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_8, 387, &defaultAccess);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_9, 388, &noArgumentsDefaultAction);
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

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 381, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&access, &_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 389, PH_NOISY_CC | PH_READONLY);
	zephir_array_keys(&_1, &_0);
	if (Z_TYPE_P(&_1) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_3);
		zephir_string_to_char_array(&_3, &_1);
		_2 = &_3;
	} else {
		_2 = &_1;
	}
	zephir_is_iterable(_2, 0, "phalcon/Acl/Adapter/Storage.zep", 175);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_2), _4)
	{
		ZEPHIR_INIT_NVAR(&accessKey);
		ZVAL_COPY(&accessKey, _4);
		ZEPHIR_INIT_NVAR(&_5$$3);
		ZVAL_LONG(&_5$$3, 0);
		zephir_array_update_zval(&access, &accessKey, &_5$$3, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&accessKey);
	ZEPHIR_INIT_VAR(&components);
	array_init(&components);
	zephir_read_property_cached(&_6, this_ptr, _zephir_prop_2, 383, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_6) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_8);
		zephir_string_to_char_array(&_8, &_6);
		_7 = &_8;
	} else {
		_7 = &_6;
	}
	zephir_is_iterable(_7, 0, "phalcon/Acl/Adapter/Storage.zep", 180);
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
			ZEPHIR_CALL_METHOD(&_12$$4, &componentObject, "getdescription", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_zval(&components, &componentName, &_12$$4, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _7, "rewind", NULL, 0);
		zephir_check_call_status();
		_14 = 1;
		while (1) {
			if (_14) {
				_14 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _7, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_13, _7, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_13)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&componentName, _7, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&componentObject, _7, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_15$$5, &componentObject, "getdescription", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_zval(&components, &componentName, &_15$$5, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&componentObject);
	ZEPHIR_INIT_NVAR(&componentName);
	ZEPHIR_INIT_VAR(&roles);
	array_init(&roles);
	zephir_read_property_cached(&_16, this_ptr, _zephir_prop_3, 385, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_16) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_18);
		zephir_string_to_char_array(&_18, &_16);
		_17 = &_18;
	} else {
		_17 = &_16;
	}
	zephir_is_iterable(_17, 0, "phalcon/Acl/Adapter/Storage.zep", 185);
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
			ZEPHIR_CALL_METHOD(&_22$$6, &roleObject, "getdescription", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_zval(&roles, &roleName, &_22$$6, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _17, "rewind", NULL, 0);
		zephir_check_call_status();
		_24 = 1;
		while (1) {
			if (_24) {
				_24 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _17, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_23, _17, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_23)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&roleName, _17, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&roleObject, _17, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_25$$7, &roleObject, "getdescription", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_zval(&roles, &roleName, &_25$$7, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&roleObject);
	ZEPHIR_INIT_NVAR(&roleName);
	zephir_read_property_cached(&_26, this_ptr, _zephir_prop_4, 379, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_27, this_ptr, _zephir_prop_5, 380, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_28);
	zephir_create_array(&_28, 9, 0);
	add_assoc_long_ex(&_28, SL("version"), 1);
	zephir_array_update_string(&_28, SL("access"), &access, PH_COPY | PH_SEPARATE);
	zephir_memory_observe(&_29);
	zephir_read_property_cached(&_29, this_ptr, _zephir_prop_6, 382, PH_NOISY_CC);
	zephir_array_update_string(&_28, SL("accessList"), &_29, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_28, SL("components"), &components, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_29);
	zephir_read_property_cached(&_29, this_ptr, _zephir_prop_7, 384, PH_NOISY_CC);
	zephir_array_update_string(&_28, SL("componentsNames"), &_29, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_28, SL("roles"), &roles, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_29);
	zephir_read_property_cached(&_29, this_ptr, _zephir_prop_8, 386, PH_NOISY_CC);
	zephir_array_update_string(&_28, SL("roleInherits"), &_29, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_29);
	zephir_read_property_cached(&_29, this_ptr, _zephir_prop_9, 387, PH_NOISY_CC);
	zephir_array_update_string(&_28, SL("defaultAccess"), &_29, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_29);
	zephir_read_property_cached(&_29, this_ptr, _zephir_prop_10, 388, PH_NOISY_CC);
	zephir_array_update_string(&_28, SL("noArgumentsDefaultAction"), &_29, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(&_26, "set", NULL, 0, &_27, &_28);
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
	zend_bool _10;
	zend_string *_5;
	zend_ulong _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long depth, ZEPHIR_LAST_CALL_STATUS;
	zval *value = NULL, value_sub, *depth_param = NULL, item, key, result, *_1, _2, *_3, _9, _0$$4, _6$$6, _7$$6, _11$$7, _12$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
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
		ZEPHIR_CALL_FUNCTION(&_0$$4, "get_object_vars", NULL, 359, value);
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
	zephir_is_iterable(_1, 0, "phalcon/Acl/Adapter/Storage.zep", 229);
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
			ZEPHIR_CALL_METHOD(&_6$$6, this_ptr, "normalizetoarray", &_8, 358, &item, &_7$$6);
			zephir_check_call_status();
			zephir_array_update_zval(&result, &key, &_6$$6, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _1, "rewind", NULL, 0);
		zephir_check_call_status();
		_10 = 1;
		while (1) {
			if (_10) {
				_10 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_9, _1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_9)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, _1, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&item, _1, "current", NULL, 0);
			zephir_check_call_status();
				ZVAL_LONG(&_12$$7, (depth + 1));
				ZEPHIR_CALL_METHOD(&_11$$7, this_ptr, "normalizetoarray", &_8, 358, &item, &_12$$7);
				zephir_check_call_status();
				zephir_array_update_zval(&result, &key, &_11$$7, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&result);
}

