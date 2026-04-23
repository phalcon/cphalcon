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

namespace Phalcon\Tests\Unit\Mvc\Micro\Collection;

use Phalcon\Mvc\Micro\Collection;
use Phalcon\Tests\Support\Micro\HttpMethodHandler;
use Phalcon\Tests\AbstractUnitTestCase;

class IsLazyTest extends AbstractUnitTestCase
{
    public static function booleanProvider(): array
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

    /**
     * @dataProvider booleanProvider
     *
     * @author       Sid Roberts <https://github.com/SidRoberts>
     * @since        2019-06-08
     */
    public function testMvcMicroCollectionIsLazy(
        bool $lazy
    ): void {
        $collection        = new Collection();
        $httpMethodHandler = new HttpMethodHandler();

        $collection->setHandler($httpMethodHandler, $lazy);

        $this->assertEquals($lazy, $collection->isLazy());
    }

    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-08
     */
    public function testMvcMicroCollectionIsLazyDefault(): void
    {
        $collection = new Collection();

        $httpMethodHandler = new HttpMethodHandler();

        $collection->setHandler($httpMethodHandler);

        $this->assertFalse(
            $collection->isLazy()
        );
    }
}
