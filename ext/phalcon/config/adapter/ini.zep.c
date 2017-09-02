
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/file.h"
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
 * $config = new \Phalcon\Config\Adapter\Ini("path/config.ini");
 *
 * echo $config->phalcon->controllersDir;
 * echo $config->database->username;
 *</code>
 *
 * PHP constants may also be parsed in the ini file, so if you define a constant
 * as an ini value before calling the constructor, the constant's value will be
 * integrated into the results. To use it this way you must specify the optional
 * second parameter as INI_SCANNER_NORMAL when calling the constructor:
 *
 * <code>
 * $config = new \Phalcon\Config\Adapter\Ini(
 *     "path/config-with-constants.ini",
 *     INI_SCANNER_NORMAL
 * );
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Config_Adapter_Ini) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Config\\Adapter, Ini, phalcon, config_adapter_ini, phalcon_config_ce, phalcon_config_adapter_ini_method_entry, 0);

	return SUCCESS;

}

/**
 * Phalcon\Config\Adapter\Ini constructor
 */
PHP_METHOD(Phalcon_Config_Adapter_Ini, __construct) {

	zend_string *_5, *_8$$6;
	zend_ulong _4, _7$$6;
	zephir_fcall_cache_entry *_11 = NULL, *_15 = NULL, *_16 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filePath_param = NULL, *mode = NULL, mode_sub, __$true, __$null, iniConfig, config, section, sections, directives, path, lastValue, *_3, _0$$4, _1$$4, _2$$4, *_6$$6, _9$$7, _12$$8, _13$$8, _14$$9;
	zval filePath, _10$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filePath);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&mode_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&iniConfig);
	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&section);
	ZVAL_UNDEF(&sections);
	ZVAL_UNDEF(&directives);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&lastValue);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &filePath_param, &mode);

	if (UNEXPECTED(Z_TYPE_P(filePath_param) != IS_STRING && Z_TYPE_P(filePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filePath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(filePath_param) == IS_STRING)) {
		zephir_get_strval(&filePath, filePath_param);
	} else {
		ZEPHIR_INIT_VAR(&filePath);
		ZVAL_EMPTY_STRING(&filePath);
	}
	if (!mode) {
		mode = &mode_sub;
		ZEPHIR_CPY_WRT(mode, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(mode);
	}


	if (Z_TYPE_P(mode) == IS_NULL) {
		ZEPHIR_INIT_NVAR(mode);
		ZVAL_LONG(mode, 1);
	}
	ZEPHIR_CALL_FUNCTION(&iniConfig, "parse_ini_file", NULL, 130, &filePath, &__$true, mode);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&iniConfig)) {
		ZEPHIR_INIT_VAR(&_0$$4);
		object_init_ex(&_0$$4, phalcon_config_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_basename(&_1$$4, &filePath TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZEPHIR_CONCAT_SVS(&_2$$4, "Configuration file ", &_1$$4, " can't be loaded");
		ZEPHIR_CALL_METHOD(NULL, &_0$$4, "__construct", NULL, 4, &_2$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$4, "phalcon/config/adapter/ini.zep", 85 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&config);
	array_init(&config);
	zephir_is_iterable(&iniConfig, 0, "phalcon/config/adapter/ini.zep", 106);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&iniConfig), _4, _5, _3)
	{
		ZEPHIR_INIT_NVAR(&section);
		if (_5 != NULL) { 
			ZVAL_STR_COPY(&section, _5);
		} else {
			ZVAL_LONG(&section, _4);
		}
		ZEPHIR_INIT_NVAR(&directives);
		ZVAL_COPY(&directives, _3);
		if (Z_TYPE_P(&directives) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(&sections);
			array_init(&sections);
			zephir_is_iterable(&directives, 0, "phalcon/config/adapter/ini.zep", 98);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&directives), _7$$6, _8$$6, _6$$6)
			{
				ZEPHIR_INIT_NVAR(&path);
				if (_8$$6 != NULL) { 
					ZVAL_STR_COPY(&path, _8$$6);
				} else {
					ZVAL_LONG(&path, _7$$6);
				}
				ZEPHIR_INIT_NVAR(&lastValue);
				ZVAL_COPY(&lastValue, _6$$6);
				zephir_get_strval(&_10$$7, &path);
				ZEPHIR_CALL_METHOD(&_9$$7, this_ptr, "_parseinistring", &_11, 0, &_10$$7, &lastValue);
				zephir_check_call_status();
				zephir_array_append(&sections, &_9$$7, PH_SEPARATE, "phalcon/config/adapter/ini.zep", 96);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&lastValue);
			ZEPHIR_INIT_NVAR(&path);
			if (zephir_fast_count_int(&sections TSRMLS_CC)) {
				ZEPHIR_INIT_NVAR(&_12$$8);
				ZEPHIR_INIT_NVAR(&_13$$8);
				ZVAL_STRING(&_13$$8, "array_merge_recursive");
				ZEPHIR_CALL_USER_FUNC_ARRAY(&_12$$8, &_13$$8, &sections);
				zephir_check_call_status();
				zephir_array_update_zval(&config, &section, &_12$$8, PH_COPY | PH_SEPARATE);
			}
		} else {
			ZEPHIR_CALL_METHOD(&_14$$9, this_ptr, "_cast", &_15, 0, &directives);
			zephir_check_call_status();
			zephir_array_update_zval(&config, &section, &_14$$9, PH_COPY | PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&directives);
	ZEPHIR_INIT_NVAR(&section);
	ZEPHIR_CALL_PARENT(NULL, phalcon_config_adapter_ini_ce, getThis(), "__construct", &_16, 0, &config);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Build multidimensional array from string
 *
 * <code>
 * $this->_parseIniString("path.hello.world", "value for last key");
 *
 * // result
 * [
 *      "path" => [
 *          "hello" => [
 *              "world" => "value for last key",
 *          ],
 *      ],
 * ];
 * </code>
 */
PHP_METHOD(Phalcon_Config_Adapter_Ini, _parseIniString) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *value = NULL, value_sub, pos, key, _0, _1, _2, _3, _4;
	zval path;
	zval *this_ptr = getThis();

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

	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(&path, path_param);
	} else {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_EMPTY_STRING(&path);
	}
	ZEPHIR_SEPARATE_PARAM(value);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "_cast", NULL, 0, value);
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
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "_parseinistring", NULL, 131, &path, value);
	zephir_check_call_status();
	zephir_array_update_zval(return_value, &key, &_0, PH_COPY);
	RETURN_MM();

}

/**
 * We have to cast values manually because parse_ini_file() has a poor implementation.
 *
 * @param mixed ini The array casted by `parse_ini_file`
 */
PHP_METHOD(Phalcon_Config_Adapter_Ini, _cast) {

	zend_bool _5$$5, _6$$5, _8$$5, _9$$5;
	zend_string *_2$$3;
	zend_ulong _1$$3;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ini, ini_sub, key, val, *_0$$3, _3$$4, _7$$5, _10$$5, _11$$9, _12$$9, _13$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ini_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ini);

	ZEPHIR_SEPARATE_PARAM(ini);


	if (Z_TYPE_P(ini) == IS_ARRAY) {
		zephir_is_iterable(ini, 1, "phalcon/config/adapter/ini.zep", 152);
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
			ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "_cast", &_4, 132, &val);
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
			ZEPHIR_INIT_VAR(&_7$$5);
			zephir_fast_strtolower(&_7$$5, ini);
			_6$$5 = ZEPHIR_IS_STRING_IDENTICAL(&_7$$5, "on");
		}
		if (_6$$5) {
			RETURN_MM_BOOL(1);
		}
		_8$$5 = ZEPHIR_IS_STRING_IDENTICAL(ini, "false");
		if (!(_8$$5)) {
			_8$$5 = ZEPHIR_IS_STRING_IDENTICAL(ini, "no");
		}
		_9$$5 = _8$$5;
		if (!(_9$$5)) {
			ZEPHIR_INIT_VAR(&_10$$5);
			zephir_fast_strtolower(&_10$$5, ini);
			_9$$5 = ZEPHIR_IS_STRING_IDENTICAL(&_10$$5, "off");
		}
		if (_9$$5) {
			RETURN_MM_BOOL(0);
		}
		if (ZEPHIR_IS_STRING_IDENTICAL(ini, "null")) {
			RETURN_MM_NULL();
		}
		if (zephir_is_numeric(ini)) {
			ZEPHIR_INIT_VAR(&_11$$9);
			ZEPHIR_INIT_VAR(&_12$$9);
			ZEPHIR_INIT_VAR(&_13$$9);
			ZVAL_STRING(&_13$$9, "/[.]+/");
			zephir_preg_match(&_12$$9, &_13$$9, ini, &_11$$9, 0, 0 , 0  TSRMLS_CC);
			if (zephir_is_true(&_12$$9)) {
				RETURN_MM_DOUBLE(zephir_get_doubleval(ini));
			} else {
				RETURN_MM_LONG(zephir_get_intval(ini));
			}
		}
	}
	RETVAL_ZVAL(ini, 1, 0);
	RETURN_MM();

}

