
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
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

use Phalcon\DiInterface;
use Phalcon\Mvc\Router;
use Phalcon\Annotations\Annotation;
use Phalcon\Mvc\Router\Exception;

/**
 * Phalcon\Mvc\Router\Annotations
 *
 * A router that reads routes annotations from classes/resources
 *
 * <code>
 * use Phalcon\Mvc\Router\Annotations;
 *
 * $di->setShared(
 *     "router",
 *     function() {
 *         // Use the annotations router
 *         $router = new Annotations(false);
 *
 *         // This will do the same as above but only if the handled uri starts with /robots
 *         $router->addResource("Robots", "/robots");
 *
 *         return $router;
 *     }
 * );
 * </code>
 */
class Annotations extends Router
{
	protected _handlers = [];

	protected _controllerSuffix = "Controller";

	protected _actionSuffix = "Action";

	protected _routePrefix;

	/**
	 * Adds a resource to the annotations handler
	 * A resource is a class that contains routing annotations
	 */
	public function addResource(string! handler, string! prefix = null) -> <Annotations>
	{
		let this->_handlers[] = [prefix, handler];

		return this;
	}

	/**
	 * Adds a resource to the annotations handler
	 * A resource is a class that contains routing annotations
	 * The class is located in a module
	 */
	public function addModuleResource(string! module, string! handler, string! prefix = null) -> <Annotations>
	{
		let this->_handlers[] = [prefix, handler, module];

		return this;
	}

	/**
	 * Produce the routing parameters from the rewrite information
	 */
	public function handle(string! uri = null)
	{
		var realUri, annotationsService, handlers, controllerSuffix,
			scope, prefix, dependencyInjector, handler, controllerName,
			lowerControllerName, namespaceName, moduleName, sufixed, handlerAnnotations,
			classAnnotations, annotations, annotation, methodAnnotations, method,
			collection;

		if !uri {
			/**
			 * If 'uri' isn't passed as parameter it reads $_GET["_url"]
			 */
			let realUri = this->getRewriteUri();
		} else {
			let realUri = uri;
		}

		let dependencyInjector = <DiInterface> this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			throw new Exception("A dependency injection container is required to access the 'annotations' service");
		}

		let annotationsService = dependencyInjector->getShared("annotations");

		let handlers = this->_handlers;

		let controllerSuffix = this->_controllerSuffix;

		for scope in handlers {

			if typeof scope != "array" {
				continue;
			}

			/**
			 * A prefix (if any) must be in position 0
			 */
			let prefix = scope[0];

			if !empty prefix && !starts_with(realUri, prefix) {
				continue;
			}

			/**
			 * The controller must be in position 1
			 */
			let handler = scope[1];

			if memstr(handler, "\\") {

				/**
				 * Extract the real class name from the namespaced class
				 * The lowercased class name is used as controller
				 * Extract the namespace from the namespaced class
				 */
				let controllerName = get_class_ns(handler),
					namespaceName = get_ns_class(handler);
			} else {
				let controllerName = handler;
				fetch namespaceName, this->_defaultNamespace;
			}

			let this->_routePrefix = null;

			/**
			 * Check if the scope has a module associated
			 */
			fetch moduleName, scope[2];

			let sufixed = controllerName . controllerSuffix;

			/**
			 * Add namespace to class if one is set
			 */
			if namespaceName !== null {
				let sufixed = namespaceName . "\\" . sufixed;
			}

			/**
			 * Get the annotations from the class
			 */
			let handlerAnnotations = annotationsService->get(sufixed);

			if typeof handlerAnnotations != "object" {
				continue;
			}

			/**
			 * Process class annotations
			 */
			let classAnnotations = handlerAnnotations->getClassAnnotations();
			if typeof classAnnotations == "object" {
				let annotations = classAnnotations->getAnnotations();
				if typeof annotations == "array" {
					for annotation in annotations {
						this->processControllerAnnotation(controllerName, annotation);
					}
				}
			}

			/**
			 * Process method annotations
			 */
			let methodAnnotations = handlerAnnotations->getMethodsAnnotations();
			if typeof methodAnnotations == "array" {
				let lowerControllerName = uncamelize(controllerName);

				for method, collection in methodAnnotations {
					if typeof collection == "object" {
						for annotation in collection->getAnnotations() {
							this->processActionAnnotation(moduleName, namespaceName, lowerControllerName, method, annotation);
						}
					}
				}
			}
		}

		/**
		 * Call the parent handle method()
		 */
		parent::handle(realUri);
	}

	/**
	 * Checks for annotations in the controller docblock
	 */
	public function processControllerAnnotation(string! handler, <Annotation> annotation)
	{
		/**
		 * @RoutePrefix add a prefix for all the routes defined in the model
		 */
		if annotation->getName() == "RoutePrefix" {
			let this->_routePrefix = annotation->getArgument(0);
		}
	}

	/**
	 * Checks for annotations in the public methods of the controller
	 */
	public function processActionAnnotation(string! module, string! namespaceName, string! controller, string! action,
		<Annotation> annotation)
	{
		var isRoute, name, actionName, routePrefix, paths, value, uri,
			route, methods, converts, param, convert, conversorParam, routeName,
			beforeMatch;

		let isRoute = false,
			methods = null,
			name = annotation->getName();

		/**
		 * Find if the route is for adding routes
		 */
		switch name {

			case "Route":
				let isRoute = true;
				break;

			case "Get":
				let isRoute = true, methods = "GET";
				break;

			case "Post":
				let isRoute = true, methods = "POST";
				break;

			case "Put":
				let isRoute = true, methods = "PUT";
				break;

			case "Patch":
				let isRoute = true, methods = "PATCH";
				break;

			case "Delete":
				let isRoute = true, methods = "DELETE";
				break;

			case "Options":
				let isRoute = true, methods = "OPTIONS";
				break;
		}

		if isRoute === true {

			let actionName = strtolower(str_replace(this->_actionSuffix, "", action)),
				routePrefix = this->_routePrefix;

			/**
			 * Check for existing paths in the annotation
			 */
			let paths = annotation->getNamedArgument("paths");
			if typeof paths != "array" {
				let paths = [];
			}

			/**
			 * Update the module if any
			 */
			if !empty module {
				let paths["module"] = module;
			}

			/**
			 * Update the namespace if any
			 */
			if !empty namespaceName {
				let paths["namespace"] = namespaceName;
			}

			let paths["controller"] = controller,
				paths["action"] = actionName;

			let value = annotation->getArgument(0);

			/**
			 * Create the route using the prefix
			 */
			if typeof value !== "null" {
				if value != "/" {
					let uri = routePrefix . value;
				} else {
					if typeof routePrefix !== "null" {
						let uri = routePrefix;
					} else {
						let uri = value;
					}
				}
			} else {
				let uri = routePrefix . actionName;
			}

			/**
			 * Add the route to the router
			 */
			let route = this->add(uri, paths);

			/**
			 * Add HTTP constraint methods
			 */
			if methods !== null {
				route->via(methods);
			} else {
				let methods = annotation->getNamedArgument("methods");
				if typeof methods == "array" || typeof methods == "string" {
					route->via(methods);
				}
			}

			/**
			 * Add the converters
			 */
			let converts = annotation->getNamedArgument("converts");
			if typeof converts == "array" {
				for param, convert in converts {
					route->convert(param, convert);
				}
			}

			/**
			 * Add the conversors
			 */
			let converts = annotation->getNamedArgument("conversors");
			if typeof converts == "array" {
				for conversorParam, convert in converts {
					route->convert(conversorParam, convert);
				}
			}

			/**
			 * Add the conversors
			 */
			let beforeMatch = annotation->getNamedArgument("beforeMatch");
			if typeof beforeMatch == "array" || typeof beforeMatch == "string" {
				route->beforeMatch(beforeMatch);
			}

			let routeName = annotation->getNamedArgument("name");
			if typeof routeName == "string" {
				route->setName(routeName);
			}

			return true;
		}
	}

	/**
	 * Changes the controller class suffix
	 */
	public function setControllerSuffix(string! controllerSuffix)
	{
		let this->_controllerSuffix = controllerSuffix;
	}

	/**
	 * Changes the action method suffix
	 */
	public function setActionSuffix(string! actionSuffix)
	{
		let this->_actionSuffix = actionSuffix;
	}

	/**
	 * Return the registered resources
	 */
	public function getResources() -> array
	{
		return this->_handlers;
	}
}
