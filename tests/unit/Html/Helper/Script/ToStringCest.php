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
use UnitTester;

/**
 * Class ToStringCest
 *
 * @package Phalcon\Tests\Unit\Html\Helper\Script
 */
class ToStringCest
{
    /**
     * Tests Phalcon\Html\Helper\Script :: __toString() - empty
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function htmlHelperScriptToStringEmpty(UnitTester $I)
    {
        $I->wantToTest('Html\Helper\Script - __toString() - empty');

        $escaper = new Escaper();
        $helper  = new Script($escaper);

        $result = $helper();

        $actual = (string) $result;
        $I->assertEmpty($actual);
    }
}
