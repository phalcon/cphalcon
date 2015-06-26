
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
 */
PHP_METHOD(Phalcon_Config_Adapter_Ini, __construct) {

	zephir_fcall_cache_entry *_10 = NULL, *_12 = NULL;
	HashTable *_4, *_7;
	HashPosition _3, _6;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *filePath_param = NULL, *iniConfig = NULL, *_0 = NULL, *_1, *_2, *config, *section = NULL, *sections = NULL, *directives = NULL, *path = NULL, *lastValue = NULL, **_5, **_8, *_9 = NULL, _11 = zval_used_for_init;
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


	ZEPHIR_CALL_FUNCTION(&iniConfig, "parse_ini_file", NULL, 61, filePath, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(iniConfig)) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, phalcon_config_exception_ce);
		ZEPHIR_INIT_VAR(_1);
		zephir_basename(_1, filePath TSRMLS_CC);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SVS(_2, "Configuration file ", _1, " can't be loaded");
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 2, _2);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0, "phalcon/config/adapter/ini.zep", 67 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(config);
	array_init(config);
	zephir_is_iterable(iniConfig, &_4, &_3, 0, 0, "phalcon/config/adapter/ini.zep", 84);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HMKEY(section, _4, _3);
		ZEPHIR_GET_HVALUE(directives, _5);
		ZEPHIR_INIT_NVAR(sections);
		array_init(sections);
		zephir_is_iterable(directives, &_7, &_6, 0, 0, "phalcon/config/adapter/ini.zep", 79);
		for (
		  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
		  ; zephir_hash_move_forward_ex(_7, &_6)
		) {
			ZEPHIR_GET_HMKEY(path, _7, _6);
			ZEPHIR_GET_HVALUE(lastValue, _8);
			ZEPHIR_CALL_METHOD(&_9, this_ptr, "_parseinistring", &_10, 0, path, lastValue);
			zephir_check_call_status();
			zephir_array_append(&sections, _9, PH_SEPARATE, "phalcon/config/adapter/ini.zep", 77);
		}
		if (zephir_fast_count_int(sections TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(_0);
			ZEPHIR_SINIT_NVAR(_11);
			ZVAL_STRING(&_11, "array_merge_recursive", 0);
			ZEPHIR_CALL_USER_FUNC_ARRAY(_0, &_11, sections);
			zephir_check_call_status();
			zephir_array_update_zval(&config, section, &_0, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_config_adapter_ini_ce, this_ptr, "__construct", &_12, 58, config);
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
 */
PHP_METHOD(Phalcon_Config_Adapter_Ini, _parseIniString) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *value, *pos, *key, _0, _1, _2, *_3, *_4 = NULL;
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
		zephir_create_array(return_value, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&return_value, Z_STRVAL_P(path), Z_STRLEN_P(path), &value, PH_COPY);
		RETURN_MM();
	}
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_INIT_VAR(key);
	zephir_substr(key, path, 0 , zephir_get_intval(pos), 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, (zephir_get_numberval(pos) + 1));
	ZEPHIR_INIT_VAR(_3);
	zephir_substr(_3, path, zephir_get_intval(&_2), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	zephir_get_strval(path, _3);
	zephir_create_array(return_value, 1, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "_parseinistring", NULL, 62, path, value);
	zephir_check_call_status();
	zephir_array_update_zval(&return_value, key, &_4, PH_COPY);
	RETURN_MM();

}

