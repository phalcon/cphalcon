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

namespace Phalcon\Tests\Unit\Support\Collection;

use PHPUnit\Framework\Attributes\DataProvider;

final class ValuesTest extends AbstractCollectionTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-12
     */
    #[DataProvider('getClasses')]
    public function testSupportCollectionValuesReturnsValues(string $class): void
    {
        $collection = new $class(['a' => 1, 'b' => 2]);

        $this->assertSame($collection->getValues(), $collection->values());
    }
}
