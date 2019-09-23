
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
 * This interface is used for consumers (write)
 */
ZEPHIR_INIT_CLASS(Phalcon_Domain_Payload_WriteableInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Domain\\Payload, WriteableInterface, phalcon, domain_payload_writeableinterface, phalcon_domain_payload_writeableinterface_method_entry);

	return SUCCESS;

}

/**
 * Sets the status of this payload.
 *
 * @param mixed $status The status for this payload.
 */
ZEPHIR_DOC_METHOD(Phalcon_Domain_Payload_WriteableInterface, setStatus);

/**
 *
 * Sets the input received by the domain layer.
 *
 * @param mixed $input The input received by the domain layer.
 *
 */
ZEPHIR_DOC_METHOD(Phalcon_Domain_Payload_WriteableInterface, setInput);

/**
 * Sets the output produced from the domain layer.
 *
 * @param mixed $output The output produced from the domain layer.
 */
ZEPHIR_DOC_METHOD(Phalcon_Domain_Payload_WriteableInterface, setOutput);

/**
 * Sets the messages produced by the domain layer.
 *
 * @param mixed $messages The messages produced by the domain layer.
 */
ZEPHIR_DOC_METHOD(Phalcon_Domain_Payload_WriteableInterface, setMessages);

/**
 * Sets arbitrary extra values produced by the domain layer.
 *
 * @param mixed $extras Arbitrary extra values produced by the domain layer.
 */
ZEPHIR_DOC_METHOD(Phalcon_Domain_Payload_WriteableInterface, setExtras);

