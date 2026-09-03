
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
 * Implementation of this file has been influenced by AtlasPHP
 *
 * @link    https://github.com/atlasphp/Atlas.Pdo
 * @license https://github.com/atlasphp/Atlas.Pdo/blob/1.x/LICENSE.md
 */
/**
 * Central registry of the array shapes used across the DataMapper namespace.
 *
 * @phpstan-type datamapper_pdo_options array<int, mixed>
 * @phpstan-type datamapper_queries list<string>
 * @phpstan-type datamapper_connection_arguments array{
 *     0: string,
 *     1: string|null,
 *     2: string|null,
 *     3: datamapper_pdo_options,
 *     4: datamapper_queries,
 * }
 * @phpstan-type datamapper_call_arguments list<mixed>
 * @phpstan-type datamapper_constructor_arguments list<mixed>
 * @phpstan-type datamapper_drivers list<string>
 * @phpstan-type datamapper_error_info array{0: string, 1?: int|null, 2?: string|null}
 * @phpstan-type datamapper_fetch_arguments list<int>
 * @phpstan-type datamapper_fetch_result array<array-key, mixed>
 * @phpstan-type datamapper_values array<array-key, mixed>
 * @phpstan-type datamapper_row array<string, mixed>
 * @phpstan-type datamapper_rows list<datamapper_row>
 * @phpstan-type datamapper_assoc_rows array<array-key, datamapper_row>
 * @phpstan-type datamapper_column list<mixed>
 * @phpstan-type datamapper_grouped_rows array<array-key, mixed>
 * @phpstan-type datamapper_objects list<object>
 * @phpstan-type datamapper_pairs array<array-key, mixed>
 * @phpstan-type datamapper_quotable bool|float|int|string|\Stringable|null
 * @phpstan-type datamapper_quote_value datamapper_quotable|array<array-key, datamapper_quotable>
 * @phpstan-type datamapper_quote_names array{
 *     prefix: string,
 *     suffix: string,
 *     find: string,
 *     replace: string,
 * }
 * @phpstan-type datamapper_connection_factory callable(): ConnectionInterface
 * @phpstan-type datamapper_connection_factories array<string, datamapper_connection_factory>
 * @phpstan-type datamapper_connection_instances array<string, ConnectionInterface>
 * @phpstan-type datamapper_profiler_context array<string, mixed>
 * @phpstan-type datamapper_log_messages list<string>
 * @phpstan-type datamapper_bind_entry array{0: mixed, 1: int}
 * @phpstan-type datamapper_bind_store array<string, datamapper_bind_entry>
 * @phpstan-type datamapper_bind_values array<string, mixed>
 * @phpstan-type datamapper_clauses array<array-key, string>
 * @phpstan-type datamapper_columns array<array-key, string>
 * @phpstan-type datamapper_column_values array<array-key, mixed>
 * @phpstan-type datamapper_flags array<string, true>
 * @phpstan-type datamapper_from_tables array<int, array<int, string>>
 * @phpstan-type datamapper_query_store array{
 *     COLUMNS: datamapper_clauses,
 *     FLAGS: datamapper_flags,
 *     FROM: string|datamapper_from_tables,
 *     GROUP: datamapper_clauses,
 *     HAVING: datamapper_clauses,
 *     LIMIT: int,
 *     OFFSET: int,
 *     ORDER: datamapper_clauses,
 *     RETURNING?: datamapper_clauses,
 *     UNION: datamapper_clauses,
 *     WHERE: datamapper_clauses,
 * }
 * @phpstan-type datamapper_select_store array{
 *     COLUMNS: datamapper_clauses,
 *     FLAGS: datamapper_flags,
 *     FROM: datamapper_from_tables,
 *     GROUP: datamapper_clauses,
 *     HAVING: datamapper_clauses,
 *     LIMIT: int,
 *     OFFSET: int,
 *     ORDER: datamapper_clauses,
 *     UNION: datamapper_clauses,
 *     WHERE: datamapper_clauses,
 * }
 * @phpstan-type datamapper_write_store array{
 *     COLUMNS: array<string, string>,
 *     FLAGS: datamapper_flags,
 *     FROM: string,
 *     GROUP: datamapper_clauses,
 *     HAVING: datamapper_clauses,
 *     LIMIT: int,
 *     OFFSET: int,
 *     ORDER: datamapper_clauses,
 *     RETURNING: datamapper_clauses,
 *     UNION: datamapper_clauses,
 *     WHERE: datamapper_clauses,
 * }
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_DataMapper_DataMapperTypes)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\DataMapper, DataMapperTypes, phalcon, contracts_datamapper_datamappertypes, NULL);

	return SUCCESS;
}

