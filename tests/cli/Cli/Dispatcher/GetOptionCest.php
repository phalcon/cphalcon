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
        $di         = new DiFactoryDefault();
        $dispatcher = new Dispatcher();
        $dispatcher->setDi($di);
        $options = [
            "phalcon" => "value123!",
        ];

        $dispatcher->setOptions($options);
        $optionName   = "phalcon";
        $defaultValue = "Phalcon Rocks!";
        $I->assertEquals($options[$optionName], $dispatcher->getOption($optionName));
        $I->assertEquals($options[$optionName], $dispatcher->getOption($optionName, '', $defaultValue));
        $I->assertEquals($defaultValue, $dispatcher->getOption('nonExisting', '', $defaultValue));

        $I->assertSame('value123', $dispatcher->getOption($optionName, 'alnum'));
        $I->assertSame(123, $dispatcher->getOption($optionName, ['int']));
    }
}
