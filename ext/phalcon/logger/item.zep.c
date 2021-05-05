
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
#include "ext/date/php_date.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Logger_Item)
{
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
	 * Log type
	 *
	 * @var integer
	 */
	zend_declare_property_null(phalcon_logger_item_ce, SL("level"), ZEND_ACC_PROTECTED);
	/**
	 * Log message
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_logger_item_ce, SL("levelName"), ZEND_ACC_PROTECTED);
	/**
	 * Log timestamp
	 *
	 * @var DateTimeImmutable
	 */
	zend_declare_property_null(phalcon_logger_item_ce, SL("time"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Log Context
 */
PHP_METHOD(Phalcon_Logger_Item, getContext)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "context");
}

/**
 * Log message
 */
PHP_METHOD(Phalcon_Logger_Item, getMessage)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "message");
}

/**
 * Log type
 */
PHP_METHOD(Phalcon_Logger_Item, getLevel)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "level");
}

/**
 * Log message
 */
PHP_METHOD(Phalcon_Logger_Item, getLevelName)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "levelName");
}

/**
 * Log timestamp
 */
PHP_METHOD(Phalcon_Logger_Item, getTime)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "time");
}

/**
 * Phalcon\Logger\Item constructor
 */
PHP_METHOD(Phalcon_Logger_Item, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval context;
	zend_long level;
	zval *message_param = NULL, *levelName_param = NULL, *level_param = NULL, *time, time_sub, *context_param = NULL, _0;
	zval message, levelName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&levelName);
	ZVAL_UNDEF(&time_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(4, 5)
		Z_PARAM_STR(message)
		Z_PARAM_STR(levelName)
		Z_PARAM_LONG(level)
		Z_PARAM_OBJECT_OF_CLASS(time, php_date_get_immutable_ce())
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(context)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &message_param, &levelName_param, &level_param, &time, &context_param);
	zephir_get_strval(&message, message_param);
	zephir_get_strval(&levelName, levelName_param);
	level = zephir_get_intval(level_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("message"), &message);
	zephir_update_property_zval(this_ptr, ZEND_STRL("levelName"), &levelName);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, level);
	zephir_update_property_zval(this_ptr, ZEND_STRL("level"), &_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("time"), time);
	zephir_update_property_zval(this_ptr, ZEND_STRL("context"), &context);
	ZEPHIR_MM_RESTORE();
}

