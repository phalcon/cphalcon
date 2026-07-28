
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

use Phalcon\ADR\Exceptions\ActionDirectoryNotSet;
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
    protected string actionDirectory = "";
    protected string baseNamespace = "";
    /**
     * @var array<string, string[]>
     */
    protected array middlewareMap = [];
    protected string wordSeparator = "-";

    /**
     * Every Action class this router would try for the given method and path,
     * in the order it tries them. The first that exists wins at match time.
     * Namespace descent consults the filesystem, so the list depends on the
     * action directory.
     *
     * @return list<class-string>
     */
    public function candidatesFor(string method, string path) -> array
    {
        return array_column(this->deriveCandidates(method, path), 0);
    }

    public function match(<RequestInterface> request) -> <RouterMatchInterface> | null
    {
        var path, method, located, other;

        if this->actionDirectory === "" {
            throw new ActionDirectoryNotSet();
        }

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

        for other in this->verbs() {
            if strcasecmp(other, method) !== 0 && typeof this->locate(other, path) == "array" {
                throw new MethodNotAllowed();
            }
        }

        return null;
    }

    public function pathFor(string className) -> string | null
    {
        var last, 
            operation = null, 
            part, parts, path, prefix, remainder, resourceName, verb;

        let prefix = this->baseNamespace . "\\";

        if strncmp(className, prefix, strlen(prefix)) !== 0 {
            return null;
        }

        let parts = explode("\\", substr(className, strlen(prefix))),
            last  = array_pop(parts);

        if empty parts {
            return in_array(last, this->verbs(), true) ? "/" : null;
        }

        let resourceName = end(parts);

        for verb in this->verbs() {
            if strncmp(last, verb, strlen(verb)) !== 0 {
                continue;
            }

            let remainder = substr(last, strlen(verb));

            if strncmp(remainder, resourceName, strlen(resourceName)) !== 0 {
                continue;
            }

            // @todo Drop the cast once zephir_substr() matches PHP 8.0+
            let operation = (string) substr(last, strlen(verb) + strlen(resourceName));

            break;
        }

        if null === operation {
            return null;
        }

        let path = "";
        for part in parts {
            let path = path . "/" . this->decamelize(part);
        }

        if operation !== "" {
            let path = path . "/" . this->decamelize(operation);
        }

        return path;
    }

    public function setActionDirectory(string actionDirectory) -> <RouterInterface>
    {
        let this->actionDirectory = rtrim(actionDirectory, DIRECTORY_SEPARATOR);

        return this;
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

    public function setWordSeparator(string wordSeparator) -> <RouterInterface>
    {
        let this->wordSeparator = wordSeparator;

        return this;
    }

    protected function camelize(string segment) -> string
    {
        return str_replace(
            this->wordSeparator,
            "",
            ucwords(segment, this->wordSeparator)
        );
    }

    protected function decamelize(string part) -> string
    {
        return strtolower(
            preg_replace(
                "/([a-z0-9])([A-Z])/",
                "$1" . this->wordSeparator . "$2",
                part
            )
        );
    }

    /**
     * The single derivation of the routing convention. Path segments are
     * consumed as namespace segments while the matching directory exists; the
     * class at the stopping depth is probed, preceded by the fused operation
     * form when exactly one segment remains. Every candidate is paired with the
     * request attributes it would leave behind.
     *
     * @return array<int, array{0: string, 1: array}>
     */
    protected function deriveCandidates(string method, string path) -> array
    {
        var candidate, className, parts, resourceName, 
            subNamespace = "", 
            segments, uri, verb;
        int depth = 0;
        array candidates = [];

        let uri      = trim(path, "/"),
            verb     = ucfirst(strtolower(method)),
            segments = uri === "" ? [] : explode("/", uri);

        if empty segments {
            let className = this->baseNamespace . "\\" . verb;

            return [[className, []]];
        }

        while !empty segments {
            let candidate = subNamespace . "\\" . this->camelize(segments[0]);

            if !this->hasSubNamespace(candidate) {
                break;
            }

            let subNamespace = candidate,
                depth        = depth + 1;

            array_shift(segments);
        }

        if depth === 0 {
            return [];
        }

        let parts        = explode("\\", ltrim(subNamespace, "\\")),
            resourceName = end(parts),
            className    = this->baseNamespace . subNamespace . "\\" . verb . resourceName;

        if count(segments) === 1 {
            let candidates[] = [className . this->camelize(segments[0]), []];
        }

        let candidates[] = [className, segments];

        return candidates;
    }

    protected function hasSubNamespace(string subNamespace) -> bool
    {
        if memstr(subNamespace, "..") {
            return false;
        }

        return is_dir(
            this->actionDirectory . str_replace("\\", DIRECTORY_SEPARATOR, subNamespace)
        );
    }

    protected function locate(string method, string path) -> array | null
    {
        var candidate, candidates;

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
        var full, list, prefix;
        array stacked = [];

        for prefix, list in this->middlewareMap {
            let full = this->baseNamespace . prefix;

            if strncmp(className, full, strlen(full)) === 0 {
                let stacked = array_merge(stacked, list);
            }
        }

        return stacked;
    }

    /**
     * The HTTP verbs the convention recognises, in class-name form.
     *
     * @return list<string>
     */
    protected function verbs() -> array
    {
        return ["Get", "Post", "Put", "Patch", "Delete"];
    }
}
