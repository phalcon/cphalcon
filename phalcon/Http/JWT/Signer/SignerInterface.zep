
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Http\JWT\Signer;

interface SignerInterface
{
    /**
     * Return the value that is used for the "alg" header
     *
     * @return string
     */
    public function getAlgHeader() -> string;

    /**
     * Return the algorithm used
     *
     * @return string
     */
    public function getAlgorithm() -> string;

    /**
     * Sign a payload using the passphrase
     *
     * @param string $payload
     * @param string $passphrase
     *
     * @return string
     */
    public function sign(string! payload, string! passphrase) -> string;

    /**
     * Verify a passed source with a payload and passphrase
     *
     * @param string $source
     * @param string $payload
     * @param string $passphrase
     *
     * @return bool
     */
    public function verify(string! source, string! payload, string! passphrase) -> bool;
}
