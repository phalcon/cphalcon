
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
ZEPHIR_INIT_CLASS(Phalcon_Config_Adapter_Inis) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Config\\Adapter, Inis, phalcon, config_adapter_inis, phalcon_config_ce, phalcon_config_adapter_inis_method_entry, 0);

	return SUCCESS;

}

/**
 * Phalcon\Config\Adapter\Ini constructor
 */
PHP_METHOD(Phalcon_Config_Adapter_Inis, __construct) {

	zend_string *_7, *_10$$5;
	zend_ulong _6, _9$$5;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_14 = NULL, *_17 = NULL;
	zval *filePath_param = NULL, __$true, iniConfig, iniConfigRaw, _1, config, section, sections, directives, path, lastValue, *_5, _2$$3, _3$$3, _4$$3, *_8$$5, _11$$6, _12$$6, _13$$6, _15$$7, _16$$7;
	zval filePath;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&filePath);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&iniConfig);
	ZVAL_UNDEF(&iniConfigRaw);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&section);
	ZVAL_UNDEF(&sections);
	ZVAL_UNDEF(&directives);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&lastValue);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);

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


	ZEPHIR_CALL_FUNCTION(&iniConfig, "parse_ini_file", &_0, 135, &filePath, &__$true);
	zephir_check_call_status();
	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_FUNCTION(&iniConfigRaw, "parse_ini_file", &_0, 135, &filePath, &__$true, &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&iniConfig)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_config_exception_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_basename(&_3$$3, &filePath TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_CONCAT_SVS(&_4$$3, "Configuration file ", &_3$$3, " can't be loaded");
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 9, &_4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/config/adapter/inis.zep", 69 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&config);
	array_init(&config);
	zephir_is_iterable(&iniConfig, 0, "phalcon/config/adapter/inis.zep", 91);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&iniConfig), _6, _7, _5)
	{
		ZEPHIR_INIT_NVAR(&section);
		if (_7 != NULL) { 
			ZVAL_STR_COPY(&section, _7);
		} else {
			ZVAL_LONG(&section, _6);
		}
		ZEPHIR_INIT_NVAR(&directives);
		ZVAL_COPY(&directives, _5);
		if (Z_TYPE_P(&directives) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(&sections);
			array_init(&sections);
			zephir_is_iterable(&directives, 0, "phalcon/config/adapter/inis.zep", 83);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&directives), _9$$5, _10$$5, _8$$5)
			{
				ZEPHIR_INIT_NVAR(&path);
				if (_10$$5 != NULL) { 
					ZVAL_STR_COPY(&path, _10$$5);
				} else {
					ZVAL_LONG(&path, _9$$5);
				}
				ZEPHIR_INIT_NVAR(&lastValue);
				ZVAL_COPY(&lastValue, _8$$5);
				zephir_array_fetch(&_11$$6, &iniConfigRaw, &section, PH_NOISY | PH_READONLY, "phalcon/config/adapter/inis.zep", 80 TSRMLS_CC);
				zephir_array_fetch(&_12$$6, &_11$$6, &path, PH_NOISY | PH_READONLY, "phalcon/config/adapter/inis.zep", 80 TSRMLS_CC);
				ZEPHIR_CALL_FUNCTION(&_13$$6, "cast", NULL, 0, &lastValue, &_12$$6);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&lastValue, &_13$$6);
				ZEPHIR_CALL_METHOD(&_13$$6, this_ptr, "_parseinistring", &_14, 0, &path, &lastValue);
				zephir_check_call_status();
				zephir_array_append(&sections, &_13$$6, PH_SEPARATE, "phalcon/config/adapter/inis.zep", 81);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&lastValue);
			ZEPHIR_INIT_NVAR(&path);
			if (zephir_fast_count_int(&sections TSRMLS_CC)) {
				ZEPHIR_INIT_NVAR(&_15$$7);
				ZEPHIR_INIT_NVAR(&_16$$7);
				ZVAL_STRING(&_16$$7, "array_merge_recursive");
				ZEPHIR_CALL_USER_FUNC_ARRAY(&_15$$7, &_16$$7, &sections);
				zephir_check_call_status();
				zephir_array_update_zval(&config, &section, &_15$$7, PH_COPY | PH_SEPARATE);
			}
		} else {
			zephir_array_update_zval(&config, &section, &directives, PH_COPY | PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&directives);
	ZEPHIR_INIT_NVAR(&section);
	ZEPHIR_CALL_PARENT(NULL, phalcon_config_adapter_inis_ce, this_ptr, "__construct", &_17, 16, &config);
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
PHP_METHOD(Phalcon_Config_Adapter_Inis, _parseIniString) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *value, value_sub, pos, key, _0, _1, _2, _3, _4;
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


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, ".");
	ZEPHIR_INIT_VAR(&pos);
	zephir_fast_strpos(&pos, &path, &_0, 0 );
	if (ZEPHIR_IS_FALSE_IDENTICAL(&pos)) {
		zephir_create_array(return_value, 1, 0 TSRMLS_CC);
		zephir_array_update_zval(return_value, &path, value, PH_COPY);
		RETURN_MM();
	}
	ZVAL_LONG(&_1, 0);
	ZEPHIR_INIT_VAR(&key);
	zephir_substr(&key, &path, 0 , zephir_get_intval(&pos), 0);
	ZVAL_LONG(&_2, (zephir_get_numberval(&pos) + 1));
	ZEPHIR_INIT_VAR(&_3);
	zephir_substr(&_3, &path, zephir_get_intval(&_2), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	zephir_get_strval(&path, &_3);
	zephir_create_array(return_value, 1, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "_parseinistring", NULL, 138, &path, value);
	zephir_check_call_status();
	zephir_array_update_zval(return_value, &key, &_4, PH_COPY);
	RETURN_MM();

}

/**
 * We have to cast values manually because parse_ini_file() has a poor implementation.
 *
 * @param mixed ini The array casted by `parse_ini_file`
 * @param mixed raw The same array but with raw strings
 * @return mixed
 */
PHP_METHOD(Phalcon_Config_Adapter_Inis, cast) {

	zend_bool _0$$3, _1$$3, _2$$3, _3$$3, _4$$3, _5$$3, _6$$3;
	zval *ini, ini_sub, *raw, raw_sub, _7$$7, _8$$7, _9$$7;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&ini_sub);
	ZVAL_UNDEF(&raw_sub);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &ini, &raw);



	if (Z_TYPE_P(ini) == IS_STRING) {
		_0$$3 = ZEPHIR_IS_LONG(ini, 1);
		if (_0$$3) {
			_1$$3 = ZEPHIR_IS_STRING_IDENTICAL(raw, "true");
			if (!(_1$$3)) {
				_1$$3 = ZEPHIR_IS_STRING_IDENTICAL(raw, "yes");
			}
			_2$$3 = _1$$3;
			if (!(_2$$3)) {
				_2$$3 = ZEPHIR_IS_STRING_IDENTICAL(raw, "on");
			}
			_0$$3 = _2$$3;
		}
		if (_0$$3) {
			RETURN_MM_BOOL(1);
		}
		_3$$3 = ZEPHIR_IS_STRING_IDENTICAL(ini, "");
		if (_3$$3) {
			_4$$3 = ZEPHIR_IS_STRING_IDENTICAL(raw, "false");
			if (!(_4$$3)) {
				_4$$3 = ZEPHIR_IS_STRING_IDENTICAL(raw, "no");
			}
			_5$$3 = _4$$3;
			if (!(_5$$3)) {
				_5$$3 = ZEPHIR_IS_STRING_IDENTICAL(raw, "off");
			}
			_3$$3 = _5$$3;
		}
		if (_3$$3) {
			RETURN_MM_BOOL(0);
		}
		_6$$3 = ZEPHIR_IS_STRING_IDENTICAL(ini, "");
		if (_6$$3) {
			_6$$3 = ZEPHIR_IS_STRING_IDENTICAL(raw, "null");
		}
		if (_6$$3) {
			RETURN_MM_NULL();
		}
		if (zephir_is_numeric(ini)) {
			ZEPHIR_INIT_VAR(&_7$$7);
			ZEPHIR_INIT_VAR(&_8$$7);
			ZEPHIR_INIT_VAR(&_9$$7);
			ZVAL_STRING(&_9$$7, "/[.]+/");
			zephir_preg_match(&_8$$7, &_9$$7, ini, &_7$$7, 0, 0 , 0  TSRMLS_CC);
			if (zephir_is_true(&_8$$7)) {
				RETURN_MM_DOUBLE(zephir_get_doubleval(ini));
			} else {
				RETURN_MM_LONG(zephir_get_intval(ini));
			}
		}
	}
	RETVAL_ZVAL(ini, 1, 0);
	RETURN_MM();

}

