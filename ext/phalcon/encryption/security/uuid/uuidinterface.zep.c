
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
 */
/**
 * Marker interface for UUID version adapters.
 *
 * Also carries the standard RFC 4122 namespace UUIDs as constants.
 *
 * @psalm-suppress DeprecatedInterface
 * @deprecated Will be removed in a future major release.
 *             Use {@see \Phalcon\Contracts\Encryption\Security\Uuid\Uuid} instead.
 */
ZEPHIR_INIT_CLASS(Phalcon_Encryption_Security_Uuid_UuidInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Encryption\\Security\\Uuid, UuidInterface, phalcon, encryption_security_uuid_uuidinterface, NULL);

	zend_class_implements(phalcon_encryption_security_uuid_uuidinterface_ce, 1, phalcon_contracts_encryption_security_uuid_uuid_ce);
	return SUCCESS;
}

