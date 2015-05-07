
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

namespace Phalcon\Mvc;

use Phalcon\DiInterface;
use Phalcon\Di\Injectable;
use Phalcon\Mvc\View\Exception;
use Phalcon\Mvc\ViewInterface;
use Phalcon\Cache\BackendInterface;
use Phalcon\Events\ManagerInterface;
use Phalcon\Mvc\View\Engine\Php as PhpEngine;

/**
 * Phalcon\Mvc\View
 *
 * Phalcon\Mvc\View is a class for working with the "view" portion of the model-view-controller pattern.
 * That is, it exists to help keep the view script separate from the model and controller scripts.
 * It provides a system of helpers, output filters, and variable escaping.
 *
 * <code>
 * //Setting views directory
 * $view = new \Phalcon\Mvc\View();
 * $view->setViewsDir('app/views/');
 *
 * $view->start();
 * //Shows recent posts view (app/views/posts/recent.phtml)
 * $view->render('posts', 'recent');
 * $view->finish();
 *
 * //Printing views output
 * echo $view->getContent();
 * </code>
 */
class View extends Injectable implements ViewInterface
{

	/**
	 * Render Level: To the main layout
	 *
	 */
	const LEVEL_MAIN_LAYOUT = 5;

	/**
	 * Render Level: Render to the templates "after"
	 *
	 */
	const LEVEL_AFTER_TEMPLATE = 4;

	/**
	 * Render Level: Hasta el layout del controlador
	 *
	 */
	const LEVEL_LAYOUT = 3;

	/**
	 * Render Level: To the templates "before"
	 *
	 */
	const LEVEL_BEFORE_TEMPLATE = 2;

	/**
	 * Render Level: To the action view
	 */
	const LEVEL_ACTION_VIEW = 1;

	/**
	 * Render Level: No render any view
	 *
	 */
	const LEVEL_NO_RENDER = 0;

	/**
	 * Cache Mode
	 *
	 */
	const CACHE_MODE_NONE = 0;
	const CACHE_MODE_INVERSE = 1;

	protected _options;

	protected _basePath = "";

	protected _content = "";

	protected _renderLevel = 5 { get };

	protected _currentRenderLevel = 0 { get };

	protected _disabledLevels;

	protected _viewParams;

	protected _layout;

	protected _layoutsDir = "";

	protected _partialsDir = "";

	protected _viewsDir;

	protected _templatesBefore;

	protected _templatesAfter;

	protected _engines = false;

	protected _registeredEngines { get };

	protected _mainView = "index";

	protected _controllerName;

	protected _actionName;

	protected _params;

	protected _pickView;

	protected _cache;

	protected _cacheLevel = 0;

	protected _activeRenderPath;

	protected _disabled = false;

	/**
	 * Phalcon\Mvc\View constructor
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
	 * Sets the views directory. Depending of your platform, always add a trailing slash or backslash
	 */
	public function setViewsDir(string viewsDir) -> <View>
	{
		if (substr(viewsDir, -1) != DIRECTORY_SEPARATOR) {
			let viewsDir = viewsDir . DIRECTORY_SEPARATOR;
		}
		let this->_viewsDir = viewsDir;
		return this;
	}

	/**
	 * Gets views directory
	 */
	public function getViewsDir() -> string
	{
		return this->_viewsDir;
	}

	/**
	 * Sets the layouts sub-directory. Must be a directory under the views directory. Depending of your platform, always add a trailing slash or backslash
	 *
	 *<code>
	 * $view->setLayoutsDir('../common/layouts/');
	 *</code>
	 */
	public function setLayoutsDir(string layoutsDir) -> <View>
	{
		let this->_layoutsDir = layoutsDir;
		return this;
	}

	/**
	 * Gets the current layouts sub-directory
	 */
	public function getLayoutsDir() -> string
	{
		return this->_layoutsDir;
	}

	/**
	 * Sets a partials sub-directory. Must be a directory under the views directory. Depending of your platform, always add a trailing slash or backslash
	 *
	 *<code>
	 * $view->setPartialsDir('../common/partials/');
	 *</code>
	 */
	public function setPartialsDir(string partialsDir) -> <View>
	{
		let this->_partialsDir = partialsDir;
		return this;
	}

	/**
	 * Gets the current partials sub-directory
	 */
	public function getPartialsDir() -> string
	{
		return this->_partialsDir;
	}

	/**
	 * Sets base path. Depending of your platform, always add a trailing slash or backslash
	 *
	 * <code>
	 * 	$view->setBasePath(__DIR__ . '/');
	 * </code>
	 */
	public function setBasePath(string basePath) -> <View>
	{
		let this->_basePath = basePath;
		return this;
	}

	/**
	 * Sets the render level for the view
	 *
	 * <code>
	 * 	//Render the view related to the controller only
	 * 	$this->view->setRenderLevel(View::LEVEL_VIEW);
	 * </code>
	 */
	public function setRenderLevel(int level) -> <View>
	{
		let this->_renderLevel = level;
		return this;
	}

	/**
	 * Disables a specific level of rendering
	 *
	 *<code>
	 * //Render all levels except ACTION level
	 * $this->view->disableLevel(View::LEVEL_ACTION_VIEW);
	 *</code>
	 *
	 * @param int|array level
	 * @return Phalcon\Mvc\View
	 */
	public function disableLevel(var level) -> <View>
	{
		if typeof level == "array" {
			let this->_disabledLevels = level;
		} else {
			let this->_disabledLevels[level] = true;
		}
		return this;
	}

	/**
	 * Sets default view name. Must be a file without extension in the views directory
	 *
	 * <code>
	 * 	//Renders as main view views-dir/base.phtml
	 * 	$this->view->setMainView('base');
	 * </code>
	 */
	public function setMainView(string viewPath) -> <View>
	{
		let this->_mainView = viewPath;
		return this;
	}

	/**
	 * Returns the name of the main view
	 */
	public function getMainView() -> string
	{
		return this->_mainView;
	}

	/**
	 * Change the layout to be used instead of using the name of the latest controller name
	 *
	 * <code>
	 * 	$this->view->setLayout('main');
	 * </code>
	 */
	public function setLayout(string layout) -> <View>
	{
		let this->_layout = layout;
		return this;
	}

	/**
	 * Returns the name of the main view
	 */
	public function getLayout() -> string
	{
		return this->_layout;
	}

	/**
	 * Sets a template before the controller layout
	 *
	 * @param string|array templateBefore
	 * @return Phalcon\Mvc\View
	 */
	public function setTemplateBefore(var templateBefore) -> <View>
	{
		if typeof templateBefore != "array" {
			let this->_templatesBefore = [templateBefore];
		} else {
			let this->_templatesBefore = templateBefore;
		}
		return this;
	}

	/**
	 * Resets any "template before" layouts
	 */
	public function cleanTemplateBefore() -> <View>
	{
		let this->_templatesBefore = null;
		return this;
	}

	/**
	 * Sets a "template after" controller layout
	 *
	 * @param string|array templateAfter
	 * @return Phalcon\Mvc\View
	 */
	public function setTemplateAfter(var templateAfter) -> <View>
	{
		if typeof templateAfter != "array" {
			let this->_templatesAfter = [templateAfter];
		} else {
			let this->_templatesAfter = templateAfter;
		}
		return this;
	}

	/**
	 * Resets any template before layouts
	 */
	public function cleanTemplateAfter() -> <View>
	{
		let this->_templatesAfter = null;
		return this;
	}

	/**
	 * Adds parameters to views (alias of setVar)
	 *
	 *<code>
	 *	$this->view->setParamToView('products', $products);
	 *</code>
	 *
	 * @param string key
	 * @param mixed value
	 * @return Phalcon\Mvc\View
	 */
	public function setParamToView(string! key, value) -> <View>
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
	 *
	 * @param array params
	 * @param boolean merge
	 * @return Phalcon\Mvc\View
	 */
	public function setVars(array! params, boolean merge = true) -> <View>
	{
		var viewParams;

		if merge {
			let viewParams = this->_viewParams;
			if typeof viewParams == "array" {
				let this->_viewParams = array_merge(viewParams, params);
			} else {
				let this->_viewParams = params;
			}
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
	 *
	 * @param string key
	 * @param mixed value
	 * @return Phalcon\Mvc\View
	 */
	public function setVar(string! key, value) -> <View>
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
		var params, value;
		let params = this->_viewParams;
		if fetch value, params[key] {
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
	 * Gets the name of the controller rendered
	 *
	 * @return string
	 */
	public function getControllerName()
	{
		return this->_controllerName;
	}

	/**
	 * Gets the name of the action rendered
	 *
	 * @return string
	 */
	public function getActionName()
	{
		return this->_actionName;
	}

	/**
	 * Gets extra parameters of the action rendered
	 *
	 * @return array
	 */
	public function getParams()
	{
		return this->_params;
	}

	/**
	 * Starts rendering process enabling the output buffering
	 */
	public function start() -> <View>
	{
		ob_start();
		let this->_content = null;
		return this;
	}

	/**
	 * Loads registered template engines, if none is registered it will use Phalcon\Mvc\View\Engine\Php
	 */
	protected function _loadTemplateEngines() -> array
	{
		var engines, dependencyInjector, registeredEngines, arguments,
			engineService, extension;

		let engines = this->_engines;

		/**
		 * If the engines aren't initialized 'engines' is false
		 */
		if engines === false {

			let dependencyInjector = <DiInterface> this->_dependencyInjector;

			let engines = [];
			let registeredEngines = this->_registeredEngines;
			if typeof registeredEngines != "array" {

				/**
				 * We use Phalcon\Mvc\View\Engine\Php as default
				 */
				let engines[".phtml"] = new PhpEngine(this, dependencyInjector);
			} else {

				if typeof dependencyInjector != "object" {
					throw new Exception("A dependency injector container is required to obtain the application services");
				}

				let arguments = [this, dependencyInjector];
				for extension, engineService in registeredEngines {

					if typeof engineService == "object" {

						/**
						 * Engine can be a closure
						 */
						if engineService instanceof \Closure {
							let engines[extension] = call_user_func_array(engineService, arguments);
						} else {
							let engines[extension] = engineService;
						}

					} else {

						/**
						 * Engine can be a string representing a service in the DI
						 */
						if typeof engineService != "string" {
							throw new Exception("Invalid template engine registration for extension: " . extension);
						}

						let engines[extension] = dependencyInjector->getShared(engineService, arguments);
					}
				}
			}

			let this->_engines = engines;
		}

		return engines;
	}

	/**
	 * Checks whether view exists on registered extensions and render it
	 *
	 * @param array engines
	 * @param string viewPath
	 * @param boolean silence
	 * @param boolean mustClean
	 * @param Phalcon\Cache\BackendInterface $cache
	 */
	protected function _engineRender(engines, string viewPath, boolean silence, boolean mustClean, <BackendInterface> cache = null)
	{
		boolean notExists;
		int renderLevel, cacheLevel;
		var key, lifetime, viewsDir, basePath, viewsDirPath,
			viewOptions, cacheOptions, cachedView, viewParams, eventsManager,
			extension, engine, viewEnginePath;

		let notExists = true,
			viewsDir = this->_viewsDir,
			basePath = this->_basePath,
			viewsDirPath = basePath . viewsDir . viewPath;

		if typeof cache == "object" {
			let renderLevel = (int) this->_renderLevel,
				cacheLevel = (int) this->_cacheLevel;

			if renderLevel >= cacheLevel {

				/**
				 * Check if the cache is started, the first time a cache is started we start the
				 * cache
				 */
				if cache->isStarted() == false {

					let key = null, lifetime = null;

					let viewOptions = this->_options;

					/**
					 * Check if the user has defined a different options to the default
					 */
					if typeof viewOptions == "array" {
						if fetch cacheOptions, viewOptions["cache"] {
							if typeof cacheOptions == "array" {
								fetch key, cacheOptions["key"];
								fetch lifetime, cacheOptions["lifetime"];
							}
						}
					}

					/**
					 * If a cache key is not set we create one using a md5
					 */
					if key === null {
						let key = md5(viewPath);
					}

					/**
					 * We start the cache using the key set
					 */
					let cachedView = cache->start(key, lifetime);
					if cachedView !== null {
						let this->_content = cachedView;
						return null;
					}
				}

				/**
				 * This method only returns true if the cache has not expired
				 */
				if !cache->isFresh() {
					return null;
				}
			}
		}

		let viewParams = this->_viewParams,
			eventsManager = <ManagerInterface> this->_eventsManager;

		/**
		 * Views are rendered in each engine
		 */
		for extension, engine in engines {

			let viewEnginePath = viewsDirPath . extension;
			if file_exists(viewEnginePath) {

				/**
				 * Call beforeRenderView if there is a events manager available
				 */
				if typeof eventsManager == "object" {
					let this->_activeRenderPath = viewEnginePath;
					if eventsManager->fire("view:beforeRenderView", this, viewEnginePath) === false {
						continue;
					}
				}

				engine->render(viewEnginePath, viewParams, mustClean);

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

		if notExists === true {

			/**
			 * Notify about not found views
			 */
			if typeof eventsManager == "object" {
				let this->_activeRenderPath = viewEnginePath;
				eventsManager->fire("view:notFoundView", this, viewEnginePath);
			}

			if !silence {
				throw new Exception("View '" . viewsDirPath . "' was not found in the views directory");
			}
		}
	}

	/**
	 * Register templating engines
	 *
	 *<code>
	 *$this->view->registerEngines(array(
	 *  ".phtml" => "Phalcon\Mvc\View\Engine\Php",
	 *  ".volt"  => "Phalcon\Mvc\View\Engine\Volt",
	 *  ".mhtml" => "MyCustomEngine"
	 *));
	 *</code>
	 */
	public function registerEngines(array! engines) -> <View>
	{
		let this->_registeredEngines = engines;
		return this;
	}

	/**
	 * Checks whether view exists
	 */
	public function exists(string! view) -> boolean
	{
		var basePath, viewsDir, engines, extension;
		boolean exists;

		let basePath = this->_basePath,
			viewsDir = this->_viewsDir,
			engines = this->_registeredEngines;

		if typeof engines != "array" {
			let engines = [],
				engines[".phtml"] = "Phalcon\\Mvc\\View\\Engine\\Php",
				this->_registeredEngines = engines;
		}

		let exists = false;
		for extension, _ in engines {
			let exists = (boolean) file_exists(basePath . viewsDir . view . extension);
			if exists {
				break;
			}
		}

		return exists;
	}

	/**
	 * Executes render process from dispatching data
	 *
	 *<code>
	 * //Shows recent posts view (app/views/posts/recent.phtml)
	 * $view->start()->render('posts', 'recent')->finish();
	 *</code>
	 *
	 * @param string controllerName
	 * @param string actionName
	 * @param array params
	 */
	public function render(string! controllerName, string! actionName, params = null) -> <View>|boolean
	{
		boolean silence, mustClean;
		int renderLevel;
		var layoutsDir, layout, pickView, layoutName,
			engines, renderView, pickViewAction, eventsManager,
			disabledLevels, templatesBefore, templatesAfter,
			templateBefore, templateAfter, cache;

		let this->_currentRenderLevel = 0;

		/**
		 * If the view is disabled we simply update the buffer from any output produced in the controller
		 */
		if this->_disabled != false {
			let this->_content = ob_get_contents();
			return false;
		}

		let this->_controllerName = controllerName,
			this->_actionName = actionName,
			this->_params = params;

		/**
		 * Check if there is a layouts directory set
		 */
		let layoutsDir = this->_layoutsDir;
		if !layoutsDir {
			let layoutsDir = "layouts/";
		}

		/**
		 * Check if the user has defined a custom layout
		 */
		let layout = this->_layout;
		if layout {
			let layoutName = layout;
		} else {
			let layoutName = controllerName;
		}

		/**
		 * Load the template engines
		 */
		let engines = this->_loadTemplateEngines();

		/**
		 * Check if the user has picked a view diferent than the automatic
		 */
		let pickView = this->_pickView;

		if pickView === null {
			let renderView = controllerName . "/" . actionName;
		} else {

			/**
			 * The 'picked' view is an array, where the first element is controller and the second the action
			 */
			let renderView = pickView[0];
			if fetch pickViewAction, pickView[1] {
				let layoutName = pickViewAction;
			}
		}

		/**
		 * Start the cache if there is a cache level enabled
		 */
		if this->_cacheLevel {
			let cache = this->getCache();
		} else {
			let cache = null;
		}

		let eventsManager = <ManagerInterface> this->_eventsManager;

		/**
		 * Create a virtual symbol table
		 */
		create_symbol_table();

		/**
		 * Call beforeRender if there is an events manager
		 */
		if typeof eventsManager == "object" {
			if eventsManager->fire("view:beforeRender", this) === false {
				return false;
			}
		}

		/**
		 * Get the current content in the buffer maybe some output from the controller?
		 */
		let this->_content = ob_get_contents();

		let mustClean = true,
			silence = true;

		/**
		 * Disabled levels allow to avoid an specific level of rendering
		 */
		let disabledLevels = this->_disabledLevels;

		/**
		 * Render level will tell use when to stop
		 */
		let renderLevel = (int) this->_renderLevel;
		if renderLevel {

			/**
			 * Inserts view related to action
			 */
			if renderLevel >= self::LEVEL_ACTION_VIEW {
				if !isset disabledLevels[self::LEVEL_ACTION_VIEW] {
					let this->_currentRenderLevel = self::LEVEL_ACTION_VIEW;
					this->_engineRender(engines, renderView, silence, mustClean, cache);
				}
			}

			/**
			 * Inserts templates before layout
			 */
			if renderLevel >= self::LEVEL_BEFORE_TEMPLATE  {
				if !isset disabledLevels[self::LEVEL_BEFORE_TEMPLATE] {
					let this->_currentRenderLevel = self::LEVEL_BEFORE_TEMPLATE,
						templatesBefore = this->_templatesBefore;

					/**
					 * Templates before must be an array
					 */
					if typeof templatesBefore == "array" {
						let silence = false;
						for templateBefore in templatesBefore {
							this->_engineRender(engines, layoutsDir . templateBefore, silence, mustClean, cache);
						}
						let silence = true;
					}
				}
			}

			/**
			 * Inserts controller layout
			 */
			if renderLevel >= self::LEVEL_LAYOUT {
				if !isset disabledLevels[self::LEVEL_LAYOUT] {
					let this->_currentRenderLevel = self::LEVEL_LAYOUT;
					this->_engineRender(engines, layoutsDir . layoutName, silence, mustClean, cache);
				}
			}

			/**
			 * Inserts templates after layout
			 */
			if renderLevel >= self::LEVEL_AFTER_TEMPLATE {
				if !isset disabledLevels[self::LEVEL_AFTER_TEMPLATE] {
					let this->_currentRenderLevel = self::LEVEL_AFTER_TEMPLATE;

					/**
					 * Templates after must be an array
					 */
					let templatesAfter = this->_templatesAfter;
					if typeof templatesAfter == "array" {
						let silence = false;
						for templateAfter in templatesAfter {
							this->_engineRender(engines, layoutsDir . templateAfter, silence, mustClean, cache);
						}
						let silence = true;
					}
				}
			}

			/**
			 * Inserts main view
			 */
			if renderLevel >= self::LEVEL_MAIN_LAYOUT {
				if !isset disabledLevels[self::LEVEL_MAIN_LAYOUT] {
					let this->_currentRenderLevel = self::LEVEL_MAIN_LAYOUT;
					this->_engineRender(engines, this->_mainView, silence, mustClean, cache);
				}
			}

			let this->_currentRenderLevel = 0;

			/**
			 * Store the data in the cache
			 */
			if typeof cache == "object" {
				if cache->isStarted() == true {
					if cache->isFresh() == true {
						cache->save();
					} else {
						cache->stop();
					}
				} else {
					cache->stop();
				}
			}
		}

		/**
		 * Call afterRender event
		 */
		if typeof eventsManager == "object" {
			eventsManager->fire("view:afterRender", this);
		}

		return this;
	}

	/**
	 * Choose a different view to render instead of last-controller/last-action
	 *
	 * <code>
	 * class ProductsController extends \Phalcon\Mvc\Controller
	 * {
	 *
	 *    public function saveAction()
	 *    {
	 *
	 *         //Do some save stuff...
	 *
	 *         //Then show the list view
	 *         $this->view->pick("products/list");
	 *    }
	 * }
	 * </code>
	 *
	 * @param string|array renderView
	 * @return Phalcon\Mvc\View
	 */
	public function pick(var renderView) -> <View>
	{
		var pickView, layout, parts;

		if typeof renderView == "array" {
			let pickView = renderView;
		} else {

			let layout = null;
			if memstr(renderView, "/") {
				let parts = explode("/", renderView), layout = parts[0];
			}

			let pickView = [renderView];
			if layout !== null {
				let pickView[] = layout;
			}
		}

		let this->_pickView = pickView;
		return this;
	}

	/**
	 * Renders a partial view
	 *
	 * <code>
	 * 	//Retrieve the contents of a partial
	 * 	echo $this->getPartial('shared/footer');
	 * </code>
	 *
	 * <code>
	 * 	//Retrieve the contents of a partial with arguments
	 * 	echo $this->getPartial('shared/footer', array('content' => $html));
	 * </code>
	 *
	 * @param string partialPath
	 * @param array params
	 * @return string
	 */
	public function getPartial(string! partialPath, params = null) -> string
	{
		// not liking the ob_* functions here, but it will greatly reduce the
		// amount of double code.
		ob_start();
		this->partial(partialPath, params);
		return ob_get_clean();
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
	 * @param array params
	 */
	public function partial(string! partialPath, params = null)
	{
		var viewParams;

		/**
		 * If the developer pass an array of variables we create a new virtual symbol table
		 */
		if typeof params == "array" {

			/**
			 * Merge or assign the new params as parameters
			 */
			let viewParams = this->_viewParams;
			if typeof viewParams == "array" {
				let this->_viewParams = array_merge(viewParams, params);
			} else {
				let this->_viewParams = params;
			}

			/**
			 * Create a virtual symbol table
			 */
			create_symbol_table();
		}

		/**
		 * Partials are looked up under the partials directory
		 * We need to check if the engines are loaded first, this method could be called outside of 'render'
		 * Call engine render, this checks in every registered engine for the partial
		 */
		this->_engineRender(this->_loadTemplateEngines(), this->_partialsDir . partialPath, false, false);

		/**
		 * Now we need to restore the original view parameters
		 */
		if typeof params == "array" {
			/**
			 * Restore the original view params
			 */
			let this->_viewParams = viewParams;
		}
	}

	/**
	 * Perform the automatic rendering returning the output as a string
	 *
	 * <code>
	 * 	$template = $this->view->getRender('products', 'show', array('products' => $products));
	 * </code>
	 *
	 * @param string controllerName
	 * @param string actionName
	 * @param array params
	 * @param mixed configCallback
	 * @return string
	 */
	public function getRender(string! controllerName, string! actionName, params = null, configCallback = null) -> string
	{
		var view;

		/**
		 * We must to clone the current view to keep the old state
		 */
		let view = clone this;

		/**
		 * The component must be reset to its defaults
		 */
		view->reset();

		/**
		 * Set the render variables
		 */
		if typeof params == "array" {
			view->setVars(params);
		}

		/**
		 * Perform extra configurations over the cloned object
		 */
		if typeof configCallback == "object" {
			call_user_func_array(configCallback, [view]);
		}

		/**
		 * Start the output buffering
		 */
		view->start();

		/**
		 * Perform the render passing only the controller and action
		 */
		view->render(controllerName, actionName);

		/**
		 * Stop the output buffering
		 */
		ob_end_clean();

		/**
		 * Get the processed content
		 */
		return view->getContent();
	}

	/**
	 * Finishes the render process by stopping the output buffering
	 */
	public function finish() -> <View>
	{
		ob_end_clean();
		return this;
	}

	/**
	 * Create a Phalcon\Cache based on the internal cache options
	 */
	protected function _createCache() -> <BackendInterface>
	{
		var dependencyInjector, cacheService, viewCache,
			viewOptions, cacheOptions;

		let dependencyInjector = <DiInterface> this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			throw new Exception("A dependency injector container is required to obtain the view cache services");
		}

		let cacheService = "viewCache";

		let viewOptions = this->_options;
		if typeof viewOptions == "array" {
			if fetch cacheOptions, viewOptions["cache"] {
				if isset cacheOptions["service"] {
					let cacheService = cacheOptions["service"];
				}
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
	 * Check if the component is currently caching the output content
	 */
	public function isCaching() -> boolean
	{
		return this->_cacheLevel > 0;
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
				let cache = this->_createCache(),
					this->_cache = cache;
			}
		} else {
			let cache = this->_createCache(),
				this->_cache = cache;
		}
		return cache;
	}

	/**
	 * Cache the actual view render to certain level
	 *
	 *<code>
	 *  $this->view->cache(array('key' => 'my-key', 'lifetime' => 86400));
	 *</code>
	 *
	 * @param boolean|array options
	 * @return Phalcon\Mvc\View
	 */
	public function cache(var options = true) -> <View>
	{
		var viewOptions, cacheOptions, key, value, cacheLevel;

		if typeof options == "array" {

			let viewOptions = this->_options;
			if typeof viewOptions != "array" {
				let viewOptions = [];
			}

			/**
			 * Get the default cache options
			 */
			if !fetch cacheOptions, viewOptions["cache"] {
				let cacheOptions = [];
			}

			for key, value in options {
				let cacheOptions[key] = value;
			}

			/**
			 * Check if the user has defined a default cache level or use self::LEVEL_MAIN_LAYOUT as default
			 */
			if fetch cacheLevel, cacheOptions["level"] {
				let this->_cacheLevel = cacheLevel;
			} else {
				let this->_cacheLevel = self::LEVEL_MAIN_LAYOUT;
			}

			let viewOptions["cache"] = cacheOptions;
			let this->_options = viewOptions;
		} else {

			/**
			 * If 'options' isn't an array we enable the cache with the default options
			 */
			if options {
				let this->_cacheLevel = self::LEVEL_MAIN_LAYOUT;
			} else {
				let this->_cacheLevel = self::LEVEL_NO_RENDER;
			}
		}

		return this;
	}

	/**
	 * Externally sets the view content
	 *
	 *<code>
	 *	$this->view->setContent("<h1>hello</h1>");
	 *</code>
	 */
	public function setContent(string content) -> <View>
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
	 */
	public function getActiveRenderPath() -> string
	{
		return this->_activeRenderPath;
	}

	/**
	 * Disables the auto-rendering process
	 */
	public function disable() -> <View>
	{
		let this->_disabled = true;
		return this;
	}

	/**
	 * Enables the auto-rendering process
	 */
	public function enable() -> <View>
	{
		let this->_disabled = false;
		return this;
	}

	/**
	 * Resets the view component to its factory default values
	 */
	public function reset() -> <View>
	{
		let this->_disabled = false,
			this->_engines = false,
			this->_cache = null,
			this->_renderLevel = self::LEVEL_MAIN_LAYOUT,
			this->_cacheLevel = self::LEVEL_NO_RENDER,
			this->_content = null,
			this->_templatesBefore = null,
			this->_templatesAfter = null;
		return this;
	}

	/**
	 * Magic method to pass variables to the views
	 *
	 *<code>
	 *	$this->view->products = $products;
	 *</code>
	 *
	 * @param string key
	 * @param mixed value
	 */
	public function __set(string! key, value)
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

	/**
	 * Whether automatic rendering is enabled
	 */
	public function isDisabled() -> boolean
	{
		return this->_disabled;
	}

	/**
	 * Magic method to retrieve if a variable is set in the view
	 *
	 *<code>
	 *  echo isset($this->view->products);
	 *</code>
	 *
	 * @param string key
	 * @return boolean
	 */
	public function __isset(string! key) -> boolean
	{
		return isset(this->_viewParams[key]);
	}
}
