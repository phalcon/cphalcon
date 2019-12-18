
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
 * Implementation of this file has been influenced by phalcon-api and AuraPHP
 * @link    https://github.com/phalcon/phalcon-api
 * @license https://github.com/phalcon/phalcon-api/blob/master/LICENSE
 * @link    https://github.com/auraphp/Aura.Payload
 * @license https://github.com/auraphp/Aura.Payload/blob/3.x/LICENSE
 *
 * @see Original inspiration for the https://github.com/phalcon/phalcon-api
 */
/**
 * This interface is used for consumers (read only)
 */
ZEPHIR_INIT_CLASS(Phalcon_Domain_Payload_ReadableInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Domain\\Payload, ReadableInterface, phalcon, domain_payload_readableinterface, phalcon_domain_payload_readableinterface_method_entry);

	return SUCCESS;

}

/**
 * Gets the potential exception thrown in the domain layer
 *
 * @return Throwable|null
 */
ZEPHIR_DOC_METHOD(Phalcon_Domain_Payload_ReadableInterface, getException);

/**
 * Gets arbitrary extra values produced by the domain layer.
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Domain_Payload_ReadableInterface, getExtras);

/**
 * Gets the input received by the domain layer.
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Domain_Payload_ReadableInterface, getInput);

/**
 * Gets the messages produced by the domain layer.
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Domain_Payload_ReadableInterface, getMessages);

/**
 * Gets the output produced from the domain layer.
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Domain_Payload_ReadableInterface, getOutput);

/**
 * Gets the status of this payload.
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Domain_Payload_ReadableInterface, getStatus);

