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

use Phalcon\Filter\Sanitize\Special;
use Phalcon\Tests\AbstractUnitTestCase;

final class SpecialTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-01-19
     */
    public function testFilterSanitizeSpecial(): void
    {
        $sanitizer = new Special();

        $this->assertSame('Hello World', $sanitizer('Hello World'));
        $this->assertSame('&#60;script&#62;', $sanitizer('<script>'));
        $this->assertSame('&#38;', $sanitizer('&'));
        $this->assertSame('', $sanitizer(''));
    }
}
