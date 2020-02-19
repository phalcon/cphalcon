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

namespace Phalcon\Test\Unit\Events\Event;

use Phalcon\Events\Event;
use UnitTester;

class IsStrictCest
{
    /**
     * Tests Phalcon\Events\Event :: isStrict()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-20
     */
    public function eventsEventIsStrict(UnitTester $I)
    {
        $I->wantToTest('Events\Event - isStrict()');


        $event = new Event(
            'some-type:beforeSome',
            $this,
            []
        );

        $I->assertFalse(
            $event->isStrict()
        );


        $event = new Event(
            'some-type:beforeSome',
            $this,
            [],
            false,
            true
        );

        $I->assertTrue(
            $event->isStrict()
        );
    }
}
