
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

namespace Phalcon\Mvc\View;

/**
 * Phalcon\Mvc\View\EngineInterface
 *
 * Interface for Phalcon\Mvc\View engine adapters
 */
interface EngineInterface
{

	/**
	 * Phalcon\Mvc\View\Engine constructor
	 */
	public function __construct(<\Phalcon\Mvc\ViewInterface> view, <\Phalcon\DiInterface> dependencyInjector = null);

	/**
	 * Returns cached ouput on another view stage
	 */
	public function getContent() -> array;

	/**
	 * Renders a partial inside another view
	 */
	public function partial(string! partialPath) -> string;

	/**
	 * Renders a view using the template engine
	 */
	public function render(string path, array params, boolean mustClean = false);

}
