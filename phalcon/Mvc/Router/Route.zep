
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Router;

/**
 * Phalcon\Mvc\Router\Route
 *
 * This class represents every route added to the router
 */
class Route implements RouteInterface
{
    protected beforeMatch;
    protected compiledPattern;
    protected converters;
    protected group;
    protected hostname;
    protected id { get };
    protected methods;
    protected match;
    protected name;
    protected paths;
    protected pattern;
    protected static uniqueId = 0;

    /**
     * Phalcon\Mvc\Router\Route constructor
     */
    public function __construct(string! pattern, var paths = null, var httpMethods = null)
    {
        var routeId, uniqueId;

        // Configure the route (extract parameters, paths, etc)
        this->reConfigure(pattern, paths);

        // Update the HTTP method constraints
        this->via(httpMethods);

        // Get the unique Id from the static member uniqueId
        let uniqueId = self::uniqueId;

        // TODO: Add a function that increase static members
        let routeId = uniqueId,
            this->id = routeId,
            self::uniqueId = uniqueId + 1;
    }

    /**
     * Sets a callback that is called if the route is matched.
     * The developer can implement any arbitrary conditions here
     * If the callback returns false the route is treated as not matched
     *
     *```php
     * $router->add(
     *     "/login",
     *     [
     *         "module"     => "admin",
     *         "controller" => "session",
     *     ]
     * )->beforeMatch(
     *     function ($uri, $route) {
     *         // Check if the request was made with Ajax
     *         if ($_SERVER["HTTP_X_REQUESTED_WITH"] === "xmlhttprequest") {
     *             return false;
     *         }
     *
     *         return true;
     *     }
     * );
     *```
     */
    public function beforeMatch(var callback) -> <RouteInterface>
    {
        let this->beforeMatch = callback;

        return this;
    }

    /**
     * Replaces placeholders from pattern returning a valid PCRE regular expression
     */
    public function compilePattern(string! pattern) -> string
    {
        string idPattern;

        // If a pattern contains ':', maybe there are placeholders to replace
        if memstr(pattern, ":") {
            // This is a pattern for valid identifiers
            let idPattern = "/([\\w0-9\\_\\-]+)";

            // Replace the module part
            if memstr(pattern, "/:module") {
                let pattern = str_replace("/:module", idPattern, pattern);
            }

            // Replace the controller placeholder
            if memstr(pattern, "/:controller") {
                let pattern = str_replace("/:controller", idPattern, pattern);
            }

            // Replace the namespace placeholder
            if memstr(pattern, "/:namespace") {
                let pattern = str_replace("/:namespace", idPattern, pattern);
            }

            // Replace the action placeholder
            if memstr(pattern, "/:action") {
                let pattern = str_replace("/:action", idPattern, pattern);
            }

            // Replace the params placeholder
            if memstr(pattern, "/:params") {
                let pattern = str_replace("/:params", "(/.*)*", pattern);
            }

            // Replace the int placeholder
            if memstr(pattern, "/:int") {
                let pattern = str_replace("/:int", "/([0-9]+)", pattern);
            }
        }

        /**
         * Check if the pattern has parentheses or square brackets in order to
         * add the regex delimiters
         */
        if memstr(pattern, "(") || memstr(pattern, "[") {
            return "#^" . pattern . "$#u";
        }

        return pattern;
    }

    /**
     * {@inheritdoc}
     */
    public function convert(string! name, var converter) -> <RouteInterface>
    {
        let this->converters[name] = converter;

        return this;
    }

    /**
     * Extracts parameters from a string
     */
    public function extractNamedParams(string! pattern) -> array | bool
    {
        char ch, prevCh = '\0';
        var tmp, matches;
        bool notValid;
        int cursor, cursorVar, marker, bracketCount = 0, parenthesesCount = 0, foundPattern = 0;
        int intermediate = 0, numberMatches = 0;
        string route, item, variable, regexp;

        if strlen(pattern) === 0 {
            return false;
        }

        let matches = [],
            route = "";

        for cursor, ch in pattern {
            if parenthesesCount == 0 {
                if ch == '{' {
                    if bracketCount == 0 {
                        let marker = cursor + 1,
                            intermediate = 0,
                            notValid = false;
                    }

                    let bracketCount++;
                } elseif ch == '}' {
                    let bracketCount--;

                    if intermediate > 0 {
                        if bracketCount == 0 {
                            let numberMatches++,
                                variable = null,
                                regexp = null,
                                item = (string) substr(pattern, marker, cursor - marker);

                            for cursorVar, ch in item {
                                if ch == '\0' {
                                    break;
                                }

                                if cursorVar == 0 && !((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
                                    let notValid = true;

                                    break;
                                }

                                if (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <='9') || ch == '-' || ch == '_' || ch ==  ':' {
                                    if ch == ':' {
                                        let variable = (string) substr(item, 0, cursorVar),
                                            regexp = (string) substr(item, cursorVar + 1);

                                        break;
                                    }
                                } else {
                                    let notValid = true;

                                    break;
                                }
                            }

                            if !notValid {
                                let tmp = numberMatches;

                                if variable && regexp {
                                    let foundPattern = 0;

                                    for ch in regexp {
                                        if ch == '\0' {
                                            break;
                                        }

                                        if !foundPattern {
                                            if ch == '(' {
                                                let foundPattern = 1;
                                            }
                                        } else {
                                            if ch == ')' {
                                                let foundPattern = 2;

                                                break;
                                            }
                                        }
                                    }

                                    if foundPattern != 2 {
                                        let route .= "(" . regexp . ")";
                                    } else {
                                        let route .= regexp;
                                    }

                                    let matches[variable] = tmp;
                                } else {
                                    let route .= "([^/]*)",
                                        matches[item] = tmp;
                                }
                            } else {
                                let route .= "{" . item . "}";
                            }

                            continue;
                        }
                    }
                }
            }

            if bracketCount == 0 {
                if ch == '(' {
                    let parenthesesCount++;
                } elseif ch == ')' {
                    let parenthesesCount--;

                    if parenthesesCount == 0 {
                        let numberMatches++;
                    }
                }
            }

            if bracketCount > 0 {
                let intermediate++;
            } else {
                if parenthesesCount == 0 && prevCh != '\\' {
                    if ch == '.' || ch == '+' || ch == '|' || ch == '#' {
                        let route .= '\\';
                    }
                }

                let route .= ch,
                    prevCh = ch;
            }
        }

        return [route, matches];
    }

    /**
     * Returns the 'before match' callback if any
     */
    public function getBeforeMatch() -> callable
    {
        return this->beforeMatch;
    }

    /**
     * Returns the route's compiled pattern
     */
    public function getCompiledPattern() -> string
    {
        return this->compiledPattern;
    }

    /**
     * Returns the router converter
     */
    public function getConverters() -> array
    {
        return this->converters;
    }

    /**
     * Returns the group associated with the route
     */
    public function getGroup() -> <GroupInterface> | null
    {
        return this->group;
    }

    /**
     * Returns the HTTP methods that constraint matching the route
     */
    public function getHttpMethods() -> array | string
    {
        return this->methods;
    }

    /**
     * Returns the hostname restriction if any
     */
    public function getHostname() -> string
    {
        return this->hostname;
    }

    /**
     * Returns the 'match' callback if any
     */
    public function getMatch() -> callable
    {
        return this->match;
    }

    /**
     * Returns the route's name
     */
    public function getName() -> string
    {
        return this->name;
    }

    /**
     * Returns the paths
     */
    public function getPaths() -> array
    {
        return this->paths;
    }

    /**
     * Returns the route's pattern
     */
    public function getPattern() -> string
    {
        return this->pattern;
    }

    /**
     * Returns the paths using positions as keys and names as values
     */
    public function getReversedPaths() -> array
    {
        return array_flip(
            this->paths
        );
    }

    /**
     * Returns the route's id
     */
    public function getRouteId() -> string
    {
        return this->id;
    }

    /**
     * Returns routePaths
     */
    public static function getRoutePaths(var paths = null) -> array
    {
        var moduleName, controllerName, actionName, parts, routePaths,
            realClassName, namespaceName;

        if paths === null {
            let paths = [];
        }

        if typeof paths == "string" {
            let moduleName = null,
                controllerName = null,
                actionName = null;

            // Explode the short paths using the :: separator
            let parts = explode("::", paths);

            // Create the array paths dynamically
            switch count(parts) {

                case 3:
                    let moduleName = parts[0],
                        controllerName = parts[1],
                        actionName = parts[2];
                    break;

                case 2:
                    let controllerName = parts[0],
                        actionName = parts[1];
                    break;

                case 1:
                    let controllerName = parts[0];
                    break;
            }

            let routePaths = [];

            // Process module name
            if moduleName !== null {
                let routePaths["module"] = moduleName;
            }

            // Process controller name
            if controllerName !== null {
                // Check if we need to obtain the namespace
                if memstr(controllerName, "\\") {
                    // Extract the real class name from the namespaced class
                    let realClassName = get_class_ns(controllerName);

                    // Extract the namespace from the namespaced class
                    let namespaceName = get_ns_class(controllerName);

                    // Update the namespace
                    if namespaceName {
                        let routePaths["namespace"] = namespaceName;
                    }
                } else {
                    let realClassName = controllerName;
                }

                // Always pass the controller to lowercase
                let routePaths["controller"] = uncamelize(realClassName);
            }

            // Process action name
            if actionName !== null {
                let routePaths["action"] = actionName;
            }
        } else {
            let routePaths = paths;
        }

        if unlikely typeof routePaths !== "array" {
            throw new Exception("The route contains invalid paths");
        }

        return routePaths;
    }

    /**
     * Allows to set a callback to handle the request directly in the route
     *
     *```php
     * $router->add(
     *     "/help",
     *     []
     * )->match(
     *     function () {
     *         return $this->getResponse()->redirect("https://support.google.com/", true);
     *     }
     * );
     *```
     */
    public function match(var callback) -> <RouteInterface>
    {
        let this->match = callback;

        return this;
    }

    /**
     * Reconfigure the route adding a new pattern and a set of paths
     */
    public function reConfigure(string! pattern, var paths = null) -> void
    {
        var routePaths, pcrePattern, compiledPattern, extracted;

        let routePaths = self::getRoutePaths(paths);

        /**
         * If the route starts with '#' we assume that it is a regular expression
         */
        if !starts_with(pattern, "#") {
            if memstr(pattern, "{") {
                /**
                 * The route has named parameters so we need to extract them
                 */
                let extracted = this->extractNamedParams(pattern),
                    pcrePattern = extracted[0],
                    routePaths = array_merge(routePaths, extracted[1]);
            } else {
                let pcrePattern = pattern;
            }

            /**
             * Transform the route's pattern to a regular expression
             */
            let compiledPattern = this->compilePattern(pcrePattern);
        } else {
            let compiledPattern = pattern;
        }

        /**
         * Update the original pattern
         */
        let this->pattern = pattern;

        /**
         * Update the compiled pattern
         */
        let this->compiledPattern = compiledPattern;

        /**
         * Update the route's paths
         */
        let this->paths = routePaths;
    }

    /**
     * Resets the internal route id generator
     */
    public static function reset() -> void
    {
        let self::uniqueId = 0;
    }

    /**
     * Sets the group associated with the route
     */
    public function setGroup(<GroupInterface> group) -> <RouteInterface>
    {
        let this->group = group;

        return this;
    }

    /**
     * Sets a set of HTTP methods that constraint the matching of the route (alias of via)
     *
     *```php
     * $route->setHttpMethods("GET");
     *
     * $route->setHttpMethods(
     *     [
     *         "GET",
     *         "POST",
     *     ]
     * );
     *```
     */
    public function setHttpMethods(var httpMethods) -> <RouteInterface>
    {
        return this->via(httpMethods);
    }

    /**
     * Sets a hostname restriction to the route
     *
     *```php
     * $route->setHostname("localhost");
     *```
     */
    public function setHostname(string! hostname) -> <RouteInterface>
    {
        let this->hostname = hostname;

        return this;
    }

    /**
     * Sets the route's name
     *
     *```php
     * $router->add(
     *     "/about",
     *     [
     *         "controller" => "about",
     *     ]
     * )->setName("about");
     *```
     */
    public function setName(string name) -> <RouteInterface>
    {
        let this->name = name;

        return this;
    }

    /**
     * Set one or more HTTP methods that constraint the matching of the route
     *
     *```php
     * $route->via("GET");
     *
     * $route->via(
     *     [
     *         "GET",
     *         "POST",
     *     ]
     * );
     *```
     */
    public function via(var httpMethods) -> <RouteInterface>
    {
        let this->methods = httpMethods;

        return this;
    }
}
