
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

class Annotations
{
	/**
	 * The meta-data is obtained by reading the column descriptions from the database information schema
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @param Phalcon\DiInterface dependencyInjector
	 * @return array
	 */
	public function getMetaData(<Phalcon\Mvc\ModelInterface> model, <Phalcon\DiInterface> dependency_injector)
	{
		var annotations, class_name, reflection, properties_annotations;
		var property, prop_annotations, column_annotation, feature;
		array field_types, field_bind_types, numeric_typed, primary_keys, non_primary_keys, identity_field, not_null, attributes, 
			automatic_default;

		let annotations = dependency_injector->get("annotations");
		let class_name = get_class(model);
		let reflection = annotations->get(class_name);

		if typeof reflection != "object" {
			throw new Phalcon\Mvc\Model\Exception("No annotations were found in class ".class_name);
		}

		let properties_annotations = reflection->getPropertiesAnnotations();
		if empty(properties_annotations) {
			throw new Phalcon\Mvc\Model\Exception("No properties with annotations were found in class ".class_name);
		}

		for property, prop_annotations in properties_annotations {
			if !prop_annotations->has("Column") {
				continue;
			}

			let column_annotation = prop_annotations->get("Column");

			let feature = column_annotation->getargument("type");

			if feature == "integer" {
				let field_types[property] = 0;
				let field_bind_types[property] = 1;
				let numeric_typed[property] = 1;
			} else {
				if feature == "decimal" {
					let field_types[property] = 3;
					let field_bind_types[property] = 32;
					let numeric_typed[property] = 1;
				} else {
					if feature == "boolean" {
						let field_types[property] = 8;
						let field_bind_types[property] = 5;
					} else {
						if feature == "date" {
							let field_types[property] = 1;
						} else {
							let field_types[property] = 2;
						}
						let field_bind_types[property] = 2;
					}
				}
			}
			
			if prop_annotations->has("Primary") {
				let primary_keys[] = property;
			} else {
				let non_primary_keys[] = property;
			}
			
			if prop_annotations->has("Identity") {
				let identity_field = property;
			}

			if column_annotation->getArgument("nullable") {
				let not_null[] = property;
			}

			let attributes[] = property;
		}

		return [
			0: attributes,
			1: primary_keys,
			2: non_primary_keys,
			3: not_null, 
			4: field_types, 
			5: numeric_typed, 
			8: identity_field, 
			9: field_bind_types, 
			10: automatic_default, 
			11: automatic_default
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
	public function getColumnMaps(<Phalcon\Mvc\ModelInterface> model, <Phalcon\DiInterface> dependency_injector)
	{
	}
}