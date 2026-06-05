
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
#include "kernel/operators.h"
#include "kernel/memory.h"
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
 * @property array             $context
 * @property string            $message
 * @property int               $level
 * @property string            $levelName
 * @property DateTimeImmutable $dateTime
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Item)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Logger, Item, phalcon, logger_item, phalcon_logger_item_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_logger_item_ce, SL("context"), ZEND_ACC_PROTECTED);
	/**
	 * @var DateTimeImmutable
	 */
	zend_declare_property_null(phalcon_logger_item_ce, SL("dateTime"), ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_null(phalcon_logger_item_ce, SL("level"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_logger_item_ce, SL("levelName"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_logger_item_ce, SL("message"), ZEND_ACC_PROTECTED);
	phalcon_logger_item_ce->create_object = zephir_init_properties_Phalcon_Logger_Item;

	return SUCCESS;
}

/**
 * Item constructor.
 *
 * @param string            $message
 * @param string            $levelName
 * @param int               $level
 * @param DateTimeImmutable $dateTime
 * @param array             $context
 */
PHP_METHOD(Phalcon_Logger_Item, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval context;
	zend_long level;
	zval message_zv, levelName_zv, *level_param = NULL, *dateTime, dateTime_sub, *context_param = NULL, _0;
	zend_string *message = NULL, *levelName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_zv);
	ZVAL_UNDEF(&levelName_zv);
	ZVAL_UNDEF(&dateTime_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);
	ZEND_PARSE_PARAMETERS_START(4, 5)
		Z_PARAM_STR(message)
		Z_PARAM_STR(levelName)
		Z_PARAM_LONG(level)
		Z_PARAM_OBJECT_OF_CLASS(dateTime, php_date_get_immutable_ce())
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(context, context_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	level_param = ZEND_CALL_ARG(execute_data, 3);
	dateTime = ZEND_CALL_ARG(execute_data, 4);
	if (ZEND_NUM_ARGS() > 4) {
		context_param = ZEND_CALL_ARG(execute_data, 5);
	}
	ZVAL_STR(&message_zv, message);
	ZVAL_STR(&levelName_zv, levelName);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("message"), &message_zv);
	zephir_update_property_zval(this_ptr, ZEND_STRL("levelName"), &levelName_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, level);
	zephir_update_property_zval(this_ptr, ZEND_STRL("level"), &_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("dateTime"), dateTime);
	zephir_update_property_zval(this_ptr, ZEND_STRL("context"), &context);
	ZEPHIR_MM_RESTORE();
}

/**
 * @return array
 */
PHP_METHOD(Phalcon_Logger_Item, getContext)
{

	RETURN_MEMBER_TYPED(getThis(), "context", IS_ARRAY);
}

/**
 * @return DateTimeImmutable
 */
PHP_METHOD(Phalcon_Logger_Item, getDateTime)
{

	RETURN_MEMBER(getThis(), "dateTime");
}

/**
 * @return int
 */
PHP_METHOD(Phalcon_Logger_Item, getLevel)
{

	RETURN_MEMBER_TYPED(getThis(), "level", IS_LONG);
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Item, getLevelName)
{

	RETURN_MEMBER_TYPED(getThis(), "levelName", IS_STRING);
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Item, getMessage)
{

	RETURN_MEMBER_TYPED(getThis(), "message", IS_STRING);
}

zend_object *zephir_init_properties_Phalcon_Logger_Item(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
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

