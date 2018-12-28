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

namespace Phalcon\Test\Unit\Events\Manager;

use UnitTester;

/**
 * Class FireCest
 */
class FireCest
{
    /**
     * Tests Phalcon\Events\Manager :: fire()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function eventsManagerFire(UnitTester $I)
    {
        $I->wantToTest('Events\Manager - fire()');
        $I->skipTest('Need implementation');
    }
}
