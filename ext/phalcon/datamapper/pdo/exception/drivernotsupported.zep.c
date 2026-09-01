
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Pdo_Exception_DriverNotSupported)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\DataMapper\\Pdo\\Exception, DriverNotSupported, phalcon, datamapper_pdo_exception_drivernotsupported, spl_ce_InvalidArgumentException, phalcon_datamapper_pdo_exception_drivernotsupported_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_DataMapper_Pdo_Exception_DriverNotSupported, __construct)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval driver_zv;
	zend_string *driver = NULL;

	ZVAL_UNDEF(&driver_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(driver)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&driver_zv);
	ZVAL_STR_COPY(&driver_zv, driver);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SVS(&_0, "Driver not supported [", &driver_zv, "]");
	ZEPHIR_CALL_PARENT(NULL, phalcon_datamapper_pdo_exception_drivernotsupported_ce, getThis(), "__construct", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

