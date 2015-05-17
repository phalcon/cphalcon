
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

/**
 * Phalcon\Annotations\Reader
 *
 * Parses docblocks returning an array with the found annotations
 */
class Reader implements ReaderInterface
{

	/**
	 * Reads annotations from the class dockblocks, its methods and/or properties
	 */
	public function parse(string className) -> array
	{
		var annotations, reflection, comment,
			properties, methods, property, method,
			classAnnotations, line, annotationsProperties,
			propertyAnnotations, annotationsMethods, methodAnnotations;

		let annotations = [];

		/**
		 * A ReflectionClass is used to obtain the class dockblock
		 */
		let reflection = new \ReflectionClass(className);

		let comment = reflection->getDocComment();
		if typeof comment == "string" {

			/**
			 * Read annotations from class
			 */
			let classAnnotations = phannot_parse_annotations(comment, reflection->getFileName(), reflection->getStartLine());

			/**
			 * Append the class annotations to the annotations var
			 */
			if typeof classAnnotations == "array" {
				let annotations["class"] = classAnnotations;
			}
		}

		/**
		 * Get the class properties
		 */
		let properties = reflection->getProperties();
		if count(properties) {

			/**
			 * Line declaration for properties isn't available
			 */
			let line = 1;

			let annotationsProperties = [];
			for property in properties {

				/**
				 * Read comment from method
				 */
				let comment = property->getDocComment();
				if typeof comment == "string" {

					/**
					 * Read annotations from the docblock
					 */
					let propertyAnnotations = phannot_parse_annotations(comment, reflection->getFileName(), line);
					if typeof propertyAnnotations == "array" {
						let annotationsProperties[property->name] = propertyAnnotations;
					}

				}
			}

			if count(annotationsProperties) {
				let annotations["properties"] = annotationsProperties;
			}
		}

		/**
		 * Get the class methods
		 */
		let methods = reflection->getMethods();
		if count(methods) {

			let annotationsMethods = [];
			for method in methods {

				/**
				 * Read comment from method
				 */
				let comment = method->getDocComment();
				if typeof comment == "string" {

					/**
					 * Read annotations from class
					 */
					let methodAnnotations = phannot_parse_annotations(comment, method->getFileName(), method->getStartLine());
					if typeof methodAnnotations == "array" {
						let annotationsMethods[method->name] = methodAnnotations;
					}
				}
			}

			if count(annotationsMethods) {
				let annotations["methods"] = annotationsMethods;
			}

		}

		return annotations;
	}

	/**
	 * Parses a raw doc block returning the annotations found
	 */
	public static function parseDocBlock(string docBlock, file = null, line = null) -> array
	{
		if typeof file != "string" {
			let file = "eval code";
		}
		return phannot_parse_annotations(docBlock, file, line);
	}
}
