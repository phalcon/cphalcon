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
use Phalcon\Tests\Fixtures\Micro\HttpMethodHandler;

class IsLazyCest
{
    /**
     * Tests Phalcon\Mvc\Micro\Collection :: isLazy() - default
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-08
     */
    public function mvcMicroCollectionIsLazyDefault(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Micro\Collection - isLazy() - default');

        $collection = new Collection();

        $httpMethodHandler = new HttpMethodHandler();

        $collection->setHandler($httpMethodHandler);

        $I->assertFalse(
            $collection->isLazy()
        );
    }

    /**
     * Tests Phalcon\Mvc\Micro\Collection :: isLazy()
     *
     * @author       Sid Roberts <https://github.com/SidRoberts>
     * @since        2019-06-08
     *
     * @dataProvider booleanProvider
     */
    public function mvcMicroCollectionIsLazy(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Mvc\Micro\Collection - isLazy()');

        $lazy = $example[0];

        $collection = new Collection();

        $httpMethodHandler = new HttpMethodHandler();

        $collection->setHandler($httpMethodHandler, $lazy);

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
