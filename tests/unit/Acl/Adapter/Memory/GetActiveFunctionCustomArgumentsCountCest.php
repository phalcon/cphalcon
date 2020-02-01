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
use Phalcon\Acl\Role;
use UnitTester;

class GetActiveFunctionCustomArgumentsCountCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory ::
     * getActiveFunctionCustomArgumentsCount()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryGetActiveFunctionCustomArgumentsCount(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - getActiveFunctionCustomArgumentsCount()');

        $acl = new Memory();

        $acl->addRole(new Role('member'));
        $acl->addComponent(new Component('group'), 'add');
        $acl->allow(
            'member',
            'group',
            'add',
            function ($accountType, $active) {
                if ('premium' === $accountType && true === $active) {
                    return true;
                }

                return false;
            }
        );

        $isAllowed = $acl->isAllowed(
            'member',
            'group',
            'add',
            [
                'accountType' => 'premium',
                'active'      => true,
            ]
        );

        $I->assertTrue($isAllowed);

        $I->assertEquals(
            2,
            $acl->getActiveFunctionCustomArgumentsCount()
        );
    }
}
