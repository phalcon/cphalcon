
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

namespace Phalcon\Mvc\View;

/**
 * Phalcon\Mvc\View\EngineInterface
 *
 * Interface for Phalcon\Mvc\View engine adapters
 */
interface EngineInterface {

	/**
	 * Phalcon\Mvc\View\Engine constructor
	 *
	 * @param Phalcon\Mvc\ViewInterface view
	 * @param Phalcon\DiInterface dependencyInjector
	 */
	public function __construct(view, dependencyInjector=null);

	/**
	 * Returns cached ouput on another view stage
	 *
	 * @return array
	 */
	public function getContent();

	/**
	 * Renders a partial inside another view
	 *
	 * @param string partialPath
	 * @return string
	 */
	public function partial(partialPath);

	/**
	 * Renders a view using the template engine
	 *
	 * @param string path
	 * @param array params
	 * @param boolean mustClean
	 */
	public function render(path, params, mustClean=false);

}