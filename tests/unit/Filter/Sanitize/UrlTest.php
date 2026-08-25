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
     * Only a scheme on the allow-list survives; any other scheme is dropped.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-25
     */
    public function testFilterSanitizeUrlAllowsOnlyListedSchemes(): void
    {
        $sanitizer = new Url();

        $this->assertSame(
            'ftp://example.com/file.txt',
            $sanitizer('ftp://example.com/file.txt')
        );
        $this->assertSame(
            'ftps://example.com/file.txt',
            $sanitizer('ftps://example.com/file.txt')
        );
        $this->assertSame('tel:+15550100', $sanitizer('tel:+15550100'));

        // Not on the allow-list.
        $this->assertSame('', $sanitizer('file:///etc/passwd'));
        $this->assertSame('', $sanitizer('ws://example.com/socket'));
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

    /**
     * The scheme allow-list is case-insensitive, so a mixed-case dangerous
     * scheme is dropped as well.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-25
     */
    public function testFilterSanitizeUrlBlocksMixedCaseScheme(): void
    {
        $sanitizer = new Url();

        $this->assertSame('', $sanitizer('JavaScript:alert(1)'));
        $this->assertSame('', $sanitizer('JAVASCRIPT:alert(1)'));
        $this->assertSame('', $sanitizer('DATA:text/html,<script>alert(1)</script>'));
        $this->assertSame('', $sanitizer('VbScript:msgbox(1)'));
    }

    /**
     * filter_var() returns false for an input it cannot sanitize. The result
     * is cast, so the sanitizer always gives back a string.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-25
     */
    public function testFilterSanitizeUrlReturnsStringWhenFilterFails(): void
    {
        $sanitizer = new Url();

        $expected = '';
        $actual   = $sanitizer(['https://phalcon.io']);
        $this->assertSame($expected, $actual);
    }
}
