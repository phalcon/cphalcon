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

use Phalcon\Filter\Sanitize\StringVal;
use Phalcon\Tests\AbstractUnitTestCase;

final class StringValTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-01-19
     */
    public function testFilterSanitizeStringVal(): void
    {
        $sanitizer = new StringVal();

        $this->assertSame('Hello World', $sanitizer('Hello World'));
        $this->assertSame('&lt;script&gt;alert(1)&lt;/script&gt;', $sanitizer('<script>alert(1)</script>'));
        $this->assertSame('&amp;', $sanitizer('&'));
        $this->assertSame('&quot;', $sanitizer('"'));
        $this->assertSame('', $sanitizer(''));
    }
}
