
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */

namespace Phalcon\Contracts\Auth\Adapter;

/**
 * Authentication adapter configuration contract.
 *
 * Per-adapter config shape is intentionally adapter-specific (e.g. Stream
 * exposes getFile(), Memory exposes getUsers()); the only field shared across
 * all adapters is the optional model class used during user hydration.
 */
interface AdapterConfig
{
    /**
     * Returns the user-model class name to hydrate, if configured.
     */
    public function getModel() -> string | null;
}
