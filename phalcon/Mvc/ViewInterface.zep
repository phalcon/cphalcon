
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
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
     * Resets any template before layouts
     */
    public function cleanTemplateAfter();

    /**
     * Resets any template before layouts
     */
    public function cleanTemplateBefore();

    /**
     * Disables the auto-rendering process
     */
    public function disable();

    /**
     * Enables the auto-rendering process
     */
    public function enable();

    /**
     * Finishes the render process by stopping the output buffering
     */
    public function finish();

    /**
     * Gets the name of the action rendered
     */
    public function getActionName() -> string;

    /**
     * Returns the path of the view that is currently rendered
     */
    public function getActiveRenderPath() -> string | array;

    /**
     * Gets base path
     */
    public function getBasePath() -> string;

    /**
     * Gets the name of the controller rendered
     */
    public function getControllerName() -> string;

    /**
     * Returns the name of the main view
     */
    public function getLayout() -> string;

    /**
     * Gets the current layouts sub-directory
     */
    public function getLayoutsDir() -> string;

    /**
     * Returns the name of the main view
     */
    public function getMainView() -> string;

    /**
     * Gets the current partials sub-directory
     */
    public function getPartialsDir() -> string;

    /**
     * Whether the automatic rendering is disabled
     */
    public function isDisabled() -> bool;

    /**
     * Choose a view different to render than last-controller/last-action
     */
    public function pick(string! renderView);

    /**
     * Register templating engines
     */
    public function registerEngines(array! engines);

    /**
     * Executes render process from dispatching data
     */
    public function render(string! controllerName, string! actionName, array params = []) -> <ViewInterface> | bool;

    /**
     * Resets the view component to its factory default values
     */
    public function reset();

    /**
     * Sets base path. Depending of your platform, always add a trailing slash
     * or backslash
     */
    public function setBasePath(string! basePath);

    /**
     * Change the layout to be used instead of using the name of the latest
     * controller name
     */
    public function setLayout(string! layout);

    /**
     * Sets the layouts sub-directory. Must be a directory under the views
     * directory. Depending of your platform, always add a trailing slash or
     * backslash
     */
    public function setLayoutsDir(string! layoutsDir);

    /**
     * Sets default view name. Must be a file without extension in the views
     * directory
     */
    public function setMainView(string! viewPath);

    /**
     * Sets a partials sub-directory. Must be a directory under the views
     * directory. Depending of your platform, always add a trailing slash or
     * backslash
     */
    public function setPartialsDir(string! partialsDir);

    /**
     * Sets the render level for the view
     */
    public function setRenderLevel(int level) -> <ViewInterface>;

    /**
     * Appends template after controller layout
     *
     * @param string|array templateAfter
     */
    public function setTemplateAfter(templateAfter);

    /**
     * Appends template before controller layout
     *
     * @param string|array templateBefore
     */
    public function setTemplateBefore(templateBefore);

    /**
     * Starts rendering process enabling the output buffering
     */
    public function start();
}
