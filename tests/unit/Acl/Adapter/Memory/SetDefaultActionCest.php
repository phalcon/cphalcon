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
use UnitTester;

class SetDefaultActionCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: setDefaultAction()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemorySetDefaultAction(UnitTester $I)
    {
        $I->wantToTest("Acl\Adapter\Memory - setDefaultAction()");
        $acl = new Memory();

        $acl->setDefaultAction(Acl::ALLOW);

        $expected = Acl::ALLOW;
        $actual   = $acl->getDefaultAction();
        $I->assertEquals($expected, $actual);
    }
}
