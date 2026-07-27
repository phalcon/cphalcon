
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

use Phalcon\ADR\Exceptions\MethodNotAllowed;
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

    /**
     * Every Action class this router would try for the given method and path,
     * in the order it tries them. The first that exists wins at match time.
     * The list is not filtered by existence.
     *
     * @return list<class-string>
     */
    public function candidatesFor(string method, string path) -> array
    {
        return array_column(this->deriveCandidates(method, path), 0);
    }

    public function match(<RequestInterface> request) -> <RouterMatchInterface> | null
    {
        var path, method, located, verbs, other;

        let path   = request->getURI(true),
            method = request->getMethod();

        let located = this->locate(method, path);
        if typeof located == "array" {
            return new RouterMatch(
                located[0],
                located[1],
                this->middlewareFor(located[0])
            );
        }

        let verbs = ["Get", "Post", "Put", "Patch", "Delete"];
        for other in verbs {
            if strcasecmp(other, method) !== 0 && typeof this->locate(other, path) == "array" {
                throw new MethodNotAllowed();
            }
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

    protected function camelize(string segment) -> string
    {
        return str_replace(" ", "", ucwords(str_replace(["-", "_"], " ", segment)));
    }

    /**
     * The single derivation of the routing convention. Every candidate is
     * paired with the request attributes it would leave behind, in try order.
     *
     * @return array<int, array{0: string, 1: array}>
     */
    protected function deriveCandidates(string method, string path) -> array
    {
        var candidates, uri, verb, segments, index, last, prev, head,
            resourceName, operation, className;

        let candidates = [],
            uri        = trim(path, "/"),
            verb       = ucfirst(strtolower(method)),
            segments   = uri === "" ? [] : explode("/", uri);

        if empty segments {
            let className    = this->baseNamespace . "\\" . verb,
                candidates[] = [className, []];

            return candidates;
        }

        let index = count(segments);

        while index >= 1 {
            let last = index - 1,
                head = array_slice(segments, 0, index);

            if index >= 2 {
                let prev         = index - 2,
                    resourceName = head[prev],
                    operation    = head[last],
                    className    = this->baseNamespace
                        . this->toNamespace(array_slice(head, 0, last))
                        . "\\" . verb . this->camelize(resourceName) . this->camelize(operation),
                    candidates[] = [className, array_slice(segments, index)];
            }

            let resourceName = head[last],
                className    = this->baseNamespace
                    . this->toNamespace(head)
                    . "\\" . verb . this->camelize(resourceName),
                candidates[] = [className, array_slice(segments, index)];

            let index = index - 1;
        }

        return candidates;
    }

    protected function locate(string method, string path) -> array | null
    {
        var candidates, candidate;

        let candidates = this->deriveCandidates(method, path);

        for candidate in candidates {
            if class_exists(candidate[0]) {
                return candidate;
            }
        }

        return null;
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

    protected function toNamespace(array segments) -> string
    {
        var segment, parts;

        let parts = [];
        for segment in segments {
            let parts[] = this->camelize(segment);
        }

        if empty parts {
            return "";
        }

        return "\\" . implode("\\", parts);
    }
}
