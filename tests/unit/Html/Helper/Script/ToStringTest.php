<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper\Script;

use Phalcon\Html\Escaper;
use Phalcon\Html\Helper\Script;
use Phalcon\Tests\AbstractUnitTestCase;

final class ToStringTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testHtmlHelperScriptToStringEmpty(): void
    {
        $escaper = new Escaper();
        $helper  = new Script($escaper);

        $result = $helper();

        $actual = (string)$result;
        $this->assertEmpty($actual);
    }
}
