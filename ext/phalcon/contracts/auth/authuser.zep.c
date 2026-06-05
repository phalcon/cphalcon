
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
 * Implemented by user models that can be authenticated.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Auth_AuthUser)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Auth, AuthUser, phalcon, contracts_auth_authuser, phalcon_contracts_auth_authuser_method_entry);

	return SUCCESS;
}

/**
 * Returns the unique identifier for the authenticatable user
 * (e.g. the primary key). Implementations MUST return a non-null
 * scalar; if a record cannot produce one, the implementation should
 * fail at construction time rather than returning null.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_AuthUser, getAuthIdentifier);
/**
 * Returns the hashed password for the authenticatable user.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_AuthUser, getAuthPassword);
