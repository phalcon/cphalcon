/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Db;

use Phalcon\Db\CheckInterface;
use Phalcon\Db\ColumnInterface;
use Phalcon\Db\IndexInterface;
use Phalcon\Db\Profiler\Item;
use Phalcon\Db\RawValue;
use Phalcon\Db\ReferenceInterface;

/**
 * Central registry of the array shapes used across the Db namespace.
 *
 * This is a type registry, not a contract. It declares no members and must
 * not be implemented; it exists only so that every shape below has a single
 * definition, imported where it is needed with a phpstan-import-type tag
 * naming this interface as the source.
 *
 * Alias names are prefixed with `db_` because PHPStan resolves imported type
 * names per file and has no namespacing for them: the prefix is what keeps
 * generic names such as `row` or `options` from clashing with an alias
 * imported from another namespace into the same file.
 *
 * The list is alphabetical, with one exception: an alias that another alias
 * names must be defined before it. Psalm reads the aliases in file order and
 * cannot resolve a forward reference; it reports the name as a missing class
 * instead. PHPStan does not care about the order, so a forward reference is
 * invisible until the cphalcon stubs are analyzed.
 *
 * @phpstan-type db_bind_counts array<string, int>
 * @phpstan-type db_bind_params array<array-key, mixed>
 * @phpstan-type db_bind_types array<array-key, int>
 * @phpstan-type db_bound_params array<string, list<mixed>|string|null>
 * @phpstan-type db_check_definition array{
 *     expression?: mixed,
 * }
 * @phpstan-type db_column_definition array{
 *     after?: string|null,
 *     array?: bool,
 *     autoIncrement?: bool,
 *     bindType?: int,
 *     comment?: string|null,
 *     default?: mixed,
 *     first?: bool,
 *     generated?: mixed,
 *     generationStored?: bool,
 *     invisible?: bool,
 *     isNumeric?: bool,
 *     notNull?: bool,
 *     primary?: bool,
 *     scale?: int,
 *     size?: int|string,
 *     type?: int|string,
 *     typeReference?: int,
 *     typeValues?: array<array-key, string>|int|string,
 *     unsigned?: bool,
 * }
 * @phpstan-type db_columns array<array-key, ColumnInterface>
 * @phpstan-type db_column_list array<array-key, array<array-key, mixed>|string>
 * @phpstan-type db_column_names array<array-key, string>
 * @phpstan-type db_constructor_arguments list<mixed>
 * @phpstan-type db_custom_functions array<string, callable>
 * @phpstan-type db_describe_row array<array-key, string|null>
 * @phpstan-type db_descriptor array<string, mixed>
 * @phpstan-type db_dict array<string, mixed>
 * @phpstan-type db_dsn_defaults array<string, string>
 * @phpstan-type db_factory_config array{
 *     adapter: string,
 *     options?: db_descriptor,
 * }
 * @phpstan-type db_error_info array{0: string, 1?: int|null, 2?: string|null}
 * @phpstan-type db_geometry_coordinates list<float>
 * @phpstan-type db_identifier array<array-key, string>|float|int|string
 * @phpstan-type db_table_identifier array<array-key, string>|string
 * @phpstan-type db_index_columns array<array-key, RawValue|string>
 * @phpstan-type db_index_directions array<array-key, string>
 * @phpstan-type db_index_build array{
 *     columns: db_index_columns,
 *     directions: db_index_directions,
 *     invisible?: bool,
 *     type: string,
 * }
 * @phpstan-type db_index_definition array{
 *     columns: db_index_columns,
 *     concurrently?: bool,
 *     directions?: array<array-key, string>,
 *     invisible?: bool,
 *     type?: string,
 *     where?: string,
 * }
 * @phpstan-type db_indexes array<array-key, IndexInterface>
 * @phpstan-type db_limit_number array{0: mixed, 1?: mixed}|int
 * @phpstan-type db_pdo_options array<int, mixed>
 * @phpstan-type db_profiler_items array<array-key, Item>
 * @phpstan-type db_reference_build array{
 *     columns: db_column_names,
 *     onDelete: string|null,
 *     onUpdate: string|null,
 *     referencedColumns: db_column_names,
 *     referencedSchema: string|null,
 *     referencedTable: string,
 * }
 * @phpstan-type db_reference_definition array{
 *     columns?: db_column_names,
 *     onDelete?: string|null,
 *     onUpdate?: string|null,
 *     referencedColumns?: db_column_names,
 *     referencedSchema?: string|null,
 *     referencedTable?: string,
 *     schema?: string|null,
 * }
 * @phpstan-type db_references array<array-key, ReferenceInterface>
 * @phpstan-type db_row array<array-key, mixed>
 * @phpstan-type db_rows array<array-key, db_row>
 * @phpstan-type db_setup_options array{
 *     escapeSqlIdentifiers?: bool|int,
 *     forceCasting?: bool|int,
 * }
 * @phpstan-type db_table_options array<string, mixed>
 * @phpstan-type db_table_definition array{
 *     checks?: array<array-key, CheckInterface>,
 *     columns?: db_columns,
 *     indexes?: db_indexes,
 *     options?: db_table_options,
 *     references?: db_references,
 *     temporary?: bool,
 * }
 * @phpstan-type db_table_names array<array-key, string>
 * @phpstan-type db_value_placeholder array{
 *     placeholder: string,
 *     bind: bool,
 *     value: mixed,
 *     hasBindType: bool,
 *     bindType: int|null,
 * }
 * @phpstan-type db_view_definition array{
 *     sql?: string,
 * }
 * @phpstan-type db_where_condition array{
 *     bind?: mixed,
 *     bindTypes?: mixed,
 *     conditions?: string,
 * }|string
 *
 * The intermediate representation the dialects consume.
 *
 * `getSqlExpression()` dispatches on the `type` key and each branch reads
 * only the keys its own node kind carries, so a single array shape cannot
 * describe the tree. The alias therefore stays an untyped map, as
 * `mvc_query_ir` does for the PHQL intermediate, and each read narrows the
 * value it needs. A recursive alias is not an option either: PHPStan rejects
 * one.
 *
 * @phpstan-type db_expression array<array-key, mixed>
 * @phpstan-type db_join array<array-key, mixed>
 * @phpstan-type db_joins array<array-key, db_join>
 * @phpstan-type db_limit_expression array<array-key, mixed>
 * @phpstan-type db_select_definition array<array-key, mixed>
 * @phpstan-type db_table_name array{0: string, 1?: string|null, 2?: string|null}|string
 */
interface DbTypes
{
}
