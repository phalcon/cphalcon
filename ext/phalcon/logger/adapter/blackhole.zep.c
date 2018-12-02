
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


/**
 * Phalcon\Logger\Adapter\Blackhole
 *
 * Any record it can handle will be thrown away.
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Adapter_Blackhole) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Logger\\Adapter, Blackhole, phalcon, logger_adapter_blackhole, phalcon_logger_adapter_ce, phalcon_logger_adapter_blackhole_method_entry, 0);

	return SUCCESS;

}

/**
 * Returns the internal formatter
 */
PHP_METHOD(Phalcon_Logger_Adapter_Blackhole, getFormatter) {

	zval *_0, *_1$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_formatter"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, phalcon_logger_formatter_line_ce);
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 312);
		zephir_check_call_status();
		zephir_update_property_this(getThis(), SL("_formatter"), _1$$3 TSRMLS_CC);
	}
	RETURN_MM_MEMBER(getThis(), "_formatter");

}

/**
 * Writes the log to the blackhole
 */
PHP_METHOD(Phalcon_Logger_Adapter_Blackhole, logInternal) {

	zval *context = NULL;
	zend_long type, time;
	zval *message_param = NULL, *type_param = NULL, *time_param = NULL, *context_param = NULL;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &message_param, &type_param, &time_param, &context_param);

	zephir_get_strval(message, message_param);
	type = zephir_get_intval(type_param);
	time = zephir_get_intval(time_param);
	zephir_get_arrval(context, context_param);



}

/**
 * Closes the logger
 */
PHP_METHOD(Phalcon_Logger_Adapter_Blackhole, close) {

	


}

