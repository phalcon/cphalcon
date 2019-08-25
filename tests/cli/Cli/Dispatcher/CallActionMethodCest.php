<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Cli\Cli\Dispatcher;

use CliTester;
use function dataDir;
use MainTask;
use Phalcon\Cli\Dispatcher;

class CallActionMethodCest
{
    /**
     * Tests Phalcon\Cli\Dispatcher :: callActionMethod()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-24
     */
    public function cliDispatcherCallActionMethod(CliTester $I)
    {
        $I->wantToTest('Cli\Dispatcher - callActionMethod()');

        require_once dataDir('fixtures/tasks/MainTask.php');

        $dispatcher = new Dispatcher();

        $task = new MainTask();

        $returnedValue = $dispatcher->callActionMethod(
            $task,
            'helloAction',
            [
                'Sid',
                '.',
            ]
        );

        $I->assertEquals(
            'Hello Sid.',
            $returnedValue
        );
    }
}
