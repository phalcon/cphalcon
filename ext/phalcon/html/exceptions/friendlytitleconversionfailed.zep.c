
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
#include "kernel/object.h"
#include "kernel/memory.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Exceptions_FriendlyTitleConversionFailed)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Exceptions, FriendlyTitleConversionFailed, phalcon, html_exceptions_friendlytitleconversionfailed, phalcon_html_exception_ce, phalcon_html_exceptions_friendlytitleconversionfailed_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Html_Exceptions_FriendlyTitleConversionFailed, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval message_zv;
	zend_string *message = NULL;

	ZVAL_UNDEF(&message_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(message)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&message_zv);
	ZVAL_STR_COPY(&message_zv, message);
	ZEPHIR_CALL_PARENT(NULL, phalcon_html_exceptions_friendlytitleconversionfailed_ce, getThis(), "__construct", NULL, 0, &message_zv);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

