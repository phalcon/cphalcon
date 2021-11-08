
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\View;

use Closure;
use Phalcon\Di\DiInterface;
use Phalcon\Di\Injectable;
use Phalcon\Events\EventsAwareInterface;
use Phalcon\Events\ManagerInterface;
use Phalcon\Mvc\ViewBaseInterface;
use Phalcon\Mvc\View\Engine\EngineInterface;
use Phalcon\Mvc\View\Engine\Php as PhpEngine;

/**
 * Phalcon\Mvc\View\Simple
 *
 * This component allows to render views without hierarchical levels
 *
 *```php
 * use Phalcon\Mvc\View\Simple as View;
 *
 * $view = new View();
 *
 * // Render a view
 * echo $view->render(
 *     "templates/my-view",
 *     [
 *         "some" => $param,
 *     ]
 * );
 *
 * // Or with filename with extension
 * echo $view->render(
 *     "templates/my-view.volt",
 *     [
 *         "parameter" => $here,
 *     ]
 * );
 *```
 */
class Simple extends Injectable implements ViewBaseInterface, EventsAwareInterface
{
    /**
     * @var string
     */
    protected activeRenderPath;

    /**
     * @var string
     */
    protected content;

    /**
     * @var EngineInterface[]|false
     */
    protected engines = false; // TODO: Change to default null or empty array

    /**
     * @var ManagerInterface|null
     */
    protected eventsManager;

    /**
     * @var array
     */
    protected options = [];

    /**
     * @var array|null
     */
    protected registeredEngines { get };

    /**
     * @var string
     */
    protected viewsDir;

    /**
     * @var array
     */
    protected viewParams = [];

    /**
     * Phalcon\Mvc\View\Simple constructor
     *
     * @param array options
     */
    public function __construct(array options = [])
    {
        let this->options = options;
    }

    /**
     * Magic method to retrieve a variable passed to the view
     *
     *```php
     * echo $this->view->products;
     *```
     *
     * @return mixed|null
     */
    public function __get(string! key) -> var | null
    {
        var value;

        if !fetch value, this->viewParams[key] {
            return null;
        }

        return value;
    }

    /**
     * Magic method to pass variables to the views
     *
     *```php
     * $this->view->products = $products;
     *```
     *
     * @return void
     */
    public function __set(string! key, var value) -> void
    {
        let this->viewParams[key] = value;
    }

    /**
     * Returns the path of the view that is currently rendered
     *
     * @return string
     */
    public function getActiveRenderPath() -> string
    {
        return this->activeRenderPath;
    }

    /**
     * Returns output from another view stage
     *
     * @return string
     */
    public function getContent() -> string
    {
        return this->content;
    }

    /**
     * Returns the internal event manager
     *
     * @return ManagerInterface|null
     */
    public function getEventsManager()  -> <ManagerInterface> | null
    {
        return this->eventsManager;
    }

    /**
     * Returns parameters to views
     *
     * @return array
     */
    public function getParamsToView() -> array
    {
        return this->viewParams;
    }

    /**
     * Returns a parameter previously set in the view
     *
     * @return mixed|null
     */
    public function getVar(string! key) -> var | null
    {
        var value;

        if !fetch value, this->viewParams[key] {
            return null;
        }

        return value;
    }

    /**
     * Gets views directory
     *
     * @return string
     */
    public function getViewsDir() -> string
    {
        return this->viewsDir;
    }

    /**
     * Renders a partial view
     *
     * ```php
     * // Show a partial inside another view
     * $this->partial("shared/footer");
     * ```
     *
     * ```php
     * // Show a partial inside another view with parameters
     * $this->partial(
     *     "shared/footer",
     *     [
     *         "content" => $html,
     *     ]
     * );
     * ```
     *
     * @return void
     */
    public function partial(string! partialPath, var params = null) -> void
    {
        var viewParams, mergedParams;

        /**
         * Start output buffering
         */
        ob_start();

        /**
         * If the developer pass an array of variables we create a new virtual
         * symbol table
         */
        if typeof params == "array" {
            let viewParams = this->viewParams;

            /**
             * Merge or assign the new params as parameters
             */
            let mergedParams = array_merge(viewParams, params);

            /**
             * Create a virtual symbol table
             */
            create_symbol_table();
        } else {
            let mergedParams = params;
        }

        /**
         * Call engine render, this checks in every registered engine for the partial
         */
        this->internalRender(partialPath, mergedParams);

        /**
         * Now we need to restore the original view parameters
         */
        if typeof params == "array" {
            /**
             * Restore the original view params
             */
            let this->viewParams = viewParams;
        }

        ob_end_clean();

        /**
         * Content is output to the parent view
         */
        echo this->content;
    }

    /**
     * Register templating engines
     *
     *```php
     * $this->view->registerEngines(
     *     [
     *         ".phtml" => \Phalcon\Mvc\View\Engine\Php::class,
     *         ".volt"  => \Phalcon\Mvc\View\Engine\Volt::class,
     *         ".mhtml" => \MyCustomEngine::class,
     *     ]
     * );
     *```
     *
     * @return void
     */
    public function registerEngines(array! engines) -> void
    {
        let this->registeredEngines = engines;
    }

    /**
     * Renders a view
     *
     * @return string
     */
    public function render(string! path, array params = []) -> string
    {
        var mergedParams, viewParams;

        /**
         * Create a virtual symbol table
         */
        create_symbol_table();

        ob_start();

        let viewParams = this->viewParams;

        /**
         * Merge parameters
         */
        let mergedParams = array_merge(viewParams, params);

        /**
         * internalRender is also reused by partials
         */
        this->internalRender(path, mergedParams);

        ob_end_clean();

        return this->content;
    }

    /**
     * Externally sets the view content
     *
     *```php
     * $this->view->setContent("<h1>hello</h1>");
     *```
     *
     * @return Simple
     */
    public function setContent(string! content) -> <Simple>
    {
        let this->content = content;

        return this;
    }

    /**
     * Sets the events manager
     *
     * @return void
     */
    public function setEventsManager(<ManagerInterface> eventsManager) -> void
    {
        let this->eventsManager = eventsManager;
    }

    /**
     * Adds parameters to views (alias of setVar)
     *
     *```php
     * $this->view->setParamToView("products", $products);
     *```
     *
     * @return Simple
     */
    public function setParamToView(string! key, var value) -> <Simple>
    {
        return this->setVar(key, value);
    }

    /**
     * Set a single view parameter
     *
     *```php
     * $this->view->setVar("products", $products);
     *```
     *
     * @return Simple
     */
    public function setVar(string! key, var value) -> <Simple>
    {
        let this->viewParams[key] = value;

        return this;
    }

    /**
     * Set all the render params
     *
     *```php
     * $this->view->setVars(
     *     [
     *         "products" => $products,
     *     ]
     * );
     *```
     *
     * @return Simple
     */
    public function setVars(array! params, bool merge = true) -> <Simple>
    {
        if merge {
            let params = array_merge(this->viewParams, params);
        }

        let this->viewParams = params;

        return this;
    }

    /**
     * Sets views directory
     *
     * @return void
     */
    public function setViewsDir(string! viewsDir) -> void
    {
        let this->viewsDir = this->getDirSeparator(viewsDir);
    }

    /**
     * Loads registered template engines, if none are registered it will use
     * Phalcon\Mvc\View\Engine\Php
     *
     * @return array
     */
    protected function loadTemplateEngines() -> array
    {
        var engines, di, registeredEngines, extension, engineService,
            engineObject;

        /**
         * If the engines aren't initialized 'engines' is false
         */
        let engines = this->engines;

        if engines === false {
            let di = this->container;

            let engines = [];

            let registeredEngines = this->registeredEngines;

            if typeof registeredEngines != "array" {
                /**
                 * We use Phalcon\Mvc\View\Engine\Php as default
                 * Use .phtml as extension for the PHP engine
                 */
                let engines[".phtml"] = new PhpEngine(this, di);
            } else {
                if typeof di != "object" {
                    throw new Exception(
                        Exception::containerServiceNotFound(
                            "the application services"
                        )
                    );
                }

                for extension, engineService in registeredEngines {
                    if typeof engineService == "object" {
                        /**
                         * Engine can be a closure
                         */
                        if engineService instanceof Closure {
                            let engineService = Closure::bind(engineService, di);

                            let engineObject = call_user_func(engineService, this);
                        } else {
                            let engineObject = engineService;
                        }
                    } elseif typeof engineService == "string" {
                        /**
                         * Engine can be a string representing a service in the DI
                         */
                        let engineObject = di->getShared(
                            engineService,
                            [
                                this
                            ]
                        );
                    } else {
                        throw new Exception(
                            "Invalid template engine registration for extension: " . extension
                        );
                    }

                    let engines[extension] = engineObject;
                }
            }

            let this->engines = engines;
        } else {
            let engines = this->engines;
        }

        return engines;
    }

    /**
     * Tries to render the view with every engine registered in the component
     *
     * @param string path
     * @param array  params
     *
     * @return void
     */
    final protected function internalRender(string! path, params) -> void
    {
        var eventsManager, engines, extension, engine;
        bool notExists, mustClean;
        string viewEnginePath, viewsDirPath;

        let eventsManager = this->eventsManager;

        if typeof eventsManager == "object" {
            let this->activeRenderPath = path;
        }

        /**
         * Call beforeRender if there is an events manager
         */
        if typeof eventsManager == "object" {
            if eventsManager->fire("view:beforeRender", this) === false {
                return;
            }
        }

        let notExists = true,
            mustClean = true;

        let viewsDirPath =  this->viewsDir . path;

        /**
         * Load the template engines
         */
        let engines = this->loadTemplateEngines();

        /**
         * Views are rendered in each engine
         */
        for extension, engine in engines {
            if file_exists(viewsDirPath . extension) {
                let viewEnginePath = viewsDirPath . extension;
            } elseif substr(viewsDirPath, -strlen(extension)) == extension && file_exists(viewsDirPath) {
                /**
                 * if passed filename with engine extension
                 */

                let viewEnginePath = viewsDirPath;
            } else {
                continue;
            }

            /**
             * Call beforeRenderView if there is an events manager available
             */
            if typeof eventsManager == "object" {
                if eventsManager->fire("view:beforeRenderView", this, viewEnginePath) === false {
                    continue;
                }
            }

            engine->render(viewEnginePath, params, mustClean);

            let notExists = false;

            /**
             * Call afterRenderView if there is an events manager available
             */
            if typeof eventsManager == "object" {
                eventsManager->fire("view:afterRenderView", this);
            }

            break;
        }

        /**
         * Always throw an exception if the view does not exist
         */
        if notExists {
            throw new Exception(
                "View '" . viewsDirPath . "' was not found in the views directory"
            );
        }

        /**
         * Call afterRender event
         */
        if typeof eventsManager == "object" {
            eventsManager->fire("view:afterRender", this);
        }
    }

    /**
     * @todo Remove this when we get traits
     */
    private function getDirSeparator(string! directory) -> string
    {
        return rtrim(directory, DIRECTORY_SEPARATOR) . DIRECTORY_SEPARATOR;
    }
}
