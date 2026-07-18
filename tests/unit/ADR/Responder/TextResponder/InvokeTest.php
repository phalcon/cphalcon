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

namespace Phalcon\Tests\Unit\ADR\Responder\TextResponder;

use Phalcon\ADR\Payload\Payload;
use Phalcon\ADR\Payload\Status;
use Phalcon\ADR\Responder\TextResponder;
use Phalcon\Http\Request;
use Phalcon\Http\Response;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class InvokeTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\Responder\TextResponder :: __invoke()
     */
    public function testAdrResponderTextResponderInvoke(): void
    {
        $responder = new TextResponder();
        $payload   = (new Payload())
            ->withStatus(Status::SUCCESS)
            ->withResult('hello');

        $result = $responder(new Request(), new Response(), $payload);

        $this->assertSame(200, $result->getStatusCode());
        $this->assertSame('hello', $result->getContent());
    }
}
