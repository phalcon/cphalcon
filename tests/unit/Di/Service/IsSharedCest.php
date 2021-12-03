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

namespace Phalcon\Tests\Unit\Di\Service;

use Codeception\Example;
use Phalcon\Di\Service;
use Phalcon\Html\Escaper;
use UnitTester;

/**
 * Class IsSharedCest
 *
 * @package Phalcon\Tests\Unit\Di\Service
 */
class IsSharedCest
{
    /**
     * Tests Phalcon\Di\Service :: isShared()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-09-09
     */
    public function diServiceIsShared(UnitTester $I, Example $example)
    {
        $I->wantToTest('Di\Service - isShared()');

        $service  = $example[0];
        $expected = $example[1];
        $actual   = $service->isShared();
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return array[]
     */
    private function getExamples(): array
    {
        return [
            [
                new Service(Escaper::class),
                false,
            ],
            [
                new Service(Escaper::class, true),
                true,
            ],
            [
                new Service(Escaper::class, false),
                false,
            ],
        ];
    }
}
