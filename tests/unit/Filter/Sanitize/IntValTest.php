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

use Phalcon\Filter\Sanitize\IntVal;
use Phalcon\Tests\AbstractUnitTestCase;

final class IntValTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-01-19
     */
    public function testFilterSanitizeIntVal(): void
    {
        $sanitizer = new IntVal();

        $this->assertSame(100, $sanitizer(100));
        $this->assertSame(100, $sanitizer('100'));
        $this->assertSame(-100, $sanitizer(-100));
        $this->assertSame(0, $sanitizer('abc'));
        $this->assertSame(100, $sanitizer('100abc'));
    }
}
