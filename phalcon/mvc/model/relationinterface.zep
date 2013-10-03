
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
	public function __construct(type, referencedModel, fields, referencedFields, options=null);

	/**
	 * Sets the intermediate model dat for has-*-through relations
	 *
	 * @param string|array intermediateFields
	 * @param string intermediateModel
	 * @param string|array intermediateReferencedFields
	 */
	public function setIntermediateRelation(var intermediateFields, string! intermediateModel, var intermediateReferencedFields);

	/**
	 * Returns the relations type
	 *
	 * @return int
	 */
	public function getType();

	/**
	 * Returns the referenced model
	 *
	 * @return string
	 */
	public function getReferencedModel();

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
	 *
	 * @return string|array
	 */
	public function isForeignKey();

	/**
	 * Returns the foreign key configuration
	 *
	 * @return string|array
	 */
	public function getForeignKey();

	/**
	 * Check whether the relation is a 'many-to-many' relation or not
	 *
	 * @return boolean
	 */
	public function isThrough();

	/**
	 * Gets the intermediate fields for has-*-through relations
	 *
	 * @return string|array
	 */
	public function getIntermediateFields();

	/**
	 * Gets the intermediate model for has-*-through relations
	 *
	 * @return string
	 */
	public function getIntermediateModel();

	/**
	 * Gets the intermediate referenced fields for has-*-through relations
	 *
	 * @return string|array
	 */
	public function getIntermediateReferencedFields();

}
