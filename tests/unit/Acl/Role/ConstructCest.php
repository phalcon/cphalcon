<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Acl\Role;

use BadMethodCallException;
use Phalcon\Acl\Exception;
use Phalcon\Acl\Role;
use UnitTester;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Acl\Role :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclRoleConstruct(UnitTester $I)
    {
        $I->wantToTest('Acl\Role - __construct()');
        $actual = new Role('Administrator');

        $class = Role::class;
        $I->assertInstanceOf($class, $actual);
    }

    /**
     * Tests Phalcon\Acl\Role :: __construct() - wildcard
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
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
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
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
