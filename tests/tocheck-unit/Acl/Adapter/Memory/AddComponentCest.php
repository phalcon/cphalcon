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

namespace Phalcon\Test\Unit\Acl\Adapter\Memory;

use Phalcon\Acl\Adapter\Memory;
use Phalcon\Acl\Component;
use UnitTester;

class AddComponentCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addComponent() - string
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryAddComponentString(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addComponent() - string');

        $acl = new Memory();

        $component = new Component('Customer', 'Customer component');

        $actual = $acl->addComponent(
            'Customer',
            ['index']
        );

        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addComponent() - object
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryAddComponentObject(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addComponent() - object');

        $acl = new Memory();

        $component = new Component('Customer', 'Customer component');

        $actual = $acl->addComponent(
            $component,
            ['index']
        );

        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addComponent() - numeric key
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryAddComponentNumericKey(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addComponent() - numeric key');

        $acl = new Memory();

        $component = new Component('11', 'Customer component');

        $actual = $acl->addComponent(
            $component,
            ['index']
        );

        $I->assertTrue($actual);

        $I->assertTrue(
            $acl->isComponent('11')
        );
    }
}
