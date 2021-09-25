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

use Closure;
use Phalcon\Acl\Adapter\Memory;
use Phalcon\Acl\Component;
use Phalcon\Acl\Role;
use UnitTester;

class GetActiveFunctionCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: getActiveFunction()
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2017-01-13
     */
    public function aclAdapterMemoryGetActiveFunction(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - getActiveFunction()');

        $function = function ($a) {
            return true;
        };

        $acl = new Memory();

        $acl->addRole(
            new Role('Guests')
        );

        $acl->addComponent(
            new Component('Post'),
            ['index', 'update', 'create']
        );

        $acl->allow('Guests', 'Post', 'create', $function);

        $I->assertTrue(
            $acl->isAllowed(
                'Guests',
                'Post',
                'create',
                [
                    'a' => 1,
                ]
            )
        );


        $returnedFunction = $acl->getActiveFunction();

        $I->assertInstanceOf(
            Closure::class,
            $returnedFunction
        );


        $I->assertEquals(
            1,
            $function(1)
        );

        $I->assertEquals(
            1,
            $acl->getActiveFunctionCustomArgumentsCount()
        );
    }
}
