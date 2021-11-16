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
use UnitTester;

use const PHP_EOL;

/**
 * Class ToStringCest
 *
 * @package Phalcon\Tests\Unit\Html\Helper\Doctype
 */
class ToStringCest
{
    /**
     * Tests Phalcon\Html\Helper\Doctype :: __toString() - empty
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function htmlHelperDoctypeToStringEmpty(UnitTester $I)
    {
        $I->wantToTest('Html\Helper\Doctype - __toString() - empty');

        $helper = new Doctype();

        $expected = "<!DOCTYPE html>" . PHP_EOL;
        $actual   = (string) $helper;
        $I->assertEquals($expected, $actual);
    }
}
