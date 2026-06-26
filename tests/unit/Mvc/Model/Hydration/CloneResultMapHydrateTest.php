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

namespace Phalcon\Tests\Unit\Mvc\Model\Hydration;

use Phalcon\Mvc\Model\Exceptions\ColumnNotInMap;
use Phalcon\Mvc\Model\Hydration\CloneResultMapHydrate;
use Phalcon\Mvc\Model\Resultset;
use Phalcon\Support\Settings;
use Phalcon\Tests\AbstractUnitTestCase;

final class CloneResultMapHydrateTest extends AbstractUnitTestCase
{
    public function testArraysModeWithoutColumnMapReturnsDataUnchanged(): void
    {
        $data = ['inv_id' => 1, 'inv_title' => 'abc'];

        $this->assertSame(
            $data,
            CloneResultMapHydrate::cloneResultMapHydrate($data, null, Resultset::HYDRATE_ARRAYS)
        );
    }

    public function testColumnMapMapsKeysInArraysMode(): void
    {
        $data      = ['inv_id' => 1, 'inv_title' => 'abc'];
        $columnMap = ['inv_id' => 'id', 'inv_title' => 'title'];

        $this->assertSame(
            ['id' => 1, 'title' => 'abc'],
            CloneResultMapHydrate::cloneResultMapHydrate($data, $columnMap, Resultset::HYDRATE_ARRAYS)
        );
    }

    public function testUnknownColumnNamesTheThreadedClassNotHydrator(): void
    {
        $previous = Settings::get('orm.ignore_unknown_columns');
        Settings::set('orm.ignore_unknown_columns', false);

        try {
            CloneResultMapHydrate::cloneResultMapHydrate(
                ['x' => 1],
                ['inv_id' => 'id'],
                0,
                'App\\Models\\Robots'
            );

            $this->fail('expected ColumnNotInMap');
        } catch (ColumnNotInMap $e) {
            $this->assertStringContainsString('Robots', $e->getMessage());
            $this->assertStringNotContainsString('Hydration', $e->getMessage());
        } finally {
            Settings::set('orm.ignore_unknown_columns', $previous);
        }
    }
}
