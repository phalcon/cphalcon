
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Helper\Str;

use RuntimeException;

/**
 * Generates random text in accordance with the template. The template is
 * defined by the left and right delimiter and it can contain values separated
 * by the separator
 */
class Dynamic
{
    /**
     * @param string $text
     * @param string $leftDelimiter
     * @param string $rightDelimiter
     * @param string $separator
     *
     * @return string
     */
    public function __invoke(
        string text,
        string leftDelimiter = "{",
        string rightDelimiter = "}",
        string separator = "|"
    ) -> string
    {
        var ldS, rdS, matches, match, words, word, sub;
        string pattern;

        if unlikely substr_count(text, leftDelimiter) !== substr_count(text, rightDelimiter) {
            throw new RuntimeException(
                "Syntax error in string '" . text . "'"
            );
        }

        let ldS = preg_quote(leftDelimiter),
            rdS = preg_quote(rightDelimiter),
            pattern = "/" . ldS . "([^" . ldS . rdS . "]+)" . rdS . "/",
            matches = [];

        if !preg_match_all(pattern, text, matches, 2) {
            return text;
        }

        if typeof matches == "array" {
            for match in matches {
                if !isset match[0] || !isset match[1] {
                    continue;
                }

                let words = explode(separator, match[1]),
                    word  = words[array_rand(words)],
                    sub   = preg_quote(match[0], separator),
                    text  = preg_replace("/" . sub . "/", word, text, 1);
            }
        }

        return text;
    }
}
