
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
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Encryption_Security_PasswordSecurity)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Encryption\\Security, PasswordSecurity, phalcon, contracts_encryption_security_passwordsecurity, phalcon_contracts_encryption_security_passwordsecurity_method_entry);

	return SUCCESS;
}

ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Security_PasswordSecurity, checkHash);
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Security_PasswordSecurity, hash);
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Security_PasswordSecurity, isLegacyHash);
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Security_PasswordSecurity, getHashInformation);
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Security_PasswordSecurity, getDefaultHash);
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Security_PasswordSecurity, setDefaultHash);
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Security_PasswordSecurity, getWorkFactor);
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Security_PasswordSecurity, setWorkFactor);
