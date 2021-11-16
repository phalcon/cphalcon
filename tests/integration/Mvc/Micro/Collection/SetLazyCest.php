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

namespace Phalcon\Tests\Integration\Mvc\Micro\Collection;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Mvc\Micro\Collection;

class SetLazyCest
{
    /**
     * Tests Phalcon\Mvc\Micro\Collection :: setLazy()
     *
     * @author       Sid Roberts <https://github.com/SidRoberts>
     * @since        2019-06-08
     *
     * @dataProvider booleanProvider
     */
    public function mvcMicroCollectionSetLazy(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Mvc\Micro\Collection - setLazy()');

        $lazy = $example[0];

        $collection = new Collection();

        $collection->setLazy($lazy);

        $I->assertEquals(
            $lazy,
            $collection->isLazy()
        );
    }

    private function booleanProvider(): array
    {
        return [
            [
                true,
            ],
            [
                false,
            ],
        ];
    }
}
