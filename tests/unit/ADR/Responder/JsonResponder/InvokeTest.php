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

namespace Phalcon\Tests\Unit\ADR\Responder\JsonResponder;

use Phalcon\ADR\Payload\Payload;
use Phalcon\ADR\Payload\Status;
use Phalcon\ADR\Responder\JsonResponder;
use Phalcon\Http\Request;
use Phalcon\Http\Response;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class InvokeTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\Responder\JsonResponder :: __invoke()
     */
    public function testAdrResponderJsonResponderInvoke(): void
    {
        $responder = new JsonResponder();
        $payload   = (new Payload())
            ->withStatus(Status::CREATED)
            ->withResult(['id' => 7]);

        $result = $responder(new Request(), new Response(), $payload);

        $this->assertSame(201, $result->getStatusCode());
        $this->assertSame('{"id":7}', $result->getContent());
    }
}
