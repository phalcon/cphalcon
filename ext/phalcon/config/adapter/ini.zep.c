
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
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
ZEPHIR_INIT_CLASS(Phalcon_Config_Adapter_Ini) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Config\\Adapter, Ini, phalcon, config_adapter_ini, phalcon_config_ce, phalcon_config_adapter_ini_method_entry, 0);

	return SUCCESS;

}

/**
 * Phalcon\Config\Adapter\Ini constructor
 *
 * @param string filePath
 */
PHP_METHOD(Phalcon_Config_Adapter_Ini, __construct) {

	HashTable *_5, *_8;
	HashPosition _4, _7;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL, *_12 = NULL;
	zval *filePath_param = NULL, *config, *iniConfig = NULL, *section = NULL, *directives = NULL, *directiveParts = NULL, *key = NULL, *value = NULL, *_1, *_2, *_3, **_6, **_9, *_10, *_11;
	zval *filePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filePath_param);

	if (unlikely(Z_TYPE_P(filePath_param) != IS_STRING && Z_TYPE_P(filePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filePath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(filePath_param) == IS_STRING)) {
		filePath = filePath_param;
	} else {
		ZEPHIR_INIT_VAR(filePath);
		ZVAL_EMPTY_STRING(filePath);
	}


	ZEPHIR_INIT_VAR(config);
	array_init(config);
	ZEPHIR_CALL_FUNCTION(&iniConfig, "parse_ini_file", &_0, filePath, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(iniConfig)) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, phalcon_config_exception_ce);
		ZEPHIR_INIT_VAR(_2);
		zephir_basename(_2, filePath TSRMLS_CC);
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_CONCAT_SVS(_3, "Configuration file ", _2, " can't be loaded");
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "phalcon/config/adapter/ini.zep", 38 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_is_iterable(iniConfig, &_5, &_4, 0, 0, "phalcon/config/adapter/ini.zep", 52);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HMKEY(section, _5, _4);
		ZEPHIR_GET_HVALUE(directives, _6);
		zephir_is_iterable(directives, &_8, &_7, 0, 0, "phalcon/config/adapter/ini.zep", 50);
		for (
		  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
		  ; zephir_hash_move_forward_ex(_8, &_7)
		) {
			ZEPHIR_GET_HMKEY(key, _8, _7);
			ZEPHIR_GET_HVALUE(value, _9);
			if (zephir_memnstr_str(key, SL("."), "phalcon/config/adapter/ini.zep", 43)) {
				ZEPHIR_INIT_NVAR(directiveParts);
				zephir_fast_explode_str(directiveParts, SL("."), key, LONG_MAX TSRMLS_CC);
				zephir_array_fetch_long(&_10, directiveParts, 0, PH_NOISY | PH_READONLY, "phalcon/config/adapter/ini.zep", 45 TSRMLS_CC);
				zephir_array_fetch_long(&_11, directiveParts, 1, PH_NOISY | PH_READONLY, "phalcon/config/adapter/ini.zep", 45 TSRMLS_CC);
				zephir_array_update_multi(&config, &value TSRMLS_CC, SL("zzz"), 3, section, _10, _11);
			} else {
				zephir_array_update_multi(&config, &value TSRMLS_CC, SL("zz"), 2, section, key);
			}
		}
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_config_adapter_ini_ce, this_ptr, "__construct", &_12, config);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

