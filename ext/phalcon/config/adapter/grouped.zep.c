
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Reads multiple files (or arrays) and merges them all together.
 *
 * See `Phalcon\Config\ConfigFactory::load` To load Config Adapter class using 'adapter' option.
 *
 * ```php
 * use Phalcon\Config\Adapter\Grouped;
 *
 * $config = new Grouped(
 *     [
 *         "path/to/config.php",
 *         "path/to/config.dist.php",
 *     ]
 * );
 * ```
 *
 * ```php
 * use Phalcon\Config\Adapter\Grouped;
 *
 * $config = new Grouped(
 *     [
 *         "path/to/config.json",
 *         "path/to/config.dist.json",
 *     ],
 *     "json"
 * );
 * ```
 *
 * ```php
 * use Phalcon\Config\Adapter\Grouped;
 *
 * $config = new Grouped(
 *     [
 *         [
 *             "filePath" => "path/to/config.php",
 *             "adapter"  => "php",
 *         ],
 *         [
 *             "filePath" => "path/to/config.json",
 *             "adapter"  => "json",
 *         ],
 *         [
 *             "adapter"  => "array",
 *             "config"   => [
 *                 "property" => "value",
 *             ],
 *         ],
 *     ],
 * );
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Config_Adapter_Grouped)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Config\\Adapter, Grouped, phalcon, config_adapter_grouped, phalcon_config_config_ce, phalcon_config_adapter_grouped_method_entry, 0);

	return SUCCESS;
}

/**
 * Phalcon\Config\Adapter\Grouped constructor
 */
PHP_METHOD(Phalcon_Config_Adapter_Grouped, __construct)
{
	zend_bool _3$$3, _20$$11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL, *_9 = NULL, *_15 = NULL, *_17 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval defaultAdapter, _14$$9, _28$$17;
	zval *arrayConfig_param = NULL, *defaultAdapter_param = NULL, configArray, configInstance, configName, _0, *_1, _2, _11$$3, _12$$3, _5$$5, _10$$5, _6$$6, _8$$6, _13$$9, _16$$8, _18$$10, _19$$10, _25$$11, _26$$11, _21$$13, _24$$13, _22$$14, _23$$14, _27$$17, _29$$16, _30$$18, _31$$18;
	zval arrayConfig;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrayConfig);
	ZVAL_UNDEF(&configArray);
	ZVAL_UNDEF(&configInstance);
	ZVAL_UNDEF(&configName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_25$$11);
	ZVAL_UNDEF(&_26$$11);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_24$$13);
	ZVAL_UNDEF(&_22$$14);
	ZVAL_UNDEF(&_23$$14);
	ZVAL_UNDEF(&_27$$17);
	ZVAL_UNDEF(&_29$$16);
	ZVAL_UNDEF(&_30$$18);
	ZVAL_UNDEF(&_31$$18);
	ZVAL_UNDEF(&defaultAdapter);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_28$$17);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(arrayConfig)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(defaultAdapter)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &arrayConfig_param, &defaultAdapter_param);
	ZEPHIR_OBS_COPY_OR_DUP(&arrayConfig, arrayConfig_param);
	if (!defaultAdapter_param) {
		ZEPHIR_INIT_VAR(&defaultAdapter);
		ZVAL_STRING(&defaultAdapter, "php");
	} else {
	if (UNEXPECTED(Z_TYPE_P(defaultAdapter_param) != IS_STRING && Z_TYPE_P(defaultAdapter_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'defaultAdapter' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(defaultAdapter_param) == IS_STRING)) {
		zephir_get_strval(&defaultAdapter, defaultAdapter_param);
	} else {
		ZEPHIR_INIT_VAR(&defaultAdapter);
	}
	}
	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	ZEPHIR_CALL_PARENT(NULL, phalcon_config_adapter_grouped_ce, getThis(), "__construct", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_is_iterable(&arrayConfig, 0, "phalcon/Config/Adapter/Grouped.zep", 121);
	if (Z_TYPE_P(&arrayConfig) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&arrayConfig), _1)
		{
			ZEPHIR_INIT_NVAR(&configName);
			ZVAL_COPY(&configName, _1);
			ZEPHIR_CPY_WRT(&configInstance, &configName);
			_3$$3 = Z_TYPE_P(&configName) == IS_OBJECT;
			if (_3$$3) {
				_3$$3 = zephir_instance_of_ev(&configName, phalcon_config_configinterface_ce);
			}
			if (_3$$3) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_4, 0, &configInstance);
				zephir_check_call_status();
				continue;
			} else if (Z_TYPE_P(&configName) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_5$$5);
				ZVAL_STRING(&_5$$5, "");
				if (ZEPHIR_IS_IDENTICAL(&_5$$5, &defaultAdapter)) {
					ZEPHIR_INIT_NVAR(&_6$$6);
					object_init_ex(&_6$$6, phalcon_config_configfactory_ce);
					ZEPHIR_CALL_METHOD(NULL, &_6$$6, "__construct", &_7, 193);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_8$$6, &_6$$6, "load", &_9, 194, &configName);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_4, 0, &_8$$6);
					zephir_check_call_status();
					continue;
				}
				ZEPHIR_INIT_NVAR(&_10$$5);
				zephir_create_array(&_10$$5, 2, 0);
				zephir_array_update_string(&_10$$5, SL("filePath"), &configName, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_10$$5, SL("adapter"), &defaultAdapter, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&configInstance, &_10$$5);
			} else if (!(zephir_array_isset_string(&configInstance, SL("adapter")))) {
				zephir_array_update_string(&configInstance, SL("adapter"), &defaultAdapter, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_string(&_11$$3, &configInstance, SL("adapter"), PH_NOISY | PH_READONLY, "phalcon/Config/Adapter/Grouped.zep", 105);
			ZEPHIR_INIT_NVAR(&_12$$3);
			ZVAL_STRING(&_12$$3, "array");
			if (ZEPHIR_IS_IDENTICAL(&_12$$3, &_11$$3)) {
				if (!(zephir_array_isset_string(&configInstance, SL("config")))) {
					ZEPHIR_INIT_NVAR(&_13$$9);
					object_init_ex(&_13$$9, phalcon_config_exception_ce);
					ZEPHIR_INIT_NVAR(&_14$$9);
					ZEPHIR_CONCAT_SS(&_14$$9, "To use 'array' adapter you have to specify ", "the 'config' as an array.");
					ZEPHIR_CALL_METHOD(NULL, &_13$$9, "__construct", &_15, 33, &_14$$9);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_13$$9, "phalcon/Config/Adapter/Grouped.zep", 110);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&configArray);
				zephir_array_fetch_string(&configArray, &configInstance, SL("config"), PH_NOISY, "phalcon/Config/Adapter/Grouped.zep", 113);
				ZEPHIR_INIT_NVAR(&configInstance);
				object_init_ex(&configInstance, phalcon_config_config_ce);
				zephir_read_property(&_16$$8, this_ptr, ZEND_STRL("insensitive"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(NULL, &configInstance, "__construct", &_17, 23, &configArray, &_16$$8);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(&_18$$10);
				object_init_ex(&_18$$10, phalcon_config_configfactory_ce);
				ZEPHIR_CALL_METHOD(NULL, &_18$$10, "__construct", &_7, 193);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_19$$10, &_18$$10, "load", &_9, 194, &configInstance);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&configInstance, &_19$$10);
			}
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_4, 0, &configInstance);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &arrayConfig, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &arrayConfig, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&configName, &arrayConfig, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CPY_WRT(&configInstance, &configName);
				_20$$11 = Z_TYPE_P(&configName) == IS_OBJECT;
				if (_20$$11) {
					_20$$11 = zephir_instance_of_ev(&configName, phalcon_config_configinterface_ce);
				}
				if (_20$$11) {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_4, 0, &configInstance);
					zephir_check_call_status();
					continue;
				} else if (Z_TYPE_P(&configName) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_21$$13);
					ZVAL_STRING(&_21$$13, "");
					if (ZEPHIR_IS_IDENTICAL(&_21$$13, &defaultAdapter)) {
						ZEPHIR_INIT_NVAR(&_22$$14);
						object_init_ex(&_22$$14, phalcon_config_configfactory_ce);
						ZEPHIR_CALL_METHOD(NULL, &_22$$14, "__construct", &_7, 193);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_23$$14, &_22$$14, "load", &_9, 194, &configName);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_4, 0, &_23$$14);
						zephir_check_call_status();
						continue;
					}
					ZEPHIR_INIT_NVAR(&_24$$13);
					zephir_create_array(&_24$$13, 2, 0);
					zephir_array_update_string(&_24$$13, SL("filePath"), &configName, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_24$$13, SL("adapter"), &defaultAdapter, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&configInstance, &_24$$13);
				} else if (!(zephir_array_isset_string(&configInstance, SL("adapter")))) {
					zephir_array_update_string(&configInstance, SL("adapter"), &defaultAdapter, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_string(&_25$$11, &configInstance, SL("adapter"), PH_NOISY | PH_READONLY, "phalcon/Config/Adapter/Grouped.zep", 105);
				ZEPHIR_INIT_NVAR(&_26$$11);
				ZVAL_STRING(&_26$$11, "array");
				if (ZEPHIR_IS_IDENTICAL(&_26$$11, &_25$$11)) {
					if (!(zephir_array_isset_string(&configInstance, SL("config")))) {
						ZEPHIR_INIT_NVAR(&_27$$17);
						object_init_ex(&_27$$17, phalcon_config_exception_ce);
						ZEPHIR_INIT_NVAR(&_28$$17);
						ZEPHIR_CONCAT_SS(&_28$$17, "To use 'array' adapter you have to specify ", "the 'config' as an array.");
						ZEPHIR_CALL_METHOD(NULL, &_27$$17, "__construct", &_15, 33, &_28$$17);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_27$$17, "phalcon/Config/Adapter/Grouped.zep", 110);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&configArray);
					zephir_array_fetch_string(&configArray, &configInstance, SL("config"), PH_NOISY, "phalcon/Config/Adapter/Grouped.zep", 113);
					ZEPHIR_INIT_NVAR(&configInstance);
					object_init_ex(&configInstance, phalcon_config_config_ce);
					zephir_read_property(&_29$$16, this_ptr, ZEND_STRL("insensitive"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(NULL, &configInstance, "__construct", &_17, 23, &configArray, &_29$$16);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&_30$$18);
					object_init_ex(&_30$$18, phalcon_config_configfactory_ce);
					ZEPHIR_CALL_METHOD(NULL, &_30$$18, "__construct", &_7, 193);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_31$$18, &_30$$18, "load", &_9, 194, &configInstance);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&configInstance, &_31$$18);
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_4, 0, &configInstance);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &arrayConfig, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&configName);
	ZEPHIR_MM_RESTORE();
}

