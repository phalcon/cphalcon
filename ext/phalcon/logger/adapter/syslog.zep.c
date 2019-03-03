
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
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Logger\Adapter\Syslog
 *
 * Sends logs to the system logger
 *
 * <code>
 * use Phalcon\Logger;
 * use Phalcon\Logger\Adapter\Syslog;
 *
 * // LOG_USER is the only valid log type under Windows operating systems
 * $logger = new Syslog(
 *     "ident",
 *     [
 *         "option"   => LOG_CONS | LOG_NDELAY | LOG_PID,
 *         "facility" => LOG_USER,
 *     ]
 * );
 *
 * $logger->log("This is a message");
 * $logger->log(Logger::ERROR, "This is an error");
 * $logger->error("This is another error");
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Adapter_Syslog) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Logger\\Adapter, Syslog, phalcon, logger_adapter_syslog, phalcon_logger_adapter_abstractadapter_ce, phalcon_logger_adapter_syslog_method_entry, 0);

	/**
	 * Name of the default formatter class
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_logger_adapter_syslog_ce, SL("defaultFormatter"), "Syslog", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_logger_adapter_syslog_ce, SL("facility"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_logger_adapter_syslog_ce, SL("name"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_logger_adapter_syslog_ce, SL("opened"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_logger_adapter_syslog_ce, SL("option"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Logger\Adapter\Syslog constructor
 */
PHP_METHOD(Phalcon_Logger_Adapter_Syslog, __construct) {

	zval options;
	zval *name_param = NULL, *options_param = NULL, option, facility;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&facility);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &options_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_OBS_VAR(&option);
	if (zephir_array_isset_string_fetch(&option, &options, SL("option"), 0)) {
		ZEPHIR_INIT_NVAR(&option);
		ZVAL_LONG(&option, 4);
	}
	ZEPHIR_OBS_VAR(&facility);
	if (!(zephir_array_isset_string_fetch(&facility, &options, SL("facility"), 0))) {
		ZEPHIR_INIT_NVAR(&facility);
		ZVAL_LONG(&facility, 8);
	}
	zephir_update_property_zval(this_ptr, SL("name"), &name);
	zephir_update_property_zval(this_ptr, SL("facility"), &facility);
	zephir_update_property_zval(this_ptr, SL("option"), &option);
	ZEPHIR_MM_RESTORE();

}

/**
 * Closes the logger
 */
PHP_METHOD(Phalcon_Logger_Adapter_Syslog, close) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("opened"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_RETURN_CALL_FUNCTION("closelog", NULL, 292);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Processes the message i.e. writes it to the syslog
 */
PHP_METHOD(Phalcon_Logger_Adapter_Syslog, process) {

	zend_bool opened = 0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *item, item_sub, __$true, __$false, name, facility, formatter, level, message, option, result, _0, _4, _5, _1$$4, _2$$4, _3$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&facility);
	ZVAL_UNDEF(&formatter);
	ZVAL_UNDEF(&level);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &item);



	ZEPHIR_CALL_METHOD(&formatter, this_ptr, "getformatter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&message, &formatter, "format", NULL, 0, item);
	zephir_check_call_status();
	if (Z_TYPE_P(&message) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_logger_exception_ce, "The formatted message is not valid", "phalcon/logger/adapter/syslog.zep", 114);
		return;
	}
	zephir_read_property(&_0, this_ptr, SL("name"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&name, &_0);
	zephir_read_property(&_0, this_ptr, SL("facility"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&facility, &_0);
	zephir_read_property(&_0, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&option, &_0);
	ZEPHIR_CALL_FUNCTION(&result, "openlog", NULL, 293, &name, &option, &facility);
	zephir_check_call_status();
	if (!zephir_is_true(&result)) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, spl_ce_LogicException);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "Cannot open syslog for name [%s] and facility [%s]");
		ZEPHIR_CALL_FUNCTION(&_3$$4, "sprintf", NULL, 139, &_2$$4, &name, &facility);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 294, &_3$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$4, "phalcon/logger/adapter/syslog.zep", 130 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	opened = 1;
	if (opened) {
		zephir_update_property_zval(this_ptr, SL("opened"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("opened"), &__$false);
	}
	zephir_array_fetch_long(&_4, &message, 1, PH_NOISY | PH_READONLY, "phalcon/logger/adapter/syslog.zep", 135 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&level, this_ptr, "logleveltosyslog", NULL, 295, &_4);
	zephir_check_call_status();
	zephir_array_fetch_long(&_5, &message, 1, PH_NOISY | PH_READONLY, "phalcon/logger/adapter/syslog.zep", 137 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "syslog", NULL, 296, &level, &_5);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Translates a Logger level to a Syslog level
 */
PHP_METHOD(Phalcon_Logger_Adapter_Syslog, logLevelToSyslog) {

	zval *level_param = NULL, levels, result;
	zval level;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&level);
	ZVAL_UNDEF(&levels);
	ZVAL_UNDEF(&result);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &level_param);

	zephir_get_strval(&level, level_param);


	ZEPHIR_INIT_VAR(&levels);
	zephir_create_array(&levels, 9, 0 TSRMLS_CC);
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
	if (!(zephir_array_isset_fetch(&result, &levels, &level, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(&result);
		ZVAL_LONG(&result, 3);
	}
	RETURN_CCTOR(&result);

}

