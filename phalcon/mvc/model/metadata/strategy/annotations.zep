
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

namespace Phalcon\Mvc\Model\MetaData\Strategy;

use Phalcon\DiInterface;
use Phalcon\Db\Column;
use Phalcon\Mvc\ModelInterface;
use Phalcon\Mvc\Model\MetaData;
use Phalcon\Mvc\Model\MetaData\StrategyInterface;
use Phalcon\Mvc\Model\Exception;

class Annotations implements StrategyInterface
{
	/**
	 * The meta-data is obtained by reading the column descriptions from the database information schema
	 */
	public final function getMetaData(<ModelInterface> model, <DiInterface> dependencyInjector) -> array
	{
		var annotations, className, reflection, propertiesAnnotations;
		var property, propAnnotations, columnAnnotation, columnName, feature;
		var fieldTypes, fieldBindTypes, numericTyped, primaryKeys, nonPrimaryKeys, identityField,
			notNull, attributes, automaticDefault, defaultValues, defaultValue, emptyStringValues;

		if typeof dependencyInjector != "object" {
			throw new Exception("The dependency injector is invalid");
		}

		let annotations = dependencyInjector->get("annotations");

		let className = get_class(model),
			reflection = annotations->get(className);

		if typeof reflection != "object" {
			throw new Exception("No annotations were found in class " . className);
		}

		/**
		 * Get the properties defined in
		 */
		let propertiesAnnotations = reflection->getPropertiesAnnotations();

		if !count(propertiesAnnotations) {
			throw new Exception("No properties with annotations were found in class " . className);
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
			identityField = false,
			defaultValues = [],
			emptyStringValues = [];

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
			 * Check if annotation has the 'column' named parameter
			 */
			let columnName = columnAnnotation->getNamedParameter("column");

			if empty columnName {
				let columnName = property;
			}

			/**
			 * Check if annotation has the 'type' named parameter
			 */
			let feature = columnAnnotation->getNamedParameter("type");

			switch feature {
				case "integer":
					let fieldTypes[property] = Column::TYPE_INTEGER,
						fieldBindTypes[columnName] = Column::BIND_PARAM_INT,
						numericTyped[columnName] = true;
					break;

				case "decimal":
					let fieldTypes[columnName] = Column::TYPE_DECIMAL,
						fieldBindTypes[columnName] = Column::BIND_PARAM_DECIMAL,
						numericTyped[columnName] = true;
					break;

				case "boolean":
					let fieldTypes[columnName] = Column::TYPE_BOOLEAN,
						fieldBindTypes[columnName] = Column::BIND_PARAM_BOOL;
					break;

				case "date":
					let fieldTypes[columnName] = Column::TYPE_DATE,
						fieldBindTypes[columnName] = Column::BIND_PARAM_STR;
					break;

				case "datetime":
					let fieldTypes[columnName] = Column::TYPE_DATETIME,
						fieldBindTypes[columnName] = Column::BIND_PARAM_STR;
					break;

				case "text":
					let fieldTypes[columnName] = Column::TYPE_TEXT,
						fieldBindTypes[columnName] = Column::BIND_PARAM_STR;
					break;

				default:
					/**
					 * By default all columns are varchar/string
					 */
					let fieldTypes[columnName] = Column::TYPE_VARCHAR,
						fieldBindTypes[columnName] = Column::BIND_PARAM_STR;
			}

			/**
			 * All columns marked with the 'Primary' annotation are considered primary keys
			 */
			if propAnnotations->has("Primary") {
				let primaryKeys[] = columnName;
			} else {
				let nonPrimaryKeys[] = columnName;
			}

			/**
			 * All columns marked with the 'Identity' annotation are considered the column identity
			 */
			if propAnnotations->has("Identity") {
				let identityField = columnName;
			}

			/**
			 * Check if the column
			 */
			if !columnAnnotation->getNamedParameter("nullable") {
				let notNull[] = columnName;
			}

			/**
			 * If column has default value or column is nullable and default value is null
			 */
			let defaultValue = columnAnnotation->getNamedParameter("default");
			if defaultValue !== null || columnAnnotation->getNamedParameter("nullable") {
				let defaultValues[columnName] = defaultValue;
			}

			let attributes[] = columnName;
		}

		/**
		 * Create an array using the MODELS_* constants as indexes
		 */
		return [
			MetaData::MODELS_ATTRIBUTES               : attributes,
			MetaData::MODELS_PRIMARY_KEY              : primaryKeys,
			MetaData::MODELS_NON_PRIMARY_KEY          : nonPrimaryKeys,
			MetaData::MODELS_NOT_NULL                 : notNull,
			MetaData::MODELS_DATA_TYPES               : fieldTypes,
			MetaData::MODELS_DATA_TYPES_NUMERIC       : numericTyped,
			MetaData::MODELS_IDENTITY_COLUMN          : identityField,
			MetaData::MODELS_DATA_TYPES_BIND          : fieldBindTypes,
			MetaData::MODELS_AUTOMATIC_DEFAULT_INSERT : automaticDefault,
			MetaData::MODELS_AUTOMATIC_DEFAULT_UPDATE : automaticDefault,
			MetaData::MODELS_DEFAULT_VALUES           : defaultValues,
			MetaData::MODELS_EMPTY_STRING_VALUES      : emptyStringValues
		];
	}

	/**
	 * Read the model's column map, this can't be inferred
	 */
	public final function getColumnMaps(<ModelInterface> model, <DiInterface> dependencyInjector) -> array
	{
		var annotations, className, reflection, propertiesAnnotations;
		var property, propAnnotations, columnAnnotation, columnName;
		var orderedColumnMap, reversedColumnMap;

		if typeof dependencyInjector != "object" {
			throw new Exception("The dependency injector is invalid");
		}

		let annotations = dependencyInjector->get("annotations");

		let className = get_class(model), reflection = annotations->get(className);
		if typeof reflection != "object" {
			throw new Exception("No annotations were found in class " . className);
		}

		/**
		 * Get the properties defined in
		 */
		let propertiesAnnotations = reflection->getPropertiesAnnotations();
		if !count(propertiesAnnotations) {
			throw new Exception("No properties with annotations were found in class " . className);
		}

		let orderedColumnMap = null, reversedColumnMap = null;

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
			 * Check if annotation has the 'column' named parameter
			 */
			let columnName = columnAnnotation->getNamedParameter("column");

			if !empty columnName {
				if typeof orderedColumnMap != "array" {
					let orderedColumnMap = [], reversedColumnMap = [];
				}

				let orderedColumnMap[columnName] = property,
					reversedColumnMap[property] = columnName;
			}
		}

		/**
		 * Store the column map
		 */
		return [orderedColumnMap, reversedColumnMap];
	}
}
