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

class GetSetTypeCest
{
    /**
     * Tests Phalcon\Events\Event :: getType()/setType()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-06
     */
    public function eventsEventSetType(UnitTester $I)
    {
        $I->wantToTest('Events\Event - getType()/setType()');

        $type    = 'some-type:beforeSome';
        $newType = 'some-type:afterSome';
        $event   = new Event($type, $this);

        $expected = $type;
        $actual   = $event->getType();
        $I->assertEquals($expected, $actual);

        $event->setType($newType);

        $expected = $newType;
        $actual   = $event->getType();
        $I->assertEquals($expected, $actual);
    }
}
