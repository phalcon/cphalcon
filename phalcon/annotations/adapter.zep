
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
	 *
	 * @param Phalcon\Annotations\ReaderInterface reader
	 */
	public function setReader(<Phalcon\Annotations\ReaderInterface> reader)
	{
		if typeof reader != "object" {
			throw new Phalcon\Annotations\Exception("Invalid annotations reader");
		}
		let this->_reader = reader;
	}

	/**
	 * Returns the annotation reader
	 *
	 * @return Phalcon\Annotations\ReaderInterface
	 */
	public function getReader() -> <Phalcon\Annotations\ReaderInterface>
	{
		var reader;
		let reader = this->_reader;
		if typeof reader != "object" {
			let reader = new Phalcon\Annotations\Reader(),
				this->_reader = reader;
		}
		return reader;
	}

	/**
	 * Parses or retrieves all the annotations found in a class
	 *
	 * @param string|object className
	 * @return Phalcon\Annotations\Reflection
	 */
	public function get(var className) -> <Phalcon\Annotations\Reflection>
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
		if typeof classAnnotations == "null" {

			/**
			 * Get the annotations reader
			 */
			let reader = this->getReader(),
				parsedAnnotations = reader->parse(realClassName);

			/**
			 * If the reader returns a
			 */
			if typeof parsedAnnotations == "array" {
				let classAnnotations = new Phalcon\Annotations\Reflection(parsedAnnotations),
					this->_annotations[realClassName] = classAnnotations;
					this->{"write"}(realClassName, classAnnotations);
			}
		}

		return classAnnotations;
	}

	/**
	 * Returns the annotations found in all the class' methods
	 *
	 * @param string className
	 * @return array
	 */
	public function getMethods(string className)
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
	 *
	 * @param string className
	 * @param string methodName
	 * @return Phalcon\Annotations\Collection
	 */
	public function getMethod(string className, string methodName) -> <Phalcon\Annotations\Collection>
	{
		var classAnnotations, methods, name, method;

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
				for name, method in methods {
					if name == methodName {
						return method;
					}
				}
			}
		}

		/**
		 * Returns a collection anyways
		 */
		return new Phalcon\Annotations\Collection();
	}

	/**
	 * Returns the annotations found in all the class' methods
	 *
	 * @param string className
	 * @return array
	 */
	public function getProperties(string className)
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
	 *
	 * @param string className
	 * @param string propertyName
	 * @return Phalcon\Annotations\Collection
	 */
	public function getProperty(string className, string propertyName) -> <Phalcon\Annotations\Collection>
	{
		var classAnnotations, properties, name, property;

		/**
		 * Get the full annotations from the class
		 */
		let classAnnotations = this->get(className);

		/**
		 * A valid annotations reflection is an object
		 */
		if typeof classAnnotations == "object" {
			let properties = classAnnotations->getPropertyAnnotations();
			if typeof properties == "array" {
				for name, property in properties {
					if name == propertyName {
						return property;
					}
				}
			}
		}

		/**
		 * Returns a collection anyways
		 */
		return new Phalcon\Annotations\Collection();
	}

}
