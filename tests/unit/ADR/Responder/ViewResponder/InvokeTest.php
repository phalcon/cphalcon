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

namespace Phalcon\Tests\Unit\ADR\Responder\ViewResponder;

use Phalcon\ADR\Payload\Payload;
use Phalcon\ADR\Payload\Status;
use Phalcon\ADR\Responder\StatusMapper;
use Phalcon\ADR\Responder\ViewResponder;
use Phalcon\Http\Request;
use Phalcon\Http\Response;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Support\ADR\Responder\FakeRenderer;

final class InvokeTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\Responder\ViewResponder :: __invoke()
     */
    public function testAdrResponderViewResponderInvoke(): void
    {
        $renderer  = new FakeRenderer();
        $responder = new ViewResponder($renderer, new StatusMapper());
        $payload   = (new Payload())
            ->withStatus(Status::CREATED)
            ->withResult(['id' => 7]);

        $result = $responder->withTemplate('users/index')(
            new Request(),
            new Response(),
            $payload
        );

        $this->assertSame('users/index', $renderer->template);
        $this->assertSame('<h1>users/index</h1>', $result->getContent());
        $this->assertSame(201, $result->getStatusCode());
        $this->assertSame(
            'text/html',
            $result->getHeaders()->get('Content-Type')
        );
    }

    /**
     * Unit Tests Phalcon\ADR\Responder\ViewResponder :: __invoke() - view data
     */
    public function testAdrResponderViewResponderInvokeViewData(): void
    {
        $renderer  = new FakeRenderer();
        $responder = new ViewResponder($renderer, new StatusMapper());
        $payload   = (new Payload())
            ->withStatus(Status::NOT_FOUND)
            ->withResult(['id' => 7])
            ->withMessages(['not there']);

        $responder->withTemplate('users/show')(
            new Request(),
            new Response(),
            $payload
        );

        $expected = [
            'result'   => ['id' => 7],
            'messages' => ['not there'],
            'status'   => Status::NOT_FOUND,
        ];

        $this->assertSame($expected, $renderer->data);
    }

    /**
     * Unit Tests Phalcon\ADR\Responder\ViewResponder :: __invoke() - unmapped
     * status
     */
    public function testAdrResponderViewResponderInvokeUnmappedStatus(): void
    {
        $renderer  = new FakeRenderer();
        $responder = new ViewResponder($renderer, new StatusMapper());
        $payload   = (new Payload())->withStatus('unknown-status');

        $result = $responder(new Request(), new Response(), $payload);

        $this->assertSame(500, $result->getStatusCode());
    }
}
