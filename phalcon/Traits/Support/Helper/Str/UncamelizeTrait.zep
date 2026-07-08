
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Traits\Support\Helper\Str;

/**
 * Converts strings to non camelized style
 */
trait UncamelizeTrait
{
    /**
     * @param string $text
     * @param string $delimiter
     *
     * @return string
     */
    protected static function toUncamelize(
        string text,
        string delimiter = "_"
    ) -> string {
        return uncamelize(text, delimiter);
    }
}
