<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Acl\Adapter\Memory;

use Phalcon\Acl\Adapter\Memory;
use Phalcon\Acl\Exception;
use Phalcon\Acl\Exceptions\ForbiddenDelimiter;
use Phalcon\Acl\Role;
use Phalcon\Acl\RoleInterface;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class AddRoleTest extends AbstractUnitTestCase
{
    /**
     * A custom RoleInterface cannot give a name with the "!" delimiter.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17800
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-26
     */
    public function testAclAdapterMemoryAddRoleCustomNameWithDelimiter(): void
    {
        $role = new class () implements RoleInterface {
            public function __toString(): string
            {
                return 'Admins!Guests';
            }

            public function getDescription(): string | null
            {
                return null;
            }

            public function getName(): string
            {
                return 'Admins!Guests';
            }
        };

        $this->expectException(ForbiddenDelimiter::class);
        $this->expectExceptionMessage("The role name cannot contain '!'");

        (new Memory())->addRole($role);
    }

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
