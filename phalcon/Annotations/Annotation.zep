
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

namespace Phalcon\Annotations;

use Phalcon\Annotations\Exceptions\UnknownAnnotationExpression;
use Phalcon\Contracts\Annotations\AnnotationsTypes;

/**
 * Represents a single annotation in an annotations collection
 *
 * @phpstan-import-type annotations_arguments from AnnotationsTypes
 * @phpstan-import-type annotations_expression from AnnotationsTypes
 * @phpstan-import-type annotations_node from AnnotationsTypes
 * @phpstan-import-type annotations_resolved_arguments from AnnotationsTypes
 */
class Annotation
{
    /**
     * Annotation Arguments
     *
     * @var array
     *
     * @phpstan-var annotations_resolved_arguments
     */
    protected arguments = [];

    /**
     * Annotation ExprArguments
     *
     * @var array
     *
     * @phpstan-var annotations_arguments
     */
    protected exprArguments = [];

    /**
     * Annotation Name
     *
     * @var string|null
     */
    protected name;

    /**
     * Phalcon\Annotations\Annotation constructor
     *
     * @phpstan-param annotations_node $reflectionData
     */
    public function __construct(array reflectionData)
    {
        var name, exprArguments, argument, resolvedArgument;
        array arguments;

        if fetch name, reflectionData["name"] {
            let this->name = reflectionData["name"];
        }

        /**
         * Process annotation arguments
         */
        if fetch exprArguments, reflectionData["arguments"] {
            let arguments = [];

            for argument in exprArguments {
                let resolvedArgument =  this->getExpression(
                    argument["expr"]
                );

                if fetch name, argument["name"] {
                    let arguments[name] = resolvedArgument;
                } else {
                    let arguments[] = resolvedArgument;
                }
            }

            let this->arguments = arguments;
            let this->exprArguments = exprArguments;
        }
    }

    /**
     * Returns an argument in a specific position
     *
     * @phpstan-param int|string $position
     */
    public function getArgument(var position) -> var | null
    {
        var argument;

        if fetch argument, this->arguments[position] {
            return argument;
        }

        return null;
    }

    /**
     * Returns the expression arguments
     *
     * @phpstan-return annotations_resolved_arguments
     */
    public function getArguments() -> array
    {
        return this->arguments;
    }

    /**
     * Returns the expression arguments without resolving
     *
     * @phpstan-return annotations_arguments
     */
    public function getExprArguments() -> array
    {
        return this->exprArguments;
    }

    /**
     * Resolves an annotation expression
     *
     * @phpstan-param annotations_expression $expr
     */
    public function getExpression(array expr) -> var
    {
        var item, resolvedItem, arrayValue, name, type,
            value = null;

        let type = expr["type"];

        switch type {
            case PHANNOT_T_INTEGER:
            case PHANNOT_T_DOUBLE:
            case PHANNOT_T_STRING:
            case PHANNOT_T_IDENTIFIER:
                let value = expr["value"];
                break;

            case PHANNOT_T_NULL:
                let value = null;
                break;

            case PHANNOT_T_FALSE:
                let value = false;
                break;

            case PHANNOT_T_TRUE:
                let value = true;
                break;

            case PHANNOT_T_ARRAY:
                let arrayValue = [];

                for item in expr["items"] {
                    let resolvedItem = this->getExpression(
                        item["expr"]
                    );

                    if fetch name, item["name"] {
                        let arrayValue[name] = resolvedItem;
                    } else {
                        let arrayValue[] = resolvedItem;
                    }
                }

                return arrayValue;

            case PHANNOT_T_ANNOTATION:
                return new Annotation(expr);

            default:
                throw new UnknownAnnotationExpression(type);
        }

        return value;
    }

    /**
     * Returns the annotation's name
     */
    public function getName() -> null | string
    {
        return this->name;
    }

    /**
     * Returns a named argument
     */
    public function getNamedArgument(string name) -> var | null
    {
        var argument;

        if fetch argument, this->arguments[name] {
            return argument;
        }

        return null;
    }

    /**
     * Returns a named parameter
     */
    public function getNamedParameter(string name) -> var
    {
        return this->getNamedArgument(name);
    }

    /**
     * Returns an argument in a specific position
     *
     * @phpstan-param int|string $position
     */
    public function hasArgument(var position) -> bool
    {
        return isset this->arguments[position];
    }

    /**
     * Returns the number of arguments that the annotation has
     */
    public function numberArguments() -> int
    {
        return count(this->arguments);
    }
}
