
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter\Sanitize;

/**
 * Phalcon\Filter\Sanitize\BoolVal
 *
 * Sanitizes a value to boolean
 */
class BoolVal
{
    /**
     * @param mixed $input The text to sanitize
     *
     * @return bool
     */
    public function __invoke(var input)
    {
        var falseArray, trueArray;

        let trueArray  = ["true", "on", "yes", "y", "1"],
            falseArray = ["false", "off", "no", "n", "0"];

        /**
         * If it is not "bool" return false
         */
        if (true !== (is_string(input) || is_int(input) || is_bool(input))) {
            return false;
        }

        /**
         * If it is a string, trim it and convert to lowercase
         */
        let input = is_string(input) ? mb_strtolower(trim(input)) : input;

        /**
         * Check the value in the true array
         */
        if (true === input || true === in_array(input, trueArray)) {
            return true;
        }

        /**
         * Check the value in the false array
         */
        if (false === input || true === in_array(input, falseArray)) {
            return false;
        }

        return (bool) input;
    }
}
