
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Translate\Interpolator;

class IndexedArray implements InterpolatorInterface
{
    /**
     * Replaces placeholders by the values passed
     *
     * @phpstan-param array<string, string> $placeholders
     */
    public function replacePlaceholders(
         string translation,
        array placeholders = []
    ) -> string {
        if true !== empty(placeholders) {
            /**
             * vsprintf() treats the translation as a format string. When the
             * translation is a fallback (e.g. a missing, possibly
             * request-derived key) its format specifiers may not match the
             * given arguments, which would raise a ValueError. Return the
             * translation unchanged in that case so a crafted key cannot turn
             * into a format-string error / DoS (CWE-134).
             */
            try {
                return vsprintf(translation, placeholders);
            } catch \ValueError {
                return translation;
            }
        }

        return translation;
    }
}
