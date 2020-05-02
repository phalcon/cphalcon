
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Helper\Input;

/**
 * Class Input
 */
class Input extends AbstractInput
{
    /**
     * Sets the type of the input
     *
     * @param string $type
     *
     * @return AbstractInput
     */
    public function setType(string type) -> <AbstractInput>
    {
        let this->type = type;

        return this;
    }
}
