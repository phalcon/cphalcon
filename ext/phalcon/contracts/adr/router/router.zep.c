
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
 * Maps a request to an Action by convention: the HTTP method and the static
 * path segments identify the class; trailing segments become positional
 * request attributes. No route table.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_ADR_Router_Router)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\ADR\\Router, Router, phalcon, contracts_adr_router_router, phalcon_contracts_adr_router_router_method_entry);

	return SUCCESS;
}

ZEPHIR_DOC_METHOD(Phalcon_Contracts_ADR_Router_Router, match);
ZEPHIR_DOC_METHOD(Phalcon_Contracts_ADR_Router_Router, setBaseNamespace);
ZEPHIR_DOC_METHOD(Phalcon_Contracts_ADR_Router_Router, setMiddlewareMap);
