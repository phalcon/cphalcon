
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

/**
 * Phalcon\Mvc\ViewInterface
 *
 * Interface for Phalcon\Mvc\View
 */
interface ViewInterface extends ViewBaseInterface
{
	/**
	 * Sets the layouts sub-directory. Must be a directory under the views directory. Depending of your platform, always add a trailing slash or backslash
	 */
	public function setLayoutsDir(string! layoutsDir);

	/**
	 * Gets the current layouts sub-directory
	 */
	public function getLayoutsDir() -> string;

	/**
	 * Sets a partials sub-directory. Must be a directory under the views directory. Depending of your platform, always add a trailing slash or backslash
	 */
	public function setPartialsDir(string! partialsDir);

	/**
	 * Gets the current partials sub-directory
	 */
	public function getPartialsDir() -> string;

	/**
	 * Sets base path. Depending of your platform, always add a trailing slash or backslash
	 */
	public function setBasePath(string! basePath);

	/**
	 * Sets the render level for the view
	 */
	public function setRenderLevel(string! level);

	/**
	 * Sets default view name. Must be a file without extension in the views directory
	 */
	public function setMainView(string! viewPath);

	/**
	 * Returns the name of the main view
	 */
	public function getMainView() -> string;

	/**
	 * Change the layout to be used instead of using the name of the latest controller name
	 */
	public function setLayout(string! layout);

	/**
	 * Returns the name of the main view
	 */
	public function getLayout() -> string;

	/**
	 * Appends template before controller layout
	 *
	 * @param string|array templateBefore
	 */
	public function setTemplateBefore(templateBefore);

	/**
	 * Resets any template before layouts
	 */
	public function cleanTemplateBefore();

	/**
	 * Appends template after controller layout
	 *
	 * @param string|array templateAfter
	 */
	public function setTemplateAfter(templateAfter);

	/**
	 * Resets any template before layouts
	 */
	public function cleanTemplateAfter();

	/**
	 * Gets the name of the controller rendered
	 */
	public function getControllerName() -> string;

	/**
	 * Gets the name of the action rendered
	 */
	public function getActionName() -> string;

	/**
	 * Gets extra parameters of the action rendered
	 */
	public function getParams() -> array;

	/**
	 * Starts rendering process enabling the output buffering
	 */
	public function start();

	/**
	 * Register templating engines
	 */
	public function registerEngines(array! engines);

	/**
	 * Executes render process from dispatching data
	 *
	 * @param string controllerName
	 * @param string actionName
	 * @param array params
	 */
	public function render(string! controllerName, string! actionName, params = null);

	/**
	 * Choose a view different to render than last-controller/last-action
	 */
	public function pick(string! renderView);

	/**
	 * Renders a partial view
	 */
	public function partial(string! partialPath) -> string;

	/**
	 * Finishes the render process by stopping the output buffering
	 */
	public function finish();

	/**
	 * Returns the path of the view that is currently rendered
	 */
	public function getActiveRenderPath() -> string;

	/**
	 * Disables the auto-rendering process
	 */
	public function disable();

	/**
	 * Enables the auto-rendering process
	 */
	public function enable();

	/**
	 * Resets the view component to its factory default values
	 */
	public function reset();

	/**
	 * Whether the automatic rendering is disabled
	 */
	public function isDisabled() -> boolean;
}
