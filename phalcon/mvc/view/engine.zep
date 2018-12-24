
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
use Phalcon\Di\Injectable;
use Phalcon\Mvc\ViewBaseInterface;

/**
 * Phalcon\Mvc\View\Engine
 *
 * All the template engine adapters must inherit this class. This provides
 * basic interfacing between the engine and the Phalcon\Mvc\View component.
 */
abstract class Engine extends Injectable implements EngineInterface
{

	protected _view;

	/**
	 * Phalcon\Mvc\View\Engine constructor
	 */
	public function __construct(<ViewBaseInterface> view, <DiInterface> dependencyInjector = null)
	{
		let this->_view = view;
		let this->_dependencyInjector = dependencyInjector;
	}

	/**
	 * Returns cached output on another view stage
	 */
	public function getContent() -> string
	{
		return this->_view->getContent();
	}

	/**
	 * Renders a partial inside another view
	 *
	 * @param array params
	 */
	public function partial(string! partialPath, var params = null) -> string
	{
		return this->_view->partial(partialPath, params);
	}

	/**
	 * Returns the view component related to the adapter
	 */
	public function getView() -> <ViewBaseInterface>
	{
		return this->_view;
	}
}
