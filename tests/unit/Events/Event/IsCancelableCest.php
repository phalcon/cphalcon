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

class IsCancelableCest
{
    /**
     * Tests Phalcon\Events\Event :: isCancelable()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-20
     */
    public function eventsEventIsCancelable(UnitTester $I)
    {
        $I->wantToTest('Events\Event - isCancelable()');


        $event = new Event(
            'some-type:beforeSome',
            $this,
            []
        );

        $I->assertTrue(
            $event->isCancelable()
        );


        $event = new Event(
            'some-type:beforeSome',
            $this,
            [],
            false
        );

        $I->assertFalse(
            $event->isCancelable()
        );


        $event = new Event(
            'some-type:beforeSome',
            $this,
            [],
            true
        );

        $I->assertTrue(
            $event->isCancelable()
        );
    }
}
