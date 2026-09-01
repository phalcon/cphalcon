
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
 * Authentication adapter contract.
 *
 * Adapters look users up by credentials or by identifier and verify the
 * password against the stored hash. The credential payload is intentionally
 * unsealed: any user-row field may be used as the lookup key, plus an
 * optional `password` entry that is ignored during the row match and
 * consumed only by validateCredentials().
 *
 * @phpstan-type AuthCredentials array<string, mixed>
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Auth_Adapter_Adapter)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Auth\\Adapter, Adapter, phalcon, contracts_auth_adapter_adapter, phalcon_contracts_auth_adapter_adapter_method_entry);

	return SUCCESS;
}

/**
 * Build an adapter from a flat options map. Used by ManagerFactory to
 * wire adapters from the application config; each implementation is
 * free to interpret the option keys it cares about.
 *
 * @param array<string, mixed> $options
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Adapter_Adapter, fromOptions);
/**
 * Find a user matching the given credentials (e.g. ['email' => 'a@b']).
 * The 'password' key, if present, is ignored during the lookup.
 * Returns null if no user matches.
 *
 * @phpstan-param AuthCredentials $credentials
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Adapter_Adapter, retrieveByCredentials);
/**
 * Find a user by their unique identifier.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Adapter_Adapter, retrieveById);
/**
 * Validate the provided credentials against the given user.
 * Implementations typically verify the password hash held under the
 * 'password' key.
 *
 * @phpstan-param AuthCredentials $credentials
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Adapter_Adapter, validateCredentials);
