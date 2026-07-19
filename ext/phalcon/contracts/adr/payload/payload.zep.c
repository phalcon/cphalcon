
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
 *
 * Implementation of this file has been influenced by phalcon-api and AuraPHP
 * @link    https://github.com/phalcon/phalcon-api
 * @license https://github.com/phalcon/phalcon-api/blob/master/LICENSE
 * @link    https://github.com/auraphp/Aura.Payload
 * @license https://github.com/auraphp/Aura.Payload/blob/3.x/LICENSE
 *
 * @see Original inspiration for the https://github.com/phalcon/phalcon-api
 */
/**
 * Contract for the immutable payload produced by the domain layer.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_ADR_Payload_Payload)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\ADR\\Payload, Payload, phalcon, contracts_adr_payload_payload, phalcon_contracts_adr_payload_payload_method_entry);

	return SUCCESS;
}

/**
 * Gets the exception thrown in the domain layer, if any.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_ADR_Payload_Payload, getException);
/**
 * Gets the arbitrary extra domain information.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_ADR_Payload_Payload, getExtras);
/**
 * Gets the domain input.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_ADR_Payload_Payload, getInput);
/**
 * Gets the domain messages.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_ADR_Payload_Payload, getMessages);
/**
 * Gets the domain result.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_ADR_Payload_Payload, getResult);
/**
 * Gets the payload status.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_ADR_Payload_Payload, getStatus);
/**
 * Returns a copy of the payload with the given exception.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_ADR_Payload_Payload, withException);
/**
 * Returns a copy of the payload with the given extras.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_ADR_Payload_Payload, withExtras);
/**
 * Returns a copy of the payload with the given input.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_ADR_Payload_Payload, withInput);
/**
 * Returns a copy of the payload with the given messages.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_ADR_Payload_Payload, withMessages);
/**
 * Returns a copy of the payload with the given result.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_ADR_Payload_Payload, withResult);
/**
 * Returns a copy of the payload with the given status.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_ADR_Payload_Payload, withStatus);
