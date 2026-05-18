
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
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Encryption_Security_CryptoUtils)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Encryption\\Security, CryptoUtils, phalcon, contracts_encryption_security_cryptoutils, phalcon_contracts_encryption_security_cryptoutils_method_entry);

	return SUCCESS;
}

ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Security_CryptoUtils, computeHmac);
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Security_CryptoUtils, getRandom);
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Security_CryptoUtils, getRandomBytes);
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Security_CryptoUtils, setRandomBytes);
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Security_CryptoUtils, getSaltBytes);
