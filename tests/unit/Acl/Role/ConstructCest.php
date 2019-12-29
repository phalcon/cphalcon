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

namespace Phalcon\Test\Unit\Acl\Role;

use BadMethodCallException;
use Phalcon\Acl\Exception;
use Phalcon\Acl\Role;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Acl\Role :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function aclRoleConstruct(UnitTester $I)
    {
        $I->wantToTest('Acl\Role - __construct()');

        $role = new Role('Administrator');

        $I->assertInstanceOf(
            Role::class,
            $role
        );
    }

    /**
     * Tests Phalcon\Acl\Role :: __construct() - wildcard
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function aclRoleConstructWithWildcardThrowsException(UnitTester $I)
    {
        $I->wantToTest('Acl\Role - __construct() - exception with "*"');

        $I->expectThrowable(
            new Exception("Role name cannot be '*'"),
            function () {
                $role = new Role('*');
            }
        );
    }

    /**
     * Tests Phalcon\Acl\Role :: __construct() - without name
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function aclRoleConstructWithoutName(UnitTester $I)
    {
        $I->wantToTest('Acl\Role - __construct() - exception params');

        $I->expectThrowable(
            new BadMethodCallException('Wrong number of parameters'),
            function () {
                $role = new Role();
            }
        );
    }
}
