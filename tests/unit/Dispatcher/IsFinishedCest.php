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

namespace Phalcon\Test\Unit\Dispatcher;

use UnitTester;

class IsFinishedCest
{
    /**
     * Tests Phalcon\Dispatcher :: isFinished()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dispatcherIsFinished(UnitTester $I)
    {
        $I->wantToTest('Dispatcher - isFinished()');

        $I->skipTest('Need implementation');
    }
}
