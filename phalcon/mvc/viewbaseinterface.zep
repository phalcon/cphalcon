
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc;

use Phalcon\Cache\BackendInterface;

/**
 * Phalcon\Mvc\ViewInterface
 *
 * Interface for Phalcon\Mvc\View and Phalcon\Mvc\View\Simple
 */
interface ViewBaseInterface
{

	/**
	 * Sets views directory. Depending of your platform, always add a trailing slash or backslash
	 */
	public function setViewsDir(string! viewsDir);

	/**
	 * Gets views directory
	 */
	public function getViewsDir() -> string | array;

	/**
	 * Adds parameters to views (alias of setVar)
	 */
	public function setParamToView(string! key, var value);

	/**
	 * Adds parameters to views
	 */
	public function setVar(string! key, var value);

	/**
	 * Returns parameters to views
	 */
	public function getParamsToView() -> array;

	/**
	 * Returns the cache instance used to cache
	 */
	public function getCache() -> <BackendInterface>;

	/**
	 * Cache the actual view render to certain level
	 */
	public function cache(var options = true);

	/**
	 * Externally sets the view content
	 */
	public function setContent(string! content);

	/**
	 * Returns cached output from another view stage
	 */
	public function getContent() -> string;

	/**
	 * Renders a partial view
	 */
	public function partial(string! partialPath, var params = null);
}
