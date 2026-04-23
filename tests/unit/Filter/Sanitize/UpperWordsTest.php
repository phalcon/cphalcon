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

use Phalcon\Filter\Sanitize\UpperWords;
use Phalcon\Tests\AbstractUnitTestCase;

final class UpperWordsTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-01-19
     */
    public function testFilterSanitizeUpperWords(): void
    {
        $sanitizer = new UpperWords();

        $this->assertSame('Hello World', $sanitizer('hello world'));
        $this->assertSame('Phalcon Framework', $sanitizer('phalcon framework'));
        $this->assertSame('Hello', $sanitizer('hello'));
        $this->assertSame('', $sanitizer(''));
        $this->assertSame('Héllo Wörld', $sanitizer('héllo wörld'));
    }
}
