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
use Phalcon\ADR\Responder\StatusMapper;
use Phalcon\ADR\Responder\ViewResponder;
use Phalcon\Http\Request;
use Phalcon\Http\Response;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Support\ADR\Responder\FakeRenderer;

final class WithTemplateTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\Responder\ViewResponder :: withTemplate()
     */
    public function testAdrResponderViewResponderWithTemplate(): void
    {
        $renderer = new FakeRenderer();
        $source   = new ViewResponder($renderer, new StatusMapper());
        $target   = $source->withTemplate('users/index');

        $this->assertNotSame($source, $target);
        $this->assertInstanceOf(ViewResponder::class, $target);
    }

    /**
     * Unit Tests Phalcon\ADR\Responder\ViewResponder :: withTemplate() - the
     * source responder keeps its own template
     */
    public function testAdrResponderViewResponderWithTemplateImmutable(): void
    {
        $renderer = new FakeRenderer();
        $source   = new ViewResponder(
            $renderer,
            new StatusMapper(),
            'users/index'
        );

        $source->withTemplate('users/show');
        $source(new Request(), new Response(), new Payload());

        $this->assertSame('users/index', $renderer->template);
    }
}
