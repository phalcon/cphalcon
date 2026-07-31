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

namespace Phalcon\Tests\Unit\ADR\Emitter\SapiEmitter;

use Phalcon\ADR\Emitter\SapiEmitter;
use Phalcon\Contracts\ADR\Emitter\Emitter;
use Phalcon\Http\Response;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class EmitTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\Emitter\SapiEmitter :: emit()
     */
    public function testAdrEmitterSapiEmitterEmit(): void
    {
        $emitter = new SapiEmitter();

        $this->assertInstanceOf(Emitter::class, $emitter);

        ob_start();
        $emitter->emit((new Response())->setContent('emitted-body'));
        $output = (string) ob_get_clean();

        $this->assertStringContainsString('emitted-body', $output);
    }
}
