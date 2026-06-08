
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
 * @phpstan-import-type AuthCredentials from Adapter
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Auth_Guard_Guard)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Auth\\Guard, Guard, phalcon, contracts_auth_guard_guard, phalcon_contracts_auth_guard_guard_method_entry);

	return SUCCESS;
}

/**
 * Build a guard from an adapter, the application container, and a flat
 * options map. Used by ManagerFactory to wire guards from the
 * application config; each implementation resolves the framework
 * services it needs from the container.
 *
 * The container is Container-first: pass a Phalcon\Container\Container.
 * The legacy Phalcon\Di\Di is also supported with provisions - its
 * service definitions must be pre-registered (no autowiring).
 *
 * @param Collection|DiInterface $container
 * @param array<string, mixed>   $options
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Guard_Guard, fromOptions);
/**
 * Whether the current request is authenticated.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Guard_Guard, check);
/**
 * Returns the last user the guard tried to authenticate during this
 * request, regardless of success.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Guard_Guard, getLastUserAttempted);
/**
 * Whether the current request is unauthenticated.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Guard_Guard, guest);
/**
 * Whether the guard currently holds a resolved user.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Guard_Guard, hasUser);
/**
 * Returns the authenticated user's identifier, or null when no
 * authenticated user is present.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Guard_Guard, id);
/**
 * Sets the current user explicitly. Returns $this for fluent chaining.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Guard_Guard, setUser);
/**
 * Returns the resolved user for the current request, or null.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Guard_Guard, user);
/**
 * Validates the given credentials without logging in.
 *
 * @phpstan-param AuthCredentials $credentials
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Guard_Guard, validate);
