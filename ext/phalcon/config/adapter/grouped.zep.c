
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"
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
 *
 * @param array              $arrayConfig
 * @param string             $defaultAdapter
 * @param ConfigFactory|null $factory        Factory used to load file
 *                                           based fragments; a default
 *                                           one is created when not
 *                                           provided
 */
PHP_METHOD(Phalcon_Config_Adapter_Grouped, __construct)
{
	zend_bool _16, _2$$4, _17$$12;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL, *_11 = NULL, *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *defaultAdapter = NULL;
	zval *arrayConfig_param = NULL, defaultAdapter_zv, *factory = NULL, factory_sub, __$null, configArray, configFactory, configInstance, configName, _0, *_1, _15, _8$$4, _9$$4, _4$$6, _7$$6, _5$$7, _10$$10, _12$$9, _14$$11, _21$$12, _22$$12, _18$$14, _20$$14, _19$$15, _23$$18, _24$$17, _25$$19;
	zval arrayConfig;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrayConfig);
	ZVAL_UNDEF(&defaultAdapter_zv);
	ZVAL_UNDEF(&factory_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&configArray);
	ZVAL_UNDEF(&configFactory);
	ZVAL_UNDEF(&configInstance);
	ZVAL_UNDEF(&configName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_21$$12);
	ZVAL_UNDEF(&_22$$12);
	ZVAL_UNDEF(&_18$$14);
	ZVAL_UNDEF(&_20$$14);
	ZVAL_UNDEF(&_19$$15);
	ZVAL_UNDEF(&_23$$18);
	ZVAL_UNDEF(&_24$$17);
	ZVAL_UNDEF(&_25$$19);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		ZEPHIR_Z_PARAM_ARRAY(arrayConfig, arrayConfig_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(defaultAdapter)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(factory, phalcon_config_configfactory_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	arrayConfig_param = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		factory = ZEND_CALL_ARG(execute_data, 3);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&arrayConfig, arrayConfig_param);
	if (!defaultAdapter) {
		defaultAdapter = zend_string_init(ZEND_STRL("php"), 0);
		zephir_memory_observe(&defaultAdapter_zv);
		ZVAL_STR(&defaultAdapter_zv, defaultAdapter);
	} else {
	zephir_memory_observe(&defaultAdapter_zv);
	ZVAL_STR_COPY(&defaultAdapter_zv, defaultAdapter);
	}
	if (!factory) {
		factory = &factory_sub;
		factory = &__$null;
	}
	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	ZEPHIR_CALL_PARENT(NULL, phalcon_config_adapter_grouped_ce, getThis(), "__construct", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&configFactory, factory);
	if (Z_TYPE_P(&configFactory) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&configFactory);
		object_init_ex(&configFactory, phalcon_config_configfactory_ce);
		ZEPHIR_CALL_METHOD(NULL, &configFactory, "__construct", NULL, 355);
		zephir_check_call_status();
	}
	zephir_is_iterable(&arrayConfig, 0, "phalcon/Config/Adapter/Grouped.zep", 135);
	if (Z_TYPE_P(&arrayConfig) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&arrayConfig), _1)
		{
			ZEPHIR_INIT_NVAR(&configName);
			ZVAL_COPY(&configName, _1);
			ZEPHIR_CPY_WRT(&configInstance, &configName);
			_2$$4 = Z_TYPE_P(&configName) == IS_OBJECT;
			if (_2$$4) {
				_2$$4 = zephir_instance_of_ev(&configName, phalcon_config_configinterface_ce);
			}
			if (_2$$4) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_3, 0, &configInstance);
				zephir_check_call_status();
				continue;
			} else if (Z_TYPE_P(&configName) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_4$$6);
				ZVAL_STRING(&_4$$6, "");
				if (ZEPHIR_IS_IDENTICAL(&_4$$6, &defaultAdapter_zv)) {
					ZEPHIR_CALL_METHOD(&_5$$7, &configFactory, "load", &_6, 356, &configName);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_3, 0, &_5$$7);
					zephir_check_call_status();
					continue;
				}
				ZEPHIR_INIT_NVAR(&_7$$6);
				zephir_create_array(&_7$$6, 2, 0);
				zephir_array_update_string(&_7$$6, SL("filePath"), &configName, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_7$$6, SL("adapter"), &defaultAdapter_zv, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&configInstance, &_7$$6);
			} else if (!(zephir_array_isset_value_string(&configInstance, SL("adapter")))) {
				zephir_array_update_string(&configInstance, SL("adapter"), &defaultAdapter_zv, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_string(&_8$$4, &configInstance, SL("adapter"), PH_NOISY | PH_READONLY, "phalcon/Config/Adapter/Grouped.zep", 122);
			ZEPHIR_INIT_NVAR(&_9$$4);
			ZVAL_STRING(&_9$$4, "array");
			if (ZEPHIR_IS_IDENTICAL(&_9$$4, &_8$$4)) {
				if (!(zephir_array_isset_value_string(&configInstance, SL("config")))) {
					ZEPHIR_INIT_NVAR(&_10$$10);
					object_init_ex(&_10$$10, phalcon_config_exceptions_groupedadapterrequiresarray_ce);
					ZEPHIR_CALL_METHOD(NULL, &_10$$10, "__construct", &_11, 357);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_10$$10, "phalcon/Config/Adapter/Grouped.zep", 124);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&configArray);
				zephir_array_fetch_string(&configArray, &configInstance, SL("config"), PH_NOISY, "phalcon/Config/Adapter/Grouped.zep", 127);
				ZEPHIR_INIT_NVAR(&configInstance);
				object_init_ex(&configInstance, phalcon_config_config_ce);
				zephir_read_property(&_12$$9, this_ptr, ZEND_STRL("insensitive"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(NULL, &configInstance, "__construct", &_13, 42, &configArray, &_12$$9);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(&_14$$11, &configFactory, "load", &_6, 356, &configInstance);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&configInstance, &_14$$11);
			}
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_3, 0, &configInstance);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &arrayConfig, "rewind", NULL, 0);
		zephir_check_call_status();
		_16 = 1;
		while (1) {
			if (_16) {
				_16 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &arrayConfig, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_15, &arrayConfig, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_15)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&configName, &arrayConfig, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CPY_WRT(&configInstance, &configName);
				_17$$12 = Z_TYPE_P(&configName) == IS_OBJECT;
				if (_17$$12) {
					_17$$12 = zephir_instance_of_ev(&configName, phalcon_config_configinterface_ce);
				}
				if (_17$$12) {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_3, 0, &configInstance);
					zephir_check_call_status();
					continue;
				} else if (Z_TYPE_P(&configName) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_18$$14);
					ZVAL_STRING(&_18$$14, "");
					if (ZEPHIR_IS_IDENTICAL(&_18$$14, &defaultAdapter_zv)) {
						ZEPHIR_CALL_METHOD(&_19$$15, &configFactory, "load", &_6, 356, &configName);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_3, 0, &_19$$15);
						zephir_check_call_status();
						continue;
					}
					ZEPHIR_INIT_NVAR(&_20$$14);
					zephir_create_array(&_20$$14, 2, 0);
					zephir_array_update_string(&_20$$14, SL("filePath"), &configName, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_20$$14, SL("adapter"), &defaultAdapter_zv, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&configInstance, &_20$$14);
				} else if (!(zephir_array_isset_value_string(&configInstance, SL("adapter")))) {
					zephir_array_update_string(&configInstance, SL("adapter"), &defaultAdapter_zv, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_string(&_21$$12, &configInstance, SL("adapter"), PH_NOISY | PH_READONLY, "phalcon/Config/Adapter/Grouped.zep", 122);
				ZEPHIR_INIT_NVAR(&_22$$12);
				ZVAL_STRING(&_22$$12, "array");
				if (ZEPHIR_IS_IDENTICAL(&_22$$12, &_21$$12)) {
					if (!(zephir_array_isset_value_string(&configInstance, SL("config")))) {
						ZEPHIR_INIT_NVAR(&_23$$18);
						object_init_ex(&_23$$18, phalcon_config_exceptions_groupedadapterrequiresarray_ce);
						ZEPHIR_CALL_METHOD(NULL, &_23$$18, "__construct", &_11, 357);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_23$$18, "phalcon/Config/Adapter/Grouped.zep", 124);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&configArray);
					zephir_array_fetch_string(&configArray, &configInstance, SL("config"), PH_NOISY, "phalcon/Config/Adapter/Grouped.zep", 127);
					ZEPHIR_INIT_NVAR(&configInstance);
					object_init_ex(&configInstance, phalcon_config_config_ce);
					zephir_read_property(&_24$$17, this_ptr, ZEND_STRL("insensitive"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(NULL, &configInstance, "__construct", &_13, 42, &configArray, &_24$$17);
					zephir_check_call_status();
				} else {
					ZEPHIR_CALL_METHOD(&_25$$19, &configFactory, "load", &_6, 356, &configInstance);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&configInstance, &_25$$19);
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_3, 0, &configInstance);
				zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&configName);
	ZEPHIR_MM_RESTORE();
}

