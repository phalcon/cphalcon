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
use Phalcon\Acl\Role;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetInheritedRolesTest extends AbstractUnitTestCase
{
    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/15154
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-02
     */
    public function testAclAdapterMemoryGetInheritedRoles(): void
    {
        $acl = new Memory();

        $acl->addRole(new Role('administrator'));
        $acl->addRole(new Role('memberOne'));
        $acl->addRole(new Role('memberTwo'));
        $acl->addRole(new Role('guestOne'));
        $acl->addRole(new Role('guestTwo'));

        $actual = $acl->addInherit('administrator', 'memberOne');
        $this->assertTrue($actual);
        $actual = $acl->addInherit('administrator', 'memberTwo');
        $this->assertTrue($actual);
        $actual = $acl->addInherit('memberTwo', 'guestOne');
        $this->assertTrue($actual);
        $actual = $acl->addInherit('memberTwo', 'guestTwo');
        $this->assertTrue($actual);

        $expected = [];
        $actual   = $acl->getInheritedRoles('unknown');
        $this->assertSame($expected, $actual);

        $expected = [
            'memberOne',
            'memberTwo',
        ];
        $actual   = $acl->getInheritedRoles('administrator');
        $this->assertSame($expected, $actual);

        $expected = [
            'administrator' => [
                'memberOne',
                'memberTwo',
            ],
            'memberTwo'     => [
                'guestOne',
                'guestTwo',
            ],
        ];
        $actual   = $acl->getInheritedRoles();
        $this->assertSame($expected, $actual);
    }
}
