
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
	zend_bool _19, _2$$3, _20$$11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL, *_8 = NULL, *_13 = NULL, *_15 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *defaultAdapter = NULL;
	zval *arrayConfig_param = NULL, defaultAdapter_zv, configArray, configInstance, configName, _0, *_1, _18, _10$$3, _11$$3, _4$$5, _9$$5, _5$$6, _7$$6, _12$$9, _14$$8, _16$$10, _17$$10, _25$$11, _26$$11, _21$$13, _24$$13, _22$$14, _23$$14, _27$$17, _28$$16, _29$$18, _30$$18;
	zval arrayConfig;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrayConfig);
	ZVAL_UNDEF(&defaultAdapter_zv);
	ZVAL_UNDEF(&configArray);
	ZVAL_UNDEF(&configInstance);
	ZVAL_UNDEF(&configName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_25$$11);
	ZVAL_UNDEF(&_26$$11);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_24$$13);
	ZVAL_UNDEF(&_22$$14);
	ZVAL_UNDEF(&_23$$14);
	ZVAL_UNDEF(&_27$$17);
	ZVAL_UNDEF(&_28$$16);
	ZVAL_UNDEF(&_29$$18);
	ZVAL_UNDEF(&_30$$18);
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
			_2$$3 = Z_TYPE_P(&configName) == IS_OBJECT;
			if (_2$$3) {
				_2$$3 = zephir_instance_of_ev(&configName, phalcon_config_configinterface_ce);
			}
			if (_2$$3) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_3, 0, &configInstance);
				zephir_check_call_status();
				continue;
			} else if (Z_TYPE_P(&configName) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_4$$5);
				ZVAL_STRING(&_4$$5, "");
				if (ZEPHIR_IS_IDENTICAL(&_4$$5, &defaultAdapter_zv)) {
					ZEPHIR_INIT_NVAR(&_5$$6);
					object_init_ex(&_5$$6, phalcon_config_configfactory_ce);
					ZEPHIR_CALL_METHOD(NULL, &_5$$6, "__construct", &_6, 310);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_7$$6, &_5$$6, "load", &_8, 311, &configName);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_3, 0, &_7$$6);
					zephir_check_call_status();
					continue;
				}
				ZEPHIR_INIT_NVAR(&_9$$5);
				zephir_create_array(&_9$$5, 2, 0);
				zephir_array_update_string(&_9$$5, SL("filePath"), &configName, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_9$$5, SL("adapter"), &defaultAdapter_zv, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&configInstance, &_9$$5);
			} else if (!(zephir_array_isset_value_string(&configInstance, SL("adapter")))) {
				zephir_array_update_string(&configInstance, SL("adapter"), &defaultAdapter_zv, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_string(&_10$$3, &configInstance, SL("adapter"), PH_NOISY | PH_READONLY, "phalcon/Config/Adapter/Grouped.zep", 106);
			ZEPHIR_INIT_NVAR(&_11$$3);
			ZVAL_STRING(&_11$$3, "array");
			if (ZEPHIR_IS_IDENTICAL(&_11$$3, &_10$$3)) {
				if (!(zephir_array_isset_value_string(&configInstance, SL("config")))) {
					ZEPHIR_INIT_NVAR(&_12$$9);
					object_init_ex(&_12$$9, phalcon_config_exceptions_groupedadapterrequiresarray_ce);
					ZEPHIR_CALL_METHOD(NULL, &_12$$9, "__construct", &_13, 312);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_12$$9, "phalcon/Config/Adapter/Grouped.zep", 108);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&configArray);
				zephir_array_fetch_string(&configArray, &configInstance, SL("config"), PH_NOISY, "phalcon/Config/Adapter/Grouped.zep", 111);
				ZEPHIR_INIT_NVAR(&configInstance);
				object_init_ex(&configInstance, phalcon_config_config_ce);
				zephir_read_property(&_14$$8, this_ptr, ZEND_STRL("insensitive"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(NULL, &configInstance, "__construct", &_15, 41, &configArray, &_14$$8);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(&_16$$10);
				object_init_ex(&_16$$10, phalcon_config_configfactory_ce);
				ZEPHIR_CALL_METHOD(NULL, &_16$$10, "__construct", &_6, 310);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_17$$10, &_16$$10, "load", &_8, 311, &configInstance);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&configInstance, &_17$$10);
			}
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_3, 0, &configInstance);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &arrayConfig, "rewind", NULL, 0);
		zephir_check_call_status();
		_19 = 1;
		while (1) {
			if (_19) {
				_19 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &arrayConfig, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_18, &arrayConfig, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_18)) {
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
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_3, 0, &configInstance);
					zephir_check_call_status();
					continue;
				} else if (Z_TYPE_P(&configName) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_21$$13);
					ZVAL_STRING(&_21$$13, "");
					if (ZEPHIR_IS_IDENTICAL(&_21$$13, &defaultAdapter_zv)) {
						ZEPHIR_INIT_NVAR(&_22$$14);
						object_init_ex(&_22$$14, phalcon_config_configfactory_ce);
						ZEPHIR_CALL_METHOD(NULL, &_22$$14, "__construct", &_6, 310);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_23$$14, &_22$$14, "load", &_8, 311, &configName);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_3, 0, &_23$$14);
						zephir_check_call_status();
						continue;
					}
					ZEPHIR_INIT_NVAR(&_24$$13);
					zephir_create_array(&_24$$13, 2, 0);
					zephir_array_update_string(&_24$$13, SL("filePath"), &configName, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_24$$13, SL("adapter"), &defaultAdapter_zv, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&configInstance, &_24$$13);
				} else if (!(zephir_array_isset_value_string(&configInstance, SL("adapter")))) {
					zephir_array_update_string(&configInstance, SL("adapter"), &defaultAdapter_zv, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_string(&_25$$11, &configInstance, SL("adapter"), PH_NOISY | PH_READONLY, "phalcon/Config/Adapter/Grouped.zep", 106);
				ZEPHIR_INIT_NVAR(&_26$$11);
				ZVAL_STRING(&_26$$11, "array");
				if (ZEPHIR_IS_IDENTICAL(&_26$$11, &_25$$11)) {
					if (!(zephir_array_isset_value_string(&configInstance, SL("config")))) {
						ZEPHIR_INIT_NVAR(&_27$$17);
						object_init_ex(&_27$$17, phalcon_config_exceptions_groupedadapterrequiresarray_ce);
						ZEPHIR_CALL_METHOD(NULL, &_27$$17, "__construct", &_13, 312);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_27$$17, "phalcon/Config/Adapter/Grouped.zep", 108);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&configArray);
					zephir_array_fetch_string(&configArray, &configInstance, SL("config"), PH_NOISY, "phalcon/Config/Adapter/Grouped.zep", 111);
					ZEPHIR_INIT_NVAR(&configInstance);
					object_init_ex(&configInstance, phalcon_config_config_ce);
					zephir_read_property(&_28$$16, this_ptr, ZEND_STRL("insensitive"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(NULL, &configInstance, "__construct", &_15, 41, &configArray, &_28$$16);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&_29$$18);
					object_init_ex(&_29$$18, phalcon_config_configfactory_ce);
					ZEPHIR_CALL_METHOD(NULL, &_29$$18, "__construct", &_6, 310);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_30$$18, &_29$$18, "load", &_8, 311, &configInstance);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&configInstance, &_30$$18);
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_3, 0, &configInstance);
				zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&configName);
	ZEPHIR_MM_RESTORE();
}

