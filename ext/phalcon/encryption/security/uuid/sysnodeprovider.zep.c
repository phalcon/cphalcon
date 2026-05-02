
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
 *   1. Instance property  — free on all calls after the first within this instance.
 *   2. APCu               — cross-request within the same PHP-FPM worker (optional).
 *
 * Falls back to RandomNodeProvider if no valid MAC address is found.
 *
 * Platform support:
 *   Linux   — reads /sys/class/net/*\/address
 *   macOS   — passthru("ifconfig 2>&1")
 *   Windows — passthru("ipconfig /all 2>&1")
 *   FreeBSD — passthru("netstat -i -f link 2>&1")
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
	zend_bool _21, _29, _38, _46;
	zval cached, addresses, address, matches, output, node, _0, _2, _22, _30, _39, _47, _1$$4, _3$$6, *_4$$7, _5$$7, _6$$8, _7$$8, _8$$8, _9$$8, _10$$8, _11$$8, _12$$8, _14$$11, _15$$11, _16$$11, _17$$11, _18$$11, _19$$11, _20$$11, _23$$14, _24$$14, _25$$14, _26$$15, _27$$15, _28$$15, _31$$16, _32$$16, _33$$16, _34$$17, _35$$17, _36$$17, _37$$17, _40$$18, _41$$18, _42$$18, _43$$19, _44$$19, _45$$19, _48$$20, _49$$21, _50$$21;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_13 = NULL;
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
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&_47);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_19$$11);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_23$$14);
	ZVAL_UNDEF(&_24$$14);
	ZVAL_UNDEF(&_25$$14);
	ZVAL_UNDEF(&_26$$15);
	ZVAL_UNDEF(&_27$$15);
	ZVAL_UNDEF(&_28$$15);
	ZVAL_UNDEF(&_31$$16);
	ZVAL_UNDEF(&_32$$16);
	ZVAL_UNDEF(&_33$$16);
	ZVAL_UNDEF(&_34$$17);
	ZVAL_UNDEF(&_35$$17);
	ZVAL_UNDEF(&_36$$17);
	ZVAL_UNDEF(&_37$$17);
	ZVAL_UNDEF(&_40$$18);
	ZVAL_UNDEF(&_41$$18);
	ZVAL_UNDEF(&_42$$18);
	ZVAL_UNDEF(&_43$$19);
	ZVAL_UNDEF(&_44$$19);
	ZVAL_UNDEF(&_45$$19);
	ZVAL_UNDEF(&_48$$20);
	ZVAL_UNDEF(&_49$$21);
	ZVAL_UNDEF(&_50$$21);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("node"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		RETURN_MM_MEMBER(getThis(), "node");
	}
	if ((zephir_function_exists_ex(ZEND_STRL("apcu_fetch")) == SUCCESS)) {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZVAL_STRING(&_1$$4, "__phalcon_uuid_node");
		ZEPHIR_CALL_FUNCTION(&cached, "apcu_fetch", NULL, 117, &_1$$4);
		zephir_check_call_status();
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&cached)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("node"), &cached);
			RETURN_MM_MEMBER(getThis(), "node");
		}
	}
	ZEPHIR_INIT_VAR(&node);
	ZVAL_NULL(&node);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "Linux");
	if (ZEPHIR_IS_STRING_IDENTICAL(&_2, "Linux")) {
		ZEPHIR_INIT_VAR(&_3$$6);
		ZVAL_STRING(&_3$$6, "/sys/class/net/*/address");
		ZEPHIR_CALL_FUNCTION(&addresses, "glob", NULL, 281, &_3$$6);
		zephir_check_call_status();
		if (Z_TYPE_P(&addresses) == IS_ARRAY) {
			zephir_is_iterable(&addresses, 0, "phalcon/Encryption/Security/Uuid/SysNodeProvider.zep", 75);
			if (Z_TYPE_P(&addresses) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&addresses), _4$$7)
				{
					ZEPHIR_INIT_NVAR(&address);
					ZVAL_COPY(&address, _4$$7);
					ZEPHIR_INIT_NVAR(&_6$$8);
					ZVAL_STRING(&_6$$8, "/lo/");
					ZEPHIR_INIT_NVAR(&_7$$8);
					zephir_fast_strpos(&_7$$8, &address, &_6$$8, 0 );
					if (!ZEPHIR_IS_FALSE_IDENTICAL(&_7$$8)) {
						continue;
					}
					ZEPHIR_INIT_NVAR(&_8$$8);
					zephir_file_get_contents(&_8$$8, &address);
					ZEPHIR_INIT_NVAR(&node);
					zephir_fast_trim(&node, &_8$$8, NULL , ZEPHIR_TRIM_BOTH);
					ZEPHIR_INIT_NVAR(&_9$$8);
					ZEPHIR_INIT_NVAR(&_10$$8);
					ZVAL_STRING(&_10$$8, ":");
					ZEPHIR_INIT_NVAR(&_11$$8);
					ZVAL_STRING(&_11$$8, "");
					zephir_fast_str_replace(&_9$$8, &_10$$8, &_11$$8, &node);
					ZEPHIR_CPY_WRT(&node, &_9$$8);
					ZEPHIR_CALL_METHOD(&_12$$8, this_ptr, "isvalidnode", &_13, 282, &node);
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
				while (1) {
					ZEPHIR_CALL_METHOD(&_5$$7, &addresses, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_5$$7)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&address, &addresses, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_14$$11);
						ZVAL_STRING(&_14$$11, "/lo/");
						ZEPHIR_INIT_NVAR(&_15$$11);
						zephir_fast_strpos(&_15$$11, &address, &_14$$11, 0 );
						if (!ZEPHIR_IS_FALSE_IDENTICAL(&_15$$11)) {
							continue;
						}
						ZEPHIR_INIT_NVAR(&_16$$11);
						zephir_file_get_contents(&_16$$11, &address);
						ZEPHIR_INIT_NVAR(&node);
						zephir_fast_trim(&node, &_16$$11, NULL , ZEPHIR_TRIM_BOTH);
						ZEPHIR_INIT_NVAR(&_17$$11);
						ZEPHIR_INIT_NVAR(&_18$$11);
						ZVAL_STRING(&_18$$11, ":");
						ZEPHIR_INIT_NVAR(&_19$$11);
						ZVAL_STRING(&_19$$11, "");
						zephir_fast_str_replace(&_17$$11, &_18$$11, &_19$$11, &node);
						ZEPHIR_CPY_WRT(&node, &_17$$11);
						ZEPHIR_CALL_METHOD(&_20$$11, this_ptr, "isvalidnode", &_13, 282, &node);
						zephir_check_call_status();
						if (zephir_is_true(&_20$$11)) {
							break;
						}
						ZEPHIR_INIT_NVAR(&node);
						ZVAL_NULL(&node);
					ZEPHIR_CALL_METHOD(NULL, &addresses, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&address);
		}
	}
	_21 = Z_TYPE_P(&node) == IS_NULL;
	if (_21) {
		ZEPHIR_INIT_VAR(&_22);
		ZVAL_STRING(&_22, "Linux");
		_21 = ZEPHIR_IS_STRING_IDENTICAL(&_22, "Darwin");
	}
	if (_21) {
		ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 283);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_23$$14);
		ZVAL_STRING(&_23$$14, "ifconfig 2>&1");
		ZEPHIR_CALL_FUNCTION(NULL, "passthru", NULL, 284, &_23$$14);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&output, "ob_get_clean", NULL, 285);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_23$$14);
		ZVAL_STRING(&_23$$14, "/ether\\s+([0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2})/i");
		ZEPHIR_INIT_VAR(&_24$$14);
		ZEPHIR_INIT_VAR(&_25$$14);
		ZVAL_STRING(&_25$$14, "/ether\\s+([0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2})/i");
		zephir_preg_match(&_24$$14, &_25$$14, &output, &matches, 0, 0 , 0 );
		if (zephir_is_true(&_24$$14)) {
			zephir_array_fetch_long(&_26$$15, &matches, 1, PH_NOISY | PH_READONLY, "phalcon/Encryption/Security/Uuid/SysNodeProvider.zep", 84);
			ZEPHIR_INIT_VAR(&_27$$15);
			ZVAL_STRING(&_27$$15, ":");
			ZEPHIR_INIT_VAR(&_28$$15);
			ZVAL_STRING(&_28$$15, "");
			ZEPHIR_INIT_NVAR(&node);
			zephir_fast_str_replace(&node, &_27$$15, &_28$$15, &_26$$15);
		}
	}
	_29 = Z_TYPE_P(&node) == IS_NULL;
	if (_29) {
		ZEPHIR_INIT_VAR(&_30);
		ZVAL_STRING(&_30, "Linux");
		_29 = ZEPHIR_IS_STRING_IDENTICAL(&_30, "Windows");
	}
	if (_29) {
		ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 283);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_31$$16);
		ZVAL_STRING(&_31$$16, "ipconfig /all 2>&1");
		ZEPHIR_CALL_FUNCTION(NULL, "passthru", NULL, 284, &_31$$16);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&output, "ob_get_clean", NULL, 285);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_31$$16);
		ZVAL_STRING(&_31$$16, "/Physical Address[^:]*:\\s+([0-9a-f]{2}-[0-9a-f]{2}-[0-9a-f]{2}-[0-9a-f]{2}-[0-9a-f]{2}-[0-9a-f]{2})/i");
		ZEPHIR_INIT_VAR(&_32$$16);
		ZEPHIR_INIT_VAR(&_33$$16);
		ZVAL_STRING(&_33$$16, "/Physical Address[^:]*:\\s+([0-9a-f]{2}-[0-9a-f]{2}-[0-9a-f]{2}-[0-9a-f]{2}-[0-9a-f]{2}-[0-9a-f]{2})/i");
		zephir_preg_match(&_32$$16, &_33$$16, &output, &matches, 0, 0 , 0 );
		if (zephir_is_true(&_32$$16)) {
			ZEPHIR_INIT_VAR(&_34$$17);
			zephir_array_fetch_long(&_35$$17, &matches, 1, PH_NOISY | PH_READONLY, "phalcon/Encryption/Security/Uuid/SysNodeProvider.zep", 94);
			ZEPHIR_INIT_VAR(&_36$$17);
			ZVAL_STRING(&_36$$17, "-");
			ZEPHIR_INIT_VAR(&_37$$17);
			ZVAL_STRING(&_37$$17, "");
			zephir_fast_str_replace(&_34$$17, &_36$$17, &_37$$17, &_35$$17);
			ZEPHIR_INIT_NVAR(&node);
			zephir_fast_strtolower(&node, &_34$$17);
		}
	}
	_38 = Z_TYPE_P(&node) == IS_NULL;
	if (_38) {
		ZEPHIR_INIT_VAR(&_39);
		ZVAL_STRING(&_39, "Linux");
		_38 = ZEPHIR_IS_STRING_IDENTICAL(&_39, "BSD");
	}
	if (_38) {
		ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 283);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_40$$18);
		ZVAL_STRING(&_40$$18, "netstat -i -f link 2>&1");
		ZEPHIR_CALL_FUNCTION(NULL, "passthru", NULL, 284, &_40$$18);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&output, "ob_get_clean", NULL, 285);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_40$$18);
		ZVAL_STRING(&_40$$18, "/([0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2})/i");
		ZEPHIR_INIT_VAR(&_41$$18);
		ZEPHIR_INIT_VAR(&_42$$18);
		ZVAL_STRING(&_42$$18, "/([0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2}:[0-9a-f]{2})/i");
		zephir_preg_match(&_41$$18, &_42$$18, &output, &matches, 0, 0 , 0 );
		if (zephir_is_true(&_41$$18)) {
			zephir_array_fetch_long(&_43$$19, &matches, 1, PH_NOISY | PH_READONLY, "phalcon/Encryption/Security/Uuid/SysNodeProvider.zep", 104);
			ZEPHIR_INIT_VAR(&_44$$19);
			ZVAL_STRING(&_44$$19, ":");
			ZEPHIR_INIT_VAR(&_45$$19);
			ZVAL_STRING(&_45$$19, "");
			ZEPHIR_INIT_NVAR(&node);
			zephir_fast_str_replace(&node, &_44$$19, &_45$$19, &_43$$19);
		}
	}
	_46 = Z_TYPE_P(&node) == IS_NULL;
	if (!(_46)) {
		ZEPHIR_CALL_METHOD(&_47, this_ptr, "isvalidnode", &_13, 282, &node);
		zephir_check_call_status();
		_46 = !zephir_is_true(&_47);
	}
	if (_46) {
		ZEPHIR_INIT_VAR(&_48$$20);
		object_init_ex(&_48$$20, phalcon_encryption_security_uuid_randomnodeprovider_ce);
		if (zephir_has_constructor(&_48$$20)) {
			ZEPHIR_CALL_METHOD(NULL, &_48$$20, "__construct", NULL, 0);
			zephir_check_call_status();
		}

		ZEPHIR_CALL_METHOD(&node, &_48$$20, "getnode", NULL, 286);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("node"), &node);
	if ((zephir_function_exists_ex(ZEND_STRL("apcu_store")) == SUCCESS)) {
		zephir_read_property(&_49$$21, this_ptr, ZEND_STRL("node"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_50$$21);
		ZVAL_STRING(&_50$$21, "__phalcon_uuid_node");
		ZEPHIR_CALL_FUNCTION(NULL, "apcu_store", NULL, 118, &_50$$21, &_49$$21);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER(getThis(), "node");
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
	ZVAL_STR_COPY(&node_zv, node);
	if (zephir_fast_strlen_ev(&node_zv) != 12) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_FUNCTION(&_0, "ctype_xdigit", NULL, 287, &node_zv);
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

