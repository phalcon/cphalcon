
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/string.h"
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
 * Phalcon\Logger\Formatter\Json
 *
 * Formats messages using JSON encoding
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Formatter_Json) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Logger\\Formatter, Json, phalcon, logger_formatter_json, phalcon_logger_formatter_abstractformatter_ce, phalcon_logger_formatter_json_method_entry, 0);

	/**
	 * Default date format
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_logger_formatter_json_ce, SL("dateFormat"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Default date format
 */
PHP_METHOD(Phalcon_Logger_Formatter_Json, getDateFormat) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "dateFormat");

}

/**
 * Default date format
 */
PHP_METHOD(Phalcon_Logger_Formatter_Json, setDateFormat) {

	zval *dateFormat_param = NULL;
	zval dateFormat;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dateFormat);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dateFormat_param);

	zephir_get_strval(&dateFormat, dateFormat_param);


	zephir_update_property_zval(this_ptr, SL("dateFormat"), &dateFormat);
	RETURN_THIS();

}

/**
 * Phalcon\Logger\Formatter\Json construct
 */
PHP_METHOD(Phalcon_Logger_Formatter_Json, __construct) {

	zval *dateFormat_param = NULL;
	zval dateFormat;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dateFormat);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &dateFormat_param);

	if (!dateFormat_param) {
		ZEPHIR_INIT_VAR(&dateFormat);
		ZVAL_STRING(&dateFormat, "D, d M y H:i:s O");
	} else {
		zephir_get_strval(&dateFormat, dateFormat_param);
	}


	zephir_update_property_zval(this_ptr, SL("dateFormat"), &dateFormat);
	ZEPHIR_MM_RESTORE();

}

/**
 * Applies a format to a message before sent it to the internal log
 */
PHP_METHOD(Phalcon_Logger_Formatter_Json, format) {

	zval _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *item, item_sub, message, _0, _3, _5, _6, _7, _8, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item_sub);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
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
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 3, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_5, item, "getname", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_4, SL("type"), &_5, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_4, SL("message"), &message, PH_COPY | PH_SEPARATE);
	zephir_read_property(&_6, this_ptr, SL("dateFormat"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_5, item, "gettime", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_7, "date", NULL, 407, &_6, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&_4, SL("timestamp"), &_7, PH_COPY | PH_SEPARATE);
	zephir_json_encode(&_3, &_4, 0 );
	ZEPHIR_INIT_VAR(&_8);
	ZEPHIR_GET_CONSTANT(&_8, "PHP_EOL");
	ZEPHIR_CONCAT_VV(return_value, &_3, &_8);
	RETURN_MM();

}

