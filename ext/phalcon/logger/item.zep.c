
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
 * @property array             $context
 * @property string            $message
 * @property int               $level
 * @property string            $levelName
 * @property DateTimeImmutable $datetime
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Item)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Logger, Item, phalcon, logger_item, phalcon_logger_item_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_logger_item_ce, SL("context"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_logger_item_ce, SL("message"), ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_null(phalcon_logger_item_ce, SL("level"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_logger_item_ce, SL("levelName"), ZEND_ACC_PROTECTED);
	/**
	 * @var DateTimeImmutable
	 */
	zend_declare_property_null(phalcon_logger_item_ce, SL("dateTime"), ZEND_ACC_PROTECTED);
	phalcon_logger_item_ce->create_object = zephir_init_properties_Phalcon_Logger_Item;

	return SUCCESS;
}

/**
 */
PHP_METHOD(Phalcon_Logger_Item, getContext)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "context");
}

/**
 */
PHP_METHOD(Phalcon_Logger_Item, getMessage)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "message");
}

/**
 */
PHP_METHOD(Phalcon_Logger_Item, getLevel)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "level");
}

/**
 */
PHP_METHOD(Phalcon_Logger_Item, getLevelName)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "levelName");
}

/**
 */
PHP_METHOD(Phalcon_Logger_Item, getDateTime)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "dateTime");
}

/**
 * Item constructor.
 *
 * @param string            $message
 * @param string            $levelName
 * @param int               $level
 * @param DateTimeImmutable $datetime
 * @param array             $context
 */
PHP_METHOD(Phalcon_Logger_Item, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval context;
	zend_long level;
	zval *message_param = NULL, *levelName_param = NULL, *level_param = NULL, *dateTime, dateTime_sub, *context_param = NULL, _0;
	zval message, levelName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&levelName);
	ZVAL_UNDEF(&dateTime_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(4, 5)
		Z_PARAM_STR(message)
		Z_PARAM_STR(levelName)
		Z_PARAM_LONG(level)
		Z_PARAM_OBJECT_OF_CLASS(dateTime, php_date_get_immutable_ce())
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(context)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &message_param, &levelName_param, &level_param, &dateTime, &context_param);
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
	zephir_update_property_zval(this_ptr, ZEND_STRL("dateTime"), dateTime);
	zephir_update_property_zval(this_ptr, ZEND_STRL("context"), &context);
	ZEPHIR_MM_RESTORE();
}

zend_object *zephir_init_properties_Phalcon_Logger_Item(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_MM_GROW();
	
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

