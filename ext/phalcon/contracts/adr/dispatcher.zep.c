
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
 *
 * Based on the Action Domain Responder pattern
 * @link    https://pmjones.io/adr/
 */
/**
 * Resolves an Action by class name, builds the middleware pipeline around it and
 * runs it to produce a response.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_ADR_Dispatcher)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\ADR, Dispatcher, phalcon, contracts_adr_dispatcher, phalcon_contracts_adr_dispatcher_method_entry);

	return SUCCESS;
}

ZEPHIR_DOC_METHOD(Phalcon_Contracts_ADR_Dispatcher, dispatch);
