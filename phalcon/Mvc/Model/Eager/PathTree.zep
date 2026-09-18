
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\Eager;

use Phalcon\Contracts\Mvc\MvcTypes;
use Phalcon\Mvc\Model\Exceptions\InvalidEagerPath;
use Phalcon\Mvc\Model\Exceptions\UnsupportedEagerOption;

/**
 * Turns the `eager` find parameter into a tree.
 *
 * Elements are either a bare path string or `path => options`. A path implies
 * every one of its prefixes and prefixes are merged, so ["customer",
 * "customer.country"] and ["customer.country"] produce the same two-node tree.
 * The number of queries an eager load costs follows the number of nodes in
 * this tree, not the number of elements supplied.
 *
 * @phpstan-import-type mvc_eager_node from MvcTypes
 * @phpstan-import-type mvc_eager_tree from MvcTypes
 * @phpstan-import-type mvc_model_parameters from MvcTypes
 */
class PathTree
{
    /**
     * Longest path accepted. Depth alone is not what makes an eager load
     * expensive, but an unbounded path is never intentional.
     *
     * @var int
     */
    const MAX_DEPTH = 5;

    /**
     * @param array $spec the `eager` find parameter
     *
     * @phpstan-param array<array-key, mixed> $spec
     * @phpstan-return mvc_eager_tree
     */
    public static function parse(array spec) -> array
    {
        var key, options, path, segments, value;
        array tree;

        let tree = [];

        for key, value in spec {
            if typeof key === "string" {
                let path    = key,
                    options = value;
            } else {
                let path    = value,
                    options = [];
            }

            if unlikely typeof path !== "string" {
                throw new InvalidEagerPath(
                    typeof path === "object" ? get_class(path) : (string) path
                );
            }

            if unlikely typeof options !== "array" {
                throw new InvalidEagerPath(path);
            }

            self::assertOptions(options);

            let segments = explode(".", path);

            if unlikely count(segments) > self::MAX_DEPTH {
                throw new InvalidEagerPath(path);
            }

            let tree = self::insert(tree, path, segments, 0, options);
        }

        return tree;
    }

    /**
     * A per-parent limit requires ROW_NUMBER() OVER (PARTITION BY ...), which
     * PHQL has no syntax for. Applying `limit` to the batch query instead
     * would return N children in total rather than N per parent, which is
     * silently wrong.
     *
     * @phpstan-param mvc_model_parameters $options
     */
    private static function assertOptions(array options) -> void
    {
        if unlikely isset options["limit"] {
            throw new UnsupportedEagerOption("limit");
        }

        if unlikely isset options["offset"] {
            throw new UnsupportedEagerOption("offset");
        }
    }

    /**
     * @param array  $tree     accumulated tree
     * @param string $path     the original path, for error messages
     * @param array  $segments exploded path
     * @param int    $index    segment currently being inserted
     * @param array  $options  attach to the last segment only
     *
     * @phpstan-param mvc_eager_tree            $tree
     * @phpstan-param array<array-key, string>  $segments
     * @phpstan-param mvc_model_parameters      $options
     * @phpstan-return mvc_eager_tree
     */
    private static function insert(
        array tree,
        string path,
        array segments,
        int index,
        array options
    ) -> array {
        var node, segment;
        bool isLast;

        let segment = trim(segments[index]);

        if unlikely segment === "" {
            throw new InvalidEagerPath(path);
        }

        if !fetch node, tree[segment] {
            let node = [
                "options"  : [],
                "children" : []
            ];
        }

        let isLast = index + 1 >= count(segments);

        if isLast {
            let node["options"] = array_merge(node["options"], options);
        } else {
            let node["children"] = self::insert(
                node["children"],
                path,
                segments,
                index + 1,
                options
            );
        }

        let tree[segment] = node;

        return tree;
    }
}
