
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
 * Central registry of the array shapes used across the Auth namespace.
 *
 * This is a type registry, not a contract. It declares no members and must
 * not be implemented; it exists only so that every shape below has a single
 * definition, imported where it is needed with a phpstan-import-type tag
 * naming this interface as the source.
 *
 * Alias names are prefixed with `auth_` because PHPStan resolves imported
 * type names per file and has no namespacing for them: the prefix is what
 * keeps generic names such as `adapter_config` from clashing with an alias
 * imported from another namespace into the same file.
 *
 * @phpstan-type auth_credentials array<string, mixed>
 * @phpstan-type auth_user_row array{id?: int|string}&array<string, mixed>
 * @phpstan-type auth_adapter_config array{
 *     name: string,
 *     options?: array<string, mixed>,
 * }
 * @phpstan-type auth_guard_config array{
 *     type: string,
 *     default?: bool,
 *     adapter: auth_adapter_config,
 *     options?: array<string, mixed>,
 * }
 * @phpstan-type auth_config array{
 *     guards?: array<string, auth_guard_config>,
 *     access?: array<string, class-string<Access>>,
 * }
 * @phpstan-type auth_access_context array{
 *     handler?: string,
 *     module?: string,
 *     params?: array<int|string, mixed>,
 * }
 * @phpstan-type auth_forward_target array{
 *     controller?: string,
 *     action?: string,
 *     params?: array<int|string, mixed>,
 *     namespace?: string,
 *     task?: string,
 * }&array<string, mixed>
 * @phpstan-type auth_remember_payload array{
 *     id?: int|string,
 *     token?: string,
 *     user_agent?: string,
 * }
 * @phpstan-type auth_acl_options array{
 *     guestRole?: string,
 *     moduleSeparator?: string,
 * }
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Auth_AuthTypes)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Auth, AuthTypes, phalcon, contracts_auth_authtypes, NULL);

	return SUCCESS;
}

