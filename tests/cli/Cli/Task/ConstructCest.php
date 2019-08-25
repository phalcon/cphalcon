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

namespace Phalcon\Test\Cli\Cli\Task;

use CliTester;
use OnConstructTask;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class ConstructCest
{
    use DiTrait;

    public function _before(CliTester $I)
    {
        $this->setNewCliFactoryDefault();
    }

    /**
     * Tests Phalcon\Cli\Task :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliTaskConstruct(CliTester $I)
    {
        $I->wantToTest('Cli\Task - __construct()');

        $I->skipTest('Need implementation');
    }

    public function testOnConstruct(CliTester $I)
    {
        /**
         * @todo Check the loader
         */
        require_once dataDir('fixtures/tasks/OnConstructTask.php');

        $task = new OnConstructTask();

        $I->assertTrue(
            $task->onConstructExecuted
        );
    }
}
