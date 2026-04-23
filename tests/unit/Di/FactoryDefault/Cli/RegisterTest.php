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

namespace Phalcon\Tests\Unit\Di\FactoryDefault\Cli;

use Phalcon\Di\FactoryDefault\Cli as Di;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Di\SomeComponent;
use Phalcon\Tests\Support\Di\SomeServiceProvider;

final class RegisterTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDiFactorydefaultCliRegister(): void
    {
        require_once supportDir('Di/SomeComponent.php');
        require_once supportDir('Di/SomeServiceProvider.php');

        $di = new Di();

        $di->register(new SomeServiceProvider());

        $expected = 'bar';
        $actual   = $di->get('foo');
        $this->assertEquals($expected, $actual);
        $this->assertInstanceOf(SomeComponent::class, $di->get('fooAction'));
    }
}
