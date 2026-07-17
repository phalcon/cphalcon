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

namespace Phalcon\Tests\Unit\Annotations\Collection;

use Phalcon\Annotations\Collection;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class HasTest extends AbstractUnitTestCase
{
    /**
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-31
     */
    public function testAnnotationsCollectionHas(): void
    {
        $reflectionData = [
            ['name' => 'NovAnnotation'],
            ['name' => 'Phalconatation'],
        ];

        $collection = new Collection($reflectionData);

        $this->assertTrue($collection->has('Phalconatation'));
        $this->assertFalse($collection->has('Phalcony'));
    }
}
