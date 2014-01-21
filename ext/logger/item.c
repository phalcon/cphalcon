
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#include "logger/item.h"

#include "kernel/main.h"
#include "kernel/object.h"

/**
 * Phalcon\Logger\Item
 *
 * Represents each item in a logging transaction
 *
 */
zend_class_entry *phalcon_logger_item_ce;

PHP_METHOD(Phalcon_Logger_Item, __construct);
PHP_METHOD(Phalcon_Logger_Item, getMessage);
PHP_METHOD(Phalcon_Logger_Item, getType);
PHP_METHOD(Phalcon_Logger_Item, getTime);
PHP_METHOD(Phalcon_Logger_Item, getContext);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_item___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, time)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_logger_item_method_entry[] = {
	PHP_ME(Phalcon_Logger_Item, __construct, arginfo_phalcon_logger_item___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Logger_Item, getMessage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Item, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Item, getTime, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Item, getContext, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Logger\Item initializer
 */
PHALCON_INIT_CLASS(Phalcon_Logger_Item){

	PHALCON_REGISTER_CLASS(Phalcon\\Logger, Item, logger_item, phalcon_logger_item_method_entry, 0);

	zend_declare_property_null(phalcon_logger_item_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_item_ce, SL("_message"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_item_ce, SL("_time"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_item_ce, SL("_context"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Logger\Item constructor
 *
 * @param string $message
 * @param integer $type
 * @param integer $time
 */
PHP_METHOD(Phalcon_Logger_Item, __construct){

	zval *message, *type, *time = NULL, *context = NULL;

	phalcon_fetch_params(0, 2, 2, &message, &type, &time, &context);
	
	if (!time) {
		time = PHALCON_GLOBAL(z_zero);
	}
	
	phalcon_update_property_this(this_ptr, SL("_message"), message TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_time"), time TSRMLS_CC);

	if (context && Z_TYPE_P(context) == IS_ARRAY) {
		phalcon_update_property_this(this_ptr, SL("_context"), context TSRMLS_CC);
	}
}

/**
 * Returns the message
 *
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Item, getMessage){


	RETURN_MEMBER(this_ptr, "_message");
}

/**
 * Returns the log type
 *
 * @return integer
 */
PHP_METHOD(Phalcon_Logger_Item, getType){


	RETURN_MEMBER(this_ptr, "_type");
}

/**
 * Returns log timestamp
 *
 * @return integer
 */
PHP_METHOD(Phalcon_Logger_Item, getTime){


	RETURN_MEMBER(this_ptr, "_time");
}

PHP_METHOD(Phalcon_Logger_Item, getContext) {

	zval *context = phalcon_fetch_nproperty_this(getThis(), SL("_context"), PH_NOISY TSRMLS_CC);

	if (Z_TYPE_P(context) == IS_ARRAY) {
		RETURN_ZVAL(context, 1, 0);
	}

	array_init(return_value);
}
