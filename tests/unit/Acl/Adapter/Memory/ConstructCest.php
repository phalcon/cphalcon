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

namespace Phalcon\Test\Unit\Acl\Adapter\Memory;

use Phalcon\Acl;
use Phalcon\Acl\Adapter\Memory;
use UnitTester;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: __construct() - constants
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryConstructConstants(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - __construct() - constants');
        $I->assertEquals(1, Acl::ALLOW);
        $I->assertEquals(0, Acl::DENY);
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryConstruct(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - __construct()');
        $acl = new Memory();

        $class = Memory::class;
        $I->assertInstanceOf($class, $acl);
    }
}
