<?php

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
use Phalcon\Acl\Resource;
use UnitTester;

class IsResourceCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: isResource()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryIsResource(UnitTester $I)
    {
        $I->wantToTest("Acl\Adapter\Memory - isResource()");
        $acl         = new Memory();
        $aclResource = new Resource('Customers', 'Customer management');

        $acl->addResource($aclResource, 'search');
        $actual = $acl->isResource('Customers');
        $I->assertTrue($actual);
    }
}
