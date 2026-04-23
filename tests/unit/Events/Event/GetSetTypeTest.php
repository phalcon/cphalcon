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
use Phalcon\Tests\AbstractUnitTestCase;

final class GetSetTypeTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-06
     */
    public function testEventsEventSetType(): void
    {
        $type    = 'some-type:beforeSome';
        $newType = 'some-type:afterSome';
        $event   = new Event($type, $this);

        $expected = $type;
        $actual   = $event->getType();
        $this->assertSame($expected, $actual);

        $event->setType($newType);

        $expected = $newType;
        $actual   = $event->getType();
        $this->assertSame($expected, $actual);
    }
}
