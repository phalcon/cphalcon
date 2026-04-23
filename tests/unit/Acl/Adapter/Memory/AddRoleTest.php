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
use Phalcon\Acl\Exception;
use Phalcon\Acl\Role;
use Phalcon\Tests\AbstractUnitTestCase;

final class AddRoleTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testAclAdapterMemoryAddRoleException(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Role must be either a string or implement RoleInterface'
        );

        $acl = new Memory();
        $acl->addRole(true);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testAclAdapterMemoryAddRoleNumericKey(): void
    {
        $acl = new Memory();

        $actual = $acl->addRole('11');
        $this->assertTrue($actual);

        $actual = $acl->isRole('11');
        $this->assertTrue($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testAclAdapterMemoryAddRoleObject(): void
    {
        $acl  = new Memory();
        $role = new Role('Administrators', 'Super User access');

        $actual = $acl->addRole($role);
        $this->assertTrue($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testAclAdapterMemoryAddRoleString(): void
    {
        $acl = new Memory();

        $actual = $acl->addRole('Administrators');
        $this->assertTrue($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testAclAdapterMemoryAddRoleTwiceObject(): void
    {
        $acl  = new Memory();
        $role = new Role('Administrators', 'Super User access');

        $actual = $acl->addRole($role);
        $this->assertTrue($actual);

        $actual = $acl->addRole($role);
        $this->assertFalse($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testAclAdapterMemoryAddRoleTwiceString(): void
    {
        $acl = new Memory();

        $actual = $acl->addRole('Administrators');
        $this->assertTrue($actual);

        $actual = $acl->addRole('Administrators');
        $this->assertFalse($actual);
    }
}
