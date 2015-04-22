
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

use Phalcon\Annotations\Collection;

/**
 * Phalcon\Annotations\Reflection
 *
 * Allows to manipulate the annotations reflection in an OO manner
 *
 *<code>
 * //Parse the annotations in a class
 * $reader = new \Phalcon\Annotations\Reader();
 * $parsing = reader->parse('MyComponent');
 *
 * //Create the reflection
 * $reflection = new \Phalcon\Annotations\Reflection($parsing);
 *
 * //Get the annotations in the class docblock
 * $classAnnotations = reflection->getClassAnnotations();
 *</code>
 */
class Reflection
{

	protected _reflectionData;

	protected _classAnnotations;

	protected _methodAnnotations;

	protected _propertyAnnotations;

	/**
	 * Phalcon\Annotations\Reflection constructor
	 *
	 * @param array reflectionData
	 */
	public function __construct(reflectionData = null)
	{
		if typeof reflectionData == "array" {
			let this->_reflectionData = reflectionData;
		}
	}

	/**
	 * Returns the annotations found in the class docblock
	 */
	public function getClassAnnotations() -> <Collection> | boolean
	{
		var annotations, reflectionClass, collection;

		let annotations = this->_classAnnotations;
		if typeof annotations != "object" {
			if fetch reflectionClass, this->_reflectionData["class"] {
				let collection = new Collection(reflectionClass),
					this->_classAnnotations = collection;
				return collection;
			}
			let this->_classAnnotations = false;
			return false;
		}
		return annotations;
	}

	/**
	 * Returns the annotations found in the methods' docblocks
	 *
	 * @return Phalcon\Annotations\Collection[]
	 */
	public function getMethodsAnnotations()
	{
		var annotations, reflectionMethods,
			collections, methodName, reflectionMethod;

		let annotations = this->_methodAnnotations;
		if typeof annotations != "object" {
			if fetch reflectionMethods, this->_reflectionData["methods"] {
				if count(reflectionMethods) {
					let collections = [];
					for methodName, reflectionMethod in reflectionMethods {
						let collections[methodName] = new Collection(reflectionMethod);
					}
					let this->_methodAnnotations = collections;
					return collections;
				}
			}
			let this->_methodAnnotations = false;
			return false;
		}
		return annotations;
	}

	/**
	 * Returns the annotations found in the properties' docblocks
	 *
	 * @return Phalcon\Annotations\Collection[]
	 */
	public function getPropertiesAnnotations()
	{
		var annotations, reflectionProperties,
			collections, property, reflectionProperty;

		let annotations = this->_propertyAnnotations;
		if typeof annotations != "object" {
			if fetch reflectionProperties, this->_reflectionData["properties"] {
				if count(reflectionProperties) {
					let collections = [];
					for property, reflectionProperty in reflectionProperties {
						let collections[property] = new Collection(reflectionProperty);
					}
					let this->_propertyAnnotations = collections;
					return collections;
				}
			}
			let this->_propertyAnnotations = false;
			return false;
		}
		return annotations;
	}

	/**
	 * Returns the raw parsing intermediate definitions used to construct the reflection
	 *
	 * @return array
	 */
	public function getReflectionData()
	{
		return this->_reflectionData;
	}

	/**
	 * Restores the state of a Phalcon\Annotations\Reflection variable export
	 *
	 * @return array data
	 */
	public static function __set_state(data) -> <Reflection>
	{
		var reflectionData;

		if typeof data == "array" {
			/**
			 * Check for a '_reflectionData' in the array to build the Reflection
			 */
			if fetch reflectionData, data["_reflectionData"] {
				return new self(reflectionData);
			}
		}

		return new self();
	}

}
