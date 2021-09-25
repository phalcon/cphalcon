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

class SetTypeCest
{
    /**
     * Tests Phalcon\Events\Event :: setType()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-20
     */
    public function eventsEventSetType(UnitTester $I)
    {
        $I->wantToTest('Events\Event - setType()');

        $event = new Event(
            'some-type:beforeSome',
            $this,
            []
        );

        $newType = 'some-type:afterSome';

        $event->setType($newType);

        $I->assertEquals(
            $newType,
            $event->getType()
        );
    }
}
