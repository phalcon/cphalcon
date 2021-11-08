
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Reads ini files and converts them to Phalcon\Config\Config objects.
 *
 * Given the next configuration file:
 *
 *```ini
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
 * ```
 *
 * You can read it as follows:
 *
 *```php
 * use Phalcon\Config\Adapter\Ini;
 *
 * $config = new Ini("path/config.ini");
 *
 * echo $config->phalcon->controllersDir;
 * echo $config->database->username;
 *```
 *
 * PHP constants may also be parsed in the ini file, so if you define a constant
 * as an ini value before calling the constructor, the constant's value will be
 * integrated into the results. To use it this way you must specify the optional
 * second parameter as `INI_SCANNER_NORMAL` when calling the constructor:
 *
 * ```php
 * $config = new \Phalcon\Config\Adapter\Ini(
 *     "path/config-with-constants.ini",
 *     INI_SCANNER_NORMAL
 * );
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Config_Adapter_Ini)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Config\\Adapter, Ini, phalcon, config_adapter_ini, phalcon_config_config_ce, phalcon_config_adapter_ini_method_entry, 0);

	return SUCCESS;
}

/**
 * Ini constructor.
 *
 * @param string $filePath
 * @param int    $mode
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Config_Adapter_Ini, __construct)
{
	zend_string *_7, *_11$$5, *_24$$10;
	zend_ulong _6, _10$$5, _23$$10;
	zval config;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_14 = NULL, *_20 = NULL, *_32 = NULL;
	zend_long mode, ZEPHIR_LAST_CALL_STATUS;
	zval *filePath_param = NULL, *mode_param = NULL, __$true, directives, iniConfig, lastValue, path, section, sections, _0, *_4, _5, _1$$3, _2$$3, _3$$3, *_8$$5, _9$$5, _12$$6, _15$$7, _17$$8, _18$$8, _19$$4, *_21$$10, _22$$10, _25$$11, _27$$12, _29$$13, _30$$13, _31$$9;
	zval filePath, _13$$6, _16$$7, _26$$11, _28$$12;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filePath);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_26$$11);
	ZVAL_UNDEF(&_28$$12);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&directives);
	ZVAL_UNDEF(&iniConfig);
	ZVAL_UNDEF(&lastValue);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&section);
	ZVAL_UNDEF(&sections);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$4);
	ZVAL_UNDEF(&_22$$10);
	ZVAL_UNDEF(&_25$$11);
	ZVAL_UNDEF(&_27$$12);
	ZVAL_UNDEF(&_29$$13);
	ZVAL_UNDEF(&_30$$13);
	ZVAL_UNDEF(&_31$$9);
	ZVAL_UNDEF(&config);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(filePath)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(mode)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &filePath_param, &mode_param);
	zephir_get_strval(&filePath, filePath_param);
	if (!mode_param) {
		mode = 1;
	} else {
		mode = zephir_get_intval(mode_param);
	}


	ZVAL_LONG(&_0, mode);
	ZEPHIR_CALL_FUNCTION(&iniConfig, "parse_ini_file", NULL, 192, &filePath, &__$true, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&iniConfig))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_config_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_basename(&_2$$3, &filePath);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SVS(&_3$$3, "Configuration file ", &_2$$3, " cannot be loaded");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 8, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Config/Adapter/Ini.zep", 79);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&config);
	array_init(&config);
	zephir_is_iterable(&iniConfig, 0, "phalcon/Config/Adapter/Ini.zep", 108);
	if (Z_TYPE_P(&iniConfig) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&iniConfig), _6, _7, _4)
		{
			ZEPHIR_INIT_NVAR(&section);
			if (_7 != NULL) { 
				ZVAL_STR_COPY(&section, _7);
			} else {
				ZVAL_LONG(&section, _6);
			}
			ZEPHIR_INIT_NVAR(&directives);
			ZVAL_COPY(&directives, _4);
			if (Z_TYPE_P(&directives) == IS_ARRAY) {
				ZEPHIR_INIT_NVAR(&sections);
				array_init(&sections);
				zephir_is_iterable(&directives, 0, "phalcon/Config/Adapter/Ini.zep", 95);
				if (Z_TYPE_P(&directives) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&directives), _10$$5, _11$$5, _8$$5)
					{
						ZEPHIR_INIT_NVAR(&path);
						if (_11$$5 != NULL) { 
							ZVAL_STR_COPY(&path, _11$$5);
						} else {
							ZVAL_LONG(&path, _10$$5);
						}
						ZEPHIR_INIT_NVAR(&lastValue);
						ZVAL_COPY(&lastValue, _8$$5);
						zephir_cast_to_string(&_13$$6, &path);
						ZEPHIR_CALL_METHOD(&_12$$6, this_ptr, "parseinistring", &_14, 0, &_13$$6, &lastValue);
						zephir_check_call_status();
						zephir_array_append(&sections, &_12$$6, PH_SEPARATE, "phalcon/Config/Adapter/Ini.zep", 92);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &directives, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_9$$5, &directives, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_9$$5)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&path, &directives, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&lastValue, &directives, "current", NULL, 0);
						zephir_check_call_status();
							zephir_cast_to_string(&_16$$7, &path);
							ZEPHIR_CALL_METHOD(&_15$$7, this_ptr, "parseinistring", &_14, 0, &_16$$7, &lastValue);
							zephir_check_call_status();
							zephir_array_append(&sections, &_15$$7, PH_SEPARATE, "phalcon/Config/Adapter/Ini.zep", 92);
						ZEPHIR_CALL_METHOD(NULL, &directives, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&lastValue);
				ZEPHIR_INIT_NVAR(&path);
				if (zephir_fast_count_int(&sections)) {
					ZEPHIR_INIT_NVAR(&_17$$8);
					ZEPHIR_INIT_NVAR(&_18$$8);
					ZVAL_STRING(&_18$$8, "array_replace_recursive");
					ZEPHIR_CALL_USER_FUNC_ARRAY(&_17$$8, &_18$$8, &sections);
					zephir_check_call_status();
					zephir_array_update_zval(&config, &section, &_17$$8, PH_COPY | PH_SEPARATE);
				}
				continue;
			}
			ZEPHIR_CALL_METHOD(&_19$$4, this_ptr, "cast", &_20, 0, &directives);
			zephir_check_call_status();
			zephir_array_update_zval(&config, &section, &_19$$4, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &iniConfig, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &iniConfig, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&section, &iniConfig, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&directives, &iniConfig, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&directives) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&sections);
					array_init(&sections);
					zephir_is_iterable(&directives, 0, "phalcon/Config/Adapter/Ini.zep", 95);
					if (Z_TYPE_P(&directives) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&directives), _23$$10, _24$$10, _21$$10)
						{
							ZEPHIR_INIT_NVAR(&path);
							if (_24$$10 != NULL) { 
								ZVAL_STR_COPY(&path, _24$$10);
							} else {
								ZVAL_LONG(&path, _23$$10);
							}
							ZEPHIR_INIT_NVAR(&lastValue);
							ZVAL_COPY(&lastValue, _21$$10);
							zephir_cast_to_string(&_26$$11, &path);
							ZEPHIR_CALL_METHOD(&_25$$11, this_ptr, "parseinistring", &_14, 0, &_26$$11, &lastValue);
							zephir_check_call_status();
							zephir_array_append(&sections, &_25$$11, PH_SEPARATE, "phalcon/Config/Adapter/Ini.zep", 92);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &directives, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_22$$10, &directives, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_22$$10)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&path, &directives, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&lastValue, &directives, "current", NULL, 0);
							zephir_check_call_status();
								zephir_cast_to_string(&_28$$12, &path);
								ZEPHIR_CALL_METHOD(&_27$$12, this_ptr, "parseinistring", &_14, 0, &_28$$12, &lastValue);
								zephir_check_call_status();
								zephir_array_append(&sections, &_27$$12, PH_SEPARATE, "phalcon/Config/Adapter/Ini.zep", 92);
							ZEPHIR_CALL_METHOD(NULL, &directives, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&lastValue);
					ZEPHIR_INIT_NVAR(&path);
					if (zephir_fast_count_int(&sections)) {
						ZEPHIR_INIT_NVAR(&_29$$13);
						ZEPHIR_INIT_NVAR(&_30$$13);
						ZVAL_STRING(&_30$$13, "array_replace_recursive");
						ZEPHIR_CALL_USER_FUNC_ARRAY(&_29$$13, &_30$$13, &sections);
						zephir_check_call_status();
						zephir_array_update_zval(&config, &section, &_29$$13, PH_COPY | PH_SEPARATE);
					}
					continue;
				}
				ZEPHIR_CALL_METHOD(&_31$$9, this_ptr, "cast", &_20, 0, &directives);
				zephir_check_call_status();
				zephir_array_update_zval(&config, &section, &_31$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &iniConfig, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&directives);
	ZEPHIR_INIT_NVAR(&section);
	ZEPHIR_CALL_PARENT(NULL, phalcon_config_adapter_ini_ce, getThis(), "__construct", &_32, 0, &config);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * We have to cast values manually because parse_ini_file() has a poor
 * implementation.
 *
 * @param mixed $ini
 *
 * @return array|float|int|mixed|string|null
 */
PHP_METHOD(Phalcon_Config_Adapter_Ini, cast)
{
	zend_bool _3;
	zval _0;
	zval castMap;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ini = NULL, ini_sub, __$true, __$false, lowerIni, _1, _2$$5, _4$$6, _5$$6, _6$$6, _7$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ini_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&lowerIni);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&castMap);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(ini)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ini);
	ZEPHIR_SEPARATE_PARAM(ini);


	if (Z_TYPE_P(ini) == IS_ARRAY) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "castarray", NULL, 0, ini);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_cast_to_string(&_0, ini);
	ZEPHIR_CPY_WRT(ini, &_0);
	ZEPHIR_INIT_VAR(&lowerIni);
	zephir_fast_strtolower(&lowerIni, ini);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "null");
	if (ZEPHIR_IS_IDENTICAL(&_1, &lowerIni)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&castMap);
	zephir_create_array(&castMap, 6, 0);
	zephir_array_update_string(&castMap, SL("on"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&castMap, SL("true"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&castMap, SL("yes"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&castMap, SL("off"), &__$false, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&castMap, SL("no"), &__$false, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&castMap, SL("false"), &__$false, PH_COPY | PH_SEPARATE);
	if (1 == zephir_array_isset(&castMap, &lowerIni)) {
		zephir_array_fetch(&_2$$5, &castMap, &lowerIni, PH_NOISY | PH_READONLY, "phalcon/Config/Adapter/Ini.zep", 147);
		RETURN_CTOR(&_2$$5);
	}
	_3 = Z_TYPE_P(ini) == IS_STRING;
	if (_3) {
		_3 = zephir_is_numeric(ini);
	}
	if (_3) {
		ZEPHIR_INIT_VAR(&_4$$6);
		ZEPHIR_INIT_VAR(&_5$$6);
		ZVAL_STRING(&_5$$6, "/[.]+/");
		ZEPHIR_INIT_VAR(&_6$$6);
		ZEPHIR_INIT_VAR(&_7$$6);
		ZVAL_STRING(&_7$$6, "/[.]+/");
		zephir_preg_match(&_6$$6, &_7$$6, ini, &_4$$6, 0, 0 , 0 );
		if (zephir_is_true(&_6$$6)) {
			RETURN_MM_DOUBLE(zephir_get_doubleval(ini));
		}
		RETURN_MM_LONG(zephir_get_intval(ini));
	}
	RETVAL_ZVAL(ini, 1, 0);
	RETURN_MM();
}

/**
 * @param array $ini
 *
 * @return array
 */
PHP_METHOD(Phalcon_Config_Adapter_Ini, castArray)
{
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ini_param = NULL, key, value, *_0, _1, _4$$3, _6$$4;
	zval ini;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ini);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(ini)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ini_param);
	zephir_get_arrval(&ini, ini_param);


	zephir_is_iterable(&ini, 1, "phalcon/Config/Adapter/Ini.zep", 175);
	if (Z_TYPE_P(&ini) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&ini), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "cast", &_5, 0, &value);
			zephir_check_call_status();
			zephir_array_update_zval(&ini, &key, &_4$$3, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &ini, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &ini, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &ini, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &ini, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "cast", &_5, 0, &value);
				zephir_check_call_status();
				zephir_array_update_zval(&ini, &key, &_6$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &ini, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CTOR(&ini);
}

/**
 * Build multidimensional array from string
 *
 * @param string $path
 * @param mixed  $value
 *
 * @return array
 */
PHP_METHOD(Phalcon_Config_Adapter_Ini, parseIniString)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *value, value_sub, castValue, key, position, result, _0, _1, _2, _3;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&castValue);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(path)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &path_param, &value);
	zephir_get_strval(&path, path_param);


	ZEPHIR_CALL_METHOD(&castValue, this_ptr, "cast", NULL, 0, value);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, ".");
	ZEPHIR_INIT_VAR(&position);
	zephir_fast_strpos(&position, &path, &_0, 0 );
	if (ZEPHIR_IS_FALSE_IDENTICAL(&position)) {
		zephir_create_array(return_value, 1, 0);
		zephir_array_update_zval(return_value, &path, &castValue, PH_COPY);
		RETURN_MM();
	}
	ZVAL_LONG(&_1, 0);
	ZEPHIR_INIT_VAR(&key);
	zephir_substr(&key, &path, 0 , zephir_get_intval(&position), 0);
	ZVAL_LONG(&_2, (zephir_get_numberval(&position) + 1));
	ZEPHIR_INIT_VAR(&_3);
	zephir_substr(&_3, &path, zephir_get_intval(&_2), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	zephir_get_strval(&path, &_3);
	ZEPHIR_CALL_METHOD(&result, this_ptr, "parseinistring", NULL, 193, &path, &castValue);
	zephir_check_call_status();
	zephir_create_array(return_value, 1, 0);
	zephir_array_update_zval(return_value, &key, &result, PH_COPY);
	RETURN_MM();
}

