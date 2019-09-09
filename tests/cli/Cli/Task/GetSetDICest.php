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

        $I->skipTest('Need implementation');
    }
}
