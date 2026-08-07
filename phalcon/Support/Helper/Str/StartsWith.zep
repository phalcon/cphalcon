
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Helper\Str;

use Phalcon\Traits\Support\Helper\Str\StartsWithTrait;

/**
 * Check if a string starts with a given string
 */
class StartsWith
{
    use StartsWithTrait;

    public function __invoke(
        string haystack,
        string needle,
        bool ignoreCase = true
    ) -> bool {
        return this->toStartsWith(haystack, needle, ignoreCase);
    }
}
