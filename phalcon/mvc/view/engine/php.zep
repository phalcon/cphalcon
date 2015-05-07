
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

namespace Phalcon\Mvc\View\Engine;

use Phalcon\Mvc\View\Engine;
use Phalcon\Mvc\View\EngineInterface;

/**
 * Phalcon\Mvc\View\Engine\Php
 *
 * Adapter to use PHP itself as templating engine
 */
class Php extends Engine implements EngineInterface
{

	/**
	 * Renders a view using the template engine
	 */
	public function render(string! path, var params, boolean mustClean = false)
	{
		var key, value;

		if mustClean === true {
			ob_clean();
		}

		/**
		 * Create the variables in local symbol table
		 */
		if typeof params == "array" {
			for key, value in params {
				let {key} = value;
			}
		}

		/**
		 * Require the file
		 */
		require path;

		if mustClean === true {
			this->_view->setContent(ob_get_contents());
		}
	}
}
