
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model;

use Phalcon\Contracts\Mvc\MvcTypes;

/**
 * Phalcon\Mvc\Model\Relation
 *
 * This class represents a relationship between two models
 *
 * @phpstan-import-type mvc_model_parameters from MvcTypes
 * @phpstan-import-type mvc_relation_fields from MvcTypes
 * @phpstan-import-type mvc_relation_options from MvcTypes
 */
class Relation implements RelationInterface
{
    /**
     * @var int
     */
    const ACTION_CASCADE   = 2;
    /**
     * @var int
     */
    const ACTION_RESTRICT  = 1;
    /**
     * @var int
     */
    const BELONGS_TO       = 0;
    /**
     * @var int
     */
    const HAS_MANY         = 2;
    /**
     * @var int
     */
    const HAS_MANY_THROUGH = 4;
    /**
     * @var int
     */
    const HAS_ONE          = 1;
    /**
     * @var int
     */
    const HAS_ONE_THROUGH  = 3;
    /**
     * @var int
     */
    const NO_ACTION        = 0;

    /**
     * @var array|string
     */
    protected fields;

    /**
     * @var array|string
     *
     * @phpstan-var mvc_relation_fields
     */
    protected intermediateFields;

    /**
     * @var string|null
     */
    protected intermediateModel = null;

    /**
     * @var array|string
     *
     * @phpstan-var mvc_relation_fields
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
     *
     * @phpstan-param mvc_relation_options $options
     */
    public function __construct(int type,  string referencedModel, var fields, var referencedFields, array options = [])
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
     *
     * @phpstan-return mvc_relation_fields
     */
    public function getFields()
    {
        return this->fields;
    }

    /**
     * Returns the foreign key configuration
     *
     * @return array|string
     *
     * @phpstan-return array<string, mixed>|string|bool
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
     *
     * @phpstan-return mvc_relation_fields
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
     *
     * @phpstan-return mvc_relation_fields
     */
    public function getIntermediateReferencedFields()
    {
        return this->intermediateReferencedFields;
    }

    /**
     * Returns an option by the specified name
     * If the option does not exist null is returned
     */
    public function getOption(string name)
    {
        var option;

        if !fetch option, this->options[name] {
            return null;
        }

        return option;
    }

    /**
     * Returns the options
     *
     * @phpstan-return mvc_relation_options
     */
    public function getOptions() -> array
    {
        return this->options;
    }

    /**
     * Returns parameters that must be always used when the related records are obtained
     *
     * @return array
     *
     * @phpstan-return mvc_model_parameters|false
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
     *
     * @phpstan-return mvc_relation_fields
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
    public function setIntermediateRelation(var intermediateFields,  string intermediateModel, var intermediateReferencedFields)
    {
        let this->intermediateFields = intermediateFields,
            this->intermediateModel = intermediateModel,
            this->intermediateReferencedFields = intermediateReferencedFields;
    }
}
