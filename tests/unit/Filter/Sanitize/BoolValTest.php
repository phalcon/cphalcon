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

use Phalcon\Filter\Sanitize\BoolVal;
use Phalcon\Tests\AbstractUnitTestCase;

final class BoolValTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-01-19
     */
    public function testFilterSanitizeBoolVal(): void
    {
        $sanitizer = new BoolVal();

        // true-array inputs
        $this->assertTrue($sanitizer('true'));
        $this->assertTrue($sanitizer('on'));
        $this->assertTrue($sanitizer('yes'));
        $this->assertTrue($sanitizer('y'));
        $this->assertTrue($sanitizer('1'));

        // false-array inputs
        $this->assertFalse($sanitizer('false'));
        $this->assertFalse($sanitizer('off'));
        $this->assertFalse($sanitizer('no'));
        $this->assertFalse($sanitizer('n'));
        $this->assertFalse($sanitizer('0'));

        // fallback: cast to bool
        $this->assertTrue($sanitizer(42));
        $this->assertFalse($sanitizer(null));
        $this->assertFalse($sanitizer(''));
    }
}
