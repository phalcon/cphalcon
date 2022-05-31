
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Helper\Str;

/**
 * Converts strings to PascalCase style
 */
class PascalCase
{
    /**
     * @param string      $text
     * @param string|null $delimiters
     *
     * @return string
     */
    public function __invoke(
        string text,
        string delimiters = null
    ) -> string {
        var exploded, output;

        let exploded = this->processArray(text, delimiters);

        let output = array_map(
            function (element) {
                return ucfirst(mb_strtolower(element));
            },
            exploded
        );

        return implode("", output);
    }

    /**
     * @param string      $text
     * @param string|null $delimiters
     *
     * @return array
     */
    protected function processArray(string text, string delimiters = null) -> array
    {
        var result;

        if delimiters === null {
            let delimiters = "-_";
        }

        /**
         * Escape the `-` if it exists so that it does not get interpreted
         * as a range. First remove any escaping for the `-` if present and then
         * add it again - just to be on the safe side
         */
        if strpos(delimiters, "\\-") !== false || strpos(delimiters, "-") !== false {
            let delimiters = str_replace(["\\-", "-"], ["", ""], delimiters),
                delimiters = "-" . delimiters;
        }

        let result = preg_split(
            "/[" . delimiters . "]+/",
            text,
            -1,
            PREG_SPLIT_DELIM_CAPTURE | PREG_SPLIT_NO_EMPTY
        );

        return (false === result) ? [] : result;
    }
}
