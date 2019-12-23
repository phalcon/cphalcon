
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */


namespace Phalcon\Http\JWT\Signer;

/**
 * Class AbstractSigner
 *
 * @property string $algo
 */
abstract class AbstractSigner implements SignerInterface
{
    /**
     * @var string
     */
    protected algorithm { get };
}
