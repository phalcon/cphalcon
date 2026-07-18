
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

use Closure;
use Phalcon\Http\RequestInterface;

/**
 * Maps a request to an Action. Routes are registered by pattern and HTTP method
 * and matched against the incoming request.
 */
interface Router
{
    public function add(string pattern, string actionClass, array methods = []) -> <Route>;

    public function delete(string pattern, string actionClass) -> <Route>;

    public function get(string pattern, string actionClass) -> <Route>;

    public function group(string prefix, <Closure> configure) -> <Group>;

    public function match(<RequestInterface> request) -> <RouterMatch> | null;

    public function patch(string pattern, string actionClass) -> <Route>;

    public function post(string pattern, string actionClass) -> <Route>;

    public function put(string pattern, string actionClass) -> <Route>;
}
