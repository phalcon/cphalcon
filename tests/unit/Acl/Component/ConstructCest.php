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

namespace Phalcon\Test\Unit\Acl\Component;

use ArgumentCountError;
use BadMethodCallException;
use Phalcon\Acl\Component;
use Phalcon\Acl\Exception;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Acl\Component :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function aclComponentConstruct(UnitTester $I)
    {
        $I->wantToTest('Acl\Component - __construct()');

        $component = new Component('Customers');

        $I->assertInstanceOf(
            Component::class,
            $component
        );
    }

    /**
     * Tests Phalcon\Acl\Component :: __construct() - wildcard
     *
     * @author Phalcon Team <team@phalcon.io>
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function aclComponentConstructWithoutName(UnitTester $I)
    {
        $I->wantToTest('Acl\Component - __construct() - exception parameters');

        if (version_compare(PHP_VERSION, '8.0.0', '>=')) {
            $I->expectThrowable(
                new ArgumentCountError('Phalcon\Acl\Component::__construct() expects at least 1 argument, 0 given'),
                function () {
                    $component = new Component();
                }
            );
        } else {
            $I->expectThrowable(
                new BadMethodCallException('Wrong number of parameters'),
                function () {
                    $component = new Component();
                }
            );
        }
    }
}
