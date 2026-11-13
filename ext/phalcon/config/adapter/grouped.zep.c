
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
	zend_bool _14, _2$$4, _3$$4, _9$$9, _15$$12, _16$$12, _22$$17;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *defaultAdapter = NULL;
	zval *arrayConfig_param = NULL, defaultAdapter_zv, *factory = NULL, factory_sub, __$null, configArray, configFactory, configInstance, configName, _0, *_1, _13, _7$$4, _8$$4, _4$$6, _6$$6, _5$$7, _11$$9, _10$$10, _12$$11, _20$$12, _21$$12, _17$$14, _19$$14, _18$$15, _24$$17, _23$$18, _25$$19;
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
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_20$$12);
	ZVAL_UNDEF(&_21$$12);
	ZVAL_UNDEF(&_17$$14);
	ZVAL_UNDEF(&_19$$14);
	ZVAL_UNDEF(&_18$$15);
	ZVAL_UNDEF(&_24$$17);
	ZVAL_UNDEF(&_23$$18);
	ZVAL_UNDEF(&_25$$19);
	ZEND_TLS zephir_method_cache _zephir_call_cache[20];
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
	ZEPHIR_CALL_PARENT_CACHED(NULL, phalcon_config_adapter_grouped_ce, getThis(), "__construct", &_zephir_call_cache[0], &_0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&configFactory, factory);
	if (Z_TYPE_P(&configFactory) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&configFactory);
		object_init_ex(&configFactory, phalcon_config_configfactory_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &configFactory, "__construct", &_zephir_call_cache[1]);
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
				ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "merge", &_zephir_call_cache[2], &configInstance);
				zephir_check_call_status();
				continue;
			} else if (Z_TYPE_P(&configName) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_4$$6);
				ZVAL_STRING(&_4$$6, "");
				if (ZEPHIR_IS_IDENTICAL(&_4$$6, &defaultAdapter_zv)) {
					ZEPHIR_CALL_METHOD_CACHED(&_5$$7, &configFactory, "load", &_zephir_call_cache[3], &configName);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "merge", &_zephir_call_cache[4], &_5$$7);
					zephir_check_call_status();
					continue;
				}
				ZEPHIR_INIT_NVAR(&_6$$6);
				zephir_create_array(&_6$$6, 2, 0);
				zephir_array_update_string(&_6$$6, SL("filePath"), &configName, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_6$$6, SL("adapter"), &defaultAdapter_zv, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&configInstance, &_6$$6);
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
			ZEPHIR_OBS_NVAR(&_7$$4);
			zephir_array_fetch_string(&_7$$4, &configInstance, SL("adapter"), PH_NOISY, "phalcon/Config/Adapter/Grouped.zep", 124);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&_8$$4);
			ZVAL_STRING(&_8$$4, "array");
			if (ZEPHIR_IS_IDENTICAL(&_8$$4, &_7$$4)) {
				_9$$9 = zephir_array_isset_value_string(&configInstance, SL("config"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_9$$9)) {
					ZEPHIR_INIT_NVAR(&_10$$10);
					object_init_ex(&_10$$10, phalcon_config_exceptions_groupedadapterrequiresarray_ce);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_10$$10, "__construct", &_zephir_call_cache[5]);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_10$$10, "phalcon/Config/Adapter/Grouped.zep", 126);
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
				zephir_read_property_cached(&_11$$9, this_ptr, _zephir_prop_0, 537, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(NULL, &configInstance, "__construct", &_zephir_call_cache[6], &configArray, &_11$$9);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD_CACHED(&_12$$11, &configFactory, "load", &_zephir_call_cache[7], &configInstance);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&configInstance, &_12$$11);
			}
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "merge", &_zephir_call_cache[8], &configInstance);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &arrayConfig, "rewind", &_zephir_call_cache[9]);
		zephir_check_call_status();
		_14 = 1;
		while (1) {
			if (_14) {
				_14 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &arrayConfig, "next", &_zephir_call_cache[10]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_13, &arrayConfig, "valid", &_zephir_call_cache[11]);
			zephir_check_call_status();
			if (!zend_is_true(&_13)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&configName, &arrayConfig, "current", &_zephir_call_cache[12]);
			zephir_check_call_status();
				ZEPHIR_CPY_WRT(&configInstance, &configName);
				_15$$12 = Z_TYPE_P(&configName) == IS_OBJECT;
				if (_15$$12) {
					_15$$12 = zephir_instance_of_ev(&configName, phalcon_config_configinterface_ce);
				}
				if (_15$$12) {
					ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "merge", &_zephir_call_cache[13], &configInstance);
					zephir_check_call_status();
					continue;
				} else if (Z_TYPE_P(&configName) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_17$$14);
					ZVAL_STRING(&_17$$14, "");
					if (ZEPHIR_IS_IDENTICAL(&_17$$14, &defaultAdapter_zv)) {
						ZEPHIR_CALL_METHOD_CACHED(&_18$$15, &configFactory, "load", &_zephir_call_cache[14], &configName);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "merge", &_zephir_call_cache[15], &_18$$15);
						zephir_check_call_status();
						continue;
					}
					ZEPHIR_INIT_NVAR(&_19$$14);
					zephir_create_array(&_19$$14, 2, 0);
					zephir_array_update_string(&_19$$14, SL("filePath"), &configName, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_19$$14, SL("adapter"), &defaultAdapter_zv, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&configInstance, &_19$$14);
				} else {
					_16$$12 = zephir_array_isset_value_string(&configInstance, SL("adapter"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_16$$12)) {
						zephir_array_update_string(&configInstance, SL("adapter"), &defaultAdapter_zv, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				}
				ZEPHIR_OBS_NVAR(&_20$$12);
				zephir_array_fetch_string(&_20$$12, &configInstance, SL("adapter"), PH_NOISY, "phalcon/Config/Adapter/Grouped.zep", 124);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_21$$12);
				ZVAL_STRING(&_21$$12, "array");
				if (ZEPHIR_IS_IDENTICAL(&_21$$12, &_20$$12)) {
					_22$$17 = zephir_array_isset_value_string(&configInstance, SL("config"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_22$$17)) {
						ZEPHIR_INIT_NVAR(&_23$$18);
						object_init_ex(&_23$$18, phalcon_config_exceptions_groupedadapterrequiresarray_ce);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_23$$18, "__construct", &_zephir_call_cache[16]);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_23$$18, "phalcon/Config/Adapter/Grouped.zep", 126);
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
					zephir_read_property_cached(&_24$$17, this_ptr, _zephir_prop_0, 537, PH_NOISY_CC | PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(NULL, &configInstance, "__construct", &_zephir_call_cache[17], &configArray, &_24$$17);
					zephir_check_call_status();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(&_25$$19, &configFactory, "load", &_zephir_call_cache[18], &configInstance);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&configInstance, &_25$$19);
				}
				ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "merge", &_zephir_call_cache[19], &configInstance);
				zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&configName);
	ZEPHIR_MM_RESTORE();
}

