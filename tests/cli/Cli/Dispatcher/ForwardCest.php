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

/**
 * Class ForwardCest
 */
class ForwardCest
{
    /**
     * Tests Phalcon\Cli\Dispatcher :: forward()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliDispatcherForward(CliTester $I)
    {
        $I->wantToTest('Cli\Dispatcher - forward()');

        $dispatcher = new Dispatcher();
        $dispatcher->setDefaultNamespace('Phalcon\Test\Fixtures\Tasks');
        $dispatcher->setActionName('hello');
        $dispatcher->forward(
            [
                'action' => 'phalcon',
            ]
        );

        $I->assertEquals(
            'phalcon',
            $dispatcher->getActionName()
        );
    }
}
