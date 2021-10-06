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

class GetSourceCest
{
    /**
     * Tests Phalcon\Events\Event :: getSource()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-06
     * @issue  https://github.com/phalcon/cphalcon/issues/15133
     */
    public function eventsEventGetSource(UnitTester $I)
    {
        $I->wantToTest('Events\Event - getSource()');

        $event = new Event('some-type:beforeSome', $this);

        $expected = $this;
        $actual   = $event->getSource();
        $I->assertSame($expected, $actual);

        $event = new Event('some-type:beforeSome');

        $actual = $event->getSource();
        $I->assertNull($actual);
    }
}
