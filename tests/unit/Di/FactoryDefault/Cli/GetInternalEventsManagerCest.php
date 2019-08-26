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

namespace Phalcon\Test\Unit\Di\FactoryDefault\Cli;

use UnitTester;

class GetInternalEventsManagerCest
{
    /**
     * Unit Tests Phalcon\Di\FactoryDefault\Cli :: getInternalEventsManager()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-13
     */
    public function diFactoryDefaultCliGetInternalEventsManager(UnitTester $I)
    {
        $I->wantToTest('Di\FactoryDefault\Cli - getInternalEventsManager()');

        $I->skipTest('Need implementation');
    }
}
