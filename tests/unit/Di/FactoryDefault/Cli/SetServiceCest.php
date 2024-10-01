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

namespace Phalcon\Tests\Unit\Di\FactoryDefault\Cli;

use Phalcon\Di\FactoryDefault;
use Phalcon\Di\Service;
use Phalcon\Html\Escaper;
use UnitTester;

/**
 * Class SetServiceCest
 *
 * @package Phalcon\Tests\Unit\Di\FactoryDefault\Cli
 */
class SetServiceCest
{
    /**
     * Unit Tests Phalcon\Di\FactoryDefault\Cli :: setService()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diFactoryDefaultCliSetRaw(UnitTester $I)
    {
        $I->wantToTest('Di\FactoryDefault\Cli - setService()');

        $container = new FactoryDefault\Cli();

        $expected = new Service(Escaper::class);
        $actual   = $container->setService('escaper', $expected);
        $I->assertSame($expected, $actual);
    }
}
