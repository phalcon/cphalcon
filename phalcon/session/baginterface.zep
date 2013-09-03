
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

namespace Phalcon\Session;

/**
 * Phalcon\Session\BagInterface
 *
 * Interface for Phalcon\Session\Bag
 */
interface BagInterface
{

	/**
	 * Initializes the session bag. This method must not be called directly, the class calls it when its internal data is accesed
	 */
	public function initialize();

	/**
	 * Destroyes the session bag
	 */
	public function destroy();

	/**
	 * Setter of values
	 *
	 * @param string property
	 * @param string value
	 */
	public function set(property, value);

	/**
	 * Getter of values
	 *
	 * @param string property
	 * @param mixed defaultValue
	 * @return mixed
	 */
	public function get(property, defaultValue=null);

	/**
	 * Isset property
	 *
	 * @param string property
	 * @return boolean
	 */
	public function has(property);

	/**
	 * Setter of values
	 *
	 * @param string property
	 * @param string value
	 */
	public function __set(property, value);

	/**
	 * Getter of values
	 *
	 * @param string property
	 * @return mixed
	 */
	public function __get(property);

	/**
	 * Isset property
	 *
	 * @param string property
	 * @return boolean
	 */
	public function __isset(property);

}