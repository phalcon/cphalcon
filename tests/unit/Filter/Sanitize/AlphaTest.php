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

use Phalcon\Filter\Sanitize\Alpha;
use Phalcon\Tests\AbstractUnitTestCase;

final class AlphaTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-01-19
     */
    public function testFilterSanitizeAlpha(): void
    {
        $sanitizer = new Alpha();

        $this->assertSame('Hello', $sanitizer('Hello! 123'));
        $this->assertSame('abc', $sanitizer('abc'));
        $this->assertSame('', $sanitizer('123456'));
        $this->assertSame(['ab', 'cd'], $sanitizer(['ab1', 'cd2']));
    }
}
