
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

namespace Phalcon\Annotations;

use Phalcon\Annotations\ReaderInterface;
use Phalcon\Annotations\Exception;
use Phalcon\Annotations\Collection;
use Phalcon\Annotations\Reflection;

/**
 * Phalcon\Annotations\Adapter
 *
 * This is the base class for Phalcon\Annotations adapters
 */
abstract class Adapter
{

	protected _reader;

	protected _annotations;

	/**
	 * Sets the annotations parser
	 */
	public function setReader(<ReaderInterface> reader)
	{
		let this->_reader = reader;
	}

	/**
	 * Returns the annotation reader
	 */
	public function getReader() -> <ReaderInterface>
	{
		if typeof this->_reader != "object" {
			let this->_reader = new \Phalcon\Annotations\Reader();
		}
		return this->_reader;
	}

	/**
	 * Parses or retrieves all the annotations found in a class
	 *
	 * @param string|object className
	 */
	public function get(var className) -> <Reflection>
	{
		var annotations, classAnnotations, parsedAnnotations, realClassName, reader;

		/**
		 * Get the class name if it's an object
		 */
		if typeof className == "object" {
			let realClassName = get_class(className);
		}  else {
			let realClassName = className;
		}

		let annotations = this->_annotations;
		if typeof annotations == "array" {
			if isset annotations[realClassName] {
				return annotations[realClassName];
			}
		}

		/**
		 * Try to read the annotations from the adapter
		 */
		let classAnnotations = this->{"read"}(realClassName);
		if classAnnotations === null || classAnnotations === false {

			/**
			 * Get the annotations reader
			 */
			let reader = this->getReader(),
				parsedAnnotations = reader->parse(realClassName);

			/**
			 * If the reader returns a
			 */
			if typeof parsedAnnotations == "array" {
				let classAnnotations = new Reflection(parsedAnnotations),
					this->_annotations[realClassName] = classAnnotations;
					this->{"write"}(realClassName, classAnnotations);
			}
		}

		return classAnnotations;
	}

	/**
	 * Returns the annotations found in all the class' methods
	 */
	public function getMethods(string className) -> array
	{
		var classAnnotations;

		/**
		 * Get the full annotations from the class
		 */
		let classAnnotations = this->get(className);

		/**
		 * A valid annotations reflection is an object
		 */
		if typeof classAnnotations == "object" {
			return classAnnotations->getMethodsAnnotations();
		}

		return [];
	}

	/**
	 * Returns the annotations found in a specific method
	 */
	public function getMethod(string className, string methodName) -> <Collection>
	{
		var classAnnotations, methods, method;

		/**
		 * Get the full annotations from the class
		 */
		let classAnnotations = this->get(className);

		/**
		 * A valid annotations reflection is an object
		 */
		if typeof classAnnotations == "object" {
			let methods = classAnnotations->getMethodsAnnotations();
			if typeof methods == "array" {
				if fetch method, methods[methodName] {
					return method;
				}
			}
		}

		/**
		 * Returns a collection anyways
		 */
		return new Collection();
	}

	/**
	 * Returns the annotations found in all the class' methods
	 */
	public function getProperties(string className) -> array
	{
		var classAnnotations;

		/**
		 * Get the full annotations from the class
		 */
		let classAnnotations = this->get(className);

		/**
		 * A valid annotations reflection is an object
		 */
		if typeof classAnnotations == "object" {
			return classAnnotations->getPropertiesAnnotations();
		}

		return [];
	}

	/**
	 * Returns the annotations found in a specific property
	 */
	public function getProperty(string className, string propertyName) -> <Collection>
	{
		var classAnnotations, properties, property;

		/**
		 * Get the full annotations from the class
		 */
		let classAnnotations = this->get(className);

		/**
		 * A valid annotations reflection is an object
		 */
		if typeof classAnnotations == "object" {
			let properties = classAnnotations->getPropertiesAnnotations();
			if typeof properties == "array" {
				if fetch property, properties[propertyName] {
					return property;
				}
			}
		}

		/**
		 * Returns a collection anyways
		 */
		return new Collection();
	}
}
