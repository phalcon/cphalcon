
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Based on the Action Domain Responder pattern
 *
 * Implementation of this file has also been heavily influenced by Autoroute.
 *
 * @link    https://pmjones.io/adr/
 *
 * @link    https://github.com/pmjones/AutoRoute
 * @license https://github.com/pmjones/AutoRoute/blob/2.x/LICENSE.md
 */

namespace Phalcon\Contracts\ADR\Router;

use Phalcon\Http\RequestInterface;

/**
 * Maps a request to an Action by convention: the HTTP method and the static
 * path segments identify the class; trailing segments become positional
 * request attributes. No route table.
 */
interface Router
{
    /**
     * Every Action class this router would try for the given method and path,
     * in the order it tries them. The first that exists wins at match time.
     * Namespace descent consults the filesystem, so the list depends on the
     * action directory.
     *
     * @return list<class-string>
     */
    public function candidatesFor(string method, string path) -> array;

    /**
     * The class this convention names for a fully static path, derived without
     * consulting the filesystem - the exact inverse of pathFor().
     *
     * For tooling that needs the name before the code exists: generators,
     * linters, documentation and "no action found; expected X" diagnostics.
     * Pass the static prefix only; placeholders are the caller's concern.
     */
    public function classFor(string method, string path) -> string;

    public function match(<RequestInterface> request) -> <RouterMatch> | null;

    /**
     * The canonical static path the given Action class answers, or null when
     * the class is not derivable from the base namespace. Positional
     * attributes are not part of the canonical path.
     */
    public function pathFor(string className) -> string | null;

    /**
     * The filesystem root that backs the base namespace. The router uses it to
     * decide whether a path segment names a sub-namespace.
     */
    public function setActionDirectory(string actionDirectory) -> <Router>;

    public function setBaseNamespace(string baseNamespace) -> <Router>;

    public function setMiddlewareMap(array middlewareMap) -> <Router>;

    /**
     * The single delimiter between words in a path segment. Applied
     * symmetrically when deriving a class name from a path and a path from a
     * class name. Any other character is literal.
     */
    public function setWordSeparator(string wordSeparator) -> <Router>;
}
