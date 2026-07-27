
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Based on the Action Domain Responder pattern
 * @link    https://pmjones.io/adr/
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
     * The list is not filtered by existence.
     *
     * @return list<class-string>
     */
    public function candidatesFor(string method, string path) -> array;

    public function match(<RequestInterface> request) -> <RouterMatch> | null;

    public function setBaseNamespace(string baseNamespace) -> <Router>;

    public function setMiddlewareMap(array middlewareMap) -> <Router>;
}
