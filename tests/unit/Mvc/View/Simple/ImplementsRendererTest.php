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

namespace Phalcon\Tests\Unit\Mvc\View\Simple;

use Phalcon\Contracts\View\Renderer;
use Phalcon\Mvc\View\Simple;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class ImplementsRendererTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\Mvc\View\Simple :: implements Renderer
     */
    public function testMvcViewSimpleImplementsRenderer(): void
    {
        $this->assertInstanceOf(Renderer::class, new Simple());
    }
}
