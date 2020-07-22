
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Di;

interface BindDefinitionInterface
{
    /**
     * Returns class name
     */
    public function getClassName() -> string;

    /**
     * Returns definition
     */
    public function getDefinition() -> string;

    public function isShared() -> bool;

    public function resolve(<DiInterface> container) -> object;
}
