<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Html\Helper\Ol;

use Phalcon\Escaper;
use Phalcon\Html\Helper\Ol;
use UnitTester;

class ToStringCest
{
    /**
     * Tests Phalcon\Html\Helper\Ol :: __toString()
     *
     * @since  2020-01-06
     */
    public function htmlHelperOlToStringEmpty(UnitTester $I)
    {
        $I->wantToTest('Html\Helper\Ol - __toString() - empty');

        $escaper = new Escaper();
        $helper  = new Ol($escaper);

        $result = $helper(null, null, ['id' => 'carsList']);

        $actual = (string) $result;
        $I->assertEmpty($actual);
    }
}
