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

class ToStringCest
{
    /**
     * Tests Phalcon\Acl\Resource :: __toString()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclResourceToString(UnitTester $I)
    {
        $I->wantToTest("Acl\Resource - __toString()");
        $resource = new Resource('Customers');

        $expected = 'Customers';
        $actual   = $resource->__toString();
        $I->assertEquals($expected, $actual);
    }
}
