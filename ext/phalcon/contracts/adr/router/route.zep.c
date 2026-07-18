
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

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
 * A registered route. Fluent, mutating configuration returned from the router's
 * registration methods.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_ADR_Router_Route)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\ADR\\Router, Route, phalcon, contracts_adr_router_route, phalcon_contracts_adr_router_route_method_entry);

	return SUCCESS;
}

ZEPHIR_DOC_METHOD(Phalcon_Contracts_ADR_Router_Route, withMiddleware);
ZEPHIR_DOC_METHOD(Phalcon_Contracts_ADR_Router_Route, withName);
