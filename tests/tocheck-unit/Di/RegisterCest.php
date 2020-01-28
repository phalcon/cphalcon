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

namespace Phalcon\Test\Unit\Di;

use Phalcon\Di;
use SomeComponent;
use SomeServiceProvider;
use UnitTester;

class RegisterCest
{
    /**
     * Unit Tests Phalcon\Di :: register()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-13
     */
    public function diRegister(UnitTester $I)
    {
        $I->wantToTest('Di - register()');

        require_once dataDir('fixtures/Di/SomeComponent.php');
        require_once dataDir('fixtures/Di/SomeServiceProvider.php');

        $di = new Di();

        $di->register(new SomeServiceProvider());

        $I->assertEquals('bar', $di->get('foo'));
        $I->assertInstanceOf(SomeComponent::class, $di->get('fooAction'));
    }
}
