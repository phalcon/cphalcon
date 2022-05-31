
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
 * Suffixes the text with the supplied suffix
 */
class Suffix
{
    /**
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
