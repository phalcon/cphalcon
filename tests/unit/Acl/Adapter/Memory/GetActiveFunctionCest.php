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

/**
 * Class GetActiveFunctionCest
 *
 * @package Phalcon\Tests\Unit\Acl\Adapter\Memory
 */
class GetActiveFunctionCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: getActiveFunction()
     *
     * @param UnitTester $I
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
        $acl->addRole(new Role('Guests'));
        $acl->addComponent(
            new Component('Post'),
            ['index', 'update', 'create']
        );

        $acl->allow('Guests', 'Post', 'create', $function);

        $actual = $acl->isAllowed(
            'Guests',
            'Post',
            'create',
            [
                'a' => 1,
            ]
        );
        $I->assertTrue($actual);

        $returnedFunction = $acl->getActiveFunction();

        $class  = Closure::class;
        $actual = $returnedFunction;
        $I->assertInstanceOf($class, $actual);

        $expected = 1;
        $actual   = $function(1);
        $I->assertEquals($expected, $actual);

        $expected = 1;
        $actual   = $acl->getActiveFunctionCustomArgumentsCount();
        $I->assertEquals($expected, $actual);
    }
}
