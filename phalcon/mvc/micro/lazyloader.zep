
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

namespace Phalcon\Mvc\Micro;

/**
 * Phalcon\Mvc\Micro\LazyLoader
 *
 * Lazy-Load of handlers for Mvc\Micro using auto-loading
 */
class LazyLoader
{
	protected _handler;

	protected _definition;

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
 		var handler, definition;

		let handler = this->_handler;

		if typeof handler != "object" {
			let definition = this->_definition;
			let handler = new {definition}();
			let this->_handler = handler;
		}

		/**
		 * Call the handler
		 */
		return call_user_func_array([handler, method], arguments);
	}
}
