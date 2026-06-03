
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
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */
/**
 * Capability extension implemented by adapters that support remember-me.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Auth_Adapter_RememberAdapter)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Auth\\Adapter, RememberAdapter, phalcon, contracts_auth_adapter_rememberadapter, phalcon_contracts_auth_adapter_rememberadapter_method_entry);

	zend_class_implements(phalcon_contracts_auth_adapter_rememberadapter_ce, 1, phalcon_contracts_auth_adapter_adapter_ce);
	return SUCCESS;
}

/**
 * Create and persist a new remember token for the user.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Adapter_RememberAdapter, createRememberToken);
/**
 * Retrieve a user by the remember-me cookie payload.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Adapter_RememberAdapter, retrieveByToken);
