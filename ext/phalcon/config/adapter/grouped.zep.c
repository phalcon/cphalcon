
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
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
 *
 * @phpstan-import-type config_grouped_entries from ConfigTypes
 * @phpstan-import-type config_options from ConfigTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Config_Adapter_Grouped)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Config\\Adapter, Grouped, phalcon, config_adapter_grouped, phalcon_config_config_ce, phalcon_config_adapter_grouped_method_entry, 0);

	return SUCCESS;
}

/**
 * Grouped constructor.
 *
 * @phpstan-param config_grouped_entries $arrayConfig
 *
 * @param ConfigFactory|null $factory Factory used to load file
 *                                    based fragments; a default
 *                                    one is created when not
 *                                    provided
 */
PHP_METHOD(Phalcon_Config_Adapter_Grouped, __construct)
{
	zend_bool _18, _2$$4, _3$$4, _11$$9, _19$$12, _20$$12, _26$$17;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL, *_13 = NULL, *_15 = NULL, *_28 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *defaultAdapter = NULL;
	zval *arrayConfig_param = NULL, defaultAdapter_zv, *factory = NULL, factory_sub, __$null, configArray, configFactory, configInstance, configName, _0, *_1, _17, _9$$4, _10$$4, _5$$6, _8$$6, _6$$7, _14$$9, _12$$10, _16$$11, _24$$12, _25$$12, _21$$14, _23$$14, _22$$15, _29$$17, _27$$18, _30$$19;
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
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_24$$12);
	ZVAL_UNDEF(&_25$$12);
	ZVAL_UNDEF(&_21$$14);
	ZVAL_UNDEF(&_23$$14);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_29$$17);
	ZVAL_UNDEF(&_27$$18);
	ZVAL_UNDEF(&_30$$19);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("insensitive", 11, 1);
	}

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
	zephir_get_arrval(&arrayConfig, arrayConfig_param);
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
		ZEPHIR_CALL_METHOD(NULL, &configFactory, "__construct", NULL, 463);
		zephir_check_call_status();
	}
	zephir_is_iterable(&arrayConfig, 0, "phalcon/Config/Adapter/Grouped.zep", 137);
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
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_4, 0, &configInstance);
				zephir_check_call_status();
				continue;
			} else if (Z_TYPE_P(&configName) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_5$$6);
				ZVAL_STRING(&_5$$6, "");
				if (ZEPHIR_IS_IDENTICAL(&_5$$6, &defaultAdapter_zv)) {
					ZEPHIR_CALL_METHOD(&_6$$7, &configFactory, "load", &_7, 464, &configName);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_4, 0, &_6$$7);
					zephir_check_call_status();
					continue;
				}
				ZEPHIR_INIT_NVAR(&_8$$6);
				zephir_create_array(&_8$$6, 2, 0);
				zephir_array_update_string(&_8$$6, SL("filePath"), &configName, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_8$$6, SL("adapter"), &defaultAdapter_zv, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&configInstance, &_8$$6);
			} else {
				_3$$4 = zephir_array_isset_value_string(&configInstance, SL("adapter"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_3$$4)) {
					zephir_array_update_string(&configInstance, SL("adapter"), &defaultAdapter_zv, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
			ZEPHIR_OBS_NVAR(&_9$$4);
			zephir_array_fetch_string(&_9$$4, &configInstance, SL("adapter"), PH_NOISY, "phalcon/Config/Adapter/Grouped.zep", 124);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&_10$$4);
			ZVAL_STRING(&_10$$4, "array");
			if (ZEPHIR_IS_IDENTICAL(&_10$$4, &_9$$4)) {
				_11$$9 = zephir_array_isset_value_string(&configInstance, SL("config"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_11$$9)) {
					ZEPHIR_INIT_NVAR(&_12$$10);
					object_init_ex(&_12$$10, phalcon_config_exceptions_groupedadapterrequiresarray_ce);
					ZEPHIR_CALL_METHOD(NULL, &_12$$10, "__construct", &_13, 465);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_12$$10, "phalcon/Config/Adapter/Grouped.zep", 126);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&configArray);
				zephir_array_fetch_string(&configArray, &configInstance, SL("config"), PH_NOISY, "phalcon/Config/Adapter/Grouped.zep", 129);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&configInstance);
				object_init_ex(&configInstance, phalcon_config_config_ce);
				zephir_read_property_cached(&_14$$9, this_ptr, _zephir_prop_0, 537, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(NULL, &configInstance, "__construct", &_15, 40, &configArray, &_14$$9);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(&_16$$11, &configFactory, "load", &_7, 464, &configInstance);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&configInstance, &_16$$11);
			}
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_4, 0, &configInstance);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &arrayConfig, "rewind", NULL, 0);
		zephir_check_call_status();
		_18 = 1;
		while (1) {
			if (_18) {
				_18 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &arrayConfig, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_17, &arrayConfig, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_17)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&configName, &arrayConfig, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CPY_WRT(&configInstance, &configName);
				_19$$12 = Z_TYPE_P(&configName) == IS_OBJECT;
				if (_19$$12) {
					_19$$12 = zephir_instance_of_ev(&configName, phalcon_config_configinterface_ce);
				}
				if (_19$$12) {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_4, 0, &configInstance);
					zephir_check_call_status();
					continue;
				} else if (Z_TYPE_P(&configName) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_21$$14);
					ZVAL_STRING(&_21$$14, "");
					if (ZEPHIR_IS_IDENTICAL(&_21$$14, &defaultAdapter_zv)) {
						ZEPHIR_CALL_METHOD(&_22$$15, &configFactory, "load", &_7, 464, &configName);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_4, 0, &_22$$15);
						zephir_check_call_status();
						continue;
					}
					ZEPHIR_INIT_NVAR(&_23$$14);
					zephir_create_array(&_23$$14, 2, 0);
					zephir_array_update_string(&_23$$14, SL("filePath"), &configName, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_23$$14, SL("adapter"), &defaultAdapter_zv, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&configInstance, &_23$$14);
				} else {
					_20$$12 = zephir_array_isset_value_string(&configInstance, SL("adapter"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_20$$12)) {
						zephir_array_update_string(&configInstance, SL("adapter"), &defaultAdapter_zv, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				}
				ZEPHIR_OBS_NVAR(&_24$$12);
				zephir_array_fetch_string(&_24$$12, &configInstance, SL("adapter"), PH_NOISY, "phalcon/Config/Adapter/Grouped.zep", 124);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_25$$12);
				ZVAL_STRING(&_25$$12, "array");
				if (ZEPHIR_IS_IDENTICAL(&_25$$12, &_24$$12)) {
					_26$$17 = zephir_array_isset_value_string(&configInstance, SL("config"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_26$$17)) {
						ZEPHIR_INIT_NVAR(&_27$$18);
						object_init_ex(&_27$$18, phalcon_config_exceptions_groupedadapterrequiresarray_ce);
						ZEPHIR_CALL_METHOD(NULL, &_27$$18, "__construct", &_28, 465);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_27$$18, "phalcon/Config/Adapter/Grouped.zep", 126);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&configArray);
					zephir_array_fetch_string(&configArray, &configInstance, SL("config"), PH_NOISY, "phalcon/Config/Adapter/Grouped.zep", 129);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&configInstance);
					object_init_ex(&configInstance, phalcon_config_config_ce);
					zephir_read_property_cached(&_29$$17, this_ptr, _zephir_prop_0, 537, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(NULL, &configInstance, "__construct", &_15, 40, &configArray, &_29$$17);
					zephir_check_call_status();
				} else {
					ZEPHIR_CALL_METHOD(&_30$$19, &configFactory, "load", &_7, 464, &configInstance);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&configInstance, &_30$$19);
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_4, 0, &configInstance);
				zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&configName);
	ZEPHIR_MM_RESTORE();
}

