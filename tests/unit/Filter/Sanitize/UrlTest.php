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
use Phalcon\Tests\AbstractUnitTestCase;

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
}
