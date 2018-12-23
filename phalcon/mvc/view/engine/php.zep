
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\View\Engine;

use Phalcon\Mvc\View\Engine;

/**
 * Phalcon\Mvc\View\Engine\Php
 *
 * Adapter to use PHP itself as templating engine
 */
class Php extends Engine
{

	/**
	 * Renders a view using the template engine
	 */
	public function render(string! path, var params, bool mustClean = false)
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
