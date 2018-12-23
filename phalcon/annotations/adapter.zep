
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Annotations;

use Phalcon\Annotations\AdapterInterface;
use Phalcon\Annotations\Reader;
use Phalcon\Annotations\Exception;
use Phalcon\Annotations\Collection;
use Phalcon\Annotations\Reflection;
use Phalcon\Annotations\ReaderInterface;

/**
 * Phalcon\Annotations\Adapter
 *
 * This is the base class for Phalcon\Annotations adapters
 */
abstract class Adapter implements AdapterInterface
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
			let this->_reader = new Reader();
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
		var classAnnotations, methods, method, methodKey;

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
				for methodKey, method in methods {
					if !strcasecmp(methodKey, methodName) {
						return method;
					}
				}
			}
		}

		/**
		 * Returns a collection anyway
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
