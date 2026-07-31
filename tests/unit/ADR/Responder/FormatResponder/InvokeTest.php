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

namespace Phalcon\Tests\Unit\ADR\Responder\FormatResponder;

use Phalcon\ADR\Payload\Payload;
use Phalcon\ADR\Responder\FormatResponder;
use Phalcon\ADR\Responder\Formatter\JsonFormatter;
use Phalcon\Http\Request;
use Phalcon\Http\Response;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class InvokeTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\Responder\FormatResponder :: __invoke() falls back to the default formatter
     */
    public function testAdrResponderFormatResponderInvokeFallsBackToDefault(): void
    {
        $responder = new FormatResponder([new JsonFormatter()]);
        $payload   = (new Payload())->withResult(['ok' => true]);

        $result = $responder(new Request(), new Response(), $payload);

        $this->assertSame('{"ok":true}', $result->getContent());
    }

    /**
     * Unit Tests Phalcon\ADR\Responder\FormatResponder :: __invoke() with no formatters is a no-op
     */
    public function testAdrResponderFormatResponderInvokeWithoutFormatters(): void
    {
        $responder = new FormatResponder();
        $payload   = (new Payload())->withResult(['ok' => true]);

        $result = $responder(new Request(), new Response(), $payload);

        $this->assertSame('', $result->getContent());
    }
}
