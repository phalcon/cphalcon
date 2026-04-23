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

namespace Phalcon\Tests\Unit\Acl\Fake;

use Phalcon\Acl\ComponentAwareInterface;

class TestComponentAware implements ComponentAwareInterface
{
    /**
     * @param int    $user
     * @param string $resourceName
     */
    public function __construct(
        protected int $user,
        protected string $resourceName
    ) {
    }

    public function getComponentName(): string
    {
        return $this->resourceName;
    }

    /**
     * @return int
     */
    public function getUser(): int
    {
        return $this->user;
    }
}
