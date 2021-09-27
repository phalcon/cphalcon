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

namespace Phalcon\Tests\Unit\Acl\Component;

use Phalcon\Acl\Component;
use Phalcon\Acl\Exception;
use UnitTester;

/**
 * Class ConstructCest
 *
 * @package Phalcon\Tests\Unit\Acl\Component
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Acl\Component :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function aclComponentConstruct(UnitTester $I)
    {
        $I->wantToTest('Acl\Component - __construct()');

        $component = new Component('Customers');

        $I->assertInstanceOf(Component::class, $component);
    }

    /**
     * Tests Phalcon\Acl\Component :: __construct() - wildcard
     *
     * @param UnitTester $I
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
}
