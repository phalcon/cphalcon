
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
ZEPHIR_INIT_CLASS(Phalcon_Security_JWT_Signer_SignerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Security\\JWT\\Signer, SignerInterface, phalcon, security_jwt_signer_signerinterface, phalcon_security_jwt_signer_signerinterface_method_entry);

	return SUCCESS;

}

/**
 * Return the value that is used for the "alg" header
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Security_JWT_Signer_SignerInterface, getAlgHeader);

/**
 * Return the algorithm used
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Security_JWT_Signer_SignerInterface, getAlgorithm);

/**
 * Sign a payload using the passphrase
 *
 * @param string $payload
 * @param string $passphrase
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Security_JWT_Signer_SignerInterface, sign);

/**
 * Verify a passed source with a payload and passphrase
 *
 * @param string $source
 * @param string $payload
 * @param string $passphrase
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Phalcon_Security_JWT_Signer_SignerInterface, verify);

