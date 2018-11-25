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

use Phalcon\Acl\Resource;
use UnitTester;

class GetDescriptionCest
{
    /**
     * Tests Phalcon\Acl\Resource :: getDescription()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclResourceGetDescription(UnitTester $I)
    {
        $I->wantToTest("Acl\Resource - getDescription()");
        $resource = new Resource('Customers', 'Customer management');

        $expected = 'Customer management';
        $actual   = $resource->getDescription();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Acl\Resource :: getDescription() - empty
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclResourceGetDescriptionEmpty(UnitTester $I)
    {
        $I->wantToTest("Acl\Resource - getDescription() - empty");
        $resource = new Resource('Customers');

        $actual = $resource->getDescription();
        $I->assertEmpty($actual);
    }
}
