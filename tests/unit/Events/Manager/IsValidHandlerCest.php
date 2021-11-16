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

namespace Phalcon\Tests\Unit\Events\Manager;

use Codeception\Example;
use Phalcon\Events\Manager;
use UnitTester;

class IsValidHandlerCest
{
    /**
     * Tests Phalcon\Events\Manager :: isValidHandler()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function eventsManagerIsValidHandler(UnitTester $I, Example $example)
    {
        $I->wantToTest('Events\Manager - isValidHandler() - ' . $example[0]);

        $manager  = new Manager();
        $handler  = $example[2];
        $expected = $example[1];
        $actual   = $manager->isValidHandler($handler);
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return array[]
     */
    private function getExamples(): array
    {
        $objectHandler  = new Manager();
        $closureHandler = function () {
            return true;
        };

        return [
            [
                'string',
                false,
                'handler'
            ],
            [
                'integer',
                false,
                134,
            ],
            [
                'object',
                true,
                $objectHandler,
            ],
            [
                'callable - method',
                true,
                [$objectHandler, 'hasListeners']
            ],
            [
                'closure',
                true,
                $closureHandler
            ],
        ];
    }
}
