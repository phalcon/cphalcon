
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
 */
/**
 * Central registry of the array shapes used across the Encryption namespace.
 *
 * This is a type registry, not a contract. It declares no members and must
 * not be implemented; it exists only so that every shape below has a single
 * definition, imported where it is needed with a phpstan-import-type tag
 * naming this interface as the source.
 *
 * Alias names are prefixed with `encryption_` because PHPStan resolves
 * imported type names per file and has no namespacing for them: the prefix is
 * what keeps generic names such as `options` or `claims` from clashing with an
 * alias imported from another namespace into the same file.
 *
 * The list is alphabetical, with one exception: an alias that another alias
 * names must be defined before it.
 *
 * @phpstan-type encryption_cipher_list array<array-key, string>
 * @phpstan-type encryption_hash_algorithms array<array-key, string>
 * @phpstan-type encryption_hash_information array{
 *     algo: int|string|null,
 *     algoName: string,
 *     options: array<array-key, mixed>,
 * }
 * @phpstan-type encryption_hash_length_cache array<string, int>
 * @phpstan-type encryption_hash_options array<string, mixed>
 * @phpstan-type encryption_jwt_audience array<array-key, string>|string
 * @phpstan-type encryption_jwt_claims array<string, mixed>
 * @phpstan-type encryption_jwt_errors array<array-key, string>
 * @phpstan-type encryption_jwt_headers array<string, string>
 * @phpstan-type encryption_jwt_item_data array<string, mixed>
 * @phpstan-type encryption_jwt_payload array<string, mixed>
 * @phpstan-type encryption_jwt_validator_claims array<string, mixed>
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Encryption_EncryptionTypes)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Encryption, EncryptionTypes, phalcon, contracts_encryption_encryptiontypes, NULL);

	return SUCCESS;
}

