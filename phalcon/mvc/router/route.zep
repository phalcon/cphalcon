
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Mvc\Router;

use Phalcon\Mvc\Router\Exception;

/**
 * Phalcon\Mvc\Router\Route
 *
 * This class represents every route added to the router
 */
class Route implements RouteInterface
{

	protected _pattern;

	protected _compiledPattern;

	protected _paths;

	protected _methods;

	protected _hostname;

	protected _converters;

	protected _id;

	protected _name;

	protected _beforeMatch;

	protected _group;

	protected static _uniqueId;

	/**
	 * Phalcon\Mvc\Router\Route constructor
	 */
	public function __construct(string! pattern, var paths = null, var httpMethods = null)
	{
		var routeId, uniqueId;

		// Configure the route (extract parameters, paths, etc)
		this->reConfigure(pattern, paths);

		// Update the HTTP method constraints
		let this->_methods = httpMethods;

		// Get the unique Id from the static member _uniqueId
		let uniqueId = self::_uniqueId;
		if uniqueId === null {
			let uniqueId = 0;
		}

		// TODO: Add a function that increase static members
		let routeId = uniqueId,
			this->_id = routeId,
			self::_uniqueId = uniqueId + 1;
	}

	/**
	 * Replaces placeholders from pattern returning a valid PCRE regular expression
	 */
	public function compilePattern(string! pattern) -> string
	{
		var idPattern;

		// If a pattern contains ':', maybe there are placeholders to replace
		if memstr(pattern, ":") {

			// This is a pattern for valid identifiers
			let idPattern = "/([a-zA-Z0-9\\_\\-]+)";

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

		// Check if the pattern has parantheses in order to add the regex delimiters
		if memstr(pattern, "(") {
			return "#^" . pattern . "$#";
		}

		// Square brackets are also checked
		if memstr(pattern, "[") {
			return "#^" . pattern . "$#";
		}

		return pattern;
	}

	/**
	 * Set one or more HTTP methods that constraint the matching of the route
	 *
	 *<code>
	 * $route->via('GET');
	 * $route->via(array('GET', 'POST'));
	 *</code>
	 */
	public function via(var httpMethods) -> <Route>
	{
		let this->_methods = httpMethods;
		return this;
	}

	/**
	 * Extracts parameters from a string
	 */
	public function extractNamedParams(string! pattern) -> array | boolean
	{
		char ch;
		var tmp, matches;
		boolean notValid;
		int cursor, cursorVar, marker, bracketCount = 0, parenthesesCount = 0, foundPattern = 0;
		int intermediate = 0, numberMatches = 0;
		string route, item, variable, regexp;

		if strlen(pattern) <= 0 {
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
				} else {
					if ch == '}' {
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
											let route .= '(',
												route .= regexp,
												route .= ')';
										} else {
											let route .= regexp;
										}
										let matches[variable] = tmp;
									} else {
										let route .= "([^/]*)",
											matches[item] = tmp;
									}
								} else {
									let route .= '{',
										route .= item,
										route .= '}';
								}
								continue;
							}
						}
					}
				}
			}

			if bracketCount == 0 {
				if ch == '(' {
					let parenthesesCount++;
				} else {
					if ch == ')' {
						let parenthesesCount--;
						if parenthesesCount == 0 {
							let numberMatches++;
						}
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
	 * Reconfigure the route adding a new pattern and a set of paths
	 */
	public function reConfigure(string! pattern, var paths = null) -> void
	{
		var routePaths, pcrePattern, compiledPattern,
			extracted;

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
		let this->_pattern = pattern;

		/**
		 * Update the compiled pattern
		 */
		let this->_compiledPattern = compiledPattern;

		/**
		 * Update the route's paths
		 */
		let this->_paths = routePaths;
	}

	/**
	 * Returns routePaths
	 */
	public static function getRoutePaths(var paths = null) -> array
	{
		var moduleName, controllerName, actionName,
			parts, routePaths, realClassName,
			namespaceName;

		if paths !== null {
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
		} else {
			let routePaths = [];
		}

		if typeof routePaths !== "array" {
			throw new Exception("The route contains invalid paths");
		}

		return routePaths;
	}

	/**
	 * Returns the route's name
	 */
	public function getName() -> string
	{
		return this->_name;
	}

	/**
	 * Sets the route's name
	 *
	 *<code>
	 * $router->add('/about', array(
	 *     'controller' => 'about'
	 * ))->setName('about');
	 *</code>
	 */
	public function setName(string name) -> <Route>
	{
		let this->_name = name;
		return this;
	}

	/**
	 * Sets a callback that is called if the route is matched.
	 * The developer can implement any arbitrary conditions here
	 * If the callback returns false the route is treated as not matched
	 */
	public function beforeMatch(callable callback) -> <Route>
	{
		let this->_beforeMatch = callback;
		return this;
	}

	/**
	 * Returns the 'before match' callback if any
	 */
	public function getBeforeMatch() -> callable
	{
		return this->_beforeMatch;
	}

	/**
	 * Returns the route's id
	 */
	public function getRouteId() -> string
	{
		return this->_id;
	}

	/**
	 * Returns the route's pattern
	 */
	public function getPattern() -> string
	{
		return this->_pattern;
	}

	/**
	 * Returns the route's compiled pattern
	 */
	public function getCompiledPattern() -> string
	{
		return this->_compiledPattern;
	}

	/**
	 * Returns the paths
	 */
	public function getPaths() -> array
	{
		return this->_paths;
	}

	/**
	 * Returns the paths using positions as keys and names as values
	 */
	public function getReversedPaths() -> array
	{
		var reversed, path, position;

		let reversed = [];
		for path, position in this->_paths {
			let reversed[position] = path;
		}
		return reversed;
	}

	/**
	 * Sets a set of HTTP methods that constraint the matching of the route (alias of via)
	 *
	 *<code>
	 * $route->setHttpMethods('GET');
	 * $route->setHttpMethods(array('GET', 'POST'));
	 *</code>
	 */
	public function setHttpMethods(var httpMethods) -> <Route>
	{
		let this->_methods = httpMethods;
		return this;
	}

	/**
	 * Returns the HTTP methods that constraint matching the route
	 */
	public function getHttpMethods() -> array | string
	{
		return this->_methods;
	}

	/**
	 * Sets a hostname restriction to the route
	 *
	 *<code>
	 * $route->setHostname('localhost');
	 *</code>
	 */
	public function setHostname(string! hostname) -> <Route>
	{
		let this->_hostname = hostname;
		return this;
	}

	/**
	 * Returns the hostname restriction if any
	 */
	public function getHostname() -> string
	{
		return this->_hostname;
	}

	/**
	 * Sets the group associated with the route
	 */
	public function setGroup(<GroupInterface> group) -> <Route>
	{
		let this->_group = group;
		return this;
	}

	/**
	 * Returns the group associated with the route
	 */
	public function getGroup() -> <GroupInterface> | null
	{
		return this->_group;
	}

	/**
	 * Adds a converter to perform an additional transformation for certain parameter
	 */
	public function convert(string! name, var converter) -> <Route>
	{
		let this->_converters[name] = converter;
		return this;
	}

	/**
	 * Returns the router converter
	 */
	public function getConverters() -> array
	{
		return this->_converters;
	}

	/**
	 * Resets the internal route id generator
	 */
	public static function reset() -> void
	{
		let self::_uniqueId = null;
	}
}
