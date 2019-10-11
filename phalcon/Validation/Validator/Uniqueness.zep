
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Validation\Validator;

use Phalcon\Messages\Message;
use Phalcon\Mvc\Model;
use Phalcon\Mvc\ModelInterface;
use Phalcon\Validation;
use Phalcon\Validation\AbstractCombinedFieldsValidator;
use Phalcon\Validation\Exception;
//use Phalcon\Mvc\CollectionInterface;
//use Phalcon\Mvc\Collection;

/**
 * Check that a field is unique in the related table
 *
 * ```php
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\Uniqueness as UniquenessValidator;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "username",
 *     new UniquenessValidator(
 *         [
 *             "model"   => new Users(),
 *             "message" => ":field must be unique",
 *         ]
 *     )
 * );
 * ```
 *
 * Different attribute from the field:
 * ```php
 * $validator->add(
 *     "username",
 *     new UniquenessValidator(
 *         [
 *             "model"     => new Users(),
 *             "attribute" => "nick",
 *         ]
 *     )
 * );
 * ```
 *
 * In model:
 * ```php
 * $validator->add(
 *     "username",
 *     new UniquenessValidator()
 * );
 * ```
 *
 * Combination of fields in model:
 * ```php
 * $validator->add(
 *     [
 *         "firstName",
 *         "lastName",
 *     ],
 *     new UniquenessValidator()
 * );
 * ```
 *
 * It is possible to convert values before validation. This is useful in
 * situations where values need to be converted to do the database lookup:
 *
 * ```php
 * $validator->add(
 *     "username",
 *     new UniquenessValidator(
 *         [
 *             "convert" => function (array $values) {
 *                 $values["username"] = strtolower($values["username"]);
 *
 *                 return $values;
 *             }
 *         ]
 *     )
 * );
 * ```
 */
class Uniqueness extends AbstractCombinedFieldsValidator
{
    protected template = "Field :field must be unique";

    private columnMap = null;

    /**
     * Constructor
     *
     * @param array options = [
     *     'message' => '',
     *     'template' => '',
     *     'allowEmpty' => false,
     *     'convert' => null,
     *     'model' => null,
     *     'except' => null
     * ]
     */
    public function __construct(array! options = [])
    {
        parent::__construct(options);
    }

    /**
     * Executes the validation
     */
    public function validate(<Validation> validation, var field) -> bool
    {
        if !this->isUniqueness(validation, field) {
            validation->appendMessage(
                this->messageFactory(validation, field)
            );

            return false;
        }

        return true;
    }

    /**
     * The column map is used in the case to get real column name
     */
    protected function getColumnNameReal(var record, string! field) -> string
    {
        // Caching columnMap
        if globals_get("orm.column_renaming") && !this->columnMap {
            let this->columnMap = record->getDI()
                ->getShared("modelsMetadata")
                ->getColumnMap(record);
        }

        if typeof this->columnMap == "array" && isset this->columnMap[field] {
            return this->columnMap[field];
        }

        return field;
    }

    protected function isUniqueness(<Validation> validation, var field) -> bool
    {
        var values, convert, record, params, className, isModel, singleField;
//
// @todo: Restore when new Collection is reintroduced
//
//        var isDocument;

        if typeof field != "array" {
            let singleField = field,
                field = [];

            let field[] = singleField;
        }

        let values = [],
            convert = this->getOption("convert");

        for singleField in field {
            let values[singleField] = validation->getValue(singleField);
        }

        if convert != null {
            let values = {convert}(values);

            if unlikely !is_array(values) {
                throw new Exception("Value conversion must return an array");
            }
        }

        let record = this->getOption("model");

        if empty record || typeof record != "object" {
            // check validation getEntity() method
            let record = validation->getEntity();

            if unlikely empty record {
                throw new Exception(
                    "Model of record must be set to property \"model\""
                );
            }
        }

        let isModel = record instanceof ModelInterface;
//
// @todo: Restore when new Collection is reintroduced
//
//        let isDocument = record instanceof CollectionInterface;

        if isModel {
            let params = this->isUniquenessModel(record, field, values);
//
// @todo: Restore when new Collection is reintroduced
//
//        } elseif isDocument {
//            let params = this->isUniquenessCollection(record, field, values);
        } else {
            throw new Exception(
                "The uniqueness validator works only with Phalcon\\Mvc\\Model"
            );
//
// @todo: Restore when new Collection is reintroduced
//
//            throw new Exception(
//                "The uniqueness validator works only with Phalcon\\Mvc\\Model or Phalcon\\Mvc\\Collection"
//            );
        }

        let className = get_class(record);

        return {className}::count(params) == 0;
    }


//
// @todo: Restore when new Collection is reintroduced
//
//    /**
//     * Uniqueness method used for collection
//     */
//    protected function isUniquenessCollection(var record, array field, array values)
//    {
//        var exceptConditions, fieldExcept, notInValues, value, singleField,
//            params, except, singleExcept;
//
//        let exceptConditions = [];
//        let params = [
//            "conditions" : []
//        ];
//
//        for singleField in field {
//            let fieldExcept = null;
//            let notInValues = [];
//            let value = values[singleField];
//
//            let except = this->getOption("except");
//
//            let params["conditions"][singleField] = value;
//
//            if except {
//                if typeof except == "array" && count(field) > 1 {
//                    if isset except[singleField] {
//                        let fieldExcept = except[singleField];
//                    }
//                }
//
//                if fieldExcept != null {
//                    if typeof fieldExcept == "array" {
//                        for singleExcept in fieldExcept {
//                            let notInValues[] = singleExcept;
//                        }
//
//                        let exceptConditions[singleField] = [
//                            "$nin": notInValues
//                        ];
//                    } else {
//                        let exceptConditions[singleField] = [
//                            "$ne": fieldExcept
//                        ];
//                    }
//                } elseif typeof except == "array" && count(field) == 1 {
//                    for singleExcept in except {
//                        let notInValues[] = singleExcept;
//                    }
//
//                    let params["conditions"][singleField] = [
//                        "$nin": notInValues
//                    ];
//                } elseif count(field) == 1 {
//                    let params["conditions"][singleField] = [
//                        "$ne": except
//                    ];
//                }
//            }
//        }
//
//        if record->getDirtyState() == Collection::DIRTY_STATE_PERSISTENT {
//            let params["conditions"]["_id"] = [
//                "$ne": record->getId()
//            ];
//        }
//
//        if !empty exceptConditions {
//            let params["conditions"]["$or"] = [exceptConditions];
//        }
//
//        return params;
//    }

    /**
     * Uniqueness method used for model
     */
    protected function isUniquenessModel(var record, array field, array values)
    {
        var index, params, attribute, metaData, primaryField, singleField,
            fieldExcept, singleExcept, notInValues, exceptConditions, value,
            except;

        let exceptConditions = [],
            index  = 0,
            params = [
                "conditions": [],
                "bind":       []
            ],
            except = this->getOption("except");

        for singleField in field {
            let fieldExcept = null,
                notInValues = [],
                value = values[singleField];

            let attribute = this->getOption("attribute", singleField);
            let attribute = this->getColumnNameReal(record, attribute);

            if value != null {
                let params["conditions"][] = attribute . " = ?" . index;
                let params["bind"][] = value;
                let index++;
            } else {
                let params["conditions"][] = attribute . " IS NULL";
            }

            if except {
                if typeof except == "array" && array_keys(except) !== range(0, count(except) - 1) {
                    for singleField, fieldExcept in except {
                        let attribute = this->getColumnNameReal(
                            record,
                            this->getOption("attribute", singleField)
                        );

                        if typeof fieldExcept == "array" {
                            for singleExcept in fieldExcept {
                                let notInValues[] = "?" . index;
                                let params["bind"][] = singleExcept;
                                let index++;
                            }

                            let exceptConditions[] = attribute . " NOT IN (" . join(",", notInValues) . ")";
                        } else {
                            let exceptConditions[] = attribute . " <> ?" . index;
                            let params["bind"][] = fieldExcept;
                            let index++;
                        }
                    }
                } elseif count(field) == 1 {
                    let attribute = this->getColumnNameReal(
                        record,
                        this->getOption("attribute", field[0])
                    );

                    if typeof except == "array" {
                        for singleExcept in except {
                            let notInValues[] = "?" . index;
                            let params["bind"][] = singleExcept;
                            let index++;
                        }

                        let exceptConditions[] = attribute . " NOT IN (" . join(",", notInValues) . ")";
                    } else {
                        let params["conditions"][] = attribute . " <> ?" . index;
                        let params["bind"][] = except;
                        let index++;
                    }
                } elseif count(field) > 1 {
                    for singleField in field {
                        let attribute = this->getColumnNameReal(
                            record,
                            this->getOption("attribute", singleField)
                        );

                        if typeof except == "array" {
                            for singleExcept in except {
                                let notInValues[] = "?" . index;
                                let params["bind"][] = singleExcept;
                                let index++;
                            }

                            let exceptConditions[] = attribute . " NOT IN (" . join(",", notInValues) . ")";
                        } else {
                            let params["conditions"][] = attribute . " <> ?" . index;
                            let params["bind"][] = except;
                            let index++;
                        }
                    }
                }
            }
        }

        /**
         * If the operation is update, there must be values in the object
         */
        if record->getDirtyState() == Model::DIRTY_STATE_PERSISTENT {
            let metaData = record->getDI()->getShared("modelsMetadata");

            for primaryField in metaData->getPrimaryKeyAttributes(record) {
                let params["conditions"][] = this->getColumnNameReal(record, primaryField) . " <> ?" . index;

                let params["bind"][] = record->readAttribute(
                    this->getColumnNameReal(record, primaryField)
                );

                let index++;
            }
        }

        if !empty exceptConditions {
            let params["conditions"][] = "(" . join(" OR ", exceptConditions) . ")";
        }

        let params["conditions"] = join(
            " AND ",
            params["conditions"]
        );

        return params;
    }
}
