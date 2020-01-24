
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
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
     * Returns the fields
     *
     * @return string|array
     */
    public function getFields();

    /**
     * Returns the foreign key configuration
     *
     * @return string|array
     */
    public function getForeignKey();

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

    /**
     * Returns an option by the specified name
     * If the option doesn't exist null is returned
     */
    public function getOption(string! name);

    /**
     * Returns the options
     */
    public function getOptions() -> array;

    /**
     * Returns parameters that must be always used when the related records are obtained
     *
     * @return array
     */
    public function getParams();

    /**
     * Returns the referenced fields
     *
     * @return string|array
     */
    public function getReferencedFields();

    /**
     * Returns the referenced model
     */
    public function getReferencedModel() -> string;

    /**
     * Returns the relations type
     */
    public function getType() -> int;

    /**
     * Check whether the relation act as a foreign key
     */
    public function isForeignKey() -> bool;

    /**
     * Check if records returned by getting belongs-to/has-many are implicitly cached during the current request
     */
    public function isReusable() -> bool;

    /**
     * Check whether the relation is a 'many-to-many' relation or not
     */
    public function isThrough() -> bool;

    /**
     * Sets the intermediate model data for has-*-through relations
     *
     * @param string|array intermediateFields
     * @param string|array intermediateReferencedFields
     */
    public function setIntermediateRelation(var intermediateFields, string! intermediateModel, var intermediateReferencedFields);
}
