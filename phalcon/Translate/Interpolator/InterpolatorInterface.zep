
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Translate\Interpolator;

/**
 * Phalcon\Translate\InterpolatorInterface
 *
 * Interface for Phalcon\Translate interpolators
 */
interface InterpolatorInterface
{
    /**
     * Replaces placeholders by the values passed
     *
     * @param string                   $translation
     * @param array<int|string, mixed> $placeholders
     *
     * @return string
     */
    public function replacePlaceholders(
        string! translation,
        array placeholders = []
    ) -> string;
}
