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

use Phalcon\Html\Escaper\UrlEscaper;
use Phalcon\Tests\AbstractUnitTestCase;

final class UrlEscaperTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-06
     */
    public function testEscapeEncodesUrl(): void
    {
        $escaper = new UrlEscaper();

        $this->assertSame('a%20b%26c', $escaper->escape('a b&c'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-06
     */
    public function testInvokeEncodesUrl(): void
    {
        $escaper = new UrlEscaper();

        $this->assertSame('a%20b', $escaper('a b'));
    }
}
