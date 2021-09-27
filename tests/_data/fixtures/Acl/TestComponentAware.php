<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Fixtures\Acl;

use Phalcon\Acl\ComponentAwareInterface;

/**
 * Class TestComponentAware
 *
 * @property int    $user
 * @property string $resourceName
 */
class TestComponentAware implements ComponentAwareInterface
{
    /**
     * @var int
     */
    protected int $user;

    /**
     * @var string
     */
    protected string $resourceName;

    /**
     * TestComponentAware constructor.
     *
     * @param string $user
     * @param string $resourceName
     */
    public function __construct(int $user, string $resourceName)
    {
        $this->user         = $user;
        $this->resourceName = $resourceName;
    }

    /**
     * @return int
     */
    public function getUser(): int
    {
        return $this->user;
    }

    public function getComponentName(): string
    {
        return $this->resourceName;
    }
}
