<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper\Style;

use Phalcon\Html\Escaper;
use Phalcon\Html\Helper\Style;
use UnitTester;

/**
 * Class ToStringCest
 *
 * @package Phalcon\Tests\Unit\Html\Helper\Style
 */
class ToStringCest
{
    /**
     * Tests Phalcon\Html\Helper\Style :: __toString() - empty
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function htmlHelperStyleToStringEmpty(UnitTester $I)
    {
        $I->wantToTest('Html\Helper\Style - __toString() - empty');

        $escaper = new Escaper();
        $helper  = new Style($escaper);

        $result = $helper();

        $actual = (string) $result;
        $I->assertEmpty($actual);
    }
}
