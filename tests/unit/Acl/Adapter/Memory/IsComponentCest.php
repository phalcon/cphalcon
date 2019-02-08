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

use Phalcon\Acl\Adapter\Memory;
use Phalcon\Acl\Component;
use UnitTester;

/**
 * Class IsComponentCest
 */
class IsComponentCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: isComponent()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryIsComponent(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - isComponent()');
        $acl        = new Memory();
        $aclComponent = new Component('Customers', 'Customer management');

        $acl->addComponent($aclComponent, 'search');
        $actual = $acl->isComponent('Customers');
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: isComponent() - unknown
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryIsComponentUnknown(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - isComponent() - unknown');
        $acl        = new Memory();
        $aclComponent = new Component('Customers', 'Customer management');

        $acl->addComponent($aclComponent, 'search');
        $actual = $acl->isComponent('unknown');
        $I->assertFalse($actual);
    }
}
