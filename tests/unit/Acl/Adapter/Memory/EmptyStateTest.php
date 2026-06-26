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

namespace Phalcon\Tests\Unit\Acl\Adapter\Memory;

use Phalcon\Acl\Adapter\Memory;
use Phalcon\Tests\AbstractUnitTestCase;

final class EmptyStateTest extends AbstractUnitTestCase
{
    public function testFreshAdapterReturnsEmptyArraysNotNull(): void
    {
        $acl = new Memory();

        $this->assertSame([], $acl->getRoles());
        $this->assertSame([], $acl->getComponents());
        $this->assertSame([], $acl->getInheritedRoles());
    }
}
