
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
ZEPHIR_INIT_CLASS(Phalcon_Logger_Adapter_Exceptions_FileOpenFailed)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Logger\\Adapter\\Exceptions, FileOpenFailed, phalcon, logger_adapter_exceptions_fileopenfailed, phalcon_logger_exception_ce, phalcon_logger_adapter_exceptions_fileopenfailed_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Logger_Adapter_Exceptions_FileOpenFailed, __construct)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, mode_zv;
	zend_string *name = NULL, *mode = NULL;

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&mode_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_STR(mode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_memory_observe(&mode_zv);
	ZVAL_STR_COPY(&mode_zv, mode);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SVSVS(&_0, "The file '", &name_zv, "' cannot be opened with mode '", &mode_zv, "'");
	ZEPHIR_CALL_PARENT(NULL, phalcon_logger_adapter_exceptions_fileopenfailed_ce, getThis(), "__construct", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

