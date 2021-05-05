
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

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
 * Allows to implement Phalcon\Mvc\Micro middleware in classes
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Micro_MiddlewareInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc\\Micro, MiddlewareInterface, phalcon, mvc_micro_middlewareinterface, phalcon_mvc_micro_middlewareinterface_method_entry);

	return SUCCESS;
}

/**
 * Calls the middleware
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Micro_MiddlewareInterface, call);
