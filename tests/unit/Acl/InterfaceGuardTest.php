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

namespace Phalcon\Tests\Unit\Acl;

use Phalcon\Acl\Adapter\AdapterInterface;
use Phalcon\Acl\Adapter\Memory;
use Phalcon\Acl\ComponentInterface;
use Phalcon\Acl\RoleInterface;
use Phalcon\Contracts\Acl\Adapter\Adapter as AdapterContract;
use Phalcon\Contracts\Acl\Component as ComponentContract;
use Phalcon\Contracts\Acl\Role as RoleContract;
use Phalcon\Tests\AbstractUnitTestCase;

final class InterfaceGuardTest extends AbstractUnitTestCase
{
    public function testLegacyInterfacesBridgeToContracts(): void
    {
        $this->assertTrue(is_subclass_of(RoleInterface::class, RoleContract::class));
        $this->assertTrue(is_subclass_of(ComponentInterface::class, ComponentContract::class));
        $this->assertTrue(is_subclass_of(AdapterInterface::class, AdapterContract::class));
        $this->assertInstanceOf(AdapterContract::class, new Memory());
    }

    public function testUserlandRoleImplementationStillSatisfiesContract(): void
    {
        // Non-null getDescription() (narrower than the contract's ?string) must
        // still satisfy the bridge + contract. A declaration failure errors here.
        $role = new class implements RoleInterface {
            public function __toString(): string
            {
                return 'admin';
            }

            public function getDescription(): string
            {
                return 'desc';
            }

            public function getName(): string
            {
                return 'admin';
            }
        };

        $this->assertInstanceOf(RoleContract::class, $role);
    }
}
