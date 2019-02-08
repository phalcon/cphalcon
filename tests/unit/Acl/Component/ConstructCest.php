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

namespace Phalcon\Test\Unit\Acl\Component;

use BadMethodCallException;
use Phalcon\Acl\Exception;
use Phalcon\Acl\Component;
use UnitTester;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Acl\Component :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclComponentConstruct(UnitTester $I)
    {
        $I->wantToTest('Acl\Component - __construct()');
        $actual = new Component('Customers');

        $class = Component::class;
        $I->assertInstanceOf($class, $actual);
    }

    /**
     * Tests Phalcon\Acl\Component :: __construct() - wildcard
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclComponentConstructWithWildcardThrowsException(UnitTester $I)
    {
        $I->wantToTest('Acl\Component - __construct() - exception with "*"');
        $I->expectThrowable(
            new Exception("Component name cannot be '*'"),
            function () {
                $component = new Component('*');
            }
        );
    }

    /**
     * Tests Phalcon\Acl\Component :: __construct() - without name
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclComponentConstructWithoutName(UnitTester $I)
    {
        $I->wantToTest('Acl\Component - __construct() - exception parameters');
        $I->expectThrowable(
            new BadMethodCallException('Wrong number of parameters'),
            function () {
                $component = new Component();
            }
        );
    }
}
