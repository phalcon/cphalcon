
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\View;

use Phalcon\DiInterface;
use Phalcon\Mvc\ViewBaseInterface;

/**
 * Phalcon\Mvc\View\EngineInterface
 *
 * Interface for Phalcon\Mvc\View engine adapters
 */
interface EngineInterface
{
	/**
	 * Returns cached output on another view stage
	 */
	public function getContent() -> string;

	/**
	 * Renders a partial inside another view
	 */
	public function partial(string! partialPath, var params = null) -> string;

	/**
	 * Renders a view using the template engine
	 */
	public function render(string path, var params, bool mustClean = false);
}
