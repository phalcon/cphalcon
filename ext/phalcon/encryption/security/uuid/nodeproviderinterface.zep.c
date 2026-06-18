
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
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-uuid
 * @link    https://github.com/sinbadxiii/cphalcon-uuid
 */
/**
 * @psalm-suppress DeprecatedInterface
 * @deprecated Will be removed in a future major release.
 *             Use {@see \Phalcon\Contracts\Encryption\Security\Uuid\NodeProvider} instead.
 */
ZEPHIR_INIT_CLASS(Phalcon_Encryption_Security_Uuid_NodeProviderInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Encryption\\Security\\Uuid, NodeProviderInterface, phalcon, encryption_security_uuid_nodeproviderinterface, NULL);

	zend_class_implements(phalcon_encryption_security_uuid_nodeproviderinterface_ce, 1, phalcon_contracts_encryption_security_uuid_nodeprovider_ce);
	return SUCCESS;
}

