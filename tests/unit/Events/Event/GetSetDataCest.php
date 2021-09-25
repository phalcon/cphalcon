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

namespace Phalcon\Tests\Unit\Events\Event;

use Phalcon\Events\Event;
use UnitTester;

class GetSetDataCest
{
    /**
     * Tests Phalcon\Events\Event - getData() when not explicitly set
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-20
     */
    public function eventsEventGetSetDataNotExplicitlySet(UnitTester $I)
    {
        $I->wantToTest('Events\Event - getData() when not explicitly set');


        $event = new Event(
            'some-type:beforeSome',
            $this
        );

        $I->assertNull(
            $event->getData()
        );
    }

    /**
     * Tests Phalcon\Events\Event - getData() when explicitly set
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-20
     */
    public function eventsEventGetDataExplicitlySet(UnitTester $I)
    {
        $I->wantToTest('Events\Event - getData() when explicitly set');

        $data = [1, 2, 3];

        $event = new Event(
            'some-type:beforeSome',
            $this,
            $data
        );

        $I->assertEquals(
            $data,
            $event->getData()
        );
    }

    /**
     * Tests Phalcon\Events\Event - setData() overwrites previous data
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-20
     */
    public function eventsEventGetSetDataOverwrite(UnitTester $I)
    {
        $I->wantToTest('Events\Event - setData() overwrites previous data');

        $event = new Event(
            'some-type:beforeSome',
            $this
        );

        $data = [1, 2, 3];

        $event->setData($data);

        $I->assertEquals(
            $data,
            $event->getData()
        );
    }

    /**
     * Tests Phalcon\Events\Event - setData() with no parameters
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-21
     */
    public function eventsEventGetSetDataWithNoParameters(UnitTester $I)
    {
        $I->wantToTest('Events\Event - setData() with no parameters');

        $event = new Event(
            'some-type:beforeSome',
            $this,
            [1, 2, 3]
        );

        $event->setData();

        $I->assertNull(
            $event->getData()
        );
    }
}
