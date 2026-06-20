
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
#include "kernel/file.h"
#include "kernel/array.h"


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
	zend_bool _22, _30, _39, _47, _14$$7;
	zval cached, addresses, address, matches, output, node, _0, _2, _23, _31, _40, _48, _1$$4, _3$$6, *_4$$7, _13$$7, _5$$8, _6$$8, _7$$8, _8$$8, _9$$8, _10$$8, _11$$8, _15$$11, _16$$11, _17$$11, _18$$11, _19$$11, _20$$11, _21$$11, _24$$14, _25$$14, _26$$14, _27$$15, _28$$15, _29$$15, _32$$16, _33$$16, _34$$16, _35$$17, _36$$17, _37$$17, _38$$17, _41$$18, _42$$18, _43$$18, _44$$19, _45$$19, _46$$19, _49$$20, _50$$21, _51$$21;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_12 = NULL;
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
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_40);
	ZVAL_UNDEF(&_48);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_19$$11);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_21$$11);
	ZVAL_UNDEF(&_24$$14);
	ZVAL_UNDEF(&_25$$14);
	ZVAL_UNDEF(&_26$$14);
	ZVAL_UNDEF(&_27$$15);
	ZVAL_UNDEF(&_28$$15);
	ZVAL_UNDEF(&_29$$15);
	ZVAL_UNDEF(&_32$$16);
	ZVAL_UNDEF(&_33$$16);
	ZVAL_UNDEF(&_34$$16);
	ZVAL_UNDEF(&_35$$17);
	ZVAL_UNDEF(&_36$$17);
	ZVAL_UNDEF(&_37$$17);
	ZVAL_UNDEF(&_38$$17);
	ZVAL_UNDEF(&_41$$18);
	ZVAL_UNDEF(&_42$$18);
	ZVAL_UNDEF(&_43$$18);
	ZVAL_UNDEF(&_44$$19);
	ZVAL_UNDEF(&_45$$19);
	ZVAL_UNDEF(&_46$$19);
	ZVAL_UNDEF(&_49$$20);
	ZVAL_UNDEF(&_50$$21);
	ZVAL_UNDEF(&_51$$21);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("node"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		RETURN_MM_MEMBER_TYPED(getThis(), "node", IS_STRING);
	}
	if ((zephir_function_exists_ex(ZEND_STRL("apcu_fetch")) == SUCCESS)) {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZVAL_STRING(&_1$$4, "__phalcon_uuid_node");
		ZEPHIR_CALL_FUNCTION(&cached, "apcu_fetch", NULL, 220, &_1$$4);
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
			zephir_is_iterable(&addresses, 0, "phalcon/Encryption/Security/Uuid/SysNodeProvider.zep", 75);
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
					ZEPHIR_INIT_NVAR(&_7$$8);
					zephir_file_get_contents(&_7$$8, &address);
					ZEPHIR_INIT_NVAR(&node);
					zephir_fast_trim(&node, &_7$$8, NULL , ZEPHIR_TRIM_BOTH);
					ZEPHIR_INIT_NVAR(&_8$$8);
					ZEPHIR_INIT_NVAR(&_9$$8);
					ZVAL_STRING(&_9$$8, ":");
					ZEPHIR_INIT_NVAR(&_10$$8);
					ZVAL_STRING(&_10$$8, "");
					zephir_fast_str_replace(&_8$$8, &_9$$8, &_10$$8, &node);
					ZEPHIR_CPY_WRT(&node, &_8$$8);
					ZEPHIR_CALL_METHOD(&_11$$8, this_ptr, "isvalidnode", &_12, 0, &node);
					zephir_check_call_status();
					if (zephir_is_true(&_11$$8)) {
						break;
					}
					ZEPHIR_INIT_NVAR(&node);
					ZVAL_NULL(&node);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &addresses, "rewind", NULL, 0);
				zephir_check_call_status();
				_14$$7 = 1;
				while (1) {
					if (_14$$7) {
						_14$$7 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, &addresses, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_13$$7, &addresses, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_13$$7)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&address, &addresses, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_15$$11);
						ZVAL_STRING(&_15$$11, "/lo/");
						ZEPHIR_INIT_NVAR(&_16$$11);
						zephir_fast_strpos(&_16$$11, &address, &_15$$11, 0 );
						if (!ZEPHIR_IS_FALSE_IDENTICAL(&_16$$11)) {
							continue;
						}
						ZEPHIR_INIT_NVAR(&_17$$11);
						zephir_file_get_contents(&_17$$11, &address);
						ZEPHIR_INIT_NVAR(&node);
						zephir_fast_trim(&node, &_17$$11, NULL , ZEPHIR_TRIM_BOTH);
						ZEPHIR_INIT_NVAR(&_18$$11);
						ZEPHIR_INIT_NVAR(&_19$$11);
						ZVAL_STRING(&_19$$11, ":");
						ZEPHIR_INIT_NVAR(&_20$$11);
						ZVAL_STRING(&_20$$11, "");
						zephir_fast_str_replace(&_18$$11, &_19$$11, &_20$$11, &node);
						ZEPHIR_CPY_WRT(&node, &_18$$11);
						ZEPHIR_CALL_METHOD(&_21$$11, this_ptr, "isvalidnode", &_12, 0, &node);
						zephir_check_call_status();
						if (zephir_is_true(&_21$$11)) {
							break;
						}
						ZEPHIR_INIT_NVAR(&node);
						ZVAL_NULL(&node);
				}
			}
			ZEPHIR_INIT_NVAR(&address);
		}
	}
	_22 = Z_TYPE_P(&node) == IS_NULL;
	if (_22) {
		ZEPHIR_INIT_VAR(&_23);
		ZVAL_STRING(&_23, "Linux");
		_22 = ZEPHIR_IS_STRING_IDENTICAL(&_23, "Darwin");
	}
	if (_22) {
		ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_24$$14);
		ZVAL_STRING(&_24$$14, "ifconfig 2>&1");
		ZEPHIR_CALL_FUNCTION(NULL, "passthru", NULL, 0, &_24$$14);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&output, "ob_get_clean", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_24$$14);
		ZVAL_STRING(&_24$$14, "/ether\\s+([0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2})/i");
		ZEPHIR_INIT_VAR(&_25$$14);
		ZEPHIR_INIT_VAR(&_26$$14);
		ZVAL_STRING(&_26$$14, "/ether\\s+([0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2})/i");
		zephir_preg_match(&_25$$14, &_26$$14, &output, &matches, 0, 0 , 0 );
		if (zephir_is_true(&_25$$14)) {
			zephir_array_fetch_long(&_27$$15, &matches, 1, PH_NOISY | PH_READONLY, "phalcon/Encryption/Security/Uuid/SysNodeProvider.zep", 84);
			ZEPHIR_INIT_VAR(&_28$$15);
			ZVAL_STRING(&_28$$15, ":");
			ZEPHIR_INIT_VAR(&_29$$15);
			ZVAL_STRING(&_29$$15, "");
			ZEPHIR_INIT_NVAR(&node);
			zephir_fast_str_replace(&node, &_28$$15, &_29$$15, &_27$$15);
		}
	}
	_30 = Z_TYPE_P(&node) == IS_NULL;
	if (_30) {
		ZEPHIR_INIT_VAR(&_31);
		ZVAL_STRING(&_31, "Linux");
		_30 = ZEPHIR_IS_STRING_IDENTICAL(&_31, "Windows");
	}
	if (_30) {
		ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_32$$16);
		ZVAL_STRING(&_32$$16, "ipconfig /all 2>&1");
		ZEPHIR_CALL_FUNCTION(NULL, "passthru", NULL, 0, &_32$$16);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&output, "ob_get_clean", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_32$$16);
		ZVAL_STRING(&_32$$16, "/Physical Address[^:]*:\\s+([0-9a-f]{2}-[0-9a-f]{2}-[0-9a-f]{2}-[0-9a-f]{2}-[0-9a-f]{2}-[0-9a-f]{2})/i");
		ZEPHIR_INIT_VAR(&_33$$16);
		ZEPHIR_INIT_VAR(&_34$$16);
		ZVAL_STRING(&_34$$16, "/Physical Address[^:]*:\\s+([0-9a-f]{2}-[0-9a-f]{2}-[0-9a-f]{2}-[0-9a-f]{2}-[0-9a-f]{2}-[0-9a-f]{2})/i");
		zephir_preg_match(&_33$$16, &_34$$16, &output, &matches, 0, 0 , 0 );
		if (zephir_is_true(&_33$$16)) {
			ZEPHIR_INIT_VAR(&_35$$17);
			zephir_array_fetch_long(&_36$$17, &matches, 1, PH_NOISY | PH_READONLY, "phalcon/Encryption/Security/Uuid/SysNodeProvider.zep", 94);
			ZEPHIR_INIT_VAR(&_37$$17);
			ZVAL_STRING(&_37$$17, "-");
			ZEPHIR_INIT_VAR(&_38$$17);
			ZVAL_STRING(&_38$$17, "");
			zephir_fast_str_replace(&_35$$17, &_37$$17, &_38$$17, &_36$$17);
			ZEPHIR_INIT_NVAR(&node);
			zephir_fast_strtolower(&node, &_35$$17);
		}
	}
	_39 = Z_TYPE_P(&node) == IS_NULL;
	if (_39) {
		ZEPHIR_INIT_VAR(&_40);
		ZVAL_STRING(&_40, "Linux");
		_39 = ZEPHIR_IS_STRING_IDENTICAL(&_40, "BSD");
	}
	if (_39) {
		ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_41$$18);
		ZVAL_STRING(&_41$$18, "netstat -i -f link 2>&1");
		ZEPHIR_CALL_FUNCTION(NULL, "passthru", NULL, 0, &_41$$18);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&output, "ob_get_clean", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_41$$18);
		ZVAL_STRING(&_41$$18, "/([0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2})/i");
		ZEPHIR_INIT_VAR(&_42$$18);
		ZEPHIR_INIT_VAR(&_43$$18);
		ZVAL_STRING(&_43$$18, "/([0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2})/i");
		zephir_preg_match(&_42$$18, &_43$$18, &output, &matches, 0, 0 , 0 );
		if (zephir_is_true(&_42$$18)) {
			zephir_array_fetch_long(&_44$$19, &matches, 1, PH_NOISY | PH_READONLY, "phalcon/Encryption/Security/Uuid/SysNodeProvider.zep", 104);
			ZEPHIR_INIT_VAR(&_45$$19);
			ZVAL_STRING(&_45$$19, ":");
			ZEPHIR_INIT_VAR(&_46$$19);
			ZVAL_STRING(&_46$$19, "");
			ZEPHIR_INIT_NVAR(&node);
			zephir_fast_str_replace(&node, &_45$$19, &_46$$19, &_44$$19);
		}
	}
	_47 = Z_TYPE_P(&node) == IS_NULL;
	if (!(_47)) {
		ZEPHIR_CALL_METHOD(&_48, this_ptr, "isvalidnode", &_12, 0, &node);
		zephir_check_call_status();
		_47 = !zephir_is_true(&_48);
	}
	if (_47) {
		ZEPHIR_INIT_VAR(&_49$$20);
		object_init_ex(&_49$$20, phalcon_encryption_security_uuid_randomnodeprovider_ce);
		if (zephir_has_constructor(&_49$$20)) {
			ZEPHIR_CALL_METHOD(NULL, &_49$$20, "__construct", NULL, 0);
			zephir_check_call_status();
		}

		ZEPHIR_CALL_METHOD(&node, &_49$$20, "getnode", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("node"), &node);
	if ((zephir_function_exists_ex(ZEND_STRL("apcu_store")) == SUCCESS)) {
		zephir_read_property(&_50$$21, this_ptr, ZEND_STRL("node"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_51$$21);
		ZVAL_STRING(&_51$$21, "__phalcon_uuid_node");
		ZEPHIR_CALL_FUNCTION(NULL, "apcu_store", NULL, 221, &_51$$21, &_50$$21);
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
	ZEPHIR_CALL_FUNCTION(&_0, "ctype_xdigit", NULL, 449, &node_zv);
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

