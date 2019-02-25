
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
#include "ext/spl/spl_exceptions.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Config\Adapter\Grouped
 *
 * Reads multiple files (or arrays) and merges them all together.
 *
 * @see Phalcon\Config\Factory::load To load Config Adapter class using 'adapter' option.
 *
 * <code>
 * use Phalcon\Config\Adapter\Grouped;
 *
 * $config = new Grouped(
 *     [
 *         "path/to/config.php",
 *         "path/to/config.dist.php",
 *     ]
 * );
 * </code>
 *
 * <code>
 * use Phalcon\Config\Adapter\Grouped;
 *
 * $config = new Grouped(
 *     [
 *         "path/to/config.json",
 *         "path/to/config.dist.json",
 *     ],
 *     "json"
 * );
 * </code>
 *
 * <code>
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
 *         ],
 *     ],
 * );
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Config_Adapter_Grouped) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Config\\Adapter, Grouped, phalcon, config_adapter_grouped, phalcon_config_ce, phalcon_config_adapter_grouped_method_entry, 0);

	return SUCCESS;

}

/**
 * Phalcon\Config\Adapter\Grouped constructor
 */
PHP_METHOD(Phalcon_Config_Adapter_Grouped, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_4 = NULL, *_5 = NULL, *_7 = NULL;
	zval defaultAdapter;
	zval *arrayConfig_param = NULL, *defaultAdapter_param = NULL, configName, configInstance, configArray, _1, *_2, _3$$5, _6$$3, _8$$10;
	zval arrayConfig;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrayConfig);
	ZVAL_UNDEF(&configName);
	ZVAL_UNDEF(&configInstance);
	ZVAL_UNDEF(&configArray);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&defaultAdapter);

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
	zephir_is_iterable(&arrayConfig, 0, "phalcon/config/adapter/grouped.zep", 111);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&arrayConfig), _2)
	{
		ZEPHIR_INIT_NVAR(&configName);
		ZVAL_COPY(&configName, _2);
		ZEPHIR_CPY_WRT(&configInstance, &configName);
		if (Z_TYPE_P(&configName) == IS_STRING) {
			if (ZEPHIR_IS_STRING_IDENTICAL(&defaultAdapter, "")) {
				ZEPHIR_CALL_CE_STATIC(&_3$$5, phalcon_config_factory_ce, "load", &_4, 0, &configName);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_merge", &_5, 13, &_3$$5);
				zephir_check_call_status();
				continue;
			}
			ZEPHIR_INIT_NVAR(&configInstance);
			zephir_create_array(&configInstance, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&configInstance, SL("filePath"), &configName, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&configInstance, SL("adapter"), &defaultAdapter, PH_COPY | PH_SEPARATE);
		} else if (!(zephir_array_isset_string(&configInstance, SL("adapter")))) {
			zephir_array_update_string(&configInstance, SL("adapter"), &defaultAdapter, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_string(&_6$$3, &configInstance, SL("adapter"), PH_NOISY | PH_READONLY, "phalcon/config/adapter/grouped.zep", 96 TSRMLS_CC);
		if (ZEPHIR_IS_STRING_IDENTICAL(&_6$$3, "array")) {
			if (!(zephir_array_isset_string(&configInstance, SL("config")))) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_factory_exception_ce, "To use 'array' adapter you have to specify the 'config' as an array.", "phalcon/config/adapter/grouped.zep", 100);
				return;
			} else {
				ZEPHIR_OBS_NVAR(&configArray);
				zephir_array_fetch_string(&configArray, &configInstance, SL("config"), PH_NOISY, "phalcon/config/adapter/grouped.zep", 102 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&configInstance);
				object_init_ex(&configInstance, phalcon_config_ce);
				ZEPHIR_CALL_METHOD(NULL, &configInstance, "__construct", &_7, 12, &configArray);
				zephir_check_call_status();
			}
		} else {
			ZEPHIR_CALL_CE_STATIC(&_8$$10, phalcon_config_factory_ce, "load", &_4, 0, &configInstance);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&configInstance, &_8$$10);
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_merge", &_5, 13, &configInstance);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&configName);
	ZEPHIR_MM_RESTORE();

}

