
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
 * The result of matching a request against the router: the Action class, the
 * extracted route attributes, the route's middleware and its optional name.
 *
 * @phpstan-import-type adr_middleware_names from ADRTypes
 * @phpstan-import-type adr_route_attributes from ADRTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_ADR_Router_RouterMatch)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\ADR\\Router, RouterMatch, phalcon, contracts_adr_router_routermatch, phalcon_contracts_adr_router_routermatch_method_entry);

	return SUCCESS;
}

/**
 * @phpstan-return class-string
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_ADR_Router_RouterMatch, getAction);
/**
 * @phpstan-return adr_route_attributes
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_ADR_Router_RouterMatch, getAttributes);
/**
 * @phpstan-return adr_middleware_names
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_ADR_Router_RouterMatch, getMiddleware);
ZEPHIR_DOC_METHOD(Phalcon_Contracts_ADR_Router_RouterMatch, getName);
