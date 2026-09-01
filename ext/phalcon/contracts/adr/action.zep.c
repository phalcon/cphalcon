
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
 * Marker contract for a per-endpoint Action. An Action is a Handler:
 * `__invoke(request): response`.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_ADR_Action)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\ADR, Action, phalcon, contracts_adr_action, NULL);

	zend_class_implements(phalcon_contracts_adr_action_ce, 1, phalcon_contracts_adr_handler_ce);
	return SUCCESS;
}

