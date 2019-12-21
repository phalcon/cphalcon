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

namespace Phalcon\Test\Cli\Cli\Dispatcher;

use CliTester;
use Phalcon\Cli\Dispatcher;

class GetSetOptionsCest
{
    /**
     * Tests Phalcon\Cli\Dispatcher - getOptions() / setOptions()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliDispatcherGetOptions(CliTester $I)
    {
        $I->wantToTest('Cli\Dispatcher - getOptions() / setOptions()');
        $dispatcher = new Dispatcher();
        $I->assertEquals([], $dispatcher->getOptions());

        $options = ["Phalcon", "Rocks"];
        $dispatcher->setOptions($options);
        $I->assertEquals($options, $dispatcher->getOptions());
    }
}
