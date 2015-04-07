
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

namespace Phalcon\Mvc\Model;

/**
 * Phalcon\Mvc\Model\RelationInterface
 *
 * Interface for Phalcon\Mvc\Model\Relation
 */
interface RelationInterface
{

	/**
	 * Phalcon\Mvc\Model\Relation constructor
	 *
	 * @param int type
	 * @param string referencedModel
	 * @param string|array fields
	 * @param string|array referencedFields
	 * @param array options
	 */
	public function __construct(type, referencedModel, fields, referencedFields, options = null);

	/**
	 * Sets the intermediate model dat for has-*-through relations
	 *
	 * @param string|array intermediateFields
	 * @param string intermediateModel
	 * @param string|array intermediateReferencedFields
	 */
	public function setIntermediateRelation(var intermediateFields, string! intermediateModel, var intermediateReferencedFields);

	/**
	 * Check if records returned by getting belongs-to/has-many are implicitly cached during the current request
	 */
	public function isReusable() -> boolean;

	/**
	 * Returns the relations type
	 */
	public function getType() -> int;

	/**
	 * Returns the referenced model
	 */
	public function getReferencedModel() -> string;

	/**
	 * Returns the fields
	 *
	 * @return string|array
	 */
	public function getFields();

	/**
	 * Returns the referenced fields
	 *
	 * @return string|array
	 */
	public function getReferencedFields();

	/**
	 * Returns the options
	 *
	 * @return string|array
	 */
	public function getOptions();

	/**
	 * Check whether the relation act as a foreign key
	 */
	public function isForeignKey() -> boolean;

	/**
	 * Returns the foreign key configuration
	 *
	 * @return string|array
	 */
	public function getForeignKey();

	/**
	 * Check whether the relation is a 'many-to-many' relation or not
	 */
	public function isThrough() -> boolean;

	/**
	 * Gets the intermediate fields for has-*-through relations
	 *
	 * @return string|array
	 */
	public function getIntermediateFields();

	/**
	 * Gets the intermediate model for has-*-through relations
	 */
	public function getIntermediateModel() -> string;

	/**
	 * Gets the intermediate referenced fields for has-*-through relations
	 *
	 * @return string|array
	 */
	public function getIntermediateReferencedFields();

}
