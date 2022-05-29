
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc;

use Closure;
use Phalcon\Application\AbstractApplication;
use Phalcon\Di\DiInterface;
use Phalcon\Http\ResponseInterface;
use Phalcon\Events\ManagerInterface;
use Phalcon\Mvc\Application\Exception;
use Phalcon\Mvc\Router\RouteInterface;
use Phalcon\Mvc\ModuleDefinitionInterface;

/**
 * Phalcon\Mvc\Application
 *
 * This component encapsulates all the complex operations behind instantiating
 * every component needed and integrating it with the rest to allow the MVC
 * pattern to operate as desired.
 *
 *```php
 * use Phalcon\Mvc\Application;
 *
 * class MyApp extends Application
 * {
 *     /**
 *      * Register the services here to make them general or register
 *      * in the ModuleDefinition to make them module-specific
 *      *\/
 *     protected function registerServices()
 *     {
 *
 *     }
 *
 *     /**
 *      * This method registers all the modules in the application
 *      *\/
 *     public function main()
 *     {
 *         $this->registerModules(
 *             [
 *                 "frontend" => [
 *                     "className" => "Multiple\\Frontend\\Module",
 *                     "path"      => "../apps/frontend/Module.php",
 *                 ],
 *                 "backend" => [
 *                     "className" => "Multiple\\Backend\\Module",
 *                     "path"      => "../apps/backend/Module.php",
 *                 ],
 *             ]
 *         );
 *     }
 * }
 *
 * $application = new MyApp();
 *
 * $application->main();
 *```
 */
class Application extends AbstractApplication
{
    /**
     * @var bool
     */
    protected implicitView = true;

    /**
     * @var bool
     */
    protected sendCookies = true;

    /**
     * @var bool
     */
    protected sendHeaders = true;

    /**
     * Handles a MVC request
     */
    public function handle(string! uri) -> <ResponseInterface> | bool
    {
        var container, eventsManager, router, dispatcher, response, view,
            module, moduleObject, moduleName, className, path, implicitView,
            returnedResponse, controller, possibleResponse, renderStatus,
            matchedRoute, match;

        let container = this->container;

        if container === null {
            throw new Exception(
                "A dependency injection container is required to access internal services"
            );
        }

        let eventsManager = <ManagerInterface> this->eventsManager;

        /**
         * Call boot event, this allow the developer to perform initialization
         * actions
         */
        if eventsManager !== null && eventsManager->fire("application:boot", this) === false {
            return false;
        }

        let router = <RouterInterface> container->getShared("router");

        /**
         * Handle the URI pattern (if any)
         */
        router->handle(uri);

        /**
         * If a 'match' callback was defined in the matched route
         * The whole dispatcher+view behavior can be overridden by the developer
         */
        let matchedRoute = router->getMatchedRoute();

        if typeof matchedRoute == "object" {
            let match = matchedRoute->getMatch();

            if match !== null {
                if match instanceof Closure {
                    let match = Closure::bind(match, container);
                }

                /**
                 * Directly call the match callback
                 */
                let possibleResponse = call_user_func_array(
                    match,
                    router->getParams()
                );

                /**
                 * If the returned value is a string return it as body
                 */
                if typeof possibleResponse == "string" {
                    let response = <ResponseInterface> container->getShared("response");

                    response->setContent(possibleResponse);

                    return response;
                }

                /**
                 * If the returned string is a ResponseInterface use it as
                 * response
                 */
                if typeof possibleResponse == "object" && possibleResponse instanceof ResponseInterface {
                    possibleResponse->sendHeaders();
                    possibleResponse->sendCookies();

                    return possibleResponse;
                }
            }
        }

        /**
         * If the router doesn't return a valid module we use the default module
         */
        let moduleName = router->getModuleName();

        if !moduleName {
            let moduleName = this->defaultModule;
        }

        let moduleObject = null;

        /**
         * Process the module definition
         */
        if moduleName {
            if typeof eventsManager == "object" {
                if eventsManager->fire("application:beforeStartModule", this, moduleName) === false {
                    return false;
                }
            }

            /**
             * Gets the module definition
             */
            let module = this->getModule(moduleName);

            /**
             * A module definition must ne an array or an object
             */
            if unlikely (typeof module != "array" && typeof module != "object") {
                throw new Exception("Invalid module definition");
            }

            /**
             * An array module definition contains a path to a module definition
             * class
             */
            if typeof module == "array" {
                /**
                 * Class name used to load the module definition
                 */
                if !fetch className, module["className"] {
                    let className = "Module";
                }

                /**
                 * If developer specify a path try to include the file
                 */
                if fetch path, module["path"] {
                    if unlikely !file_exists(path) {
                        throw new Exception(
                            "Module definition path '" . path . "' doesn't exist"
                        );
                    }

                    if !class_exists(className, false) {
                        require_once path;
                    }
                }

                let moduleObject = <ModuleDefinitionInterface> container->get(className);

                /**
                 * 'registerAutoloaders' and 'registerServices' are
                 * automatically called
                 */
                moduleObject->registerAutoloaders(container);
                moduleObject->registerServices(container);
            } else {
                /**
                 * A module definition object, can be a Closure instance
                 */
                if unlikely !(module instanceof Closure) {
                    throw new Exception("Invalid module definition");
                }

                let moduleObject = call_user_func_array(
                    module,
                    [
                        container
                    ]
                );
            }

            /**
             * Calling afterStartModule event
             */
            if typeof eventsManager == "object" {
                eventsManager->fire("application:afterStartModule", this, moduleObject);
            }
        }

        /**
         * Check whether use implicit views or not
         */
        let implicitView = this->implicitView;

        if implicitView === true {
            let view = <ViewInterface> container->getShared("view");
        }

        /**
         * We get the parameters from the router and assign them to the dispatcher
         * Assign the values passed from the router
         */
        let dispatcher = <DispatcherInterface> container->getShared("dispatcher");

        dispatcher->setModuleName(router->getModuleName());
        dispatcher->setNamespaceName(router->getNamespaceName());
        dispatcher->setControllerName(router->getControllerName());
        dispatcher->setActionName(router->getActionName());
        dispatcher->setParams(router->getParams());

        /**
         * Start the view component (start output buffering)
         */
        if implicitView === true {
            view->start();
        }

        /**
         * Calling beforeHandleRequest
         */
        if typeof eventsManager == "object" {
            if eventsManager->fire("application:beforeHandleRequest", this, dispatcher) === false {
                return false;
            }
        }

        /**
         * The dispatcher must return an object
         */
        let controller = dispatcher->dispatch();

        /**
         * Get the latest value returned by an action
         */
        let possibleResponse = dispatcher->getReturnedValue();

        /**
         * Returning false from an action cancels the view
         */
        if possibleResponse === false {
            let response = <ResponseInterface> container->getShared("response");
        } else {
            /**
             * Returning a string makes use it as the body of the response
             */
            if typeof possibleResponse == "string" {
                let response = <ResponseInterface> container->getShared("response");

                response->setContent(possibleResponse);
            } else {
                /**
                 * Check if the returned object is already a response
                 */
                let returnedResponse = ((typeof possibleResponse == "object") && (possibleResponse instanceof ResponseInterface));

                /**
                 * Calling afterHandleRequest
                 */
                if typeof eventsManager == "object" {
                    eventsManager->fire("application:afterHandleRequest", this, controller);
                }

                /**
                 * If the dispatcher returns an object we try to render the view
                 * in auto-rendering mode
                 */
                if returnedResponse === false && implicitView === true {
                    if typeof controller == "object" {
                        let renderStatus = true;

                        /**
                         * This allows to make a custom view render
                         */
                        if typeof eventsManager == "object" {
                            let renderStatus = eventsManager->fire("application:viewRender", this, view);
                        }

                        /**
                         * Check if the view process has been treated by the
                         * developer
                         */
                        if renderStatus !== false {

                            /**
                             * Automatic render based on the latest controller
                             * executed
                             */
                            view->render(
                                dispatcher->getControllerName(),
                                dispatcher->getActionName()
                            );
                        }
                    }
                }

                /**
                 * Finish the view component (stop output buffering)
                 */
                if implicitView === true {
                    view->finish();
                }

                if returnedResponse === true {
                    /**
                     * We don't need to create a response because there is one
                     * already created
                     */
                    let response = possibleResponse;
                } else {
                    let response = <ResponseInterface> container->getShared("response");

                    if implicitView === true {
                        /**
                         * The content returned by the view is passed to the
                         * response service
                         */
                        response->setContent(
                            view->getContent()
                        );
                    }
                }
            }
        }

        /**
         * Calling beforeSendResponse
         */
        if typeof eventsManager == "object" {
            eventsManager->fire("application:beforeSendResponse", this, response);
        }

        /**
         * Check whether send headers or not (by default yes)
         */
        if this->sendHeaders  {
            response->sendHeaders();
        }

        /**
         * Check whether send cookies or not (by default yes)
         */
        if this->sendCookies {
            response->sendCookies();
        }

        /**
         * Return the response
         */
        return response;
    }

    /**
     * Enables or disables sending cookies by each request handling
     */
    public function sendCookiesOnHandleRequest(bool sendCookies) -> <Application>
    {
        let this->sendCookies = sendCookies;

        return this;
    }


    /**
     * Enables or disables sending headers by each request handling
     */
    public function sendHeadersOnHandleRequest(bool sendHeaders) -> <Application>
    {
        let this->sendHeaders = sendHeaders;

        return this;
    }

    /**
     * By default. The view is implicitly buffering all the output
     * You can full disable the view component using this method
     */
    public function useImplicitView(bool implicitView) -> <Application>
    {
        let this->implicitView = implicitView;

        return this;
    }
}
