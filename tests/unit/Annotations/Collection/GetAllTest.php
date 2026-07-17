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

use Phalcon\Annotations\Annotation;
use Phalcon\Annotations\Collection;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class GetAllTest extends AbstractUnitTestCase
{
    /**
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-27
     */
    public function testAnnotationsCollectionGetAll(): void
    {
        $dataAnnotation  = ['name' => 'NovAnnotation'];
        $dataAnnotation1 = ['name' => 'NovAnnotation1'];
        $dataAnnotation2 = ['name' => 'NovAnnotation'];

        $collection = new Collection(
            [$dataAnnotation, $dataAnnotation1, $dataAnnotation2]
        );

        $annotation  = new Annotation($dataAnnotation);
        $annotation2 = new Annotation($dataAnnotation2);

        $this->assertEmpty($collection->getAll('Phalconatation'));

        $expected = [$annotation, $annotation2];
        $this->assertEquals($expected, $collection->getAll('NovAnnotation'));
    }
}
