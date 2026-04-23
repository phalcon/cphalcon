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

use Phalcon\Filter\Sanitize\Alnum;
use Phalcon\Tests\AbstractUnitTestCase;

final class AlnumTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-01-19
     */
    public function testFilterSanitizeAlnum(): void
    {
        $sanitizer = new Alnum();

        $this->assertSame('Hello123', $sanitizer('Hello! #123'));
        $this->assertSame('abc', $sanitizer('abc'));
        $this->assertSame('', $sanitizer('!@#$%'));
        $this->assertSame(['ab1', 'cd2'], $sanitizer(['ab!1', 'cd@2']));
    }
}
