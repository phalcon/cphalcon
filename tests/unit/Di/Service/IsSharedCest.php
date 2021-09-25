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
use UnitTester;

class IsSharedCest
{
    /**
     * Tests Phalcon\Di\Service :: isShared()
     *
     * @author       Sid Roberts <https://github.com/SidRoberts>
     * @since        2019-06-12
     *
     * @dataProvider provider
     */
    public function diServiceIsShared(UnitTester $I, Example $example)
    {
        $I->wantToTest('Di\Service - isShared()');

        $I->assertEquals(
            $example['expected'],
            $example['service']->isShared()
        );
    }

    private function provider(): array
    {
        return [
            [
                'service'  => new Service('some-service'),
                'expected' => false,
            ],
            [
                'service'  => new Service('some-service', true),
                'expected' => true,
            ],
            [
                'service'  => new Service('some-service', false),
                'expected' => false,
            ],
        ];
    }
}
