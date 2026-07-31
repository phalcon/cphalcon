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
use Phalcon\Mvc\View\Simple;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;

final class InvokePhtmlTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\Responder\ViewResponder :: __invoke() - end to end
     * through a real Simple view and the default `.phtml` engine.
     *
     * The view is wired exactly as an ADR consumer must wire it: a bare
     * `Simple` with no container and no `registerEngines()` call. Registering
     * an engine requires a `Phalcon\Di\DiInterface`, which the ADR container is
     * not, so `.phtml` is the only engine reachable from ADR until v7.
     */
    public function testAdrResponderViewResponderInvokeWithPhtml(): void
    {
        $responder = new ViewResponder(
            $this->newRenderer(),
            new StatusMapper()
        );
        $payload   = (new Payload())
            ->withStatus(Status::SUCCESS)
            ->withResult(['name' => 'Phalcon'])
            ->withMessages(['all good']);

        $result = $responder->withTemplate('adr/users')(
            new Request(),
            new Response(),
            $payload
        );

        $this->assertSame(
            '<h1>Phalcon</h1><p>SUCCESS</p><i>all good</i>',
            $result->getContent()
        );
        $this->assertSame(200, $result->getStatusCode());
        $this->assertSame(
            'text/html',
            $result->getHeaders()->get('Content-Type')
        );
    }

    /**
     * Unit Tests Phalcon\ADR\Responder\ViewResponder :: __invoke() - the status
     * mapping survives a real render
     */
    public function testAdrResponderViewResponderInvokeWithPhtmlFailureStatus(): void
    {
        $responder = new ViewResponder(
            $this->newRenderer(),
            new StatusMapper()
        );
        $payload   = (new Payload())
            ->withStatus(Status::NOT_FOUND)
            ->withResult(['name' => 'Phalcon'])
            ->withMessages(['nope']);

        $result = $responder->withTemplate('adr/users')(
            new Request(),
            new Response(),
            $payload
        );

        $this->assertSame(
            '<h1>Phalcon</h1><p>NOT_FOUND</p><i>nope</i>',
            $result->getContent()
        );
        $this->assertSame(404, $result->getStatusCode());
    }

    /**
     * Unit Tests Phalcon\ADR\Responder\ViewResponder :: __invoke() - the ADR
     * render fires no view events, because no events manager is wired
     */
    public function testAdrResponderViewResponderInvokeWithPhtmlFiresNoEvents(): void
    {
        $view      = $this->newRenderer();
        $responder = new ViewResponder($view, new StatusMapper());
        $payload   = (new Payload())
            ->withStatus(Status::SUCCESS)
            ->withResult(['name' => 'Phalcon'])
            ->withMessages(['all good']);

        $responder->withTemplate('adr/users')(
            new Request(),
            new Response(),
            $payload
        );

        $this->assertNull($view->getEventsManager());
    }

    /**
     * The consumer-side wiring from the design: no container, no registered
     * engines, no events manager.
     */
    protected function newRenderer(): Simple
    {
        $view = new Simple();
        $view->setViewsDir(Talon::settings()->supportPath('assets/views/'));

        return $view;
    }
}
