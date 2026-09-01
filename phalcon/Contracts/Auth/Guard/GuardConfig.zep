
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

namespace Phalcon\Contracts\Auth\Guard;

/**
 * Authentication guard configuration contract.
 *
 * Per-guard config shape is intentionally guard-specific (e.g. Token exposes
 * getInputKey()/getStorageKey(); Session has no required config today).
 * The contract carries no methods of its own - it only marks the type so
 * AbstractGuard can accept any guard config uniformly.
 */
interface GuardConfig
{
}
