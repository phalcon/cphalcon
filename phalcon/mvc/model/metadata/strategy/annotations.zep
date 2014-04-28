
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

namespace Phalcon\Mvc\Model\MetaData\Strategy;

use Phalcon\Db\Column;

class Annotations
{
	/**
	 * The meta-data is obtained by reading the column descriptions from the database information schema
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @param Phalcon\DiInterface dependencyInjector
	 * @return array
	 */
	public function getMetaData(<\Phalcon\Mvc\ModelInterface> model, <\Phalcon\DiInterface> dependencyInjector)
	{
		var annotations, className, reflection, propertiesAnnotations;
		var property, propAnnotations, columnAnnotation, feature;
		var fieldTypes, fieldBindTypes, numericTyped, primaryKeys, nonPrimaryKeys, identityField,
			notNull, attributes, automaticDefault;

		if typeof dependencyInjector != "object" {
			throw new \Phalcon\Mvc\Model\Exception("The dependency injector is invalid");
		}

		let annotations = dependencyInjector->get("annotations");

		let className = get_class(model), reflection = annotations->get(className);
		if typeof reflection != "object" {
			throw new \Phalcon\Mvc\Model\Exception("No annotations were found in class " . className);
		}

		/**
		 * Get the properties defined in
		 */
		let propertiesAnnotations = reflection->getPropertiesAnnotations();
		if !count(propertiesAnnotations) {
			throw new \Phalcon\Mvc\Model\Exception("No properties with annotations were found in class " . className);
		}

		/**
		 * Initialize meta-data
		 */
		let attributes = [],
			primaryKeys = [],
			nonPrimaryKeys = [],
			numericTyped = [],
			notNull = [],
			fieldTypes = [],
			fieldBindTypes = [],
			automaticDefault = [],
			identityField = false;

		for property, propAnnotations in propertiesAnnotations {

			/**
			 * All columns marked with the 'Column' annotation are considered columns
			 */
			if !propAnnotations->has("Column") {
				continue;
			}

			/**
			 * Fetch the 'column' annotation
			 */
			let columnAnnotation = propAnnotations->get("Column");

			/**
			 * Check if annotation has the 'type' named parameter
			 */
			let feature = columnAnnotation->getNamedParameter("type");

			if feature == "integer" {
				let fieldTypes[property] = Column::TYPE_INTEGER,
					fieldBindTypes[property] = 1,
					numericTyped[property] = true;
			} else {
				if feature == "decimal" {
					let fieldTypes[property] = 3,
						fieldBindTypes[property] = 32,
						numericTyped[property] = true;
				} else {
					if feature == "boolean" {
						let fieldTypes[property] = 8,
							fieldBindTypes[property] = 5;
					} else {
						if feature == "date" {
							let fieldTypes[property] = 1;
						} else {
							/**
							 * By default all columns are varchar/string
							 */
							let fieldTypes[property] = Column::TYPE_VARCHAR;
						}
						let fieldBindTypes[property] = Column::TYPE_VARCHAR;
					}
				}
			}

			/**
			 * All columns marked with the 'Primary' annotation are considered primary keys
			 */
			if propAnnotations->has("Primary") {
				let primaryKeys[] = property;
			} else {
				let nonPrimaryKeys[] = property;
			}

			/**
			 * All columns marked with the 'Identity' annotation are considered the column identity
			 */
			if propAnnotations->has("Identity") {
				let identityField = property;
			}

			/**
			 * Check if the column
			 */
			if !columnAnnotation->getNamedParameter("nullable") {
				let notNull[] = property;
			}

			let attributes[] = property;
		}

		/**
		 * Create an array using the MODELS_* constants as indexes
		 */
		return [
			0: attributes,
			1: primaryKeys,
			2: nonPrimaryKeys,
			3: notNull,
			4: fieldTypes,
			5: numericTyped,
			8: identityField,
			9: fieldBindTypes,
			10: automaticDefault,
			11: automaticDefault
		];
	}

	/**
	 * Read the model's column map, this can't be inferred
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @param Phalcon\DiInterface dependencyInjector
	 * @return array
	 * @todo Not implemented
	 */
	public function getColumnMaps(<\Phalcon\Mvc\ModelInterface> model, <\Phalcon\DiInterface> dependencyInjector)
	{
	}

}
