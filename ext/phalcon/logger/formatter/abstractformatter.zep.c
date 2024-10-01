
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Class AbstractFormatter
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Formatter_AbstractFormatter)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Logger\\Formatter, AbstractFormatter, phalcon, logger_formatter_abstractformatter, phalcon_support_helper_str_abstractstr_ce, phalcon_logger_formatter_abstractformatter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Default date format
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_logger_formatter_abstractformatter_ce, SL("dateFormat"), "c", ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_logger_formatter_abstractformatter_ce, SL("interpolatorLeft"), "%", ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_logger_formatter_abstractformatter_ce, SL("interpolatorRight"), "%", ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_logger_formatter_abstractformatter_ce, 1, phalcon_logger_formatter_formatterinterface_ce);
	return SUCCESS;
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Formatter_AbstractFormatter, getDateFormat)
{

	RETURN_MEMBER(getThis(), "dateFormat");
}

/**
 * @param string $format
 */
PHP_METHOD(Phalcon_Logger_Formatter_AbstractFormatter, setDateFormat)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *format_param = NULL;
	zval format;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&format);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(format)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &format_param);
	zephir_get_strval(&format, format_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("dateFormat"), &format);
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the date formatted for the logger.
 *
 * @param Item $item
 *
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Formatter_AbstractFormatter, getFormattedDate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *item, item_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(item, phalcon_logger_item_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &item);
	ZEPHIR_CALL_METHOD(&_0, item, "getdatetime", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("dateFormat"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "format", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param Item   $item
 * @param string $message
 *
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Formatter_AbstractFormatter, getInterpolatedMessage)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval message;
	zval *item, item_sub, *message_param = NULL, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&message);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(item, phalcon_logger_item_ce)
		Z_PARAM_STR(message)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &item, &message_param);
	zephir_get_strval(&message, message_param);
	ZEPHIR_CALL_METHOD(&_0, item, "getcontext", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("interpolatorLeft"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("interpolatorRight"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "tointerpolate", NULL, 0, &message, &_0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

