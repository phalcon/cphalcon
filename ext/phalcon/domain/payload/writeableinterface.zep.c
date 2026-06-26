
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
 *
 * @psalm-suppress DeprecatedInterface
 * @deprecated Will be removed in a future major release.
 *             Use {@see \Phalcon\Contracts\Domain\Payload\Writeable} instead.
 */
ZEPHIR_INIT_CLASS(Phalcon_Domain_Payload_WriteableInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Domain\\Payload, WriteableInterface, phalcon, domain_payload_writeableinterface, NULL);

	zend_class_implements(phalcon_domain_payload_writeableinterface_ce, 1, phalcon_contracts_domain_payload_writeable_ce);
	return SUCCESS;
}

