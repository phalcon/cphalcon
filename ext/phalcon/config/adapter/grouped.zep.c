
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
 * See `Phalcon\Config\Factory::load` To load Config Adapter class using 'adapter' option.
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
ZEPHIR_INIT_CLASS(Phalcon_Config_Adapter_Grouped) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Config\\Adapter, Grouped, phalcon, config_adapter_grouped, phalcon_config_ce, phalcon_config_adapter_grouped_method_entry, 0);

	return SUCCESS;

}

/**
 * Phalcon\Config\Adapter\Grouped constructor
 */
PHP_METHOD(Phalcon_Config_Adapter_Grouped, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_4 = NULL, *_7 = NULL, *_9 = NULL, *_15 = NULL, *_16 = NULL;
	zval defaultAdapter, _14$$9, _26$$17;
	zval *arrayConfig_param = NULL, *defaultAdapter_param = NULL, configArray, configInstance, configName, _1, *_2, _3, _5$$5, _10$$5, _6$$6, _8$$6, _11$$3, _12$$3, _13$$9, _17$$10, _18$$10, _19$$13, _22$$13, _20$$14, _21$$14, _23$$11, _24$$11, _25$$17, _27$$18, _28$$18;
	zval arrayConfig;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrayConfig);
	ZVAL_UNDEF(&configArray);
	ZVAL_UNDEF(&configInstance);
	ZVAL_UNDEF(&configName);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_22$$13);
	ZVAL_UNDEF(&_20$$14);
	ZVAL_UNDEF(&_21$$14);
	ZVAL_UNDEF(&_23$$11);
	ZVAL_UNDEF(&_24$$11);
	ZVAL_UNDEF(&_25$$17);
	ZVAL_UNDEF(&_27$$18);
	ZVAL_UNDEF(&_28$$18);
	ZVAL_UNDEF(&defaultAdapter);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_26$$17);

	ZEPHIR_MM_GROW();
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
		ZVAL_EMPTY_STRING(&defaultAdapter);
	}
	}


	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	ZEPHIR_CALL_PARENT(NULL, phalcon_config_adapter_grouped_ce, getThis(), "__construct", &_0, 0, &_1);
	zephir_check_call_status();
	zephir_is_iterable(&arrayConfig, 0, "/home/nikos/Work/niden/cphalcon/phalcon/Config/Adapter/Grouped.zep", 120);
	if (Z_TYPE_P(&arrayConfig) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&arrayConfig), _2)
		{
			ZEPHIR_INIT_NVAR(&configName);
			ZVAL_COPY(&configName, _2);
			ZEPHIR_CPY_WRT(&configInstance, &configName);
			if (zephir_is_instance_of(&configName, SL("Phalcon\\Config"))) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_4, 0, &configInstance);
				zephir_check_call_status();
				continue;
			} else if (Z_TYPE_P(&configName) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_5$$5);
				ZVAL_STRING(&_5$$5, "");
				if (ZEPHIR_IS_IDENTICAL(&_5$$5, &defaultAdapter)) {
					ZEPHIR_INIT_NVAR(&_6$$6);
					object_init_ex(&_6$$6, phalcon_config_configfactory_ce);
					ZEPHIR_CALL_METHOD(NULL, &_6$$6, "__construct", &_7, 174);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_8$$6, &_6$$6, "load", &_9, 175, &configName);
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
			zephir_array_fetch_string(&_11$$3, &configInstance, SL("adapter"), PH_NOISY | PH_READONLY, "/home/nikos/Work/niden/cphalcon/phalcon/Config/Adapter/Grouped.zep", 104);
			ZEPHIR_INIT_NVAR(&_12$$3);
			ZVAL_STRING(&_12$$3, "array");
			if (ZEPHIR_IS_IDENTICAL(&_12$$3, &_11$$3)) {
				if (!(zephir_array_isset_string(&configInstance, SL("config")))) {
					ZEPHIR_INIT_NVAR(&_13$$9);
					object_init_ex(&_13$$9, phalcon_config_exception_ce);
					ZEPHIR_INIT_NVAR(&_14$$9);
					ZEPHIR_CONCAT_SS(&_14$$9, "To use 'array' adapter you have to specify ", "the 'config' as an array.");
					ZEPHIR_CALL_METHOD(NULL, &_13$$9, "__construct", &_15, 8, &_14$$9);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_13$$9, "/home/nikos/Work/niden/cphalcon/phalcon/Config/Adapter/Grouped.zep", 109);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&configArray);
				zephir_array_fetch_string(&configArray, &configInstance, SL("config"), PH_NOISY, "/home/nikos/Work/niden/cphalcon/phalcon/Config/Adapter/Grouped.zep", 112);
				ZEPHIR_INIT_NVAR(&configInstance);
				object_init_ex(&configInstance, phalcon_config_ce);
				ZEPHIR_CALL_METHOD(NULL, &configInstance, "__construct", &_16, 22, &configArray);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(&_17$$10);
				object_init_ex(&_17$$10, phalcon_config_configfactory_ce);
				ZEPHIR_CALL_METHOD(NULL, &_17$$10, "__construct", &_7, 174);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_18$$10, &_17$$10, "load", &_9, 175, &configInstance);
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
			ZEPHIR_CALL_METHOD(&_3, &arrayConfig, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&configName, &arrayConfig, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CPY_WRT(&configInstance, &configName);
				if (zephir_is_instance_of(&configName, SL("Phalcon\\Config"))) {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_4, 0, &configInstance);
					zephir_check_call_status();
					continue;
				} else if (Z_TYPE_P(&configName) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_19$$13);
					ZVAL_STRING(&_19$$13, "");
					if (ZEPHIR_IS_IDENTICAL(&_19$$13, &defaultAdapter)) {
						ZEPHIR_INIT_NVAR(&_20$$14);
						object_init_ex(&_20$$14, phalcon_config_configfactory_ce);
						ZEPHIR_CALL_METHOD(NULL, &_20$$14, "__construct", &_7, 174);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_21$$14, &_20$$14, "load", &_9, 175, &configName);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_4, 0, &_21$$14);
						zephir_check_call_status();
						continue;
					}
					ZEPHIR_INIT_NVAR(&_22$$13);
					zephir_create_array(&_22$$13, 2, 0);
					zephir_array_update_string(&_22$$13, SL("filePath"), &configName, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_22$$13, SL("adapter"), &defaultAdapter, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&configInstance, &_22$$13);
				} else if (!(zephir_array_isset_string(&configInstance, SL("adapter")))) {
					zephir_array_update_string(&configInstance, SL("adapter"), &defaultAdapter, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_string(&_23$$11, &configInstance, SL("adapter"), PH_NOISY | PH_READONLY, "/home/nikos/Work/niden/cphalcon/phalcon/Config/Adapter/Grouped.zep", 104);
				ZEPHIR_INIT_NVAR(&_24$$11);
				ZVAL_STRING(&_24$$11, "array");
				if (ZEPHIR_IS_IDENTICAL(&_24$$11, &_23$$11)) {
					if (!(zephir_array_isset_string(&configInstance, SL("config")))) {
						ZEPHIR_INIT_NVAR(&_25$$17);
						object_init_ex(&_25$$17, phalcon_config_exception_ce);
						ZEPHIR_INIT_NVAR(&_26$$17);
						ZEPHIR_CONCAT_SS(&_26$$17, "To use 'array' adapter you have to specify ", "the 'config' as an array.");
						ZEPHIR_CALL_METHOD(NULL, &_25$$17, "__construct", &_15, 8, &_26$$17);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_25$$17, "/home/nikos/Work/niden/cphalcon/phalcon/Config/Adapter/Grouped.zep", 109);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&configArray);
					zephir_array_fetch_string(&configArray, &configInstance, SL("config"), PH_NOISY, "/home/nikos/Work/niden/cphalcon/phalcon/Config/Adapter/Grouped.zep", 112);
					ZEPHIR_INIT_NVAR(&configInstance);
					object_init_ex(&configInstance, phalcon_config_ce);
					ZEPHIR_CALL_METHOD(NULL, &configInstance, "__construct", &_16, 22, &configArray);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&_27$$18);
					object_init_ex(&_27$$18, phalcon_config_configfactory_ce);
					ZEPHIR_CALL_METHOD(NULL, &_27$$18, "__construct", &_7, 174);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_28$$18, &_27$$18, "load", &_9, 175, &configInstance);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&configInstance, &_28$$18);
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

