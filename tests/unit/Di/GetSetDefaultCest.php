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

namespace Phalcon\Tests\Unit\Di;

use Phalcon\Di\Di;
use Phalcon\Html\Escaper;
use Phalcon\Support\Collection;
use UnitTester;

use function spl_object_hash;

/**
 * Class GetSetDefaultCest
 *
 * @package Phalcon\Tests\Unit\Di
 */
class GetSetDefaultCest
{
    /**
     * Tests Phalcon\Di :: getDefault() / setDefault()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diGetDefault(UnitTester $I)
    {
        $I->wantToTest('Di - getDefault() / setDefault()');

        $one = new Di();
        $one->set('collection', Collection::class);

        $two = new Di();
        $two->set('escaper', Escaper::class);

        Di::setDefault($one);

        $expected = spl_object_hash($one);
        $actual   = spl_object_hash(Di::getDefault());
        $I->assertEquals($expected, $actual);

        Di::setDefault($two);

        $expected = spl_object_hash($two);
        $actual   = spl_object_hash(Di::getDefault());
        $I->assertEquals($expected, $actual);
    }
}
