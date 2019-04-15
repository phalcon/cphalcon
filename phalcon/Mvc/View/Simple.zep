
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\View;

use Closure;
use Phalcon\Di\Injectable;
use Phalcon\Mvc\View\Exception;
use Phalcon\Mvc\ViewBaseInterface;
use Phalcon\Cache\BackendInterface;
use Phalcon\Mvc\View\EngineInterface;
use Phalcon\Mvc\View\Engine\Php as PhpEngine;

/**
 * Phalcon\Mvc\View\Simple
 *
 * This component allows to render views without hierarchical levels
 *
 *<code>
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
 *</code>
 */
class Simple extends Injectable implements ViewBaseInterface
{

    protected activeRenderPath;
    protected cache = false;
    protected cacheOptions;
    protected content;

    /**
     * @var \Phalcon\Mvc\View\EngineInterface[]|false
     */
    protected engines = false;

    protected options;
    protected partialsDir;

    /**
     * @var array|null
     */
    protected registeredEngines { get };

    protected viewsDir;

    protected viewParams;

    /**
     * Phalcon\Mvc\View\Simple constructor
     */
    public function __construct(array options = [])
    {
        let this->options = options;
    }

    /**
     * Magic method to retrieve a variable passed to the view
     *
     *<code>
     * echo $this->view->products;
     *</code>
     */
    public function __get(string! key) -> var | null
    {
        var value;
        if fetch value, this->viewParams[key] {
            return value;
        }

        return null;
    }

    /**
     * Magic method to pass variables to the views
     *
     *<code>
     * $this->view->products = $products;
     *</code>
     */
    public function __set(string! key, var value)
    {
        let this->viewParams[key] = value;
    }

    /**
     * Cache the actual view render to certain level
     *
     *<code>
     * $this->view->cache(
     *     [
     *         "key"      => "my-key",
     *         "lifetime" => 86400,
     *     ]
     * );
     *</code>
     */
    public function cache(var options = true) -> <Simple>
    {
        if typeof options == "array" {
            let this->cache = true,
                this->cacheOptions = options;
        } else {
            if options {
                let this->cache = true;
            } else {
                let this->cache = false;
            }
        }
        return this;
    }

    /**
     * Returns the path of the view that is currently rendered
     */
    public function getActiveRenderPath() -> string
    {
        return this->activeRenderPath;
    }

    /**
     * Returns the cache instance used to cache
     */
    public function getCache() -> <BackendInterface>
    {
        if this->cache && typeof this->cache != "object" {
            let this->cache = this->createCache();
        }

        return this->cache;
    }

    /**
     * Returns the cache options
     */
    public function getCacheOptions() -> array
    {
        return this->cacheOptions;
    }

    /**
     * Returns cached output from another view stage
     */
    public function getContent() -> string
    {
        return this->content;
    }

    /**
     * Returns parameters to views
     */
    public function getParamsToView() -> array
    {
        return this->viewParams;
    }

    /**
     * Returns a parameter previously set in the view
     */
    public function getVar(string! key) -> var | null
    {
        var    value;
        if fetch value, this->viewParams[key] {
            return value;
        }
        return null;
    }

    /**
     * Gets views directory
     */
    public function getViewsDir() -> string
    {
        return this->viewsDir;
    }

    /**
     * Renders a partial view
     *
     * <code>
     * // Show a partial inside another view
     * $this->partial("shared/footer");
     * </code>
     *
     * <code>
     * // Show a partial inside another view with parameters
     * $this->partial(
     *     "shared/footer",
     *     [
     *         "content" => $html,
     *     ]
     * );
     * </code>
     */
    public function partial(string! partialPath, var params = null)
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
            if typeof viewParams == "array" {
                let mergedParams = array_merge(viewParams, params);
            } else {
                let mergedParams = params;
            }

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
     *<code>
     * $this->view->registerEngines(
     *     [
     *         ".phtml" => "Phalcon\\Mvc\\View\\Engine\\Php",
     *         ".volt"  => "Phalcon\\Mvc\\View\\Engine\\Volt",
     *         ".mhtml" => "MyCustomEngine",
     *     ]
     * );
     *</code>
     */
    public function registerEngines(array! engines)
    {
        let this->registeredEngines = engines;
    }

    /**
     * Renders a view
     *
     * @param  array  params
     */
    public function render(string! path, params = null) -> string
    {
        var cache, key, lifetime, cacheOptions, content, viewParams, mergedParams;

        /**
         * Create/Get a cache
         */
        let cache = this->getCache();

        if typeof cache == "object" {

            /**
             * Check if the cache is started, the first time a cache is started
             * we start the cache
             */
            if !cache->isStarted() {

                let key = null, lifetime = null;

                /**
                 * Check if the user has defined a different options to the
                 * default
                 */
                let cacheOptions = this->cacheOptions;
                if typeof cacheOptions == "array" {
                    fetch key, cacheOptions["key"];
                    fetch lifetime, cacheOptions["lifetime"];
                }

                /**
                 * If a cache key is not set we create one using a md5
                 */
                if key === null {
                    let key = md5(path);
                }

                /**
                 * We start the cache using the key set
                 */
                let content = cache->start(key, lifetime);
                if content !== null {
                    let this->content = content;
                    return content;
                }
            }

        }

        /**
         * Create a virtual symbol table
         */
        create_symbol_table();

        ob_start();

        let viewParams = this->viewParams;

        /**
         * Merge parameters
         */
        if typeof params == "array" {
            if typeof viewParams == "array" {
                let mergedParams = array_merge(viewParams, params);
            } else {
                let mergedParams = params;
            }
        } else {
            let mergedParams = viewParams;
        }

        /**
         * internalRender is also reused by partials
         */
        this->internalRender(path, mergedParams);

        /**
         * Store the data in output into the cache
         */
        if typeof cache == "object" {
            if cache->isStarted() && cache->isFresh() {
                cache->save();
            } else {
                cache->stop();
            }
        }

        ob_end_clean();

        return this->content;
    }

    /**
     * Sets the cache options
     */
    public function setCacheOptions(array options) -> <Simple>
    {
        let this->cacheOptions = options;
        return this;
    }

    /**
     * Externally sets the view content
     *
     *<code>
     * $this->view->setContent("<h1>hello</h1>");
     *</code>
     */
    public function setContent(string! content) -> <Simple>
    {
        let this->content = content;
        return this;
    }

    /**
     * Adds parameters to views (alias of setVar)
     *
     *<code>
     * $this->view->setParamToView("products", $products);
     *</code>
     */
    public function setParamToView(string! key, var value) -> <Simple>
    {
        let this->viewParams[key] = value;
        return this;
    }

    /**
     * Set a single view parameter
     *
     *<code>
     * $this->view->setVar("products", $products);
     *</code>
     */
    public function setVar(string! key, var value) -> <Simple>
    {
        let this->viewParams[key] = value;
        return this;
    }

    /**
     * Set all the render params
     *
     *<code>
     * $this->view->setVars(
     *     [
     *         "products" => $products,
     *     ]
     * );
     *</code>
     */
    public function setVars(array! params, bool merge = true) -> <Simple>
    {
        if merge && typeof this->viewParams == "array" {
            let this->viewParams = array_merge(this->viewParams, params);
        } else {
            let this->viewParams = params;
        }

        return this;
    }

    /**
     * Sets views directory
     */
    public function setViewsDir(string! viewsDir)
    {
        if substr(viewsDir, -1) != DIRECTORY_SEPARATOR {
            let viewsDir = viewsDir . DIRECTORY_SEPARATOR;
        }

        let this->viewsDir = viewsDir;
    }

    /**
     * Create a Phalcon\Cache based on the internal cache options
     */
    protected function createCache() -> <BackendInterface>
    {
        var container, cacheService, cacheOptions, viewCache;

        let container = this->container;
        if typeof container != "object" {
            throw new Exception(
                Exception::containerServiceNotFound("the view cache services")
            );
        }

        let cacheService = "viewCache";

        let cacheOptions = this->cacheOptions;
        if typeof cacheOptions == "array" {
            if isset cacheOptions["service"] {
                fetch cacheService, cacheOptions["service"];
            }
        }

        /**
         * The injected service must be an object
         */
        let viewCache = <BackendInterface> container->getShared(cacheService);
        if typeof viewCache != "object" {
            throw new Exception("The injected caching service is invalid");
        }

        return viewCache;
    }

    /**
     * Loads registered template engines, if none is registered it will use Phalcon\Mvc\View\Engine\Php
     */
    protected function loadTemplateEngines() -> array
    {
        var engines, di, registeredEngines, extension,
            engineService, engineObject;

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
     * @param array  params
     */
    final protected function internalRender(string! path, params)
    {
        var eventsManager, engines, extension, engine, mustClean, viewEnginePath, viewsDirPath;
        bool notExists;

        let eventsManager = this->eventsManager;

        if typeof eventsManager == "object" {
            let this->activeRenderPath = path;
        }

        /**
         * Call beforeRender if there is an events manager
         */
        if typeof eventsManager == "object" {
            if eventsManager->fire("view:beforeRender", this) === false {
                return null;
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
            } else {

                /**
                 * if passed filename with engine extension
                 */
                if extension && substr(viewsDirPath, -strlen(extension)) == extension && file_exists(viewsDirPath) {
                    let viewEnginePath = viewsDirPath;
                } else {
                    let viewEnginePath = "";
                }
            }

            if viewEnginePath {

                /**
                 * Call beforeRenderView if there is an events manager available
                 */
                if typeof eventsManager == "object" {
                    if eventsManager->fire("view:beforeRenderView", this, viewEnginePath) === false {
                        continue;
                    }
                }

                engine->render(viewEnginePath, params, mustClean);

                /**
                 * Call afterRenderView if there is an events manager available
                 */
                let notExists = false;
                if typeof eventsManager == "object" {
                    eventsManager->fire("view:afterRenderView", this);
                }
                break;
            }
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
}
