
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc;

use Phalcon\Cache\Adapter\AdapterInterface;

/**
 * Phalcon\Mvc\ViewInterface
 *
 * Interface for Phalcon\Mvc\View and Phalcon\Mvc\View\Simple
 */
interface ViewBaseInterface
{
    /**
     * Cache the actual view render to certain level
     */
    public function cache(var options = true);

    /**
     * Returns the cache instance used to cache
     */
    public function getCache() -> <AdapterInterface>;

    /**
     * Returns cached output from another view stage
     */
    public function getContent() -> string;

    /**
     * Returns parameters to views
     */
    public function getParamsToView() -> array;

    /**
     * Gets views directory
     */
    public function getViewsDir() -> string | array;

    /**
     * Renders a partial view
     */
    public function partial(string! partialPath, var params = null);

    /**
     * Externally sets the view content
     */
    public function setContent(string! content);

    /**
     * Adds parameters to views (alias of setVar)
     */
    public function setParamToView(string! key, var value);

    /**
     * Adds parameters to views
     */
    public function setVar(string! key, var value);

    /**
     * Sets views directory. Depending of your platform, always add a trailing
     * slash or backslash
     */
    public function setViewsDir(string! viewsDir);

}
