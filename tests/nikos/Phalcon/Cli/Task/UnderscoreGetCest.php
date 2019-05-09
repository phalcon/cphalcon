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

namespace Phalcon\Test\Unit\Cli\Task;

use UnitTester;

class UnderscoreGetCest
{
    /**
     * Tests Phalcon\Cli\Task :: __get()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function cliTaskUnderscoreGet(UnitTester $I)
    {
        $I->wantToTest('Cli\Task - __get()');

        $I->skipTest('Need implementation');
    }
}
