
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
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
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
 *
 * @phpstan-import-type config_data from ConfigTypes
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
	zval _15$$6, _19$$7, _31$$11, _35$$12;
	zend_bool _24, _17$$5, _33$$10;
	zend_ulong _7, _12$$5, _28$$10;
	zval config;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long mode, ZEPHIR_LAST_CALL_STATUS;
	zval filePath_zv, *mode_param = NULL, directives, iniConfig, lastValue, path, section, sections, _0, _1, *_4, _5, *_6, _23, _2$$3, _3$$3, *_9$$5, _10$$5, *_11$$5, _16$$5, _14$$6, _18$$7, _20$$8, _21$$8, _22$$4, *_25$$10, _26$$10, *_27$$10, _32$$10, _30$$11, _34$$12, _36$$13, _37$$13, _38$$9;
	zend_string *filePath = NULL, *_8, *_13$$5, *_29$$10;
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
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_22$$4);
	ZVAL_UNDEF(&_26$$10);
	ZVAL_UNDEF(&_32$$10);
	ZVAL_UNDEF(&_30$$11);
	ZVAL_UNDEF(&_34$$12);
	ZVAL_UNDEF(&_36$$13);
	ZVAL_UNDEF(&_37$$13);
	ZVAL_UNDEF(&_38$$9);
	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_31$$11);
	ZVAL_UNDEF(&_35$$12);
	ZEND_TLS zephir_method_cache _zephir_call_cache[24];
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
	ZEPHIR_CALL_METHOD_CACHED(&iniConfig, this_ptr, "phpParseIniFile", &_zephir_call_cache[0], &filePath_zv, &_0, &_1);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&iniConfig))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_config_exceptions_cannotloadconfigfile_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_basename(&_3$$3, &filePath_zv);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_2$$3, "__construct", &_zephir_call_cache[1], &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Config/Adapter/Ini.zep", 83);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&config);
	array_init(&config);
	if (Z_TYPE_P(&iniConfig) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_5);
		zephir_string_to_char_array(&_5, &iniConfig);
		_4 = &_5;
	} else {
		_4 = &iniConfig;
	}
	zephir_is_iterable(_4, 0, "phalcon/Config/Adapter/Ini.zep", 112);
	if (Z_TYPE_P(_4) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_4), _7, _8, _6)
		{
			ZEPHIR_INIT_NVAR(&section);
			if (_8 != NULL) { 
				ZVAL_STR_COPY(&section, _8);
			} else {
				ZVAL_LONG(&section, _7);
			}
			ZEPHIR_INIT_NVAR(&directives);
			ZVAL_COPY(&directives, _6);
			if (Z_TYPE_P(&directives) == IS_ARRAY) {
				ZEPHIR_INIT_NVAR(&sections);
				array_init(&sections);
				if (Z_TYPE_P(&directives) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_10$$5);
					zephir_string_to_char_array(&_10$$5, &directives);
					_9$$5 = &_10$$5;
				} else {
					_9$$5 = &directives;
				}
				zephir_is_iterable(_9$$5, 0, "phalcon/Config/Adapter/Ini.zep", 99);
				if (Z_TYPE_P(_9$$5) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_9$$5), _12$$5, _13$$5, _11$$5)
					{
						ZEPHIR_INIT_NVAR(&path);
						if (_13$$5 != NULL) { 
							ZVAL_STR_COPY(&path, _13$$5);
						} else {
							ZVAL_LONG(&path, _12$$5);
						}
						ZEPHIR_INIT_NVAR(&lastValue);
						ZVAL_COPY(&lastValue, _11$$5);
						zephir_cast_to_string(&_15$$6, &path);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD_CACHED(&_14$$6, this_ptr, "parseIniString", &_zephir_call_cache[2], &_15$$6, &lastValue);
						zephir_check_call_status();
						zephir_array_append(&sections, &_14$$6, PH_SEPARATE, "phalcon/Config/Adapter/Ini.zep", 96);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _9$$5, "rewind", &_zephir_call_cache[3]);
					zephir_check_call_status();
					_17$$5 = 1;
					while (1) {
						if (_17$$5) {
							_17$$5 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _9$$5, "next", &_zephir_call_cache[4]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_16$$5, _9$$5, "valid", &_zephir_call_cache[5]);
						zephir_check_call_status();
						if (!zend_is_true(&_16$$5)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&path, _9$$5, "key", &_zephir_call_cache[6]);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD_CACHED(&lastValue, _9$$5, "current", &_zephir_call_cache[7]);
						zephir_check_call_status();
							zephir_cast_to_string(&_19$$7, &path);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CALL_METHOD_CACHED(&_18$$7, this_ptr, "parseIniString", &_zephir_call_cache[8], &_19$$7, &lastValue);
							zephir_check_call_status();
							zephir_array_append(&sections, &_18$$7, PH_SEPARATE, "phalcon/Config/Adapter/Ini.zep", 96);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
					}
				}
				ZEPHIR_INIT_NVAR(&lastValue);
				ZEPHIR_INIT_NVAR(&path);
				if (!(ZEPHIR_IS_EMPTY(&sections))) {
					ZEPHIR_INIT_NVAR(&_20$$8);
					ZEPHIR_INIT_NVAR(&_21$$8);
					ZVAL_STRING(&_21$$8, "array_replace_recursive");
					ZEPHIR_CALL_USER_FUNC_ARRAY(&_20$$8, &_21$$8, &sections);
					zephir_check_call_status();
					zephir_array_update_zval(&config, &section, &_20$$8, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				continue;
			}
			ZEPHIR_CALL_METHOD_CACHED(&_22$$4, this_ptr, "cast", &_zephir_call_cache[9], &directives);
			zephir_check_call_status();
			zephir_array_update_zval(&config, &section, &_22$$4, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _4, "rewind", &_zephir_call_cache[10]);
		zephir_check_call_status();
		_24 = 1;
		while (1) {
			if (_24) {
				_24 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _4, "next", &_zephir_call_cache[11]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_23, _4, "valid", &_zephir_call_cache[12]);
			zephir_check_call_status();
			if (!zend_is_true(&_23)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&section, _4, "key", &_zephir_call_cache[13]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&directives, _4, "current", &_zephir_call_cache[14]);
			zephir_check_call_status();
				if (Z_TYPE_P(&directives) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&sections);
					array_init(&sections);
					if (Z_TYPE_P(&directives) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_26$$10);
						zephir_string_to_char_array(&_26$$10, &directives);
						_25$$10 = &_26$$10;
					} else {
						_25$$10 = &directives;
					}
					zephir_is_iterable(_25$$10, 0, "phalcon/Config/Adapter/Ini.zep", 99);
					if (Z_TYPE_P(_25$$10) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_25$$10), _28$$10, _29$$10, _27$$10)
						{
							ZEPHIR_INIT_NVAR(&path);
							if (_29$$10 != NULL) { 
								ZVAL_STR_COPY(&path, _29$$10);
							} else {
								ZVAL_LONG(&path, _28$$10);
							}
							ZEPHIR_INIT_NVAR(&lastValue);
							ZVAL_COPY(&lastValue, _27$$10);
							zephir_cast_to_string(&_31$$11, &path);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CALL_METHOD_CACHED(&_30$$11, this_ptr, "parseIniString", &_zephir_call_cache[15], &_31$$11, &lastValue);
							zephir_check_call_status();
							zephir_array_append(&sections, &_30$$11, PH_SEPARATE, "phalcon/Config/Adapter/Ini.zep", 96);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _25$$10, "rewind", &_zephir_call_cache[16]);
						zephir_check_call_status();
						_33$$10 = 1;
						while (1) {
							if (_33$$10) {
								_33$$10 = 0;
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _25$$10, "next", &_zephir_call_cache[17]);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD_CACHED(&_32$$10, _25$$10, "valid", &_zephir_call_cache[18]);
							zephir_check_call_status();
							if (!zend_is_true(&_32$$10)) {
								break;
							}
							ZEPHIR_CALL_METHOD_CACHED(&path, _25$$10, "key", &_zephir_call_cache[19]);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD_CACHED(&lastValue, _25$$10, "current", &_zephir_call_cache[20]);
							zephir_check_call_status();
								zephir_cast_to_string(&_35$$12, &path);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_CALL_METHOD_CACHED(&_34$$12, this_ptr, "parseIniString", &_zephir_call_cache[21], &_35$$12, &lastValue);
								zephir_check_call_status();
								zephir_array_append(&sections, &_34$$12, PH_SEPARATE, "phalcon/Config/Adapter/Ini.zep", 96);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
						}
					}
					ZEPHIR_INIT_NVAR(&lastValue);
					ZEPHIR_INIT_NVAR(&path);
					if (!(ZEPHIR_IS_EMPTY(&sections))) {
						ZEPHIR_INIT_NVAR(&_36$$13);
						ZEPHIR_INIT_NVAR(&_37$$13);
						ZVAL_STRING(&_37$$13, "array_replace_recursive");
						ZEPHIR_CALL_USER_FUNC_ARRAY(&_36$$13, &_37$$13, &sections);
						zephir_check_call_status();
						zephir_array_update_zval(&config, &section, &_36$$13, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					continue;
				}
				ZEPHIR_CALL_METHOD_CACHED(&_38$$9, this_ptr, "cast", &_zephir_call_cache[22], &directives);
				zephir_check_call_status();
				zephir_array_update_zval(&config, &section, &_38$$9, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&directives);
	ZEPHIR_INIT_NVAR(&section);
	ZEPHIR_CALL_PARENT_CACHED(NULL, phalcon_config_adapter_ini_ce, getThis(), "__construct", &_zephir_call_cache[23], &config);
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
	zend_bool _2;
	zval _0;
	zval castMap;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ini = NULL, ini_sub, __$true, __$false, lowerIni, _1, _3$$5, _4$$6, _5$$6, _6$$6, _7$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ini_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&lowerIni);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&castMap);
	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(ini)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &ini);
	ZEPHIR_SEPARATE_PARAM(ini);
	if (Z_TYPE_P(ini) == IS_ARRAY) {
		ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "castArray", &_zephir_call_cache[0], ini);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_cast_to_string(&_0, ini);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
	_2 = zephir_array_isset_value(&castMap, &lowerIni);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (1 == _2) {
		zephir_array_fetch(&_3$$5, &castMap, &lowerIni, PH_NOISY | PH_READONLY, "phalcon/Config/Adapter/Ini.zep", 157);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_CTOR(&_3$$5);
	}
	if (zephir_is_numeric(ini)) {
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
	zend_bool _5;
	zend_string *_2;
	zend_ulong _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ini_param = NULL, key, value, *_0, _4, _3$$3, _6$$4;
	zval ini;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ini);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_6$$4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[7];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(ini, ini_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &ini_param);
	zephir_get_arrval(&ini, ini_param);
	zephir_is_iterable(&ini, 1, "phalcon/Config/Adapter/Ini.zep", 185);
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
			ZEPHIR_CALL_METHOD_CACHED(&_3$$3, this_ptr, "cast", &_zephir_call_cache[0], &value);
			zephir_check_call_status();
			zephir_array_update_zval(&ini, &key, &_3$$3, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &ini, "rewind", &_zephir_call_cache[1]);
		zephir_check_call_status();
		_5 = 1;
		while (1) {
			if (_5) {
				_5 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &ini, "next", &_zephir_call_cache[2]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_4, &ini, "valid", &_zephir_call_cache[3]);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&key, &ini, "key", &_zephir_call_cache[4]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&value, &ini, "current", &_zephir_call_cache[5]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_6$$4, this_ptr, "cast", &_zephir_call_cache[6], &value);
				zephir_check_call_status();
				zephir_array_update_zval(&ini, &key, &_6$$4, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CTOR(&ini);
}

/**
 * Build multidimensional array from string
 *
 * @param mixed $value
 *
 * @phpstan-return config_data
 */
PHP_METHOD(Phalcon_Config_Adapter_Ini, parseIniString)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *value, value_sub, castValue, key, position, result, _0, _1, _2, _3, _4;
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
	ZVAL_UNDEF(&_4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(path_param)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &path_param, &value);
	zephir_get_strval(&path, path_param);
	ZEPHIR_CALL_METHOD_CACHED(&castValue, this_ptr, "cast", &_zephir_call_cache[0], value);
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
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_LONG(&_2, 1);
	ZEPHIR_INIT_VAR(&_3);
	zephir_add_function(&_3, &position, &_2);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_4);
	zephir_substr(&_4, &path, zephir_get_intval(&_3), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	zephir_get_strval(&path, &_4);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&result, this_ptr, "parseIniString", &_zephir_call_cache[1], &path, &castValue);
	zephir_check_call_status();
	zephir_create_array(return_value, 1, 0);
	zephir_array_update_zval(return_value, &key, &result, PH_COPY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

/**
 * Gets the value of a configuration option
 *
 * @param string $input
 * @param string $defaultValue
 *
 * @return string
 *
 * @link https://php.net/manual/en/function.ini-get.php
 * @link https://php.net/manual/en/ini.list.php
 */
PHP_METHOD(Phalcon_Config_Adapter_Ini, phpIniGet)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval input_zv, defaultValue_zv, value;
	zend_string *input = NULL, *defaultValue = NULL;

	ZVAL_UNDEF(&input_zv);
	ZVAL_UNDEF(&defaultValue_zv);
	ZVAL_UNDEF(&value);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(input)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&input_zv);
	ZVAL_STR_COPY(&input_zv, input);
	if (!defaultValue) {
		defaultValue = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&defaultValue_zv);
		ZVAL_STR(&defaultValue_zv, defaultValue);
	} else {
		zephir_memory_observe(&defaultValue_zv);
	ZVAL_STR_COPY(&defaultValue_zv, defaultValue);
	}
	ZEPHIR_CALL_FUNCTION(&value, "ini_get", NULL, 111, &input_zv);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&value)) {
		RETURN_MM_STR(zend_string_copy(defaultValue));
	}
	RETURN_CCTOR(&value);
}

/**
 * Query a php.ini value and return it back as boolean
 *
 * @param string $input
 * @param bool   $defaultValue
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.ini-get.php
 * @link https://php.net/manual/en/ini.list.php
 */
PHP_METHOD(Phalcon_Config_Adapter_Ini, phpIniGetBool)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool defaultValue, result;
	zval input_zv, *defaultValue_param = NULL, value, _0;
	zend_string *input = NULL;

	ZVAL_UNDEF(&input_zv);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(input)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		defaultValue_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&input_zv);
	ZVAL_STR_COPY(&input_zv, input);
	if (!defaultValue_param) {
		defaultValue = 0;
	} else {
		}
	result = 0;
	ZEPHIR_CALL_FUNCTION(&value, "ini_get", NULL, 111, &input_zv);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&value)) {
		RETURN_MM_BOOL(defaultValue);
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtolower(&_0, &value);
	if (ZEPHIR_IS_STRING(&_0, "true")) { goto zephir_switch_0_clause_0; }
	if (ZEPHIR_IS_STRING(&_0, "on")) { goto zephir_switch_0_clause_1; }
	if (ZEPHIR_IS_STRING(&_0, "yes")) { goto zephir_switch_0_clause_2; }
	if (ZEPHIR_IS_STRING(&_0, "y")) { goto zephir_switch_0_clause_3; }
	if (ZEPHIR_IS_STRING(&_0, "1")) { goto zephir_switch_0_clause_4; }
	goto zephir_switch_0_end;
	zephir_switch_0_clause_0: ;
	zephir_switch_0_clause_1: ;
	zephir_switch_0_clause_2: ;
	zephir_switch_0_clause_3: ;
	zephir_switch_0_clause_4: ;
		result = 1;
	zephir_switch_0_end: ;

	RETURN_MM_BOOL(result);
}

/**
 * Query a php.ini value and return it back as integer
 *
 * @param string $input
 * @param int    $defaultValue
 *
 * @return int
 *
 * @link https://php.net/manual/en/function.ini-get.php
 * @link https://php.net/manual/en/ini.list.php
 */
PHP_METHOD(Phalcon_Config_Adapter_Ini, phpIniGetInt)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long defaultValue, ZEPHIR_LAST_CALL_STATUS;
	zval input_zv, *defaultValue_param = NULL, value;
	zend_string *input = NULL;

	ZVAL_UNDEF(&input_zv);
	ZVAL_UNDEF(&value);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(input)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		defaultValue_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&input_zv);
	ZVAL_STR_COPY(&input_zv, input);
	if (!defaultValue_param) {
		defaultValue = 0;
	} else {
		}
	ZEPHIR_CALL_FUNCTION(&value, "ini_get", NULL, 111, &input_zv);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&value)) {
		RETURN_MM_LONG(defaultValue);
	}
	RETURN_MM_LONG(zephir_get_intval(&value));
}

/**
 * Parse a configuration file
 *
 * @param string $filename
 * @param bool   $processSections
 * @param int    $scannerMode
 *
 * @return array|false
 *
 * @link https://php.net/manual/en/function.parse-ini-file.php
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
		scannerMode = 0;
	} else {
		}
	ZVAL_BOOL(&_0, (processSections ? 1 : 0));
	ZVAL_LONG(&_1, scannerMode);
	ZEPHIR_RETURN_CALL_FUNCTION("parse_ini_file", NULL, 112, &filename_zv, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

