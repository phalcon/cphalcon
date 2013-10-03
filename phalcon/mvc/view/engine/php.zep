
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

namespace Phalcon\Mvc\View\Engine;

/**
 * Phalcon\Mvc\View\Engine\Php
 *
 * Adapter to use PHP itself as templating engine
 */
class Php extends Phalcon\Mvc\View\Engine implements Phalcon\Mvc\View\EngineInterface
{

	/**
	 * Renders a view using the template engine
	 *
	 * @param string path
	 * @param array params
	 * @param boolean mustClean
	 */
	public function render(string! path, params, boolean mustClean=false)
	{
		var status, view;

		if mustClean === true {
			ob_clean();
		}

		/**
		 * Create the variables in local symbol table
		 */
		if typeof params == "array" {
			//for key, value in params {
				//let {key} = value;
			//}
		}

		/**
		 * Require the file
		 */
		let status = require path;

		if mustClean === true {
			let view = this->_view;
			view->setContent(ob_get_contents());
		}
	}

}
