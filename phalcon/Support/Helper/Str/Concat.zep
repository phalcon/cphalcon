
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Helper\Str;

use Phalcon\Traits\Support\Helper\Str\EndsWithTrait;
use Phalcon\Traits\Support\Helper\Str\StartsWithTrait;
use Phalcon\Support\Helper\Str\Exceptions\InsufficientArguments;

/**
 * Concatenates strings using the separator only once without duplication in
 * places concatenation
 */
class Concat
{
    use EndsWithTrait;
    use StartsWithTrait;

    /**
     * @param string $delimiter
     * @param string ...$many
     *
     * @return string
     *
     * @throws InsufficientArguments
     */
    public function __invoke(string delimiter, string ...many) -> string
    {
        var item, first, last;
        array data = [];
        string prefix = "", suffix = "";

        if unlikely count(many) < 2 {
            throw new InsufficientArguments();
        }

        let first = reset(many),
            last  = end(many);

        if this->toStartsWith(first, delimiter, false) {
            let prefix = delimiter;
        }

        if this->toEndsWith(last, delimiter, false) {
            let suffix = delimiter;
        }

        for item in many {
            let data[] = trim(item, delimiter);
        }

        return prefix . implode(delimiter, data) . suffix;
    }
}
