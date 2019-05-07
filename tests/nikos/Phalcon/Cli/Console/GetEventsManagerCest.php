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

namespace Phalcon\Test\Unit\Cli\Console;

use UnitTester;

class GetEventsManagerCest
{
    /**
     * Tests Phalcon\Cli\Console :: getEventsManager()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function cliConsoleGetEventsManager(UnitTester $I)
    {
        $I->wantToTest('Cli\Console - getEventsManager()');

        $I->skipTest('Need implementation');
    }
}
