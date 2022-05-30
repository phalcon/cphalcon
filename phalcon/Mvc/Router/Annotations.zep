
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Router;

use Phalcon\Di\DiInterface;
use Phalcon\Mvc\Router;
use Phalcon\Annotations\Annotation;

/**
 * Phalcon\Mvc\Router\Annotations
 *
 * A router that reads routes annotations from classes/resources
 *
 * ```php
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
 * ```
 */
class Annotations extends Router
{
    /**
     * @var string
     */
    protected actionSuffix = "Action";

    /**
     * @var callable|string|null
     */
    protected actionPreformatCallback = null;

    /**
     * @var string
     */
    protected controllerSuffix = "Controller";

    /**
     * @var array
     */
    protected handlers = [];

    /**
     * @var string
     */
    protected routePrefix = "";

    /**
     * Adds a resource to the annotations handler
     * A resource is a class that contains routing annotations
     * The class is located in a module
     */
    public function addModuleResource(string! module, string! handler, string! prefix = null) -> <Annotations>
    {
        let this->handlers[] = [prefix, handler, module];

        return this;
    }

    /**
     * Adds a resource to the annotations handler
     * A resource is a class that contains routing annotations
     */
    public function addResource(string! handler, string! prefix = null) -> <Annotations>
    {
        let this->handlers[] = [prefix, handler];

        return this;
    }

    /**
     * Return the registered resources
     */
    public function getResources() -> array
    {
        return this->handlers;
    }

    /**
     * Produce the routing parameters from the rewrite information
     */
    public function handle(string! uri) -> void
    {
        var annotationsService, handlers, controllerSuffix, scope, prefix,
            route, compiledPattern, container, handler, controllerName,
            lowerControllerName, namespaceName, moduleName, handlerAnnotations,
            classAnnotations, annotations, annotation, methodAnnotations, method,
            collection;
        string sufixed;

        let container = <DiInterface> this->container;

        if unlikely typeof container != "object" {
            throw new Exception(
                "A dependency injection container is required to access the 'annotations' service"
            );
        }

        let handlers = this->handlers;
        let controllerSuffix = this->controllerSuffix;
        let annotationsService = container->getShared("annotations");

        for scope in handlers {
            if typeof scope != "array" {
                continue;
            }

            /**
             * A prefix (if any) must be in position 0
             */
            let prefix = scope[0];

            if !empty prefix {
                /**
                 * Route object is used to compile patterns
                 */
                let route = new Route(prefix);

                /**
                 * Compiled patterns can be valid regular expressions.
                 * In that case We only need to theck if it starts with
                 * the pattern so we remove to "$" from the end.
                 */
                let compiledPattern = str_replace(
                    "$#", "#", route->getCompiledPattern()
                );

                if memstr(compiledPattern, "^") {
                    /**
                     * If it's a regular expression, it will contain the "^"
                     */
                    if !preg_match(compiledPattern, uri) {
                        continue;
                    }
                } elseif !starts_with(uri, prefix) {
                    continue;
                }
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

                fetch namespaceName, this->defaultNamespace;
            }

            let this->routePrefix = null;

            /**
             * Check if the scope has a module associated
             */
            fetch moduleName, scope[2];
            let moduleName = moduleName !== null ? moduleName : "";

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
                        this->processControllerAnnotation(
                            controllerName,
                            annotation
                        );
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
                    if typeof collection != "object" {
                        continue;
                    }

                    for annotation in collection->getAnnotations() {
                        this->processActionAnnotation(
                            moduleName,
                            namespaceName,
                            lowerControllerName,
                            method,
                            annotation
                        );
                    }
                }
            }
        }

        /**
         * Call the parent handle method()
         */
        parent::handle(uri);
    }

    /**
     * Checks for annotations in the public methods of the controller
     */
    public function processActionAnnotation(
        string! module,
        string! namespaceName,
        string! controller,
        string! action,
        <Annotation> annotation
    ) -> void {
        var name, proxyActionName, actionName, routePrefix, paths, value, uri, route, methods,
            converts, param, convert, converterParam, routeName, beforeMatch;
        bool isRoute;

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
            case "Post":
            case "Put":
            case "Patch":
            case "Delete":
            case "Options":
                let isRoute = true,
                    methods = strtoupper(name);
                break;
        }

        if !isRoute {
            return;
        }

        let proxyActionName = str_replace(this->actionSuffix, "", action),
            routePrefix = this->routePrefix;

        if this->actionPreformatCallback !== null {
            let proxyActionName = call_user_func(this->actionPreformatCallback, proxyActionName);
        }

        let actionName = strtolower(proxyActionName);

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
        if value !== null {
            if value != "/" {
                let uri = routePrefix . value;
            } else {
                if routePrefix !== null {
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
        if methods === null {
            let methods = annotation->getNamedArgument("methods");
        }

        if typeof methods == "array" || typeof methods == "string" {
            route->via(methods);
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
         * Add the converters
         */
        let converts = annotation->getNamedArgument("converters");

        if typeof converts == "array" {
            for converterParam, convert in converts {
                route->convert(converterParam, convert);
            }
        }

        /**
         * Add the converters
         */
        let beforeMatch = annotation->getNamedArgument("beforeMatch");

        if typeof beforeMatch == "array" || typeof beforeMatch == "string" {
            route->beforeMatch(beforeMatch);
        }

        let routeName = annotation->getNamedArgument("name");

        if typeof routeName == "string" {
            route->setName(routeName);
        }
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
            let this->routePrefix = annotation->getArgument(0);
        }
    }

    /**
     * Changes the action method suffix
     */
    public function setActionSuffix(string! actionSuffix)
    {
        let this->actionSuffix = actionSuffix;
    }

    /**
     * Sets the action preformat callback
     * $action here already without suffix 'Action'
     *
     * ```php
     * // Array as callback
     * $annotationRouter->setActionPreformatCallback(
     *      [
     *          new Uncamelize(),
     *          '__invoke'
     *      ]
     *  );
     *
     * // Function as callback
     * $annotationRouter->setActionPreformatCallback(
     *     function ($action) {
     *         return $action;
     *     }
     * );
     *
     * // String as callback
     * $annotationRouter->setActionPreformatCallback('strtolower');
     *
     * // If empty method constructor called [null], sets uncamelize with - delimiter
     * $annotationRouter->setActionPreformatCallback();
     * ```
     *
     * @param callable|string|null $callback
     */
    public function setActionPreformatCallback(var callback = null)
    {
        if likely is_callable(callback) {
            let this->actionPreformatCallback = callback;
        } elseif callback === null {
            let this->actionPreformatCallback = function (action) {
                return uncamelize(action, "-");
            };
        } else {
            throw new Exception(
                "The 'callback' parameter must be either a callable or NULL."
            );
        }
    }

    /**
     * @return callable|string|null
     */
    public function getActionPreformatCallback()
    {
        return this->actionPreformatCallback;
    }

    /**
     * Changes the controller class suffix
     */
    public function setControllerSuffix(string! controllerSuffix)
    {
        let this->controllerSuffix = controllerSuffix;
    }
}
