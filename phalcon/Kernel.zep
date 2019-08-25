
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon;

/**
 * This class allows to change the internal behavior of the framework in runtime
 */
class Kernel
{
    /**
     * Produces a pre-computed hash key based on a string. This function
     * produces different numbers in 32bit/64bit processors
     *
     * @return string
     */
    public static function preComputeHashKey(string! key)
    {
        %{

        {

        RETURN_MM_NULL();

        }

        }%
    }
}
