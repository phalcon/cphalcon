<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Cli\Cli\Task;

use CliTester;

/**
 * Class GetDICest
 */
class GetDICest
{
    /**
     * Tests Phalcon\Cli\Task :: getDI()
     *
     * @param CliTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cliTaskGetDI(CliTester $I)
    {
        $I->wantToTest('Cli\Task - getDI()');
        $I->skipTest('Need implementation');
    }
}
