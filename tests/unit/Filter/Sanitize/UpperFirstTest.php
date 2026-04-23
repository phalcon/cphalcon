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

use Phalcon\Filter\Sanitize\UpperFirst;
use Phalcon\Tests\AbstractUnitTestCase;

final class UpperFirstTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-01-19
     */
    public function testFilterSanitizeUpperFirst(): void
    {
        $sanitizer = new UpperFirst();

        $this->assertSame('Hello World', $sanitizer('hello World'));
        $this->assertSame('PHALCON', $sanitizer('pHALCON'));
        $this->assertSame('Phalcon', $sanitizer('phalcon'));
        $this->assertSame('', $sanitizer(''));
    }
}
