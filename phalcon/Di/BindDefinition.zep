
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Di;

class BindDefinition implements BindDefinitionInterface
{
    /**
     * @var string
     */
    protected className;

    /**
     * @var string
     */
    protected definition;

    /**
     * @var bind
     */
    protected isShared;

    public function __construct(string! className, string! definition, bool isShared = false)
    {
        let this->className = className,
            this->definition = definition,
            this->isShared = isShared;
    }

    public function getClassName() -> string
    {
        return this->className;
    }

    public function getDefinition() -> string
    {
        return this->definition;
    }

    public function isShared() -> bool
    {
        return this->isShared;
    }

    public function resolve(<DiInterface> container) -> object
    {
        if this->isShared {
            return container->getShared(this->definition);
        }

        return container->get(this->definition);
    }
}
