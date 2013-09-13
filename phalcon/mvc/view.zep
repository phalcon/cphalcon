
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

/**
 * Phalcon\Mvc\View
 *
 * Phalcon\Mvc\View is a class for working with the "view" portion of the model-view-controller pattern.
 * That is, it exists to help keep the view script separate from the model and controller scripts.
 * It provides a system of helpers, output filters, and variable escaping.
 *
 * <code>
 * //Setting views directory
 * $view = new Phalcon\Mvc\View();
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
class View extends Phalcon\Di\Injectable implements Phalcon\Mvc\ViewInterface
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

	protected _options;

	protected _basePath = "";

	protected _content = "";

	protected _renderLevel = 5;

	protected _disabledLevels;

	protected _viewParams;

	protected _layout;

	protected _layoutsDir = "";

	protected _partialsDir = "";

	protected _viewsDir;

	protected _templatesBefore;

	protected _templatesAfter;

	protected _engines = false;

	protected _registeredEngines;

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
	public function __construct(options=null)
	{
		if typeof options == "array" {
			let this->_options = options;
		}
	}

	/**
	 * Sets views directory. Depending of your platform, always add a trailing slash or backslash
	 *
	 * @param string viewsDir
	 * @return Phalcon\Mvc\View
	 */
	public function setViewsDir(viewsDir)
	{
		if typeof viewsDir != "string" {
			throw new Phalcon\Mvc\View\Exception("The views directory must be a string");
		}
		let this->_viewsDir = viewsDir;
		return this;
	}

}