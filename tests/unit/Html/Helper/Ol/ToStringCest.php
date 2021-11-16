<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper\Ol;

use Phalcon\Html\Escaper;
use Phalcon\Html\Helper\Ol;
use UnitTester;

use const PHP_EOL;

/**
 * Class ToStringCest
 *
 * @package Phalcon\Tests\Unit\Html\Helper\Ol
 */
class ToStringCest
{
    /**
     * Tests Phalcon\Html\Helper\Ol :: __toString()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function htmlHelperOlToStringEmpty(UnitTester $I)
    {
        $I->wantToTest('Html\Helper\Ol - __toString() - empty');

        $escaper = new Escaper();
        $helper  = new Ol($escaper);

        $result = $helper('', PHP_EOL, ['id' => 'carsList']);

        $actual = (string) $result;
        $I->assertEmpty($actual);
    }
}
