
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
 * Implemented by authenticatable models that support remember-me tokens.
 * This is intentionally separate from AuthUser so that adapters which do
 * not support remember-me are not forced to implement it.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Auth_AuthRemember)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Auth, AuthRemember, phalcon, contracts_auth_authremember, phalcon_contracts_auth_authremember_method_entry);

	return SUCCESS;
}

/**
 * Persists a new remember token for the user.
 *
 * @param string      $token
 * @param string|null $userAgent
 *
 * @return RememberToken
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_AuthRemember, createRememberToken);
/**
 * Returns the remember token entry matching the given token value,
 * or null if not found.
 *
 * @param string $token
 *
 * @return RememberToken|null
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_AuthRemember, getRememberToken);
