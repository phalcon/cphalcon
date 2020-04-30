
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Logger\Formatter\Json
 *
 * Formats messages using JSON encoding
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Formatter_Json) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Logger\\Formatter, Json, phalcon, logger_formatter_json, phalcon_logger_formatter_abstractformatter_ce, phalcon_logger_formatter_json_method_entry, 0);

	return SUCCESS;

}

/**
 * Phalcon\Logger\Formatter\Json construct
 */
PHP_METHOD(Phalcon_Logger_Formatter_Json, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *dateFormat_param = NULL;
	zval dateFormat;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dateFormat);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &dateFormat_param);

	if (!dateFormat_param) {
		ZEPHIR_INIT_VAR(&dateFormat);
		ZVAL_STRING(&dateFormat, "c");
	} else {
		zephir_get_strval(&dateFormat, dateFormat_param);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("dateFormat"), &dateFormat);
	ZEPHIR_MM_RESTORE();

}

/**
 * Applies a format to a message before sent it to the internal log
 */
PHP_METHOD(Phalcon_Logger_Formatter_Json, format) {

	zval _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *item, item_sub, message, _0, _5, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item_sub);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &item);



	ZEPHIR_CALL_METHOD(&_0, item, "getcontext", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_1$$3, item, "getmessage", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_2$$3, item, "getcontext", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&message, this_ptr, "interpolate", NULL, 0, &_1$$3, &_2$$3);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&message, item, "getmessage", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 3, 0);
	ZEPHIR_CALL_METHOD(&_5, item, "getname", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_4, SL("type"), &_5, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_4, SL("message"), &message, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getformatteddate", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_4, SL("timestamp"), &_5, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_helper_json_ce, "encode", &_3, 13, &_4);
	zephir_check_call_status();
	RETURN_MM();

}

