
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


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
/**
 * Phalcon\Logger\Item
 *
 * Represents each item in a logging transaction
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Item) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Logger, Item, phalcon, logger_item, phalcon_logger_item_method_entry, 0);

	/**
	 * Log type
	 *
	 * @var integer
	 */
	zend_declare_property_null(phalcon_logger_item_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Log message
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_logger_item_ce, SL("_message"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Log timestamp
	 *
	 * @var integer
	 */
	zend_declare_property_null(phalcon_logger_item_ce, SL("_time"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_logger_item_ce, SL("_context"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Log type
 *
 * @var integer
 */
PHP_METHOD(Phalcon_Logger_Item, getType) {


	RETURN_MEMBER(this_ptr, "_type");

}

/**
 * Log message
 *
 * @var string
 */
PHP_METHOD(Phalcon_Logger_Item, getMessage) {


	RETURN_MEMBER(this_ptr, "_message");

}

/**
 * Log timestamp
 *
 * @var integer
 */
PHP_METHOD(Phalcon_Logger_Item, getTime) {


	RETURN_MEMBER(this_ptr, "_time");

}

PHP_METHOD(Phalcon_Logger_Item, getContext) {


	RETURN_MEMBER(this_ptr, "_context");

}

/**
 * Phalcon\Logger\Item constructor
 *
 * @param string $message
 * @param integer $type
 * @param integer $time
 * @param array $context
 */
PHP_METHOD(Phalcon_Logger_Item, __construct) {

	zval *context = NULL;
	int type, time;
	zval *message_param = NULL, *type_param = NULL, *time_param = NULL, *context_param = NULL, *_0, *_1;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &message_param, &type_param, &time_param, &context_param);

	zephir_get_strval(message, message_param);
	type = zephir_get_intval(type_param);
	if (!time_param) {
		time = 0;
	} else {
		time = zephir_get_intval(time_param);
	}
	if (!context_param) {
	ZEPHIR_INIT_VAR(context);
	ZVAL_NULL(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	zephir_update_property_this(this_ptr, SL("_message"), message TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, type);
	zephir_update_property_this(this_ptr, SL("_type"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, time);
	zephir_update_property_this(this_ptr, SL("_time"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_gettype(_1, context TSRMLS_CC);
	if (ZEPHIR_IS_STRING(_1, "array")) {
		zephir_update_property_this(this_ptr, SL("_context"), context TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

