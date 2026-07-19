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

namespace Phalcon\Tests\Unit\ADR\Responder\Formatter\JsonFormatter;

use Phalcon\ADR\Responder\Formatter\JsonFormatter;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class AcceptsTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\Responder\Formatter\JsonFormatter :: accepts()
     */
    public function testAdrResponderFormatterJsonFormatterAccepts(): void
    {
        $formatter = new JsonFormatter();

        $this->assertTrue($formatter->accepts('application/json'));
        $this->assertTrue($formatter->accepts('application/vnd.api+json'));
        $this->assertFalse($formatter->accepts('text/html'));
    }
}
