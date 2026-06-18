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

namespace Phalcon\Tests\Unit\Html\Escaper;

use Phalcon\Html\Escaper;
use Phalcon\Tests\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\RequiresPhpExtension;

final class NormalizeEncodingTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    #[RequiresPhpExtension('mbstring')]
    public function testEscaperNormalizeEncoding(): void
    {
        $escaper = new Escaper();

        $expected = mb_convert_encoding('Hello', 'UTF-32', 'UTF-8');
        $actual   = $escaper->normalizeEncoding('Hello');
        $this->assertSame($expected, $actual);
    }
}
