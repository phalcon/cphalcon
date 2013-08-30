
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

namespace Phalcon\Annotations;

/**
 * Phalcon\Annotations\AdapterInterface
 *
 * This interface must be implemented for adapters in Phalcon\Annotations
 */
interface AdapterInterface
{

	/**
	 * Sets the annotations parser
	 *
	 * @param Phalcon\Annotations\ReaderInterface reader
	 */
	public function setReader(reader);

	/**
	 * Returns the annotation reader
	 *
	 * @return Phalcon\Annotations\ReaderInterface
	 */
	public function getReader();

	/**
	 * Parses or retrieves all the annotations found in a class
	 *
	 * @param string|object className
	 * @return Phalcon\Annotations\Reflection
	 */
	public function get(className);

	/**
	 * Returns the annotations found in all the class' methods
	 *
	 * @param string className
	 * @return array
	 */
	public function getMethods(className);

	/**
	 * Returns the annotations found in a specific method
	 *
	 * @param string className
	 * @param string methodName
	 * @return Phalcon\Annotations\Collection
	 */
	public function getMethod(className, methodName);

	/**
	 * Returns the annotations found in all the class' methods
	 *
	 * @param string className
	 * @return array
	 */
	public function getProperties(className);

	/**
	 * Returns the annotations found in a specific property
	 *
	 * @param string className
	 * @param string propertyName
	 * @return Phalcon\Annotations\Collection
	 */
	public function getProperty(className, propertyName);

}
