
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Annotations;

use Phalcon\Annotations\Annotation;
use Phalcon\Annotations\Collection;
use Phalcon\Annotations\Reflection;

/**
 * Central registry of the array shapes used across the Annotations namespace.
 *
 * This is a type registry, not a contract. It declares no members and must
 * not be implemented; it exists only so that every shape below has a single
 * definition, imported where it is needed with a phpstan-import-type tag
 * naming this interface as the source.
 *
 * Alias names are prefixed with `annotations_` because PHPStan resolves
 * imported type names per file and has no namespacing for them: the prefix is
 * what keeps generic names such as `arguments` or `options` from clashing with
 * an alias imported from another namespace into the same file.
 *
 * The list is alphabetical, with one exception: an alias that another alias
 * names must be defined before it. Psalm reads the aliases in file order and
 * cannot resolve a forward reference; it reports the name as a missing class
 * instead. PHPStan does not care about the order, so a forward reference is
 * invisible until the stubs are analyzed. `annotations_expression` is hoisted
 * for that reason.
 *
 * These shapes are this project's own. The Annotations namespace is the one
 * namespace whose implementation differs between cphalcon and phalcon:
 * cphalcon parses docblocks with `phannot_parse_annotations()` and hands the
 * raw parser nodes around, while phalcon reads native PHP attributes and hands
 * `ReflectionAttribute` objects around. Do not mirror the two registries.
 *
 * The node shapes below are what `ext/phalcon/annotations/parser.php.inc.h`
 * builds: `phannot_ret_annotation()`, `phannot_ret_named_item()`,
 * `phannot_ret_literal_zval()` and `phannot_ret_array()`.
 *
 * An expression is one of a literal node (`type` plus an optional string
 * `value`), an array node (`type` plus optional `items`) or a nested
 * annotation node, and `getExpression()` walks into `items` and into nested
 * annotations. That makes the shape recursive, which neither PHPStan nor Psalm
 * accepts, so the alias stays an untyped map, as `db_expression` does for the
 * dialect intermediate. Each read narrows the value it needs.
 *
 * @phpstan-type annotations_expression array<array-key, mixed>
 * @phpstan-type annotations_argument array{
 *     expr: annotations_expression,
 *     name?: string,
 * }
 * @phpstan-type annotations_arguments array<array-key, annotations_argument>
 * @phpstan-type annotations_cache array<string, Reflection>
 * @phpstan-type annotations_collection_map array<string, Collection>
 * @phpstan-type annotations_list list<Annotation>
 * @phpstan-type annotations_node array{
 *     arguments?: annotations_arguments,
 *     file: string,
 *     line: int,
 *     name?: string,
 *     type: int,
 * }
 * @phpstan-type annotations_node_list list<annotations_node>
 * @phpstan-type annotations_node_map array<string, annotations_node_list>
 * @phpstan-type annotations_options array<string, mixed>
 * @phpstan-type annotations_reflection_data array{
 *     class?: annotations_node_list,
 *     constants?: annotations_node_map,
 *     methods?: annotations_node_map,
 *     properties?: annotations_node_map,
 * }
 * @phpstan-type annotations_resolved_arguments array<array-key, mixed>
 */
interface AnnotationsTypes
{
}
