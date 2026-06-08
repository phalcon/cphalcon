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

use Phalcon\Html\Escaper\JsEscaper;
use Phalcon\Tests\AbstractUnitTestCase;

final class JsEscaperTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-06
     */
    public function testEscapeEmptyStringReturnsEmpty(): void
    {
        $escaper = new JsEscaper();

        $this->assertSame('', $escaper->escape(''));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-06
     */
    public function testInvokeEscapesSpecialCharacters(): void
    {
        $escaper = new JsEscaper();

        $this->assertSame('\x27', $escaper("'"));
    }
}
