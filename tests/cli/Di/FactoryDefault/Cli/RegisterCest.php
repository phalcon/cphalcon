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

namespace Phalcon\Tests\Cli\Di\FactoryDefault\Cli;

use CliTester;
use Phalcon\Di\FactoryDefault\Cli as Di;
use SomeComponent;
use SomeServiceProvider;

class RegisterCest
{
    /**
     * Tests Phalcon\Di\FactoryDefault\Cli :: register()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function diFactorydefaultCliRegister(CliTester $I)
    {
        $I->wantToTest('Di\FactoryDefault\Cli - register()');

        require_once dataDir('fixtures/Di/SomeComponent.php');
        require_once dataDir('fixtures/Di/SomeServiceProvider.php');

        $di = new Di();

        $di->register(new SomeServiceProvider());

        $I->assertEquals('bar', $di->get('foo'));
        $I->assertInstanceOf(SomeComponent::class, $di->get('fooAction'));
    }
}
