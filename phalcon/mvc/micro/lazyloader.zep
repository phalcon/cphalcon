
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Micro;

use Phalcon\Mvc\Model\BinderInterface;

/**
 * Phalcon\Mvc\Micro\LazyLoader
 *
 * Lazy-Load of handlers for Mvc\Micro using auto-loading
 */
class LazyLoader
{
	protected handler;

	protected definition { get };

	/**
	 * Phalcon\Mvc\Micro\LazyLoader constructor
	 */
	public function __construct(string! definition)
	{
		let this->definition = definition;
	}

	/**
	 * Calling __call method
	 *
	 * @param  string method
	 * @param  array arguments
	 * @return mixed
	 */
	public function callMethod(string! method, arguments, <BinderInterface> modelBinder = null)
	{
 		var handler, definition, bindCacheKey;

		let handler    = this->handler,
			definition = this->definition;

		if typeof handler != "object" {
			let handler = new {definition}();
			let this->handler = handler;
		}

		if modelBinder != null {
			let bindCacheKey = "_PHMB_" . definition . "_" . method;
			let arguments = modelBinder->bindToHandler(handler, arguments, bindCacheKey, method);
		}

		/**
		 * Call the handler
		 */
		return call_user_func_array([handler, method], arguments);
	}
}
