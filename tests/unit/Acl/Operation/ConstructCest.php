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

namespace Phalcon\Test\Unit\Acl\Operation;

use BadMethodCallException;
use Phalcon\Acl\Exception;
use Phalcon\Acl\Operation;
use UnitTester;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Acl\Operation :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclOperationConstruct(UnitTester $I)
    {
        $I->wantToTest('Acl\Operation - __construct()');
        $actual = new Operation('Administrator');

        $class = Operation::class;
        $I->assertInstanceOf($class, $actual);
    }

    /**
     * Tests Phalcon\Acl\Operation :: __construct() - wildcard
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclOperationConstructWithWildcardThrowsException(UnitTester $I)
    {
        $I->wantToTest('Acl\Operation - __construct() - exception with "*"');
        $I->expectThrowable(
            new Exception("Operation name cannot be '*'"),
            function () {
                $operation = new Operation('*');
            }
        );
    }

    /**
     * Tests Phalcon\Acl\Operation :: __construct() - without name
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclOperationConstructWithoutName(UnitTester $I)
    {
        $I->wantToTest('Acl\Operation - __construct() - exception params');
        $I->expectThrowable(
            new BadMethodCallException('Wrong number of parameters'),
            function () {
                $operation = new Operation();
            }
        );
    }
}
