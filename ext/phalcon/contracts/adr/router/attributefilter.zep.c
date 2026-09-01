
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
 * Validates, casts and converts a router match's positional tail segments into
 * named request attributes, driven by the matched Action's optional static
 * `params()` declaration.
 *
 * @phpstan-import-type adr_filtered_attributes from ADRTypes
 * @phpstan-import-type adr_route_attributes from ADRTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_ADR_Router_AttributeFilter)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\ADR\\Router, AttributeFilter, phalcon, contracts_adr_router_attributefilter, phalcon_contracts_adr_router_attributefilter_method_entry);

	return SUCCESS;
}

/**
 * @phpstan-param class-string          $actionClass
 * @phpstan-param adr_route_attributes  $attributes
 *
 * @phpstan-return adr_filtered_attributes
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_ADR_Router_AttributeFilter, filter);
