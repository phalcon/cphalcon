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

use Phalcon\ADR\Payload\Payload;
use Phalcon\ADR\Responder\Formatter\JsonFormatter;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class FormatTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\Responder\Formatter\JsonFormatter :: format()
     */
    public function testAdrResponderFormatterJsonFormatterFormat(): void
    {
        $formatter = new JsonFormatter();

        $this->assertSame(
            '{"id":1}',
            $formatter->format((new Payload())->withResult(['id' => 1]))
        );

        $this->assertSame(
            '["bad"]',
            $formatter->format((new Payload())->withMessages(['bad']))
        );
    }
}
