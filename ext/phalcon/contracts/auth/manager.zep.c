
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

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
 * @phpstan-import-type AuthCredentials from Adapter
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Auth_Manager)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Auth, Manager, phalcon, contracts_auth_manager, phalcon_contracts_auth_manager_method_entry);

	return SUCCESS;
}

/**
 * Activates the named access gate for the current request and returns the
 * manager for fluent only()/except() configuration.
 *
 * Enforcement is opt-in and fail-open: when no access has been activated
 * (getAccess() returns null) every dispatch is allowed. An activated gate
 * stays active for subsequent dispatches in the same request (forwards,
 * nested handlers) until it is replaced. Under classic FPM this is scoped
 * to a single request; long-running runtimes must reset it per request.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Manager, access);
/**
 * @phpstan-param array<string, class-string<Access>> $accessList
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Manager, addAccessList);
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Manager, addGuard);
/**
 * @phpstan-param AuthCredentials $credentials
 *
 * @throws Exception
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Manager, attempt);
/**
 * Whether the default guard reports the current request as authenticated.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Manager, check);
/**
 * Restricts the active access gate to skip the listed action names.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Manager, except);
/**
 * Returns the active access gate, or null when none has been activated -
 * in which case listener enforcement is a no-op (see access()).
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Manager, getAccess);
/**
 * @phpstan-return array<string, class-string<Access>>
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Manager, getAccessList);
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Manager, getDefaultGuard);
/**
 * @return array<string, Guard>
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Manager, getGuards);
/**
 * Returns the named guard, or the default guard when $name is null.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Manager, guard);
/**
 * Returns the authenticated user's identifier from the default guard,
 * or null when no authenticated user is present.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Manager, id);
/**
 * Logs the current user out via the default guard.
 *
 * @throws Exception
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Manager, logout);
/**
 * Restricts the active access gate to apply only to the listed action names.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Manager, only);
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Manager, setAccess);
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Manager, setDefaultGuard);
/**
 * Returns the resolved user from the default guard, or null.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Manager, user);
/**
 * Validates the given credentials against the default guard without
 * logging in.
 *
 * @phpstan-param AuthCredentials $credentials
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Manager, validate);
