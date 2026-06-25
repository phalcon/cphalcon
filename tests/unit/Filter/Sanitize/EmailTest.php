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

use Phalcon\Filter\Sanitize\Email;
use Phalcon\Tests\AbstractUnitTestCase;

final class EmailTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-01-19
     */
    public function testFilterSanitizeEmail(): void
    {
        $sanitizer = new Email();

        $this->assertSame('test@phalcon.io', $sanitizer('test@phalcon.io'));
        $this->assertSame('test@phalcon.io', $sanitizer('  test@ phalcon.io  '));
        $this->assertSame('user+tag@example.com', $sanitizer('user+tag@example.com'));
        $this->assertSame('', $sanitizer(''));
    }
}
