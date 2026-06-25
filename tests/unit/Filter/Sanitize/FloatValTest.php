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

use Phalcon\Filter\Sanitize\FloatVal;
use Phalcon\Tests\AbstractUnitTestCase;

final class FloatValTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-01-19
     */
    public function testFilterSanitizeFloatVal(): void
    {
        $sanitizer = new FloatVal();

        $this->assertSame(3.14, $sanitizer(3.14));
        $this->assertSame(3.14, $sanitizer('3.14'));
        $this->assertSame(100.0, $sanitizer('100abc'));
        $this->assertSame(0.0, $sanitizer('abc'));
        $this->assertSame(-1.5, $sanitizer(-1.5));
    }
}
