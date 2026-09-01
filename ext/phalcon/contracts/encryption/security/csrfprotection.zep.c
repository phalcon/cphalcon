
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
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Encryption_Security_CsrfProtection)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Encryption\\Security, CsrfProtection, phalcon, contracts_encryption_security_csrfprotection, phalcon_contracts_encryption_security_csrfprotection_method_entry);

	return SUCCESS;
}

ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Security_CsrfProtection, getToken);
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Security_CsrfProtection, getTokenKey);
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Security_CsrfProtection, checkToken);
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Security_CsrfProtection, destroyToken);
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Security_CsrfProtection, getRequestToken);
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Security_CsrfProtection, getSessionToken);
