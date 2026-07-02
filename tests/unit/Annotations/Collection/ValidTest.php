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

final class ValidTest extends AbstractUnitTestCase
{
    /**
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-31
     */
    public function testAnnotationsCollectionValid(): void
    {
        $reflectionData = [
            ['name' => 'NovAnnotation'],
            ['name' => 'Phalconatation'],
        ];

        $collection = new Collection($reflectionData);

        $this->assertTrue($collection->valid());

        $collection->next();
        $this->assertTrue($collection->valid());

        $collection->next();
        $this->assertFalse($collection->valid());
    }
}
