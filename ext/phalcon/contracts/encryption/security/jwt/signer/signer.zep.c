
#ifdef HAVE_CONFIG_H
#include "../../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../../php_ext.h"
#include "../../../../../../ext.h"

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
 * Canonical contract for JWT Signer classes
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Encryption_Security_JWT_Signer_Signer)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Encryption\\Security\\JWT\\Signer, Signer, phalcon, contracts_encryption_security_jwt_signer_signer, phalcon_contracts_encryption_security_jwt_signer_signer_method_entry);

	return SUCCESS;
}

/**
 * Return the value that is used for the "alg" header
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Security_JWT_Signer_Signer, getAlgHeader);
/**
 * Return the algorithm used
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Security_JWT_Signer_Signer, getAlgorithm);
/**
 * Sign a payload using the passphrase
 *
 * @param string $payload
 * @param string $passphrase
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Security_JWT_Signer_Signer, sign);
/**
 * Verify a passed source with a payload and passphrase
 *
 * @param string $source
 * @param string $payload
 * @param string $passphrase
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Security_JWT_Signer_Signer, verify);
