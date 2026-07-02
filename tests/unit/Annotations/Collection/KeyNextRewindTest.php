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

final class KeyNextRewindTest extends AbstractUnitTestCase
{
    /**
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-31
     */
    public function testAnnotationsCollectionKeyNextRewind(): void
    {
        $dataAnnotation  = ['name' => 'NovAnnotation'];
        $dataAnnotation1 = ['name' => 'Phalconatation'];

        $collection  = new Collection([$dataAnnotation, $dataAnnotation1]);
        $annotation  = new Annotation($dataAnnotation);
        $annotation1 = new Annotation($dataAnnotation1);

        $this->assertEquals(0, $collection->key());
        $this->assertEquals($annotation, $collection->current());

        $collection->next();

        $this->assertEquals(1, $collection->key());
        $this->assertEquals($annotation1, $collection->current());

        $collection->rewind();

        $this->assertEquals(0, $collection->key());
        $this->assertEquals($annotation, $collection->current());
    }
}
