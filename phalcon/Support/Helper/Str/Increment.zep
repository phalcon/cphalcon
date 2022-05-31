
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
 * Adds a number to the end of a string or increments that number if it
 * is already defined
 */
class Increment
{
    /**
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

        let parts  = explode(separator, text),
            number = 1;

        if true === isset(parts[1]) {
            let number = ((int) parts[1]) + 1;
        }

        return parts[0] . separator . number;
    }
}
