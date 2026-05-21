
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
ZEPHIR_INIT_CLASS(Phalcon_Forms_Exceptions_InvalidJsonSchema)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Forms\\Exceptions, InvalidJsonSchema, phalcon, forms_exceptions_invalidjsonschema, phalcon_forms_exception_ce, phalcon_forms_exceptions_invalidjsonschema_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Forms_Exceptions_InvalidJsonSchema, __construct)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval detail_zv;
	zend_string *detail = NULL;

	ZVAL_UNDEF(&detail_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(detail)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&detail_zv);
	ZVAL_STR_COPY(&detail_zv, detail);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SV(&_0, "JSON form schema is invalid: ", &detail_zv);
	ZEPHIR_CALL_PARENT(NULL, phalcon_forms_exceptions_invalidjsonschema_ce, getThis(), "__construct", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

