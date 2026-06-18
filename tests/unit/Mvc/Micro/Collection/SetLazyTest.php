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
use Phalcon\Tests\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;

class SetLazyTest extends AbstractUnitTestCase
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
     * @author       Sid Roberts <https://github.com/SidRoberts>
     * @since        2019-06-08
     */
    #[DataProvider('booleanProvider')]
    public function testMvcMicroCollectionSetLazy(
        bool $lazy
    ): void {
        $collection = new Collection();

        $collection->setLazy($lazy);

        $this->assertEquals(
            $lazy,
            $collection->isLazy()
        );
    }
}
