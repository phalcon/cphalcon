
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
 * Sanitizes a value to string
 */
class StringVal
{
    /**
     * @param mixed $input The text to sanitize
     *
     * @return string|false
     */
    public function __invoke(var input)
    {
        /**
         * Since PHP8.1, filter `FILTER_SANITIZE_STRING` is deprecated.
         *
         * Code below is identical replication of `filter_var(input, FILTER_SANITIZE_STRING)`
         * for backward compatibility.
         */

        if typeof input === "array" {
            return false;
        }

        let input = str_replace(chr(0), "", (string)input);
        let input = preg_replace("/<[^>]*>?/", "", input);

        return str_replace(["'", "\""], ["&#39;", "&#34;"], input);
    }
}
