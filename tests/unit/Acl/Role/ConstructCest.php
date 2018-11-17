<?php

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

class ConstructCest
{
    /**
     * Tests Phalcon\Acl\Role :: __construct()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testConstruct(UnitTester $I)
    {
        $actual = new Role('Administrator');

        $class = Role::class;
        $I->assertInstanceOf($class, $actual);
    }

    /**
     * Tests Phalcon\Acl\Role :: __construct() - wildcard
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testConstructWithWildcardThrowsException(UnitTester $I)
    {
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
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testConstructWithoutName(UnitTester $I)
    {
        $I->expectThrowable(
            new BadMethodCallException('Wrong number of parameters'),
            function () {
                $role = new Role();
            }
        );
    }
}
