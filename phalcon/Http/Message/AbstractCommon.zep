
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Http\Message;

use Phalcon\Http\Message\Exception\InvalidArgumentException;

/**
 * Common methods
 */
abstract class AbstractCommon
{
    /**
     * Returns a new instance having set the parameter
     *
     * @param mixed  $element
     * @param string $property
     *
     * @return mixed
     */
    final protected function cloneInstance(element, string! property) -> var
    {
        var newInstance;

        let newInstance             = clone this,
            newInstance->{property} = element;

        return newInstance;
    }

    /**
     * Checks the element passed if it is a string
     *
     * @param mixed $element
     */
    final protected function checkStringParameter(var element) -> void
    {
        if typeof element === "string" {
            throw new InvalidArgumentException(
                "Method requires a string argument"
            );
        }
    }

    /**
     * Checks the element passed; assigns it to the property and returns a
     * clone of the object back
     *
     * @param mixed  $element
     * @param string $property
     *
     * @return mixed
     */
    final protected function processWith(var element, string! property) -> var
    {
        this->checkStringParameter($element);

        return this->cloneInstance(element, property);
    }
}
