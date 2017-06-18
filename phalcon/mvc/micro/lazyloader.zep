
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
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
	protected _handler;

	protected _modelBinder;

	protected _definition {
		get
	};

	/**
	 * Phalcon\Mvc\Micro\LazyLoader constructor
	 */
	public function __construct(string! definition)
	{
		let this->_definition = definition;
	}

	/**
	 * Initializes the internal handler, calling functions on it
	 *
	 * @param  string method
	 * @param  array arguments
	 * @return mixed
	 */
	public function __call(string! method, arguments)
	{
 		var handler, definition, modelBinder, bindCacheKey;

		let handler = this->_handler;

		let definition = this->_definition;

		if typeof handler != "object" {
			let handler = new {definition}();
			let this->_handler = handler;
		}

		let modelBinder = this->_modelBinder;

		if modelBinder != null {
			let bindCacheKey = "_PHMB_" . definition . "_" . method;
			let arguments = modelBinder->bindToHandler(handler, arguments, bindCacheKey, method);
		}

		/**
		 * Call the handler
		 */
		return call_user_func_array([handler, method], arguments);
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
		let this->_modelBinder = modelBinder;

		return this->__call(method, arguments);
	}
}
