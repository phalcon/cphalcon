<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Acl\Resource;

use BadMethodCallException;
use Phalcon\Acl\Exception;
use Phalcon\Acl\Resource;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Acl\Resource :: __construct()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testConstruct(UnitTester $I)
    {
        $actual = new Resource('Customers');

        $class = Resource::class;
        $I->assertInstanceOf($class, $actual);
    }

    /**
     * Tests Phalcon\Acl\Resource :: __construct() - wildcard
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testConstructWithWildcardThrowsException(UnitTester $I)
    {
        $I->expectThrowable(
            new Exception("Resource name cannot be '*'"),
            function () {
                $resource = new Resource('*');
            }
        );
    }

    /**
     * Tests Phalcon\Acl\Resource :: __construct() - without name
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testConstructWithoutName(UnitTester $I)
    {
        $I->expectThrowable(
            new BadMethodCallException('Wrong number of parameters'),
            function () {
                $resource = new Resource();
            }
        );
    }
}
