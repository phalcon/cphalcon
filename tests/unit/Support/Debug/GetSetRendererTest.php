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

namespace Phalcon\Tests\Unit\Support\Debug;

use Phalcon\Support\Debug;
use Phalcon\Support\Debug\Renderer\HtmlRenderer;
use Phalcon\Support\Debug\Report\ExceptionReport;
use Phalcon\Support\Exception;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetSetRendererTest extends AbstractUnitTestCase
{
    public function testGetRendererReturnsDefaultHtmlRenderer(): void
    {
        $this->assertInstanceOf(HtmlRenderer::class, (new Debug())->getRenderer());
    }

    public function testSetRendererIsUsedForRendering(): void
    {
        $fake = new class extends HtmlRenderer {
            public function render(ExceptionReport $report): string
            {
                return 'FAKE_OUTPUT';
            }
        };

        $debug  = new Debug();
        $result = $debug->setRenderer($fake);

        $this->assertSame($debug, $result);
        $this->assertSame($fake, $debug->getRenderer());
        $this->assertSame('FAKE_OUTPUT', $debug->renderHtml(new Exception('boom')));
    }
}
