
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Class Syslog
 *
 * @property string $defaultFormatter
 * @property int    $facility
 * @property string $name
 * @property bool   $opened
 * @property int    $option
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Adapter_Syslog)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Logger\\Adapter, Syslog, phalcon, logger_adapter_syslog, phalcon_logger_adapter_abstractadapter_ce, phalcon_logger_adapter_syslog_method_entry, 0);

	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_logger_adapter_syslog_ce, SL("facility"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_logger_adapter_syslog_ce, SL("name"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_logger_adapter_syslog_ce, SL("opened"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_logger_adapter_syslog_ce, SL("option"), 0, ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Syslog constructor.
 *
 * @param string $name
 * @param array  $options
 */
PHP_METHOD(Phalcon_Logger_Adapter_Syslog, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval options;
	zval *name_param = NULL, *options_param = NULL, facility, option;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&facility);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&options);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &options_param);
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_OBS_VAR(&facility);
	if (!(zephir_array_isset_string_fetch(&facility, &options, SL("facility"), 0))) {
		ZEPHIR_INIT_NVAR(&facility);
		ZVAL_LONG(&facility, 8);
	}
	ZEPHIR_OBS_VAR(&option);
	if (!(zephir_array_isset_string_fetch(&option, &options, SL("option"), 0))) {
		ZEPHIR_INIT_NVAR(&option);
		ZVAL_LONG(&option, 4);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &name);
	zephir_update_property_zval(this_ptr, ZEND_STRL("option"), &option);
	zephir_update_property_zval(this_ptr, ZEND_STRL("facility"), &facility);
	ZEPHIR_MM_RESTORE();
}

/**
 * Closes the logger
 */
PHP_METHOD(Phalcon_Logger_Adapter_Syslog, close)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("opened"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_RETURN_CALL_FUNCTION("closelog", NULL, 444);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Processes the message i.e. writes it to the syslog
 *
 * @param Item $item
 *
 * @throws LogicException
 */
PHP_METHOD(Phalcon_Logger_Adapter_Syslog, process)
{
	zval _6$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *item, item_sub, __$true, __$false, level, message, result, _0, _1, _2, _9, _3$$3, _4$$3, _5$$3, _7$$3, _8$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&level);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_6$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(item, phalcon_logger_item_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &item);


	ZEPHIR_CALL_METHOD(&message, this_ptr, "getformatteditem", NULL, 0, item);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("facility"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&result, this_ptr, "openlog", NULL, 0, &_0, &_1, &_2);
	zephir_check_call_status();
	if (!zephir_is_true(&result)) {
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, spl_ce_LogicException);
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&_5$$3);
		zephir_read_property(&_5$$3, this_ptr, ZEND_STRL("facility"), PH_NOISY_CC);
		zephir_cast_to_string(&_6$$3, &_5$$3);
		ZEPHIR_INIT_VAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "Cannot open syslog for name [%s] and facility [%s]");
		ZEPHIR_CALL_FUNCTION(&_8$$3, "sprintf", NULL, 139, &_7$$3, &_4$$3, &_6$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 443, &_8$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "phalcon/Logger/Adapter/Syslog.zep", 106);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (1) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("opened"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("opened"), &__$false);
	}
	ZEPHIR_CALL_METHOD(&_9, item, "getlevel", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&level, this_ptr, "logleveltosyslog", NULL, 445, &_9);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "syslog", NULL, 446, &level, &message);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Open connection to system logger
 *
 * @link https://php.net/manual/en/function.openlog.php
 *
 * @param string $ident
 * @param int    $option
 * @param int    $facility
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Logger_Adapter_Syslog, openlog)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long option, facility, ZEPHIR_LAST_CALL_STATUS;
	zval *ident_param = NULL, *option_param = NULL, *facility_param = NULL, _0, _1;
	zval ident;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ident);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(ident)
		Z_PARAM_LONG(option)
		Z_PARAM_LONG(facility)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &ident_param, &option_param, &facility_param);
	zephir_get_strval(&ident, ident_param);
	option = zephir_get_intval(option_param);
	facility = zephir_get_intval(facility_param);


	ZVAL_LONG(&_0, option);
	ZVAL_LONG(&_1, facility);
	ZEPHIR_RETURN_CALL_FUNCTION("openlog", NULL, 447, &ident, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Translates a Logger level to a Syslog level
 *
 * @param int $level
 *
 * @return int
 */
PHP_METHOD(Phalcon_Logger_Adapter_Syslog, logLevelToSyslog)
{
	zval levels;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *level_param = NULL, result;
	zend_long level;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&levels);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(level)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &level_param);
	level = zephir_get_intval(level_param);


	ZEPHIR_INIT_VAR(&levels);
	zephir_create_array(&levels, 9, 0);
	add_index_long(&levels, 2, 1);
	add_index_long(&levels, 1, 2);
	add_index_long(&levels, 8, 3);
	add_index_long(&levels, 7, 7);
	add_index_long(&levels, 0, 0);
	add_index_long(&levels, 3, 3);
	add_index_long(&levels, 6, 6);
	add_index_long(&levels, 5, 5);
	add_index_long(&levels, 4, 4);
	ZEPHIR_OBS_VAR(&result);
	if (!(zephir_array_isset_long_fetch(&result, &levels, level, 0))) {
		ZEPHIR_INIT_NVAR(&result);
		ZVAL_LONG(&result, 3);
	}
	RETURN_CCTOR(&result);
}

