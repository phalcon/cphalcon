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

use Phalcon\Filter\Sanitize\Upper;
use Phalcon\Tests\AbstractUnitTestCase;

final class UpperTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-01-19
     */
    public function testFilterSanitizeUpper(): void
    {
        $sanitizer = new Upper();

        $this->assertSame('HELLO WORLD', $sanitizer('Hello World'));
        $this->assertSame('PHALCON', $sanitizer('phalcon'));
        $this->assertSame('', $sanitizer(''));
        $this->assertSame('HÉLLO', $sanitizer('héllo'));
    }
}
