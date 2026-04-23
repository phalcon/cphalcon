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

use Phalcon\Filter\Sanitize\Striptags;
use Phalcon\Tests\AbstractUnitTestCase;

final class StriptagsTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-01-19
     */
    public function testFilterSanitizeStriptags(): void
    {
        $sanitizer = new Striptags();

        $this->assertSame('Hello World', $sanitizer('Hello World'));
        $this->assertSame('Hello World', $sanitizer('<p>Hello World</p>'));
        $this->assertSame('Hello World', $sanitizer('<b>Hello</b> <i>World</i>'));
        $this->assertSame('alert(1)', $sanitizer('<script>alert(1)</script>'));
        $this->assertSame('', $sanitizer(''));
    }
}
