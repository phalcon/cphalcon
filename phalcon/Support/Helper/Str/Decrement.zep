
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Helper\Str;

class Decrement
{
    /**
     * Removes a number from a string or decrements that number if it is already
     * defined
     *
     * ```php
     * use Phalcon\Support\Helper\Str;
     *
     * echo Str::decrement('a_1');  // 'a'
     * echo Str::decrement('a_2');  // 'a_1'
     * ```
     *
     * @param string $text
     * @param string $separator
     *
     * @return string
     */
    public function __invoke(
        string text,
        string separator = "_"
    ) -> string {
        var number, parts;

        let number = 0,
            parts  = explode(separator, text),
            parts  = typeof parts !== "array" ? [] : parts;

        if true === isset(parts[1]) {
            let number = (int) parts[1],
                number--;
            if number <= 0 {
                return parts[0];
            }
        }

        return parts[0] . separator . number;
    }
}
