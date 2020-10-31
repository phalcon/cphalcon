
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
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
	 * Log Context
	 *      
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_logger_item_ce, SL("context"), ZEND_ACC_PROTECTED);

	/**
	 * Log message
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_logger_item_ce, SL("message"), ZEND_ACC_PROTECTED);

	/**
	 * Log message
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_logger_item_ce, SL("name"), ZEND_ACC_PROTECTED);

	/**
	 * Log timestamp
	 *
	 * @var integer
	 */
	zend_declare_property_null(phalcon_logger_item_ce, SL("time"), ZEND_ACC_PROTECTED);

	/**
	 * Log type
	 *
	 * @var integer
	 */
	zend_declare_property_null(phalcon_logger_item_ce, SL("type"), ZEND_ACC_PROTECTED);

	return SUCCESS;

}

/**
 * Log Context
 */
PHP_METHOD(Phalcon_Logger_Item, getContext) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "context");

}

/**
 * Log message
 */
PHP_METHOD(Phalcon_Logger_Item, getMessage) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "message");

}

/**
 * Log message
 */
PHP_METHOD(Phalcon_Logger_Item, getName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "name");

}

/**
 * Log timestamp
 */
PHP_METHOD(Phalcon_Logger_Item, getTime) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "time");

}

/**
 * Log type
 */
PHP_METHOD(Phalcon_Logger_Item, getType) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "type");

}

/**
 * Phalcon\Logger\Item constructor
 * @todo Remove the time or change the signature to an array
 */
PHP_METHOD(Phalcon_Logger_Item, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long type, time;
	zval *message_param = NULL, *name_param = NULL, *type_param = NULL, *time_param = NULL, *context = NULL, context_sub, _0;
	zval message, name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&context_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 2, &message_param, &name_param, &type_param, &time_param, &context);

	zephir_get_strval(&message, message_param);
	zephir_get_strval(&name, name_param);
	type = zephir_get_intval(type_param);
	if (!time_param) {
		time = 0;
	} else {
		time = zephir_get_intval(time_param);
	}
	if (!context) {
		context = &context_sub;
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("message"), &message);
	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &name);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, type);
	zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &_0);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, time);
	zephir_update_property_zval(this_ptr, ZEND_STRL("time"), &_0);
	if (Z_TYPE_P(context) == IS_ARRAY) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("context"), context);
	}
	ZEPHIR_MM_RESTORE();

}

