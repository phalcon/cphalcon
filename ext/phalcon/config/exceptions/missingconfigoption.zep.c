
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
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/memory.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Config_Exceptions_MissingConfigOption)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Config\\Exceptions, MissingConfigOption, phalcon, config_exceptions_missingconfigoption, phalcon_config_exception_ce, phalcon_config_exceptions_missingconfigoption_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_config_exceptions_missingconfigoption_ce, SL("option"), ZEND_ACC_PRIVATE);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Config_Exceptions_MissingConfigOption, __construct)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval option_zv;
	zend_string *option = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(option)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&option_zv);
	ZVAL_STR_COPY(&option_zv, option);
	zephir_update_property_zval(this_ptr, ZEND_STRL("option"), &option_zv);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SVS(&_0, "You must provide '", &option_zv, "' option in factory config parameter.");
	ZEPHIR_CALL_PARENT(NULL, phalcon_config_exceptions_missingconfigoption_ce, getThis(), "__construct", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Config_Exceptions_MissingConfigOption, getOption)
{

	RETURN_MEMBER_TYPED(getThis(), "option", IS_STRING);
}

