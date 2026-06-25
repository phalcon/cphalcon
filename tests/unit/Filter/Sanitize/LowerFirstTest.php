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

use Phalcon\Filter\Sanitize\LowerFirst;
use Phalcon\Tests\AbstractUnitTestCase;

final class LowerFirstTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-01-19
     */
    public function testFilterSanitizeLowerFirst(): void
    {
        $sanitizer = new LowerFirst();

        $this->assertSame('hello World', $sanitizer('Hello World'));
        $this->assertSame('pHALCON', $sanitizer('PHALCON'));
        $this->assertSame('', $sanitizer(''));
    }
}
