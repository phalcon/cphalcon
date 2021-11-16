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

class HasCest
{
    /**
     * Tests Phalcon\Helper\TagFactory :: has()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function filterTagFactoryHas(UnitTester $I)
    {
        $I->wantToTest('Helper\TagFactory - has()');
        $escaper = new Escaper();
        $factory = new TagFactory($escaper);

        $actual = $factory->has('a');
        $I->assertTrue($actual);
    }
}
