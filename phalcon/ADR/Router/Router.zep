
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
 *
 * ## The convention
 *
 * Every static path segment is a namespace segment, and the class name is the
 * verb followed by all of those segments concatenated:
 *
 *     GET  /                      -> Get
 *     GET  /profiles              -> Profiles\GetProfiles
 *     GET  /company/all           -> Company\All\GetCompanyAll
 *     GET  /company/all/7         -> Company\All\GetCompanyAll  with ["7"]
 *     POST /session/forgot-password -> Session\ForgotPassword\PostSessionForgotPassword
 *
 * ## Guarantees
 *
 * - One path names exactly one class; that class names exactly one path.
 * - `classFor()` and `pathFor()` are pure functions of their input. Neither
 *   touches the filesystem, and neither consults any Action but the one it was
 *   given, so adding or deleting an Action can never move another one's URL.
 * - There is no candidate list and no first-that-exists. Nothing can be
 *   shadowed.
 *
 * ## Constraints - these are load-bearing, not style
 *
 * - **Arguments always trail the static path.** `/album/edit/1`, never
 *   `/album/1/edit`. A class name encodes which segments exist, not where a
 *   value sits among them; putting an argument in the middle would require
 *   consulting some other Action to find the boundary, and that is exactly the
 *   coupling this convention exists to avoid.
 * - **`params()` never affects routing.** It constrains, casts and converts
 *   attributes after a match. A wrong declaration is a validation bug, never a
 *   404.
 * - **No route table, no compile step, no cache.** Resolution is a string
 *   derivation plus one `class_exists`. In PHP's shared-nothing model a table
 *   must be rebuilt or reloaded on every request, and that cost dominates
 *   matching - which is why this router is faster in practice than a cached
 *   table-driven one.
 * - **Nothing may be layered onto the naming convention** to express argument
 *   position, arity or ordering. Any such declaration is a path template in
 *   disguise, and a path template belongs in a declared-route router, not here.
 *
 * The cost of all of this is `/album/edit/1` rather than `/album/1/edit`. That
 * is a spelling difference, not a capability one - and it is not a deviation
 * from any standard. REST is Fielding's dissertation, not an RFC; RFC 3986 and
 * RFC 9110 both leave path structure entirely to the origin server.
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

    /**
     * The class this convention names for a fully static path, derived without
     * consulting the filesystem.
     *
     * candidatesFor() cannot answer this. It walks the action directory to find
     * where static segments end, so a path whose directories do not exist yet
     * yields nothing - and a generator needs the name precisely in order to
     * create them. Every static segment is a namespace segment, so the answer
     * is unambiguous and pathFor() inverts it exactly.
     *
     * Placeholders are the caller's concern: pass the static prefix only.
     */
    public function classFor(string method, string path) -> string
    {
        var segment, segments, uri, verb;
        array parts = [];

        let uri      = trim(path, "/"),
            verb     = ucfirst(strtolower(method)),
            segments = uri === "" ? [] : explode("/", uri);

        if empty segments {
            return this->baseNamespace . "\\" . verb;
        }

        for segment in segments {
            let parts[] = this->camelize(segment);
        }

        return this->baseNamespace
            . "\\" . implode("\\", parts)
            . "\\" . verb . implode("", parts);
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
        var candidate, last, name, names, part, parts, path, prefix,
            verb = null;

        let prefix = this->baseNamespace . "\\";

        if strncmp(className, prefix, strlen(prefix)) !== 0 {
            return null;
        }

        let parts = explode("\\", substr(className, strlen(prefix))),
            last  = array_pop(parts);

        if empty parts {
            return in_array(last, this->verbs(), true) ? "/" : null;
        }

        /**
         * The class name is the verb followed by every namespace segment, so
         * the namespace alone reconstructs the static path and the class name
         * only has to agree with it. Anything that does not agree is not a
         * class this convention would ever have produced.
         */
        for candidate in this->verbs() {
            if last === candidate . implode("", parts) {
                let verb = candidate;

                break;
            }
        }

        if null === verb {
            return null;
        }

        /**
         * Placeholders are emitted at the level that declares them, so the
         * result is the route as it is actually written - `/photo/{id}/edit`,
         * not `/photo/edit`. A level that declares nothing contributes none,
         * which is why an Action without params() reverses to a static path.
         * Only this class is consulted - never a parent, never a sibling. That
         * is what makes the reverse local: adding or removing any other Action
         * cannot change the path this one answers.
         */
        let path = "";

        for part in parts {
            let path = path . "/" . this->decamelize(part);
        }

        let names = array_keys(this->actionParams(className));

        for name in names {
            let path = path . "/{" . name . "}";
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

    /**
     * An Action's declared positional parameters, or an empty array when it
     * declares none.
     *
     * This is what lets an argument sit *between* two static segments: the
     * walk needs to know how many segments a level consumes before it can
     * carry on matching. `params()` is static and already exists for filtering
     * and casting, so nothing new is asked of an Action - but declaring it now
     * decides routing, not just validation.
     *
     * @return array<string, array<string, mixed>>
     */
    protected function actionParams(string className) -> array
    {
        var params;

        if !class_exists(className) || !method_exists(className, "params") {
            return [];
        }

        let params = call_user_func([className, "params"]);

        return typeof params == "array" ? params : [];
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
     * The single derivation of the routing convention.
     *
     * Every static path segment becomes a namespace segment, and the class name
     * is the verb followed by all of those segments concatenated - so
     * `/company/all` is `Company\All\GetCompanyAll` and nothing else. One path
     * yields exactly one class, and pathFor() inverts it exactly.
     *
     * Segments are consumed while the matching directory exists; whatever
     * remains is a dynamic argument. That walk decides where static ends and
     * dynamic begins - it no longer chooses between competing class shapes,
     * because there is only one.
     *
     * @return array<int, array{0: string, 1: array}>
     */
    protected function deriveCandidates(string method, string path) -> array
    {
        var candidate, className, segment,
            subNamespace = "",
            segments, uri, verb;
        array parts = [];

        let uri      = trim(path, "/"),
            verb     = ucfirst(strtolower(method)),
            segments = uri === "" ? [] : explode("/", uri);

        if empty segments {
            let className = this->baseNamespace . "\\" . verb;

            return [[className, []]];
        }

        while !empty segments {
            let segment   = this->camelize(segments[0]),
                candidate = subNamespace . "\\" . segment;

            if !this->hasSubNamespace(candidate) {
                break;
            }

            let subNamespace = candidate;
            let parts[]      = segment;

            array_shift(segments);
        }

        if empty parts {
            return [];
        }

        let className = this->baseNamespace
            . subNamespace
            . "\\" . verb . implode("", parts);

        /**
         * Everything the walk did not consume is a positional attribute. The
         * boundary is found once and never revisited, which is what makes the
         * class name alone sufficient to reconstruct the path.
         */
        return [[className, segments]];
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
