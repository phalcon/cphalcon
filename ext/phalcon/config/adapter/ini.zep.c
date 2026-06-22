
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
	zval _11$$6, _16$$7, _27$$11, _31$$12;
	zend_bool _22, _14$$5, _29$$10;
	zend_ulong _5, _8$$5, _24$$10;
	zval config;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_12 = NULL, *_20 = NULL;
	zend_long mode, ZEPHIR_LAST_CALL_STATUS;
	zval filePath_zv, *mode_param = NULL, directives, iniConfig, lastValue, path, section, sections, _0, _1, *_4, _21, _2$$3, _3$$3, *_7$$5, _13$$5, _10$$6, _15$$7, _17$$8, _18$$8, _19$$4, *_23$$10, _28$$10, _26$$11, _30$$12, _32$$13, _33$$13, _34$$9;
	zend_string *filePath = NULL, *_6, *_9$$5, *_25$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filePath_zv);
	ZVAL_UNDEF(&directives);
	ZVAL_UNDEF(&iniConfig);
	ZVAL_UNDEF(&lastValue);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&section);
	ZVAL_UNDEF(&sections);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$4);
	ZVAL_UNDEF(&_28$$10);
	ZVAL_UNDEF(&_26$$11);
	ZVAL_UNDEF(&_30$$12);
	ZVAL_UNDEF(&_32$$13);
	ZVAL_UNDEF(&_33$$13);
	ZVAL_UNDEF(&_34$$9);
	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_27$$11);
	ZVAL_UNDEF(&_31$$12);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(filePath)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(mode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		mode_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&filePath_zv);
	ZVAL_STR_COPY(&filePath_zv, filePath);
	if (!mode_param) {
		mode = 1;
	} else {
		}
	ZVAL_BOOL(&_0, 1);
	ZVAL_LONG(&_1, mode);
	ZEPHIR_CALL_METHOD(&iniConfig, this_ptr, "phpparseinifile", NULL, 0, &filePath_zv, &_0, &_1);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&iniConfig))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_config_exceptions_cannotloadconfigfile_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_basename(&_3$$3, &filePath_zv);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 375, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Config/Adapter/Ini.zep", 77);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&config);
	array_init(&config);
	zephir_is_iterable(&iniConfig, 0, "phalcon/Config/Adapter/Ini.zep", 106);
	if (Z_TYPE_P(&iniConfig) == IS_ARRAY) {
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
				zephir_is_iterable(&directives, 0, "phalcon/Config/Adapter/Ini.zep", 93);
				if (Z_TYPE_P(&directives) == IS_ARRAY) {
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
						zephir_cast_to_string(&_11$$6, &path);
						ZEPHIR_CALL_METHOD(&_10$$6, this_ptr, "parseinistring", &_12, 0, &_11$$6, &lastValue);
						zephir_check_call_status();
						zephir_array_append(&sections, &_10$$6, PH_SEPARATE, "phalcon/Config/Adapter/Ini.zep", 90);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &directives, "rewind", NULL, 0);
					zephir_check_call_status();
					_14$$5 = 1;
					while (1) {
						if (_14$$5) {
							_14$$5 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &directives, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_13$$5, &directives, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_13$$5)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&path, &directives, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&lastValue, &directives, "current", NULL, 0);
						zephir_check_call_status();
							zephir_cast_to_string(&_16$$7, &path);
							ZEPHIR_CALL_METHOD(&_15$$7, this_ptr, "parseinistring", &_12, 0, &_16$$7, &lastValue);
							zephir_check_call_status();
							zephir_array_append(&sections, &_15$$7, PH_SEPARATE, "phalcon/Config/Adapter/Ini.zep", 90);
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
		_22 = 1;
		while (1) {
			if (_22) {
				_22 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &iniConfig, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_21, &iniConfig, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_21)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&section, &iniConfig, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&directives, &iniConfig, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&directives) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&sections);
					array_init(&sections);
					zephir_is_iterable(&directives, 0, "phalcon/Config/Adapter/Ini.zep", 93);
					if (Z_TYPE_P(&directives) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&directives), _24$$10, _25$$10, _23$$10)
						{
							ZEPHIR_INIT_NVAR(&path);
							if (_25$$10 != NULL) { 
								ZVAL_STR_COPY(&path, _25$$10);
							} else {
								ZVAL_LONG(&path, _24$$10);
							}
							ZEPHIR_INIT_NVAR(&lastValue);
							ZVAL_COPY(&lastValue, _23$$10);
							zephir_cast_to_string(&_27$$11, &path);
							ZEPHIR_CALL_METHOD(&_26$$11, this_ptr, "parseinistring", &_12, 0, &_27$$11, &lastValue);
							zephir_check_call_status();
							zephir_array_append(&sections, &_26$$11, PH_SEPARATE, "phalcon/Config/Adapter/Ini.zep", 90);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &directives, "rewind", NULL, 0);
						zephir_check_call_status();
						_29$$10 = 1;
						while (1) {
							if (_29$$10) {
								_29$$10 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, &directives, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_28$$10, &directives, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_28$$10)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&path, &directives, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&lastValue, &directives, "current", NULL, 0);
							zephir_check_call_status();
								zephir_cast_to_string(&_31$$12, &path);
								ZEPHIR_CALL_METHOD(&_30$$12, this_ptr, "parseinistring", &_12, 0, &_31$$12, &lastValue);
								zephir_check_call_status();
								zephir_array_append(&sections, &_30$$12, PH_SEPARATE, "phalcon/Config/Adapter/Ini.zep", 90);
						}
					}
					ZEPHIR_INIT_NVAR(&lastValue);
					ZEPHIR_INIT_NVAR(&path);
					if (zephir_fast_count_int(&sections)) {
						ZEPHIR_INIT_NVAR(&_32$$13);
						ZEPHIR_INIT_NVAR(&_33$$13);
						ZVAL_STRING(&_33$$13, "array_replace_recursive");
						ZEPHIR_CALL_USER_FUNC_ARRAY(&_32$$13, &_33$$13, &sections);
						zephir_check_call_status();
						zephir_array_update_zval(&config, &section, &_32$$13, PH_COPY | PH_SEPARATE);
					}
					continue;
				}
				ZEPHIR_CALL_METHOD(&_34$$9, this_ptr, "cast", &_20, 0, &directives);
				zephir_check_call_status();
				zephir_array_update_zval(&config, &section, &_34$$9, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&directives);
	ZEPHIR_INIT_NVAR(&section);
	ZEPHIR_CALL_PARENT(NULL, phalcon_config_adapter_ini_ce, getThis(), "__construct", NULL, 0, &config);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * We have to cast values manually because parse_ini_file() has a poor
 * implementation.
 *
 * Note: this casting is an ini-format compensation and is deliberately
 * specific to this adapter. Ini files carry untyped strings, so
 * `on/yes/true`, `off/no/false`, `null` and numeric strings are decoded
 * here. The json, yaml and php adapters receive natively typed values
 * from their parsers and perform no casting.
 *
 * @param mixed $ini
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Config_Adapter_Ini, cast)
{
	zval _0;
	zval castMap;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ini = NULL, ini_sub, __$true, __$false, lowerIni, _1, _2$$5, _3$$6, _4$$6, _5$$6, _6$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ini_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&lowerIni);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&castMap);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(ini)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	if (1 == zephir_array_isset_value(&castMap, &lowerIni)) {
		zephir_array_fetch(&_2$$5, &castMap, &lowerIni, PH_NOISY | PH_READONLY, "phalcon/Config/Adapter/Ini.zep", 151);
		RETURN_CTOR(&_2$$5);
	}
	if (zephir_is_numeric(ini)) {
		ZEPHIR_INIT_VAR(&_3$$6);
		ZEPHIR_INIT_VAR(&_4$$6);
		ZVAL_STRING(&_4$$6, "/[.]+/");
		ZEPHIR_INIT_VAR(&_5$$6);
		ZEPHIR_INIT_VAR(&_6$$6);
		ZVAL_STRING(&_6$$6, "/[.]+/");
		zephir_preg_match(&_5$$6, &_6$$6, ini, &_3$$6, 0, 0 , 0 );
		if (zephir_is_true(&_5$$6)) {
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
	zend_bool _6;
	zend_string *_2;
	zend_ulong _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ini_param = NULL, key, value, *_0, _5, _3$$3, _7$$4;
	zval ini;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ini);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_7$$4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(ini, ini_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &ini_param);
	zephir_get_arrval(&ini, ini_param);
	zephir_is_iterable(&ini, 1, "phalcon/Config/Adapter/Ini.zep", 179);
	if (Z_TYPE_P(&ini) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&ini), _1, _2, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_2 != NULL) { 
				ZVAL_STR_COPY(&key, _2);
			} else {
				ZVAL_LONG(&key, _1);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "cast", &_4, 0, &value);
			zephir_check_call_status();
			zephir_array_update_zval(&ini, &key, &_3$$3, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &ini, "rewind", NULL, 0);
		zephir_check_call_status();
		_6 = 1;
		while (1) {
			if (_6) {
				_6 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &ini, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_5, &ini, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &ini, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &ini, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_7$$4, this_ptr, "cast", &_4, 0, &value);
				zephir_check_call_status();
				zephir_array_update_zval(&ini, &key, &_7$$4, PH_COPY | PH_SEPARATE);
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
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(path_param)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	ZEPHIR_CALL_METHOD(&result, this_ptr, "parseinistring", NULL, 376, &path, &castValue);
	zephir_check_call_status();
	zephir_create_array(return_value, 1, 0);
	zephir_array_update_zval(return_value, &key, &result, PH_COPY);
	RETURN_MM();
}

/**
 * @todo to be removed when we get traits
 */
PHP_METHOD(Phalcon_Config_Adapter_Ini, phpParseIniFile)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long scannerMode, ZEPHIR_LAST_CALL_STATUS;
	zend_bool processSections;
	zval filename_zv, *processSections_param = NULL, *scannerMode_param = NULL, _0, _1;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(filename)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(processSections)
		Z_PARAM_LONG(scannerMode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		processSections_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		scannerMode_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!processSections_param) {
		processSections = 0;
	} else {
		}
	if (!scannerMode_param) {
		scannerMode = 1;
	} else {
		}
	ZVAL_BOOL(&_0, (processSections ? 1 : 0));
	ZVAL_LONG(&_1, scannerMode);
	ZEPHIR_RETURN_CALL_FUNCTION("parse_ini_file", NULL, 377, &filename_zv, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

