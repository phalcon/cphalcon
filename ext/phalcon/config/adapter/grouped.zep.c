
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
	zend_bool _16, _3$$4, _4$$4, _10$$9, _17$$12, _18$$12, _24$$17;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *defaultAdapter = NULL;
	zval *arrayConfig_param = NULL, defaultAdapter_zv, *factory = NULL, factory_sub, __$null, configArray, configFactory, configInstance, configName, _0, *_2, _15, _1$$3, _8$$4, _9$$4, _5$$6, _7$$6, _6$$7, _12$$9, _13$$9, _11$$10, _14$$11, _22$$12, _23$$12, _19$$14, _21$$14, _20$$15, _26$$17, _27$$17, _25$$18, _28$$19;
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
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_22$$12);
	ZVAL_UNDEF(&_23$$12);
	ZVAL_UNDEF(&_19$$14);
	ZVAL_UNDEF(&_21$$14);
	ZVAL_UNDEF(&_20$$15);
	ZVAL_UNDEF(&_26$$17);
	ZVAL_UNDEF(&_27$$17);
	ZVAL_UNDEF(&_25$$18);
	ZVAL_UNDEF(&_28$$19);
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
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_config_configfactory_ce);
		zephir_constructor_start(&_1$$3);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[1]);
		zephir_check_call_status();
		zephir_constructor_finish(&_1$$3);
		ZEPHIR_CPY_WRT(&configFactory, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
	}
	zephir_is_iterable(&arrayConfig, 0, "phalcon/Config/Adapter/Grouped.zep", 137);
	if (Z_TYPE_P(&arrayConfig) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&arrayConfig), _2)
		{
			ZEPHIR_INIT_NVAR(&configName);
			ZVAL_COPY(&configName, _2);
			ZEPHIR_CPY_WRT(&configInstance, &configName);
			_3$$4 = Z_TYPE_P(&configName) == IS_OBJECT;
			if (_3$$4) {
				_3$$4 = zephir_instance_of_ev(&configName, phalcon_config_configinterface_ce);
			}
			if (_3$$4) {
				ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "merge", &_zephir_call_cache[2], &configInstance);
				zephir_check_call_status();
				continue;
			} else if (Z_TYPE_P(&configName) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_5$$6);
				ZVAL_STRING(&_5$$6, "");
				if (ZEPHIR_IS_IDENTICAL(&_5$$6, &defaultAdapter_zv)) {
					ZEPHIR_CALL_METHOD_CACHED(&_6$$7, &configFactory, "load", &_zephir_call_cache[3], &configName);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "merge", &_zephir_call_cache[4], &_6$$7);
					zephir_check_call_status();
					continue;
				}
				ZEPHIR_INIT_NVAR(&_7$$6);
				zephir_create_array(&_7$$6, 2, 0);
				zephir_array_update_string(&_7$$6, SL("filePath"), &configName, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_7$$6, SL("adapter"), &defaultAdapter_zv, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&configInstance, &_7$$6);
			} else {
				_4$$4 = zephir_array_isset_value_string(&configInstance, SL("adapter"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_4$$4)) {
					zephir_array_update_string(&configInstance, SL("adapter"), &defaultAdapter_zv, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
			ZEPHIR_OBS_NVAR(&_8$$4);
			zephir_array_fetch_string(&_8$$4, &configInstance, SL("adapter"), PH_NOISY, "phalcon/Config/Adapter/Grouped.zep", 124);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&_9$$4);
			ZVAL_STRING(&_9$$4, "array");
			if (ZEPHIR_IS_IDENTICAL(&_9$$4, &_8$$4)) {
				_10$$9 = zephir_array_isset_value_string(&configInstance, SL("config"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_10$$9)) {
					ZEPHIR_INIT_NVAR(&_11$$10);
					object_init_ex(&_11$$10, phalcon_config_exceptions_groupedadapterrequiresarray_ce);
					zephir_constructor_start(&_11$$10);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_11$$10, "__construct", &_zephir_call_cache[5]);
					zephir_check_call_status();
					zephir_constructor_finish(&_11$$10);
					zephir_throw_exception_debug(&_11$$10, "phalcon/Config/Adapter/Grouped.zep", 126);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&configArray);
				zephir_array_fetch_string(&configArray, &configInstance, SL("config"), PH_NOISY, "phalcon/Config/Adapter/Grouped.zep", 129);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_12$$9);
				object_init_ex(&_12$$9, phalcon_config_config_ce);
				zephir_constructor_start(&_12$$9);
				zephir_read_property_cached(&_13$$9, this_ptr, _zephir_prop_0, 537, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_12$$9, "__construct", &_zephir_call_cache[6], &configArray, &_13$$9);
				zephir_check_call_status();
				zephir_constructor_finish(&_12$$9);
				ZEPHIR_CPY_WRT(&configInstance, &_12$$9);
				ZEPHIR_INIT_NVAR(&_12$$9);
			} else {
				ZEPHIR_CALL_METHOD_CACHED(&_14$$11, &configFactory, "load", &_zephir_call_cache[7], &configInstance);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&configInstance, &_14$$11);
			}
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "merge", &_zephir_call_cache[8], &configInstance);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &arrayConfig, "rewind", &_zephir_call_cache[9]);
		zephir_check_call_status();
		_16 = 1;
		while (1) {
			if (_16) {
				_16 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &arrayConfig, "next", &_zephir_call_cache[10]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_15, &arrayConfig, "valid", &_zephir_call_cache[11]);
			zephir_check_call_status();
			if (!zend_is_true(&_15)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&configName, &arrayConfig, "current", &_zephir_call_cache[12]);
			zephir_check_call_status();
				ZEPHIR_CPY_WRT(&configInstance, &configName);
				_17$$12 = Z_TYPE_P(&configName) == IS_OBJECT;
				if (_17$$12) {
					_17$$12 = zephir_instance_of_ev(&configName, phalcon_config_configinterface_ce);
				}
				if (_17$$12) {
					ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "merge", &_zephir_call_cache[13], &configInstance);
					zephir_check_call_status();
					continue;
				} else if (Z_TYPE_P(&configName) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_19$$14);
					ZVAL_STRING(&_19$$14, "");
					if (ZEPHIR_IS_IDENTICAL(&_19$$14, &defaultAdapter_zv)) {
						ZEPHIR_CALL_METHOD_CACHED(&_20$$15, &configFactory, "load", &_zephir_call_cache[14], &configName);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "merge", &_zephir_call_cache[15], &_20$$15);
						zephir_check_call_status();
						continue;
					}
					ZEPHIR_INIT_NVAR(&_21$$14);
					zephir_create_array(&_21$$14, 2, 0);
					zephir_array_update_string(&_21$$14, SL("filePath"), &configName, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_21$$14, SL("adapter"), &defaultAdapter_zv, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&configInstance, &_21$$14);
				} else {
					_18$$12 = zephir_array_isset_value_string(&configInstance, SL("adapter"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_18$$12)) {
						zephir_array_update_string(&configInstance, SL("adapter"), &defaultAdapter_zv, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				}
				ZEPHIR_OBS_NVAR(&_22$$12);
				zephir_array_fetch_string(&_22$$12, &configInstance, SL("adapter"), PH_NOISY, "phalcon/Config/Adapter/Grouped.zep", 124);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_23$$12);
				ZVAL_STRING(&_23$$12, "array");
				if (ZEPHIR_IS_IDENTICAL(&_23$$12, &_22$$12)) {
					_24$$17 = zephir_array_isset_value_string(&configInstance, SL("config"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_24$$17)) {
						ZEPHIR_INIT_NVAR(&_25$$18);
						object_init_ex(&_25$$18, phalcon_config_exceptions_groupedadapterrequiresarray_ce);
						zephir_constructor_start(&_25$$18);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_25$$18, "__construct", &_zephir_call_cache[16]);
						zephir_check_call_status();
						zephir_constructor_finish(&_25$$18);
						zephir_throw_exception_debug(&_25$$18, "phalcon/Config/Adapter/Grouped.zep", 126);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&configArray);
					zephir_array_fetch_string(&configArray, &configInstance, SL("config"), PH_NOISY, "phalcon/Config/Adapter/Grouped.zep", 129);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_26$$17);
					object_init_ex(&_26$$17, phalcon_config_config_ce);
					zephir_constructor_start(&_26$$17);
					zephir_read_property_cached(&_27$$17, this_ptr, _zephir_prop_0, 537, PH_NOISY_CC | PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_26$$17, "__construct", &_zephir_call_cache[17], &configArray, &_27$$17);
					zephir_check_call_status();
					zephir_constructor_finish(&_26$$17);
					ZEPHIR_CPY_WRT(&configInstance, &_26$$17);
					ZEPHIR_INIT_NVAR(&_26$$17);
				} else {
					ZEPHIR_CALL_METHOD_CACHED(&_28$$19, &configFactory, "load", &_zephir_call_cache[18], &configInstance);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&configInstance, &_28$$19);
				}
				ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "merge", &_zephir_call_cache[19], &configInstance);
				zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();
}

