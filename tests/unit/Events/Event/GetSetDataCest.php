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
     * Tests Phalcon\Events\Event - setData() - default
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-06
     */
    public function eventsEventGetSetData(UnitTester $I)
    {
        $I->wantToTest('Events\Event - getData()/setData() - default');

        $event = new Event('some-type:beforeSome', $this);

        $actual = $event->getData();
        $I->assertNull($actual);
    }

    /**
     * Tests Phalcon\Events\Event - setData() - constructor
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-06
     */
    public function eventsEventGetSetDataConstructor(UnitTester $I)
    {
        $I->wantToTest('Events\Event - getData()/setData() - constructor');

        $data     = [1, 2, 3];
        $event    = new Event('some-type:beforeSome', $this, $data);
        $expected = $data;
        $actual   = $event->getData();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Events\Event - setData() - overwrite
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-06
     */
    public function eventsEventGetSetDataOverwrite(UnitTester $I)
    {
        $I->wantToTest('Events\Event - getData()/setData() - overwrite');

        $data     = [1, 2, 3];
        $event    = new Event('some-type:beforeSome', $this, $data);
        $expected = $data;
        $actual   = $event->getData();
        $I->assertEquals($expected, $actual);

        $newData = [4, 5, 6];
        $event->setData($newData);
        $expected = $newData;
        $actual   = $event->getData();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Events\Event - setData() - empty
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-06
     */
    public function eventsEventGetSetDataEmpty(UnitTester $I)
    {
        $I->wantToTest('Events\Event - getData()/setData() - empty');

        $data     = [1, 2, 3];
        $event    = new Event('some-type:beforeSome', $this, $data);
        $expected = $data;
        $actual   = $event->getData();
        $I->assertEquals($expected, $actual);

        $event->setData();
        $actual = $event->getData();
        $I->assertNull($actual);
    }
}
