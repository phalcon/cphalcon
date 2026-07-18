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

namespace Phalcon\Tests\Unit\ADR\Events;

use Phalcon\ADR\Events\Event;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class EventTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\Events\Event :: event name constants
     */
    public function testAdrEventsEventNames(): void
    {
        $this->assertSame('application:beforeHandle', Event::APPLICATION_BEFORE_HANDLE);
        $this->assertSame('application:afterHandle', Event::APPLICATION_AFTER_HANDLE);
        $this->assertSame('pipeline:beforeDispatch', Event::PIPELINE_BEFORE_DISPATCH);
        $this->assertSame('pipeline:afterDispatch', Event::PIPELINE_AFTER_DISPATCH);
        $this->assertSame('adr:beforeExecuteAction', Event::ADR_BEFORE_EXECUTE_ACTION);
        $this->assertSame('adr:afterExecuteAction', Event::ADR_AFTER_EXECUTE_ACTION);
    }
}
