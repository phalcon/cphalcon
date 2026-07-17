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

namespace Phalcon\Tests\Database\Mvc\Model;

use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\Resultset;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class CloneResultMapHydrateTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcModelCloneResultMapHydrate(): void
    {
        $data = [
            'inv_id'    => 1,
            'inv_title' => 'test',
        ];

        // No column map + HYDRATE_ARRAYS returns the data unchanged
        $this->assertSame(
            $data,
            Model::cloneResultMapHydrate($data, null, Resultset::HYDRATE_ARRAYS)
        );

        // No column map + HYDRATE_OBJECTS returns a stdClass
        $object = Model::cloneResultMapHydrate(
            $data,
            null,
            Resultset::HYDRATE_OBJECTS
        );

        $this->assertIsObject($object);
        $this->assertEquals(1, $object->inv_id);
        $this->assertEquals('test', $object->inv_title);

        // A column map remaps the keys
        $columnMap = [
            'inv_id'    => 'id',
            'inv_title' => 'title',
        ];

        $this->assertSame(
            [
                'id'    => 1,
                'title' => 'test',
            ],
            Model::cloneResultMapHydrate(
                $data,
                $columnMap,
                Resultset::HYDRATE_ARRAYS
            )
        );
    }
}
