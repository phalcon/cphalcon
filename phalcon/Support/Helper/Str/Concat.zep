
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
 * Class Concat
 *
 * @package Phalcon\Support\Str
 */
class Concat extends AbstractStr
{
    /**
     * Concatenates strings using the separator only once without duplication in
     * places concatenation
     *
     * ```php
     * $str = Phalcon\Helper\Str::concat(
     *     "/",
     *     "/tmp/",
     *     "/folder_1/",
     *     "/folder_2",
     *     "folder_3/"
     * );
     *
     * echo $str;   // /tmp/folder_1/folder_2/folder_3/
     * ```
     *
     * @param string separator
     * @param string a
     * @param string b
     * @param string ...N
     *
     * @return string
     */
    public function __invoke() -> string
    {
        var argument, arguments, delimiter, data, filtered, first, last,
            prefix, suffix;

        let arguments = func_get_args();

        if unlikely count(arguments) < 3 {
            throw new Exception("concat needs at least three parameters");
        }

        let filtered  = array_filter(arguments),
            delimiter = reset(filtered),
            arguments = array_slice(arguments, 1),
            filtered  = array_filter(arguments),
            first     = reset(filtered),
            last      = end(filtered),
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
