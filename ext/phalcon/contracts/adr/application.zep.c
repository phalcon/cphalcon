
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
 * Handles a request end to end: routes it, dispatches the Action and returns
 * the response, routing any error through the error responder.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_ADR_Application)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\ADR, Application, phalcon, contracts_adr_application, phalcon_contracts_adr_application_method_entry);

	return SUCCESS;
}

ZEPHIR_DOC_METHOD(Phalcon_Contracts_ADR_Application, handle);
