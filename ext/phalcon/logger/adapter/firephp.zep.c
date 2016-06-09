
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/array.h"


/**
 * Phalcon\Logger\Adapter\Firephp
 *
 * Sends logs to FirePHP
 *
 *<code>
 * use Phalcon\Logger\Adapter\Firephp;
 * use Phalcon\Logger;
 *
 * $logger = new Firephp("");
 * $logger->log(Logger::ERROR, "This is an error");
 * $logger->error("This is another error");
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Adapter_Firephp) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Logger\\Adapter, Firephp, phalcon, logger_adapter_firephp, phalcon_logger_adapter_ce, phalcon_logger_adapter_firephp_method_entry, 0);

	zend_declare_property_null(phalcon_logger_adapter_firephp_ce, SL("_initialized"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(phalcon_logger_adapter_firephp_ce, SL("_index"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_class_implements(phalcon_logger_adapter_firephp_ce TSRMLS_CC, 1, phalcon_logger_adapterinterface_ce);
	return SUCCESS;

}

/**
 * Returns the internal formatter
 */
PHP_METHOD(Phalcon_Logger_Adapter_Firephp, getFormatter) {

	zval _0, _1$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("_formatter"), PH_NOISY_CC);
	if (Z_TYPE_P(&_0) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_logger_formatter_firephp_ce);
		if (zephir_has_constructor(&_1$$3 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_update_property_zval(this_ptr, SL("_formatter"), &_1$$3);
	}
	RETURN_MM_MEMBER(this_ptr, "_formatter");

}

/**
 * Writes the log to the stream itself
 *
 * @link http://www.firephp.org/Wiki/Reference/Protocol
 */
PHP_METHOD(Phalcon_Logger_Adapter_Firephp, logInternal) {

	zend_string *_10;
	zend_ulong _9;
	zephir_fcall_cache_entry *_4 = NULL;
	zval context;
	int type, time, ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *type_param = NULL, *time_param = NULL, *context_param = NULL, __$true, chunk, format, chString, content, key, _0, _2, _5, _6, _7, *_8, _1$$3, _3$$4, _11$$5, _12$$5, _13$$5;
	zval message;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&message);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&chunk);
	ZVAL_UNDEF(&format);
	ZVAL_UNDEF(&chString);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &message_param, &type_param, &time_param, &context_param);

	zephir_get_strval(&message, message_param);
	type = zephir_get_intval(type_param);
	time = zephir_get_intval(time_param);
	zephir_get_arrval(&context, context_param);


	zephir_read_static_property_ce(&_0, phalcon_logger_adapter_firephp_ce, SL("_index"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_ZVAL_NREF(_1$$3);
		ZVAL_LONG(&_1$$3, 1);
		zephir_update_static_property_ce(phalcon_logger_adapter_firephp_ce, SL("_index"), &_1$$3);
	}
	zephir_read_static_property_ce(&_2, phalcon_logger_adapter_firephp_ce, SL("_initialized"), PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_2)) {
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "X-Wf-Protocol-1: http://meta.wildfirehq.org/Protocol/JsonStream/0.2");
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_4, 246, &_3$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "X-Wf-1-Plugin-1: http://meta.firephp.org/Wildfire/Plugin/FirePHP/Library-FirePHPCore/0.3");
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_4, 246, &_3$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "X-Wf-Structure-1: http://meta.firephp.org/Wildfire/Structure/FirePHP/FirebugConsole/0.1");
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_4, 246, &_3$$4);
		zephir_check_call_status();
		zephir_update_static_property_ce(phalcon_logger_adapter_firephp_ce, SL("_initialized"), &__$true);
	}
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getformatter", NULL, 0);
	zephir_check_call_status();
	ZVAL_LONG(&_6, type);
	ZVAL_LONG(&_7, time);
	ZEPHIR_CALL_METHOD(&format, &_5, "format", NULL, 0, &message, &_6, &_7, &context);
	zephir_check_call_status();
	ZVAL_LONG(&_6, 4500);
	ZEPHIR_CALL_FUNCTION(&chunk, "str_split", NULL, 74, &format, &_6);
	zephir_check_call_status();
	zephir_is_iterable(&chunk, 0, "phalcon/logger/adapter/firephp.zep", 96);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&chunk), _9, _10, _8)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_10 != NULL) { 
			ZVAL_STR_COPY(&key, _10);
		} else {
			ZVAL_LONG(&key, _9);
		}
		ZEPHIR_INIT_NVAR(&chString);
		ZVAL_COPY(&chString, _8);
		ZEPHIR_OBS_NVAR(&_11$$5);
		zephir_read_static_property_ce(&_11$$5, phalcon_logger_adapter_firephp_ce, SL("_index"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(&content);
		ZEPHIR_CONCAT_SVSV(&content, "X-Wf-1-1-1-", &_11$$5, ": ", &chString);
		if (zephir_array_isset_long(&chunk, (zephir_get_numberval(&key) + 1))) {
			zephir_concat_self_str(&content, SL("|\\") TSRMLS_CC);
		}
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_4, 246, &content);
		zephir_check_call_status();
		zephir_read_static_property_ce(&_12$$5, phalcon_logger_adapter_firephp_ce, SL("_index"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_ZVAL_NREF(_13$$5);
		ZVAL_LONG(&_13$$5, (zephir_get_numberval(&_12$$5) + 1));
		zephir_update_static_property_ce(phalcon_logger_adapter_firephp_ce, SL("_index"), &_13$$5);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&chString);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

/**
 * Closes the logger
 */
PHP_METHOD(Phalcon_Logger_Adapter_Firephp, close) {

	ZEPHIR_INIT_THIS();


	RETURN_BOOL(1);

}

