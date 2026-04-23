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

use Phalcon\Filter\Sanitize\Lower;
use Phalcon\Tests\AbstractUnitTestCase;

final class LowerTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-01-19
     */
    public function testFilterSanitizeLower(): void
    {
        $sanitizer = new Lower();

        $this->assertSame('hello world', $sanitizer('Hello World'));
        $this->assertSame('phalcon', $sanitizer('PHALCON'));
        $this->assertSame('', $sanitizer(''));
        $this->assertSame('héllo', $sanitizer('HÉLLO'));
    }
}
