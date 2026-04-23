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

use const PHP_EOL;

final class ResetTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testHtmlHelperAbstractSeriesReset(): void
    {
        $escaper = new Escaper();
        $helper  = new Script($escaper);

        $result = $helper('    ', PHP_EOL);
        $result->add('/js/custom.js');

        $actual = $result->reset();
        $this->assertInstanceOf(Script::class, $actual);

        $this->assertSame('', (string)$result);
    }
}
