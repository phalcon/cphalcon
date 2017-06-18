
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

namespace Phalcon\Annotations;

use Phalcon\Annotations\Reflection;
use Phalcon\Annotations\Collection;
use Phalcon\Annotations\ReaderInterface;

/**
 * Phalcon\Annotations\AdapterInterface
 *
 * This interface must be implemented by adapters in Phalcon\Annotations
 */
interface AdapterInterface
{
	/**
	 * Sets the annotations parser
	 */
	public function setReader(<ReaderInterface> reader);

	/**
	 * Returns the annotation reader
	 */
	public function getReader() -> <ReaderInterface>;

	/**
	 * Parses or retrieves all the annotations found in a class
	 *
	 * @param string|object className
     */
	public function get(className) -> <Reflection>;

	/**
	 * Returns the annotations found in all the class' methods
	 */
	public function getMethods(string className) -> array;

	/**
	 * Returns the annotations found in a specific method
	 */
	public function getMethod(string className, string methodName) -> <Collection>;

	/**
	 * Returns the annotations found in all the class' methods
	 */
	public function getProperties(string className) -> array;

	/**
	 * Returns the annotations found in a specific property
	 */
	public function getProperty(string className, string propertyName) -> <Collection>;
}
