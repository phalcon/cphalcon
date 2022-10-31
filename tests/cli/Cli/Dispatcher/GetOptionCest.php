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

namespace Phalcon\Tests\Cli\Cli\Dispatcher;

use CliTester;
use Phalcon\Cli\Dispatcher;
use Phalcon\Di\FactoryDefault\Cli as DiFactoryDefault;

/**
 * Class GetOptionCest
 */
class GetOptionCest
{
    /**
     * Tests Phalcon\Cli\Dispatcher :: getOption()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliDispatcherGetOption(CliTester $I)
    {
        $I->wantToTest('Cli\Dispatcher - getOption()');
        $container  = new DiFactoryDefault();
        $dispatcher = new Dispatcher();
        $dispatcher->setDi($container);
        $options = [
            "phalcon" => "value123!",
        ];

        $dispatcher->setOptions($options);
        $optionName   = "phalcon";
        $defaultValue = "Phalcon Rocks!";

        $expected = $options[$optionName];
        $actual   = $dispatcher->getOption($optionName);
        $I->assertSame($expected, $actual);

        $expected = $options[$optionName];
        $actual   = $dispatcher->getOption($optionName, '', $defaultValue);
        $I->assertSame($expected, $actual);

        $expected = $defaultValue;
        $actual   = $dispatcher->getOption('nonExisting', '', $defaultValue);
        $I->assertSame($expected, $actual);

        $expected = 'value123';
        $actual   = $dispatcher->getOption($optionName, 'alnum');
        $I->assertSame($expected, $actual);

        $expected = 123;
        $actual   = $dispatcher->getOption($optionName, ['int']);
        $I->assertSame($expected, $actual);
    }
}
