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
 * Class UnderscoreGetCest
 */
class UnderscoreGetCest
{
    /**
     * Tests Phalcon\Cli\Task :: __get()
     *
     * @param CliTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cliTaskUnderscoreGet(CliTester $I)
    {
        $I->wantToTest('Cli\Task - __get()');
        $I->skipTest('Need implementation');
    }
}
