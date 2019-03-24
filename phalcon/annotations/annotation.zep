
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Annotations;

use Phalcon\Annotations\Annotation;
use Phalcon\Annotations\Exception;

/**
 * Phalcon\Annotations\Annotation
 *
 * Represents a single annotation in an annotations collection
 */
class Annotation
{
    /**
     * Annotation Name
     * @var string
     */
    protected name;

    /**
     * Annotation Arguments
     * @var string
     */
    protected arguments;

    /**
     * Annotation ExprArguments
     * @var string
     */
    protected exprArguments;

    /**
     * Phalcon\Annotations\Annotation constructor
     */
    public function __construct(array! reflectionData) -> void
    {
        var name, exprArguments, argument, resolvedArgument, arguments;

        let this->name = reflectionData["name"];

        /**
         * Process annotation arguments
         */
        if fetch exprArguments, reflectionData["arguments"] {
            let arguments = [];
            for argument in exprArguments {
                let resolvedArgument =  this->getExpression(argument["expr"]);
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
     * @param int|string position
     * @return mixed
     */
    public function getArgument(var position) -> var
    {
        var argument;
        if fetch argument, this->arguments[position] {
            return argument;
        }
    }

    /**
     * Returns the expression arguments
     *
     * @return array
     */
    public function getArguments() -> array
    {
        return this->arguments;
    }

    /**
     * Returns the expression arguments without resolving
     *
     * @return array
     */
    public function getExprArguments() -> array
    {
        return this->exprArguments;
    }

    /**
     * Resolves an annotation expression
     *
     * @return mixed
     */
    public function getExpression(array! expr) -> var
    {
        var value, item, resolvedItem, arrayValue, name, type;

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
                    let resolvedItem = this->getExpression(item["expr"]);
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
                throw new Exception("The expression ". type. " is unknown");
        }

        return value;
    }

    /**
     * Returns the annotation's name
     */
    public function getName() -> string
    {
        return this->name;
    }

    /**
     * Returns a named argument
     *
     * @return mixed
     */
    public function getNamedArgument(string! name) -> var
    {
        var argument;
        if fetch argument, this->arguments[name] {
            return argument;
        }
    }

    /**
     * Returns a named parameter
     *
     * @return mixed
     */
    public function getNamedParameter(string! name) -> var
    {
        return this->getNamedArgument(name);
    }

    /**
     * Returns an argument in a specific position
     *
     * @param int|string position
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
