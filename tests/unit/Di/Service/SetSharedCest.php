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

class SetSharedCest
{
    /**
     * Tests Phalcon\Di\Service :: setShared()
     *
     * @author       Sid Roberts <https://github.com/SidRoberts>
     * @since        2019-06-12
     *
     * @dataProvider provider
     */
    public function diServiceSetShared(UnitTester $I, Example $example)
    {
        $I->wantToTest('Di\Service - setShared()');

        $service = $example['service'];

        $service->setShared(true);

        $I->assertTrue(
            $service->isShared()
        );

        $service->setShared(false);

        $I->assertFalse(
            $service->isShared()
        );
    }

    private function provider(): array
    {
        return [
            [
                'service' => new Service('some-service'),
            ],
            [
                'service' => new Service('some-service', true),
            ],
            [
                'service' => new Service('some-service', false),
            ],
        ];
    }
}
