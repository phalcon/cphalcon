
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */


namespace Phalcon\Encryption\Security\JWT\Signer;

/**
 * Abstract class helping with the signer classes
 */
abstract class AbstractSigner implements SignerInterface
{
    /**
     * @var string
     */
    protected algorithm = "";

    public function getAlgorithm() -> string
    {
        return this->algorithm;
    }
}
