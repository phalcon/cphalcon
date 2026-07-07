
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
 * For the full copyright and license information, please view the LICENSE.txt
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

	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_encryption_security_uuid_sysnodeprovider_ce, SL("node"), ZEND_ACC_PRIVATE);
	zend_class_implements(phalcon_encryption_security_uuid_sysnodeprovider_ce, 1, phalcon_encryption_security_uuid_nodeproviderinterface_ce);
	return SUCCESS;
}

/**
 * Returns the hardware MAC address as a 12-character hex string.
 * Result is cached in the instance property and optionally in APCu.
 */
PHP_METHOD(Phalcon_Encryption_Security_Uuid_SysNodeProvider, getNode)
{
	zend_bool _23, _31, _40, _48, _15$$7;
	zval cached, addresses, address, matches, output, node, _0, _2, _24, _32, _41, _49, _1$$4, _3$$6, *_4$$7, _14$$7, _5$$8, _6$$8, _7$$8, _9$$8, _10$$8, _11$$8, _12$$8, _16$$11, _17$$11, _18$$11, _19$$11, _20$$11, _21$$11, _22$$11, _25$$14, _26$$14, _27$$14, _28$$15, _29$$15, _30$$15, _33$$16, _34$$16, _35$$16, _36$$17, _37$$17, _38$$17, _39$$17, _42$$18, _43$$18, _44$$18, _45$$19, _46$$19, _47$$19, _50$$20, _51$$21, _52$$21;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cached);
	ZVAL_UNDEF(&addresses);
	ZVAL_UNDEF(&address);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&node);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_41);
	ZVAL_UNDEF(&_49);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_19$$11);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_21$$11);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&_25$$14);
	ZVAL_UNDEF(&_26$$14);
	ZVAL_UNDEF(&_27$$14);
	ZVAL_UNDEF(&_28$$15);
	ZVAL_UNDEF(&_29$$15);
	ZVAL_UNDEF(&_30$$15);
	ZVAL_UNDEF(&_33$$16);
	ZVAL_UNDEF(&_34$$16);
	ZVAL_UNDEF(&_35$$16);
	ZVAL_UNDEF(&_36$$17);
	ZVAL_UNDEF(&_37$$17);
	ZVAL_UNDEF(&_38$$17);
	ZVAL_UNDEF(&_39$$17);
	ZVAL_UNDEF(&_42$$18);
	ZVAL_UNDEF(&_43$$18);
	ZVAL_UNDEF(&_44$$18);
	ZVAL_UNDEF(&_45$$19);
	ZVAL_UNDEF(&_46$$19);
	ZVAL_UNDEF(&_47$$19);
	ZVAL_UNDEF(&_50$$20);
	ZVAL_UNDEF(&_51$$21);
	ZVAL_UNDEF(&_52$$21);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("node"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		RETURN_MM_MEMBER_TYPED(getThis(), "node", IS_STRING);
	}
	if ((zephir_function_exists_ex(ZEND_STRL("apcu_fetch")) == SUCCESS)) {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZVAL_STRING(&_1$$4, "__phalcon_uuid_node");
		ZEPHIR_CALL_FUNCTION(&cached, "apcu_fetch", NULL, 263, &_1$$4);
		zephir_check_call_status();
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&cached)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("node"), &cached);
			RETURN_MM_MEMBER_TYPED(getThis(), "node", IS_STRING);
		}
	}
	ZEPHIR_INIT_VAR(&node);
	ZVAL_NULL(&node);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "Linux");
	if (ZEPHIR_IS_STRING_IDENTICAL(&_2, "Linux")) {
		ZEPHIR_INIT_VAR(&_3$$6);
		ZVAL_STRING(&_3$$6, "/sys/class/net/*/address");
		ZEPHIR_CALL_FUNCTION(&addresses, "glob", NULL, 0, &_3$$6);
		zephir_check_call_status();
		if (Z_TYPE_P(&addresses) == IS_ARRAY) {
			zephir_is_iterable(&addresses, 0, "phalcon/Encryption/Security/Uuid/SysNodeProvider.zep", 79);
			if (Z_TYPE_P(&addresses) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&addresses), _4$$7)
				{
					ZEPHIR_INIT_NVAR(&address);
					ZVAL_COPY(&address, _4$$7);
					ZEPHIR_INIT_NVAR(&_5$$8);
					ZVAL_STRING(&_5$$8, "/lo/");
					ZEPHIR_INIT_NVAR(&_6$$8);
					zephir_fast_strpos(&_6$$8, &address, &_5$$8, 0 );
					if (!ZEPHIR_IS_FALSE_IDENTICAL(&_6$$8)) {
						continue;
					}
					ZEPHIR_CALL_METHOD(&_7$$8, this_ptr, "phpfilegetcontents", &_8, 0, &address);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&node);
					zephir_fast_trim(&node, &_7$$8, NULL , ZEPHIR_TRIM_BOTH);
					ZEPHIR_INIT_NVAR(&_9$$8);
					ZEPHIR_INIT_NVAR(&_10$$8);
					ZVAL_STRING(&_10$$8, ":");
					ZEPHIR_INIT_NVAR(&_11$$8);
					ZVAL_STRING(&_11$$8, "");
					zephir_fast_str_replace(&_9$$8, &_10$$8, &_11$$8, &node);
					ZEPHIR_CPY_WRT(&node, &_9$$8);
					ZEPHIR_CALL_METHOD(&_12$$8, this_ptr, "isvalidnode", &_13, 0, &node);
					zephir_check_call_status();
					if (zephir_is_true(&_12$$8)) {
						break;
					}
					ZEPHIR_INIT_NVAR(&node);
					ZVAL_NULL(&node);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &addresses, "rewind", NULL, 0);
				zephir_check_call_status();
				_15$$7 = 1;
				while (1) {
					if (_15$$7) {
						_15$$7 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, &addresses, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_14$$7, &addresses, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_14$$7)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&address, &addresses, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_16$$11);
						ZVAL_STRING(&_16$$11, "/lo/");
						ZEPHIR_INIT_NVAR(&_17$$11);
						zephir_fast_strpos(&_17$$11, &address, &_16$$11, 0 );
						if (!ZEPHIR_IS_FALSE_IDENTICAL(&_17$$11)) {
							continue;
						}
						ZEPHIR_CALL_METHOD(&_18$$11, this_ptr, "phpfilegetcontents", &_8, 0, &address);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&node);
						zephir_fast_trim(&node, &_18$$11, NULL , ZEPHIR_TRIM_BOTH);
						ZEPHIR_INIT_NVAR(&_19$$11);
						ZEPHIR_INIT_NVAR(&_20$$11);
						ZVAL_STRING(&_20$$11, ":");
						ZEPHIR_INIT_NVAR(&_21$$11);
						ZVAL_STRING(&_21$$11, "");
						zephir_fast_str_replace(&_19$$11, &_20$$11, &_21$$11, &node);
						ZEPHIR_CPY_WRT(&node, &_19$$11);
						ZEPHIR_CALL_METHOD(&_22$$11, this_ptr, "isvalidnode", &_13, 0, &node);
						zephir_check_call_status();
						if (zephir_is_true(&_22$$11)) {
							break;
						}
						ZEPHIR_INIT_NVAR(&node);
						ZVAL_NULL(&node);
				}
			}
			ZEPHIR_INIT_NVAR(&address);
		}
	}
	_23 = Z_TYPE_P(&node) == IS_NULL;
	if (_23) {
		ZEPHIR_INIT_VAR(&_24);
		ZVAL_STRING(&_24, "Linux");
		_23 = ZEPHIR_IS_STRING_IDENTICAL(&_24, "Darwin");
	}
	if (_23) {
		ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_25$$14);
		ZVAL_STRING(&_25$$14, "ifconfig 2>&1");
		ZEPHIR_CALL_FUNCTION(NULL, "passthru", NULL, 0, &_25$$14);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&output, "ob_get_clean", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_25$$14);
		ZVAL_STRING(&_25$$14, "/ether\\s+([0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2})/i");
		ZEPHIR_INIT_VAR(&_26$$14);
		ZEPHIR_INIT_VAR(&_27$$14);
		ZVAL_STRING(&_27$$14, "/ether\\s+([0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2})/i");
		zephir_preg_match(&_26$$14, &_27$$14, &output, &matches, 0, 0 , 0 );
		if (zephir_is_true(&_26$$14)) {
			zephir_array_fetch_long(&_28$$15, &matches, 1, PH_NOISY | PH_READONLY, "phalcon/Encryption/Security/Uuid/SysNodeProvider.zep", 88);
			ZEPHIR_INIT_VAR(&_29$$15);
			ZVAL_STRING(&_29$$15, ":");
			ZEPHIR_INIT_VAR(&_30$$15);
			ZVAL_STRING(&_30$$15, "");
			ZEPHIR_INIT_NVAR(&node);
			zephir_fast_str_replace(&node, &_29$$15, &_30$$15, &_28$$15);
		}
	}
	_31 = Z_TYPE_P(&node) == IS_NULL;
	if (_31) {
		ZEPHIR_INIT_VAR(&_32);
		ZVAL_STRING(&_32, "Linux");
		_31 = ZEPHIR_IS_STRING_IDENTICAL(&_32, "Windows");
	}
	if (_31) {
		ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_33$$16);
		ZVAL_STRING(&_33$$16, "ipconfig /all 2>&1");
		ZEPHIR_CALL_FUNCTION(NULL, "passthru", NULL, 0, &_33$$16);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&output, "ob_get_clean", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_33$$16);
		ZVAL_STRING(&_33$$16, "/Physical Address[^:]*:\\s+([0-9a-f]{2}-[0-9a-f]{2}-[0-9a-f]{2}-[0-9a-f]{2}-[0-9a-f]{2}-[0-9a-f]{2})/i");
		ZEPHIR_INIT_VAR(&_34$$16);
		ZEPHIR_INIT_VAR(&_35$$16);
		ZVAL_STRING(&_35$$16, "/Physical Address[^:]*:\\s+([0-9a-f]{2}-[0-9a-f]{2}-[0-9a-f]{2}-[0-9a-f]{2}-[0-9a-f]{2}-[0-9a-f]{2})/i");
		zephir_preg_match(&_34$$16, &_35$$16, &output, &matches, 0, 0 , 0 );
		if (zephir_is_true(&_34$$16)) {
			ZEPHIR_INIT_VAR(&_36$$17);
			zephir_array_fetch_long(&_37$$17, &matches, 1, PH_NOISY | PH_READONLY, "phalcon/Encryption/Security/Uuid/SysNodeProvider.zep", 98);
			ZEPHIR_INIT_VAR(&_38$$17);
			ZVAL_STRING(&_38$$17, "-");
			ZEPHIR_INIT_VAR(&_39$$17);
			ZVAL_STRING(&_39$$17, "");
			zephir_fast_str_replace(&_36$$17, &_38$$17, &_39$$17, &_37$$17);
			ZEPHIR_INIT_NVAR(&node);
			zephir_fast_strtolower(&node, &_36$$17);
		}
	}
	_40 = Z_TYPE_P(&node) == IS_NULL;
	if (_40) {
		ZEPHIR_INIT_VAR(&_41);
		ZVAL_STRING(&_41, "Linux");
		_40 = ZEPHIR_IS_STRING_IDENTICAL(&_41, "BSD");
	}
	if (_40) {
		ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_42$$18);
		ZVAL_STRING(&_42$$18, "netstat -i -f link 2>&1");
		ZEPHIR_CALL_FUNCTION(NULL, "passthru", NULL, 0, &_42$$18);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&output, "ob_get_clean", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_42$$18);
		ZVAL_STRING(&_42$$18, "/([0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2})/i");
		ZEPHIR_INIT_VAR(&_43$$18);
		ZEPHIR_INIT_VAR(&_44$$18);
		ZVAL_STRING(&_44$$18, "/([0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2})/i");
		zephir_preg_match(&_43$$18, &_44$$18, &output, &matches, 0, 0 , 0 );
		if (zephir_is_true(&_43$$18)) {
			zephir_array_fetch_long(&_45$$19, &matches, 1, PH_NOISY | PH_READONLY, "phalcon/Encryption/Security/Uuid/SysNodeProvider.zep", 108);
			ZEPHIR_INIT_VAR(&_46$$19);
			ZVAL_STRING(&_46$$19, ":");
			ZEPHIR_INIT_VAR(&_47$$19);
			ZVAL_STRING(&_47$$19, "");
			ZEPHIR_INIT_NVAR(&node);
			zephir_fast_str_replace(&node, &_46$$19, &_47$$19, &_45$$19);
		}
	}
	_48 = Z_TYPE_P(&node) == IS_NULL;
	if (!(_48)) {
		ZEPHIR_CALL_METHOD(&_49, this_ptr, "isvalidnode", &_13, 0, &node);
		zephir_check_call_status();
		_48 = !zephir_is_true(&_49);
	}
	if (_48) {
		ZEPHIR_INIT_VAR(&_50$$20);
		object_init_ex(&_50$$20, phalcon_encryption_security_uuid_randomnodeprovider_ce);
		if (zephir_has_constructor(&_50$$20)) {
			ZEPHIR_CALL_METHOD(NULL, &_50$$20, "__construct", NULL, 0);
			zephir_check_call_status();
		}

		ZEPHIR_CALL_METHOD(&node, &_50$$20, "getnode", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("node"), &node);
	if ((zephir_function_exists_ex(ZEND_STRL("apcu_store")) == SUCCESS)) {
		zephir_read_property(&_51$$21, this_ptr, ZEND_STRL("node"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_52$$21);
		ZVAL_STRING(&_52$$21, "__phalcon_uuid_node");
		ZEPHIR_CALL_FUNCTION(NULL, "apcu_store", NULL, 264, &_52$$21, &_51$$21);
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
	ZEPHIR_CALL_FUNCTION(&_0, "ctype_xdigit", NULL, 481, &node_zv);
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
	ZEPHIR_RETURN_CALL_FUNCTION("fgetcsv", NULL, 158, stream, &_0, &separator_zv, enclosure, escape);
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
 * @param string $filename
 *
 * @return false|string
 *
 * @link https://php.net/manual/en/function.file-get-contents.php
 */
PHP_METHOD(Phalcon_Encryption_Security_Uuid_SysNodeProvider, phpFileGetContents)
{
	zval filename_zv;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&filename_zv, filename);
	zephir_file_get_contents(return_value, &filename_zv);
	return;
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
	ZEPHIR_RETURN_CALL_FUNCTION("file_put_contents", NULL, 159, &filename_zv, data, &_0, context);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $filename
 * @param string $mode
 *
 * @return resource|false
 *
 * @link https://php.net/manual/en/function.fopen.php
 */
PHP_METHOD(Phalcon_Encryption_Security_Uuid_SysNodeProvider, phpFopen)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv, mode_zv;
	zend_string *filename = NULL, *mode = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&mode_zv);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(filename)
		Z_PARAM_STR(mode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	zephir_memory_observe(&mode_zv);
	ZVAL_STR_COPY(&mode_zv, mode);
	ZEPHIR_RETURN_CALL_FUNCTION("fopen", NULL, 160, &filename_zv, &mode_zv);
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
	ZEPHIR_RETURN_CALL_FUNCTION("fwrite", NULL, 161, handle, &data_zv, &_0);
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
	ZEPHIR_RETURN_CALL_FUNCTION("is_writable", NULL, 162, &filename_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $filename
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.unlink.php
 */
PHP_METHOD(Phalcon_Encryption_Security_Uuid_SysNodeProvider, phpUnlink)
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
	ZEPHIR_RETURN_CALL_FUNCTION("unlink", NULL, 163, &filename_zv);
	zephir_check_call_status();
	RETURN_MM();
}

