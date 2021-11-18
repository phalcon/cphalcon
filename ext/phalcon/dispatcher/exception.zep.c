
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Exceptions thrown in Phalcon\Dispatcher/* will use this class
 */
ZEPHIR_INIT_CLASS(Phalcon_Dispatcher_Exception)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Dispatcher, Exception, phalcon, dispatcher_exception, zend_ce_exception, NULL, 0);

	zephir_declare_class_constant_long(phalcon_dispatcher_exception_ce, SL("EXCEPTION_ACTION_NOT_FOUND"), 5);

	zephir_declare_class_constant_long(phalcon_dispatcher_exception_ce, SL("EXCEPTION_CYCLIC_ROUTING"), 1);

	zephir_declare_class_constant_long(phalcon_dispatcher_exception_ce, SL("EXCEPTION_HANDLER_NOT_FOUND"), 2);

	zephir_declare_class_constant_long(phalcon_dispatcher_exception_ce, SL("EXCEPTION_INVALID_HANDLER"), 3);

	zephir_declare_class_constant_long(phalcon_dispatcher_exception_ce, SL("EXCEPTION_INVALID_PARAMS"), 4);

	zephir_declare_class_constant_long(phalcon_dispatcher_exception_ce, SL("EXCEPTION_NO_DI"), 0);

	return SUCCESS;
}

