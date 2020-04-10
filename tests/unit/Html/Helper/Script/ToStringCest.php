<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Html\Helper\Script;

use Phalcon\Escaper;
use Phalcon\Html\Helper\Script;
use UnitTester;

class ToStringCest
{
    /**
     * Tests Phalcon\Html\Helper\Script :: __toString() - empty
     *
     * @since  2020-01-06
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
