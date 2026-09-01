
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
 * Implementation of this file has been influenced by phalcon-api and AuraPHP
 * @link    https://github.com/phalcon/phalcon-api
 * @license https://github.com/phalcon/phalcon-api/blob/master/LICENSE
 * @link    https://github.com/auraphp/Aura.Payload
 * @license https://github.com/auraphp/Aura.Payload/blob/3.x/LICENSE
 *
 * @see Original inspiration for the https://github.com/phalcon/phalcon-api
 */
/**
 * Canonical read-only contract for a domain payload.
 *
 * Responders consume a finished payload through this contract (the getters),
 * narrowing the surface to the read side of the Action-Domain-Responder
 * boundary.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Domain_Payload_Readable)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Domain\\Payload, Readable, phalcon, contracts_domain_payload_readable, phalcon_contracts_domain_payload_readable_method_entry);

	return SUCCESS;
}

/**
 * Gets the potential exception thrown in the domain layer
 *
 * @return Throwable|null
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Domain_Payload_Readable, getException);
/**
 * Gets arbitrary extra values produced by the domain layer.
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Domain_Payload_Readable, getExtras);
/**
 * Gets the input received by the domain layer.
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Domain_Payload_Readable, getInput);
/**
 * Gets the messages produced by the domain layer.
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Domain_Payload_Readable, getMessages);
/**
 * Gets the output produced from the domain layer.
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Domain_Payload_Readable, getOutput);
/**
 * Gets the status of this payload.
 *
 * Status values are drawn from the `Status` vocabulary.
 *
 * @return mixed
 *
 * @see \Phalcon\Domain\Payload\Status
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Domain_Payload_Readable, getStatus);
