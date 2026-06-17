
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Encryption\Crypt;

use Phalcon\Contracts\Encryption\Crypt\Crypt as CryptContract;

/**
 * Interface for Phalcon\Crypt
 *
 * @psalm-suppress DeprecatedInterface
 * @deprecated Will be removed in a future major release.
 *             Use {@see \Phalcon\Contracts\Encryption\Crypt\Crypt} instead.
 */
interface CryptInterface extends CryptContract
{
}
