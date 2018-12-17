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

namespace Phalcon\Test\Unit\Acl\Subject;

use BadMethodCallException;
use Phalcon\Acl\Exception;
use Phalcon\Acl\Subject;
use UnitTester;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Acl\Subject :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclSubjectConstruct(UnitTester $I)
    {
        $I->wantToTest('Acl\Subject - __construct()');
        $actual = new Subject('Customers');

        $class = Subject::class;
        $I->assertInstanceOf($class, $actual);
    }

    /**
     * Tests Phalcon\Acl\Subject :: __construct() - wildcard
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclSubjectConstructWithWildcardThrowsException(UnitTester $I)
    {
        $I->wantToTest('Acl\Subject - __construct() - exception with "*"');
        $I->expectThrowable(
            new Exception("Subject name cannot be '*'"),
            function () {
                $resource = new Subject('*');
            }
        );
    }

    /**
     * Tests Phalcon\Acl\Subject :: __construct() - without name
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclSubjectConstructWithoutName(UnitTester $I)
    {
        $I->wantToTest('Acl\Subject - __construct() - exception parameters');
        $I->expectThrowable(
            new BadMethodCallException('Wrong number of parameters'),
            function () {
                $resource = new Subject();
            }
        );
    }
}
