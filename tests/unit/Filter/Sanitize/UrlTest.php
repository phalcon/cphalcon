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

namespace Phalcon\Tests\Unit\Filter\Sanitize;

use Phalcon\Filter\Sanitize\Url;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class UrlTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-01-19
     */
    public function testFilterSanitizeUrl(): void
    {
        $sanitizer = new Url();

        $this->assertSame(
            'https://phalcon.io/en/download',
            $sanitizer('https://phalcon.io/en/download')
        );

        $this->assertSame(
            'https://phalcon.io/en/download',
            $sanitizer('https://phalcon.io/en/ download')
        );

        $this->assertSame(
            'https://example.com/path?query=value&other=1',
            $sanitizer('https://example.com/path?query=value&other=1')
        );

        $this->assertSame('', $sanitizer(''));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-24
     */
    public function testFilterSanitizeUrlBlocksDangerousScheme(): void
    {
        $sanitizer = new Url();

        // Dangerous schemes survive FILTER_SANITIZE_URL and must be dropped.
        $this->assertSame('', $sanitizer('javascript:alert(1)'));
        $this->assertSame('', $sanitizer('data:text/html,<script>alert(1)</script>'));
        $this->assertSame('', $sanitizer('vbscript:msgbox(1)'));

        // Safe schemes and relative URLs pass through.
        $this->assertSame('https://phalcon.io', $sanitizer('https://phalcon.io'));
        $this->assertSame('mailto:team@phalcon.io', $sanitizer('mailto:team@phalcon.io'));
        $this->assertSame('/relative/path', $sanitizer('/relative/path'));
    }
}
