
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
 * Phalcon\Mvc\Model\Relation
 *
 * This class represents a relationship between two models
 */
class Relation implements RelationInterface
{
    const ACTION_CASCADE   = 2;
    const ACTION_RESTRICT  = 1;
    const BELONGS_TO       = 0;
    const HAS_MANY         = 2;
    const HAS_MANY_THROUGH = 4;
    const HAS_ONE          = 1;
    const HAS_ONE_THROUGH  = 3;
    const NO_ACTION        = 0;

    /**
     * @var array|string
     */
    protected fields;

    /**
     * @var array|string
     */
    protected intermediateFields;

    /**
     * @var string|null
     */
    protected intermediateModel = null;

    /**
     * @var array|string
     */
    protected intermediateReferencedFields;

    /**
     * @var array
     */
    protected options = [];

    /**
     * @var array|string
     */
    protected referencedFields;

    /**
     * @var string
     */
    protected referencedModel;

    /**
     * @var int
     */
    protected type;

    /**
     * Phalcon\Mvc\Model\Relation constructor
     *
     * @param int type
     * @param string referencedModel
     * @param array|string fields
     * @param array|string referencedFields
     * @param array options
     */
    public function __construct(int type, string! referencedModel, var fields, var referencedFields, array options = [])
    {
        let this->type = type,
            this->referencedModel = referencedModel,
            this->fields = fields,
            this->referencedFields = referencedFields,
            this->options = options;
    }

    /**
     * Returns the fields
     *
     * @return array|string
     */
    public function getFields()
    {
        return this->fields;
    }

    /**
     * Returns the foreign key configuration
     *
     * @return array|string
     */
    public function getForeignKey()
    {
        var options, foreignKey;

        let options = this->options;

        if fetch foreignKey, options["foreignKey"] {
            if foreignKey {
                return foreignKey;
            }
        }

        return false;
    }

    /**
     * Gets the intermediate fields for has-*-through relations
     *
     * @return array|string
     */
    public function getIntermediateFields()
    {
        return this->intermediateFields;
    }

    /**
     * Gets the intermediate model for has-*-through relations
     */
    public function getIntermediateModel() -> string
    {
        return this->intermediateModel;
    }

    /**
     * Gets the intermediate referenced fields for has-*-through relations
     *
     * @return array|string
     */
    public function getIntermediateReferencedFields()
    {
        return this->intermediateReferencedFields;
    }

    /**
     * Returns an option by the specified name
     * If the option doesn't exist null is returned
     */
    public function getOption(string! name)
    {
        var option;

        if !fetch option, this->options[name] {
            return null;
        }

        return option;
    }

    /**
     * Returns the options
     */
    public function getOptions() -> array
    {
        return this->options;
    }

    /**
     * Returns parameters that must be always used when the related records are obtained
     *
     * @return array
     */
    public function getParams()
    {
        var options, params;

        let options = this->options;

        if fetch params, options["params"] {
            if params {
                if is_callable(params) {
                    return call_user_func(params);
                }

                return params;
            }
        }

        return false;
    }

    /**
     * Returns the relation type
     */
    public function getType() -> int
    {
        return this->type;
    }

    /**
     * Returns the referenced fields
     *
     * @return array|string
     */
    public function getReferencedFields()
    {
        return this->referencedFields;
    }

    /**
     * Returns the referenced model
     */
    public function getReferencedModel() -> string
    {
        return this->referencedModel;
    }

    /**
     * Check whether the relation act as a foreign key
     */
    public function isForeignKey() -> bool
    {
        var foreignKey;

        if !fetch foreignKey, this->options["foreignKey"] {
            return false;
        }

        return (bool) foreignKey;
    }

    /**
     * Check whether the relation is a 'many-to-many' relation or not
     */
    public function isThrough() -> bool
    {
        var type;

        let type = this->type;

        return type == self::HAS_ONE_THROUGH || type == self::HAS_MANY_THROUGH;
    }

    /**
     * Check if records returned by getting belongs-to/has-many are implicitly cached during the current request
     */
    public function isReusable() -> bool
    {
        var options, reusable;

        let options = this->options;

        if !fetch reusable, options["reusable"] {
            return false;
        }

        return reusable;
    }

    /**
     * Sets the intermediate model data for has-*-through relations
     *
     * @param array|string intermediateFields
     * @param string       intermediateModel
     * @param array|string intermediateReferencedFields
     */
    public function setIntermediateRelation(var intermediateFields, string! intermediateModel, var intermediateReferencedFields)
    {
        let this->intermediateFields = intermediateFields,
            this->intermediateModel = intermediateModel,
            this->intermediateReferencedFields = intermediateReferencedFields;
    }
}
