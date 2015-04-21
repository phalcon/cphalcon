
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

namespace Phalcon\Di;

use Phalcon\DiInterface;

/**
 * Phalcon\Di\InjectionAwareInterface
 *
 * This interface must be implemented in those classes that uses internally the Phalcon\Di that creates them
 */
interface InjectionAwareInterface
{

	/**
	 * Sets the dependency injector
	 */
	public function setDI(<DiInterface> dependencyInjector);

	/**
	 * Returns the internal dependency injector
	 */
	public function getDI() -> <DiInterface>;
}
