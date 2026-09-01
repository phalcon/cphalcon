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

final class CurrentTest extends AbstractUnitTestCase
{
    /**
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-27
     */
    public function testAnnotationsCollectionCurrent(): void
    {
        $collection = new Collection();

        $this->assertFalse($collection->current());
    }

    /**
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-27
     */
    public function testAnnotationsCollectionCurrentWithAnnotations(): void
    {
        $dataAnnotation  = ['name' => 'NovAnnotation'];
        $dataAnnotation1 = ['name' => 'NovAnnotation1'];

        $collection = new Collection([$dataAnnotation, $dataAnnotation1]);
        $annotation = new Annotation($dataAnnotation);

        $this->assertEquals($annotation, $collection->current());
    }
}
