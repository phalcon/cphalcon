
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
 * Central registry of the array shapes used across the Paginator namespace.
 *
 * This is a type registry, not a contract. It declares no members and must
 * not be implemented; it exists only so that every shape below has a single
 * definition, imported where it is needed with a phpstan-import-type tag
 * naming this interface as the source.
 *
 * Alias names are prefixed with `paginator_` because PHPStan resolves
 * imported type names per file and has no namespacing for them: the prefix
 * is what keeps generic names such as `config` from clashing with an alias
 * imported from another namespace into the same file.
 *
 * @phpstan-type paginator_aliases array<string, string>
 * @phpstan-type paginator_columns array<array-key, string>|string
 * @phpstan-type paginator_config array<string, mixed>
 * @phpstan-type paginator_count_object object{rowcount: float|int|string}
 * @phpstan-type paginator_count_row array{rowcount: float|int|string}
 * @phpstan-type paginator_cursor_items array<array-key, array<array-key, mixed>>
 * @phpstan-type paginator_factory_options array{
 *     adapter: string,
 *     builder?: Builder,
 *     limit?: int,
 *     options?: paginator_config,
 *     page?: int,
 * }
 * @phpstan-type paginator_group_by array<array-key, string>
 * @phpstan-type paginator_properties array<string, mixed>
 * @phpstan-type paginator_query_sql array{
 *     bind: array<array-key, mixed>,
 *     bindTypes: array<array-key, mixed>,
 *     sql: string,
 * }
 * @phpstan-type paginator_services array<string, class-string<Adapter>>
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Paginator_PaginatorTypes)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Paginator, PaginatorTypes, phalcon, contracts_paginator_paginatortypes, NULL);

	return SUCCESS;
}

