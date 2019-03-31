
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
#include "kernel/memory.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Logger\Formatter\Syslog
 *
 * Prepares a message to be used in a Syslog backend
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Formatter_Syslog) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Logger\\Formatter, Syslog, phalcon, logger_formatter_syslog, phalcon_logger_formatter_abstractformatter_ce, phalcon_logger_formatter_syslog_method_entry, 0);

	return SUCCESS;

}

/**
 * Applies a format to a message before sent it to the internal log
 *
 * @param <Item> item
 *
 * @return array
 */
PHP_METHOD(Phalcon_Logger_Formatter_Syslog, format) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *item, item_sub, context, message, type, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item_sub);
	ZVAL_UNDEF(&context);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &item);



	ZEPHIR_CALL_METHOD(&message, item, "getmessage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&type, item, "gettype", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&context, item, "getcontext", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&context) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "interpolate", NULL, 0, &message, &context);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&message, &_0$$3);
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(return_value, &type);
	zephir_array_fast_append(return_value, &message);
	RETURN_MM();

}

