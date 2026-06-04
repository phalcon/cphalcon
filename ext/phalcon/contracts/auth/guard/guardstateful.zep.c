
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
 * Implemented by guards backed by persistent state (sessions/cookies).
 *
 * @phpstan-import-type AuthCredentials from Adapter
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Auth_Guard_GuardStateful)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Auth\\Guard, GuardStateful, phalcon, contracts_auth_guard_guardstateful, phalcon_contracts_auth_guard_guardstateful_method_entry);

	return SUCCESS;
}

/**
 * Attempts to authenticate the user with the given credentials and, on
 * success, persists the resulting state on the guard.
 *
 * @phpstan-param AuthCredentials $credentials
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Guard_GuardStateful, attempt);
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Guard_GuardStateful, login);
/**
 * Logs in the user identified by $id. Returns the resolved user on
 * success or false when no user matches the id.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Guard_GuardStateful, loginById);
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Guard_GuardStateful, logout);
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_Guard_GuardStateful, viaRemember);
