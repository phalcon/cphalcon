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

namespace Phalcon\Test\Cli\Cli\Task;

use CliTester;
use Phalcon\Cli\Task;
use Phalcon\Di\FactoryDefault\Cli as CliDi;

class GetSetDICest
{
    /**
     * Tests Phalcon\Cli\Task :: getDI() / setDI()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliTaskGetSetDI(CliTester $I)
    {
        $I->wantToTest('Cli\Task - getDI() / setDI()');

        $task = new Task();
        $di   = new CliDi();
        $task->setDi($di);

        $I->assertEquals($di, $task->getDi());
    }
}
