
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Encryption\Security\JWT\Signer;

/**
 * Canonical contract for JWT Signer classes
 */
interface Signer
{
    /**
     * Return the value that is used for the "alg" header
     */
    public function getAlgHeader() -> string;

    /**
     * Return the algorithm used
     */
    public function getAlgorithm() -> string;

    /**
     * Sign a payload using the passphrase
     */
    public function sign(string payload,  string passphrase) -> string;

    /**
     * Verify a passed source with a payload and passphrase
     */
    public function verify(
        string source,
        string payload,
        string passphrase
    ) -> bool;
}
