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

namespace Phalcon\Tests\Unit\Acl\Adapter\Memory;

use Phalcon\Acl\Adapter\Memory;
use Phalcon\Acl\Component;
use UnitTester;

/**
 * Class IsComponentCest
 *
 * @package Phalcon\Tests\Unit\Acl\Adapter\Memory
 */
class IsComponentCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: isComponent()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryIsComponent(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - isComponent()');

        $acl          = new Memory();
        $aclComponent = new Component('Customers', 'Customer management');

        $acl->addComponent($aclComponent, 'search');

        $I->assertTrue($acl->isComponent('Customers'));
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: isComponent() - unknown
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryIsComponentUnknown(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - isComponent() - unknown');

        $acl          = new Memory();
        $aclComponent = new Component('Customers', 'Customer management');

        $acl->addComponent($aclComponent, 'search');

        $I->assertFalse($acl->isComponent('unknown'));
    }
}
