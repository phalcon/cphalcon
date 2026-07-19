
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
 * Wraps the handler chain. Middleware may pass the request through to the next
 * handler, decorate the response, short-circuit by returning its own response,
 * or throw to route through the error responder.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_ADR_Middleware)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\ADR, Middleware, phalcon, contracts_adr_middleware, phalcon_contracts_adr_middleware_method_entry);

	return SUCCESS;
}

ZEPHIR_DOC_METHOD(Phalcon_Contracts_ADR_Middleware, __invoke);
