
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Encryption\Security\JWT\Signer;

use Phalcon\Contracts\Encryption\Security\JWT\Signer\Signer as SignerContract;

/**
 * Interface for JWT Signer classes
 *
 * @psalm-suppress DeprecatedInterface
 * @deprecated Will be removed in a future major release.
 *             Use {@see \Phalcon\Contracts\Encryption\Security\JWT\Signer\Signer} instead.
 */
interface SignerInterface extends SignerContract
{
}
