
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
 * Reads ini files and converts them to Phalcon\Config objects.
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
ZEPHIR_INIT_CLASS(Phalcon_Config_Adapter_Ini) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Config\\Adapter, Ini, phalcon, config_adapter_ini, phalcon_config_ce, phalcon_config_adapter_ini_method_entry, 0);

	return SUCCESS;

}

/**
 * Ini constructor.
 */
PHP_METHOD(Phalcon_Config_Adapter_Ini, __construct) {

	zend_string *_6, *_10$$6, *_23$$12;
	zend_ulong _5, _9$$6, _22$$12;
	zval config;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_13 = NULL, *_19 = NULL, *_31 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filePath_param = NULL, *mode = NULL, mode_sub, __$true, __$null, directives, iniConfig, lastValue, path, section, sections, *_3, _4, _0$$4, _1$$4, _2$$4, *_7$$6, _8$$6, _11$$7, _14$$8, _16$$9, _17$$9, _18$$10, *_20$$12, _21$$12, _24$$13, _26$$14, _28$$15, _29$$15, _30$$16;
	zval filePath, _12$$7, _15$$8, _25$$13, _27$$14;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filePath);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_25$$13);
	ZVAL_UNDEF(&_27$$14);
	ZVAL_UNDEF(&mode_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&directives);
	ZVAL_UNDEF(&iniConfig);
	ZVAL_UNDEF(&lastValue);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&section);
	ZVAL_UNDEF(&sections);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_21$$12);
	ZVAL_UNDEF(&_24$$13);
	ZVAL_UNDEF(&_26$$14);
	ZVAL_UNDEF(&_28$$15);
	ZVAL_UNDEF(&_29$$15);
	ZVAL_UNDEF(&_30$$16);
	ZVAL_UNDEF(&config);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &filePath_param, &mode);

	if (UNEXPECTED(Z_TYPE_P(filePath_param) != IS_STRING && Z_TYPE_P(filePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filePath' must be of the type string"));
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


	if (EXPECTED(Z_TYPE_P(mode) == IS_NULL)) {
		ZEPHIR_INIT_NVAR(mode);
		ZVAL_LONG(mode, 1);
	}
	ZEPHIR_CALL_FUNCTION(&iniConfig, "parse_ini_file", NULL, 169, &filePath, &__$true, mode);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&iniConfig))) {
		ZEPHIR_INIT_VAR(&_0$$4);
		object_init_ex(&_0$$4, phalcon_config_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_basename(&_1$$4, &filePath);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZEPHIR_CONCAT_SVS(&_2$$4, "Configuration file ", &_1$$4, " cannot be loaded");
		ZEPHIR_CALL_METHOD(NULL, &_0$$4, "__construct", NULL, 6, &_2$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$4, "phalcon/Config/Adapter/Ini.zep", 78);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&config);
	array_init(&config);
	zephir_is_iterable(&iniConfig, 0, "phalcon/Config/Adapter/Ini.zep", 105);
	if (Z_TYPE_P(&iniConfig) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&iniConfig), _5, _6, _3)
		{
			ZEPHIR_INIT_NVAR(&section);
			if (_6 != NULL) { 
				ZVAL_STR_COPY(&section, _6);
			} else {
				ZVAL_LONG(&section, _5);
			}
			ZEPHIR_INIT_NVAR(&directives);
			ZVAL_COPY(&directives, _3);
			if (Z_TYPE_P(&directives) == IS_ARRAY) {
				ZEPHIR_INIT_NVAR(&sections);
				array_init(&sections);
				zephir_is_iterable(&directives, 0, "phalcon/Config/Adapter/Ini.zep", 94);
				if (Z_TYPE_P(&directives) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&directives), _9$$6, _10$$6, _7$$6)
					{
						ZEPHIR_INIT_NVAR(&path);
						if (_10$$6 != NULL) { 
							ZVAL_STR_COPY(&path, _10$$6);
						} else {
							ZVAL_LONG(&path, _9$$6);
						}
						ZEPHIR_INIT_NVAR(&lastValue);
						ZVAL_COPY(&lastValue, _7$$6);
						zephir_get_strval(&_12$$7, &path);
						ZEPHIR_CALL_METHOD(&_11$$7, this_ptr, "parseinistring", &_13, 0, &_12$$7, &lastValue);
						zephir_check_call_status();
						zephir_array_append(&sections, &_11$$7, PH_SEPARATE, "phalcon/Config/Adapter/Ini.zep", 91);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &directives, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_8$$6, &directives, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_8$$6)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&path, &directives, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&lastValue, &directives, "current", NULL, 0);
						zephir_check_call_status();
							zephir_get_strval(&_15$$8, &path);
							ZEPHIR_CALL_METHOD(&_14$$8, this_ptr, "parseinistring", &_13, 0, &_15$$8, &lastValue);
							zephir_check_call_status();
							zephir_array_append(&sections, &_14$$8, PH_SEPARATE, "phalcon/Config/Adapter/Ini.zep", 91);
						ZEPHIR_CALL_METHOD(NULL, &directives, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&lastValue);
				ZEPHIR_INIT_NVAR(&path);
				if (zephir_fast_count_int(&sections)) {
					ZEPHIR_INIT_NVAR(&_16$$9);
					ZEPHIR_INIT_NVAR(&_17$$9);
					ZVAL_STRING(&_17$$9, "array_replace_recursive");
					ZEPHIR_CALL_USER_FUNC_ARRAY(&_16$$9, &_17$$9, &sections);
					zephir_check_call_status();
					zephir_array_update_zval(&config, &section, &_16$$9, PH_COPY | PH_SEPARATE);
				}
			} else {
				ZEPHIR_CALL_METHOD(&_18$$10, this_ptr, "cast", &_19, 0, &directives);
				zephir_check_call_status();
				zephir_array_update_zval(&config, &section, &_18$$10, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &iniConfig, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_4, &iniConfig, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&section, &iniConfig, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&directives, &iniConfig, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&directives) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&sections);
					array_init(&sections);
					zephir_is_iterable(&directives, 0, "phalcon/Config/Adapter/Ini.zep", 94);
					if (Z_TYPE_P(&directives) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&directives), _22$$12, _23$$12, _20$$12)
						{
							ZEPHIR_INIT_NVAR(&path);
							if (_23$$12 != NULL) { 
								ZVAL_STR_COPY(&path, _23$$12);
							} else {
								ZVAL_LONG(&path, _22$$12);
							}
							ZEPHIR_INIT_NVAR(&lastValue);
							ZVAL_COPY(&lastValue, _20$$12);
							zephir_get_strval(&_25$$13, &path);
							ZEPHIR_CALL_METHOD(&_24$$13, this_ptr, "parseinistring", &_13, 0, &_25$$13, &lastValue);
							zephir_check_call_status();
							zephir_array_append(&sections, &_24$$13, PH_SEPARATE, "phalcon/Config/Adapter/Ini.zep", 91);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &directives, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_21$$12, &directives, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_21$$12)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&path, &directives, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&lastValue, &directives, "current", NULL, 0);
							zephir_check_call_status();
								zephir_get_strval(&_27$$14, &path);
								ZEPHIR_CALL_METHOD(&_26$$14, this_ptr, "parseinistring", &_13, 0, &_27$$14, &lastValue);
								zephir_check_call_status();
								zephir_array_append(&sections, &_26$$14, PH_SEPARATE, "phalcon/Config/Adapter/Ini.zep", 91);
							ZEPHIR_CALL_METHOD(NULL, &directives, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&lastValue);
					ZEPHIR_INIT_NVAR(&path);
					if (zephir_fast_count_int(&sections)) {
						ZEPHIR_INIT_NVAR(&_28$$15);
						ZEPHIR_INIT_NVAR(&_29$$15);
						ZVAL_STRING(&_29$$15, "array_replace_recursive");
						ZEPHIR_CALL_USER_FUNC_ARRAY(&_28$$15, &_29$$15, &sections);
						zephir_check_call_status();
						zephir_array_update_zval(&config, &section, &_28$$15, PH_COPY | PH_SEPARATE);
					}
				} else {
					ZEPHIR_CALL_METHOD(&_30$$16, this_ptr, "cast", &_19, 0, &directives);
					zephir_check_call_status();
					zephir_array_update_zval(&config, &section, &_30$$16, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &iniConfig, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&directives);
	ZEPHIR_INIT_NVAR(&section);
	ZEPHIR_CALL_PARENT(NULL, phalcon_config_adapter_ini_ce, getThis(), "__construct", &_31, 0, &config);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * We have to cast values manually because parse_ini_file() has a poor
 * implementation.
 */
PHP_METHOD(Phalcon_Config_Adapter_Ini, cast) {

	zend_string *_3$$3;
	zend_ulong _2$$3;
	zend_bool _8;
	zval _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ini = NULL, ini_sub, key, lowerIni, value, *_0$$3, _1$$3, _4$$4, _6$$5, _9$$9, _10$$9, _11$$9, _12$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ini_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&lowerIni);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ini);

	ZEPHIR_SEPARATE_PARAM(ini);


	if (Z_TYPE_P(ini) == IS_ARRAY) {
		zephir_is_iterable(ini, 1, "phalcon/Config/Adapter/Ini.zep", 121);
		if (Z_TYPE_P(ini) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(ini), _2$$3, _3$$3, _0$$3)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_3$$3 != NULL) { 
					ZVAL_STR_COPY(&key, _3$$3);
				} else {
					ZVAL_LONG(&key, _2$$3);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _0$$3);
				ZEPHIR_CALL_METHOD(&_4$$4, this_ptr, "cast", &_5, 170, &value);
				zephir_check_call_status();
				zephir_array_update_zval(ini, &key, &_4$$4, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, ini, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, ini, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, ini, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, ini, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_6$$5, this_ptr, "cast", &_5, 170, &value);
					zephir_check_call_status();
					zephir_array_update_zval(ini, &key, &_6$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, ini, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
		RETVAL_ZVAL(ini, 1, 0);
		RETURN_MM();
	}
	zephir_get_strval(&_7, ini);
	ZEPHIR_CPY_WRT(ini, &_7);
	ZEPHIR_INIT_VAR(&lowerIni);
	zephir_fast_strtolower(&lowerIni, ini);
	do {
		if (ZEPHIR_IS_STRING(&lowerIni, "true") || ZEPHIR_IS_STRING(&lowerIni, "yes") || ZEPHIR_IS_STRING(&lowerIni, "on")) {
			RETURN_MM_BOOL(1);
		}
		if (ZEPHIR_IS_STRING(&lowerIni, "false") || ZEPHIR_IS_STRING(&lowerIni, "no") || ZEPHIR_IS_STRING(&lowerIni, "off")) {
			RETURN_MM_BOOL(0);
		}
		if (ZEPHIR_IS_STRING(&lowerIni, "null")) {
			RETURN_MM_NULL();
		}
	} while(0);

	_8 = Z_TYPE_P(ini) == IS_STRING;
	if (_8) {
		_8 = zephir_is_numeric(ini);
	}
	if (_8) {
		ZEPHIR_INIT_VAR(&_9$$9);
		ZEPHIR_INIT_VAR(&_10$$9);
		ZVAL_STRING(&_10$$9, "/[.]+/");
		ZEPHIR_INIT_VAR(&_11$$9);
		ZEPHIR_INIT_VAR(&_12$$9);
		ZVAL_STRING(&_12$$9, "/[.]+/");
		zephir_preg_match(&_11$$9, &_12$$9, ini, &_9$$9, 0, 0 , 0 );
		if (zephir_is_true(&_11$$9)) {
			RETURN_MM_DOUBLE(zephir_get_doubleval(ini));
		} else {
			RETURN_MM_LONG(zephir_get_intval(ini));
		}
	}
	RETVAL_ZVAL(ini, 1, 0);
	RETURN_MM();

}

/**
 * Build multidimensional array from string
 */
PHP_METHOD(Phalcon_Config_Adapter_Ini, parseIniString) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *value = NULL, value_sub, key, position, _0, _1, _2, _3, _4;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &path_param, &value);

	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(&path, path_param);
	} else {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_EMPTY_STRING(&path);
	}
	ZEPHIR_SEPARATE_PARAM(value);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "cast", NULL, 0, value);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(value, &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, ".");
	ZEPHIR_INIT_VAR(&position);
	zephir_fast_strpos(&position, &path, &_1, 0 );
	if (ZEPHIR_IS_FALSE_IDENTICAL(&position)) {
		zephir_create_array(return_value, 1, 0);
		zephir_array_update_zval(return_value, &path, value, PH_COPY);
		RETURN_MM();
	}
	ZVAL_LONG(&_2, 0);
	ZEPHIR_INIT_VAR(&key);
	zephir_substr(&key, &path, 0 , zephir_get_intval(&position), 0);
	ZVAL_LONG(&_3, (zephir_get_numberval(&position) + 1));
	ZEPHIR_INIT_VAR(&_4);
	zephir_substr(&_4, &path, zephir_get_intval(&_3), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	zephir_get_strval(&path, &_4);
	zephir_create_array(return_value, 1, 0);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "parseinistring", NULL, 171, &path, value);
	zephir_check_call_status();
	zephir_array_update_zval(return_value, &key, &_0, PH_COPY);
	RETURN_MM();

}

