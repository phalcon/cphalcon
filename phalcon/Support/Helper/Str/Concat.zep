
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Helper\Str;

use Phalcon\Support\Helper\Exception;

/**
 * Concatenates strings using the separator only once without duplication in
 * places concatenation
 */
class Concat extends AbstractStr
{
    /**
     * @param string $delimiter
     * @param string $first
     * @param string $second
     * @param string ...$arguments
     *
     * @return string
     */
    public function __invoke() -> string
    {
        var argument, arguments, delimiter, data, first, last,
            prefix, suffix;

        let arguments = func_get_args();

        if unlikely count(arguments) < 3 {
            throw new Exception("concat needs at least three parameters");
        }

        let delimiter = reset(arguments),
            arguments = array_slice(arguments, 1),
            first     = reset(arguments),
            last      = end(arguments),
            prefix    = "",
            suffix    = "",
            data      = [];

        if starts_with(first, delimiter) {
            let prefix = delimiter;
        }

        if ends_with(last, delimiter) {
            let suffix = delimiter;
        }


        for argument in arguments {
            let data[] = trim(argument, delimiter);
        }

        return prefix . implode(delimiter, data) . suffix;
    }
}
