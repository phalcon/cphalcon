
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
 * Class FirstBetween
 *
 * @package Phalcon\Support\Str
 */
class FirstBetween
{
    /**
     * Returns the first string there is between the strings from the
     * parameter start and end.
     *
     * @param string $text
     * @param string $start
     * @param string $end
     *
     * @return string
     */
    public function __invoke(
        string text,
        string start,
        string end
    ) -> string {
        var result;

        let result = mb_strstr(text, start),
            result = (false === result) ? "" : result,
            result = mb_strstr(result, end, true),
            result = (false === result) ? "" : result;

        return trim(result, start . end);
    }
}
