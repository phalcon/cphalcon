
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AtlasPHP
 *
 * @link    https://github.com/atlasphp/Atlas.Pdo
 * @license https://github.com/atlasphp/Atlas.Pdo/blob/1.x/LICENSE.md
 */
/**
 * Sends query profiles to a logger.
 *
 * @property bool            $active
 * @property array           $context
 * @property string          $logFormat
 * @property string          $logLevel
 * @property LoggerInterface $logger
 */
ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Pdo_Profiler_Profiler)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\DataMapper\\Pdo\\Profiler, Profiler, phalcon, datamapper_pdo_profiler_profiler, phalcon_datamapper_pdo_profiler_profiler_method_entry, 0);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_datamapper_pdo_profiler_profiler_ce, SL("active"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_datamapper_pdo_profiler_profiler_ce, SL("context"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_datamapper_pdo_profiler_profiler_ce, SL("logFormat"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_datamapper_pdo_profiler_profiler_ce, SL("logLevel"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var LoggerInterface
	 */
	zend_declare_property_null(phalcon_datamapper_pdo_profiler_profiler_ce, SL("logger"), ZEND_ACC_PROTECTED);
	phalcon_datamapper_pdo_profiler_profiler_ce->create_object = zephir_init_properties_Phalcon_DataMapper_Pdo_Profiler_Profiler;

	zend_class_implements(phalcon_datamapper_pdo_profiler_profiler_ce, 1, phalcon_datamapper_pdo_profiler_profilerinterface_ce);
	return SUCCESS;
}

/**
 * Constructor.
 *
 * @param LoggerInterface $logger
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Profiler_Profiler, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *logger = NULL, logger_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&logger_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(logger, zephir_get_internal_ce(SL("psr\\log\\loggerinterface")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &logger);
	if (!logger) {
		logger = &logger_sub;
		ZEPHIR_CPY_WRT(logger, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(logger);
	}


	if (Z_TYPE_P(logger) == IS_NULL) {
		ZEPHIR_INIT_NVAR(logger);
		object_init_ex(logger, phalcon_datamapper_pdo_profiler_memorylogger_ce);
		if (zephir_has_constructor(logger)) {
			ZEPHIR_CALL_METHOD(NULL, logger, "__construct", NULL, 0);
			zephir_check_call_status();
		}

	}
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "{method} ({duration}s): {statement} {backtrace}");
	zephir_update_property_zval(this_ptr, ZEND_STRL("logFormat"), &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "debug");
	zephir_update_property_zval(this_ptr, ZEND_STRL("logLevel"), &_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("logger"), logger);
	ZEPHIR_MM_RESTORE();
}

/**
 * Finishes and logs a profile entry.
 *
 * @param string $statement
 * @param array  $values
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Profiler_Profiler, finish)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval values;
	zval *statement_param = NULL, *values_param = NULL, __$true, ex, finish, _0, _1$$3, _2$$3, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3, _10$$3, _11$$3, _12$$3, _13$$3, _14$$3, _15$$3;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&ex);
	ZVAL_UNDEF(&finish);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&values);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(statement)
		Z_PARAM_ARRAY(values)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &statement_param, &values_param);
	if (!statement_param) {
		ZEPHIR_INIT_VAR(&statement);
	} else {
		zephir_get_strval(&statement, statement_param);
	}
	if (!values_param) {
		ZEPHIR_INIT_VAR(&values);
		array_init(&values);
	} else {
		zephir_get_arrval(&values, values_param);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("active"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&ex);
		object_init_ex(&ex, phalcon_datamapper_pdo_exception_exception_ce);
		ZEPHIR_CALL_METHOD(NULL, &ex, "__construct", NULL, 8);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&finish, "hrtime", NULL, 202, &__$true);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_1$$3, &ex, "gettraceasstring", NULL, 203);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "backtrace");
		zephir_update_property_array(this_ptr, SL("context"), &_2$$3, &_1$$3);
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("context"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_4$$3, &_3$$3, SL("start"), PH_NOISY | PH_READONLY, "phalcon/DataMapper/Pdo/Profiler/Profiler.zep", 91);
		ZEPHIR_INIT_VAR(&_5$$3);
		zephir_sub_function(&_5$$3, &finish, &_4$$3);
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "duration");
		zephir_update_property_array(this_ptr, SL("context"), &_6$$3, &_5$$3);
		ZEPHIR_INIT_VAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "finish");
		zephir_update_property_array(this_ptr, SL("context"), &_7$$3, &finish);
		ZEPHIR_INIT_VAR(&_8$$3);
		ZVAL_STRING(&_8$$3, "statement");
		zephir_update_property_array(this_ptr, SL("context"), &_8$$3, &statement);
		ZEPHIR_INIT_NVAR(&_5$$3);
		if (ZEPHIR_IS_EMPTY(&values)) {
			ZEPHIR_INIT_NVAR(&_5$$3);
			ZVAL_STRING(&_5$$3, "");
		} else {
			ZEPHIR_CALL_CE_STATIC(&_5$$3, phalcon_helper_json_ce, "encode", &_9, 14, &values);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(&_10$$3);
		ZVAL_STRING(&_10$$3, "values");
		zephir_update_property_array(this_ptr, SL("context"), &_10$$3, &_5$$3);
		zephir_read_property(&_11$$3, this_ptr, ZEND_STRL("logger"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_12$$3, this_ptr, ZEND_STRL("logLevel"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_13$$3, this_ptr, ZEND_STRL("logFormat"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_14$$3, this_ptr, ZEND_STRL("context"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_11$$3, "log", NULL, 0, &_12$$3, &_13$$3, &_14$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_15$$3);
		array_init(&_15$$3);
		zephir_update_property_zval(this_ptr, ZEND_STRL("context"), &_15$$3);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the log message format string, with placeholders.
 *
 * @return string
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Profiler_Profiler, getLogFormat)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "logFormat");
}

/**
 * Returns the underlying logger instance.
 *
 * @return LoggerInterface
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Profiler_Profiler, getLogger)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "logger");
}

/**
 * Returns the level at which to log profile messages.
 *
 * @return string
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Profiler_Profiler, getLogLevel)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "logLevel");
}

/**
 * Returns true if logging is active.
 *
 * @return bool
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Profiler_Profiler, isActive)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "active");
}

/**
 * Enable or disable profiler logging.
 *
 * @param bool $active
 *
 * @return ProfilerInterface
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Profiler_Profiler, setActive)
{
	zval *active_param = NULL, __$true, __$false;
	zend_bool active;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(active)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &active_param);
	active = zephir_get_boolval(active_param);


	if (active) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("active"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("active"), &__$false);
	}
	RETURN_THISW();
}

/**
 * Sets the log message format string, with placeholders.
 *
 * @param string $logFormat
 *
 * @return ProfilerInterface
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Profiler_Profiler, setLogFormat)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *logFormat_param = NULL;
	zval logFormat;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&logFormat);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(logFormat)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &logFormat_param);
	zephir_get_strval(&logFormat, logFormat_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("logFormat"), &logFormat);
	RETURN_THIS();
}

/**
 * Level at which to log profile messages.
 *
 * @param string $logLevel
 *
 * @return ProfilerInterface
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Profiler_Profiler, setLogLevel)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *logLevel_param = NULL;
	zval logLevel;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&logLevel);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(logLevel)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &logLevel_param);
	zephir_get_strval(&logLevel, logLevel_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("logLevel"), &logLevel);
	RETURN_THIS();
}

/**
 * Starts a profile entry.
 *
 * @param string $method
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Profiler_Profiler, start)
{
	zval _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, __$true, _0, _2$$3;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(method)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &method_param);
	zephir_get_strval(&method, method_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("active"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 2, 0);
		zephir_array_update_string(&_1$$3, SL("method"), &method, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "hrtime", NULL, 202, &__$true);
		zephir_check_call_status();
		zephir_array_update_string(&_1$$3, SL("start"), &_2$$3, PH_COPY | PH_SEPARATE);
		zephir_update_property_zval(this_ptr, ZEND_STRL("context"), &_1$$3);
	}
	ZEPHIR_MM_RESTORE();
}

zend_object *zephir_init_properties_Phalcon_DataMapper_Pdo_Profiler_Profiler(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("context"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("context"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

