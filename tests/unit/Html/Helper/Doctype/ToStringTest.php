<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper\Doctype;

use Phalcon\Html\Helper\Doctype;
use Phalcon\Tests\AbstractUnitTestCase;

use const PHP_EOL;

final class ToStringTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testHtmlHelperDoctypeToStringEmpty(): void
    {
        $helper = new Doctype();

        $expected = "<!DOCTYPE html>" . PHP_EOL;
        $actual   = (string)$helper;
        $this->assertSame($expected, $actual);
    }
}
