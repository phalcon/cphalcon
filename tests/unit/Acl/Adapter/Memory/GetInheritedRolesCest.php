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
use Phalcon\Acl\Component;
use Phalcon\Acl\Exception;
use Phalcon\Acl\Role;
use UnitTester;

/**
 * Class GetInheritedRolesCest
 *
 * @package Phalcon\Tests\Unit\Acl\Adapter\Memory
 */
class GetInheritedRolesCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: getInheritedRoles()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-02
     * @issue  https://github.com/phalcon/cphalcon/issues/15154
     */
    public function aclAdapterMemoryGetInheritedRoles(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - getInheritedRoles()');

        $acl = new Memory();

        $acl->addRole(new Role('administrator'));
        $acl->addRole(new Role('memberOne'));
        $acl->addRole(new Role('memberTwo'));
        $acl->addRole(new Role('guestOne'));
        $acl->addRole(new Role('guestTwo'));

        /**
         * Inheritance
         */
        $actual = $acl->addInherit('administrator', 'memberOne');
        $I->assertTrue($actual);
        $actual = $acl->addInherit('administrator', 'memberTwo');
        $I->assertTrue($actual);
        $actual = $acl->addInherit('memberTwo', 'guestOne');
        $I->assertTrue($actual);
        $actual = $acl->addInherit('memberTwo', 'guestTwo');
        $I->assertTrue($actual);

        $expected = [];
        $actual   = $acl->getInheritedRoles('unknown');
        $I->assertEquals($expected, $actual);

        $expected = [
            'memberOne',
            'memberTwo',
        ];
        $actual   = $acl->getInheritedRoles('administrator');
        $I->assertEquals($expected, $actual);

        $expected = [
            'administrator' => [
                'memberOne',
                'memberTwo',
            ],
            'memberTwo'      => [
                'guestOne',
                'guestTwo',
            ],
        ];
        $actual   = $acl->getInheritedRoles();
        $I->assertEquals($expected, $actual);
    }
}
