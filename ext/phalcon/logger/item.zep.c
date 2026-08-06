
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

	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_logger_item_ce, SL("context"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_logger_item_ce, SL("dateTime"), &_zc0, ZEND_ACC_PROTECTED, 0, SL("DateTimeImmutable"));
	}

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_logger_item_ce, SL("level"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_LONG, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_logger_item_ce, SL("levelName"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_logger_item_ce, SL("message"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("message", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("levelName", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("level", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("dateTime", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("context", 7, 1);
	}

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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 939, &message_zv);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 940, &levelName_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, level);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 941, &_0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 942, dateTime);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 943, &context);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Logger_Item, getContext)
{

	RETURN_MEMBER_TYPED(getThis(), "context", IS_ARRAY);
}

PHP_METHOD(Phalcon_Logger_Item, getDateTime)
{

	RETURN_MEMBER(getThis(), "dateTime");
}

PHP_METHOD(Phalcon_Logger_Item, getLevel)
{

	RETURN_MEMBER_TYPED(getThis(), "level", IS_LONG);
}

PHP_METHOD(Phalcon_Logger_Item, getLevelName)
{

	RETURN_MEMBER_TYPED(getThis(), "levelName", IS_STRING);
}

PHP_METHOD(Phalcon_Logger_Item, getMessage)
{

	RETURN_MEMBER_TYPED(getThis(), "message", IS_STRING);
}

