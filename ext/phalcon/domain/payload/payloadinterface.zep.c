
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
 * This interface is used for consumers
 */
ZEPHIR_INIT_CLASS(Phalcon_Domain_Payload_PayloadInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Domain\\Payload, PayloadInterface, phalcon, domain_payload_payloadinterface, NULL);

	zend_class_implements(phalcon_domain_payload_payloadinterface_ce, 1, phalcon_domain_payload_readableinterface_ce);
	zend_class_implements(phalcon_domain_payload_payloadinterface_ce, 1, phalcon_domain_payload_writeableinterface_ce);
	return SUCCESS;
}

