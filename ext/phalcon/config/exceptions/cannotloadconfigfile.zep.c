
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
ZEPHIR_INIT_CLASS(Phalcon_Config_Exceptions_CannotLoadConfigFile)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Config\\Exceptions, CannotLoadConfigFile, phalcon, config_exceptions_cannotloadconfigfile, phalcon_config_exception_ce, phalcon_config_exceptions_cannotloadconfigfile_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_config_exceptions_cannotloadconfigfile_ce, SL("fileName"), ZEND_ACC_PRIVATE);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Config_Exceptions_CannotLoadConfigFile, __construct)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval fileName_zv;
	zend_string *fileName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fileName_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(fileName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&fileName_zv);
	ZVAL_STR_COPY(&fileName_zv, fileName);
	zephir_update_property_zval(this_ptr, ZEND_STRL("fileName"), &fileName_zv);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SVS(&_0, "Configuration file ", &fileName_zv, " cannot be loaded");
	ZEPHIR_CALL_PARENT(NULL, phalcon_config_exceptions_cannotloadconfigfile_ce, getThis(), "__construct", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Config_Exceptions_CannotLoadConfigFile, getFileName)
{

	RETURN_MEMBER_TYPED(getThis(), "fileName", IS_STRING);
}

