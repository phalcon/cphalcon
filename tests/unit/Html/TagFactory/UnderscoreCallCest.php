<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\TagFactory;

use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use UnitTester;

class UnderscoreCallCest
{
    /**
     * Tests Phalcon\Helper\TagFactory :: __call()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function filterTagFactoryUnderscoreCall(UnitTester $I)
    {
        $I->wantToTest('Helper\TagFactory - __call()');
        $escaper = new Escaper();
        $factory = new TagFactory($escaper);

        $expected = '<body>';
        $actual   = $factory->body();
        $I->assertEquals($expected, $actual);
    }
}
