
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
 * The business-logic seam - HTTP-free. Generic over its input type via docblock
 * generics: the runtime parameter is `var`, and the generic is enforced by the
 * IDE and static analysis through the generated stubs.
 *
 * @template TInput of object
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_ADR_Domain)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\ADR, Domain, phalcon, contracts_adr_domain, phalcon_contracts_adr_domain_method_entry);

	return SUCCESS;
}

/**
 * @param TInput $input
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_ADR_Domain, __invoke);
