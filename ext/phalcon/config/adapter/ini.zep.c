
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

	zend_string *_6, *_9$$5;
	zend_ulong _5, _8$$5;
	zephir_fcall_cache_entry *_12 = NULL, *_16 = NULL, *_17 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *filePath_param = NULL, __$true, iniConfig, _0, config, section, sections, directives, path, lastValue, *_4, _1$$3, _2$$3, _3$$3, *_7$$5, _10$$6, _13$$7, _14$$7, _15$$8;
	zval filePath, _11$$6;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&filePath);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&iniConfig);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&section);
	ZVAL_UNDEF(&sections);
	ZVAL_UNDEF(&directives);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&lastValue);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filePath_param);

	if (unlikely(Z_TYPE_P(filePath_param) != IS_STRING && Z_TYPE_P(filePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filePath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(filePath_param) == IS_STRING)) {
		zephir_get_strval(&filePath, filePath_param);
	} else {
		ZEPHIR_INIT_VAR(&filePath);
		ZVAL_EMPTY_STRING(&filePath);
	}


	ZVAL_LONG(&_0, 1);
	ZEPHIR_CALL_FUNCTION(&iniConfig, "parse_ini_file", NULL, 135, &filePath, &__$true, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&iniConfig)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_config_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_basename(&_2$$3, &filePath TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SVS(&_3$$3, "Configuration file ", &_2$$3, " can't be loaded");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 9, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/config/adapter/ini.zep", 68 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&config);
	array_init(&config);
	zephir_is_iterable(&iniConfig, 0, "phalcon/config/adapter/ini.zep", 90);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&iniConfig), _5, _6, _4)
	{
		ZEPHIR_INIT_NVAR(&section);
		if (_6 != NULL) { 
			ZVAL_STR_COPY(&section, _6);
		} else {
			ZVAL_LONG(&section, _5);
		}
		ZEPHIR_INIT_NVAR(&directives);
		ZVAL_COPY(&directives, _4);
		if (Z_TYPE_P(&directives) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(&sections);
			array_init(&sections);
			zephir_is_iterable(&directives, 0, "phalcon/config/adapter/ini.zep", 82);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&directives), _8$$5, _9$$5, _7$$5)
			{
				ZEPHIR_INIT_NVAR(&path);
				if (_9$$5 != NULL) { 
					ZVAL_STR_COPY(&path, _9$$5);
				} else {
					ZVAL_LONG(&path, _8$$5);
				}
				ZEPHIR_INIT_NVAR(&lastValue);
				ZVAL_COPY(&lastValue, _7$$5);
				zephir_get_strval(&_11$$6, &path);
				ZEPHIR_CALL_METHOD(&_10$$6, this_ptr, "_parseinistring", &_12, 0, &_11$$6, &lastValue);
				zephir_check_call_status();
				zephir_array_append(&sections, &_10$$6, PH_SEPARATE, "phalcon/config/adapter/ini.zep", 80);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&lastValue);
			ZEPHIR_INIT_NVAR(&path);
			if (zephir_fast_count_int(&sections TSRMLS_CC)) {
				ZEPHIR_INIT_NVAR(&_13$$7);
				ZEPHIR_INIT_NVAR(&_14$$7);
				ZVAL_STRING(&_14$$7, "array_merge_recursive");
				ZEPHIR_CALL_USER_FUNC_ARRAY(&_13$$7, &_14$$7, &sections);
				zephir_check_call_status();
				zephir_array_update_zval(&config, &section, &_13$$7, PH_COPY | PH_SEPARATE);
			}
		} else {
			ZEPHIR_CALL_METHOD(&_15$$8, this_ptr, "_cast", &_16, 136, &directives);
			zephir_check_call_status();
			zephir_array_update_zval(&config, &section, &_15$$8, PH_COPY | PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&directives);
	ZEPHIR_INIT_NVAR(&section);
	ZEPHIR_CALL_PARENT(NULL, phalcon_config_adapter_ini_ce, this_ptr, "__construct", &_17, 16, &config);
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
	zval *path_param = NULL, *value = NULL, value_sub, pos, key, _0, _1, _2, _3, _4;
	zval path;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&pos);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &path_param, &value);

	if (unlikely(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(&path, path_param);
	} else {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_EMPTY_STRING(&path);
	}
	ZEPHIR_SEPARATE_PARAM(value);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "_cast", NULL, 136, value);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(value, &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, ".");
	ZEPHIR_INIT_VAR(&pos);
	zephir_fast_strpos(&pos, &path, &_1, 0 );
	if (ZEPHIR_IS_FALSE_IDENTICAL(&pos)) {
		zephir_create_array(return_value, 1, 0 TSRMLS_CC);
		zephir_array_update_zval(return_value, &path, value, PH_COPY);
		RETURN_MM();
	}
	ZVAL_LONG(&_2, 0);
	ZEPHIR_INIT_VAR(&key);
	zephir_substr(&key, &path, 0 , zephir_get_intval(&pos), 0);
	ZVAL_LONG(&_3, (zephir_get_numberval(&pos) + 1));
	ZEPHIR_INIT_VAR(&_4);
	zephir_substr(&_4, &path, zephir_get_intval(&_3), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	zephir_get_strval(&path, &_4);
	zephir_create_array(return_value, 1, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "_parseinistring", NULL, 137, &path, value);
	zephir_check_call_status();
	zephir_array_update_zval(return_value, &key, &_0, PH_COPY);
	RETURN_MM();

}

/**
 * @link https://github.com/ice/framework/blob/dev/ice/config/ini.zep#L46
 * We have to cast values manually because parse_ini_file() has a poor implementation.
 *
 * @param mixed ini The array casted by `parse_ini_file`
 * @return mixed
 */
PHP_METHOD(Phalcon_Config_Adapter_Ini, _cast) {

	zend_bool _5$$5, _6$$5, _7$$5, _8$$5;
	zend_string *_2$$3;
	zend_ulong _1$$3;
	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *ini, ini_sub, key, val, *_0$$3, _3$$4, _9$$9, _10$$9, _11$$9;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&ini_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ini);

	ZEPHIR_SEPARATE_PARAM(ini);


	if (Z_TYPE_P(ini) == IS_ARRAY) {
		zephir_is_iterable(ini, 1, "phalcon/config/adapter/ini.zep", 139);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(ini), _1$$3, _2$$3, _0$$3)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_2$$3 != NULL) { 
				ZVAL_STR_COPY(&key, _2$$3);
			} else {
				ZVAL_LONG(&key, _1$$3);
			}
			ZEPHIR_INIT_NVAR(&val);
			ZVAL_COPY(&val, _0$$3);
			ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "_cast", &_4, 136, &val);
			zephir_check_call_status();
			zephir_array_update_zval(ini, &key, &_3$$4, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&val);
		ZEPHIR_INIT_NVAR(&key);
	}
	if (Z_TYPE_P(ini) == IS_STRING) {
		_5$$5 = ZEPHIR_IS_STRING_IDENTICAL(ini, "true");
		if (!(_5$$5)) {
			_5$$5 = ZEPHIR_IS_STRING_IDENTICAL(ini, "yes");
		}
		_6$$5 = _5$$5;
		if (!(_6$$5)) {
			_6$$5 = ZEPHIR_IS_STRING_IDENTICAL(ini, "on");
		}
		if (_6$$5) {
			RETURN_MM_BOOL(1);
		}
		_7$$5 = ZEPHIR_IS_STRING_IDENTICAL(ini, "false");
		if (!(_7$$5)) {
			_7$$5 = ZEPHIR_IS_STRING_IDENTICAL(ini, "no");
		}
		_8$$5 = _7$$5;
		if (!(_8$$5)) {
			_8$$5 = ZEPHIR_IS_STRING_IDENTICAL(ini, "off");
		}
		if (_8$$5) {
			RETURN_MM_BOOL(0);
		}
		if (ZEPHIR_IS_STRING_IDENTICAL(ini, "null")) {
			RETURN_MM_NULL();
		}
		if (zephir_is_numeric(ini)) {
			ZEPHIR_INIT_VAR(&_9$$9);
			ZEPHIR_INIT_VAR(&_10$$9);
			ZEPHIR_INIT_VAR(&_11$$9);
			ZVAL_STRING(&_11$$9, "/[.]+/");
			zephir_preg_match(&_10$$9, &_11$$9, ini, &_9$$9, 0, 0 , 0  TSRMLS_CC);
			if (zephir_is_true(&_10$$9)) {
				RETURN_MM_DOUBLE(zephir_get_doubleval(ini));
			} else {
				RETURN_MM_LONG(zephir_get_intval(ini));
			}
		}
	}
	RETVAL_ZVAL(ini, 1, 0);
	RETURN_MM();

}

