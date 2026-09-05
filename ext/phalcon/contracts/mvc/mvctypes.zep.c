
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
 * Central registry of the array shapes used across the Mvc namespace.
 *
 * This is a type registry, not a contract. It declares no members and must
 * not be implemented; it exists only so that every shape below has a single
 * definition, imported where it is needed with a phpstan-import-type tag
 * naming this interface as the source.
 *
 * Alias names are prefixed with `mvc_` because PHPStan resolves imported
 * type names per file and has no namespacing for them: the prefix is what
 * keeps generic names such as `model_find_parameters` from clashing with an
 * alias imported from another namespace into the same file.
 *
 * @phpstan-type mvc_model_find_parameters array{
 *     conditions: string,
 *     bind: array<string, mixed>,
 * }
 * @phpstan-type mvc_router_paths array<string, int|string>
 * @phpstan-type mvc_router_reversed_paths array<int|string, string>
 * @phpstan-type mvc_router_http_methods array<array-key, string>
 * @phpstan-type mvc_router_matches array<int|string, string>
 * @phpstan-type mvc_router_params array<array-key, mixed>
 * @phpstan-type mvc_router_defaults array{
 *     namespace?: scalar,
 *     module?: scalar,
 *     controller?: scalar,
 *     action?: scalar,
 *     params?: mvc_router_params,
 * }
 * @phpstan-type mvc_router_converters array<string, callable>
 * @phpstan-type mvc_router_named_params array{0: string, 1: array<string, int>}
 * @phpstan-type mvc_micro_handler array{
 *     0: array<array-key, string>|string,
 *     1: string,
 *     2: callable|string,
 *     3: string|null,
 * }
 * @phpstan-type mvc_micro_handlers list<mvc_micro_handler>
 * @phpstan-type mvc_model_attributes list<string>
 * @phpstan-type mvc_model_messages list<MessageInterface>
 * @phpstan-type mvc_model_related array<string, mixed>
 * @phpstan-type mvc_model_snapshot array<string, mixed>
 * @phpstan-type mvc_model_sync_related array<string, bool>
 * @phpstan-type mvc_model_serialized array{
 *     attributes: array<string, mixed>,
 *     snapshot: mvc_model_snapshot|null,
 *     dirtyState: int,
 * }
 * @phpstan-type mvc_model_bind_params array<array-key, mixed>
 * @phpstan-type mvc_model_bind_types array<array-key, int>
 * @phpstan-type mvc_model_cache_options array<string, mixed>
 * @phpstan-type mvc_model_data array<array-key, mixed>
 * @phpstan-type mvc_model_parameters array<array-key, mixed>
 * @phpstan-type mvc_metadata_column_map array<string, string>
 * @phpstan-type mvc_metadata_default_values array<string, mixed>
 * @phpstan-type mvc_metadata_index array<array-key, mixed>
 * @phpstan-type mvc_metadata_types array<string, int>
 * @phpstan-type mvc_relation_fields array<array-key, string>|string
 * @phpstan-type mvc_relation_options array<string, mixed>
 * @phpstan-type mvc_query_columns array<array-key, string>|string
 * @phpstan-type mvc_query_ir array<string, mixed>
 * @phpstan-type mvc_query_order array<array-key, string>|string
 * @phpstan-type mvc_criteria_params array{
 *     bind?: mvc_model_bind_params,
 *     bindTypes?: mvc_model_bind_types,
 *     cache?: mvc_model_cache_options,
 *     columns?: mvc_query_columns,
 *     conditions?: string,
 *     di?: DiInterface,
 *     distinct?: mixed,
 *     eager?: array<array-key, mixed>,
 *     for_update?: bool,
 *     group?: mixed,
 *     having?: mixed,
 *     joins?: array<array-key, mixed>,
 *     limit?: array{number: int|string, offset?: int|string}|int,
 *     order?: string,
 *     shared_lock?: bool,
 * }
 * @phpstan-type mvc_router_route_meta array{
 *     pattern: string,
 *     isRegex: bool,
 *     hostname: string|null,
 *     hostRegex: string|null,
 *     beforeMatch: callable|null,
 * }
 * @phpstan-type mvc_router_method_buckets array<string, list<RouteInterface>>
 * @phpstan-type mvc_router_static_buckets array<string, array<string, list<RouteInterface>>>
 * @phpstan-type mvc_router_shadow_buckets array<string, array<string, bool>>
 * @phpstan-type mvc_router_hostname_buckets array<string, array<string, list<int>>>
 * @phpstan-type mvc_router_index_buckets array<string, list<int>>
 * @phpstan-type mvc_router_regex_chunks array<string, list<string>>
 * @phpstan-type mvc_router_regex_disabled array<string, bool>
 * @phpstan-type mvc_router_regex_mark_map array<string, array<int, array<array-key, int>>>
 * @phpstan-type mvc_router_config_route array{
 *     pattern: string,
 *     paths: mvc_router_paths|string,
 *     method?: string,
 *     name?: string,
 *     hostname?: string,
 * }
 * @phpstan-type mvc_router_config_group array{
 *     paths?: mvc_router_paths|string|null,
 *     prefix?: string,
 *     hostname?: string,
 *     routes?: mixed,
 * }
 * @phpstan-type mvc_router_dumped_route array{
 *     class: class-string<RouteInterface>,
 *     pattern: string,
 *     paths: mvc_router_paths,
 *     methods: mvc_router_http_methods|string|null,
 *     hostname: string|null,
 *     name: string|null,
 *     id: string,
 *     beforeMatch: callable|null,
 *     converters: mixed,
 * }
 * @phpstan-type mvc_router_dump array{
 *     version: int,
 *     routes: list<mvc_router_dumped_route>,
 *     methodRoutes: mvc_router_index_buckets,
 *     candidatesByMethod: mvc_router_index_buckets,
 *     staticByMethod: array<string, array<string, list<int>>>,
 *     staticShadowedByMethod: mvc_router_shadow_buckets,
 *     hostnameByMethod: mvc_router_hostname_buckets,
 *     hostnameLessByMethod: mvc_router_index_buckets,
 *     combinedRegexByMethod: mvc_router_regex_chunks,
 *     combinedRegexDisabled: mvc_router_regex_disabled,
 *     combinedRegexMarkMap: mvc_router_regex_mark_map,
 *     routeMeta: array<string, mvc_router_route_meta>,
 * }
 * @phpstan-type mvc_volt_node array<array-key, mixed>
 * @phpstan-type mvc_query_ast array{
 *     columns?: array<array-key, mixed>,
 *     delete?: array<array-key, mixed>,
 *     distinct?: mixed,
 *     fields?: array<array-key, mixed>,
 *     forUpdate?: mixed,
 *     groupBy?: array<array-key, mixed>,
 *     having?: array<array-key, mixed>,
 *     id?: int|string,
 *     joins?: array<array-key, mixed>,
 *     limit?: array<array-key, mixed>,
 *     orderBy?: array<array-key, mixed>,
 *     qualifiedName?: array<array-key, mixed>,
 *     select?: array<string, mixed>,
 *     tables?: array<array-key, mixed>,
 *     type?: int,
 *     update?: array<array-key, mixed>,
 *     values?: array<array-key, mixed>,
 *     where?: array<array-key, mixed>,
 *     ...
 * }
 * @phpstan-type mvc_query_builder_join array{
 *     0: string,
 *     1: string|null,
 *     2: string|null,
 *     3: string|null,
 * }
 * @phpstan-type mvc_query_builder_params array{
 *     0?: array<array-key, mixed>|int|string,
 *     bind?: mvc_model_bind_params,
 *     bindTypes?: mvc_model_bind_types,
 *     columns?: mvc_query_columns,
 *     conditions?: array<array-key, mixed>|string,
 *     distinct?: mixed,
 *     for_update?: bool,
 *     group?: array<array-key, string>|string|null,
 *     having?: string,
 *     joins?: array<array-key, mvc_query_builder_join>,
 *     limit?: array<array-key, mixed>|int|string,
 *     models?: mvc_query_columns,
 *     offset?: int,
 *     order?: array<array-key, int|string>|string,
 *     shared_lock?: bool,
 * }
 * @phpstan-type mvc_metadata_slot array<array-key, mixed>|bool|string|null
 * @phpstan-type mvc_metadata_model array<array-key, mvc_metadata_slot>
 * @phpstan-type mvc_metadata_store array<string, mvc_metadata_model>
 * @phpstan-type mvc_metadata_column_maps array<array-key, mvc_metadata_column_map|mvc_metadata_slot>
 * @phpstan-type mvc_metadata_column_map_store array<string, mvc_metadata_column_maps>
 * @phpstan-type mvc_manager_relations array<string, list<\Phalcon\Mvc\Model\RelationInterface>>
 * @phpstan-type mvc_hydration_column_map array<array-key, array<array-key, int|string>|int|string>
 * @phpstan-type mvc_eager_node array{
 *     options: mvc_model_parameters,
 *     children: array<string, mixed>,
 * }
 * @phpstan-type mvc_eager_tree array<string, mvc_eager_node>
 * @phpstan-type mvc_eager_map_node array{
 *     fields: array<array-key, string>,
 *     records: array<string, mixed>,
 *     empty: \Phalcon\Mvc\Model\Resultset\Simple|null,
 * }
 * @phpstan-type mvc_eager_map array<string, mvc_eager_map_node>
 * @phpstan-type mvc_eager_parents array<array-key, \Phalcon\Mvc\EntityInterface|array<array-key, mixed>>
 * @phpstan-type mvc_resultset_object_column array{
 *     type: string,
 *     column: string,
 *     attributes: array<array-key, string>,
 *     columnMap: mvc_metadata_column_map|null,
 *     instance: object,
 *     balias: string,
 *     eager?: mixed,
 *     keepSnapshots?: bool,
 * }
 * @phpstan-type mvc_resultset_scalar_column array{
 *     type: string,
 *     balias?: string,
 *     eager?: mixed,
 *     sqlAlias?: string,
 * }
 * @phpstan-type mvc_resultset_complex_state array{
 *     cache: mixed,
 *     columnTypes: array<array-key, mixed>|null,
 *     hydrateMode: int,
 *     rows: array<array-key, mixed>,
 * }
 * @phpstan-type mvc_resultset_simple_state array{
 *     cache: mixed,
 *     columnMap: mvc_hydration_column_map|string|null,
 *     hydrateMode: int,
 *     keepSnapshots?: bool,
 *     model: \Phalcon\Mvc\ModelInterface|\Phalcon\Mvc\Model\Row,
 *     rows: array<array-key, mixed>,
 * }
 * @phpstan-type mvc_model_foreign_key array{
 *     action?: int,
 *     allowNulls?: bool,
 *     conditions?: string,
 *     message?: string,
 * }
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Mvc_MvcTypes)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Mvc, MvcTypes, phalcon, contracts_mvc_mvctypes, NULL);

	return SUCCESS;
}

