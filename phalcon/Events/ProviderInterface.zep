
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Events;

/**
 * Phalcon\Events\ProviderInterface
 *
 * Interface for Phalcon\Events providers.
 */
interface ProviderInterface
{
    public function getListeners() -> array;

    public function getOptions() -> array;
}
