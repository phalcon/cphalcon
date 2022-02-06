
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
 * Converts strings to snake_case style
 */
class SnakeCase extends PascalCase
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
        var output;

        let output = this->processArray(text, delimiters);

        return implode("_", output);
    }
}
