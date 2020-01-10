<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Html\Helper\Meta;

use Phalcon\Escaper;
use Phalcon\Html\Helper\Meta;
use UnitTester;

class ToStringCest
{
    /**
     * Tests Phalcon\Html\Helper\Meta :: __toString() - empty
     *
     * @since  2020-01-06
     */
    public function htmlHelperMetaToStringEmpty(UnitTester $I)
    {
        $I->wantToTest('Html\Helper\Meta - __toString() - empty');

        $escaper = new Escaper();
        $helper  = new Meta($escaper);

        $result = $helper();

        $actual = (string) $result;
        $I->assertEmpty($actual);
    }
}
