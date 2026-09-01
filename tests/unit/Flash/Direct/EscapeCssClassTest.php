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

namespace Phalcon\Tests\Unit\Flash\Direct;

use Phalcon\Flash\Direct;
use Phalcon\Html\Escaper;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class EscapeCssClassTest extends AbstractUnitTestCase
{
    /**
     * A crafted css class must not break out of the class attribute.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-23
     */
    public function testFlashEscapesCssClass(): void
    {
        $flash = new Direct();
        $flash->setEscaperService(new Escaper());
        $flash->setImplicitFlush(false);
        $flash->setCssClasses(['error' => '"><script>alert(1)</script>']);

        $html = $flash->error('hello');

        $this->assertStringNotContainsString('<script>', $html);
    }

    /**
     * A crafted css icon class must not break out of the class attribute of
     * the `<i>` fragment.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-25
     */
    public function testFlashEscapesCssIconClass(): void
    {
        $flash = new Direct();
        $flash->setEscaperService(new Escaper());
        $flash->setImplicitFlush(false);
        $flash->setCssIconClasses(['error' => '" onmouseover="alert(1)']);

        $html = $flash->error('hello');

        $this->assertStringContainsString(
            '<i class="&quot; onmouseover=&quot;alert(1)"></i>',
            $html
        );
        $this->assertStringNotContainsString('onmouseover="', $html);
    }
}
