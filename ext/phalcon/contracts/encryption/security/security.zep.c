
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
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Encryption_Security_Security)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Encryption\\Security, Security, phalcon, contracts_encryption_security_security, NULL);

	zend_class_implements(phalcon_contracts_encryption_security_security_ce, 1, phalcon_contracts_encryption_security_cryptoutils_ce);
	zend_class_implements(phalcon_contracts_encryption_security_security_ce, 1, phalcon_contracts_encryption_security_csrfprotection_ce);
	zend_class_implements(phalcon_contracts_encryption_security_security_ce, 1, phalcon_contracts_encryption_security_passwordsecurity_ce);
	return SUCCESS;
}

