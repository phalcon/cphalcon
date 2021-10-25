
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
 * Class Suffix
 *
 * @package Phalcon\Support\Str
 */
class Suffix
{
    /**
     * Suffixes the text with the supplied suffix
     *
     * @param mixed  $text
     * @param string $suffix
     *
     * @return string
     */
    public function __invoke(var text, string suffix) -> string
    {
        return ((string) text) . suffix;
    }
}
