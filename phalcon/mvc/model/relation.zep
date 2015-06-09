
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

use Phalcon\Mvc\Model\RelationInterface;

/**
 * Phalcon\Mvc\Model\Relation
 *
 * This class represents a relationship between two models
 */
class Relation implements RelationInterface
{

	protected _type;

	protected _referencedModel;

	protected _fields;

	protected _referencedFields;

	protected _intermediateModel;

	protected _intermediateFields;

	protected _intermediateReferencedFields;

	protected _options;

	const BELONGS_TO = 0;

	const HAS_ONE = 1;

	const HAS_MANY = 2;

	const HAS_ONE_THROUGH = 3;

	const HAS_MANY_THROUGH = 4;

	const NO_ACTION = 0;

	const ACTION_RESTRICT = 1;

	const ACTION_CASCADE = 2;

	/**
	 * Phalcon\Mvc\Model\Relation constructor
	 *
	 * @param int type
	 * @param string referencedModel
	 * @param string|array fields
	 * @param string|array referencedFields
	 * @param array options
	 */
	public function __construct(type, string! referencedModel, var fields, var referencedFields, var options = null)
	{
		let this->_type = type,
			this->_referencedModel = referencedModel,
			this->_fields = fields,
			this->_referencedFields = referencedFields,
			this->_options = options;
	}

	/**
	 * Sets the intermediate model data for has-*-through relations
	 *
	 * @param string|array intermediateFields
	 * @param string intermediateModel
	 * @param string intermediateReferencedFields
	 */
	public function setIntermediateRelation(intermediateFields, string! intermediateModel, intermediateReferencedFields)
	{
		let this->_intermediateFields = intermediateFields,
			this->_intermediateModel = intermediateModel,
			this->_intermediateReferencedFields = intermediateReferencedFields;
	}

	/**
	 * Returns the relation type
	 */
	public function getType() -> int
	{
		return this->_type;
	}

	/**
	 * Returns the referenced model
	 */
	public function getReferencedModel() -> string
	{
		return this->_referencedModel;
	}

	/**
	 * Returns the fields
	 *
	 * @return string|array
	 */
	public function getFields()
	{
		return this->_fields;
	}

	/**
	 * Returns the referenced fields
	 *
	 * @return string|array
	 */
	public function getReferencedFields()
	{
		return this->_referencedFields;
	}

	/**
	 * Returns the options
	 *
	 * @return string|array
	 */
	public function getOptions()
	{
		return this->_options;
	}

	/**
	 * Check whether the relation act as a foreign key
	 */
	public function isForeignKey() -> boolean
	{
		var options;
		let options = this->_options;
		if typeof options == "array" {
			if isset options["foreignKey"] {
				return true;
			}
		}
		return false;
	}

	/**
	 * Returns the foreign key configuration
	 *
	 * @return string|array
	 */
	public function getForeignKey()
	{
		var options, foreignKey;
		let options = this->_options;
		if typeof options == "array" {
			if fetch foreignKey, options["foreignKey"] {
				if foreignKey {
					return foreignKey;
				}
			}
		}
		return false;
	}	

	/**
	 * Returns parameters that must be always used when the related records are obtained
	 *
	 * @return array
	 */
	public function getParams()
	{
		var options, params;
		let options = this->_options;
		if typeof options == "array" {
			if fetch params, options["params"] {
				if params {
					return params;
				}
			}
		}
		return false;
	}

	/**
	 * Check whether the relation is a 'many-to-many' relation or not
	 */
	public function isThrough() -> boolean
	{
		var type;
		let type = this->_type;
		return type == self::HAS_ONE_THROUGH || type == self::HAS_MANY_THROUGH;
	}

	/**
	 * Check if records returned by getting belongs-to/has-many are implicitly cached during the current request
	 */
	public function isReusable() -> boolean
	{
		var options, reusable;
		let options = this->_options;
		if typeof options == "array" {
			if fetch reusable, options["reusable"] {
				return reusable;
			}
		}
		return false;
	}

	/**
	 * Gets the intermediate fields for has-*-through relations
	 *
	 * @return string|array
	 */
	public function getIntermediateFields()
	{
		return this->_intermediateFields;
	}

	/**
	 * Gets the intermediate model for has-*-through relations
	 */
	public function getIntermediateModel() -> string
	{
		return this->_intermediateModel;
	}

	/**
	 * Gets the intermediate referenced fields for has-*-through relations
	 *
	 * @return string|array
	 */
	public function getIntermediateReferencedFields()
	{
		return this->_intermediateReferencedFields;
	}
}
