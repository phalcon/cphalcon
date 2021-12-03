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

class SetSharedCest
{
    /**
     * Tests Phalcon\Di\Service :: setShared()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-09-09
     */
    public function diServiceSetShared(UnitTester $I, Example $example)
    {
        $I->wantToTest('Di\Service - setShared()');

        $service = $example[0];
        $service->setShared(true);

        $actual = $service->isShared();
        $I->assertTrue($actual);

        $service->setShared(false);

        $actual = $service->isShared();
        $I->assertFalse($actual);
    }

    /**
     * @return Service[][]
     */
    private function getExamples(): array
    {
        return [
            [
                new Service(Escaper::class),
            ],
            [
                new Service(Escaper::class, true),
            ],
            [
                new Service(Escaper::class, false),
            ],
        ];
    }
}
