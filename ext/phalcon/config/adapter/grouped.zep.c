
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
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/object.h"


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
	zephir_fcall_cache_entry *_0 = NULL, *_6 = NULL, *_8 = NULL, *_9 = NULL, *_15 = NULL, *_16 = NULL;
	zval defaultAdapter, _14$$8, _26$$15;
	zval *arrayConfig_param = NULL, *defaultAdapter_param = NULL, configArray, configInstance, configName, _1, *_2, _3, _4$$4, _10$$4, _5$$5, _7$$5, _11$$3, _12$$3, _13$$8, _17$$9, _18$$9, _19$$11, _22$$11, _20$$12, _21$$12, _23$$10, _24$$10, _25$$15, _27$$16, _28$$16;
	zval arrayConfig;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrayConfig);
	ZVAL_UNDEF(&configArray);
	ZVAL_UNDEF(&configInstance);
	ZVAL_UNDEF(&configName);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_19$$11);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&_20$$12);
	ZVAL_UNDEF(&_21$$12);
	ZVAL_UNDEF(&_23$$10);
	ZVAL_UNDEF(&_24$$10);
	ZVAL_UNDEF(&_25$$15);
	ZVAL_UNDEF(&_27$$16);
	ZVAL_UNDEF(&_28$$16);
	ZVAL_UNDEF(&defaultAdapter);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_26$$15);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &arrayConfig_param, &defaultAdapter_param);

	ZEPHIR_OBS_COPY_OR_DUP(&arrayConfig, arrayConfig_param);
	if (!defaultAdapter_param) {
		ZEPHIR_INIT_VAR(&defaultAdapter);
		ZVAL_STRING(&defaultAdapter, "php");
	} else {
	if (UNEXPECTED(Z_TYPE_P(defaultAdapter_param) != IS_STRING && Z_TYPE_P(defaultAdapter_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'defaultAdapter' must be of the type string") TSRMLS_CC);
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
	zephir_is_iterable(&arrayConfig, 0, "phalcon/Config/Adapter/Grouped.zep", 117);
	if (Z_TYPE_P(&arrayConfig) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&arrayConfig), _2)
		{
			ZEPHIR_INIT_NVAR(&configName);
			ZVAL_COPY(&configName, _2);
			ZEPHIR_CPY_WRT(&configInstance, &configName);
			if (Z_TYPE_P(&configName) == IS_STRING) {
				ZEPHIR_SINIT_NVAR(_4$$4);
				ZVAL_STRING(&_4$$4, "");
				if (ZEPHIR_IS_IDENTICAL(&_4$$4, &defaultAdapter)) {
					ZEPHIR_INIT_NVAR(&_5$$5);
					object_init_ex(&_5$$5, phalcon_config_configfactory_ce);
					ZEPHIR_CALL_METHOD(NULL, &_5$$5, "__construct", &_6, 163);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_7$$5, &_5$$5, "load", &_8, 164, &configName);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_9, 0, &_7$$5);
					zephir_check_call_status();
					continue;
				}
				ZEPHIR_INIT_NVAR(&_10$$4);
				zephir_create_array(&_10$$4, 2, 0 TSRMLS_CC);
				zephir_array_update_string(&_10$$4, SL("filePath"), &configName, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_10$$4, SL("adapter"), &defaultAdapter, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&configInstance, &_10$$4);
			} else if (!(zephir_array_isset_string(&configInstance, SL("adapter")))) {
				zephir_array_update_string(&configInstance, SL("adapter"), &defaultAdapter, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_string(&_11$$3, &configInstance, SL("adapter"), PH_NOISY | PH_READONLY, "phalcon/Config/Adapter/Grouped.zep", 101 TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_12$$3);
			ZVAL_STRING(&_12$$3, "array");
			if (ZEPHIR_IS_IDENTICAL(&_12$$3, &_11$$3)) {
				if (!(zephir_array_isset_string(&configInstance, SL("config")))) {
					ZEPHIR_INIT_NVAR(&_13$$8);
					object_init_ex(&_13$$8, phalcon_config_exception_ce);
					ZEPHIR_INIT_LNVAR(_14$$8);
					ZEPHIR_CONCAT_SS(&_14$$8, "To use 'array' adapter you have to specify ", "the 'config' as an array.");
					ZEPHIR_CALL_METHOD(NULL, &_13$$8, "__construct", &_15, 5, &_14$$8);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_13$$8, "phalcon/Config/Adapter/Grouped.zep", 106 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&configArray);
				zephir_array_fetch_string(&configArray, &configInstance, SL("config"), PH_NOISY, "phalcon/Config/Adapter/Grouped.zep", 109 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&configInstance);
				object_init_ex(&configInstance, phalcon_config_ce);
				ZEPHIR_CALL_METHOD(NULL, &configInstance, "__construct", &_16, 17, &configArray);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(&_17$$9);
				object_init_ex(&_17$$9, phalcon_config_configfactory_ce);
				ZEPHIR_CALL_METHOD(NULL, &_17$$9, "__construct", &_6, 163);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_18$$9, &_17$$9, "load", &_8, 164, &configInstance);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&configInstance, &_18$$9);
			}
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_9, 0, &configInstance);
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
				if (Z_TYPE_P(&configName) == IS_STRING) {
					ZEPHIR_SINIT_NVAR(_19$$11);
					ZVAL_STRING(&_19$$11, "");
					if (ZEPHIR_IS_IDENTICAL(&_19$$11, &defaultAdapter)) {
						ZEPHIR_INIT_NVAR(&_20$$12);
						object_init_ex(&_20$$12, phalcon_config_configfactory_ce);
						ZEPHIR_CALL_METHOD(NULL, &_20$$12, "__construct", &_6, 163);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_21$$12, &_20$$12, "load", &_8, 164, &configName);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_9, 0, &_21$$12);
						zephir_check_call_status();
						continue;
					}
					ZEPHIR_INIT_NVAR(&_22$$11);
					zephir_create_array(&_22$$11, 2, 0 TSRMLS_CC);
					zephir_array_update_string(&_22$$11, SL("filePath"), &configName, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_22$$11, SL("adapter"), &defaultAdapter, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&configInstance, &_22$$11);
				} else if (!(zephir_array_isset_string(&configInstance, SL("adapter")))) {
					zephir_array_update_string(&configInstance, SL("adapter"), &defaultAdapter, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_string(&_23$$10, &configInstance, SL("adapter"), PH_NOISY | PH_READONLY, "phalcon/Config/Adapter/Grouped.zep", 101 TSRMLS_CC);
				ZEPHIR_SINIT_NVAR(_24$$10);
				ZVAL_STRING(&_24$$10, "array");
				if (ZEPHIR_IS_IDENTICAL(&_24$$10, &_23$$10)) {
					if (!(zephir_array_isset_string(&configInstance, SL("config")))) {
						ZEPHIR_INIT_NVAR(&_25$$15);
						object_init_ex(&_25$$15, phalcon_config_exception_ce);
						ZEPHIR_INIT_LNVAR(_26$$15);
						ZEPHIR_CONCAT_SS(&_26$$15, "To use 'array' adapter you have to specify ", "the 'config' as an array.");
						ZEPHIR_CALL_METHOD(NULL, &_25$$15, "__construct", &_15, 5, &_26$$15);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_25$$15, "phalcon/Config/Adapter/Grouped.zep", 106 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&configArray);
					zephir_array_fetch_string(&configArray, &configInstance, SL("config"), PH_NOISY, "phalcon/Config/Adapter/Grouped.zep", 109 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&configInstance);
					object_init_ex(&configInstance, phalcon_config_ce);
					ZEPHIR_CALL_METHOD(NULL, &configInstance, "__construct", &_16, 17, &configArray);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&_27$$16);
					object_init_ex(&_27$$16, phalcon_config_configfactory_ce);
					ZEPHIR_CALL_METHOD(NULL, &_27$$16, "__construct", &_6, 163);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_28$$16, &_27$$16, "load", &_8, 164, &configInstance);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&configInstance, &_28$$16);
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", &_9, 0, &configInstance);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &arrayConfig, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&configName);
	ZEPHIR_MM_RESTORE();

}

