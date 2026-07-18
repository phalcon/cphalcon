
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

use Phalcon\ADR\Router\Traits\HasMiddleware;
use Phalcon\Contracts\ADR\Router\Route as RouteInterface;

/**
 * A route registered with the router. Compiles a `/posts/{id}` style pattern to
 * a regular expression (with `{name:regex}` constraints supported) and matches
 * the request path against it, extracting the named parameters.
 */
class Route implements RouteInterface
{
    use HasMiddleware;

    /**
     * @var string
     */
    protected action;

    /**
     * @var string
     */
    protected compiled;

    /**
     * @var array
     */
    protected methods;

    /**
     * @var string|null
     */
    protected name = null;

    public function __construct(string pattern, string action, array methods = [])
    {
        let this->action   = action,
            this->methods  = methods,
            this->compiled = this->compile(pattern);
    }

    public function allowsMethod(string method) -> bool
    {
        return empty this->methods || in_array(method, this->methods, true);
    }

    public function getAction() -> string
    {
        return this->action;
    }

    public function getName() -> string | null
    {
        return this->name;
    }

    public function matches(string uri) -> array | bool
    {
        var matches, params, key, value;

        if !preg_match(this->compiled, uri, matches) {
            return false;
        }

        let params = [];
        for key, value in matches {
            if typeof key === "string" {
                let params[key] = value;
            }
        }

        return params;
    }

    public function withMiddleware(string... classes) -> <RouteInterface>
    {
        this->pushMiddleware(classes);

        return this;
    }

    public function withName(string name) -> <RouteInterface>
    {
        let this->name = name;

        return this;
    }

    protected function compile(string pattern) -> string
    {
        var compiled;

        let compiled = preg_replace("#\\{([a-zA-Z_][a-zA-Z0-9_]*):([^{}]+)\\}#", "(?<$1>$2)", pattern),
            compiled = preg_replace("#\\{([a-zA-Z_][a-zA-Z0-9_]*)\\}#", "(?<$1>[^/]+)", compiled);

        return "#^" . compiled . "$#";
    }
}
