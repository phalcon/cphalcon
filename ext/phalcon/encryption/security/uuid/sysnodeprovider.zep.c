
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/file.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-uuid
 * @link    https://github.com/sinbadxiii/cphalcon-uuid
 */
/**
 * Discovers the hardware MAC address and returns it as a 12-character hex node.
 *
 * Two-layer cache:
 *   1. Instance property  - free on all calls after the first within this instance.
 *   2. APCu               - cross-request within the same PHP-FPM worker (optional).
 *
 * Falls back to RandomNodeProvider if no valid MAC address is found.
 *
 * Platform support:
 *   Linux   - reads /sys/class/net/*\/address
 *   macOS   - passthru("ifconfig 2>&1")
 *   Windows - passthru("ipconfig /all 2>&1")
 *   FreeBSD - passthru("netstat -i -f link 2>&1")
 */
ZEPHIR_INIT_CLASS(Phalcon_Encryption_Security_Uuid_SysNodeProvider)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Encryption\\Security\\Uuid, SysNodeProvider, phalcon, encryption_security_uuid_sysnodeprovider, phalcon_encryption_security_uuid_sysnodeprovider_method_entry, 0);

	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_encryption_security_uuid_sysnodeprovider_ce, SL("node"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_STRING|MAY_BE_NULL, NULL, 0);
	}

	zend_class_implements(phalcon_encryption_security_uuid_sysnodeprovider_ce, 1, phalcon_encryption_security_uuid_nodeproviderinterface_ce);
	return SUCCESS;
}

/**
 * Returns the hardware MAC address as a 12-character hex string.
 * Result is cached in the instance property and optionally in APCu.
 */
PHP_METHOD(Phalcon_Encryption_Security_Uuid_SysNodeProvider, getNode)
{
	zend_bool _28, _39, _48, _56, _20$$7;
	zval cached, addresses, address, matches, output, node, _0, _1, _2, _5, _29, _40, _49, _57, _59, _4$$4, _6$$6, *_7$$7, _8$$7, *_9$$7, _19$$7, _10$$8, _11$$8, _12$$8, _14$$8, _15$$8, _16$$8, _17$$8, _21$$11, _22$$11, _23$$11, _24$$11, _25$$11, _26$$11, _27$$11, _31$$14, _34$$14, _35$$14, _36$$15, _37$$15, _38$$15, _41$$16, _42$$16, _43$$16, _44$$17, _45$$17, _46$$17, _47$$17, _50$$18, _51$$18, _52$$18, _53$$19, _54$$19, _55$$19, _58$$20, _60$$21, _61$$21;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_13 = NULL, *_18 = NULL, *_30 = NULL, *_32 = NULL, *_33 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cached);
	ZVAL_UNDEF(&addresses);
	ZVAL_UNDEF(&address);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&node);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_40);
	ZVAL_UNDEF(&_49);
	ZVAL_UNDEF(&_57);
	ZVAL_UNDEF(&_59);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_21$$11);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&_23$$11);
	ZVAL_UNDEF(&_24$$11);
	ZVAL_UNDEF(&_25$$11);
	ZVAL_UNDEF(&_26$$11);
	ZVAL_UNDEF(&_27$$11);
	ZVAL_UNDEF(&_31$$14);
	ZVAL_UNDEF(&_34$$14);
	ZVAL_UNDEF(&_35$$14);
	ZVAL_UNDEF(&_36$$15);
	ZVAL_UNDEF(&_37$$15);
	ZVAL_UNDEF(&_38$$15);
	ZVAL_UNDEF(&_41$$16);
	ZVAL_UNDEF(&_42$$16);
	ZVAL_UNDEF(&_43$$16);
	ZVAL_UNDEF(&_44$$17);
	ZVAL_UNDEF(&_45$$17);
	ZVAL_UNDEF(&_46$$17);
	ZVAL_UNDEF(&_47$$17);
	ZVAL_UNDEF(&_50$$18);
	ZVAL_UNDEF(&_51$$18);
	ZVAL_UNDEF(&_52$$18);
	ZVAL_UNDEF(&_53$$19);
	ZVAL_UNDEF(&_54$$19);
	ZVAL_UNDEF(&_55$$19);
	ZVAL_UNDEF(&_58$$20);
	ZVAL_UNDEF(&_60$$21);
	ZVAL_UNDEF(&_61$$21);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("node", 4, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 739, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		RETURN_MM_MEMBER_TYPED(getThis(), "node", IS_STRING);
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "apcu_fetch");
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "phpFunctionExists", &_3, 0, &_2);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&_4$$4);
		ZVAL_STRING(&_4$$4, "__phalcon_uuid_node");
		ZEPHIR_CALL_FUNCTION(&cached, "apcu_fetch", NULL, 287, &_4$$4);
		zephir_check_call_status();
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&cached)) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 739, &cached);
			RETURN_MM_MEMBER_TYPED(getThis(), "node", IS_STRING);
		}
	}
	ZEPHIR_INIT_VAR(&node);
	ZVAL_NULL(&node);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "Linux");
	if (ZEPHIR_IS_STRING_IDENTICAL(&_5, "Linux")) {
		ZEPHIR_INIT_VAR(&_6$$6);
		ZVAL_STRING(&_6$$6, "/sys/class/net/*/address");
		ZEPHIR_CALL_FUNCTION(&addresses, "glob", NULL, 0, &_6$$6);
		zephir_check_call_status();
		if (Z_TYPE_P(&addresses) == IS_ARRAY) {
			if (Z_TYPE_P(&addresses) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_8$$7);
				zephir_string_to_char_array(&_8$$7, &addresses);
				_7$$7 = &_8$$7;
			} else {
				_7$$7 = &addresses;
			}
			zephir_is_iterable(_7$$7, 0, "phalcon/Encryption/Security/Uuid/SysNodeProvider.zep", 78);
			if (Z_TYPE_P(_7$$7) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_7$$7), _9$$7)
				{
					ZEPHIR_INIT_NVAR(&address);
					ZVAL_COPY(&address, _9$$7);
					ZEPHIR_INIT_NVAR(&_10$$8);
					ZVAL_STRING(&_10$$8, "/lo/");
					ZEPHIR_INIT_NVAR(&_11$$8);
					zephir_fast_strpos(&_11$$8, &address, &_10$$8, 0 );
					if (!ZEPHIR_IS_FALSE_IDENTICAL(&_11$$8)) {
						continue;
					}
					ZEPHIR_CALL_METHOD(&_12$$8, this_ptr, "phpFileGetContents", &_13, 0, &address);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&node);
					zephir_fast_trim(&node, &_12$$8, NULL , ZEPHIR_TRIM_BOTH);
					ZEPHIR_INIT_NVAR(&_14$$8);
					ZEPHIR_INIT_NVAR(&_15$$8);
					ZVAL_STRING(&_15$$8, ":");
					ZEPHIR_INIT_NVAR(&_16$$8);
					ZVAL_STRING(&_16$$8, "");
					zephir_fast_str_replace(&_14$$8, &_15$$8, &_16$$8, &node);
					ZEPHIR_CPY_WRT(&node, &_14$$8);
					ZEPHIR_CALL_METHOD(&_17$$8, this_ptr, "isValidNode", &_18, 0, &node);
					zephir_check_call_status();
					if (zephir_is_true(&_17$$8)) {
						break;
					}
					ZEPHIR_INIT_NVAR(&node);
					ZVAL_NULL(&node);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _7$$7, "rewind", NULL, 0);
				zephir_check_call_status();
				_20$$7 = 1;
				while (1) {
					if (_20$$7) {
						_20$$7 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _7$$7, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_19$$7, _7$$7, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_19$$7)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&address, _7$$7, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_21$$11);
						ZVAL_STRING(&_21$$11, "/lo/");
						ZEPHIR_INIT_NVAR(&_22$$11);
						zephir_fast_strpos(&_22$$11, &address, &_21$$11, 0 );
						if (!ZEPHIR_IS_FALSE_IDENTICAL(&_22$$11)) {
							continue;
						}
						ZEPHIR_CALL_METHOD(&_23$$11, this_ptr, "phpFileGetContents", &_13, 0, &address);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&node);
						zephir_fast_trim(&node, &_23$$11, NULL , ZEPHIR_TRIM_BOTH);
						ZEPHIR_INIT_NVAR(&_24$$11);
						ZEPHIR_INIT_NVAR(&_25$$11);
						ZVAL_STRING(&_25$$11, ":");
						ZEPHIR_INIT_NVAR(&_26$$11);
						ZVAL_STRING(&_26$$11, "");
						zephir_fast_str_replace(&_24$$11, &_25$$11, &_26$$11, &node);
						ZEPHIR_CPY_WRT(&node, &_24$$11);
						ZEPHIR_CALL_METHOD(&_27$$11, this_ptr, "isValidNode", &_18, 0, &node);
						zephir_check_call_status();
						if (zephir_is_true(&_27$$11)) {
							break;
						}
						ZEPHIR_INIT_NVAR(&node);
						ZVAL_NULL(&node);
				}
			}
			ZEPHIR_INIT_NVAR(&address);
		}
	}
	_28 = Z_TYPE_P(&node) == IS_NULL;
	if (_28) {
		ZEPHIR_INIT_VAR(&_29);
		ZVAL_STRING(&_29, "Linux");
		_28 = ZEPHIR_IS_STRING_IDENTICAL(&_29, "Darwin");
	}
	if (_28) {
		ZEPHIR_CALL_FUNCTION(NULL, "ob_start", &_30, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_31$$14);
		ZVAL_STRING(&_31$$14, "ifconfig 2>&1");
		ZEPHIR_CALL_FUNCTION(NULL, "passthru", &_32, 0, &_31$$14);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&output, "ob_get_clean", &_33, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_31$$14);
		ZVAL_STRING(&_31$$14, "/ether\\s+([0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2})/i");
		ZEPHIR_INIT_VAR(&_34$$14);
		ZEPHIR_INIT_VAR(&_35$$14);
		ZVAL_STRING(&_35$$14, "/ether\\s+([0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2})/i");
		zephir_preg_match(&_34$$14, &_35$$14, &output, &matches, 0, 0 , 0 );
		if (zephir_is_true(&_34$$14)) {
			zephir_memory_observe(&_36$$15);
			zephir_array_fetch_long(&_36$$15, &matches, 1, PH_NOISY, "phalcon/Encryption/Security/Uuid/SysNodeProvider.zep", 87);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_37$$15);
			ZVAL_STRING(&_37$$15, ":");
			ZEPHIR_INIT_VAR(&_38$$15);
			ZVAL_STRING(&_38$$15, "");
			ZEPHIR_INIT_NVAR(&node);
			zephir_fast_str_replace(&node, &_37$$15, &_38$$15, &_36$$15);
		}
	}
	_39 = Z_TYPE_P(&node) == IS_NULL;
	if (_39) {
		ZEPHIR_INIT_VAR(&_40);
		ZVAL_STRING(&_40, "Linux");
		_39 = ZEPHIR_IS_STRING_IDENTICAL(&_40, "Windows");
	}
	if (_39) {
		ZEPHIR_CALL_FUNCTION(NULL, "ob_start", &_30, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_41$$16);
		ZVAL_STRING(&_41$$16, "ipconfig /all 2>&1");
		ZEPHIR_CALL_FUNCTION(NULL, "passthru", &_32, 0, &_41$$16);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&output, "ob_get_clean", &_33, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_41$$16);
		ZVAL_STRING(&_41$$16, "/Physical Address[^:]*:\\s+([0-9a-f]{2}-[0-9a-f]{2}-[0-9a-f]{2}-[0-9a-f]{2}-[0-9a-f]{2}-[0-9a-f]{2})/i");
		ZEPHIR_INIT_VAR(&_42$$16);
		ZEPHIR_INIT_VAR(&_43$$16);
		ZVAL_STRING(&_43$$16, "/Physical Address[^:]*:\\s+([0-9a-f]{2}-[0-9a-f]{2}-[0-9a-f]{2}-[0-9a-f]{2}-[0-9a-f]{2}-[0-9a-f]{2})/i");
		zephir_preg_match(&_42$$16, &_43$$16, &output, &matches, 0, 0 , 0 );
		if (zephir_is_true(&_42$$16)) {
			ZEPHIR_INIT_VAR(&_44$$17);
			zephir_memory_observe(&_45$$17);
			zephir_array_fetch_long(&_45$$17, &matches, 1, PH_NOISY, "phalcon/Encryption/Security/Uuid/SysNodeProvider.zep", 97);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_46$$17);
			ZVAL_STRING(&_46$$17, "-");
			ZEPHIR_INIT_VAR(&_47$$17);
			ZVAL_STRING(&_47$$17, "");
			zephir_fast_str_replace(&_44$$17, &_46$$17, &_47$$17, &_45$$17);
			ZEPHIR_INIT_NVAR(&node);
			zephir_fast_strtolower(&node, &_44$$17);
		}
	}
	_48 = Z_TYPE_P(&node) == IS_NULL;
	if (_48) {
		ZEPHIR_INIT_VAR(&_49);
		ZVAL_STRING(&_49, "Linux");
		_48 = ZEPHIR_IS_STRING_IDENTICAL(&_49, "BSD");
	}
	if (_48) {
		ZEPHIR_CALL_FUNCTION(NULL, "ob_start", &_30, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_50$$18);
		ZVAL_STRING(&_50$$18, "netstat -i -f link 2>&1");
		ZEPHIR_CALL_FUNCTION(NULL, "passthru", &_32, 0, &_50$$18);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&output, "ob_get_clean", &_33, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_50$$18);
		ZVAL_STRING(&_50$$18, "/([0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2})/i");
		ZEPHIR_INIT_VAR(&_51$$18);
		ZEPHIR_INIT_VAR(&_52$$18);
		ZVAL_STRING(&_52$$18, "/([0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2})/i");
		zephir_preg_match(&_51$$18, &_52$$18, &output, &matches, 0, 0 , 0 );
		if (zephir_is_true(&_51$$18)) {
			zephir_memory_observe(&_53$$19);
			zephir_array_fetch_long(&_53$$19, &matches, 1, PH_NOISY, "phalcon/Encryption/Security/Uuid/SysNodeProvider.zep", 107);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_54$$19);
			ZVAL_STRING(&_54$$19, ":");
			ZEPHIR_INIT_VAR(&_55$$19);
			ZVAL_STRING(&_55$$19, "");
			ZEPHIR_INIT_NVAR(&node);
			zephir_fast_str_replace(&node, &_54$$19, &_55$$19, &_53$$19);
		}
	}
	_56 = Z_TYPE_P(&node) == IS_NULL;
	if (!(_56)) {
		ZEPHIR_CALL_METHOD(&_57, this_ptr, "isValidNode", &_18, 0, &node);
		zephir_check_call_status();
		_56 = !zephir_is_true(&_57);
	}
	if (_56) {
		ZEPHIR_INIT_VAR(&_58$$20);
		object_init_ex(&_58$$20, phalcon_encryption_security_uuid_randomnodeprovider_ce);
		if (zephir_has_constructor(&_58$$20)) {
			ZEPHIR_CALL_METHOD(NULL, &_58$$20, "__construct", NULL, 0);
			zephir_check_call_status();
		}

		ZEPHIR_CALL_METHOD(&node, &_58$$20, "getNode", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 739, &node);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "apcu_store");
	ZEPHIR_CALL_METHOD(&_59, this_ptr, "phpFunctionExists", &_3, 0, &_2);
	zephir_check_call_status();
	if (zephir_is_true(&_59)) {
		zephir_read_property_cached(&_60$$21, this_ptr, _zephir_prop_0, 739, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_61$$21);
		ZVAL_STRING(&_61$$21, "__phalcon_uuid_node");
		ZEPHIR_CALL_FUNCTION(NULL, "apcu_store", NULL, 289, &_61$$21, &_60$$21);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER_TYPED(getThis(), "node", IS_STRING);
}

/**
 * Returns true if the given hex node is a valid non-loopback, non-broadcast MAC.
 */
PHP_METHOD(Phalcon_Encryption_Security_Uuid_SysNodeProvider, isValidNode)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval node_zv, _0;
	zend_string *node = NULL;

	ZVAL_UNDEF(&node_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(node)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&node_zv);
	ZVAL_STR_COPY(&node_zv, node);
	if (zephir_fast_strlen_ev(&node_zv) != 12) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_FUNCTION(&_0, "ctype_xdigit", NULL, 0, &node_zv);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		RETURN_MM_BOOL(0);
	}
	_1 = ZEPHIR_IS_STRING_IDENTICAL(&node_zv, "000000000000");
	if (!(_1)) {
		_1 = ZEPHIR_IS_STRING_IDENTICAL(&node_zv, "ffffffffffff");
	}
	if (_1) {
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);
}

/**
 * Closes an open file pointer
 *
 * @link https://php.net/manual/en/function.fclose.php
 *
 * @param resource $handle
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Encryption_Security_Uuid_SysNodeProvider, phpFclose)
{
	zval *handle, handle_sub;

	ZVAL_UNDEF(&handle_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle);
	RETURN_BOOL(zephir_fclose(handle));
}

/**
 * Gets line from file pointer and parse for CSV fields
 *
 * @param resource $stream
 * @param int      $length
 * @param string   $separator
 * @param string   $enclosure
 * @param string   $escape
 *
 * @return array<array-key, mixed>|false
 *
 * @link https://php.net/manual/en/function.fgetcsv.php
 */
PHP_METHOD(Phalcon_Encryption_Security_Uuid_SysNodeProvider, phpFgetCsv)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_string *separator = NULL;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
	zval *stream, stream_sub, *length_param = NULL, separator_zv, *enclosure = NULL, enclosure_sub, *escape = NULL, escape_sub, __$null, _0;

	ZVAL_UNDEF(&stream_sub);
	ZVAL_UNDEF(&separator_zv);
	ZVAL_UNDEF(&enclosure_sub);
	ZVAL_UNDEF(&escape_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 5)
		Z_PARAM_ZVAL(stream)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(length)
		Z_PARAM_STR(separator)
		Z_PARAM_ZVAL_OR_NULL(enclosure)
		Z_PARAM_ZVAL_OR_NULL(escape)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	stream = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 1) {
		length_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 3) {
		enclosure = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		escape = ZEND_CALL_ARG(execute_data, 5);
	}
	if (!length_param) {
		length = 0;
	} else {
		}
	if (!separator) {
		separator = zend_string_init(ZEND_STRL(","), 0);
		zephir_memory_observe(&separator_zv);
		ZVAL_STR(&separator_zv, separator);
	} else {
		zephir_memory_observe(&separator_zv);
	ZVAL_STR_COPY(&separator_zv, separator);
	}
	if (!enclosure) {
		enclosure = &enclosure_sub;
		ZEPHIR_CPY_WRT(enclosure, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(enclosure);
	}
	if (!escape) {
		escape = &escape_sub;
		ZEPHIR_CPY_WRT(escape, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(escape);
	}
	if (Z_TYPE_P(enclosure) == IS_NULL) {
		ZEPHIR_INIT_NVAR(enclosure);
		ZVAL_STRING(enclosure, "\"");
	}
	if (Z_TYPE_P(escape) == IS_NULL) {
		ZEPHIR_INIT_NVAR(escape);
		ZVAL_STRING(escape, "\\");
	}
	ZVAL_LONG(&_0, length);
	ZEPHIR_RETURN_CALL_FUNCTION("fgetcsv", NULL, 160, stream, &_0, &separator_zv, enclosure, escape);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $filename
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.file-exists.php
 */
PHP_METHOD(Phalcon_Encryption_Security_Uuid_SysNodeProvider, phpFileExists)
{
	zval filename_zv;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&filename_zv, filename);
	RETURN_BOOL((zephir_file_exists(&filename_zv) == SUCCESS));
}

/**
 * @param string        $filename
 * @param bool          $useIncludePath
 * @param resource|null $context
 * @param int           $offset
 * @param int|null      $length
 *
 * @return false|string
 *
 * @link https://php.net/manual/en/function.file-get-contents.php
 */
PHP_METHOD(Phalcon_Encryption_Security_Uuid_SysNodeProvider, phpFileGetContents)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long offset, length, ZEPHIR_LAST_CALL_STATUS;
	zend_bool useIncludePath;
	zval filename_zv, *useIncludePath_param = NULL, *context = NULL, context_sub, *offset_param = NULL, *length_param = NULL, __$null, _0$$3, _1$$3, _3, _4, _5;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 5)
		Z_PARAM_STR(filename)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(useIncludePath)
		Z_PARAM_ZVAL_OR_NULL(context)
		Z_PARAM_LONG(offset)
		Z_PARAM_LONG_OR_NULL(length, is_null_true)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		useIncludePath_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		context = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		offset_param = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		length_param = ZEND_CALL_ARG(execute_data, 5);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!useIncludePath_param) {
		useIncludePath = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	if (!offset_param) {
		offset = 0;
	} else {
		}
	if (!length_param) {
		length = 0;
	} else {
		}
	if (0 == length) {
		ZVAL_BOOL(&_0$$3, (useIncludePath ? 1 : 0));
		ZVAL_LONG(&_1$$3, offset);
		ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", &_2, 161, &filename_zv, &_0$$3, context, &_1$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZVAL_BOOL(&_3, (useIncludePath ? 1 : 0));
	ZVAL_LONG(&_4, offset);
	ZVAL_LONG(&_5, length);
	ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", &_2, 161, &filename_zv, &_3, context, &_4, &_5);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string   $filename
 * @param mixed    $data
 * @param int      $flags
 * @param resource $context
 *
 * @return false|int
 *
 * @link https://php.net/manual/en/function.file-put-contents.php
 */
PHP_METHOD(Phalcon_Encryption_Security_Uuid_SysNodeProvider, phpFilePutContents)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long flags, ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv, *data, data_sub, *flags_param = NULL, *context = NULL, context_sub, __$null, _0;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(filename)
		Z_PARAM_ZVAL(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(flags)
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	data = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		flags_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		context = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!flags_param) {
		flags = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZVAL_LONG(&_0, flags);
	ZEPHIR_RETURN_CALL_FUNCTION("file_put_contents", NULL, 162, &filename_zv, data, &_0, context);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string        $filename
 * @param string        $mode
 * @param bool          $useIncludePath
 * @param resource|null $context
 *
 * @return resource|false
 *
 * @link https://php.net/manual/en/function.fopen.php
 */
PHP_METHOD(Phalcon_Encryption_Security_Uuid_SysNodeProvider, phpFopen)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool useIncludePath;
	zval filename_zv, mode_zv, *useIncludePath_param = NULL, *context = NULL, context_sub, __$null, _0;
	zend_string *filename = NULL, *mode = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&mode_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(filename)
		Z_PARAM_STR(mode)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(useIncludePath)
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		useIncludePath_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		context = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	zephir_memory_observe(&mode_zv);
	ZVAL_STR_COPY(&mode_zv, mode);
	if (!useIncludePath_param) {
		useIncludePath = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZVAL_BOOL(&_0, (useIncludePath ? 1 : 0));
	ZEPHIR_RETURN_CALL_FUNCTION("fopen", NULL, 163, &filename_zv, &mode_zv, &_0, context);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Binary-safe file write
 *
 * @link https://php.net/manual/en/function.fwrite.php
 *
 * @param resource $handle
 * @param string   $data
 * @param int|null $length
 *
 * @return false|int
 */
PHP_METHOD(Phalcon_Encryption_Security_Uuid_SysNodeProvider, phpFwrite)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
	zend_string *data = NULL;
	zval *handle, handle_sub, data_zv, *length_param = NULL, _0;

	ZVAL_UNDEF(&handle_sub);
	ZVAL_UNDEF(&data_zv);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(handle)
		Z_PARAM_STR(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG_OR_NULL(length, is_null_true)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	handle = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		length_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&data_zv);
	ZVAL_STR_COPY(&data_zv, data);
	if (!length_param) {
		length = 0;
	} else {
		}
	if (0 == length) {
		zephir_fwrite(return_value, handle, &data_zv);
		RETURN_MM();
	}
	ZVAL_LONG(&_0, length);
	ZEPHIR_RETURN_CALL_FUNCTION("fwrite", &_1, 164, handle, &data_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Tells whether the filename is a directory
 *
 * @param string $filename
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.is-dir.php
 */
PHP_METHOD(Phalcon_Encryption_Security_Uuid_SysNodeProvider, phpIsDir)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	ZEPHIR_RETURN_CALL_FUNCTION("is_dir", NULL, 165, &filename_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Tells whether the filename is writable
 *
 * @param string $filename
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.is-writable.php
 */
PHP_METHOD(Phalcon_Encryption_Security_Uuid_SysNodeProvider, phpIsWritable)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	ZEPHIR_RETURN_CALL_FUNCTION("is_writable", NULL, 166, &filename_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Makes a directory
 *
 * @param string        $directory
 * @param int           $permissions
 * @param bool          $recursive
 * @param resource|null $context
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.mkdir.php
 */
PHP_METHOD(Phalcon_Encryption_Security_Uuid_SysNodeProvider, phpMkdir)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool recursive;
	zend_long permissions, ZEPHIR_LAST_CALL_STATUS;
	zval directory_zv, *permissions_param = NULL, *recursive_param = NULL, *context = NULL, context_sub, __$null, _0, _1;
	zend_string *directory = NULL;

	ZVAL_UNDEF(&directory_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(directory)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(permissions)
		Z_PARAM_BOOL(recursive)
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		permissions_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		recursive_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		context = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&directory_zv);
	ZVAL_STR_COPY(&directory_zv, directory);
	if (!permissions_param) {
		permissions = 0777;
	} else {
		}
	if (!recursive_param) {
		recursive = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZVAL_LONG(&_0, permissions);
	ZVAL_BOOL(&_1, (recursive ? 1 : 0));
	ZEPHIR_RETURN_CALL_FUNCTION("mkdir", NULL, 167, &directory_zv, &_0, &_1, context);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string        $filename
 * @param resource|null $context
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.unlink.php
 */
PHP_METHOD(Phalcon_Encryption_Security_Uuid_SysNodeProvider, phpUnlink)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv, *context = NULL, context_sub, __$null;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(filename)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		context = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZEPHIR_RETURN_CALL_FUNCTION("unlink", NULL, 168, &filename_zv, context);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Find out whether an extension is loaded
 *
 * @param string $name
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.extension-loaded.php
 */
PHP_METHOD(Phalcon_Encryption_Security_Uuid_SysNodeProvider, phpExtensionLoaded)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv;
	zend_string *name = NULL;

	ZVAL_UNDEF(&name_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_RETURN_CALL_FUNCTION("extension_loaded", NULL, 472, &name_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return true if the given function has been defined
 *
 * @param string $functionName
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.function-exists.php
 */
PHP_METHOD(Phalcon_Encryption_Security_Uuid_SysNodeProvider, phpFunctionExists)
{
	zval functionName_zv;
	zend_string *functionName = NULL;

	ZVAL_UNDEF(&functionName_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(functionName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&functionName_zv, functionName);
	RETURN_BOOL((zephir_function_exists(&functionName_zv) == SUCCESS));
}

