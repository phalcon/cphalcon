
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

	HashTable *_4, *_7;
	HashPosition _3, _6;
	zval *filePath_param = NULL, *config, *iniConfig, *section = NULL, *directives = NULL, *directiveParts = NULL, *key = NULL, *value = NULL, *_0, *_1, *_2, **_5, **_8, *_9, *_10;
	zval *filePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filePath_param);

	if (Z_TYPE_P(filePath_param) != IS_STRING && Z_TYPE_P(filePath_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filePath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(filePath_param) == IS_STRING) {
		filePath = filePath_param;
	} else {
		ZEPHIR_INIT_VAR(filePath);
		ZVAL_EMPTY_STRING(filePath);
	}


	ZEPHIR_INIT_VAR(config);
	array_init(config);
	ZEPHIR_INIT_VAR(iniConfig);
	zephir_call_func_p2(iniConfig, "parse_ini_file", filePath, ZEPHIR_GLOBAL(global_true));
	if (ZEPHIR_IS_FALSE(iniConfig)) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, phalcon_config_exception_ce);
		ZEPHIR_INIT_VAR(_1);
		zephir_basename(_1, filePath TSRMLS_CC);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SVS(_2, "Configuration file ", _1, " can't be loaded");
		zephir_call_method_p1_noret(_0, "__construct", _2);
		zephir_throw_exception(_0 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_is_iterable(iniConfig, &_4, &_3, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HMKEY(section, _4, _3);
		ZEPHIR_GET_HVALUE(directives, _5);
		zephir_is_iterable(directives, &_7, &_6, 0, 0);
		for (
		  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
		  ; zephir_hash_move_forward_ex(_7, &_6)
		) {
			ZEPHIR_GET_HMKEY(key, _7, _6);
			ZEPHIR_GET_HVALUE(value, _8);
			if (zephir_memnstr_str(key, SL("."), "phalcon/config/adapter/ini.zep", 43)) {
				ZEPHIR_INIT_NVAR(directiveParts);
				zephir_fast_explode_str(directiveParts, SL("."), key, LONG_MAX TSRMLS_CC);
				zephir_array_fetch_long(&_9, directiveParts, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
				zephir_array_fetch_long(&_10, directiveParts, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
				zephir_array_update_multi(&config, &value TSRMLS_CC, SL("zzz"), 3, section, _9, _10);
			} else {
				zephir_array_update_multi(&config, &value TSRMLS_CC, SL("zz"), 2, section, key);
			}
		}
	}
	zephir_call_parent_p1_noret(this_ptr, phalcon_config_adapter_ini_ce, "__construct", config);
	ZEPHIR_MM_RESTORE();

}

