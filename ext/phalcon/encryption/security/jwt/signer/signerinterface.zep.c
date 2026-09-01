
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

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
 * Interface for JWT Signer classes
 *
 * @psalm-suppress DeprecatedInterface
 * @deprecated Will be removed in a future major release.
 *             Use {@see \Phalcon\Contracts\Encryption\Security\JWT\Signer\Signer} instead.
 */
ZEPHIR_INIT_CLASS(Phalcon_Encryption_Security_JWT_Signer_SignerInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Encryption\\Security\\JWT\\Signer, SignerInterface, phalcon, encryption_security_jwt_signer_signerinterface, NULL);

	zend_class_implements(phalcon_encryption_security_jwt_signer_signerinterface_ce, 1, phalcon_contracts_encryption_security_jwt_signer_signer_ce);
	return SUCCESS;
}

