
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Formatter_AbstractFormatter)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Logger\\Formatter, AbstractFormatter, phalcon, logger_formatter_abstractformatter, phalcon_logger_formatter_abstractformatter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Default date format
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_logger_formatter_abstractformatter_ce, SL("dateFormat"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_logger_formatter_abstractformatter_ce, 1, phalcon_logger_formatter_formatterinterface_ce);
	return SUCCESS;
}

/**
 * Default date format
 */
PHP_METHOD(Phalcon_Logger_Formatter_AbstractFormatter, getDateFormat)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "dateFormat");
}

/**
 * Default date format
 */
PHP_METHOD(Phalcon_Logger_Formatter_AbstractFormatter, setDateFormat)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *dateFormat_param = NULL;
	zval dateFormat;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dateFormat);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(dateFormat)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dateFormat_param);
	zephir_get_strval(&dateFormat, dateFormat_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("dateFormat"), &dateFormat);
	RETURN_THIS();
}

