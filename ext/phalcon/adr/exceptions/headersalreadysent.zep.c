
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
#include "kernel/memory.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Based on the Action Domain Responder pattern
 * @link    https://pmjones.io/adr/
 */
/**
 * Thrown when the emitter is asked to send a response after headers have
 * already been sent.
 */
ZEPHIR_INIT_CLASS(Phalcon_ADR_Exceptions_HeadersAlreadySent)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\ADR\\Exceptions, HeadersAlreadySent, phalcon, adr_exceptions_headersalreadysent, phalcon_adr_exceptions_exception_ce, phalcon_adr_exceptions_headersalreadysent_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_ADR_Exceptions_HeadersAlreadySent, __construct)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Headers have already been sent; cannot emit the response.");
	ZEPHIR_CALL_PARENT(NULL, phalcon_adr_exceptions_headersalreadysent_ce, getThis(), "__construct", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

