
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

namespace Phalcon\ADR\Router;

use Phalcon\ADR\Router\Exceptions\MethodNotAllowed;
use Phalcon\Contracts\ADR\Router\Router as RouterInterface;
use Phalcon\Contracts\ADR\Router\RouterMatch as RouterMatchInterface;
use Phalcon\Http\RequestInterface;

/**
 * Convention router. `method + static path -> Action class`; the path tail
 * becomes positional request attributes. Middleware is resolved from a
 * namespace-prefix map (group semantics); global middleware stays on the
 * pipeline. No route table.
 */
final class Router implements RouterInterface
{
    /**
     * @var string
     */
    protected baseNamespace = "";

    /**
     * @var array<string, string[]>
     */
    protected middlewareMap = [];

    public function match(<RequestInterface> request) -> <RouterMatchInterface> | null
    {
        var uri, verb, segments, index, prefix, className, params;

        let uri      = trim(request->getURI(true), "/"),
            verb     = ucfirst(strtolower(request->getMethod())),
            segments = uri === "" ? [] : explode("/", uri);

        let index = count(segments);
        while index >= 0 {
            let prefix    = this->baseNamespace . this->toNamespace(array_slice(segments, 0, index)),
                className = prefix . "\\" . verb;

            if class_exists(className) {
                let params = array_slice(segments, index);

                return new RouterMatch(className, params, this->middlewareFor(className));
            }

            let index = index - 1;
        }

        if this->routableUnderAnotherVerb(segments) {
            throw new MethodNotAllowed("The request method is not allowed for the matched route.");
        }

        return null;
    }

    public function setBaseNamespace(string baseNamespace) -> <RouterInterface>
    {
        let this->baseNamespace = rtrim(baseNamespace, "\\");

        return this;
    }

    public function setMiddlewareMap(array middlewareMap) -> <RouterInterface>
    {
        let this->middlewareMap = middlewareMap;

        return this;
    }

    protected function middlewareFor(string className) -> array
    {
        var prefix, list, full, stacked;

        let stacked = [];
        for prefix, list in this->middlewareMap {
            let full = this->baseNamespace . prefix;

            if strncmp(className, full, strlen(full)) === 0 {
                let stacked = array_merge(stacked, list);
            }
        }

        return stacked;
    }

    protected function routableUnderAnotherVerb(array segments) -> bool
    {
        var index, prefix, verb, verbs;

        let verbs = ["Get", "Post", "Put", "Patch", "Delete"],
            index = count(segments);

        while index >= 0 {
            let prefix = this->baseNamespace . this->toNamespace(array_slice(segments, 0, index));

            for verb in verbs {
                if class_exists(prefix . "\\" . verb) {
                    return true;
                }
            }

            let index = index - 1;
        }

        return false;
    }

    protected function toNamespace(array segments) -> string
    {
        var segment, parts;

        let parts = [];
        for segment in segments {
            let parts[] = str_replace(" ", "", ucwords(str_replace(["-", "_"], " ", segment)));
        }

        if empty parts {
            return "";
        }

        return "\\" . implode("\\", parts);
    }
}
