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

namespace Phalcon\Tests\Unit\Support\Debug\Dump;

use Phalcon\Support\Debug\Dump;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class EscapeArrayKeyTest extends AbstractUnitTestCase
{
    /**
     * A dumped array key must be escaped (reflected-XSS when dumping request
     * data such as $_GET).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-23
     */
    public function testDumpEscapesArrayKey(): void
    {
        $dump = new Dump();

        $html = $dump->variable(['<img src=x onerror=alert(1)>' => 'v']);

        $this->assertStringNotContainsString(
            '<img src=x onerror=alert(1)>',
            $html
        );
    }
}
