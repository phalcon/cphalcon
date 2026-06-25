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

use Phalcon\Filter\Sanitize\Replace;
use Phalcon\Tests\AbstractUnitTestCase;

final class ReplaceTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-01-19
     */
    public function testFilterSanitizeReplace(): void
    {
        $sanitizer = new Replace();

        $this->assertSame('Hello-World', $sanitizer('Hello World', ' ', '-'));
        $this->assertSame('Hello World', $sanitizer('Hello World', 'foo', 'bar'));
        $this->assertSame('bar baz', $sanitizer('foo baz', 'foo', 'bar'));
        $this->assertSame('', $sanitizer('', ' ', '-'));
    }
}
