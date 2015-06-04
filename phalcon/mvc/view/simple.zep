
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

namespace Phalcon\Mvc\View;

use Phalcon\Di\Injectable;
use Phalcon\Mvc\View\Exception;
use Phalcon\Mvc\ViewBaseInterface;
use Phalcon\Cache\BackendInterface;
use Phalcon\Mvc\View\Engine\Php as PhpEngine;

/**
 * Phalcon\Mvc\View\Simple
 *
 * This component allows to render views without hierarchical levels
 *
 *<code>
 * $view = new \Phalcon\Mvc\View\Simple();
 * echo $view->render('templates/my-view', array('content' => $html));
 * //or with filename with extension
 * echo $view->render('templates/my-view.volt', array('content' => $html));
 *</code>
 */
class Simple extends Injectable implements ViewBaseInterface
{

	protected _options;

	protected _viewsDir;

	protected _partialsDir;

	protected _viewParams;

	protected _engines = false;

	protected _registeredEngines  { get };

	protected _activeRenderPath;

	protected _content;

	protected _cache = false;

	protected _cacheOptions;

	/**
	 * Phalcon\Mvc\View\Simple constructor
	 *
	 * @param array options
	 */
	public function __construct(options = null)
	{
		if typeof options == "array" {
			let this->_options = options;
		}
	}

	/**
	 * Sets views directory. Depending of your platform, always add a trailing slash or backslash
	 */
	public function setViewsDir(string! viewsDir)
	{
		let this->_viewsDir = viewsDir;
	}

	/**
	 * Gets views directory
	 */
	public function getViewsDir() -> string
	{
		return this->_viewsDir;
	}

	/**
	 * Register templating engines
	 *
	 *<code>
	 *$this->view->registerEngines(array(
	 *  ".phtml" => "Phalcon\Mvc\View\Engine\Php",
	 *  ".volt" => "Phalcon\Mvc\View\Engine\Volt",
	 *  ".mhtml" => "MyCustomEngine"
	 *));
	 *</code>
	 */
	public function registerEngines(array! engines)
	{
		let this->_registeredEngines = engines;
	}

	/**
	 * Loads registered template engines, if none is registered it will use Phalcon\Mvc\View\Engine\Php
	 *
	 * @return array
	 */
	protected function _loadTemplateEngines()
	{
		var engines, dependencyInjector, registeredEngines, arguments, extension,
			engineService, engineObject;

		/**
		 * If the engines aren't initialized 'engines' is false
		 */
		let engines = this->_engines;
		if engines === false {

			let dependencyInjector = this->_dependencyInjector;

			let engines = [];

			let registeredEngines = this->_registeredEngines;
			if typeof registeredEngines != "array" {

				/**
				 * We use Phalcon\Mvc\View\Engine\Php as default
				 * Use .phtml as extension for the PHP engine
				 */
				let engines[".phtml"] = new PhpEngine(this, dependencyInjector);

			} else {

				if typeof dependencyInjector != "object" {
					throw new Exception("A dependency injector container is required to obtain the application services");
				}

				/**
				 * Arguments for instantiated engines
				 */
				let arguments = [this, dependencyInjector];

				for extension, engineService in registeredEngines {

					if typeof engineService == "object" {
						/**
						 * Engine can be a closure
						 */
						if engineService instanceof \Closure {
							let engineObject = call_user_func_array(engineService, arguments);
						} else {
							let engineObject = engineService;
						}
					} else {
						/**
						 * Engine can be a string representing a service in the DI
						 */
						if typeof engineService == "string" {
							let engineObject = dependencyInjector->getShared(engineService, arguments);
						} else {
							throw new Exception("Invalid template engine registration for extension: " . extension);
						}
					}

					let engines[extension] = engineObject;
				}
			}

			let this->_engines = engines;
		} else {
			let engines = this->_engines;
		}

		return engines;
	}

	/**
	 * Tries to render the view with every engine registered in the component
	 *
	 * @param string path
	 * @param array  params
	 */
	protected final function _internalRender(string! path, params)
	{
		var eventsManager, notExists, engines, extension, engine, mustClean, viewEnginePath, viewsDirPath;

		let eventsManager = this->_eventsManager;

		if typeof eventsManager == "object" {
			let this->_activeRenderPath = path;
		}

		/**
		 * Call beforeRender if there is an events manager
		 */
		if typeof eventsManager == "object" {
			if eventsManager->fire("view:beforeRender", this) === false {
				return null;
			}
		}

		let notExists = true, mustClean = true;

		let viewsDirPath =  this->_viewsDir . path;

		/**
		 * Load the template engines
		 */
		let engines = this->_loadTemplateEngines();

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
				 * Call beforeRenderView if there is a events manager available
				 */
				if typeof eventsManager == "object" {
					if eventsManager->fire("view:beforeRenderView", this, viewEnginePath) === false {
						continue;
					}
				}

				engine->render(viewEnginePath, params, mustClean);

				/**
				 * Call afterRenderView if there is a events manager available
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
		if notExists === true {
			throw new Exception("View '" . viewsDirPath . "' was not found in the views directory");
		}

		/**
		 * Call afterRender event
		 */
		if typeof eventsManager == "object" {
			eventsManager->fire("view:afterRender", this);
		}

	}

	/**
	 * Renders a view
	 *
	 * @param  string path
	 * @param  array  params
	 * @return string
	 */
	public function render(string! path, params = null)
	{
		var cache, key, lifetime, cacheOptions, content, viewParams, mergedParams;

		/**
		 * Create/Get a cache
		 */
		let cache = this->getCache();

		if typeof cache == "object" {

			/**
			 * Check if the cache is started, the first time a cache is started we start the cache
			 */
			if cache->isStarted() === false {

				let key = null, lifetime = null;

				/**
				 * Check if the user has defined a different options to the default
				 */
				let cacheOptions = this->_cacheOptions;
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
					let this->_content = content;
					return content;
				}
			}

		}

		/**
		 * Create a virtual symbol table
		 */
		create_symbol_table();

		ob_start();

		let viewParams = this->_viewParams;

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
		this->_internalRender(path, mergedParams);

		/**
		 * Store the data in output into the cache
		 */
		if typeof cache == "object" {
			if cache->isStarted() === true {
				if cache->isFresh() === true {
					cache->save();
				} else {
					cache->stop();
				}
			} else {
				cache->stop();
			}
		}

		ob_end_clean();

		return this->_content;
	}

	/**
	 * Renders a partial view
	 *
	 * <code>
	 * 	//Show a partial inside another view
	 * 	$this->partial('shared/footer');
	 * </code>
	 *
	 * <code>
	 * 	//Show a partial inside another view with parameters
	 * 	$this->partial('shared/footer', array('content' => $html));
	 * </code>
	 *
	 * @param string partialPath
	 * @param array  params
	 */
	public function partial(string! partialPath, params = null)
	{
		var viewParams, mergedParams;

		/**
		 * Start output buffering
		 */
		ob_start();

		/**
		 * If the developer pass an array of variables we create a new virtual symbol table
		 */
		if typeof params == "array" {

			let viewParams = this->_viewParams;

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
		this->_internalRender(partialPath, mergedParams);

		/**
		 * Now we need to restore the original view parameters
		 */
		if typeof params == "array" {
			/**
			 * Restore the original view params
			 */
			let this->_viewParams = viewParams;
		}

		ob_end_clean();

		/**
		 * Content is output to the parent view
		 */
		echo this->_content;
	}

	/**
	 * Sets the cache options
	 *
	 * @param  array options
	 * @return Phalcon\Mvc\View\Simple
	 */
	public function setCacheOptions(options) -> <Simple>
	{
		let this->_cacheOptions = options;
		return this;
	}

	/**
	 * Returns the cache options
	 *
	 * @return array
	 */
	public function getCacheOptions()
	{
		return this->_cacheOptions;
	}

	/**
	 * Create a Phalcon\Cache based on the internal cache options
	 */
	protected function _createCache() -> <BackendInterface>
	{
		var dependencyInjector, cacheService, cacheOptions, viewCache;

		let dependencyInjector = this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			throw new Exception("A dependency injector container is required to obtain the view cache services");
		}

		let cacheService = "viewCache";

		let cacheOptions = this->_cacheOptions;
		if typeof cacheOptions == "array" {
			if isset cacheOptions["service"] {
				fetch cacheService, cacheOptions["service"];
			}
		}

		/**
		 * The injected service must be an object
		 */
		let viewCache = <BackendInterface> dependencyInjector->getShared(cacheService);
		if typeof viewCache != "object" {
			throw new Exception("The injected caching service is invalid");
		}

		return viewCache;
	}

	/**
	 * Returns the cache instance used to cache
	 */
	public function getCache() -> <BackendInterface>
	{
		var cache;

		let cache = this->_cache;
		if cache {
			if typeof cache != "object" {
				let cache = this->_createCache(), this->_cache = cache;
			}
		}
		return cache;
	}

	/**
	 * Cache the actual view render to certain level
	 *
	 *<code>
	 *  $this->view->cache(array('key' => 'my-key', 'lifetime' => 86400));
	 *</code>
	 */
	public function cache(var options = true) -> <Simple>
	{
		if typeof options == "array" {
			let this->_cache = true, this->_cacheOptions = options;
		} else {
			if options {
				let this->_cache = true;
			} else {
				let this->_cache = false;
			}
		}
		return this;
	}

	/**
	 * Adds parameters to views (alias of setVar)
	 *
	 *<code>
	 *	$this->view->setParamToView('products', $products);
	 *</code>
	 */
	public function setParamToView(string! key, var value) -> <Simple>
	{
		let this->_viewParams[key] = value;
		return this;
	}

	/**
	 * Set all the render params
	 *
	 *<code>
	 *	$this->view->setVars(array('products' => $products));
	 *</code>
	 */
	public function setVars(array! params, boolean merge = true) -> <Simple>
	{
		var viewParams, mergedParams;

		if merge {
			let viewParams = this->_viewParams;
			if typeof viewParams == "array" {
				let mergedParams = array_merge(viewParams, params);
			} else {
				let mergedParams = params;
			}
			let this->_viewParams = mergedParams;
		} else {
			let this->_viewParams = params;
		}

		return this;
	}

	/**
	 * Set a single view parameter
	 *
	 *<code>
	 *	$this->view->setVar('products', $products);
	 *</code>
	 */
	public function setVar(string! key, value) -> <Simple>
	{
		let this->_viewParams[key] = value;
		return this;
	}

	/**
	 * Returns a parameter previously set in the view
	 *
	 * @param string key
	 * @return mixed
	 */
	public function getVar(string! key)
	{
		var	value;
		if fetch value, this->_viewParams[key] {
			return value;
		}
		return null;
	}

	/**
	 * Returns parameters to views
	 *
	 * @return array
	 */
	public function getParamsToView()
	{
		return this->_viewParams;
	}

	/**
	 * Externally sets the view content
	 *
	 *<code>
	 *	$this->view->setContent("<h1>hello</h1>");
	 *</code>
	 */
	public function setContent(string! content) -> <Simple>
	{
		let this->_content = content;
		return this;
	}

	/**
	 * Returns cached output from another view stage
	 */
	public function getContent() -> string
	{
		return this->_content;
	}

	/**
	 * Returns the path of the view that is currently rendered
	 *
	 * @return string
	 */
	public function getActiveRenderPath()
	{
		return this->_activeRenderPath;
	}

	/**
	 * Magic method to pass variables to the views
	 *
	 *<code>
	 *	$this->view->products = $products;
	 *</code>
	 */
	public function __set(string! key, var value)
	{
		let this->_viewParams[key] = value;
	}

	/**
	 * Magic method to retrieve a variable passed to the view
	 *
	 *<code>
	 *	echo $this->view->products;
	 *</code>
	 *
	 * @param string key
	 * @return mixed
	 */
	public function __get(string! key)
	{
		var value;
		if fetch value, this->_viewParams[key] {
			return value;
		}
		return null;
	}
}
