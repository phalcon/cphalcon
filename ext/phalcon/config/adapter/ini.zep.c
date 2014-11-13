
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
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"


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
 |          Ivan Zubok <chi_no@ukr.net>                                   |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Config\Adapter\Ini
 *
 * Reads ini files and converts them to Phalcon\Config objects.
 *
 * Given the next configuration file:
 *
 *<code>
 * [database]
 * adapter = Mysql
 * host = localhost
 * username = scott
 * password = cheetah
 * dbname = test_db
 *
 * [phalcon]
 * controllersDir = "../app/controllers/"
 * modelsDir = "../app/models/"
 * viewsDir = "../app/views/"
 * </code>
 *
 * You can read it as follows:
 *
 *<code>
 * $config = new Phalcon\Config\Adapter\Ini("path/config.ini");
 * echo $config->phalcon->controllersDir;
 * echo $config->database->username;
 *</code>
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

	zephir_fcall_cache_entry *_11 = NULL;
	HashTable *_5, *_8;
	HashPosition _4, _7;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL, *_13 = NULL;
	zval *filePath_param = NULL, *iniConfig = NULL, *_1, *_2 = NULL, *_3, *config, *section = NULL, *sections = NULL, *directives = NULL, *path = NULL, *lastValue = NULL, **_6, **_9, *_10 = NULL, _12 = zval_used_for_init;
	zval *filePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filePath_param);

	if (unlikely(Z_TYPE_P(filePath_param) != IS_STRING && Z_TYPE_P(filePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filePath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(filePath_param) == IS_STRING)) {
		zephir_get_strval(filePath, filePath_param);
	} else {
		ZEPHIR_INIT_VAR(filePath);
		ZVAL_EMPTY_STRING(filePath);
	}


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
		zephir_throw_exception_debug(_1, "phalcon/config/adapter/ini.zep", 69 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(config);
	array_init(config);
	zephir_is_iterable(iniConfig, &_5, &_4, 0, 0, "phalcon/config/adapter/ini.zep", 84);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HMKEY(section, _5, _4);
		ZEPHIR_GET_HVALUE(directives, _6);
		ZEPHIR_INIT_NVAR(sections);
		array_init(sections);
		zephir_is_iterable(directives, &_8, &_7, 0, 0, "phalcon/config/adapter/ini.zep", 81);
		for (
		  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
		  ; zephir_hash_move_forward_ex(_8, &_7)
		) {
			ZEPHIR_GET_HMKEY(path, _8, _7);
			ZEPHIR_GET_HVALUE(lastValue, _9);
			ZEPHIR_CALL_METHOD(&_10, this_ptr, "_parseinistring", &_11, path, lastValue);
			zephir_check_call_status();
			zephir_array_append(&sections, _10, PH_SEPARATE, "phalcon/config/adapter/ini.zep", 79);
		}
		ZEPHIR_INIT_NVAR(_2);
		ZEPHIR_SINIT_NVAR(_12);
		ZVAL_STRING(&_12, "array_merge_recursive", 0);
		ZEPHIR_CALL_USER_FUNC_ARRAY(_2, &_12, sections);
		zephir_check_call_status();
		zephir_array_update_zval(&config, section, &_2, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_config_adapter_ini_ce, this_ptr, "__construct", &_13, config);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Build multidimensional array from string
 *
 * <code>
 * $this->_parseIniString('path.hello.world', 'value for last key');
 *
 * // result
 * [
 *      'path' => [
 *          'hello' => [
 *              'world' => 'value for last key',
 *          ],
 *      ],
 * ];
 * </code>
 * @param string path
 * @param mixed value
 *
 * @return array parsed path
 */
PHP_METHOD(Phalcon_Config_Adapter_Ini, _parseIniString) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *path_param = NULL, *value, *pos, *key = NULL, _0, _1 = zval_used_for_init, *_3 = NULL, *_4 = NULL;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &path_param, &value);

	if (unlikely(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(path, path_param);
	} else {
		ZEPHIR_INIT_VAR(path);
		ZVAL_EMPTY_STRING(path);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, ".", 0);
	ZEPHIR_INIT_VAR(pos);
	zephir_fast_strpos(pos, path, &_0, 0 );
	if (ZEPHIR_IS_FALSE_IDENTICAL(pos)) {
		array_init_size(return_value, 2);
		zephir_array_update_string(&return_value, Z_STRVAL_P(path), Z_STRLEN_P(path), &value, PH_COPY);
		RETURN_MM();
	}
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_FUNCTION(&key, "substr", &_2, path, &_1, pos);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, (zephir_get_numberval(pos) + 1));
	ZEPHIR_CALL_FUNCTION(&_3, "substr", &_2, path, &_1);
	zephir_check_call_status();
	zephir_get_strval(path, _3);
	array_init_size(return_value, 2);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "_parseinistring", NULL, path, value);
	zephir_check_call_status();
	zephir_array_update_zval(&return_value, key, &_4, PH_COPY);
	RETURN_MM();

}

