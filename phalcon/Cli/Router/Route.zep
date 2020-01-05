
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Cli\Router;

/**
 * This class represents every route added to the router
 */
class Route implements RouteInterface
{
    const DEFAULT_DELIMITER = " ";

    protected beforeMatch;

    protected compiledPattern;

    protected converters;

    protected delimiter;

    protected static delimiterPath = self::DEFAULT_DELIMITER;

    protected description;

    protected id;

    protected name;

    protected paths;

    protected pattern;

    protected static uniqueId = 0;

    /**
     * @param array|string paths
     */
    public function __construct(string! pattern, paths = null)
    {
        var routeId, uniqueId;

        // Get the delimiter from the static member delimiterPath
        let this->delimiter = self::delimiterPath;

        // Configure the route (extract parameters, paths, etc)
        this->reConfigure(pattern, paths);

        // Get the unique Id from the static member uniqueId
        let uniqueId = self::uniqueId;

        // TODO: Add a function that increase static members
        let routeId        = uniqueId,
            this->id       = routeId,
            self::uniqueId = uniqueId + 1;
    }

    /**
     * Sets a callback that is called if the route is matched.
     * The developer can implement any arbitrary conditions here
     * If the callback returns false the route is treated as not matched
     *
     * @param callback callback
     */
    public function beforeMatch(var callback) -> <RouteInterface>
    {
        let this->beforeMatch = callback;

        return this;
    }

    /**
     * Replaces placeholders from pattern returning a valid PCRE regular
     * expression
     */
    public function compilePattern(string! pattern) -> string
    {
        var idPattern, part;

        // If a pattern contains ':', maybe there are placeholders to replace
        if memstr(pattern, ":") {

            // This is a pattern for valid identifiers
            let idPattern = this->delimiter . "([a-zA-Z0-9\\_\\-]+)";

            // Replace the delimiter part
            if memstr(pattern, ":delimiter") {
                let pattern = str_replace(
                    ":delimiter",
                    this->delimiter,
                    pattern
                );
            }

            // Replace the module part
            let part = this->delimiter . ":module";
            if memstr(pattern, part) {
                let pattern = str_replace(part, idPattern, pattern);
            }

            // Replace the task placeholder
            let part = this->delimiter . ":task";
            if memstr(pattern, part) {
                let pattern = str_replace(part, idPattern, pattern);
            }

            // Replace the namespace placeholder
            let part = this->delimiter . ":namespace";
            if memstr(pattern, part) {
                let pattern = str_replace(part, idPattern, pattern);
            }

            // Replace the action placeholder
            let part = this->delimiter . ":action";
            if memstr(pattern, part) {
                let pattern = str_replace(part, idPattern, pattern);
            }

            // Replace the params placeholder
            let part = this->delimiter . ":params";
            if memstr(pattern, part) {
                let pattern = str_replace(
                    part,
                    "(" . this->delimiter . ".*)*",
                    pattern
                );
            }

            // Replace the int placeholder
            let part = this->delimiter . ":int";
            if memstr(pattern, part) {
                let pattern = str_replace(
                    part,
                    this->delimiter . "([0-9]+)",
                    pattern
                );
            }
        }

        /**
         * Check if the pattern has parentheses or square brackets in order to
         * add the regex delimiters
         */
        if memstr(pattern, "(") || memstr(pattern, "[") {
            return "#^" . pattern . "$#";
        }

        return pattern;
    }

    /**
     * Adds a converter to perform an additional transformation for certain
     * parameter
     *
     * @param callable converter
     */
    public function convert(string! name, converter) -> <RouteInterface>
    {
        let this->converters[name] = converter;

        return this;
    }

    /**
     * Set the routing delimiter
     */
    public static function delimiter(string! delimiter = null) -> void
    {
        let self::delimiterPath = delimiter;
    }

    /**
     * Extracts parameters from a string
     */
    public function extractNamedParams(string! pattern) -> array | bool
    {
        char ch;
        var tmp;
        array matches;
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
                                    let route .= "([^" . this->delimiter . "]*)",
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
                let route .= ch;
            }
        }

        return [route, matches];
    }

    /**
     * Returns the 'before match' callback if any
     */
    public function getBeforeMatch() -> var
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
     * Get routing delimiter
     */
    public static function getDelimiter() -> string
    {
        return self::delimiterPath;
    }

    /**
     * Returns the route's description
     */
    public function getDescription() -> string
    {
        return this->description;
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
     * Reconfigure the route adding a new pattern and a set of paths
     *
     * @param array|string paths
     */
    public function reConfigure(string! pattern, paths = null) -> void
    {
        var moduleName, taskName, actionName, parts, routePaths, realClassName,
            namespaceName, pcrePattern, compiledPattern, extracted;

        if paths === null {
            let paths = [];
        }

        if typeof paths == "string" {
            let moduleName = null,
                taskName = null,
                actionName = null;

            // Explode the short paths using the :: separator
            let parts = explode("::", paths);

            // Create the array paths dynamically
            switch count(parts) {

                case 3:
                    let moduleName = parts[0],
                        taskName   = parts[1],
                        actionName = parts[2];
                    break;

                case 2:
                    let taskName   = parts[0],
                        actionName = parts[1];
                    break;

                case 1:
                    let taskName = parts[0];
                    break;
            }

            let routePaths = [];

            // Process module name
            if moduleName !== null {
                let routePaths["module"] = moduleName;
            }

            // Process task name
            if taskName !== null {
                // Check if we need to obtain the namespace
                if memstr(taskName, "\\") {
                    // Extract the real class name from the namespaced class
                    let realClassName = get_class_ns(taskName);

                    // Extract the namespace from the namespaced class
                    let namespaceName = get_ns_class(taskName);

                    if unlikely (namespaceName === null || realClassName === null) {
                        throw new Exception(
                            "The route contains invalid paths"
                        );
                    }

                    // Update the namespace
                    if namespaceName {
                        let routePaths["namespace"] = namespaceName;
                    }
                } else {
                    let realClassName = taskName;
                }

                // Always pass the task to lowercase
                let routePaths["task"] = uncamelize(realClassName);
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

        /**
         * If the route starts with '#' we assume that it is a regular
         * expression
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
            // Replace the delimiter part
            if memstr(pattern, ":delimiter") {
                let pattern = str_replace(
                    ":delimiter",
                    this->delimiter,
                    pattern
                );
            }

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
     * Sets the route's description
     */
    public function setDescription(string! description) -> <RouteInterface>
    {
        let this->description = description;

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
    public function setName(string! name) -> <RouteInterface>
    {
        let this->name = name;

        return this;
    }
}
