
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
use Phalcon\Traits\Support\Helper\Str\InterpolateTrait;
use Phalcon\Traits\Support\Helper\Str\LowerTrait;
use Phalcon\Traits\Support\Helper\Str\StartsWithTrait;

/**
 * Abstract class offering methods to help with the Str namespace. This can
 * be moved to a trait once Zephir supports it.
 *
 * This base exists only for the `Str` helper hierarchy; it is not a general
 * base class. New code that needs these routines should compose the relevant
 * invokable helper (for example `Str\Interpolate`) rather than extending it.
 *
 * @internal
 *
 * @todo move to trait when there is support for it
 */
abstract class AbstractStr
{
    use EndsWithTrait;
    use InterpolateTrait;
    use LowerTrait;
    use StartsWithTrait;

    /**
     * Uppercases a string using mbstring
     *
     * @param string $text
     * @param string $encoding
     *
     * @return string
     */
    protected function toUpper(
        string text,
        string encoding = "UTF-8"
    ) -> string {
        return mb_convert_case(text, MB_CASE_UPPER, encoding);
    }
}
