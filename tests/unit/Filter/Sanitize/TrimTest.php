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

use Phalcon\Filter\Sanitize\Trim;
use Phalcon\Tests\AbstractUnitTestCase;

final class TrimTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-01-19
     */
    public function testFilterSanitizeTrim(): void
    {
        $sanitizer = new Trim();

        $this->assertSame('Hello World', $sanitizer('  Hello World  '));
        $this->assertSame('Hello World', $sanitizer('Hello World'));
        $this->assertSame('Hello World', $sanitizer("\tHello World\n"));
        $this->assertSame('', $sanitizer('   '));
        $this->assertSame('', $sanitizer(''));
    }
}
