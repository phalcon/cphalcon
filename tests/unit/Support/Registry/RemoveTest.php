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

namespace Phalcon\Tests\Unit\Support\Registry;

use Phalcon\Support\Registry;

final class RemoveTest extends AbstractRegistryTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testSupportRegistryRemove(): void
    {
        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $registry = new Registry($data);

        $this->assertSame(
            $data,
            $registry->toArray(),
        );


        $registry->remove('five');

        $this->assertSame(
            [
                'one'   => 'two',
                'three' => 'four',
            ],
            $registry->toArray(),
        );


        $registry->remove('FIVE');

        $this->assertSame(
            [
                'one'   => 'two',
                'three' => 'four',
            ],
            $registry->toArray(),
        );


        $registry->init($data);

        unset($registry['five']);

        $this->assertSame(
            [
                'one'   => 'two',
                'three' => 'four',
            ],
            $registry->toArray(),
        );


        $registry->init($data);

        $registry->offsetUnset('five');

        $this->assertSame(
            [
                'one'   => 'two',
                'three' => 'four',
            ],
            $registry->toArray(),
        );
    }
}
