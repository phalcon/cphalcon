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

namespace Phalcon\Test\Unit\Events\Event;

use UnitTester;

/**
 * Class GetSourceCest
 */
class GetSourceCest
{
    /**
     * Tests Phalcon\Events\Event :: getSource()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function eventsEventGetSource(UnitTester $I)
    {
        $I->wantToTest('Events\Event - getSource()');
        $I->skipTest('Need implementation');
    }
}
