
/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

namespace Phalcon\Html;

/**
 * Class EscaperFactory
 */
class EscaperFactory
{
    /**
     * Create a new instance of the object
     *
     * @return Escaper
     */
    public function newInstance() -> <Escaper>
    {
        return new Escaper();
    }
}
