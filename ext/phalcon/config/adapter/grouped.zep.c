
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
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
	zend_bool _3$$3, _19$$11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL, *_9 = NULL, *_14 = NULL, *_16 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *defaultAdapter = NULL;
	zval *arrayConfig_param = NULL, defaultAdapter_zv, configArray, configInstance, configName, _0, *_1, _2, _11$$3, _12$$3, _5$$5, _10$$5, _6$$6, _8$$6, _13$$9, _15$$8, _17$$10, _18$$10, _24$$11, _25$$11, _20$$13, _23$$13, _21$$14, _22$$14, _26$$17, _27$$16, _28$$18, _29$$18;
	zval arrayConfig;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrayConfig);
	ZVAL_UNDEF(&defaultAdapter_zv);
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
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_24$$11);
	ZVAL_UNDEF(&_25$$11);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_23$$13);
	ZVAL_UNDEF(&_21$$14);
	ZVAL_UNDEF(&_22$$14);
	ZVAL_UNDEF(&_26$$17);
	ZVAL_UNDEF(&_27$$16);
	ZVAL_UNDEF(&_28$$18);
	ZVAL_UNDEF(&_29$$18);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(arrayConfig, arrayConfig_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(defaultAdapter)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	arrayConfig_param = ZEND_CALL_ARG(execute_data, 1);
	ZEPHIR_OBS_COPY_OR_DUP(&arrayConfig, arrayConfig_param);
	if (!defaultAdapter) {
		defaultAdapter = zend_string_init(ZEND_STRL("php"), 0);
		zephir_memory_observe(&defaultAdapter_zv);
		ZVAL_STR(&defaultAdapter_zv, defaultAdapter);
	} else {
	zephir_memory_observe(&defaultAdapter_zv);
	ZVAL_STR_COPY(&defaultAdapter_zv, defaultAdapter);
	}
	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	ZEPHIR_CALL_PARENT(NULL, phalcon_config_adapter_grouped_ce, getThis(), "__construct", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_is_iterable(&arrayConfig, 0, "phalcon/Config/Adapter/Grouped.zep", 119);
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
				if (ZEPHIR_IS_IDENTICAL(&_5$$5, &defaultAdapter_zv)) {
					ZEPHIR_INIT_NVAR(&_6$$6);
					object_init_ex(&_6$$6, phalcon_config_configfactory_ce);
					ZEPHIR_CALL_METHOD(NULL, &_6$$6, "__construct", &_7, 304);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_8$$6, &_6$$6, "load", &_9, 305, &configName);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_4, 0, &_8$$6);
					zephir_check_call_status();
					continue;
				}
				ZEPHIR_INIT_NVAR(&_10$$5);
				zephir_create_array(&_10$$5, 2, 0);
				zephir_array_update_string(&_10$$5, SL("filePath"), &configName, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_10$$5, SL("adapter"), &defaultAdapter_zv, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&configInstance, &_10$$5);
			} else if (!(zephir_array_isset_value_string(&configInstance, SL("adapter")))) {
				zephir_array_update_string(&configInstance, SL("adapter"), &defaultAdapter_zv, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_string(&_11$$3, &configInstance, SL("adapter"), PH_NOISY | PH_READONLY, "phalcon/Config/Adapter/Grouped.zep", 106);
			ZEPHIR_INIT_NVAR(&_12$$3);
			ZVAL_STRING(&_12$$3, "array");
			if (ZEPHIR_IS_IDENTICAL(&_12$$3, &_11$$3)) {
				if (!(zephir_array_isset_value_string(&configInstance, SL("config")))) {
					ZEPHIR_INIT_NVAR(&_13$$9);
					object_init_ex(&_13$$9, phalcon_config_exceptions_groupedadapterrequiresarray_ce);
					ZEPHIR_CALL_METHOD(NULL, &_13$$9, "__construct", &_14, 306);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_13$$9, "phalcon/Config/Adapter/Grouped.zep", 108);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&configArray);
				zephir_array_fetch_string(&configArray, &configInstance, SL("config"), PH_NOISY, "phalcon/Config/Adapter/Grouped.zep", 111);
				ZEPHIR_INIT_NVAR(&configInstance);
				object_init_ex(&configInstance, phalcon_config_config_ce);
				zephir_read_property(&_15$$8, this_ptr, ZEND_STRL("insensitive"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(NULL, &configInstance, "__construct", &_16, 41, &configArray, &_15$$8);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(&_17$$10);
				object_init_ex(&_17$$10, phalcon_config_configfactory_ce);
				ZEPHIR_CALL_METHOD(NULL, &_17$$10, "__construct", &_7, 304);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_18$$10, &_17$$10, "load", &_9, 305, &configInstance);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&configInstance, &_18$$10);
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
				_19$$11 = Z_TYPE_P(&configName) == IS_OBJECT;
				if (_19$$11) {
					_19$$11 = zephir_instance_of_ev(&configName, phalcon_config_configinterface_ce);
				}
				if (_19$$11) {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_4, 0, &configInstance);
					zephir_check_call_status();
					continue;
				} else if (Z_TYPE_P(&configName) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_20$$13);
					ZVAL_STRING(&_20$$13, "");
					if (ZEPHIR_IS_IDENTICAL(&_20$$13, &defaultAdapter_zv)) {
						ZEPHIR_INIT_NVAR(&_21$$14);
						object_init_ex(&_21$$14, phalcon_config_configfactory_ce);
						ZEPHIR_CALL_METHOD(NULL, &_21$$14, "__construct", &_7, 304);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_22$$14, &_21$$14, "load", &_9, 305, &configName);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_4, 0, &_22$$14);
						zephir_check_call_status();
						continue;
					}
					ZEPHIR_INIT_NVAR(&_23$$13);
					zephir_create_array(&_23$$13, 2, 0);
					zephir_array_update_string(&_23$$13, SL("filePath"), &configName, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_23$$13, SL("adapter"), &defaultAdapter_zv, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&configInstance, &_23$$13);
				} else if (!(zephir_array_isset_value_string(&configInstance, SL("adapter")))) {
					zephir_array_update_string(&configInstance, SL("adapter"), &defaultAdapter_zv, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_string(&_24$$11, &configInstance, SL("adapter"), PH_NOISY | PH_READONLY, "phalcon/Config/Adapter/Grouped.zep", 106);
				ZEPHIR_INIT_NVAR(&_25$$11);
				ZVAL_STRING(&_25$$11, "array");
				if (ZEPHIR_IS_IDENTICAL(&_25$$11, &_24$$11)) {
					if (!(zephir_array_isset_value_string(&configInstance, SL("config")))) {
						ZEPHIR_INIT_NVAR(&_26$$17);
						object_init_ex(&_26$$17, phalcon_config_exceptions_groupedadapterrequiresarray_ce);
						ZEPHIR_CALL_METHOD(NULL, &_26$$17, "__construct", &_14, 306);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_26$$17, "phalcon/Config/Adapter/Grouped.zep", 108);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&configArray);
					zephir_array_fetch_string(&configArray, &configInstance, SL("config"), PH_NOISY, "phalcon/Config/Adapter/Grouped.zep", 111);
					ZEPHIR_INIT_NVAR(&configInstance);
					object_init_ex(&configInstance, phalcon_config_config_ce);
					zephir_read_property(&_27$$16, this_ptr, ZEND_STRL("insensitive"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(NULL, &configInstance, "__construct", &_16, 41, &configArray, &_27$$16);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&_28$$18);
					object_init_ex(&_28$$18, phalcon_config_configfactory_ce);
					ZEPHIR_CALL_METHOD(NULL, &_28$$18, "__construct", &_7, 304);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_29$$18, &_28$$18, "load", &_9, 305, &configInstance);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&configInstance, &_29$$18);
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

