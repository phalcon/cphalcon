
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
 *
 * Implementation of this file has also been heavily influenced by Autoroute.
 *
 * @link    https://pmjones.io/adr/
 *
 * @link    https://github.com/pmjones/AutoRoute
 * @license https://github.com/pmjones/AutoRoute/blob/2.x/LICENSE.md
 */
/**
 * Maps a request to an Action by convention: the HTTP method and the static
 * path segments identify the class; trailing segments become positional
 * request attributes. No route table.
 *
 * @phpstan-import-type adr_middleware_map from ADRTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_ADR_Router_Router)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\ADR\\Router, Router, phalcon, contracts_adr_router_router, phalcon_contracts_adr_router_router_method_entry);

	return SUCCESS;
}

/**
 * Every Action class this router would try for the given method and path,
 * in the order it tries them. The first that exists wins at match time.
 * Namespace descent consults the filesystem, so the list depends on the
 * action directory.
 *
 * @return list<class-string>
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_ADR_Router_Router, candidatesFor);
/**
 * The class this convention names for a fully static path, derived without
 * consulting the filesystem - the exact inverse of pathFor().
 *
 * For tooling that needs the name before the code exists: generators,
 * linters, documentation and "no action found; expected X" diagnostics.
 * Pass the static prefix only; placeholders are the caller's concern.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_ADR_Router_Router, classFor);
ZEPHIR_DOC_METHOD(Phalcon_Contracts_ADR_Router_Router, match);
/**
 * The HTTP method the given Action class answers, uppercased, or null when
 * the class is not one this convention would have produced.
 *
 * The counterpart to pathFor(): same argument, same null semantics, so a
 * caller that accepts one answer accepts the other. Together they are the
 * whole inverse of classFor().
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_ADR_Router_Router, methodFor);
/**
 * The canonical static path the given Action class answers, or null when
 * the class is not derivable from the base namespace. Positional
 * attributes are not part of the canonical path.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_ADR_Router_Router, pathFor);
/**
 * The filesystem root that backs the base namespace. The router uses it to
 * decide whether a path segment names a sub-namespace.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_ADR_Router_Router, setActionDirectory);
ZEPHIR_DOC_METHOD(Phalcon_Contracts_ADR_Router_Router, setBaseNamespace);
/**
 * @phpstan-param adr_middleware_map $middlewareMap
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_ADR_Router_Router, setMiddlewareMap);
/**
 * The single delimiter between words in a path segment. Applied
 * symmetrically when deriving a class name from a path and a path from a
 * class name. Any other character is literal.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_ADR_Router_Router, setWordSeparator);
