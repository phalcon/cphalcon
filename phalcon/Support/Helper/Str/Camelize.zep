
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Helper\Str;

/**
 * Converts strings to camelize style
 */
class Camelize
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
        var delims, exploded, output;

        if !delimiters {
            let delims = "_-";
        } else {
            let delims = delimiters;
        }

        let exploded   = preg_split(
            "/[" . delims . "]+/",
            text,
            -1,
            PREG_SPLIT_DELIM_CAPTURE | PREG_SPLIT_NO_EMPTY
        );

        let output     = array_map(
            function (element) {
                return ucfirst(mb_strtolower(element));
            },
            exploded
        );

        return implode("", output);
    }
}
