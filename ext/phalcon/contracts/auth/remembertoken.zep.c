
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
 * A persisted remember-me token row.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Auth_RememberToken)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Auth, RememberToken, phalcon, contracts_auth_remembertoken, phalcon_contracts_auth_remembertoken_method_entry);

	return SUCCESS;
}

/**
 * Deletes the token from storage.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_RememberToken, delete);
/**
 * Returns the token value stored for this remember entry.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_RememberToken, getToken);
/**
 * Returns the user agent associated with this token, if any.
 *
 * @return string|null
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Auth_RememberToken, getUserAgent);
